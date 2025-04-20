#include <iostream>
#include <string>
#include <cstdlib>
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
    string username;
    string password;
    Workout workoutPlans[MAX_WORKOUTS];
    int age;
    string gender;
    string activityLevel;
    int numWorkouts = 0;
    Measurement measurements[MAX_MEASUREMENTS];
    int numMeasurements = 0;
};

struct Trainer {
    int trainerID;
    string username;
    string password;
    int clients[MAX_CLIENTS];
    int numClients = 0;
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
