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
    float bmi;
    string date;
    int age;
    string gender;
    string activityLevel;
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

