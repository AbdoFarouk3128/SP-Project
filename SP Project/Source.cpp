#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include "sqlite3.h"
using namespace std;

// ================== CONSTANTS ==================
const int MAX_CLIENTS = 100;
const int MAX_TRAINERS = 20;
const int MAX_WORKOUTS = 10;
const int MAX_EXERCISES = 10;
const int MAX_LOGS = 20;
const int MAX_MEASUREMENTS = 20;

// ================== STRUCTURES ==================
struct Measurement {
    float weight;
    float height;
    struct Date {
        int Day;
        int Month;
        int Year;
    }date;
    float bmi;
    double bmr;
    double tdee;
    struct Macros {
        double protein;
        double carbs;
        double fats;
    } macros;
};

struct Workout {
    int workoutID;
    string workoutName;
    string exercises[MAX_EXERCISES];
    int numExercises;
    int duration;
    int sets;
    int reps;
};

struct Client {
    int clientID;
    string name;
    string username;
    string password;
    int age;
    string gender;
    string activityLevel;
    Workout workoutPlans[MAX_WORKOUTS];
    int numWorkouts = 0;
    string progressLogs[MAX_LOGS];
    int numLogs = 0;
    Measurement measurements[MAX_MEASUREMENTS];
    int numMeasurements = 0;
};

struct Trainer {
    int trainerID;
    string name;
    string username;
    string password;
    //int clients[MAX_CLIENTS];
    //int numClients = 0;
};

//========sara======
/*
 //Workout predefineWorkout[MAX_WORKOUTS];
 const int MAX_EXERCISES_INWORKOUT = 3;
Workout trainer_choice;
int numPredefinedWorkouts=0 ;
int arr[MAX_WORKOUTS];
void display();
void display_workouts ();
int displayClientsAndSelect(Client clients[], int numClients);
void assign_workout();
void createPredefinedWorkout(Workout predefineWorkout[], int& numPredefinedWorkouts)
Workout createCustomWorkout();
void display_workouts_to_client();
*/

// ================== GLOBAL DATA ==================
Client clients[MAX_CLIENTS];
int clientCount = 0;
Trainer trainers[MAX_TRAINERS];
int trainerCount = 0;
//������ ��� �����
string usertype;     

//// ================== UTILITY FUNCTIONS ==================

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

string joinLogs(string logs[], int numLogs) {
    string result = "";
    for (int i = 0; i < numLogs; ++i) {
        result += logs[i];
        if (i != numLogs - 1)
            result += "|"; // use | as a separator
    }
    return result;
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

string formatDate(Measurement::Date d) {
    char buffer[11];
    snprintf(buffer, sizeof(buffer), "%02d-%02d-%04d", d.Day, d.Month, d.Year);
    return string(buffer);
}

// ================== Database and Data Intry ===================

// sqlite3* opendatabase() {
//     sqlite3* db = nullptr;
//     const char* dbPath = "database.db";
 
//     if (sqlite3_open(dbPath, &db) == SQLITE_OK) {
//         cout << "Database opened successfully: " << dbPath << endl;
//     }
//     else {
//         cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
//     }
 
//     return db;
// }

// sqlite3* db= opendatabase(); // Database pointer
sqlite3* db;
void loadTrainers(sqlite3* db) {
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

void loadClients(sqlite3* db) {
    clientCount = 0;
    const char* query = "SELECT * FROM Clients;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW && clientCount < MAX_CLIENTS) {
            clients[clientCount].clientID = sqlite3_column_int(stmt, 0);
            clients[clientCount].name = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            clients[clientCount].username = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            clients[clientCount].password = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
            clients[clientCount].age = sqlite3_column_int(stmt, 4);
            clients[clientCount].gender = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
            clients[clientCount].activityLevel = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
            const char* logsStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
            if (logsStr)
                clients[clientCount].numLogs = splitLogs(logsStr, clients[clientCount].progressLogs, MAX_LOGS);

            clientCount++;
        }
    }
    sqlite3_finalize(stmt);
}

void loadWorkouts(sqlite3* db) {
    const char* query = "SELECT * FROM Workouts;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int clientId = sqlite3_column_int(stmt, 7);
            for (int i = 0; i < clientCount; ++i) {
                if (clients[i].clientID == clientId && clients[i].numWorkouts < MAX_WORKOUTS) {
                    Workout& w = clients[i].workoutPlans[clients[i].numWorkouts];
                    w.workoutID = sqlite3_column_int(stmt, 0);
                    w.workoutName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
                    string exercisesStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
                    w.numExercises = sqlite3_column_int(stmt, 3);
                    w.duration = sqlite3_column_int(stmt, 4);
                    w.sets = sqlite3_column_int(stmt, 5);
                    w.reps = sqlite3_column_int(stmt, 6);

                    // Split exercises by comma
                    string temp;
                    int exCount = 0;
                    for (char ch : exercisesStr) {
                        if (ch == ',') {
                            w.exercises[exCount++] = temp;
                            temp.clear();
                        }
                        else {
                            temp += ch;
                        }
                    }
                    if (!temp.empty()) {
                        w.exercises[exCount++] = temp;
                    }

                    clients[i].numWorkouts++;
                    break;
                }
            }
        }
    }
    sqlite3_finalize(stmt);
}
void loadMeasurements(sqlite3* db) {
    const char* query = "SELECT * FROM Measurements;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        while (sqlite3_step(stmt) == SQLITE_ROW) {
            int clientId = sqlite3_column_int(stmt, 1);
            for (int i = 0; i < clientCount; ++i) {
                if (clients[i].clientID == clientId && clients[i].numMeasurements < MAX_MEASUREMENTS) {
                    Measurement& m = clients[i].measurements[clients[i].numMeasurements];
                    m.weight = sqlite3_column_double(stmt, 2);
                    m.height = sqlite3_column_double(stmt, 3);
                    const char* dateStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
                    if (dateStr && strlen(dateStr) == 10) {
                        sscanf(dateStr, "%2d-%2d-%4d", &m.date.Day, &m.date.Month, &m.date.Year);
                    }
                    // You can calculate bmi, bmr, tdee later
                    clients[i].numMeasurements++;
                    break;
                }
            }
        }
    }
    sqlite3_finalize(stmt);
}
/*
/ void loadPredefinedWorkouts(sqlite3 db) {
    const char* query = "SELECT * FROM PredefinedWorkouts;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        int count = 0;
        while (sqlite3_step(stmt) == SQLITE_ROW && count < MAX_PREDEFINED_WORKOUTS) {
            predefineWorkout[count].workoutID = sqlite3_column_int(stmt, 0);
            predefineWorkout[count].workoutName = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
            string exercisesStr = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            predefineWorkout[count].duration = sqlite3_column_int(stmt, 4);
            predefineWorkout[count].sets = sqlite3_column_type(stmt, 5) != SQLITE_NULL ? sqlite3_column_int(stmt, 5) : 0;
            predefineWorkout[count].reps = sqlite3_column_type(stmt, 6) != SQLITE_NULL ? sqlite3_column_int(stmt, 6) : 0;

            // Split exercises
            string temp;
            int exCount = 0;
            for (char ch : exercisesStr) {
                if (ch == ',') {
                    predefineWorkout[count].exercises[exCount++] = trim(temp);
                    temp.clear();
                }
                else {
                    temp += ch;
                }
            }
            if (!temp.empty()) {
                predefineWorkout[count].exercises[exCount++] = trim(temp);
            }

            predefineWorkout[count].numExercises = exCount;

            count++;
        }
    }
    sqlite3_finalize(stmt);
}
*/

void loadAllData(sqlite3* db) {
    loadTrainers(db);
    loadClients(db);
    loadWorkouts(db);
    loadMeasurements(db);
}

void insertTrainer(sqlite3* db, Trainer t) {
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
    const char* query = "INSERT INTO Clients (name, username, password, age, gender, activityLevel) VALUES (?, ?, ?, ?, ?, ?);";
    sqlite3_stmt* stmt;
    string logsString = joinLogs(c.progressLogs, c.numLogs);

    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, c.name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, c.username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, c.password.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 4, c.age);
        sqlite3_bind_text(stmt, 5, c.gender.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 6, c.activityLevel.c_str(), -1, SQLITE_STATIC);
        // sqlite3_bind_text(stmt, 7, logsString.c_str(), -1, SQLITE_STATIC);
        sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}

void insertWorkout(sqlite3* db, Workout w, int clientId) {
    const char* query = "INSERT INTO Workouts (workoutName, exercises, numExercises, duration, sets, reps, clientId) VALUES (?, ?, ?, ?, ?, ?, ?);";
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
        sqlite3_bind_int(stmt, 7, clientId);
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

// ================== HEALTH CALCULATIONS ==================
double calculateBMR(Client& a) {
    int index = a.numMeasurements - 1;

    if (a.gender == "male" || a.gender == "Male")
        return 10.0 * a.measurements[index].weight + 6.25 * a.measurements[index].height - 5.0 * a.age + 5.0;
    else if (a.gender == "female" || a.gender == "Female")
        return  10.0 * a.measurements[index].weight + 6.25 * a.measurements[index].height - 5.0 * a.age - 161.0;
    else
    {
        cout << "INVALID CHOICE" << endl;
        return 0;
    }
}

double getActivityMultiplier(Client& a) {//c.activity
    if (a.activityLevel == "sedentary" || a.activityLevel == "Sedentary") return 1.2;
    else if (a.activityLevel == "light" || a.activityLevel == "Light") return 1.375;
    else if (a.activityLevel == "moderate" || a.activityLevel == "Moderate")  return 1.55;
    else if (a.activityLevel == "active" || a.activityLevel == "Active")  return 1.725;
    else if (a.activityLevel == "Very active" || a.activityLevel == "very active")
        return 1.9;
    else
    {
        cout << "Invalid activity level" << endl;
        return 1.0;
    }
}
  
double calculateTDEE(double bmr, double activitylevel) {
    return (bmr) * (activitylevel);
}

void calculateMacros(double tdee, Client& a) {

    a.measurements[a.numMeasurements - 1].macros.protein = (tdee * 0.3) / 4;
    a.measurements[a.numMeasurements - 1].macros.carbs = (tdee * 0.45) / 4;
    a.measurements[a.numMeasurements - 1].macros.fats = (tdee * 0.25) / 9;
    cout << "\n--- YOUR MACRONUTRIENTS ---" << endl;
    cout << "Protein (grams): " << a.measurements[a.numMeasurements - 1].macros.protein << endl;
    cout << "Carbohydrates (grams): " << a.measurements[a.numMeasurements - 1].macros.carbs << endl;
    cout << "Fats (grams): " << a.measurements[a.numMeasurements - 1].macros.fats << endl;
}


double calculateBMI(Client& a){

    float heightInMeters = a.measurements[a.numMeasurements - 1].height / 100.0;
    return a.measurements[a.numMeasurements - 1].weight / (heightInMeters * heightInMeters);
}


string getBMICategory(double bmi) {
    if (bmi < 18.5) return "Underweight";
    else if (bmi < 25) return "Normal";
    else if (bmi < 30) return "Overweight";
    else
        return "Obese";
}


void  healthsummary(Client& client) {
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
    cout << "Your BMI(Body Mass Index) = " << bmi << "| Your Status is " << status << endl;
    cout << "Your BMR(Basel Metabolic Rate) = " << bmr << endl;
    cout << "Your TDEE(Total Daily Energy Expenditure) = " << tdee << endl;
    calculateMacros(tdee, client);
}

// ================== CLIENT FEATURES ==================
void Veiw_Workout(Client& client) {
    if (client.numWorkouts == 0) {
        cout << "No workouuts assigned Yet....\n";
    }
    else {
        for (int i = 0; i < client.numWorkouts; i++) {
            cout << i + 1 << ". " << client.workoutPlans[i].workoutName << "(" << client.workoutPlans[i].duration << "min)\n";
            for (int j = 0; j < client.workoutPlans[i].numExercises; j++) {
                cout << "- " << client.workoutPlans[i].exercises[j] << endl;
            }
        }
    }
}
void Log_Workout(Client& client) {
    if (client.numWorkouts == 0) { //number of workout
        cout << "No workouts assigned Yet ...\n";

    }
    else if (client.numLogs >= MAX_LOGS){ // number of completed workout
        cout << "Log Limit Reached ...\n";

    }
    else {
        // viwe all workouts 

        string log; // -> workout.id
        cout << "Enter workout name you completed: ";
        cin.ignore();
        getline(cin, log);  //to log more than word such that(chest day) , but cin>> recieve ane word only 
        client.progressLogs[client.numLogs++] = log;// workout.name
        cout << "Workout Loged Successfully!\n";
        updateClientProgressLogs(db,client.clientID,joinLogs(client.progressLogs,client.numLogs));

    }
}

bool LeapYear(int year) {
    if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
        return true;
    }
    else {
        return false;
    }
}

int days_month = 0;
bool invalidDate(int day, int month, int year) {
    if (year < 1) return 1;
    else if (month < 1 || month>12) return 1;
    else if (day < 1) return 1;
    int days_month = 31;
    switch (month) {
    case 4:
    case 6:
    case 9:
    case 11:
        days_month = 30;
        break;
    case 2:
        days_month = LeapYear(year) ? 29 : 28;

        break;
    default:
        return 1;
    }
    return day > days_month;
}
void Log_Measurments(Client& client) {
    if (client.numMeasurements >= MAX_MEASUREMENTS) {
        cout << "Measurements Limit Reached ...\n";
    }
    else {
        Measurement log_measurement;
        cout << "Enter weight (kg): ";
        cin >> log_measurement.weight;
        cout << "Enter height (cm): ";
        cin >> log_measurement.height;
        bool dateValid = 0;
        while (!dateValid) {
            cout << "Enter date:\n";
            cout << "Day: ";
            cin >> log_measurement.date.Day;

            cout << "Month: ";
            cin >> log_measurement.date.Month;

            cout << "Year: ";
            cin >> log_measurement.date.Year;

            if (invalidDate(log_measurement.date.Day, log_measurement.date.Month, log_measurement.date.Year)) {
                cout << "Invalid date.....\n";
                cout << "\nPleaese try again.";
                cin.ignore();
                cin.get();
                //clearScreen();
            }
            else dateValid = 1;
            
        }
        //rawan
        /*
void Log_Workout(Client& client) {
    if (client.numWorkouts == 0) { //number of workout
        cout << "No workouts assigned Yet ...\n";

    }
    else if (client.numLogs >= MAX_LOGS) { // number of completed workout
        cout << "Log Limit Reached ...\n";

    }
    else {
        string log;
        cout << "Enter workout name you completed: ";
        cin.ignore();
        getline(cin, log);  //to log more than word such that(chest day) , but cin>> recieve ane word only
        client.progressLogs[client.numLogs++] = log;
        cout << "Workout Loged Successfully!\n";
        updateClientProgressLogs(db, client.clientID, joinLogs(client.progressLogs, client.numLogs));

    }

}*/
// log workout ===sara=====

/*
void Log_Workout(Client& client, sqlite3* db) {
    if (client.numWorkouts == 0) {
        cout << "No workouts assigned Yet ...\n";
    } else if (client.numLogs >= MAX_LOGS) {
        cout << "Log Limit Reached ...\n";
    } else {
        string log;
        cout << "Enter workout name you completed: ";
        cin.ignore();
        getline(cin, log);

        client.progressLogs[client.numLogs++] = log;
        cout << "Workout Logged Successfully!\n";

        updateClientProgressLogs(db, client.clientID, joinLogs(client.progressLogs, client.numLogs));
    }
}
*/


        client.measurements[client.numMeasurements++] = log_measurement;
        insertMeasurement(db,log_measurement,client.clientID);
        cout << "Measurements Added Successfully!\n ";
    }
}
void ViewMeasurements(Client& client) {
    if (client.numMeasurements == 0) {
        cout << "No measurements recorded yet.\n";
        return;
    }

    cout << "======= Measurements History =======\n";
    for (int i = 0; i < client.numMeasurements; i++) {
        cout << i + 1 << ". "
            << "Date: " << client.measurements[i].date.Day << "/"
            << client.measurements[i].date.Month << "/"
            << client.measurements[i].date.Year
            << " | Weight: " << client.measurements[i].weight << "kg"
            << " | Height: " << client.measurements[i].height << "m\n";
    }
}


void client_menue(Client& client) {
    int choice;
  
    do {
        //clearScreen(); 
        cout <<"======================= CLIENT MENUE =======================\n"
            << "1.Veiw Workout\n"
            << "2.Log Workout\n"
            << "3.Log Measurments\n"
            << "4.Health Summery\n"
            <<"5.ViewMeasurements\n"
            << "6.Logout\n";
        cout << "Enter Choice: ";
        cin >> choice;
        //clearScreen();
        switch (choice) {
        case 1: Veiw_Workout(client);
            break;
        
        case 2:
            Log_Workout(client);
            break;

        case 3:
            Log_Measurments(client);
            break;

        case 4:
             healthsummary(client);
            break;

        case 5:
            ViewMeasurements(client);
            break;

        case 6:
            cout << "Logout....";
            break;

        default:
            cout << "Invalied Choice!\n";
            break;
        }

        if (choice != 6) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 6);
}

//
     
// ================== TRAINER FEATURES ==================
// rahma 
void displayClientData( Client & c) {
    cout << "Full Name: " << c.name << " , " << "Age: " << c.age << " , " << "Gender: " << c.gender << " , ";
    cout << "Activity Level: " << c.activityLevel << endl;
}
void  ClientProgress(Client&client) {
    cout << "--------------Completed Workout---------------\n";
    if (client.numLogs == 0) {
        cout << "There is no progresslogs for this client!\n";
    }
    else {
        for (int i = 0; i < client.numLogs; i++) {

            cout << i + 1 << "." << client.progressLogs[i] << endl;
        }
    }
    cout << "Weight Trend: "<<client.measurements[client.numMeasurements-1].weight<<" Kg" << endl;

}
void TrainerMenu() {
    int choice;
    do {
        cout << "\n===Trainer Menu===\n";
        cout << "1-View Clients Information\n";
        //cout << "2-Assign Workouts to client\n";
        cout << "2-workouts\n";
        cout << "3-View Client Progress\n";
        //cout << "4-Creat special workout for client\n";
        cout << "4-Logout\n";
        cout << "Enter your choice: ";
        cin >> choice;
        //clearScreen();
        switch (choice) {
        case 1:
            cout << "\n---------Client Information-----------\n";
            //displayClientData(client_m
            break;
        case 2://assign workout
            /*
                 display();
                 int choice;
                 cin >> choice;
                 while (cin.fail())
                 {
                     cout << " Its Invalid . Enter 1 or 2 ,PLease .";
                     display();
                     cin >> choice;
                 }
                  int clientID = displayClientsAndSelect(clients, numClients);


                int clientIndex = -1;
                for (int i = 0; i < numClients; i++) {
                    if (clients[i].clientID == clientID) {
                        clientIndex = i;
                        break;
                    }
                }


                if (clientIndex == -1) {
                    cout << "Client not found!\n";
                    break;
                }
                 Client& selectedClient = clients[clientIndex];

                 if (choice == 1)
                 {
                  assign_workout();
                  }
                  else if (choice == 2)
                  {
                createPredefinedWorkout(predefineWorkout, numPredefinedWorkouts);


                  }
                   else
                {
                NEW = createCustomWorkout();
               }
               */

            break;
        case 3:
            //ClientProgress(client_m);
            break;

        case 4: cout << "Logout.....\n";
            break;
        default:cout << "Invalid Choice\n";
        }
        if (choice != 5) {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }
    } while (choice != 5);



}

// ================== AUTHENTICATION ==================

void registerUser() {
    string name,username, pass, gender, level;
    int age;
    
    cout << "Enter Name: ";cin >> name;
    bool exists;
    do {
        exists = false;
        cout << "Enter username: ";
        cin >> username;

        for (int i = 0; i < trainerCount; i++) {
            if (clients[i].username == username) {
                cout << "Username already taken. Try another.\n";
                exists = true;
                break;
            }
        }
    } while (exists);

    cout << "Enter password: ";
    cin >> pass;

    cout << "Enter age: ";
    while (!(cin >> age) || age <= 0) {
        cout << "Invalid input. Please enter a valid age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    do {
        cout << "Enter gender (Male/Female): ";
        cin >> gender;
        if (gender != "Male" && gender != "Female") {
            cout << "Invalid input. Please enter 'Male' or 'Female'.\n";
        }
    } while (gender != "Male" && gender != "Female");

    do {
        cout << "Enter activity level (Sedentary/Light/Moderate/Active/VeryActive): ";
        cin >> level;
        if (level != "Sedentary" && level != "Light" && level != "Moderate" && level != "Active" && level != "Very Active") {
            cout << "Invalid level. Try again.\n";
        }
    } while (level != "Sedentary" && level != "Light" && level != "Moderate" && level != "Active" && level != "Very Active");

    clients[clientCount].clientID= clientCount + 1;
    clients[clientCount].name = name;
    clients[clientCount].username = username;
    clients[clientCount].password = pass;
    clients[clientCount].age = age;
    clients[clientCount].gender = gender;
    clients[clientCount].activityLevel= level;

    clients[clientCount].clientID = clientCount + 1;
    cout << "Account created! Your ID is: " << clients[clientCount].clientID<< "\n";
    clientCount++;
    insertClient(db,clients[clientCount-1]);
}

// donia/rahma
/// ------------ Log in ------------
// void initializeSampleData(Client &client) {
//     // Clients
//     clients[clientCount++] = { 1, "alice","alice", "alice123", 21, "female","light"};
//     clients[clientCount++] = { 2, "bob","bobi", "bob123",25 };

//     // Trainers
//     trainers[trainerCount++] = { 1, "sarah", "sarah123" };

//     // Assign sample workouts --> Sarah

// }
int login() {
    string username, password;
    cout << "===LOGIN===" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // check client

    for (int i = 0; i < clientCount; i++) {
        if (clients[i].username == username && clients[i].password == password)
        {
            usertype = "client";
            cout << "Login successfully as client,Welcome " << clients[i].username << endl;
            return i;
        }
    }

    //check trainer

    for (int i = 0; i < trainerCount; i++) {
        if (trainers[i].username == username && trainers[i].password == password)
        {
            usertype = "trainer";
            cout << "Login successfully as trainer,Welcome " << trainers[i].username << endl;
            return i;
           
        }
    }
    cout << "Invalid username or password." << endl;
    return -1;
}






// ================== MAIN SYSTEM ==================


int main() {
    
    if (sqlite3_open("database.db", &db) == SQLITE_OK) {
        loadAllData(db);
    }
    else {
        cout << "Failed to open database." << endl;
    }
    //------------------------------------------------------
    int mainChoice;
    for (int i = 0; i < clientCount; i++)
    {
        cout << clients[i].name << endl;
    }cout << clientCount << endl;
    cout<<clients[0].clientID<<endl;
    do {
        //clearScreen();
        cout << "\n=== FITNESS MANAGEMENT SYSTEM ===\n"
            << "1. Login\n"
            << "2. Register\n"
            << "3. Exit\n"
            << "Choice: ";
        cin >> mainChoice;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        switch (mainChoice)
        {
        case 1:
        {
            int index = login();
            if (index != -1) {
                if (usertype == "client") {
                    client_menue(clients[index]);
                }
                else if (usertype == "trainer") {
                    TrainerMenu();
                }
            }
            break;
        }
        case 2:
            registerUser();
            break;
        case 3:
            break;
        default:
            cout << "invalid input" << endl;
            break;
        }


    } while (mainChoice != 3);

    cout << "Exiting system...\n";
    return 0;
}
/*

   void display() {
    cout << "Please,Enter Your Choice 1 or 2 \n";
    cout << "===========================\n";
    cout << "Do You Want  1) Predefine Workout\n">>
   " 2) creat Predefine Workout\n">>
   "3) creat custom workout \n";

   ============================================================

void display_workouts () {
    for (int i = 0; i < MAX_WORKOUTS;i++)
    {
        cout << i + 1 << predefineWorkout[i].workoutName << endl;
        for (int j = 0;j < MAX_EXERCISES_INWORKOUT;j++)
        {
            cout << predefineWorkout[i].exercises[j];
        }
        cout << predefineWorkout[i].numExercises << endl <<
            predefineWorkout[i].duration << endl <<
            predefineWorkout[i].sets << endl <<
            predefineWorkout[i].reps << endl;
    }
};
===================================================================
    //client list
    int displayClientsAndSelect(Client clients[], int numClients) {
    cout << "=== CLIENT LIST ===\n";
    for (int i = 0; i < numClients; i++) {
        cout << "ID: " << clients[i].clientID
             << " | Name: " << clients[i].name
             << " | Workouts: " << clients[i].numWorkouts << "\n";
    }

    int selectedID;
    cout << "\nEnter client ID: ";
    cin >> selectedID;
    return selectedID;
}


};
=================================================================
     void assign_workout(Client& client)
     {
        int num_Of_PredefineWorkout;
       //display workouts for trainer
        display_workouts();

       //input of trainer choice
       cout << "Please , Enter How many predefineWorkout do you want  \n";
       cin >> num_Of_PredefineWorkout;
       cout << "Enter the number of each predefined workout you choose  ";
       for (int i = 0;i < num_Of_PredefineWorkout;i++)
           cin >> arr[i];
           cout <<"assignworkout created successfully!\n";
     }
     ================================================================
     void createPredefinedWorkout(Workout predefineWorkout[], int& numPredefinedWorkouts) {
    if (numPredefinedWorkouts >= MAX_WORKOUTS) {
        cout << "Workout limit reached! Cannot add more predefined workouts.\n";
        return;
    }

    Workout newWorkout;

    cout << "Enter workout name: ";
    cin.ignore();
    getline(cin, newWorkout.workoutName);

    cout << "Enter number of exercises (max " << MAX_EXERCISES << "): ";
    cin >> newWorkout.numExercises;
    cin.ignore();

    for (int i = 0; i < newWorkout.numExercises && i < MAX_EXERCISES; ++i) {
        cout << "Enter exercise " << i + 1 << ": ";
        getline(cin, newWorkout.exercises[i]);
    }

    cout << "Enter duration (in minutes): ";
    cin >> newWorkout.duration;

    cout << "Enter number of sets: ";
    cin >> newWorkout.sets;

    cout << "Enter number of reps: ";
    cin >> newWorkout.reps;

    newWorkout.workoutID = numPredefinedWorkouts + 1;

    predefineWorkout[numPredefinedWorkouts++] = newWorkout;

    cout << "Predefined workout created successfully!\n";
}
=====================================================================

     Workout createCustomWorkout(Client& client) {
      Workout NEW;
         cout << "Please ,Enter 1- Workout Name\n"
             << " 2- num of exercises "
             << " 3- exercises\n"
             << " 4- Duration\n"
             << " 5- sets\n"
             << " 6- reps\n";
         cin.ignore();
      getline(cin, NEW.workoutName);
      cout << "Enter number of exercises: ";
     cin>> NEW.numExercises;
     cin.ignore();
   for (int i = 0; i < NEW.numExercises; i++) {
    cout << "Exercise " << i + 1 << ": ";
    getline(cin, NEW.exercises[i]);
   }
         cin >> NEW.duration;
         cin >> NEW.sets;
         cin >> NEW.reps;

         return NEW;
     }





     ============================================================
     void display_workouts_to_client(Client& client) {
         for (int i = 0;i < num_Of_PredefineWorkout;i++)
         {
             cout << i + 1 << predefineWorkout[arr[i] + 1].workoutName << endl;
             for (int j = 0;j < MAX_EXERCISES_INWORKOUT;j++)
             {
                 cout << predefineWorkout[i].exercises[j];
             }
             cout << predefineWorkout[arr[i] + 1].numExercises << endl <<
                 predefineWorkout[arr[i] + 1].duration << endl <<
                 predefineWorkout[arr[i] + 1].sets << endl <<
                 predefineWorkout[arr[i] + 1].reps << endl;
         }
     };
     */