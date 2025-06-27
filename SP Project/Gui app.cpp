#include "core.h"
#include "LoginForm.h"
#include "sqlite3.h"

using namespace System;
using namespace System::Windows::Forms;
//using namespace FitnessGUI;
using namespace SPProject;

sqlite3* db = nullptr;
int clientCount = 0;
int trainerCount = 0;
int numPredefinedWorkouts = 0;
Trainer* trainers = new Trainer[MAX_TRAINERS];
Workout* predefineWorkout = new Workout[MAX_WORKOUTS];


[STAThread]
int main(cli::array<System::String^>^ args)  // Use cli::array instead of just array
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    if (sqlite3_open("database.db", &db) != SQLITE_OK) {
        MessageBox::Show("Database error.");
        return 1;
    }

    loadAllData(db);

    Application::Run(gcnew LoginForm());

    sqlite3_close(db);

    delete[] trainers;
    delete[] predefineWorkout;
    trainers = 0;
    predefineWorkout = 0;

    
    return 0;
}