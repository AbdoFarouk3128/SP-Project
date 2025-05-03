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
	using namespace msclr::interop;

	/// <summary>
	/// Summary for clientmenupage
	/// </summary>
	public ref class clientmenupage : public System::Windows::Forms::Form
	{

	public:
		Client* client;
	public:
		clientmenupage(Client* c)
		{
			client = c;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

		}


	public:
		// هنا نضع الدالة المعدلة
		void ViewMeasurements(Client* client, DataGridView^ dataGridView) {
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

	private:
		void LogMeasurement() {
			// التحقق من عدم تجاوز الحد الأقصى للقياسات
			if (client->numMeasurements >= MAX_MEASUREMENTS) {
				MessageBox::Show("Measurements limit reached!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// التحقق من صحة الوزن المدخل
			double weight;
			if (!Double::TryParse(tB_weight->Text, weight) || weight <= 0) {
				MessageBox::Show("Please enter a valid weight!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			// التحقق من صحة الطول المدخل (إذا كان أول قياس)
			double height;
			if (client->numMeasurements == 0) {
				if (!Double::TryParse(tB_height->Text, height) || height <= 0) {
					MessageBox::Show("Please enter a valid height!", "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
			}
			else {
				height = client->measurements[client->numMeasurements - 1].height;
			}

			// إنشاء قياس جديد
			Measurement newMeasure;
			newMeasure.weight = weight;
			newMeasure.height = height;
			newMeasure.date.Day = Date->Value.Day;
			newMeasure.date.Month = Date->Value.Month;
			newMeasure.date.Year = Date->Value.Year;

			// إضافة القياس إلى العميل
			client->measurements[client->numMeasurements++] = newMeasure;

			// إدراج القياس في قاعدة البيانات
			insertMeasurement(db, newMeasure, client->clientID);

			// عرض رسالة نجاح
			MessageBox::Show("Measurements added successfully!", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

			// مسح الحقول
			tB_weight->Text = "";
			if (client->numMeasurements == 1) {
				tB_height->Text = "";
			}
		}
	
		// ... باقي الكود ...
	private:
		void ValidateWeightInput(System::Object^ sender, System::EventArgs^ e) {
			double result;
			if (!Double::TryParse(tB_weight->Text, result) || result <= 0) {
				tB_weight->ForeColor = Color::Red;
			}
			else {
				tB_weight->ForeColor = Color::Black;
			}
		}

	private: 
		void ViewWorkouts(Client* client, ListBox^ listBoxWorkouts) {
			listBoxWorkouts->Items->Clear(); // مسح المحتوى القديم

			if (client->numWorkouts == 0) {
				listBoxWorkouts->Items->Add("No workouts assigned yet...");
				return;
			}

			for (int i = 0; i < client->numWorkouts; i++) {
				// تحويل std::string إلى String^ يدوياً
				String^ workoutName = gcnew String(client->workoutPlans[i].workoutName.c_str());
				String^ status = gcnew String(client->workoutPlans[i].istrue.c_str());

				// إضافة اسم التمرين والمدة
				String^ workoutInfo = String::Format("{0}. {1} ({2} min)",
					i + 1,
					workoutName,
					client->workoutPlans[i].duration);

				listBoxWorkouts->Items->Add(workoutInfo);

				// إضافة التمارين الفرعية
				for (int j = 0; j < client->workoutPlans[i].numExercises; j++) {
					String^ exercise = gcnew String(client->workoutPlans[i].exercises[j].c_str());
					listBoxWorkouts->Items->Add("   - " + exercise);
				}

				// إضافة التفاصيل (المجموعات، التكرارات، الحالة)
				String^ details = String::Format("   Sets: {0} | Reps: {1} | Status: {2}",
					client->workoutPlans[i].sets,
					client->workoutPlans[i].reps,
					status);

				listBoxWorkouts->Items->Add(details);
				listBoxWorkouts->Items->Add(""); // سطر فارغ لفصل بين التمارين
			}
		}
	private:
		void LogWorkout(Client* client,
			ListBox^ lstWorkouts,
			Label^ lblStatus,
			TextBox^ txtWorkoutNumber,
			Button^ btnLogWorkout)
		{
			// Clear previous items
			lstWorkouts->Items->Clear();
			txtWorkoutNumber->Text = "";
			lblStatus->Text = "";

			// Check if there are any workouts
			if (client->numWorkouts == 0) {
				lblStatus->Text = "No workouts assigned yet.";
				txtWorkoutNumber->Enabled = false;
				btnLogWorkout->Enabled = false;
				return;
			}

			// Check log limit
			if (client->numLogs >= MAX_LOGS) {
				lblStatus->Text = "Log limit reached!";
				txtWorkoutNumber->Enabled = false;
				btnLogWorkout->Enabled = false;
				return;
			}

			// Populate ListBox with workouts
			ViewWorkouts(client, lstWorkouts);

			// Enable controls
			txtWorkoutNumber->Enabled = true;
			btnLogWorkout->Enabled = true;
			lblStatus->Text = "Enter workout number and click Log";
			//UpdateProgressLogsDisplay(dgvProgressLogs, client);
		}

		private: 
			void ShowHealthSummary(Client* client,
				Label^ lbBMIvalue, Label^ lblStatus,
				Label^ lblBMR, Label^ lblTDEE,
				Label^ lblProtein, Label^ lblCarbs, Label^ lblFats)
			{
				if (client->numMeasurements == 0) {
					MessageBox::Show("No measurements recorded yet.", "Information",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}

				double activityMulti =getActivityMultiplier(*client);
				double bmr = calculateBMR(*client);
				double tdee = calculateTDEE(bmr, activityMulti);
				double bmi = calculateBMI(*client);
				String^ status = marshal_as<String^>(getBMICategory(bmi));
				Measurement::Macros macros = calculateMacros(tdee,*client);

				// عرض النتائج مع استخدام lbBMIvalue بدلاً من lblBMI
				lbBMIvalue->Text = String::Format("{0:F2}", bmi);
				lblStatus->Text = String::Format("{0}", status);
				lblBMR->Text = String::Format("{0:F2} calories", bmr);
				lblTDEE->Text = String::Format("{0:F2} calories", tdee);
				lblProtein->Text = String::Format("{0:F2}g", macros.protein);
				lblCarbs->Text = String::Format("{0:F2}g", macros.carbs);
				lblFats->Text = String::Format("{0:F2}g", macros.fats);
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
private: System::Windows::Forms::Panel^ Title;
protected:


	protected:
	private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Panel^ p_measurment;
private: System::Windows::Forms::Panel^ p_workout;
private: System::Windows::Forms::Panel^ p_logworkouts;



private: System::Windows::Forms::Panel^ p_logmeasurments;

private: System::Windows::Forms::Panel^ p_health;








	private: System::Windows::Forms::Panel^ mainpage;
private: System::Windows::Forms::Panel^ logoutp;

private: System::Windows::Forms::Button^ Logout;

	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::Label^ CLIENTM;

	private: System::Windows::Forms::Button^ bLogCompletedWorkout;

	private: System::Windows::Forms::Button^ bLog_Measurments;

	private: System::Windows::Forms::Button^ bHealth_Summary;

	private: System::Windows::Forms::Button^ bView_Measurments;
	private: System::Windows::Forms::Button^ bViewWorkouts;


	private: System::Windows::Forms::Panel^ VIEWmeasurment;
	private: System::Windows::Forms::Label^ PAGEtitle_viewmeasurment;

	private: System::Windows::Forms::DataGridView^ dgv_ViewMeasurment;
	private: System::Windows::Forms::Panel^ HEALTHsummary;
	private: System::Windows::Forms::Label^ PAGEtitle_health;

	private: System::Windows::Forms::Label^ lblBMRValue;
	private: System::Windows::Forms::Label^ lblBMIValue;





	private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ lblProteinValue;

private: System::Windows::Forms::Label^ lblStatusValue;
private: System::Windows::Forms::Label^ lblFatsValue;

private: System::Windows::Forms::Label^ lblCarbsValue;
private: System::Windows::Forms::Label^ lbFatsValue;

private: System::Windows::Forms::Label^ lbCarbsValue;

private: System::Windows::Forms::Label^ lbProteinValue;

private: System::Windows::Forms::Label^ lbBMRValue;
private: System::Windows::Forms::Label^ lbTDEEValue;

private: System::Windows::Forms::Label^ lbStatusValue;
private: System::Windows::Forms::Label^ lbBMIValue;
private: System::Windows::Forms::Panel^ LOGmeasurment;

private: System::Windows::Forms::Label^ lbl_weight;



private: System::Windows::Forms::Label^ PAGEtitle_logm;
private: System::Windows::Forms::DateTimePicker^ Date;

private: System::Windows::Forms::TextBox^ tB_height;
private: System::Windows::Forms::TextBox^ tB_weight;
private: System::Windows::Forms::Label^ lbl_height;
private: System::Windows::Forms::Label^ lbl_date;
private: System::Windows::Forms::Button^ LOGm;
private: System::Windows::Forms::Panel^ LOGcomworkout;
private: System::Windows::Forms::Label^ lblStatus;
private: System::Windows::Forms::TextBox^ txtWorkoutNumber;


private: System::Windows::Forms::ListBox^ WOKOUTS;
private: System::Windows::Forms::Label^ label2;
private: System::Windows::Forms::Button^ bt_Logw;



private: System::Windows::Forms::Panel^ VIEWworkouts;
private: System::Windows::Forms::ListBox^ listBoxWorkouts;

private: System::Windows::Forms::Label^ PAGEtitle_viewworkouts;
private: System::Windows::Forms::Panel^ LOGO;







	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{   
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(clientmenupage::typeid));
			this->Title = (gcnew System::Windows::Forms::Panel());
			this->CLIENTM = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->p_logworkouts = (gcnew System::Windows::Forms::Panel());
			this->bLogCompletedWorkout = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->p_logmeasurments = (gcnew System::Windows::Forms::Panel());
			this->bLog_Measurments = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->p_health = (gcnew System::Windows::Forms::Panel());
			this->bHealth_Summary = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->p_measurment = (gcnew System::Windows::Forms::Panel());
			this->bView_Measurments = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->p_workout = (gcnew System::Windows::Forms::Panel());
			this->bViewWorkouts = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->mainpage = (gcnew System::Windows::Forms::Panel());
			this->HEALTHsummary = (gcnew System::Windows::Forms::Panel());
			this->lbFatsValue = (gcnew System::Windows::Forms::Label());
			this->lbCarbsValue = (gcnew System::Windows::Forms::Label());
			this->lbProteinValue = (gcnew System::Windows::Forms::Label());
			this->lbBMRValue = (gcnew System::Windows::Forms::Label());
			this->lbTDEEValue = (gcnew System::Windows::Forms::Label());
			this->lbStatusValue = (gcnew System::Windows::Forms::Label());
			this->lbBMIValue = (gcnew System::Windows::Forms::Label());
			this->lblFatsValue = (gcnew System::Windows::Forms::Label());
			this->lblCarbsValue = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->lblProteinValue = (gcnew System::Windows::Forms::Label());
			this->lblStatusValue = (gcnew System::Windows::Forms::Label());
			this->lblBMRValue = (gcnew System::Windows::Forms::Label());
			this->lblBMIValue = (gcnew System::Windows::Forms::Label());
			this->PAGEtitle_health = (gcnew System::Windows::Forms::Label());
			this->VIEWmeasurment = (gcnew System::Windows::Forms::Panel());
			this->dgv_ViewMeasurment = (gcnew System::Windows::Forms::DataGridView());
			this->PAGEtitle_viewmeasurment = (gcnew System::Windows::Forms::Label());
			this->LOGO = (gcnew System::Windows::Forms::Panel());
			this->VIEWworkouts = (gcnew System::Windows::Forms::Panel());
			this->listBoxWorkouts = (gcnew System::Windows::Forms::ListBox());
			this->PAGEtitle_viewworkouts = (gcnew System::Windows::Forms::Label());
			this->LOGcomworkout = (gcnew System::Windows::Forms::Panel());
			this->bt_Logw = (gcnew System::Windows::Forms::Button());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->WOKOUTS = (gcnew System::Windows::Forms::ListBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtWorkoutNumber = (gcnew System::Windows::Forms::TextBox());
			this->LOGmeasurment = (gcnew System::Windows::Forms::Panel());
			this->LOGm = (gcnew System::Windows::Forms::Button());
			this->Date = (gcnew System::Windows::Forms::DateTimePicker());
			this->tB_height = (gcnew System::Windows::Forms::TextBox());
			this->tB_weight = (gcnew System::Windows::Forms::TextBox());
			this->lbl_height = (gcnew System::Windows::Forms::Label());
			this->lbl_date = (gcnew System::Windows::Forms::Label());
			this->lbl_weight = (gcnew System::Windows::Forms::Label());
			this->PAGEtitle_logm = (gcnew System::Windows::Forms::Label());
			this->logoutp = (gcnew System::Windows::Forms::Panel());
			this->Logout = (gcnew System::Windows::Forms::Button());
			this->Title->SuspendLayout();
			this->panel2->SuspendLayout();
			this->p_logworkouts->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->p_logmeasurments->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->p_health->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->p_measurment->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->p_workout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->mainpage->SuspendLayout();
			this->HEALTHsummary->SuspendLayout();
			this->VIEWmeasurment->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_ViewMeasurment))->BeginInit();
			this->VIEWworkouts->SuspendLayout();
			this->LOGcomworkout->SuspendLayout();
			this->LOGmeasurment->SuspendLayout();
			this->logoutp->SuspendLayout();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->Title->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Title->Controls->Add(this->CLIENTM);
			this->Title->Dock = System::Windows::Forms::DockStyle::Top;
			this->Title->Location = System::Drawing::Point(0, 0);
			this->Title->Margin = System::Windows::Forms::Padding(5);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(1179, 100);
			this->Title->TabIndex = 0;
			// 
			// CLIENTM
			// 
			this->CLIENTM->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->CLIENTM->AutoSize = true;
			this->CLIENTM->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->CLIENTM->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CLIENTM->ForeColor = System::Drawing::Color::White;
			this->CLIENTM->Location = System::Drawing::Point(460, 20);
			this->CLIENTM->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->CLIENTM->Name = L"CLIENTM";
			this->CLIENTM->Size = System::Drawing::Size(269, 54);
			this->CLIENTM->TabIndex = 0;
			this->CLIENTM->Text = L"Client Menu";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->panel2->Controls->Add(this->p_logworkouts);
			this->panel2->Controls->Add(this->p_logmeasurments);
			this->panel2->Controls->Add(this->p_health);
			this->panel2->Controls->Add(this->p_measurment);
			this->panel2->Controls->Add(this->p_workout);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 100);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(336, 714);
			this->panel2->TabIndex = 1;
			// 
			// p_logworkouts
			// 
			this->p_logworkouts->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->p_logworkouts->Controls->Add(this->bLogCompletedWorkout);
			this->p_logworkouts->Controls->Add(this->pictureBox3);
			this->p_logworkouts->Location = System::Drawing::Point(3, 148);
			this->p_logworkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->p_logworkouts->Name = L"p_logworkouts";
			this->p_logworkouts->Size = System::Drawing::Size(327, 134);
			this->p_logworkouts->TabIndex = 1;
			// 
			// bLogCompletedWorkout
			// 
			this->bLogCompletedWorkout->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bLogCompletedWorkout->Location = System::Drawing::Point(125, 16);
			this->bLogCompletedWorkout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bLogCompletedWorkout->Name = L"bLogCompletedWorkout";
			this->bLogCompletedWorkout->Size = System::Drawing::Size(187, 94);
			this->bLogCompletedWorkout->TabIndex = 2;
			this->bLogCompletedWorkout->Text = L"Log Completed Workout";
			this->bLogCompletedWorkout->UseVisualStyleBackColor = true;
			this->bLogCompletedWorkout->Click += gcnew System::EventHandler(this, &clientmenupage::bLogCompletedWorkout_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(11, 14);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(100, 98);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// p_logmeasurments
			// 
			this->p_logmeasurments->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->p_logmeasurments->Controls->Add(this->bLog_Measurments);
			this->p_logmeasurments->Controls->Add(this->pictureBox2);
			this->p_logmeasurments->Location = System::Drawing::Point(3, 286);
			this->p_logmeasurments->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->p_logmeasurments->Name = L"p_logmeasurments";
			this->p_logmeasurments->Size = System::Drawing::Size(327, 143);
			this->p_logmeasurments->TabIndex = 1;
			this->p_logmeasurments->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &clientmenupage::panel11_Paint);
			// 
			// bLog_Measurments
			// 
			this->bLog_Measurments->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bLog_Measurments->Location = System::Drawing::Point(125, 21);
			this->bLog_Measurments->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bLog_Measurments->Name = L"bLog_Measurments";
			this->bLog_Measurments->Size = System::Drawing::Size(187, 95);
			this->bLog_Measurments->TabIndex = 3;
			this->bLog_Measurments->Text = L"Log Measurments";
			this->bLog_Measurments->UseVisualStyleBackColor = true;
			this->bLog_Measurments->Click += gcnew System::EventHandler(this, &clientmenupage::bLog_Measurments_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(11, 21);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 98);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// p_health
			// 
			this->p_health->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->p_health->Controls->Add(this->bHealth_Summary);
			this->p_health->Controls->Add(this->pictureBox4);
			this->p_health->Location = System::Drawing::Point(3, 433);
			this->p_health->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->p_health->Name = L"p_health";
			this->p_health->Size = System::Drawing::Size(327, 142);
			this->p_health->TabIndex = 1;
			// 
			// bHealth_Summary
			// 
			this->bHealth_Summary->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bHealth_Summary->Location = System::Drawing::Point(125, 15);
			this->bHealth_Summary->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bHealth_Summary->Name = L"bHealth_Summary";
			this->bHealth_Summary->Size = System::Drawing::Size(187, 103);
			this->bHealth_Summary->TabIndex = 4;
			this->bHealth_Summary->Text = L"Health Summary";
			this->bHealth_Summary->UseVisualStyleBackColor = true;
			this->bHealth_Summary->Click += gcnew System::EventHandler(this, &clientmenupage::bHealth_Summary_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(11, 15);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 103);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 2;
			this->pictureBox4->TabStop = false;
			// 
			// p_measurment
			// 
			this->p_measurment->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->p_measurment->Controls->Add(this->bView_Measurments);
			this->p_measurment->Controls->Add(this->pictureBox5);
			this->p_measurment->Location = System::Drawing::Point(3, 583);
			this->p_measurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->p_measurment->Name = L"p_measurment";
			this->p_measurment->Size = System::Drawing::Size(327, 127);
			this->p_measurment->TabIndex = 1;
			// 
			// bView_Measurments
			// 
			this->bView_Measurments->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bView_Measurments->Location = System::Drawing::Point(125, 20);
			this->bView_Measurments->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bView_Measurments->Name = L"bView_Measurments";
			this->bView_Measurments->Size = System::Drawing::Size(187, 92);
			this->bView_Measurments->TabIndex = 5;
			this->bView_Measurments->Text = L"View Measurments";
			this->bView_Measurments->UseVisualStyleBackColor = true;
			this->bView_Measurments->Click += gcnew System::EventHandler(this, &clientmenupage::button6_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(11, 14);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(100, 98);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 2;
			this->pictureBox5->TabStop = false;
			// 
			// p_workout
			// 
			this->p_workout->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->p_workout->Controls->Add(this->bViewWorkouts);
			this->p_workout->Controls->Add(this->pictureBox1);
			this->p_workout->Location = System::Drawing::Point(3, 4);
			this->p_workout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->p_workout->Name = L"p_workout";
			this->p_workout->Size = System::Drawing::Size(327, 144);
			this->p_workout->TabIndex = 0;
			// 
			// bViewWorkouts
			// 
			this->bViewWorkouts->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bViewWorkouts->Location = System::Drawing::Point(125, 14);
			this->bViewWorkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bViewWorkouts->Name = L"bViewWorkouts";
			this->bViewWorkouts->Size = System::Drawing::Size(187, 103);
			this->bViewWorkouts->TabIndex = 1;
			this->bViewWorkouts->Text = L"View Workouts";
			this->bViewWorkouts->UseVisualStyleBackColor = true;
			this->bViewWorkouts->Click += gcnew System::EventHandler(this, &clientmenupage::bViewWorkouts_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(11, 14);
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
			this->mainpage->Controls->Add(this->HEALTHsummary);
			this->mainpage->Controls->Add(this->VIEWmeasurment);
			this->mainpage->Controls->Add(this->LOGO);
			this->mainpage->Controls->Add(this->VIEWworkouts);
			this->mainpage->Controls->Add(this->LOGcomworkout);
			this->mainpage->Controls->Add(this->LOGmeasurment);
			this->mainpage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainpage->Location = System::Drawing::Point(336, 100);
			this->mainpage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->mainpage->Name = L"mainpage";
			this->mainpage->Size = System::Drawing::Size(843, 714);
			this->mainpage->TabIndex = 2;
			// 
			// HEALTHsummary
			// 
			this->HEALTHsummary->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->HEALTHsummary->Controls->Add(this->lbFatsValue);
			this->HEALTHsummary->Controls->Add(this->lbCarbsValue);
			this->HEALTHsummary->Controls->Add(this->lbProteinValue);
			this->HEALTHsummary->Controls->Add(this->lbBMRValue);
			this->HEALTHsummary->Controls->Add(this->lbTDEEValue);
			this->HEALTHsummary->Controls->Add(this->lbStatusValue);
			this->HEALTHsummary->Controls->Add(this->lbBMIValue);
			this->HEALTHsummary->Controls->Add(this->lblFatsValue);
			this->HEALTHsummary->Controls->Add(this->lblCarbsValue);
			this->HEALTHsummary->Controls->Add(this->label7);
			this->HEALTHsummary->Controls->Add(this->lblProteinValue);
			this->HEALTHsummary->Controls->Add(this->lblStatusValue);
			this->HEALTHsummary->Controls->Add(this->lblBMRValue);
			this->HEALTHsummary->Controls->Add(this->lblBMIValue);
			this->HEALTHsummary->Controls->Add(this->PAGEtitle_health);
			this->HEALTHsummary->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HEALTHsummary->Location = System::Drawing::Point(0, 0);
			this->HEALTHsummary->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->HEALTHsummary->Name = L"HEALTHsummary";
			this->HEALTHsummary->Size = System::Drawing::Size(843, 714);
			this->HEALTHsummary->TabIndex = 4;
			// 
			// lbFatsValue
			// 
			this->lbFatsValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbFatsValue->AutoSize = true;
			this->lbFatsValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbFatsValue->Location = System::Drawing::Point(312, 462);
			this->lbFatsValue->Name = L"lbFatsValue";
			this->lbFatsValue->Size = System::Drawing::Size(58, 16);
			this->lbFatsValue->TabIndex = 17;
			this->lbFatsValue->Text = L"label10";
			this->lbFatsValue->Click += gcnew System::EventHandler(this, &clientmenupage::lbFatsValue_Click);
			// 
			// lbCarbsValue
			// 
			this->lbCarbsValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbCarbsValue->AutoSize = true;
			this->lbCarbsValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCarbsValue->Location = System::Drawing::Point(319, 400);
			this->lbCarbsValue->Name = L"lbCarbsValue";
			this->lbCarbsValue->Size = System::Drawing::Size(50, 16);
			this->lbCarbsValue->TabIndex = 16;
			this->lbCarbsValue->Text = L"label9";
			// 
			// lbProteinValue
			// 
			this->lbProteinValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbProteinValue->AutoSize = true;
			this->lbProteinValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbProteinValue->Location = System::Drawing::Point(319, 348);
			this->lbProteinValue->Name = L"lbProteinValue";
			this->lbProteinValue->Size = System::Drawing::Size(50, 16);
			this->lbProteinValue->TabIndex = 15;
			this->lbProteinValue->Text = L"label8";
			// 
			// lbBMRValue
			// 
			this->lbBMRValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbBMRValue->AutoSize = true;
			this->lbBMRValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBMRValue->Location = System::Drawing::Point(195, 238);
			this->lbBMRValue->Name = L"lbBMRValue";
			this->lbBMRValue->Size = System::Drawing::Size(50, 16);
			this->lbBMRValue->TabIndex = 14;
			this->lbBMRValue->Text = L"label6";
			// 
			// lbTDEEValue
			// 
			this->lbTDEEValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbTDEEValue->AutoSize = true;
			this->lbTDEEValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTDEEValue->Location = System::Drawing::Point(483, 238);
			this->lbTDEEValue->Name = L"lbTDEEValue";
			this->lbTDEEValue->Size = System::Drawing::Size(50, 16);
			this->lbTDEEValue->TabIndex = 13;
			this->lbTDEEValue->Text = L"label5";
			// 
			// lbStatusValue
			// 
			this->lbStatusValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbStatusValue->AutoSize = true;
			this->lbStatusValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbStatusValue->Location = System::Drawing::Point(483, 134);
			this->lbStatusValue->Name = L"lbStatusValue";
			this->lbStatusValue->Size = System::Drawing::Size(50, 16);
			this->lbStatusValue->TabIndex = 12;
			this->lbStatusValue->Text = L"label4";
			// 
			// lbBMIValue
			// 
			this->lbBMIValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbBMIValue->AutoSize = true;
			this->lbBMIValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBMIValue->Location = System::Drawing::Point(193, 134);
			this->lbBMIValue->Name = L"lbBMIValue";
			this->lbBMIValue->Size = System::Drawing::Size(50, 16);
			this->lbBMIValue->TabIndex = 11;
			this->lbBMIValue->Text = L"label3";
			// 
			// lblFatsValue
			// 
			this->lblFatsValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblFatsValue->AutoSize = true;
			this->lblFatsValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFatsValue->Location = System::Drawing::Point(213, 450);
			this->lblFatsValue->Name = L"lblFatsValue";
			this->lblFatsValue->Size = System::Drawing::Size(59, 37);
			this->lblFatsValue->TabIndex = 10;
			this->lblFatsValue->Text = L"Fats:";
			// 
			// lblCarbsValue
			// 
			this->lblCarbsValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblCarbsValue->AutoSize = true;
			this->lblCarbsValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCarbsValue->Location = System::Drawing::Point(213, 389);
			this->lblCarbsValue->Name = L"lblCarbsValue";
			this->lblCarbsValue->Size = System::Drawing::Size(74, 37);
			this->lblCarbsValue->TabIndex = 9;
			this->lblCarbsValue->Text = L"Carbs:";
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(399, 226);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(78, 37);
			this->label7->TabIndex = 8;
			this->label7->Text = L"TDEE:";
			// 
			// lblProteinValue
			// 
			this->lblProteinValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblProteinValue->AutoSize = true;
			this->lblProteinValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProteinValue->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->lblProteinValue->Location = System::Drawing::Point(213, 334);
			this->lblProteinValue->Name = L"lblProteinValue";
			this->lblProteinValue->Size = System::Drawing::Size(88, 37);
			this->lblProteinValue->TabIndex = 7;
			this->lblProteinValue->Text = L"Protein:";
			// 
			// lblStatusValue
			// 
			this->lblStatusValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblStatusValue->AutoSize = true;
			this->lblStatusValue->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblStatusValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatusValue->Location = System::Drawing::Point(399, 123);
			this->lblStatusValue->Name = L"lblStatusValue";
			this->lblStatusValue->Size = System::Drawing::Size(79, 39);
			this->lblStatusValue->TabIndex = 6;
			this->lblStatusValue->Text = L"Status:";
			// 
			// lblBMRValue
			// 
			this->lblBMRValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblBMRValue->AutoSize = true;
			this->lblBMRValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBMRValue->Location = System::Drawing::Point(108, 226);
			this->lblBMRValue->Name = L"lblBMRValue";
			this->lblBMRValue->Size = System::Drawing::Size(70, 37);
			this->lblBMRValue->TabIndex = 5;
			this->lblBMRValue->Text = L"BMR:";
			// 
			// lblBMIValue
			// 
			this->lblBMIValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblBMIValue->AutoSize = true;
			this->lblBMIValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBMIValue->Location = System::Drawing::Point(104, 123);
			this->lblBMIValue->Name = L"lblBMIValue";
			this->lblBMIValue->Size = System::Drawing::Size(63, 37);
			this->lblBMIValue->TabIndex = 4;
			this->lblBMIValue->Text = L"BMI:";
			// 
			// PAGEtitle_health
			// 
			this->PAGEtitle_health->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PAGEtitle_health->AutoSize = true;
			this->PAGEtitle_health->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->PAGEtitle_health->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PAGEtitle_health->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PAGEtitle_health->ForeColor = System::Drawing::Color::White;
			this->PAGEtitle_health->Location = System::Drawing::Point(283, 18);
			this->PAGEtitle_health->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PAGEtitle_health->Name = L"PAGEtitle_health";
			this->PAGEtitle_health->Size = System::Drawing::Size(226, 50);
			this->PAGEtitle_health->TabIndex = 1;
			this->PAGEtitle_health->Text = L"Health Summary";
			// 
			// VIEWmeasurment
			// 
			this->VIEWmeasurment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->VIEWmeasurment->Controls->Add(this->dgv_ViewMeasurment);
			this->VIEWmeasurment->Controls->Add(this->PAGEtitle_viewmeasurment);
			this->VIEWmeasurment->Dock = System::Windows::Forms::DockStyle::Fill;
			this->VIEWmeasurment->Location = System::Drawing::Point(0, 0);
			this->VIEWmeasurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->VIEWmeasurment->Name = L"VIEWmeasurment";
			this->VIEWmeasurment->Size = System::Drawing::Size(843, 714);
			this->VIEWmeasurment->TabIndex = 3;
			this->VIEWmeasurment->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &clientmenupage::VIEWmeasurment_Paint);
			// 
			// dgv_ViewMeasurment
			// 
			this->dgv_ViewMeasurment->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->dgv_ViewMeasurment->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dgv_ViewMeasurment->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgv_ViewMeasurment->Location = System::Drawing::Point(77, 148);
			this->dgv_ViewMeasurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgv_ViewMeasurment->Name = L"dgv_ViewMeasurment";
			this->dgv_ViewMeasurment->RowHeadersWidth = 51;
			this->dgv_ViewMeasurment->RowTemplate->Height = 24;
			this->dgv_ViewMeasurment->Size = System::Drawing::Size(696, 449);
			this->dgv_ViewMeasurment->TabIndex = 2;
			this->dgv_ViewMeasurment->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &clientmenupage::dataGridView1_CellContentClick);
			// 
			// PAGEtitle_viewmeasurment
			// 
			this->PAGEtitle_viewmeasurment->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PAGEtitle_viewmeasurment->AutoSize = true;
			this->PAGEtitle_viewmeasurment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->PAGEtitle_viewmeasurment->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PAGEtitle_viewmeasurment->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PAGEtitle_viewmeasurment->ForeColor = System::Drawing::Color::White;
			this->PAGEtitle_viewmeasurment->Location = System::Drawing::Point(283, 18);
			this->PAGEtitle_viewmeasurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PAGEtitle_viewmeasurment->Name = L"PAGEtitle_viewmeasurment";
			this->PAGEtitle_viewmeasurment->Size = System::Drawing::Size(254, 50);
			this->PAGEtitle_viewmeasurment->TabIndex = 1;
			this->PAGEtitle_viewmeasurment->Text = L"View Measurments";
			this->PAGEtitle_viewmeasurment->Click += gcnew System::EventHandler(this, &clientmenupage::label2_Click);
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
			this->LOGO->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &clientmenupage::LOGO_Paint);
			// 
			// VIEWworkouts
			// 
			this->VIEWworkouts->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->VIEWworkouts->Controls->Add(this->listBoxWorkouts);
			this->VIEWworkouts->Controls->Add(this->PAGEtitle_viewworkouts);
			this->VIEWworkouts->Dock = System::Windows::Forms::DockStyle::Fill;
			this->VIEWworkouts->Location = System::Drawing::Point(0, 0);
			this->VIEWworkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->VIEWworkouts->Name = L"VIEWworkouts";
			this->VIEWworkouts->Size = System::Drawing::Size(843, 714);
			this->VIEWworkouts->TabIndex = 7;
			// 
			// listBoxWorkouts
			// 
			this->listBoxWorkouts->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->listBoxWorkouts->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listBoxWorkouts->FormattingEnabled = true;
			this->listBoxWorkouts->ItemHeight = 34;
			this->listBoxWorkouts->Location = System::Drawing::Point(77, 134);
			this->listBoxWorkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listBoxWorkouts->Name = L"listBoxWorkouts";
			this->listBoxWorkouts->Size = System::Drawing::Size(700, 378);
			this->listBoxWorkouts->TabIndex = 2;
			// 
			// PAGEtitle_viewworkouts
			// 
			this->PAGEtitle_viewworkouts->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PAGEtitle_viewworkouts->AutoSize = true;
			this->PAGEtitle_viewworkouts->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->PAGEtitle_viewworkouts->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PAGEtitle_viewworkouts->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PAGEtitle_viewworkouts->ForeColor = System::Drawing::Color::White;
			this->PAGEtitle_viewworkouts->Location = System::Drawing::Point(315, 18);
			this->PAGEtitle_viewworkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PAGEtitle_viewworkouts->Name = L"PAGEtitle_viewworkouts";
			this->PAGEtitle_viewworkouts->Size = System::Drawing::Size(210, 50);
			this->PAGEtitle_viewworkouts->TabIndex = 1;
			this->PAGEtitle_viewworkouts->Text = L"Your Workouts";
			// 
			// LOGcomworkout
			// 
			this->LOGcomworkout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->LOGcomworkout->Controls->Add(this->bt_Logw);
			this->LOGcomworkout->Controls->Add(this->lblStatus);
			this->LOGcomworkout->Controls->Add(this->WOKOUTS);
			this->LOGcomworkout->Controls->Add(this->label2);
			this->LOGcomworkout->Controls->Add(this->txtWorkoutNumber);
			this->LOGcomworkout->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LOGcomworkout->Location = System::Drawing::Point(0, 0);
			this->LOGcomworkout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LOGcomworkout->Name = L"LOGcomworkout";
			this->LOGcomworkout->Size = System::Drawing::Size(843, 714);
			this->LOGcomworkout->TabIndex = 6;
			// 
			// bt_Logw
			// 
			this->bt_Logw->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->bt_Logw->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_Logw->ForeColor = System::Drawing::Color::White;
			this->bt_Logw->Location = System::Drawing::Point(295, 494);
			this->bt_Logw->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_Logw->Name = L"bt_Logw";
			this->bt_Logw->Size = System::Drawing::Size(171, 33);
			this->bt_Logw->TabIndex = 6;
			this->bt_Logw->Text = L"Log";
			this->bt_Logw->UseVisualStyleBackColor = false;
			this->bt_Logw->Click += gcnew System::EventHandler(this, &clientmenupage::bt_Logw_Click);
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatus->Location = System::Drawing::Point(60, 416);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(387, 37);
			this->lblStatus->TabIndex = 4;
			this->lblStatus->Text = L"Enter number of workout you completed :";
			// 
			// WOKOUTS
			// 
			this->WOKOUTS->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->WOKOUTS->FormattingEnabled = true;
			this->WOKOUTS->ItemHeight = 34;
			this->WOKOUTS->Location = System::Drawing::Point(99, 162);
			this->WOKOUTS->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->WOKOUTS->Name = L"WOKOUTS";
			this->WOKOUTS->Size = System::Drawing::Size(562, 208);
			this->WOKOUTS->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(239, 18);
			this->label2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(334, 50);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Log Completed Workouts";
			// 
			// txtWorkoutNumber
			// 
			this->txtWorkoutNumber->Location = System::Drawing::Point(453, 424);
			this->txtWorkoutNumber->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtWorkoutNumber->Name = L"txtWorkoutNumber";
			this->txtWorkoutNumber->Size = System::Drawing::Size(87, 22);
			this->txtWorkoutNumber->TabIndex = 3;
			this->txtWorkoutNumber->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// LOGmeasurment
			// 
			this->LOGmeasurment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->LOGmeasurment->Controls->Add(this->LOGm);
			this->LOGmeasurment->Controls->Add(this->Date);
			this->LOGmeasurment->Controls->Add(this->tB_height);
			this->LOGmeasurment->Controls->Add(this->tB_weight);
			this->LOGmeasurment->Controls->Add(this->lbl_height);
			this->LOGmeasurment->Controls->Add(this->lbl_date);
			this->LOGmeasurment->Controls->Add(this->lbl_weight);
			this->LOGmeasurment->Controls->Add(this->PAGEtitle_logm);
			this->LOGmeasurment->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LOGmeasurment->Location = System::Drawing::Point(0, 0);
			this->LOGmeasurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LOGmeasurment->Name = L"LOGmeasurment";
			this->LOGmeasurment->Size = System::Drawing::Size(843, 714);
			this->LOGmeasurment->TabIndex = 5;
			// 
			// LOGm
			// 
			this->LOGm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->LOGm->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LOGm->ForeColor = System::Drawing::Color::White;
			this->LOGm->Location = System::Drawing::Point(652, 441);
			this->LOGm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LOGm->Name = L"LOGm";
			this->LOGm->Size = System::Drawing::Size(100, 50);
			this->LOGm->TabIndex = 8;
			this->LOGm->Text = L"Log";
			this->LOGm->UseVisualStyleBackColor = false;
			this->LOGm->Click += gcnew System::EventHandler(this, &clientmenupage::button2_Click);
			// 
			// Date
			// 
			this->Date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Date->Location = System::Drawing::Point(28, 389);
			this->Date->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Date->Name = L"Date";
			this->Date->Size = System::Drawing::Size(305, 24);
			this->Date->TabIndex = 7;
			// 
			// tB_height
			// 
			this->tB_height->Location = System::Drawing::Point(28, 286);
			this->tB_height->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tB_height->Name = L"tB_height";
			this->tB_height->Size = System::Drawing::Size(341, 22);
			this->tB_height->TabIndex = 6;
			// 
			// tB_weight
			// 
			this->tB_weight->Location = System::Drawing::Point(28, 174);
			this->tB_weight->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tB_weight->Name = L"tB_weight";
			this->tB_weight->Size = System::Drawing::Size(341, 22);
			this->tB_weight->TabIndex = 5;
			// 
			// lbl_height
			// 
			this->lbl_height->AutoSize = true;
			this->lbl_height->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_height->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_height->Location = System::Drawing::Point(7, 224);
			this->lbl_height->Name = L"lbl_height";
			this->lbl_height->Size = System::Drawing::Size(192, 39);
			this->lbl_height->TabIndex = 4;
			this->lbl_height->Text = L"Enter Your Height :";
			// 
			// lbl_date
			// 
			this->lbl_date->AutoSize = true;
			this->lbl_date->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_date->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_date->Location = System::Drawing::Point(5, 332);
			this->lbl_date->Name = L"lbl_date";
			this->lbl_date->Size = System::Drawing::Size(123, 39);
			this->lbl_date->TabIndex = 3;
			this->lbl_date->Text = L"Enter Date :";
			// 
			// lbl_weight
			// 
			this->lbl_weight->AutoSize = true;
			this->lbl_weight->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_weight->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_weight->Location = System::Drawing::Point(5, 110);
			this->lbl_weight->Name = L"lbl_weight";
			this->lbl_weight->Size = System::Drawing::Size(196, 39);
			this->lbl_weight->TabIndex = 2;
			this->lbl_weight->Text = L"Enter Your Weight :";
			// 
			// PAGEtitle_logm
			// 
			this->PAGEtitle_logm->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Right));
			this->PAGEtitle_logm->AutoSize = true;
			this->PAGEtitle_logm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->PAGEtitle_logm->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->PAGEtitle_logm->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PAGEtitle_logm->ForeColor = System::Drawing::Color::White;
			this->PAGEtitle_logm->Location = System::Drawing::Point(283, 18);
			this->PAGEtitle_logm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->PAGEtitle_logm->Name = L"PAGEtitle_logm";
			this->PAGEtitle_logm->Size = System::Drawing::Size(244, 50);
			this->PAGEtitle_logm->TabIndex = 1;
			this->PAGEtitle_logm->Text = L"Log  Measurments";
			// 
			// logoutp
			// 
			this->logoutp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->logoutp->Controls->Add(this->Logout);
			this->logoutp->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->logoutp->Location = System::Drawing::Point(336, 714);
			this->logoutp->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->logoutp->Name = L"logoutp";
			this->logoutp->Size = System::Drawing::Size(843, 100);
			this->logoutp->TabIndex = 3;
			// 
			// Logout
			// 
			this->Logout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Logout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->Logout->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logout->ForeColor = System::Drawing::Color::White;
			this->Logout->Location = System::Drawing::Point(695, 25);
			this->Logout->Margin = System::Windows::Forms::Padding(0);
			this->Logout->Name = L"Logout";
			this->Logout->Size = System::Drawing::Size(120, 60);
			this->Logout->TabIndex = 0;
			this->Logout->Text = L"Logout";
			this->Logout->UseVisualStyleBackColor = false;
			this->Logout->Click += gcnew System::EventHandler(this, &clientmenupage::Logout_Click);
			// 
			// clientmenupage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1179, 814);
			this->Controls->Add(this->logoutp);
			this->Controls->Add(this->mainpage);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->Title);
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"clientmenupage";
			this->Text = L"clientmenupage";
			this->Title->ResumeLayout(false);
			this->Title->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->p_logworkouts->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->p_logmeasurments->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->p_health->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->p_measurment->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->p_workout->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->mainpage->ResumeLayout(false);
			this->HEALTHsummary->ResumeLayout(false);
			this->HEALTHsummary->PerformLayout();
			this->VIEWmeasurment->ResumeLayout(false);
			this->VIEWmeasurment->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_ViewMeasurment))->EndInit();
			this->VIEWworkouts->ResumeLayout(false);
			this->VIEWworkouts->PerformLayout();
			this->LOGcomworkout->ResumeLayout(false);
			this->LOGcomworkout->PerformLayout();
			this->LOGmeasurment->ResumeLayout(false);
			this->LOGmeasurment->PerformLayout();
			this->logoutp->ResumeLayout(false);
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
		ViewMeasurements(client, dgv_ViewMeasurment);
	}
	private: System::Void Logout_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::ExitThread();
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void VIEWmeasurment_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void bHealth_Summary_Click(System::Object^ sender, System::EventArgs^ e) {
		HEALTHsummary->BringToFront();
		ShowHealthSummary(client,
			lbBMIValue,
			lbStatusValue,
			lbBMRValue,
			lbTDEEValue,
			lbProteinValue,
			lbCarbsValue,
			lbFatsValue);
	
	}
private: System::Void bLog_Measurments_Click(System::Object^ sender, System::EventArgs^ e) {
	LOGmeasurment->BringToFront();
	if (client->numMeasurements > 0) {
		tB_height->Visible = false;
		lbl_height->Visible = false;
	}
	else {
		tB_height->Visible = true;
		lbl_height->Visible = true;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	LogMeasurement(); 

}
private: System::Void bLogCompletedWorkout_Click(System::Object^ sender, System::EventArgs^ e) {
	LOGcomworkout->BringToFront();
	ViewWorkouts(client, WOKOUTS);

}
	// تسجيل ا
private: System::Void bViewWorkouts_Click(System::Object^ sender, System::EventArgs^ e) {
	VIEWworkouts->BringToFront();
	
	ViewWorkouts(client, listBoxWorkouts);
}
private: System::Void LOGO_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void bt_Logw_Click(System::Object^ sender, System::EventArgs^ e) {
	if (client == nullptr) {
		MessageBox::Show("Client data not loaded.", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (String::IsNullOrWhiteSpace(txtWorkoutNumber->Text)) {
		MessageBox::Show("Please enter a workout number.", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int log;
	if (!Int32::TryParse(txtWorkoutNumber->Text, log)) {
		MessageBox::Show("Please enter a valid number.", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (log < 1 || log > client->numWorkouts) {
		MessageBox::Show(String::Format("Invalid workout number. Please enter between 1 and {0}.", client->numWorkouts),
			"Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (client->workoutPlans[log - 1].istrue == "Done") {
		MessageBox::Show("This workout has been done before. Choose another one.",
			"Information",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}

	try {
		// Update client data
		client->progressLogs[client->numLogs++] = client->workoutPlans[log - 1].workoutName;
		client->workoutPlans[log - 1].istrue = "Done";

		// Update database
		updateClientProgressLogs(db, client->clientID, joinLogs(client->progressLogs, client->numLogs));
		updatetheworkoutstatus(db, client->workoutPlans[log - 1].workoutID);

		// Refresh UI
		LogWorkout(client, WOKOUTS, lblStatus, txtWorkoutNumber, bt_Logw);
		MessageBox::Show("Workout logged successfully!", "Success",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show("An error occurred: " + ex->Message, "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}

private: System::Void lbFatsValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
