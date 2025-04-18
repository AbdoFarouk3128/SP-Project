#include "FristForm.h"
using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew SPProject::FristForm());
    return 0;
}