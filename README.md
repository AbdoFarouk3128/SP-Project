# Fitness Training Management System

This is a C++ project developed as a SP course assignment. The system is designed to manage fitness clients, trainers, workouts, and progress logs.

The project supports **two modes**:
- A **console-based application**
- A **Windows Forms GUI application** (using C++/CLI in Visual Studio)

## 🚀 How to Run

### ✅ Console Version

If you want to run the **console application**:

1. Open the project in Visual Studio.
2. Make sure **`ConsoleApp.cpp`** is **uncommented** (not excluded from the build).
3. Comment out or exclude all the other `.cpp` files related to the Windows Forms GUI (such as `MainForm.cpp`, `WelcomeForm.cpp`, etc.).
4. **Change the linker subsystem to Console:**
   - Go to **Project > Properties > Linker > System**
   - Set **Subsystem** to `Console (/SUBSYSTEM:CONSOLE)`
5. Build and run the project.

### ✅ Windows Forms GUI Version

If you want to run the **Windows Forms GUI** version:

1. Open the project in Visual Studio.
2. Comment out or exclude the file **`ConsoleApp.cpp`** from the build.
3. Uncomment or include all the GUI-related `.cpp` files (e.g., `MainForm.cpp`, `WelcomeForm.cpp`, etc.).
4. Make sure the correct startup form is set in your `main()`:
   ```cpp
   Application::Run(gcnew WelcomeForm());
