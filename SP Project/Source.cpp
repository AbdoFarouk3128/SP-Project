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
    double weight;
    double height;
    string date;
    float bmi;
    double bmr;
    double tdee;
    struct Macros {
        double protein;
        double carbs;
        double fats;
    }macros;
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
Measurement w = { 75,160,"24-04-23" };
Client a = { 0,"","",23,"male","light" };
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
double calculateBMR(Client & a ) {
    a.measurements[a.numMeasurements - 1].height *= 100;
  
    if (a.gender == "male" || a.gender == "Male")
       return (10 * a.measurements[a.numMeasurements - 1].weight) + (6.25 * a.measurements[a.numMeasurements - 1].height) - (5 * a.age) + 5;
    else if (a.gender == "female" || a.gender == "Female")
      return  (10 * a.measurements[a.numMeasurements - 1].weight) + (6.25 * a.measurements[a.numMeasurements - 1].height) - (5 * a.age) - 161;
    else
    {
        cout << "INVALID CHOICE" << endl;
        return 0;
    }
}

double getActivityMultiplier(Client & a) {//c.activity
    if ( a.activityLevel== "sedentary" || a.activityLevel == "Sedentary") return 1.2;
    else if (a.activityLevel == "light" ||a.activityLevel == "Light") return 1.375;
    else if (a.activityLevel == "moderate"|| a.activityLevel== "Moderate")  return 1.55;
    else if (a.activityLevel == "active"||a.activityLevel == "Active")  return 1.725;
    else if (a.activityLevel== "Very active" || a.activityLevel == "very active")
        return 1.9;
    else
    {
        cout << "Invalid activity level" << endl;
        return 1.0;
    }
}

double calculateTDEE(double bmr,double activitylevel) {
    return (bmr) * (activitylevel);
}

 void calculateMacros( double tdee,Client & a) {
   
     a.measurements[a.numMeasurements - 1].macros.protein = (tdee * 0.3) / 4;
    a.measurements[a.numMeasurements - 1].macros.carbs = (tdee * 0.45) / 4;
    a.measurements[a.numMeasurements - 1].macros.fats = (tdee * 0.25) / 9;
    cout << "\n--- YOUR MACRONUTRIENTS ---" << endl;
    cout << "Protein (grams): " << a.measurements[a.numMeasurements - 1].macros.protein << endl;
    cout << "Carbohydrates (grams): " << a.measurements[a.numMeasurements - 1].macros.carbs << endl;
    cout << "Fats (grams): " << a.measurements[a.numMeasurements - 1].macros.fats << endl;
 }


double calculateBMI(Client & a) {
   
    a.measurements[a.numMeasurements - 1].height/= 100.0;
    return  a.measurements[a.numMeasurements - 1].weight / (a.measurements[a.numMeasurements - 1].height * a.measurements[a.numMeasurements - 1].height);
}


string getBMICategory(double bmi) {
    if (bmi < 18.5) return "Underweight";
    else if (bmi < 25) return "Normal";
    else if (bmi < 30) return "Overweight";
    else
        return "Obese";
}


void  healthsummary() {
    if (a.numMeasurements == 0) {
        cout << "No measurements available to generate health summary." << endl;
        return;
    }
    double activityMulti = getActivityMultiplier(a);
    double bmi = calculateBMI(a);
    string status = getBMICategory(bmi);
    double bmr = calculateBMR(a);
    double tdee = calculateTDEE(bmr, activityMulti);
    cout << "------HEALTH SUMMARY------" << endl;
    cout << "Your BMI(Body Mass Index) = " << bmi << "| Your Status is " << status << endl;
    cout << "Your BMR(Basel Metabolic Rate) = " << bmr << endl;
    cout << "Your TDEE(Total Daily Energy Expenditure) = " << tdee << endl;
    calculateMacros(tdee, a);
}
    int main()
    {
        a.measurements[0] = w;
        a.numMeasurements = 1;
        healthsummary();
    
      


        return 0;

}

// client --> view health summary
// ================== CLIENT FEATURES ==================

// Rawan

// ================== TRAINER FEATURES ==================

// rahma 

// ================== AUTHENTICATION ==================

// donia/rahma

// ================== MAIN SYSTEM ==================

void initializeSampleData() {
    // Clients
    clients[clientCount++] = { 1, "alice", "alice123", 21, "female","light" };
    clients[clientCount++] = { 2, "bob", "bob123",25 };

    // Trainers
    trainers[trainerCount++] = { 1, "sarah", "sarah123" };

    // Assign sample workouts --> Sarah

}

int main() {
   // initializeSampleData();
    healthsummary();

    return 0;
}