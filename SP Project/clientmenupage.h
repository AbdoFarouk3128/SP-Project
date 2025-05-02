#pragma once
#include "core.h"
#include <msclr/marshal_cppstd.h>
namespace SPProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for clientmenupage
	/// </summary>
	public ref class clientmenupage : public System::Windows::Forms::Form
	{


	public:
		Client* client;
	public:
		clientmenupage(Client * c)
		{
			client = c;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	//public:
	//  	void LogWorkout(Client* client,
	//		ListBox^ lstWorkouts,
	//		Label^ lblStatus,
	//		TextBox^ txtWorkoutNumber,
	//		Button^ btnLogWorkout,
	//		DataGridView^ dgvProgressLogs)
	//	{
	//		// التحقق من وجود تمارين
	//		if (client->numWorkouts == 0) {
	//			MessageBox::Show("No workouts assigned yet.", "Information",
	//				MessageBoxButtons::OK, MessageBoxIcon::Information);
	//			return;
	//		}

	//		// التحقق من الوصول للحد الأقصى للسجلات
	//		if (client->numLogs >= MAX_LOGS) {
	//			MessageBox::Show("Log limit reached.", "Warning",
	//				MessageBoxButtons::OK, MessageBoxIcon::Warning);
	//			return;
	//		}

	//		// تعبئة ListBox بالتمارين
	//		lstWorkouts->Items->Clear();
	//		for (int i = 0; i < client->numWorkouts; i++) {
	//			String^ workoutInfo = String::Format("{0}- {1} | Status: {2}",
	//				i + 1,
	//				client->workoutPlans[i]->workoutName,
	//				client->workoutPlans[i]->istrue);
	//			lstWorkouts->Items->Add(workoutInfo);
	//		}

	//		// تمكين عناصر التحكم
	//		txtWorkoutNumber->Enabled = true;
	//		btnLogWorkout->Enabled = true;
	//		lblStatus->Text = "Select workout number and click Log";
	//	}

	//	// دالة مساعدة لمعالجة تسجيل التمرين
	//private: System::Void btnLogWorkout_Click(System::Object^ sender, System::EventArgs^ e) {
	//	int log;


	//	// التحقق من صحة الإدخال
	//	if (!Int32::TryParse(txtWorkoutNumber->Text, log)) {
	//		MessageBox::Show("Please enter a valid number.", "Error",
	//			MessageBoxButtons::OK, MessageBoxIcon::Error);
	//		return;
	//	}

	//	// التحقق من نطاق الرقم
	//	if (log < 1 || log > client->numWorkouts) {
	//		MessageBox::Show("Invalid workout number.", "Error",
	//			MessageBoxButtons::OK, MessageBoxIcon::Error);
	//		return;
	//	}

	//	// التحقق إذا كان التمرين مسجل مسبقاً
	//	if (client.workoutPlans[log - 1]->istrue == "Done") {
	//		MessageBox::Show("This workout has been done before. Choose another one.",
	//			"Information",
	//			MessageBoxButtons::OK, MessageBoxIcon::Information);
	//		return;
	//	}

	//	// تسجيل التمرين
	//	client->progressLogs[client->numLogs++] = client->workoutPlans[log - 1]->workoutName;
	//	client->workoutPlans[log - 1]->istrue = "Done";

	//	// تحديث واجهة المستخدم
	//	UpdateProgressLogsDisplay(dgvProgressLogs, client);
	//	MessageBox::Show("Workout logged successfully!", "Success",
	//		MessageBoxButtons::OK, MessageBoxIcon::Information);

	//	// تحديث قاعدة البيانات
	//	UpdateClientProgressLogs(db, client->clientID, JoinLogs(client->progressLogs, client->numLogs));
	//	UpdateWorkoutStatus(db, client->workoutPlans[log - 1]->workoutID);

	//	// تعطيل عناصر التحكم بعد التسجيل
	//	txtWorkoutNumber->Text = "";
	//	txtWorkoutNumber->Enabled = false;
	//	btnLogWorkout->Enabled = false;
	//}

	//	   // دالة مساعدة لتحديث عرض سجلات التقدم
	//	   void UpdateProgressLogsDisplay(DataGridView^ dgv, Client client) {
	//		   dgv->Rows->Clear();
	//		   for (int i = 0; i < client->numLogs; i++) {
	//			   dgv->Rows->Add(client->progressLogs[i]);
	//		   }
	//	   }

	//	   // دالة مساعدة لدمج السجلات (إذا كنت بحاجتها)
	//	   String^ JoinLogs(array<String^>^ logs, int count) {
	//		   return String::Join(", ", logs);
	//	   }
	//public:
	//	static double CalculateBMR(Client*client) {
	//		int index = client->numMeasurements - 1;
	//		String^ gender = client->gender->ToLower();

	//		if (gender == "male")
	//			return 10.0 * client->measurements[index]->weight +
	//			6.25 * client->measurements[index]->height -
	//			5.0 * client->age + 5.0;
	//		else if (gender == "female")
	//			return 10.0 * client->measurements[index]->weight +
	//			6.25 * client->measurements[index]->height -
	//			5.0 * client->age - 161.0;
	//		else {
	//			MessageBox::Show("Invalid gender specified", "Error",
	//				MessageBoxButtons::OK, MessageBoxIcon::Error);
	//			return 0;
	//		}
	//	}

	//	static double GetActivityMultiplier(Client *client) {
	//		String* activity = client.activityLevel->ToLower();

	//		if (activity == "sedentary") return 1.2;
	//		else if (activity == "light") return 1.375;
	//		else if (activity == "moderate") return 1.55;
	//		else if (activity == "active") return 1.725;
	//		else if (activity == "veryactive") return 1.9;
	//		else {
	//			MessageBox::Show("Invalid activity level", "Warning",
	//				MessageBoxButtons::OK, MessageBoxIcon::Warning);
	//			return 1.0;
	//		}
	//	}

	//	static double CalculateTDEE(double bmr, double activityLevel) {
	//		return bmr * activityLevel;
	//	}

	//	static array<double>^ CalculateMacros(double tdee) {
	//		array<double>^ macros = gcnew array<double>(3);
	//		macros[0] = (tdee * 0.3) / 4;   // Protein
	//		macros[1] = (tdee * 0.45) / 4;  // Carbs
	//		macros[2] = (tdee * 0.25) / 9;  // Fats
	//		return macros;
	//	}

	//	static double CalculateBMI(Client^ client) {
	//		int index = client->numMeasurements - 1;
	//		double heightInMeters = client->measurements[index]->height / 100.0;
	//		return client->measurements[index]->weight / (heightInMeters * heightInMeters);
	//	}

	//	static String^ GetBMICategory(double bmi) {
	//		if (bmi < 18.5) return "Underweight";
	//		else if (bmi < 25) return "Normal";
	//		else if (bmi < 30) return "Overweight";
	//		else return "Obese";
	//	}
	//
	////2. دالة عرض الملخص الصحي في الفورم الرئيسي
	//	//cpp
	//	void ShowHealthSummary(Client * client,
	//		Label ^ lbBMI, Label ^ lbStatus,
	//		Label ^ lbBMR, Label ^ lbTDEE,
	//		Label ^ lbProtein, Label ^ lbCarbs, Label ^ lbFats,
	//		GroupBox ^ summaryGroup, PictureBox ^ statusIcon) {
	//	// التحقق من وجود بيانات
	//	if (client->numMeasurements == 0) {
	//		MessageBox::Show("No measurements available to generate health summary.",
	//			"Information",
	//			MessageBoxButtons::OK,
	//			MessageBoxIcon::Information);
	//		summaryGroup->Visible = false;
	//		return;
	//	}

	//	// حساب المؤشرات
	//	double activityMulti = clientmenupage::GetActivityMultiplier(client);
	//	double bmr = clientmenupage::CalculateBMR(client);
	//	double tdee = clientmenupage::CalculateTDEE(bmr, activityMulti);
	//	double bmi = clientmenupage::CalculateBMI(client);
	//	String^ status = clientmenupage::GetBMICategory(bmi);
	//	double macros[3] = clientmenupage::CalculateMacros(tdee);

	//	// عرض النتائج
	//	lbBMI->Text = bmi.ToString("F1");
	//	lbStatus->Text = status;
	//	lbBMR->Text = bmr.ToString("F0") + " kcal/day";
	//	lbTDEE->Text = tdee.ToString("F0") + " kcal/day";
	//	lbProtein->Text = macros[0].ToString("F0") + "g";
	//	lbCarbs->Text = macros[1].ToString("F0") + "g";
	//	lbFats->Text = macros[2].ToString("F0") + "g";

	//	// تنسيق الحالة الصحية
	//	SetHealthStatusStyle(status, lbStatus, statusIcon);
	//	summaryGroup->Visible = true;
	//}

	//// دالة مساعدة لتنسيق الحالة
	//void SetHealthStatusStyle(String^ status, Label^ statusLabel, PictureBox^ icon) {
	//	if (status == "Underweight") {
	//		statusLabel->ForeColor = Color::Blue;
	//		icon->Image = Properties::Resources.UnderweightIcon;
	//	}
	//	else if (status == "Normal") {
	//		statusLabel->ForeColor = Color::Green;
	//		icon->Image = Properties::Resources.NormalIcon;
	//	}
	//	else if (status == "Overweight") {
	//		statusLabel->ForeColor = Color::Orange;
	//		icon->Image = Properties::Resources.OverweightIcon;
	//	}
	//	else {
	//		statusLabel->ForeColor = Color::Red;
	//		icon->Image = Properties::Resources.ObeseIcon;
	//	}

	//	statusLabel->Font = gcnew System::Drawing::Font("Segoe UI", 10, FontStyle::Bold);
	//}
	public:

		// هنا نضع الدالة المعدلة
		void ViewMeasurements(Client * client, DataGridView^ dataGridView) {
			dataGridView->Rows->Clear();

			if (client->numMeasurements == 0) {
				MessageBox::Show("No measurements recorded yet.", "Information",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			// إضافة الأعمدة إذا لم تكن موجودة
			if (dataGridView->Columns->Count == 0) {
				dataGridView->Columns->Add("colNumber", "#");
				dataGridView->Columns->Add("colDate", "Date");
				dataGridView->Columns->Add("colWeight", "Weight (kg)");
				dataGridView->Columns->Add("colHeight", "Height (cm)");
			}

			// تعبئة البيانات
			for (int i = 0; i < client->numMeasurements; i++) {
				String^ dateStr = String::Format("{0}/{1}/{2}",
					client->measurements[i].date.Day,
					client->measurements[i].date.Month,
					client->measurements[i].date.Year);

				dataGridView->Rows->Add(
					(i + 1).ToString(),
					dateStr,
					client->measurements[i].weight.ToString(),
					client->measurements[i].height.ToString()
				);
			}
		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~clientmenupage()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel13;
	private: System::Windows::Forms::Panel^ panel4;





	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Panel^ panel11;
	private: System::Windows::Forms::Panel^ panel12;
	private: System::Windows::Forms::Panel^ mainpage;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label1;
private: System::Windows::Forms::Button^ b_logworkout;
private: System::Windows::Forms::Button^ b_logmeasurment;
private: System::Windows::Forms::Button^ b_healthsummary;
private: System::Windows::Forms::Button^ b_viewmeasurment;




private: System::Windows::Forms::Button^ b_viewworkout;

	private: System::Windows::Forms::Panel^ VIEWmeasurment;
private: System::Windows::Forms::Label^ PAGEtitle_viewM;

	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::Panel^ HEALTHsummary;
private: System::Windows::Forms::Label^ PAGEtitle_Health;

private: System::Windows::Forms::Label^ lblProteinValue;

private: System::Windows::Forms::Label^ lblTDEEValue;
private: System::Windows::Forms::Label^ lblCarbsValue;
private: System::Windows::Forms::Label^ lblFatsValue;




private: System::Windows::Forms::Label^ lblBMRValue;

private: System::Windows::Forms::Label^ lblStatusValue;
private: System::Windows::Forms::Label^ lblBMIValue;
private: System::Windows::Forms::Label^ lbBMIValue;
private: System::Windows::Forms::Label^ lbBMRValue;
private: System::Windows::Forms::Label^ lbFatsValue;

private: System::Windows::Forms::Label^ lbCarbsValue;

private: System::Windows::Forms::Label^ lbProteinValue;
private: System::Windows::Forms::Label^ lbTDEEValue;
private: System::Windows::Forms::Label^ lbStatusValue;
private: System::Windows::Forms::Panel^ LOGmeasurments;
private: System::Windows::Forms::Label^ PAGEtitle_LOGM;




private: System::Windows::Forms::Label^ lb_date;

private: System::Windows::Forms::Label^ lb_height;

private: System::Windows::Forms::Label^ lb_weight;
private: System::Windows::Forms::TextBox^ tB_height;
private: System::Windows::Forms::TextBox^ tB_weight;
private: System::Windows::Forms::DateTimePicker^ DT_date;
private: System::Windows::Forms::Button^ LOG_M;
private: System::Windows::Forms::Panel^ LOGworkout;

private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::TextBox^ txtWorkoutNumber;

private: System::Windows::Forms::ListBox^ lstWorkouts;
private: System::Windows::Forms::Label^ lblStatus;
private: System::Windows::Forms::DataGridView^ dataGridView2dgvProgressLogs;


private: System::Windows::Forms::Button^ btnLogWorkout;
private: System::Windows::Forms::Label^ lblProgressLogs;
private: System::Windows::Forms::Panel^ VIEWworkouts;

private: System::Windows::Forms::Label^ PAGEtitle_viewW;
private: System::Windows::Forms::TreeView^ tvWorkoutDetails;
private: System::Windows::Forms::DataGridView^ dgvWorkouts;
private: System::Windows::Forms::Panel^ LOGO;




























	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(clientmenupage::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->b_logworkout = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->b_logmeasurment = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel12 = (gcnew System::Windows::Forms::Panel());
			this->b_healthsummary = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->panel13 = (gcnew System::Windows::Forms::Panel());
			this->b_viewmeasurment = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->b_viewworkout = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->mainpage = (gcnew System::Windows::Forms::Panel());
			this->LOGworkout = (gcnew System::Windows::Forms::Panel());
			this->lblProgressLogs = (gcnew System::Windows::Forms::Label());
			this->dataGridView2dgvProgressLogs = (gcnew System::Windows::Forms::DataGridView());
			this->btnLogWorkout = (gcnew System::Windows::Forms::Button());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->txtWorkoutNumber = (gcnew System::Windows::Forms::TextBox());
			this->lstWorkouts = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->LOGmeasurments = (gcnew System::Windows::Forms::Panel());
			this->LOG_M = (gcnew System::Windows::Forms::Button());
			this->tB_height = (gcnew System::Windows::Forms::TextBox());
			this->tB_weight = (gcnew System::Windows::Forms::TextBox());
			this->DT_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->lb_date = (gcnew System::Windows::Forms::Label());
			this->lb_height = (gcnew System::Windows::Forms::Label());
			this->lb_weight = (gcnew System::Windows::Forms::Label());
			this->PAGEtitle_LOGM = (gcnew System::Windows::Forms::Label());
			this->HEALTHsummary = (gcnew System::Windows::Forms::Panel());
			this->lbBMRValue = (gcnew System::Windows::Forms::Label());
			this->lbFatsValue = (gcnew System::Windows::Forms::Label());
			this->lbCarbsValue = (gcnew System::Windows::Forms::Label());
			this->lbProteinValue = (gcnew System::Windows::Forms::Label());
			this->lbTDEEValue = (gcnew System::Windows::Forms::Label());
			this->lbStatusValue = (gcnew System::Windows::Forms::Label());
			this->lbBMIValue = (gcnew System::Windows::Forms::Label());
			this->lblProteinValue = (gcnew System::Windows::Forms::Label());
			this->lblTDEEValue = (gcnew System::Windows::Forms::Label());
			this->lblCarbsValue = (gcnew System::Windows::Forms::Label());
			this->lblFatsValue = (gcnew System::Windows::Forms::Label());
			this->lblBMRValue = (gcnew System::Windows::Forms::Label());
			this->lblStatusValue = (gcnew System::Windows::Forms::Label());
			this->lblBMIValue = (gcnew System::Windows::Forms::Label());
			this->PAGEtitle_Health = (gcnew System::Windows::Forms::Label());
			this->VIEWmeasurment = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->PAGEtitle_viewM = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->VIEWworkouts = (gcnew System::Windows::Forms::Panel());
			this->PAGEtitle_viewW = (gcnew System::Windows::Forms::Label());
			this->dgvWorkouts = (gcnew System::Windows::Forms::DataGridView());
			this->tvWorkoutDetails = (gcnew System::Windows::Forms::TreeView());
			this->LOGO = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel10->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel12->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->panel13->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->mainpage->SuspendLayout();
			this->LOGworkout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2dgvProgressLogs))->BeginInit();
			this->LOGmeasurments->SuspendLayout();
			this->HEALTHsummary->SuspendLayout();
			this->VIEWmeasurment->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel3->SuspendLayout();
			this->VIEWworkouts->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvWorkouts))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1179, 100);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(305, 23);
			this->label1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(269, 54);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Client Menu";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->panel2->Controls->Add(this->panel10);
			this->panel2->Controls->Add(this->panel11);
			this->panel2->Controls->Add(this->panel12);
			this->panel2->Controls->Add(this->panel13);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 100);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(336, 714);
			this->panel2->TabIndex = 1;
			// 
			// panel10
			// 
			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel10->Controls->Add(this->b_logworkout);
			this->panel10->Controls->Add(this->pictureBox3);
			this->panel10->Location = System::Drawing::Point(3, 149);
			this->panel10->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(327, 137);
			this->panel10->TabIndex = 1;
			// 
			// b_logworkout
			// 
			this->b_logworkout->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b_logworkout->Location = System::Drawing::Point(125, 12);
			this->b_logworkout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->b_logworkout->Name = L"b_logworkout";
			this->b_logworkout->Size = System::Drawing::Size(187, 94);
			this->b_logworkout->TabIndex = 2;
			this->b_logworkout->Text = L"Log Completed Workout";
			this->b_logworkout->UseVisualStyleBackColor = true;
			this->b_logworkout->Click += gcnew System::EventHandler(this, &clientmenupage::b_logworkout_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(7, 12);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(100, 98);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// panel11
			// 
			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel11->Controls->Add(this->b_logmeasurment);
			this->panel11->Controls->Add(this->pictureBox2);
			this->panel11->Location = System::Drawing::Point(3, 290);
			this->panel11->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(327, 136);
			this->panel11->TabIndex = 1;
			this->panel11->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &clientmenupage::panel11_Paint);
			// 
			// b_logmeasurment
			// 
			this->b_logmeasurment->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b_logmeasurment->Location = System::Drawing::Point(125, 14);
			this->b_logmeasurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->b_logmeasurment->Name = L"b_logmeasurment";
			this->b_logmeasurment->Size = System::Drawing::Size(187, 95);
			this->b_logmeasurment->TabIndex = 3;
			this->b_logmeasurment->Text = L"Log Measurments";
			this->b_logmeasurment->UseVisualStyleBackColor = true;
			this->b_logmeasurment->Click += gcnew System::EventHandler(this, &clientmenupage::b_logmeasurment_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(7, 14);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 98);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// panel12
			// 
			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel12->Controls->Add(this->b_healthsummary);
			this->panel12->Controls->Add(this->pictureBox4);
			this->panel12->Location = System::Drawing::Point(3, 430);
			this->panel12->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel12->Name = L"panel12";
			this->panel12->Size = System::Drawing::Size(327, 134);
			this->panel12->TabIndex = 1;
			// 
			// b_healthsummary
			// 
			this->b_healthsummary->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b_healthsummary->Location = System::Drawing::Point(122, 14);
			this->b_healthsummary->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->b_healthsummary->Name = L"b_healthsummary";
			this->b_healthsummary->Size = System::Drawing::Size(187, 103);
			this->b_healthsummary->TabIndex = 4;
			this->b_healthsummary->Text = L"Health Summary";
			this->b_healthsummary->UseVisualStyleBackColor = true;
			this->b_healthsummary->Click += gcnew System::EventHandler(this, &clientmenupage::b_healthsummary_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(4, 14);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 103);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 2;
			this->pictureBox4->TabStop = false;
			// 
			// panel13
			// 
			this->panel13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel13->Controls->Add(this->b_viewmeasurment);
			this->panel13->Controls->Add(this->pictureBox5);
			this->panel13->Location = System::Drawing::Point(3, 566);
			this->panel13->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel13->Name = L"panel13";
			this->panel13->Size = System::Drawing::Size(327, 137);
			this->panel13->TabIndex = 1;
			// 
			// b_viewmeasurment
			// 
			this->b_viewmeasurment->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b_viewmeasurment->Location = System::Drawing::Point(125, 15);
			this->b_viewmeasurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->b_viewmeasurment->Name = L"b_viewmeasurment";
			this->b_viewmeasurment->Size = System::Drawing::Size(187, 92);
			this->b_viewmeasurment->TabIndex = 5;
			this->b_viewmeasurment->Text = L"View Measurments";
			this->b_viewmeasurment->UseVisualStyleBackColor = true;
			this->b_viewmeasurment->Click += gcnew System::EventHandler(this, &clientmenupage::button6_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(7, 15);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(100, 98);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 2;
			this->pictureBox5->TabStop = false;
			// 
			// panel4
			// 
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panel4->Controls->Add(this->b_viewworkout);
			this->panel4->Controls->Add(this->pictureBox1);
			this->panel4->Location = System::Drawing::Point(3, 4);
			this->panel4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(327, 141);
			this->panel4->TabIndex = 0;
			// 
			// b_viewworkout
			// 
			this->b_viewworkout->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->b_viewworkout->Location = System::Drawing::Point(125, 18);
			this->b_viewworkout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->b_viewworkout->Name = L"b_viewworkout";
			this->b_viewworkout->Size = System::Drawing::Size(187, 103);
			this->b_viewworkout->TabIndex = 1;
			this->b_viewworkout->Text = L"View Workouts";
			this->b_viewworkout->UseVisualStyleBackColor = true;
			this->b_viewworkout->Click += gcnew System::EventHandler(this, &clientmenupage::b_viewworkout_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(7, 18);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 103);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// mainpage
			// 
			this->mainpage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->mainpage->Controls->Add(this->LOGO);
			this->mainpage->Controls->Add(this->VIEWworkouts);
			this->mainpage->Controls->Add(this->LOGworkout);
			this->mainpage->Controls->Add(this->LOGmeasurments);
			this->mainpage->Controls->Add(this->HEALTHsummary);
			this->mainpage->Controls->Add(this->VIEWmeasurment);
			this->mainpage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainpage->Location = System::Drawing::Point(336, 100);
			this->mainpage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->mainpage->Name = L"mainpage";
			this->mainpage->Size = System::Drawing::Size(843, 714);
			this->mainpage->TabIndex = 2;
			// 
			// LOGworkout
			// 
			this->LOGworkout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->LOGworkout->Controls->Add(this->lblProgressLogs);
			this->LOGworkout->Controls->Add(this->dataGridView2dgvProgressLogs);
			this->LOGworkout->Controls->Add(this->btnLogWorkout);
			this->LOGworkout->Controls->Add(this->lblStatus);
			this->LOGworkout->Controls->Add(this->txtWorkoutNumber);
			this->LOGworkout->Controls->Add(this->lstWorkouts);
			this->LOGworkout->Controls->Add(this->label2);
			this->LOGworkout->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LOGworkout->Location = System::Drawing::Point(0, 0);
			this->LOGworkout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LOGworkout->Name = L"LOGworkout";
			this->LOGworkout->Size = System::Drawing::Size(843, 714);
			this->LOGworkout->TabIndex = 6;
			// 
			// lblProgressLogs
			// 
			this->lblProgressLogs->AutoSize = true;
			this->lblProgressLogs->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->lblProgressLogs->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->lblProgressLogs->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProgressLogs->ForeColor = System::Drawing::Color::White;
			this->lblProgressLogs->Location = System::Drawing::Point(470, 335);
			this->lblProgressLogs->Margin = System::Windows::Forms::Padding(4);
			this->lblProgressLogs->Name = L"lblProgressLogs";
			this->lblProgressLogs->Size = System::Drawing::Size(200, 53);
			this->lblProgressLogs->TabIndex = 7;
			this->lblProgressLogs->Text = L"Progress Logs";
			// 
			// dataGridView2dgvProgressLogs
			// 
			this->dataGridView2dgvProgressLogs->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2dgvProgressLogs->Location = System::Drawing::Point(300, 396);
			this->dataGridView2dgvProgressLogs->Name = L"dataGridView2dgvProgressLogs";
			this->dataGridView2dgvProgressLogs->RowHeadersWidth = 51;
			this->dataGridView2dgvProgressLogs->RowTemplate->Height = 24;
			this->dataGridView2dgvProgressLogs->Size = System::Drawing::Size(515, 191);
			this->dataGridView2dgvProgressLogs->TabIndex = 6;
			// 
			// btnLogWorkout
			// 
			this->btnLogWorkout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->btnLogWorkout->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogWorkout->ForeColor = System::Drawing::Color::White;
			this->btnLogWorkout->Location = System::Drawing::Point(60, 345);
			this->btnLogWorkout->Name = L"btnLogWorkout";
			this->btnLogWorkout->Size = System::Drawing::Size(178, 37);
			this->btnLogWorkout->TabIndex = 5;
			this->btnLogWorkout->Text = L"Log";
			this->btnLogWorkout->UseVisualStyleBackColor = false;
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatus->Location = System::Drawing::Point(7, 296);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(361, 37);
			this->lblStatus->TabIndex = 4;
			this->lblStatus->Text = L"Enter workout number you completed:";
			this->lblStatus->Click += gcnew System::EventHandler(this, &clientmenupage::label3_Click);
			// 
			// txtWorkoutNumber
			// 
			this->txtWorkoutNumber->Location = System::Drawing::Point(374, 304);
			this->txtWorkoutNumber->Name = L"txtWorkoutNumber";
			this->txtWorkoutNumber->Size = System::Drawing::Size(63, 22);
			this->txtWorkoutNumber->TabIndex = 3;
			// 
			// lstWorkouts
			// 
			this->lstWorkouts->FormattingEnabled = true;
			this->lstWorkouts->ItemHeight = 16;
			this->lstWorkouts->Location = System::Drawing::Point(11, 106);
			this->lstWorkouts->Name = L"lstWorkouts";
			this->lstWorkouts->Size = System::Drawing::Size(418, 180);
			this->lstWorkouts->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(238, 24);
			this->label2->Margin = System::Windows::Forms::Padding(4);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(343, 53);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Log Completed Worcout";
			// 
			// LOGmeasurments
			// 
			this->LOGmeasurments->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->LOGmeasurments->Controls->Add(this->LOG_M);
			this->LOGmeasurments->Controls->Add(this->tB_height);
			this->LOGmeasurments->Controls->Add(this->tB_weight);
			this->LOGmeasurments->Controls->Add(this->DT_date);
			this->LOGmeasurments->Controls->Add(this->lb_date);
			this->LOGmeasurments->Controls->Add(this->lb_height);
			this->LOGmeasurments->Controls->Add(this->lb_weight);
			this->LOGmeasurments->Controls->Add(this->PAGEtitle_LOGM);
			this->LOGmeasurments->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LOGmeasurments->Location = System::Drawing::Point(0, 0);
			this->LOGmeasurments->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LOGmeasurments->Name = L"LOGmeasurments";
			this->LOGmeasurments->Size = System::Drawing::Size(843, 714);
			this->LOGmeasurments->TabIndex = 5;
			// 
			// LOG_M
			// 
			this->LOG_M->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->LOG_M->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LOG_M->ForeColor = System::Drawing::Color::White;
			this->LOG_M->Location = System::Drawing::Point(653, 527);
			this->LOG_M->Name = L"LOG_M";
			this->LOG_M->Size = System::Drawing::Size(100, 50);
			this->LOG_M->TabIndex = 8;
			this->LOG_M->Text = L"Log";
			this->LOG_M->UseVisualStyleBackColor = false;
			// 
			// tB_height
			// 
			this->tB_height->Location = System::Drawing::Point(50, 360);
			this->tB_height->Name = L"tB_height";
			this->tB_height->Size = System::Drawing::Size(305, 22);
			this->tB_height->TabIndex = 7;
			// 
			// tB_weight
			// 
			this->tB_weight->Location = System::Drawing::Point(50, 206);
			this->tB_weight->Name = L"tB_weight";
			this->tB_weight->Size = System::Drawing::Size(305, 22);
			this->tB_weight->TabIndex = 6;
			// 
			// DT_date
			// 
			this->DT_date->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->DT_date->Location = System::Drawing::Point(50, 501);
			this->DT_date->Name = L"DT_date";
			this->DT_date->Size = System::Drawing::Size(273, 27);
			this->DT_date->TabIndex = 5;
			// 
			// lb_date
			// 
			this->lb_date->AutoSize = true;
			this->lb_date->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lb_date->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_date->Location = System::Drawing::Point(14, 430);
			this->lb_date->Name = L"lb_date";
			this->lb_date->Size = System::Drawing::Size(123, 39);
			this->lb_date->TabIndex = 4;
			this->lb_date->Text = L"Enter Date: ";
			// 
			// lb_height
			// 
			this->lb_height->AutoSize = true;
			this->lb_height->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lb_height->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_height->Location = System::Drawing::Point(14, 296);
			this->lb_height->Name = L"lb_height";
			this->lb_height->Size = System::Drawing::Size(188, 39);
			this->lb_height->TabIndex = 3;
			this->lb_height->Text = L"Enter Your Height:";
			// 
			// lb_weight
			// 
			this->lb_weight->AutoSize = true;
			this->lb_weight->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lb_weight->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lb_weight->Location = System::Drawing::Point(14, 149);
			this->lb_weight->Name = L"lb_weight";
			this->lb_weight->Size = System::Drawing::Size(192, 39);
			this->lb_weight->TabIndex = 2;
			this->lb_weight->Text = L"Enter Your Weight:";
			// 
			// PAGEtitle_LOGM
			// 
			this->PAGEtitle_LOGM->AutoSize = true;
			this->PAGEtitle_LOGM->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->PAGEtitle_LOGM->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PAGEtitle_LOGM->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PAGEtitle_LOGM->ForeColor = System::Drawing::Color::White;
			this->PAGEtitle_LOGM->Location = System::Drawing::Point(255, 24);
			this->PAGEtitle_LOGM->Margin = System::Windows::Forms::Padding(4);
			this->PAGEtitle_LOGM->Name = L"PAGEtitle_LOGM";
			this->PAGEtitle_LOGM->Size = System::Drawing::Size(255, 53);
			this->PAGEtitle_LOGM->TabIndex = 1;
			this->PAGEtitle_LOGM->Text = L"Log Measurments";
			// 
			// HEALTHsummary
			// 
			this->HEALTHsummary->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->HEALTHsummary->Controls->Add(this->lbBMRValue);
			this->HEALTHsummary->Controls->Add(this->lbFatsValue);
			this->HEALTHsummary->Controls->Add(this->lbCarbsValue);
			this->HEALTHsummary->Controls->Add(this->lbProteinValue);
			this->HEALTHsummary->Controls->Add(this->lbTDEEValue);
			this->HEALTHsummary->Controls->Add(this->lbStatusValue);
			this->HEALTHsummary->Controls->Add(this->lbBMIValue);
			this->HEALTHsummary->Controls->Add(this->lblProteinValue);
			this->HEALTHsummary->Controls->Add(this->lblTDEEValue);
			this->HEALTHsummary->Controls->Add(this->lblCarbsValue);
			this->HEALTHsummary->Controls->Add(this->lblFatsValue);
			this->HEALTHsummary->Controls->Add(this->lblBMRValue);
			this->HEALTHsummary->Controls->Add(this->lblStatusValue);
			this->HEALTHsummary->Controls->Add(this->lblBMIValue);
			this->HEALTHsummary->Controls->Add(this->PAGEtitle_Health);
			this->HEALTHsummary->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HEALTHsummary->Location = System::Drawing::Point(0, 0);
			this->HEALTHsummary->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->HEALTHsummary->Name = L"HEALTHsummary";
			this->HEALTHsummary->Size = System::Drawing::Size(843, 714);
			this->HEALTHsummary->TabIndex = 4;
			// 
			// lbBMRValue
			// 
			this->lbBMRValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbBMRValue->AutoSize = true;
			this->lbBMRValue->Location = System::Drawing::Point(174, 231);
			this->lbBMRValue->Name = L"lbBMRValue";
			this->lbBMRValue->Size = System::Drawing::Size(44, 16);
			this->lbBMRValue->TabIndex = 15;
			this->lbBMRValue->Text = L"label4";
			// 
			// lbFatsValue
			// 
			this->lbFatsValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbFatsValue->AutoSize = true;
			this->lbFatsValue->Location = System::Drawing::Point(363, 472);
			this->lbFatsValue->Name = L"lbFatsValue";
			this->lbFatsValue->Size = System::Drawing::Size(44, 16);
			this->lbFatsValue->TabIndex = 14;
			this->lbFatsValue->Text = L"label4";
			// 
			// lbCarbsValue
			// 
			this->lbCarbsValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbCarbsValue->AutoSize = true;
			this->lbCarbsValue->Location = System::Drawing::Point(373, 396);
			this->lbCarbsValue->Name = L"lbCarbsValue";
			this->lbCarbsValue->Size = System::Drawing::Size(44, 16);
			this->lbCarbsValue->TabIndex = 13;
			this->lbCarbsValue->Text = L"label4";
			// 
			// lbProteinValue
			// 
			this->lbProteinValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbProteinValue->AutoSize = true;
			this->lbProteinValue->Location = System::Drawing::Point(363, 317);
			this->lbProteinValue->Name = L"lbProteinValue";
			this->lbProteinValue->Size = System::Drawing::Size(44, 16);
			this->lbProteinValue->TabIndex = 12;
			this->lbProteinValue->Text = L"label4";
			// 
			// lbTDEEValue
			// 
			this->lbTDEEValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbTDEEValue->AutoSize = true;
			this->lbTDEEValue->Location = System::Drawing::Point(573, 231);
			this->lbTDEEValue->Name = L"lbTDEEValue";
			this->lbTDEEValue->Size = System::Drawing::Size(44, 16);
			this->lbTDEEValue->TabIndex = 11;
			this->lbTDEEValue->Text = L"label4";
			// 
			// lbStatusValue
			// 
			this->lbStatusValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbStatusValue->AutoSize = true;
			this->lbStatusValue->Location = System::Drawing::Point(572, 160);
			this->lbStatusValue->Name = L"lbStatusValue";
			this->lbStatusValue->Size = System::Drawing::Size(44, 16);
			this->lbStatusValue->TabIndex = 10;
			this->lbStatusValue->Text = L"label4";
			// 
			// lbBMIValue
			// 
			this->lbBMIValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbBMIValue->AutoSize = true;
			this->lbBMIValue->Location = System::Drawing::Point(174, 160);
			this->lbBMIValue->Name = L"lbBMIValue";
			this->lbBMIValue->Size = System::Drawing::Size(44, 16);
			this->lbBMIValue->TabIndex = 9;
			this->lbBMIValue->Text = L"label4";
			// 
			// lblProteinValue
			// 
			this->lblProteinValue->AutoSize = true;
			this->lblProteinValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProteinValue->Location = System::Drawing::Point(231, 306);
			this->lblProteinValue->Name = L"lblProteinValue";
			this->lblProteinValue->Size = System::Drawing::Size(92, 37);
			this->lblProteinValue->TabIndex = 8;
			this->lblProteinValue->Text = L"Protein: ";
			this->lblProteinValue->Click += gcnew System::EventHandler(this, &clientmenupage::lblProteinValue_Click);
			// 
			// lblTDEEValue
			// 
			this->lblTDEEValue->AutoSize = true;
			this->lblTDEEValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblTDEEValue->Location = System::Drawing::Point(463, 220);
			this->lblTDEEValue->Name = L"lblTDEEValue";
			this->lblTDEEValue->Size = System::Drawing::Size(78, 37);
			this->lblTDEEValue->TabIndex = 7;
			this->lblTDEEValue->Text = L"TDEE:";
			// 
			// lblCarbsValue
			// 
			this->lblCarbsValue->AutoSize = true;
			this->lblCarbsValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCarbsValue->Location = System::Drawing::Point(235, 385);
			this->lblCarbsValue->Name = L"lblCarbsValue";
			this->lblCarbsValue->Size = System::Drawing::Size(74, 37);
			this->lblCarbsValue->TabIndex = 6;
			this->lblCarbsValue->Text = L"Carbs:";
			// 
			// lblFatsValue
			// 
			this->lblFatsValue->AutoSize = true;
			this->lblFatsValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFatsValue->Location = System::Drawing::Point(235, 461);
			this->lblFatsValue->Name = L"lblFatsValue";
			this->lblFatsValue->Size = System::Drawing::Size(59, 37);
			this->lblFatsValue->TabIndex = 5;
			this->lblFatsValue->Text = L"Fats:";
			// 
			// lblBMRValue
			// 
			this->lblBMRValue->AutoSize = true;
			this->lblBMRValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBMRValue->Location = System::Drawing::Point(64, 220);
			this->lblBMRValue->Name = L"lblBMRValue";
			this->lblBMRValue->Size = System::Drawing::Size(70, 37);
			this->lblBMRValue->TabIndex = 4;
			this->lblBMRValue->Text = L"BMR:";
			this->lblBMRValue->Click += gcnew System::EventHandler(this, &clientmenupage::lblBMRValue_Click);
			// 
			// lblStatusValue
			// 
			this->lblStatusValue->AutoSize = true;
			this->lblStatusValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatusValue->Location = System::Drawing::Point(463, 149);
			this->lblStatusValue->Name = L"lblStatusValue";
			this->lblStatusValue->Size = System::Drawing::Size(81, 37);
			this->lblStatusValue->TabIndex = 3;
			this->lblStatusValue->Text = L"Status: ";
			// 
			// lblBMIValue
			// 
			this->lblBMIValue->AutoSize = true;
			this->lblBMIValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBMIValue->Location = System::Drawing::Point(64, 149);
			this->lblBMIValue->Name = L"lblBMIValue";
			this->lblBMIValue->Size = System::Drawing::Size(67, 37);
			this->lblBMIValue->TabIndex = 2;
			this->lblBMIValue->Text = L"BMI: ";
			// 
			// PAGEtitle_Health
			// 
			this->PAGEtitle_Health->AutoSize = true;
			this->PAGEtitle_Health->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->PAGEtitle_Health->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PAGEtitle_Health->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PAGEtitle_Health->ForeColor = System::Drawing::Color::White;
			this->PAGEtitle_Health->Location = System::Drawing::Point(255, 24);
			this->PAGEtitle_Health->Margin = System::Windows::Forms::Padding(4);
			this->PAGEtitle_Health->Name = L"PAGEtitle_Health";
			this->PAGEtitle_Health->Size = System::Drawing::Size(246, 53);
			this->PAGEtitle_Health->TabIndex = 1;
			this->PAGEtitle_Health->Text = L"Health Summary";
			// 
			// VIEWmeasurment
			// 
			this->VIEWmeasurment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->VIEWmeasurment->Controls->Add(this->dataGridView1);
			this->VIEWmeasurment->Controls->Add(this->PAGEtitle_viewM);
			this->VIEWmeasurment->Dock = System::Windows::Forms::DockStyle::Fill;
			this->VIEWmeasurment->Location = System::Drawing::Point(0, 0);
			this->VIEWmeasurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->VIEWmeasurment->Name = L"VIEWmeasurment";
			this->VIEWmeasurment->Size = System::Drawing::Size(843, 714);
			this->VIEWmeasurment->TabIndex = 3;
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Location = System::Drawing::Point(21, 137);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(784, 450);
			this->dataGridView1->TabIndex = 2;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &clientmenupage::dataGridView1_CellContentClick);
			// 
			// PAGEtitle_viewM
			// 
			this->PAGEtitle_viewM->AutoSize = true;
			this->PAGEtitle_viewM->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->PAGEtitle_viewM->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PAGEtitle_viewM->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PAGEtitle_viewM->ForeColor = System::Drawing::Color::White;
			this->PAGEtitle_viewM->Location = System::Drawing::Point(255, 24);
			this->PAGEtitle_viewM->Margin = System::Windows::Forms::Padding(4);
			this->PAGEtitle_viewM->Name = L"PAGEtitle_viewM";
			this->PAGEtitle_viewM->Size = System::Drawing::Size(274, 53);
			this->PAGEtitle_viewM->TabIndex = 1;
			this->PAGEtitle_viewM->Text = L"View Measurments";
			this->PAGEtitle_viewM->Click += gcnew System::EventHandler(this, &clientmenupage::label2_Click);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->panel3->Controls->Add(this->button1);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(336, 714);
			this->panel3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(843, 100);
			this->panel3->TabIndex = 3;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(695, 25);
			this->button1->Margin = System::Windows::Forms::Padding(0);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Logout";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &clientmenupage::button1_Click);
			// 
			// VIEWworkouts
			// 
			this->VIEWworkouts->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->VIEWworkouts->Controls->Add(this->tvWorkoutDetails);
			this->VIEWworkouts->Controls->Add(this->dgvWorkouts);
			this->VIEWworkouts->Controls->Add(this->PAGEtitle_viewW);
			this->VIEWworkouts->Dock = System::Windows::Forms::DockStyle::Fill;
			this->VIEWworkouts->Location = System::Drawing::Point(0, 0);
			this->VIEWworkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->VIEWworkouts->Name = L"VIEWworkouts";
			this->VIEWworkouts->Size = System::Drawing::Size(843, 714);
			this->VIEWworkouts->TabIndex = 7;
			// 
			// PAGEtitle_viewW
			// 
			this->PAGEtitle_viewW->AutoSize = true;
			this->PAGEtitle_viewW->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->PAGEtitle_viewW->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PAGEtitle_viewW->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PAGEtitle_viewW->ForeColor = System::Drawing::Color::White;
			this->PAGEtitle_viewW->Location = System::Drawing::Point(255, 24);
			this->PAGEtitle_viewW->Margin = System::Windows::Forms::Padding(4);
			this->PAGEtitle_viewW->Name = L"PAGEtitle_viewW";
			this->PAGEtitle_viewW->Size = System::Drawing::Size(225, 53);
			this->PAGEtitle_viewW->TabIndex = 1;
			this->PAGEtitle_viewW->Text = L"Your Workouts";
			// 
			// dgvWorkouts
			// 
			this->dgvWorkouts->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dgvWorkouts->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvWorkouts->Location = System::Drawing::Point(39, 137);
			this->dgvWorkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgvWorkouts->Name = L"dgvWorkouts";
			this->dgvWorkouts->RowHeadersWidth = 51;
			this->dgvWorkouts->RowTemplate->Height = 24;
			this->dgvWorkouts->Size = System::Drawing::Size(347, 276);
			this->dgvWorkouts->TabIndex = 2;
			// 
			// tvWorkoutDetails
			// 
			this->tvWorkoutDetails->Location = System::Drawing::Point(481, 168);
			this->tvWorkoutDetails->Name = L"tvWorkoutDetails";
			this->tvWorkoutDetails->Size = System::Drawing::Size(272, 222);
			this->tvWorkoutDetails->TabIndex = 3;
			this->tvWorkoutDetails->AfterSelect += gcnew System::Windows::Forms::TreeViewEventHandler(this, &clientmenupage::tvWorkoutDetails_AfterSelect);
			// 
			// LOGO
			// 
			this->LOGO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->LOGO->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LOGO.BackgroundImage")));
			this->LOGO->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->LOGO->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LOGO->Location = System::Drawing::Point(0, 0);
			this->LOGO->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LOGO->Name = L"LOGO";
			this->LOGO->Size = System::Drawing::Size(843, 714);
			this->LOGO->TabIndex = 8;
			// 
			// clientmenupage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1179, 814);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->mainpage);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"clientmenupage";
			this->Text = L"clientmenupage";
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel11->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel12->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->panel13->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->mainpage->ResumeLayout(false);
			this->LOGworkout->ResumeLayout(false);
			this->LOGworkout->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2dgvProgressLogs))->EndInit();
			this->LOGmeasurments->ResumeLayout(false);
			this->LOGmeasurments->PerformLayout();
			this->HEALTHsummary->ResumeLayout(false);
			this->HEALTHsummary->PerformLayout();
			this->VIEWmeasurment->ResumeLayout(false);
			this->VIEWmeasurment->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->VIEWworkouts->ResumeLayout(false);
			this->VIEWworkouts->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvWorkouts))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel11_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
//private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
//	VIEWworkout->BringToFront();
//}
//private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
//	LOGworkout->BringToFront();
//}
//private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
//	LOGmeasurment->BringToFront();
//}
//
//private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
//	HEALTHsummry->BringToFront();
//}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	VIEWmeasurment->BringToFront();
	ViewMeasurements(client, dataGridView1);
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::Exit();
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void lblBMRValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblProteinValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void b_healthsummary_Click(System::Object^ sender, System::EventArgs^ e) {
	HEALTHsummary->BringToFront();

}
private: System::Void b_logmeasurment_Click(System::Object^ sender, System::EventArgs^ e) {
	LOGmeasurments->BringToFront();
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void b_logworkout_Click(System::Object^ sender, System::EventArgs^ e) {
	LOGworkout->BringToFront();
}
private: System::Void tvWorkoutDetails_AfterSelect(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e) {
}
private: System::Void b_viewworkout_Click(System::Object^ sender, System::EventArgs^ e) {
	VIEWworkouts->BringToFront();
}
};
}
