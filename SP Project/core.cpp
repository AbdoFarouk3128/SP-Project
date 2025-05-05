#include "core.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <limits>
#include <algorithm>
#include "sqlite3.h"
//#include"LoginForm.h"
//#include"ClientForm.h"
//#include"TrainerForm.h"

using namespace std;

// ================== UTILITY FUNCTIONS ==================
#pragma region UTILITY FUNCTIONS
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pressEnter() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

string joinLogs(string logs[], int numLogs) { // make logs to string to save in the database
    string result;
    for (int i = 0; i < numLogs; ++i) {
        result += logs[i];
        if (i != numLogs - 1)
            result += "|";
    }
    return result;
}

//void clearInputBuffer() { // error handling to int cin
//    cin.clear();
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//}

string toLower(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

bool isUsernameTaken(const string& username) {
    string lowerUsername = toLower(username);
    for (int i = 0; i < trainerCount; i++) {
        if (toLower(trainers[i].username) == lowerUsername) return true;
    }
    for (int j = 0; j < trainerCount; j++)
    {
        for (int i = 0; i < trainers->numClients; i++) {
            if (toLower(trainers[j].clients[i].username) == lowerUsername) return true;
        }
    }
    return false;
}

int splitLogs(string logsString, string logs[], int maxLogs) {
    stringstream ss(logsString);
    string item;
    int count = 0;
    while (getline(ss, item, '|') && count < maxLogs) {
        logs[count++] = item;
    }
    return count;
}

string formatDate(Measurement::Date d) { // make to string to put it in database
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%02d-%02d-%04d", d.Day, d.Month, d.Year);
    return string(buffer);
}
#pragma endregion
// ================== DATABASE FUNCTIONS ==================
#pragma region Database Functions
void loadTrainers(sqlite3* db) { //load trainers in array
    trainerCount = 0;
    const char* query = "SELECT * FROM Trainers;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW && trainerCount < MAX_TRAINERS) {
            trainers[trainerCount].trainerID = sqlite3_column_int(stmt, 0);
            trainers[trainerCount].name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            trainers[trainerCount].username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            trainers[trainerCount].password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            trainerCount++;
        }
    }
    sqlite3_finalize(stmt);
}

void loadWorkouts(sqlite3* db) { // load workout to clients
    const char* query = "SELECT * FROM Workouts;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int clientId = sqlite3_column_int(stmt, 8);
            for (int j = 0; j < trainerCount; j++)
            {
                for (int i = 0; i < trainers[j].numClients; ++i) {
                    if (trainers[j].clients[i].clientID == clientId && trainers[j].clients[i].numWorkouts < MAX_WORKOUTS) {
                        Workout& w = trainers[j].clients[i].workoutPlans[trainers[j].clients[i].numWorkouts];
                        w.workoutID = sqlite3_column_int(stmt, 0);
                        w.workoutName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                        string exercisesStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
                        w.numExercises = sqlite3_column_int(stmt, 3);
                        w.duration = sqlite3_column_int(stmt, 4);
                        w.sets = sqlite3_column_int(stmt, 5);
                        w.reps = sqlite3_column_int(stmt, 6);
                        w.istrue = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));

                        stringstream ss(exercisesStr);
                        string temp;
                        int exCount = 0;
                        while (getline(ss, temp, ',') && exCount < MAX_EXERCISES) {
                            w.exercises[exCount++] = temp;
                        }
                        w.numExercises = exCount;

                        trainers[j].clients[i].numWorkouts++;
                        break;
                    }
                }

            }
        }
    }
    sqlite3_finalize(stmt);
}

void loadClientsOfTrainers(sqlite3* db) { //load clients for trainers
    const char* query = "SELECT * FROM Clients;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            // Extract all client information
            Client client;
            client.clientID = sqlite3_column_int(stmt, 0);
            client.name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            client.username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            client.password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            client.age = sqlite3_column_int(stmt, 4);
            client.gender = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
            client.activityLevel = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));

            // Load progress logs if they exist
            const char* logsStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
            if (logsStr) {
                client.numLogs = splitLogs(logsStr, client.progressLogs, MAX_LOGS);
            }

            client.trainerId = sqlite3_column_int(stmt, 8);
            // Find the trainer and add this client to their list
            for (int i = 0; i < trainerCount; ++i) {
                if (trainers[i].trainerID == client.trainerId && trainers[i].numClients < MAX_CLIENTS) {
                    trainers[i].clients[trainers[i].numClients++] = client;
                    break;
                }
            }
            clientCount++;
        }
    }
    sqlite3_finalize(stmt);
}

void loadMeasurements(sqlite3* db) { // load measerments every client
    const char* query = "SELECT * FROM Measurements;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int clientId = sqlite3_column_int(stmt, 1);
            for (int j = 0; j < trainerCount; j++)
            {
                for (int i = 0; i < trainers[j].numClients; ++i) {
                    if (trainers[j].clients[i].clientID == clientId && trainers[j].clients[i].numMeasurements < MAX_MEASUREMENTS) {
                        Measurement& m = trainers[j].clients[i].measurements[trainers[j].clients[i].numMeasurements];
                        m.weight = sqlite3_column_double(stmt, 2);
                        m.height = sqlite3_column_double(stmt, 3);
                        const char* dateStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
                        if (dateStr && strlen(dateStr) == 10) {
                            sscanf(dateStr, "%02d-%02d-%04d", &m.date.Day, &m.date.Month, &m.date.Year);
                        }
                        trainers[j].clients[i].numMeasurements++;
                        break;
                    }
                }
            }
        }
    }
    sqlite3_finalize(stmt);
}

void loadPredefinedWorkouts(sqlite3* db) { // load in the array
    const char* query = "SELECT * FROM PredefinedWorkouts;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        numPredefinedWorkouts = 0;
        while (sqlite3_step(stmt) == SQLITE_ROW && numPredefinedWorkouts < MAX_WORKOUTS) {
            predefineWorkout[numPredefinedWorkouts].workoutID = sqlite3_column_int(stmt, 0);
            predefineWorkout[numPredefinedWorkouts].workoutName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            string exercisesStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            predefineWorkout[numPredefinedWorkouts].numExercises = sqlite3_column_int(stmt, 3);
            predefineWorkout[numPredefinedWorkouts].duration = sqlite3_column_int(stmt, 4);
            predefineWorkout[numPredefinedWorkouts].sets = sqlite3_column_int(stmt, 5);
            predefineWorkout[numPredefinedWorkouts].reps = sqlite3_column_int(stmt, 6);

            stringstream ss(exercisesStr);
            string temp;
            int exCount = 0;
            while (getline(ss, temp, ',') && exCount < MAX_EXERCISES) {
                predefineWorkout[numPredefinedWorkouts].exercises[exCount++] = temp;
            }
            predefineWorkout[numPredefinedWorkouts].numExercises = exCount;

            numPredefinedWorkouts++;
        }
    }
    sqlite3_finalize(stmt);
}

void loadAllData(sqlite3* db) {
    loadTrainers(db);
    loadClientsOfTrainers(db);
    loadWorkouts(db);
    loadMeasurements(db);
    loadPredefinedWorkouts(db);
}

void insertTrainer(sqlite3* db, Trainer  t) {
    const char* query = "INSERT INTO Trainers (name, username, password) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, t.name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, t.username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, t.password.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}

void insertClient(sqlite3* db, Client c) {
    const char* query = "INSERT INTO Clients (name, username, password, age, gender, activityLevel, progressLogs, trainerId) VALUES (?, ?, ?, ?, ?, ?, ?, ?)";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, c.name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, c.username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, c.password.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 4, c.age);
        sqlite3_bind_text(stmt, 5, c.gender.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 6, c.activityLevel.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 7, "", -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 8, c.trainerId);
        sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}

void insertWorkout(sqlite3* db, Workout w, int clientId) {
    const char* query = "INSERT INTO Workouts (workoutName, exercises, numExercises, duration, sets, reps, isdone, clientId) VALUES (?, ?, ?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    string exerciseList;
    for (int i = 0; i < w.numExercises; i++) {
        exerciseList += w.exercises[i];
        if (i < w.numExercises - 1) exerciseList += ",";
    }

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, w.workoutName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, exerciseList.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 3, w.numExercises);
        sqlite3_bind_int(stmt, 4, w.duration);
        sqlite3_bind_int(stmt, 5, w.sets);
        sqlite3_bind_int(stmt, 6, w.reps);
        sqlite3_bind_text(stmt, 7, "Pending", -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 8, clientId);
        sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}

void insertPredefinedWorkout(sqlite3* db, Workout w) {
    const char* query = "INSERT INTO PredefinedWorkouts (workoutName, exercises, numExercises, duration, sets, reps) VALUES (?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    string exerciseList;
    for (int i = 0; i < w.numExercises; i++) {
        exerciseList += w.exercises[i];
        if (i < w.numExercises - 1) exerciseList += ",";
    }

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, w.workoutName.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, exerciseList.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 3, w.numExercises);
        sqlite3_bind_int(stmt, 4, w.duration);
        sqlite3_bind_int(stmt, 5, w.sets);
        sqlite3_bind_int(stmt, 6, w.reps);
        sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}

void insertMeasurement(sqlite3* db, Measurement m, int clientId) {
    const char* query = "INSERT INTO Measurements (clientId, weight, height, date) VALUES (?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    string dateStr = formatDate(m.date);

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, clientId);
        sqlite3_bind_double(stmt, 2, m.weight);
        sqlite3_bind_double(stmt, 3, m.height);
        sqlite3_bind_text(stmt, 4, dateStr.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}

void updateClientProgressLogs(sqlite3* db, int clientId, const string& logsStr) {
    const char* query = "UPDATE Clients SET progressLogs = ? WHERE clientId = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, logsStr.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, clientId);
        sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}

void updatetheworkoutstatus(sqlite3* db, int workoutid) {
    const char* query = "UPDATE Workouts SET isdone = ? WHERE workoutID = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, "Done", -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 2, workoutid);
        sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}
#pragma endregion
// ================== HEALTH CALCULATIONS ==================
#pragma region Health Calcultaions
double calculateBMR(Client& a) {
    int index = a.numMeasurements - 1;

    if (a.gender == "male" || a.gender == "Male")
        return 10.0 * a.measurements[index].weight + 6.25 * a.measurements[index].height - 5.0 * a.age + 5.0;
    else if (a.gender == "female" || a.gender == "Female")
        return  10.0 * a.measurements[index].weight + 6.25 * a.measurements[index].height - 5.0 * a.age - 161.0;
    else {
        cout << "INVALID CHOICE" << endl;
        return 0;
    }
}

double getActivityMultiplier(Client& a) {
    if (a.activityLevel == "sedentary" || a.activityLevel == "Sedentary") return 1.2;
    else if (a.activityLevel == "light" || a.activityLevel == "Light") return 1.375;
    else if (a.activityLevel == "moderate" || a.activityLevel == "Moderate")  return 1.55;
    else if (a.activityLevel == "active" || a.activityLevel == "Active")  return 1.725;
    else if (a.activityLevel == "Veryactive" || a.activityLevel == "veryactive")
        return 1.9;
    else {
        cout << "Invalid activity level" << endl;
        return 1.0;
    }
}

double calculateTDEE(double bmr, double activitylevel) {
    return bmr * activitylevel;
}

Measurement::Macros calculateMacros(double tdee, Client& a) {
    Measurement::Macros mac;
    a.measurements[a.numMeasurements - 1].macros.protein = (tdee * 0.3) / 4;
     mac.protein=a.measurements[a.numMeasurements - 1].macros.protein ;
    a.measurements[a.numMeasurements - 1].macros.carbs = (tdee * 0.45) / 4;
    mac.carbs= a.measurements[a.numMeasurements - 1].macros.carbs;
    a.measurements[a.numMeasurements - 1].macros.fats = (tdee * 0.25) / 9;
    mac.fats=a.measurements[a.numMeasurements - 1].macros.fats;
    return mac;
}

double calculateBMI(Client& a) {
    float heightInMeters = a.measurements[a.numMeasurements - 1].height / 100.0;
    return a.measurements[a.numMeasurements - 1].weight / (heightInMeters * heightInMeters);
}

string getBMICategory(double bmi) {
    if (bmi < 18.5) return "Underweight";
    else if (bmi < 25) return "Normal";
    else if (bmi < 30) return "Overweight";
    else return "Obese";
}

void healthsummary(Client& client) {
    if (client.numMeasurements == 0) {
        cout << "No measurements available to generate health summary." << endl;
        return;
    }
    double activityMulti = getActivityMultiplier(client);
    double bmr = calculateBMR(client);
    double tdee = calculateTDEE(bmr, activityMulti);
    double bmi = calculateBMI(client);
    string status = getBMICategory(bmi);

    cout << "------HEALTH SUMMARY------" << endl;
    cout << " BMI(Body Mass Index) = " << bmi << " | Status is " << status << endl;
    cout << " BMR(Basal Metabolic Rate) = " << bmr << endl;
    cout << " TDEE(Total Daily Energy Expenditure) = " << tdee << endl;
    calculateMacros(tdee, client);
}
#pragma endregion
// ================== CLIENT FEATURES ==================
#pragma region Client Features

void Veiw_Workout(Client& client) {
    if (client.numWorkouts == 0) {
        cout << "No workouts assigned Yet....\n";
    }
    else {
        for (int i = 0; i < client.numWorkouts; i++) {
            cout << i + 1 << ". " << client.workoutPlans[i].workoutName << " (" << client.workoutPlans[i].duration << "min)\n";
            for (int j = 0; j < client.workoutPlans[i].numExercises; j++) {
                cout << "- " << client.workoutPlans[i].exercises[j] << endl;
            }
            cout << "Sets: " << client.workoutPlans[i].sets << " | Reps: " << client.workoutPlans[i].reps << " Status: " << client.workoutPlans[i].istrue << "\n\n";
        }
    }
}

void Log_Workout(Client& client) {
    if (client.numWorkouts == 0) {
        cout << "No workouts assigned Yet ...\n";
    }
    else if (client.numLogs >= MAX_LOGS) {
        cout << "Log Limit Reached ...\n";
    }
    else {
        for (int i = 0; i < client.numWorkouts; i++)
        {

            cout << i + 1 << "- " << client.workoutPlans[i].workoutName << " Status: " << client.workoutPlans[i].istrue << endl;
        }
        bool istrue = 0;
        int log;
        do
        {
            cout << "Enter workout number you completed: ";
            cin >> log;
            if (cin.fail()) {
                cin.clear();
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            if (log<1 || log >client.numWorkouts)
            {
                cout << "Ivalid choice.\n";
                continue;
            }
            else if (client.workoutPlans[log - 1].istrue == "Done") {
                cout << "This Workout has been done before choose another one.\n";
                return;
            }
            else
            {
                istrue = 1;
            }
        } while (!istrue);
        client.progressLogs[client.numLogs++] = client.workoutPlans[log - 1].workoutName;
        cout << "Workout Logged Successfully!\n";
        updateClientProgressLogs(db, client.clientID, joinLogs(client.progressLogs, client.numLogs));
        updatetheworkoutstatus(db, client.workoutPlans[log - 1].workoutID);
        client.workoutPlans[log - 1].istrue = "Done";
    }
}

bool invalidDate(int day, int month, int year) {
    if (year < 1 || month < 1 || month > 12 || day < 1) return true;
    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) daysInMonth[1] = 29;
    return day > daysInMonth[month - 1];
}

void Log_Measurments(Client& client) {
    if (client.numMeasurements >= MAX_MEASUREMENTS) {
        cout << "Measurements Limit Reached ...\n";
        return;
    }
    Measurement log_measurement;
    cout << "Enter weight (kg): ";
    cin >> log_measurement.weight;
    if (client.numMeasurements >= 1)
    {
        log_measurement.height = client.measurements[client.numMeasurements - 1].height;
    }
    else {
        cout << "Enter height (cm): ";
        cin >> log_measurement.height;
    }

    bool dateValid = false;
    while (!dateValid) {
        cout << "Enter date:\n";
        cout << "Day: ";
        do {
            cin >> log_measurement.date.Day;
            if (cin.fail()) {
                cin.clear();
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            else
            {
                break;
            }
        } while (true);
        cout << "Month: ";
        do {
            cin >> log_measurement.date.Month;
            if (cin.fail()) {
                cin.clear();
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            else
            {
                break;
            }
        } while (true);

        cout << "Year: ";
        do {
            cin >> log_measurement.date.Year;
            if (cin.fail()) {
                cin.clear();
                //cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input. Please enter a number.\n";
                continue;
            }
            else
            {
                break;
            }
        } while (true);

        if (invalidDate(log_measurement.date.Day, log_measurement.date.Month, log_measurement.date.Year)) {
            cout << "Invalid date. Please try again.\n";
        }
        else {
            dateValid = true;
        }
    }
    client.measurements[client.numMeasurements++] = log_measurement;
    insertMeasurement(db, log_measurement, client.clientID);
    cout << "Measurements Added Successfully!\n";
}

void ViewMeasurements(Client& client) {
    if (client.numMeasurements == 0) {
        cout << "No measurements recorded yet.\n";
        return;
    }
    cout << "======= Measurements History =======\n";
    for (int i = 0; i < client.numMeasurements; i++) {
        cout << i + 1 << ". Date: " << client.measurements[i].date.Day << "/"
            << client.measurements[i].date.Month << "/"
            << client.measurements[i].date.Year
            << " | Weight: " << client.measurements[i].weight << "kg"
            << " | Height: " << client.measurements[i].height << "cm\n";
    }
}

void client_menue(Client& client) {
    int choice;

    do {
        clearScreen();
        cout << "======================= CLIENT MENU =======================\n"
            << "1. View Workouts\n"
            << "2. Log Completed Workout\n"
            << "3. Log Measurements\n"
            << "4. Health Summary\n"
            << "5. View Measurement History\n"
            << "6. Logout\n"
            << "Enter Choice: ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        clearScreen();
        switch (choice) {
        case 1: Veiw_Workout(client); break;
        case 2: Log_Workout(client); break;
        case 3: Log_Measurments(client); break;
        case 4: healthsummary(client); break;
        case 5: ViewMeasurements(client); break;
        case 6: cout << "Logging out...\n"; break;
        default: cout << "Invalid Choice!\n"; break;
        }
        if (choice != 6) pressEnter();
    } while (choice != 6);
}
#pragma endregion
// ================== TRAINER FEATURES ==================
#pragma region Trainer Features
void displayClientData(Client& c) {
    cout << "Full Name: " << c.name << " | Age: " << c.age << " | Gender: " << c.gender
        << " | Activity Level: " << c.activityLevel << " | numbers of workouts: " << c.numWorkouts << endl;
}

void ClientProgress(Client& client) {
    cout << "-------------- Completed Workouts ---------------\n";
    if (client.numLogs == 0) {
        cout << "No progress logs for this client!\n";
    }
    else {
        for (int i = 0; i < client.numLogs; i++) {
            cout << i + 1 << ". " << client.progressLogs[i] << "\n\n\n";
        }
    }
    if (client.numMeasurements == 0) {
        cout << "No Measurements have been added.";
    }
    else {
        cout << "======= Measurements History =======\n";
        for (int i = 0; i < client.numMeasurements; i++)
        {
            cout << i + 1 << ". Date: " << client.measurements[i].date.Day << "/"
                << client.measurements[i].date.Month << "/"
                << client.measurements[i].date.Year
                << " | Weight: " << client.measurements[i].weight << "kg"
                << " | Height: " << client.measurements[i].height << "cm\n\n\n";
        }
        healthsummary(client);

    }
}

bool checkclientid(Trainer& trainer, int selectedID) {
    for (int i = 0; i < trainer.numClients; i++)
    {
        if (trainer.clients[i].clientID == selectedID) return true;
    }
    return false;
}

int displayClientsAndSelect(Trainer& trainer) {
    cout << "=== CLIENT LIST ===\n";
    for (int i = 0; i < trainer.numClients; i++) {
        cout << "ID: " << trainer.clients[i].clientID
            << " | Name: " << trainer.clients[i].name
            << " | Workouts: " << trainer.clients[i].numWorkouts << "\n";
    }
    int selectedID;
    cout << "Enter client ID: ";
    while (!(cin >> selectedID) || !(checkclientid(trainer, selectedID))) {
        cout << "Invalid input. Enter correct ID: ";
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return selectedID;
}

void display_predefeined_workouts() {
    if (numPredefinedWorkouts == 0) {
        cout << "No predefined workouts available.\n";
        return;
    }
    cout << "=== PREDEFINED WORKOUTS ===\n";
    for (int i = 0; i < numPredefinedWorkouts; i++) {
        cout << i + 1 << ". " << predefineWorkout[i].workoutName << " (" << predefineWorkout[i].duration << " mins)\n";
        for (int j = 0; j < predefineWorkout[i].numExercises; j++) {
            cout << "   - " << predefineWorkout[i].exercises[j] << "\n";
        }
        cout << "   Sets: " << predefineWorkout[i].sets << " | Reps: " << predefineWorkout[i].reps << "\n\n";
    }
}

void assign_workout(Client& client) {
    display_predefeined_workouts();
    if (numPredefinedWorkouts == 0) return;

    int numToAssign;
    cout << "How many predefined workouts do you want to assign? ";
    cin >> numToAssign;

    for (int i = 0; i < numToAssign; i++) {
        int choice;
        cout << "Enter the number of the workout to assign (" << i + 1 << "/" << numToAssign << "): ";
        cin >> choice;
        if (cin.fail()) {
            cin.clear();
            //cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }
        choice--;

        if (choice >= 0 && choice < numPredefinedWorkouts) {
            if (client.numWorkouts < MAX_WORKOUTS) {
                client.workoutPlans[client.numWorkouts] = predefineWorkout[choice];
                client.workoutPlans[client.numWorkouts].istrue = "Pending";
                client.numWorkouts++;
                insertWorkout(db, predefineWorkout[choice], client.clientID);
                cout << "Workout '" << predefineWorkout[choice].workoutName << "' assigned successfully!\n";
            }
            else {
                cout << "Client cannot have more workouts.\n";
                break;
            }
        }
        else {
            cout << "Invalid workout number.\n";
            i--;
        }
    }
}

void createPredefinedWorkout() {
    if (numPredefinedWorkouts >= MAX_WORKOUTS) {
        cout << "Maximum predefined workouts reached.\n";
        return;
    }
    Workout newWorkout;

    do {
        cout << "Enter workout name: ";
        cin.ignore();
        getline(cin, newWorkout.workoutName);
        if (newWorkout.workoutName.empty())
        {
            cout << "Workout name can't be empty  please try again.\n";
        }

    } while (newWorkout.workoutName.empty());


    do {
        cout << "Enter number of exercises (max " << MAX_EXERCISES << "): ";
        cin >> newWorkout.numExercises;
    } while (newWorkout.numExercises < 1 || newWorkout.numExercises > MAX_EXERCISES);

    for (int i = 0; i < newWorkout.numExercises; i++) {
        cout << "Exercise " << i + 1 << ": ";
        cin.ignore();
        getline(cin, newWorkout.exercises[i]);
        if (newWorkout.exercises[i].empty())
        {
            cout << "Exercise name can't be empty  please try again.\n";

        }
    }

    cout << "Duration (minutes): ";
    cin >> newWorkout.duration;
    cout << "Number of sets: ";
    cin >> newWorkout.sets;
    cout << "Number of reps: ";
    cin >> newWorkout.reps;

    predefineWorkout[numPredefinedWorkouts] = newWorkout;
    insertPredefinedWorkout(db, newWorkout);
    numPredefinedWorkouts++;
    cout << "Predefined workout created successfully!\n";
}

Workout createCustomWorkout() {
    Workout newWorkout;
    cout << "Enter workout name: ";
    cin.ignore();
    getline(cin, newWorkout.workoutName);

    cout << "Enter number of exercises: ";
    cin >> newWorkout.numExercises;
    cin.ignore();

    for (int i = 0; i < newWorkout.numExercises; i++) {
        cout << "Exercise " << i + 1 << ": ";
        getline(cin, newWorkout.exercises[i]);
    }

    cout << "Duration (minutes): ";
    cin >> newWorkout.duration;
    cout << "Sets: ";
    cin >> newWorkout.sets;
    cout << "Reps: ";
    cin >> newWorkout.reps;

    return newWorkout;
}

void TrainerMenu(Trainer& trainer) {
    int choice;
    do {
        clearScreen();
        cout << "\n=== TRAINER MENU ===\n"
            << "1. View Clients Information\n"
            << "2. Manage Workouts\n"
            << "3. View Client Progress\n"
            << "4. Logout\n"
            << "Enter your choice: ";
        cin >> choice;
        clearScreen();
        switch (choice) {
        case 1: {
            if (trainer.numClients == 0)
            {
                cout << "-----There is no information allowed now -----" << endl;
                break;
            }
            else
            {
                cout << "\n--------- Client Information -----------\n";
                for (int i = 0; i < trainer.numClients; ++i) {
                    cout << i + 1 << ". ";
                    displayClientData(trainer.clients[i]);
                }
                break;
            }
        }
        case 2: {
            cout << "1. Assign Predefined Workout\n"
                << "2. Create New Predefined Workout\n"
                << "3. Create Custom Workout for Client\n"
                << "Enter option: ";
            int subChoice;
            cin >> subChoice;
            clearScreen();
            if (subChoice == 1 || subChoice == 3) {
                int clientID = displayClientsAndSelect(trainer);
                int clientIndex = -1;
                for (int i = 0; i < trainer.numClients; i++) {
                    if (trainer.clients[i].clientID == clientID) {
                        clientIndex = i;
                        break;
                    }
                }
                if (clientIndex == -1) {
                    cout << "Client not found!\n";
                    break;
                }
                Client& selectedClient = trainer.clients[clientIndex];
                if (subChoice == 1) {
                    assign_workout(selectedClient);
                }
                else if (subChoice == 3) {
                    Workout customWorkout = createCustomWorkout();
                    if (selectedClient.numWorkouts < MAX_WORKOUTS) {
                        selectedClient.workoutPlans[selectedClient.numWorkouts++] = customWorkout;
                        insertWorkout(db, customWorkout, selectedClient.clientID);
                        cout << "Custom workout assigned successfully!\n";
                    }
                    else {
                        cout << "Client's workout limit reached.\n";
                    }
                }
            }
            else if (subChoice == 2) {
                createPredefinedWorkout();
            }
            else {
                cout << "Invalid option.\n";
            }
            break;
        }
        case 3: {
            cout << "\n---------- Select a client to view progress ---------\n";
            int clientID = displayClientsAndSelect(trainer);
            if (checkclientid(trainer, clientID)) {
                for (int i = 0; i < trainer.numClients; i++)
                {
                    if (trainer.clients[i].clientID == clientID)
                    {
                        ClientProgress(trainer.clients[i]);
                    }
                }
            }
            else {
                cout << "Invalid client selection.\n";
            }
            break;
        }
        case 4: cout << "Logging out...\n"; break;
        default: cout << "Invalid choice.\n"; break;
        }
        if (choice != 4) pressEnter();
    } while (choice != 4);
}
#pragma endregion
// ================== AUTHENTICATION ==================
#pragma region Authentication 
int  chooseTrainer() {  //CHOOSING TRAINER
    cout << "Choose your Trainer: " << endl;
    for (int i = 0; i < trainerCount; i++) {
        cout << trainers[i].trainerID << "-" << trainers[i].name << endl;
    }
    int id;
    cout << "Enter Trainer Number: ";
    while (!(cin >> id) || (id <= 0 || id > trainerCount)) {
        cout << "Invalid input. Choose Correct ID: ";
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return id;

}

void registerTrainer() {
    if (trainerCount >= MAX_TRAINERS) {
        cout << "Maximum trainers reached. Cannot register new trainer.\n";
        return;
    }

    // Dynamically allocate the Trainer object
    Trainer* newTrainer = new Trainer();
    cout << "\nTrainer Registration\n";
    do {
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, newTrainer->name);
        if (newTrainer->name.empty())
        {
            cout << "Trainer's  name can't be empty  please try again.\n";
        }
    } while (newTrainer->name.empty());
    int attempts = 0;
    bool usernameTaken;
    do {
        if (attempts >= MAX_USERNAME_ATTEMPTS) {
            cout << "Too many failed attempts. Registration cancelled.\n";
            delete newTrainer;  // Clean up memory
            return;
        }



        do {
            cout << "choose username: ";

            getline(cin, newTrainer->username);
            if (newTrainer->username.empty())
            {
                cout << "Trainer's  username can't be empty  please try again.\n";

            }
        } while (newTrainer->username.empty());

        usernameTaken = isUsernameTaken(newTrainer->username);
        if (usernameTaken) {
            cout << "Username already taken. Please try another.\n";
            attempts++;
        }
    } while (usernameTaken);

    do {
        cout << "choose password: ";

        getline(cin, newTrainer->password);
        if (newTrainer->password.empty())
        {
            cout << "Trainer's  password can't be empty  please try again.\n";
        }
    } while (newTrainer->password.empty());


    newTrainer->trainerID = trainerCount + 1;
    trainers[trainerCount] = *newTrainer;  // Copy to the array
    insertTrainer(db, *newTrainer);
    trainerCount++;

    delete newTrainer;  // Free the dynamically allocated memory

    cout << "Trainer account created! Your ID is: " << trainers[trainerCount - 1].trainerID << "\n";
}

void registerClient() {
    /*if (clientCount >= MAX_CLIENTS) {
        cout << "Maximum clients reached. Cannot register new client.\n";
        return;
    }*/

    Client newClient;
    cout << "\nClient Registration\n";
    do {
        cout << "Enter Name: ";
        cin.ignore();

        getline(cin, newClient.name);
        if (newClient.name.empty())
        {
            cout << "Clients's  Name can't be empty  please try again.\n";
        }
    } while (newClient.name.empty());




    int attempts = 0;
    bool usernameTaken;
    do {
        if (attempts >= MAX_USERNAME_ATTEMPTS) {
            cout << "Too many failed attempts. Registration cancelled.\n";
            return;
        }
        do {
            cout << "Choose Username: ";

            getline(cin, newClient.username);
            if (newClient.username.empty())
            {
                cout << "Clients's  Username can't be empty  please try again.\n";
            }
        } while (newClient.username.empty());



        usernameTaken = isUsernameTaken(newClient.username);
        if (usernameTaken) {
            cout << "Username already taken. Please try another.\n";
            attempts++;
        }
    } while (usernameTaken);
    do {
        cout << "Choose password: ";

        getline(cin, newClient.password);

        if (newClient.password.empty())
        {
            cout << "Clients's  password can't be empty  please try again.\n";
        }
    } while (newClient.password.empty());



    cout << "Enter age: ";
    while (!(cin >> newClient.age) || newClient.age <= 0) {
        cout << "Invalid age. Enter a positive number: ";
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    do {
        cout << "Enter gender (Male/Female): ";
        cin >> newClient.gender;
        if (newClient.gender != "Male" && newClient.gender != "Female" &&
            newClient.gender != "male" && newClient.gender != "female") {
            cout << "Invalid input. Please enter 'Male' or 'Female'.\n";
        }
    } while (newClient.gender != "Male" && newClient.gender != "Female" &&
        newClient.gender != "male" && newClient.gender != "female");

    do {
        cout << "Enter activity level (Sedentary/Light/Moderate/Active/VeryActive): ";
        cin >> newClient.activityLevel;
        if (newClient.activityLevel != "Sedentary" && newClient.activityLevel != "Light" &&
            newClient.activityLevel != "Moderate" && newClient.activityLevel != "Active" &&
            newClient.activityLevel != "VeryActive" && newClient.activityLevel != "sedentary" && newClient.activityLevel != "light" &&
            newClient.activityLevel != "moderate" && newClient.activityLevel != "active" &&
            newClient.activityLevel != "veryactive") {
            cout << "Invalid level. Try again.\n";
        }
    } while (newClient.activityLevel != "Sedentary" && newClient.activityLevel != "Light" &&
        newClient.activityLevel != "Moderate" && newClient.activityLevel != "Active" &&
        newClient.activityLevel != "VeryActive" && newClient.activityLevel != "sedentary" && newClient.activityLevel != "light" &&
        newClient.activityLevel != "moderate" && newClient.activityLevel != "active" &&
        newClient.activityLevel != "veryactive");

    newClient.trainerId = chooseTrainer();

    if (trainers[newClient.trainerId - 1].numClients < MAX_CLIENTS) {
        newClient.clientID = clientCount + 1;
        trainers[newClient.trainerId - 1].clients[trainers[newClient.trainerId - 1].numClients] = newClient;
        insertClient(db, newClient);
        trainers[newClient.trainerId - 1].numClients++;
        cout << "Client account created! Your ID is: " << newClient.clientID << "\n";
        clientCount++;
    }
    else {
        cout << "Client registration failed. System at capacity.\n";
    }
}



void registerUser() {
    int userType;
    cout << "Register as:\n";
    cout << "1. Trainer\n";
    cout << "2. Client\n";
    cout << "Enter choice: ";
    while (!(cin >> userType) || (userType != 1 && userType != 2)) {
        cout << "Invalid input. Enter 1 for Trainer or 2 for Client: ";
        cin.clear();
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    if (userType == 1) { // Trainer registration
        registerTrainer();
    }
    if (userType == 2)  // Client registration
        registerClient();
}

Client* clientLogin(string &username, string &password) {
    for (int j = 0; j < trainerCount; j++)
    {
        for (int i = 0; i < trainers->numClients; i++) {
            if (trainers[j].clients[i].username == username && trainers[j].clients[i].password == password) {
                return &trainers[j].clients[i];
            }
        }

    }
    return nullptr;
}

Trainer* trainerLogin(string &username, string &password) {
    for (int i = 0; i < trainerCount; i++) {
        if (trainers[i].username == username && trainers[i].password == password) {
            return &trainers[i];
        }
    }
    return nullptr;
}
#pragma endregion
// ================== MAIN FUNCTION ==================

