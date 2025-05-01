#pragma once
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
//gui


// ================== CONSTANTS ==================
#pragma region Constants
const int MAX_CLIENTS = 100;
const int MAX_TRAINERS = 20;
const int MAX_WORKOUTS = 10;
const int MAX_EXERCISES = 10;
const int MAX_LOGS = 20;
const int MAX_MEASUREMENTS = 20;
const int MAX_USERNAME_ATTEMPTS = 5;
#pragma endregion
// ================== STRUCTURES ==================
#pragma region Structres
struct Measurement {
    float weight;
    float height;
    struct Date {
        int Day;
        int Month;
        int Year;
    } date;
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
    string istrue; // done / pending
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
    int numLogs = 0; // number of workout done
    Measurement measurements[MAX_MEASUREMENTS];
    int numMeasurements = 0;
    int trainerId;
};

struct Trainer {
    int trainerID;
    string name;
    string username;
    string password;
    Client clients[MAX_CLIENTS];
    int numClients = 0;
};
#pragma endregion
// ================== GLOBAL DATA ==================
#pragma region Global Data
extern int clientCount ;
extern Trainer trainers[MAX_TRAINERS];
extern int trainerCount ;
extern Workout predefineWorkout[MAX_WORKOUTS];
extern int numPredefinedWorkouts ;
extern sqlite3* db;

#pragma endregion
// ================== FUNCTION DECLARATIONS ==================
#pragma region Function Declarations
void clearScreen();
void pressEnter();
void clearInputBuffer();
string toLower(const string& str);
string joinLogs(string logs[], int numLogs);
bool isUsernameTaken(const string& username);
int splitLogs(string logsString, string logs[], int maxLogs);
string formatDate(Measurement::Date d);
void loadTrainers(sqlite3* db);
void loadClients(sqlite3* db);
void loadClientsOfTrainers(sqlite3* db);
void loadWorkouts(sqlite3* db);
void loadMeasurements(sqlite3* db);
void loadPredefinedWorkouts(sqlite3* db);
void loadAllData(sqlite3* db);
void insertTrainer(sqlite3* db, Trainer t);
void insertClient(sqlite3* db, Client c);
void insertWorkout(sqlite3* db, Workout w, int clientId);
void insertPredefinedWorkout(sqlite3* db, Workout w);
void insertMeasurement(sqlite3* db, Measurement m, int clientId);
void updateClientProgressLogs(sqlite3* db, int clientId, const string& logsStr);
void updatetheworkoutstatus(sqlite3* db, int workoutid);
double calculateBMR(Client& a);
double getActivityMultiplier(Client& a);
double calculateTDEE(double bmr, double activitylevel);
void calculateMacros(double tdee, Client& a);
double calculateBMI(Client& a);
string getBMICategory(double bmi);
void healthsummary(Client& client);
void Veiw_Workout(Client& client);
void Log_Workout(Client& client);
void Log_Measurments(Client& client);
void ViewMeasurements(Client& client);
void client_menue(Client& client);
void displayClientData(Client& c);
void ClientProgress(Client& client);
void TrainerMenu(Trainer& trainer);
bool checkclientid(Trainer& trainer, int selectedID);
int chooseTrainer();
void registerUser();
void registerTrainer();
void registerClient();
Trainer* trainerLogin(string username, string password);
Client* clientLogin(string username, string password);
void display_workouts();
int displayClientsAndSelect(Trainer& trainer);
void assign_workout(Client& client);
void createPredefinedWorkout();
Workout createCustomWorkout();
void display_workouts_to_client();
#pragma endregion
