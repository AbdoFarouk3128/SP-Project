//#include <iostream>
//#include <string>
//#include <cstdlib>
//using namespace std;
//
//
//
//// ================== CONSTANTS ==================
//const int MAX_CLIENTS = 100;
//const int MAX_TRAINERS = 20;
//const int MAX_WORKOUTS = 10;
//const int MAX_EXERCISES = 10;
//const int MAX_MEASUREMENTS = 20;
//
//// ================== STRUCTURES ==================
//struct Measurement {
//    float weight;
//    float height;
//    string date;
//    float bmi;
//    double bmr;
//    double tdee;
//    struct Macros {
//        double protein;
//        double carbs;
//        double fats;
//    } macros;
//};
//
//struct Workout {
//    int workoutID;
//    string workoutName;
//    string exercises[MAX_EXERCISES];
//    int numExercises;
//    int duration;
//    int sets;
//    int reps;
//};
//
//struct Client {
//    int clientID;
//    string username;
//    string password;
//    int age;
//    string gender;
//    string activityLevel;
//    Workout workoutPlans[MAX_WORKOUTS];
//    int numWorkouts = 0;
//    Measurement measurements[MAX_MEASUREMENTS];
//    int numMeasurements = 0;
//};
//
//struct Trainer {
//    int trainerID;
//    string username;
//    string password;
//    //int clients[MAX_CLIENTS];
//    //int numClients = 0;
//};
//
//// ================== GLOBAL DATA ==================
//Client clients[MAX_CLIENTS];
//int clientCount = 0;
//Trainer trainers[MAX_TRAINERS];
//int trainerCount = 0;
//
//
//// ================== UTILITY FUNCTIONS ==================
//void clearScreen() {
//#ifdef _WIN32
//    system("cls");
//#else
//    system("clear");
//#endif
//}
//
//void pressEnter() {
//    cout << "\nPress Enter to continue...";
//    cin.ignore();
//    cin.get();
//}
//
//// ================== HEALTH CALCULATIONS ==================
//double calculateBMR(double weight, double height, int age, string gender) {
//    return (gender == "male") ?
//        (10 * weight) + (6.25 * height) - (5 * age) + 5 :
//        (10 * weight) + (6.25 * height) - (5 * age) - 161;
//}
//
//double getActivityMultiplier(string level) {
//    if (level == "sedentary") return 1.2;
//    if (level == "light") return 1.375;
//    if (level == "moderate") return 1.55;
//    if (level == "active") return 1.725;
//    return 1.9;
//}
//
//double calculateTDEE(double bmr, double activityMulti) {
//    return bmr * activityMulti;
//}
//
//Measurement::Macros calculateMacros(double tdee) {
//    Measurement::Macros m;
//    m.protein = (tdee * 0.3) / 4;
//    m.carbs = (tdee * 0.45) / 4;
//    m.fats = (tdee * 0.25) / 9;
//    return m;
//}
//
//double calculateBMI(float weight, float height) {  
//    float heightM = height / 100;
//    return weight / (heightM * heightM);
//}
//
//string getBMICategory(double bmi) {
//    if (bmi < 18.5) return "Underweight";
//    if (bmi < 25) return "Normal";
//    if (bmi < 30) return "Overweight";
//    return "Obese";
//}
//
//
//// client --> view health summary
//// ================== CLIENT FEATURES ===================
///Rawan
//void Veiw_Workout(Client &client) {
//    if (client.numWorkouts == 0) {
//        cout << "No Workouut Assigned Yet....\n";
//    }
//    else {
//        for (int i = 0; i < client.numWorkouts; i++) {
//            cout << i + 1 << ". " << client.workoutPlans[i].workoutName << "(" << client.workoutPlans[i].duration << "min)\n";
//            for (int j = 0; j < client.workoutPlans[i].numExercises; j++) {
//                cout << "- " << client.workoutPlans[i].exercises[j] << endl;
//            }
//        }
//    }
//}
//void Log_Workout(Client client) {
//
//}
//void client_menue(Client & client) {
//    int choice;
//    do {
//        clearScreen();
//        cout <<"======================= CLIENT MENUE =======================\n"
//            <<"1.Veiw Workout\n "
//            <<"2.Log Workout\n"
//            <<"3.Log Measurments\n"
//            <<"4.Health Summery\n"
//            <<"5.Logout\n";
//        cout <<"Enter Choice: ";
//        cin >> choice;
//        clearScreen();
//        switch (choice) {
//        case 1: Veiw_Workout(client_menu); 
//            break;
//        case 2:
//            Log_Workout(client); 
//            break;
//        case 3:
//            //log measurment
//            break;
//        case 4://health summery
//            break;
//        case 5:
//            cout << "Logout....";
//            break;
//        default:
//            cout << "Invalied Choice!\n";
//            break;
//        }
//
//        if (choice != 5) {
//            cout << "\nPress Enter to continue...";
//            cin.ignore(); cin.get();
//        }
//    } while (choice != 5);
//}
//
//
//// ================== TRAINER FEATURES ==================
//
//// rahma 
//
//// ================== AUTHENTICATION ==================
//
//// donia/rahma
//
//// ================== MAIN SYSTEM ==================
//
//void initializeSampleData() {
//    // Clients
//    clients[clientCount++] = { 1, "alice", "alice123", 21, "female","light" };
//    clients[clientCount++] = { 2, "bob", "bob123",25 };
//
//    // Trainers
//    trainers[trainerCount++] = { 1, "sarah", "sarah123" };
//
//    // Assign sample workouts --> Sarah
//
//}
//
//int main() {
//  initializeSampleData();   
//  //  client_menue(clients);
//    return 0;

#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
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

// ================== GLOBAL DATA ==================
Client clients[MAX_CLIENTS];
int clientCount = 0;
Trainer trainers[MAX_TRAINERS];
int trainerCount = 0;


// ================== UTILITY FUNCTIONS ==================
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

// ================== HEALTH CALCULATIONS ==================
double calculateBMR(double weight, double height, int age, string gender) {
    return (gender == "male") ?
        (10 * weight) + (6.25 * height) - (5 * age) + 5 :
        (10 * weight) + (6.25 * height) - (5 * age) - 161;
}

double getActivityMultiplier(string level) {
    if (level == "sedentary") return 1.2;
    if (level == "light") return 1.375;
    if (level == "moderate") return 1.55;
    if (level == "active") return 1.725;
    return 1.9;
}

double calculateTDEE(double bmr, double activityMulti) {
    return bmr * activityMulti;
}

Measurement::Macros calculateMacros(double tdee) {
    Measurement::Macros m;
    m.protein = (tdee * 0.3) / 4;
    m.carbs = (tdee * 0.45) / 4;
    m.fats = (tdee * 0.25) / 9;
    return m;
}

double calculateBMI(float weight, float height) {
    float heightM = height / 100;
    return weight / (heightM * heightM);
}

string getBMICategory(double bmi) {
    if (bmi < 18.5) return "Underweight";
    if (bmi < 25) return "Normal";
    if (bmi < 30) return "Overweight";
    return "Obese";
}


// client --> view health summary
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
    void Log_Workout(Client & client) { 
        if (client.numWorkouts == 0) {
            cout << "No workouutd assigned Yet ...\n";

        }
        else if (client.numLogs >= MAX_LOGS) {
            cout << "Log Limit Reached ...\n";

        }
        else  {
            string log;
            cout << "Enter workout name you completed: ";
            cin.ignore();
            getline(cin, log);  //to log more than word such that(chest day) , but cin>> recieve ane word only 
            client.progressLogs[client.numLogs++] = log;
            cout << "Workout Loged Successfully!\n";

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
            cout << "Enter height (kg): ";
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
                    cout << "\nPleae try again.";
                    cin.ignore();
                    cin.get();
                    clearScreen();
                }
                else dateValid = 1;
            }


            client.measurements[client.numMeasurements++] = log_measurement;
            cout << "Measurements Added Successfully!\n ";
        }
    }


    void client_menue(Client & client) {
        int choice;
        do {
            clearScreen();
            cout <<"======================= CLIENT MENUE =======================\n"
                <<"1.Veiw Workout\n "
                <<"2.Log Workout\n"
                <<"3.Log Measurments\n"
                <<"4.Health Summery\n"
                <<"5.Logout\n";
            cout <<"Enter Choice: ";
            cin >> choice;
            clearScreen();
            switch (choice) {
            case 1: Veiw_Workout(client);
                break;
            case 2:
                Log_Workout(client);  
                break;
            case 3:
                Log_Measurments(client);
                break;
            case 4://healthsummary(client);
                break;
            case 5:
                cout << "Logout....";
                break;
            default:
                cout << "Invalied Choice!\n";
                break;
            }
    
            if (choice != 5) {
                cout << "\nPress Enter to continue...";
                cin.ignore(); 
                cin.get();
            }
        } while (choice != 5);
    }
    //

// ================== TRAINER FEATURES ==================

// rahma 

// ================== AUTHENTICATION ==================

// donia/rahma


// ================== Database and Data Intry ===================

//sqlite3* opendatabase() {
//    sqlite3* db = nullptr;
//    const char* dbPath = "database.db";
// 
//    if (sqlite3_open(dbPath, &db) == SQLITE_OK) {
//        cout << "Database opened successfully: " << dbPath << endl;
//    }
//    else {
//        cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
//    }
// 
//    return db;
//}
//
//sqlite3* db= opendatabase(); // Database pointer

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
                    // You can calculate bmi, bmr, tdee later
                    clients[i].numMeasurements++;
                    break;
                }
            }
        }
    }
    sqlite3_finalize(stmt);
}

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
    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_text(stmt, 1, c.name.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 2, c.username.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 3, c.password.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_int(stmt, 4, c.age);
        sqlite3_bind_text(stmt, 5, c.gender.c_str(), -1, SQLITE_STATIC);
        sqlite3_bind_text(stmt, 6, c.activityLevel.c_str(), -1, SQLITE_STATIC);
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
    const char* query = "INSERT INTO Measurements (clientId, weight, height) VALUES (?, ?, ?);";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, query, -1, &stmt, nullptr) == SQLITE_OK) {
        sqlite3_bind_int(stmt, 1, clientId);
        sqlite3_bind_double(stmt, 2, m.weight);
        sqlite3_bind_double(stmt, 3, m.height);
        sqlite3_step(stmt);
    }
    sqlite3_finalize(stmt);
}



// ================== MAIN SYSTEM ==================


int main() {
    sqlite3* db;
    if (sqlite3_open("database.db", &db) == SQLITE_OK) {
        loadAllData(db);
    }
    else {
        cout << "Failed to open database." << endl;
    }
    for(int i=0;i<clientCount;i++)
        cout << clients[i].name << endl;

    return 0;
}
