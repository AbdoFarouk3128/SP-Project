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
//}client_menu;
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
//// Rawan
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
//void Log_Workout(Client client[]) {
//
//}
//void client_menue(Client client[]) {
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
//    client_menue(clients);
//    return 0;
//}