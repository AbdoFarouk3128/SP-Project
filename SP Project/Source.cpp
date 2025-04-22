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
const int MAX_MEASUREMENTS = 20;

// ================== STRUCTURES ==================
struct Measurement {
    float weight;
    float height;
    string date;
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

// Rawan

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