#pragma once
#include "core.h"
#include <msclr/marshal_cppstd.h>
#include "LoginForm.h"

namespace SPProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for traiermenu
	/// </summary>
	public ref class traiermenu : public System::Windows::Forms::Form
	{
	public:
		Trainer* trainer;
	
	public:
		traiermenu(Trainer* t)
		{
			trainer = t;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->button1->Click += gcnew System::EventHandler(this, &traiermenu::OnButtonClick);
			this->button2->Click += gcnew System::EventHandler(this, &traiermenu::OnButtonClick);
			this->button3->Click += gcnew System::EventHandler(this, &traiermenu::OnButtonClick);

		}
	private: System::Windows::Forms::Panel^ LOGO;
	public:

	private:
		Button^ lastClickedButton = nullptr;

		void OnButtonClick(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);

			if (clickedButton == nullptr)
				return;

			// ???? ???? ?????? ????? ??????
			if (lastClickedButton != nullptr && lastClickedButton != clickedButton) {
				lastClickedButton->ForeColor = System::Drawing::Color::Black;
				lastClickedButton->BackColor = normalColor;
			}

			// ???? ???? ??????
			clickedButton->ForeColor = System::Drawing::Color::White;
			clickedButton->BackColor = hoverColor;

			// ????? ???? ??
			lastClickedButton = clickedButton;
		}
		private:
			System::Drawing::Color normalColor = System::Drawing::Color::FromArgb(236, 241, 240);
	private: System::Windows::Forms::Timer^ hoverTimer;

		   System::Drawing::Color hoverColor = System::Drawing::Color::LightSkyBlue;

		void OnButtonHover(System::Object^ sender, System::EventArgs^ e) {
			Button^ btn = dynamic_cast<Button^>(sender);
			if (btn != nullptr) {
				btn->BackColor = hoverColor;
			}
		}

		void OnButtonLeave(System::Object^ sender, System::EventArgs^ e) {
			Button^ btn = dynamic_cast<Button^>(sender);
			if (btn != nullptr) {
				btn->BackColor = normalColor;
			}
		}
	

	public:
		void DisplayClients(Trainer* trainer, DataGridView^ dgvClients) {
			dgvClients->Rows->Clear();
			dgvClients->Columns->Clear();

			// Define columns (once)
			dgvClients->Columns->Add("ID", "Client ID");
			dgvClients->Columns->Add("Name", "Name");
			dgvClients->Columns->Add("Age", "Age");
			dgvClients->Columns->Add("Gender", "Gender");
			dgvClients->Columns->Add("ActivityLevel", "Activity Level");
			dgvClients->Columns->Add("NumWorkouts", "Number of Workouts");


			for (int i = 0; i < trainer->numClients; i++) {
				//if (trainer->clients[i] == nullptr) continue;

				Client c = trainer->clients[i];

				dgvClients->Rows->Add(
					c.clientID.ToString(),                                 // Assuming clientID is int or has .ToString()
					marshal_as<System::String^>(c.name),                   // std::string to System::String^
					c.age.ToString(),                                      // Assuming age is int
					marshal_as<System::String^>(c.gender),                 // std::string to System::String^
					marshal_as<System::String^>(c.activityLevel),          // std::string to System::String^
					c.numWorkouts.ToString()                               // Assuming int
				);
			}
		}
		void FillClientsDataGrid(Trainer* trainer, DataGridView^ data) {
			data->Rows->Clear();
			if (data->Columns->Count == 0) {
				data->Columns->Add("ID", "Client ID");
				data->Columns->Add("Name", "Name");
				data->Columns->Add("Workouts", "Number of Workouts");
			}
			for (int i = 0; i < trainer->numClients; i++) {
				String^ clientID = trainer->clients[i].clientID.ToString();
				String^ name = gcnew String(trainer->clients[i].name.c_str());
				String^ workouts = trainer->clients[i].numWorkouts.ToString();

				// إضافة صف جديد في DataGrid
				data->Rows->Add(clientID, name, workouts);
			}
		}
		void LoadWorkoutsToCheckedListBox() {
			checkedListBox1->Items->Clear();

			for (int i = 0; i < numPredefinedWorkouts; i++) {

				std::string nativeItem = predefineWorkout[i].workoutName;
				String^ item = gcnew String(nativeItem.c_str());
				checkedListBox1->Items->Add(item);
			}
			checkedListBox1->CheckOnClick = true;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~traiermenu()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Panel^ clientinfo;
	private: System::Windows::Forms::DataGridView^ dataGridView1;

	private: System::Windows::Forms::Panel^ progress;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;

















	private: System::Windows::Forms::Button^ button7;





























private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
private: System::Windows::Forms::Panel^ panel10;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Panel^ pnlcompletedworkout;
private: System::Windows::Forms::Button^ viewcompletedworkout;
private: System::Windows::Forms::Label^ label6;


































private: System::Windows::Forms::DataGridViewTextBoxColumn^ NAME;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Age;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ gender;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ activitylevel;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ workouts;

private: System::Windows::Forms::Panel^ manage;
private: System::Windows::Forms::Panel^ btn;
private: System::Windows::Forms::Button^ button6;
private: System::Windows::Forms::Button^ button5;
private: System::Windows::Forms::Button^ button4;

private: System::Windows::Forms::Panel^ manpanel;
private: System::Windows::Forms::Panel^ customwork;
private: System::Windows::Forms::TextBox^ textBox3;
private: System::Windows::Forms::Label^ label5;
private: System::Windows::Forms::SplitContainer^ splitContainer2;
private: System::Windows::Forms::NumericUpDown^ numExercises1;
private: System::Windows::Forms::NumericUpDown^ numSets1;
private: System::Windows::Forms::NumericUpDown^ numDuration1;
private: System::Windows::Forms::TextBox^ txtWorkoutName1;
private: System::Windows::Forms::Button^ btnSaveWorkout1;
private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::NumericUpDown^ numReps1;
private: System::Windows::Forms::FlowLayoutPanel^ panelExercises1;
private: System::Windows::Forms::DataGridView^ dataGridView4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
private: System::Windows::Forms::Panel^ newwork;
private: System::Windows::Forms::SplitContainer^ splitContainer1;
private: System::Windows::Forms::Button^ btnSaveWorkout;
private: System::Windows::Forms::NumericUpDown^ numExercises;
private: System::Windows::Forms::Label^ label11;
private: System::Windows::Forms::NumericUpDown^ numReps;
private: System::Windows::Forms::Label^ label10;
private: System::Windows::Forms::NumericUpDown^ numSets;
private: System::Windows::Forms::Label^ label9;
private: System::Windows::Forms::NumericUpDown^ numDuration;
private: System::Windows::Forms::Label^ label8;
private: System::Windows::Forms::TextBox^ txtWorkoutName;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::FlowLayoutPanel^ panelExercises;
private: System::Windows::Forms::Panel^ assign;
private: System::Windows::Forms::Label^ label4;
private: System::Windows::Forms::TextBox^ textBox2;
private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
private: System::Windows::Forms::Button^ button9;
private: System::Windows::Forms::DataGridView^ dataGridView3;




private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
private: System::Windows::Forms::PictureBox^ pictureBox4;






































































































	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(traiermenu::typeid));
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle6 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle7 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle8 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->manage = (gcnew System::Windows::Forms::Panel());
			this->manpanel = (gcnew System::Windows::Forms::Panel());
			this->newwork = (gcnew System::Windows::Forms::Panel());
			this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			this->btnSaveWorkout = (gcnew System::Windows::Forms::Button());
			this->numExercises = (gcnew System::Windows::Forms::NumericUpDown());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->numReps = (gcnew System::Windows::Forms::NumericUpDown());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->numSets = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->numDuration = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtWorkoutName = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->panelExercises = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->assign = (gcnew System::Windows::Forms::Panel());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->customwork = (gcnew System::Windows::Forms::Panel());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			this->numExercises1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numSets1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numDuration1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->txtWorkoutName1 = (gcnew System::Windows::Forms::TextBox());
			this->btnSaveWorkout1 = (gcnew System::Windows::Forms::Button());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->numReps1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->panelExercises1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btn = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->LOGO = (gcnew System::Windows::Forms::Panel());
			this->progress = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pnlcompletedworkout = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->viewcompletedworkout = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->clientinfo = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->NAME = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Age = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->gender = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->activitylevel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->workouts = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			this->manage->SuspendLayout();
			this->manpanel->SuspendLayout();
			this->newwork->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numExercises))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numReps))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSets))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDuration))->BeginInit();
			this->assign->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->customwork->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			this->splitContainer2->Panel1->SuspendLayout();
			this->splitContainer2->Panel2->SuspendLayout();
			this->splitContainer2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numExercises1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSets1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDuration1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numReps1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->btn->SuspendLayout();
			this->progress->SuspendLayout();
			this->panel9->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->panel10->SuspendLayout();
			this->pnlcompletedworkout->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->clientinfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->panel1->Controls->Add(this->pictureBox4);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(884, 75);
			this->panel1->TabIndex = 0;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(3, 3);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(182, 80);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 2;
			this->pictureBox4->TabStop = false;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(305, 18);
			this->label1->Margin = System::Windows::Forms::Padding(200);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(275, 42);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TRAINER MENU";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 75);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(185, 534);
			this->panel2->TabIndex = 1;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(26, 490);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(146, 41);
			this->button7->TabIndex = 3;
			this->button7->Text = L"LOGOUT";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &traiermenu::button7_Click);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->pictureBox3);
			this->panel6->Controls->Add(this->button3);
			this->panel6->Location = System::Drawing::Point(0, 323);
			this->panel6->Margin = System::Windows::Forms::Padding(10);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(184, 162);
			this->panel6->TabIndex = 2;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(21, 3);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(148, 72);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 1;
			this->pictureBox3->TabStop = false;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(-2, 82);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(187, 53);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Client Progress";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &traiermenu::button3_Click);
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->pictureBox2);
			this->panel5->Controls->Add(this->button2);
			this->panel5->Location = System::Drawing::Point(0, 165);
			this->panel5->Margin = System::Windows::Forms::Padding(10);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(184, 155);
			this->panel5->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(21, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(148, 67);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(-6, 77);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(191, 53);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Manage Workouts";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &traiermenu::button2_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pictureBox1);
			this->panel4->Controls->Add(this->button1);
			this->panel4->Location = System::Drawing::Point(3, 0);
			this->panel4->Margin = System::Windows::Forms::Padding(10);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(181, 162);
			this->panel4->TabIndex = 0;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::panel4_Paint);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(18, 3);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(148, 72);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &traiermenu::pictureBox1_Click_1);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(-7, 81);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(190, 60);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Clients Information";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &traiermenu::button1_Click_1);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->panel3->Controls->Add(this->LOGO);
			this->panel3->Controls->Add(this->manage);
			this->panel3->Controls->Add(this->progress);
			this->panel3->Controls->Add(this->clientinfo);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(185, 75);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(699, 534);
			this->panel3->TabIndex = 2;
			// 
			// manage
			// 
			this->manage->BackColor = System::Drawing::Color::White;
			this->manage->Controls->Add(this->manpanel);
			this->manage->Controls->Add(this->btn);
			this->manage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->manage->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->manage->Location = System::Drawing::Point(0, 0);
			this->manage->Name = L"manage";
			this->manage->Size = System::Drawing::Size(699, 534);
			this->manage->TabIndex = 11;
			// 
			// manpanel
			// 
			this->manpanel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->manpanel->Controls->Add(this->newwork);
			this->manpanel->Controls->Add(this->assign);
			this->manpanel->Controls->Add(this->customwork);
			this->manpanel->Dock = System::Windows::Forms::DockStyle::Fill;
			this->manpanel->Location = System::Drawing::Point(0, 75);
			this->manpanel->Name = L"manpanel";
			this->manpanel->Size = System::Drawing::Size(699, 459);
			this->manpanel->TabIndex = 1;
			// 
			// newwork
			// 
			this->newwork->BackColor = System::Drawing::Color::White;
			this->newwork->Controls->Add(this->splitContainer1);
			this->newwork->Location = System::Drawing::Point(6, 6);
			this->newwork->Name = L"newwork";
			this->newwork->Size = System::Drawing::Size(690, 446);
			this->newwork->TabIndex = 10;
			this->newwork->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::newwork_Paint);
			// 
			// splitContainer1
			// 
			this->splitContainer1->BackColor = System::Drawing::Color::WhiteSmoke;
			this->splitContainer1->Location = System::Drawing::Point(21, 22);
			this->splitContainer1->Name = L"splitContainer1";
			// 
			// splitContainer1.Panel1
			// 
			this->splitContainer1->Panel1->Controls->Add(this->btnSaveWorkout);
			this->splitContainer1->Panel1->Controls->Add(this->numExercises);
			this->splitContainer1->Panel1->Controls->Add(this->label11);
			this->splitContainer1->Panel1->Controls->Add(this->numReps);
			this->splitContainer1->Panel1->Controls->Add(this->label10);
			this->splitContainer1->Panel1->Controls->Add(this->numSets);
			this->splitContainer1->Panel1->Controls->Add(this->label9);
			this->splitContainer1->Panel1->Controls->Add(this->numDuration);
			this->splitContainer1->Panel1->Controls->Add(this->label8);
			this->splitContainer1->Panel1->Controls->Add(this->txtWorkoutName);
			this->splitContainer1->Panel1->Controls->Add(this->label7);
			this->splitContainer1->Panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::splitContainer1_Panel1_Paint);
			// 
			// splitContainer1.Panel2
			// 
			this->splitContainer1->Panel2->Controls->Add(this->panelExercises);
			this->splitContainer1->Size = System::Drawing::Size(646, 368);
			this->splitContainer1->SplitterDistance = 310;
			this->splitContainer1->TabIndex = 1;
			// 
			// btnSaveWorkout
			// 
			this->btnSaveWorkout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->btnSaveWorkout->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSaveWorkout->ForeColor = System::Drawing::SystemColors::Control;
			this->btnSaveWorkout->Location = System::Drawing::Point(85, 279);
			this->btnSaveWorkout->Name = L"btnSaveWorkout";
			this->btnSaveWorkout->Size = System::Drawing::Size(176, 74);
			this->btnSaveWorkout->TabIndex = 10;
			this->btnSaveWorkout->Text = L"Save";
			this->btnSaveWorkout->UseVisualStyleBackColor = false;
			this->btnSaveWorkout->Click += gcnew System::EventHandler(this, &traiermenu::btnSaveWorkout_Click_1);
			// 
			// numExercises
			// 
			this->numExercises->Location = System::Drawing::Point(153, 216);
			this->numExercises->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numExercises->Name = L"numExercises";
			this->numExercises->Size = System::Drawing::Size(135, 23);
			this->numExercises->TabIndex = 9;
			this->numExercises->ValueChanged += gcnew System::EventHandler(this, &traiermenu::numExercises_ValueChanged_1);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(10, 221);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(137, 16);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Number of Exercises";
			// 
			// numReps
			// 
			this->numReps->Location = System::Drawing::Point(153, 177);
			this->numReps->Name = L"numReps";
			this->numReps->Size = System::Drawing::Size(135, 23);
			this->numReps->TabIndex = 7;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(37, 180);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(39, 16);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Reps";
			// 
			// numSets
			// 
			this->numSets->Location = System::Drawing::Point(153, 135);
			this->numSets->Name = L"numSets";
			this->numSets->Size = System::Drawing::Size(135, 23);
			this->numSets->TabIndex = 5;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(37, 142);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(36, 16);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Sets";
			// 
			// numDuration
			// 
			this->numDuration->Location = System::Drawing::Point(153, 98);
			this->numDuration->Name = L"numDuration";
			this->numDuration->Size = System::Drawing::Size(135, 23);
			this->numDuration->TabIndex = 3;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(19, 105);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(101, 16);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Duration (min)";
			// 
			// txtWorkoutName
			// 
			this->txtWorkoutName->Location = System::Drawing::Point(153, 55);
			this->txtWorkoutName->Name = L"txtWorkoutName";
			this->txtWorkoutName->Size = System::Drawing::Size(136, 23);
			this->txtWorkoutName->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(19, 58);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(102, 16);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Workout Name";
			// 
			// panelExercises
			// 
			this->panelExercises->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelExercises->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelExercises->Location = System::Drawing::Point(0, 0);
			this->panelExercises->Name = L"panelExercises";
			this->panelExercises->Size = System::Drawing::Size(332, 368);
			this->panelExercises->TabIndex = 0;
			// 
			// assign
			// 
			this->assign->BackColor = System::Drawing::Color::White;
			this->assign->Controls->Add(this->label4);
			this->assign->Controls->Add(this->textBox2);
			this->assign->Controls->Add(this->checkedListBox1);
			this->assign->Controls->Add(this->button9);
			this->assign->Controls->Add(this->dataGridView3);
			this->assign->Location = System::Drawing::Point(6, 8);
			this->assign->Margin = System::Windows::Forms::Padding(2);
			this->assign->Name = L"assign";
			this->assign->Size = System::Drawing::Size(690, 421);
			this->assign->TabIndex = 0;
			this->assign->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::assign_Paint);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(189, 224);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(144, 19);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Enter Client Id : ";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(364, 221);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(126, 23);
			this->textBox2->TabIndex = 7;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"Full Body Workout", L"Morning Cardio",
					L"Strength Training", L"Strength Training 1"
			});
			this->checkedListBox1->Location = System::Drawing::Point(5, 269);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(640, 76);
			this->checkedListBox1->Sorted = true;
			this->checkedListBox1->TabIndex = 6;
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->button9->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->button9->Location = System::Drawing::Point(559, 351);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(113, 50);
			this->button9->TabIndex = 5;
			this->button9->Text = L"Submit";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &traiermenu::button9_Click_1);
			// 
			// dataGridView3
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::SkyBlue;
			this->dataGridView3->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView3->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView3->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView3->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView3->Location = System::Drawing::Point(148, 3);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->Size = System::Drawing::Size(380, 203);
			this->dataGridView3->TabIndex = 1;
			this->dataGridView3->CellFormatting += gcnew System::Windows::Forms::DataGridViewCellFormattingEventHandler(this, &traiermenu::dataGridView3_CellFormatting);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Id";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			this->Column1->Width = 80;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Name";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			this->Column2->Width = 140;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Workout";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 90;
			// 
			// customwork
			// 
			this->customwork->BackColor = System::Drawing::Color::White;
			this->customwork->Controls->Add(this->textBox3);
			this->customwork->Controls->Add(this->label5);
			this->customwork->Controls->Add(this->splitContainer2);
			this->customwork->Controls->Add(this->dataGridView4);
			this->customwork->Location = System::Drawing::Point(6, 6);
			this->customwork->Name = L"customwork";
			this->customwork->Size = System::Drawing::Size(690, 423);
			this->customwork->TabIndex = 11;
			this->customwork->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::customwork_Paint);
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(482, 98);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(90, 30);
			this->textBox3->TabIndex = 9;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(444, 67);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(171, 25);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Enter Client Id : ";
			// 
			// splitContainer2
			// 
			this->splitContainer2->Location = System::Drawing::Point(0, 207);
			this->splitContainer2->Name = L"splitContainer2";
			// 
			// splitContainer2.Panel1
			// 
			this->splitContainer2->Panel1->Controls->Add(this->numExercises1);
			this->splitContainer2->Panel1->Controls->Add(this->numSets1);
			this->splitContainer2->Panel1->Controls->Add(this->numDuration1);
			this->splitContainer2->Panel1->Controls->Add(this->txtWorkoutName1);
			this->splitContainer2->Panel1->Controls->Add(this->btnSaveWorkout1);
			this->splitContainer2->Panel1->Controls->Add(this->label17);
			this->splitContainer2->Panel1->Controls->Add(this->label16);
			this->splitContainer2->Panel1->Controls->Add(this->label15);
			this->splitContainer2->Panel1->Controls->Add(this->label14);
			this->splitContainer2->Panel1->Controls->Add(this->label13);
			this->splitContainer2->Panel1->Controls->Add(this->numReps1);
			// 
			// splitContainer2.Panel2
			// 
			this->splitContainer2->Panel2->Controls->Add(this->panelExercises1);
			this->splitContainer2->Size = System::Drawing::Size(688, 207);
			this->splitContainer2->SplitterDistance = 334;
			this->splitContainer2->TabIndex = 7;
			// 
			// numExercises1
			// 
			this->numExercises1->Location = System::Drawing::Point(170, 133);
			this->numExercises1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numExercises1->Name = L"numExercises1";
			this->numExercises1->Size = System::Drawing::Size(133, 23);
			this->numExercises1->TabIndex = 21;
			this->numExercises1->ValueChanged += gcnew System::EventHandler(this, &traiermenu::numExercises1_ValueChanged_1);
			// 
			// numSets1
			// 
			this->numSets1->Location = System::Drawing::Point(171, 72);
			this->numSets1->Name = L"numSets1";
			this->numSets1->Size = System::Drawing::Size(133, 23);
			this->numSets1->TabIndex = 20;
			// 
			// numDuration1
			// 
			this->numDuration1->Location = System::Drawing::Point(171, 39);
			this->numDuration1->Name = L"numDuration1";
			this->numDuration1->Size = System::Drawing::Size(133, 23);
			this->numDuration1->TabIndex = 19;
			// 
			// txtWorkoutName1
			// 
			this->txtWorkoutName1->Location = System::Drawing::Point(171, 6);
			this->txtWorkoutName1->Name = L"txtWorkoutName1";
			this->txtWorkoutName1->Size = System::Drawing::Size(133, 23);
			this->txtWorkoutName1->TabIndex = 18;
			// 
			// btnSaveWorkout1
			// 
			this->btnSaveWorkout1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->btnSaveWorkout1->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSaveWorkout1->ForeColor = System::Drawing::SystemColors::Control;
			this->btnSaveWorkout1->Location = System::Drawing::Point(62, 162);
			this->btnSaveWorkout1->Name = L"btnSaveWorkout1";
			this->btnSaveWorkout1->Size = System::Drawing::Size(176, 39);
			this->btnSaveWorkout1->TabIndex = 11;
			this->btnSaveWorkout1->Text = L"Save";
			this->btnSaveWorkout1->UseVisualStyleBackColor = false;
			this->btnSaveWorkout1->Click += gcnew System::EventHandler(this, &traiermenu::btnSaveWorkout1_Click_1);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(59, 103);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(39, 16);
			this->label17->TabIndex = 17;
			this->label17->Text = L"Reps";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(56, 72);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(36, 16);
			this->label16->TabIndex = 16;
			this->label16->Text = L"Sets";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(23, 41);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(101, 16);
			this->label15->TabIndex = 15;
			this->label15->Text = L"Duration (min)";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(22, 10);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(102, 16);
			this->label14->TabIndex = 14;
			this->label14->Text = L"Workout Name";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(13, 135);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(137, 16);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Number of Exercises";
			// 
			// numReps1
			// 
			this->numReps1->Location = System::Drawing::Point(170, 101);
			this->numReps1->Name = L"numReps1";
			this->numReps1->Size = System::Drawing::Size(133, 23);
			this->numReps1->TabIndex = 12;
			// 
			// panelExercises1
			// 
			this->panelExercises1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelExercises1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelExercises1->Location = System::Drawing::Point(0, 0);
			this->panelExercises1->Name = L"panelExercises1";
			this->panelExercises1->Size = System::Drawing::Size(350, 207);
			this->panelExercises1->TabIndex = 0;
			// 
			// dataGridView4
			// 
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::SkyBlue;
			this->dataGridView4->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView4->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView4->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn4,
					this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6
			});
			this->dataGridView4->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView4->Location = System::Drawing::Point(5, 3);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->RowHeadersWidth = 51;
			this->dataGridView4->Size = System::Drawing::Size(363, 189);
			this->dataGridView4->TabIndex = 1;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Id";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 80;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Name";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 130;
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Workout";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			this->dataGridViewTextBoxColumn6->Width = 80;
			// 
			// btn
			// 
			this->btn->Controls->Add(this->button6);
			this->btn->Controls->Add(this->button5);
			this->btn->Controls->Add(this->button4);
			this->btn->Dock = System::Windows::Forms::DockStyle::Top;
			this->btn->Location = System::Drawing::Point(0, 0);
			this->btn->Name = L"btn";
			this->btn->Size = System::Drawing::Size(699, 75);
			this->btn->TabIndex = 0;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(434, 10);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(238, 65);
			this->button6->TabIndex = 2;
			this->button6->Text = L"Create Custom Workout for Client";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &traiermenu::button6_Click);
			this->button6->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::customwork_Paint);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(197, 10);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(231, 65);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Create New Predefined Workout";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &traiermenu::button5_Click);
			this->button5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::newwork_Paint);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(6, 10);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(185, 65);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Assign Predefined Workout";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &traiermenu::button4_Click);
			this->button4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::assign_Paint);
			// 
			// LOGO
			// 
			this->LOGO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->LOGO->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"LOGO.BackgroundImage")));
			this->LOGO->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->LOGO->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LOGO->Location = System::Drawing::Point(0, 0);
			this->LOGO->Margin = System::Windows::Forms::Padding(2);
			this->LOGO->Name = L"LOGO";
			this->LOGO->Size = System::Drawing::Size(699, 534);
			this->LOGO->TabIndex = 19;
			// 
			// progress
			// 
			this->progress->BackColor = System::Drawing::Color::White;
			this->progress->Controls->Add(this->panel9);
			this->progress->Controls->Add(this->viewcompletedworkout);
			this->progress->Controls->Add(this->textBox1);
			this->progress->Controls->Add(this->panel8);
			this->progress->Controls->Add(this->panel7);
			this->progress->Controls->Add(this->label2);
			this->progress->Dock = System::Windows::Forms::DockStyle::Fill;
			this->progress->Location = System::Drawing::Point(0, 0);
			this->progress->Name = L"progress";
			this->progress->Size = System::Drawing::Size(699, 534);
			this->progress->TabIndex = 3;
			// 
			// panel9
			// 
			this->panel9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->panel9->Controls->Add(this->tableLayoutPanel5);
			this->panel9->Location = System::Drawing::Point(3, 347);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(678, 180);
			this->panel9->TabIndex = 4;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->tableLayoutPanel5->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetDouble;
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				43.32344F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				56.67656F)));
			this->tableLayoutPanel5->Controls->Add(this->panel10, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->pnlcompletedworkout, 1, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tableLayoutPanel5->Location = System::Drawing::Point(0, 3);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(678, 177);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// panel10
			// 
			this->panel10->BackColor = System::Drawing::Color::WhiteSmoke;
			this->panel10->Controls->Add(this->label3);
			this->panel10->Location = System::Drawing::Point(6, 6);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(282, 165);
			this->panel10->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Gainsboro;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(75, 77);
			this->label3->Margin = System::Windows::Forms::Padding(250);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 29);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Progress";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlcompletedworkout
			// 
			this->pnlcompletedworkout->AutoScroll = true;
			this->pnlcompletedworkout->BackColor = System::Drawing::Color::WhiteSmoke;
			this->pnlcompletedworkout->Controls->Add(this->label6);
			this->pnlcompletedworkout->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pnlcompletedworkout->Location = System::Drawing::Point(298, 6);
			this->pnlcompletedworkout->Name = L"pnlcompletedworkout";
			this->pnlcompletedworkout->Size = System::Drawing::Size(371, 165);
			this->pnlcompletedworkout->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(15, 9);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 29);
			this->label6->TabIndex = 0;
			// 
			// viewcompletedworkout
			// 
			this->viewcompletedworkout->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->viewcompletedworkout->Location = System::Drawing::Point(407, 295);
			this->viewcompletedworkout->Name = L"viewcompletedworkout";
			this->viewcompletedworkout->Size = System::Drawing::Size(89, 36);
			this->viewcompletedworkout->TabIndex = 2;
			this->viewcompletedworkout->Text = L"View";
			this->viewcompletedworkout->UseVisualStyleBackColor = true;
			this->viewcompletedworkout->Click += gcnew System::EventHandler(this, &traiermenu::viewcompletedworkout_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(172, 301);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(207, 23);
			this->textBox1->TabIndex = 3;
			// 
			// panel8
			// 
			this->panel8->Location = System::Drawing::Point(0, 539);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(684, 22);
			this->panel8->TabIndex = 1;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->dataGridView2);
			this->panel7->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel7->Location = System::Drawing::Point(22, 0);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(538, 288);
			this->panel7->TabIndex = 0;
			// 
			// dataGridView2
			// 
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::SkyBlue;
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridView2->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3
			});
			this->dataGridView2->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView2->Location = System::Drawing::Point(62, 3);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->Size = System::Drawing::Size(454, 279);
			this->dataGridView2->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Id";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 125;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Name";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 150;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Workouts";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 125;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(29, 302);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(139, 20);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Enter Client Id :";
			// 
			// clientinfo
			// 
			this->clientinfo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->clientinfo->Controls->Add(this->dataGridView1);
			this->clientinfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->clientinfo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clientinfo->Location = System::Drawing::Point(0, 0);
			this->clientinfo->Margin = System::Windows::Forms::Padding(2);
			this->clientinfo->Name = L"clientinfo";
			this->clientinfo->Size = System::Drawing::Size(699, 534);
			this->clientinfo->TabIndex = 8;
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::SkyBlue;
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle7;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedHeaders;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle8->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle8;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->NAME, this->ID,
					this->Age, this->gender, this->activitylevel, this->workouts
			});
			this->dataGridView1->GridColor = System::Drawing::Color::Black;
			this->dataGridView1->Location = System::Drawing::Point(17, 22);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 45;
			this->dataGridView1->Size = System::Drawing::Size(666, 457);
			this->dataGridView1->TabIndex = 0;
			// 
			// NAME
			// 
			this->NAME->HeaderText = L"Name";
			this->NAME->MinimumWidth = 6;
			this->NAME->Name = L"NAME";
			this->NAME->ReadOnly = true;
			this->NAME->Width = 120;
			// 
			// ID
			// 
			this->ID->HeaderText = L"Id";
			this->ID->MinimumWidth = 6;
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			this->ID->Width = 70;
			// 
			// Age
			// 
			this->Age->HeaderText = L"Age";
			this->Age->MinimumWidth = 6;
			this->Age->Name = L"Age";
			this->Age->ReadOnly = true;
			this->Age->Width = 70;
			// 
			// gender
			// 
			this->gender->HeaderText = L"Gender";
			this->gender->MinimumWidth = 6;
			this->gender->Name = L"gender";
			this->gender->ReadOnly = true;
			this->gender->Width = 125;
			// 
			// activitylevel
			// 
			this->activitylevel->HeaderText = L"Activity Level";
			this->activitylevel->MinimumWidth = 6;
			this->activitylevel->Name = L"activitylevel";
			this->activitylevel->ReadOnly = true;
			this->activitylevel->Width = 150;
			// 
			// workouts
			// 
			this->workouts->HeaderText = L"Workouts";
			this->workouts->MinimumWidth = 6;
			this->workouts->Name = L"workouts";
			this->workouts->ReadOnly = true;
			this->workouts->Width = 80;
			// 
			// traiermenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoValidate = System::Windows::Forms::AutoValidate::EnableAllowFocusChange;
			this->ClientSize = System::Drawing::Size(884, 609);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"traiermenu";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"traiermenu";
			this->Load += gcnew System::EventHandler(this, &traiermenu::traiermenu_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->manage->ResumeLayout(false);
			this->manpanel->ResumeLayout(false);
			this->newwork->ResumeLayout(false);
			this->splitContainer1->Panel1->ResumeLayout(false);
			this->splitContainer1->Panel1->PerformLayout();
			this->splitContainer1->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			this->splitContainer1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numExercises))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numReps))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSets))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDuration))->EndInit();
			this->assign->ResumeLayout(false);
			this->assign->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->customwork->ResumeLayout(false);
			this->customwork->PerformLayout();
			this->splitContainer2->Panel1->ResumeLayout(false);
			this->splitContainer2->Panel1->PerformLayout();
			this->splitContainer2->Panel2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			this->splitContainer2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numExercises1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSets1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDuration1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numReps1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->btn->ResumeLayout(false);
			this->progress->ResumeLayout(false);
			this->progress->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->panel10->ResumeLayout(false);
			this->panel10->PerformLayout();
			this->pnlcompletedworkout->ResumeLayout(false);
			this->pnlcompletedworkout->PerformLayout();
			this->panel7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->clientinfo->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void traiermenu_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel4_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		clientinfo->BringToFront();
		DisplayClients(trainer, dataGridView1);
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		manage->BringToFront();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		progress->BringToFront();
		FillClientsDataGrid(trainer, dataGridView2);
	}
	private: System::Void progress_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		assign->BringToFront();
		FillClientsDataGrid(trainer, dataGridView3);
		LoadWorkoutsToCheckedListBox();
	}
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		newwork->BringToFront();
	}
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		customwork->BringToFront();
		FillClientsDataGrid(trainer, dataGridView4);
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void assign_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}

	private: System::Void customwork_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Predefined workout created successfully!");
	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ clientIdText = textBox2->Text;
		if (String::IsNullOrEmpty(clientIdText)) {
			MessageBox::Show("Please enter a client ID", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		int clientId;
		if (!Int32::TryParse(clientIdText, clientId)) {
			MessageBox::Show("Please enter a valid numeric client ID", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		Client* client = nullptr;
		for (int i = 0; i < trainer->numClients; i++) {
			if (trainer->clients[i].clientID == clientId) {
				client = &trainer->clients[i];
				break;
			}
		}

		if (client == nullptr) {
			MessageBox::Show("Client not found with ID: " + clientId, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		if (checkedListBox1->CheckedItems->Count == 0) {
			MessageBox::Show("Please select at least one workout", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		std::vector<Workout> selectedWorkouts;
		for each (System::Object ^ item in checkedListBox1->CheckedItems) {
			System::String^ workoutName = item->ToString();

			for (int i = 0; i < numPredefinedWorkouts; i++) {
				if (gcnew System::String(predefineWorkout[i].workoutName.c_str()) == workoutName) {
					selectedWorkouts.push_back(predefineWorkout[i]);
					break;
				}
			}
		}

		if (selectedWorkouts.empty()) {
			MessageBox::Show("No valid workouts were selected", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		for (Workout& workout : selectedWorkouts) {
			if (client->numWorkouts < MAX_WORKOUTS) {
				workout.istrue = "Pending";
				client->workoutPlans[client->numWorkouts] = workout;
				client->numWorkouts++;
				insertWorkout(db, workout, client->clientID);
			}
			else {
				MessageBox::Show("Client has reached maximum number of workouts", "Warning",
					MessageBoxButtons::OK, MessageBoxIcon::Warning);
				break;
			}
		}


		if (selectedWorkouts.size() == 1) {
			MessageBox::Show(String::Format("Successfully assigned workout '{0}' to client {1}",
				gcnew String(selectedWorkouts[0].workoutName.c_str()), clientId),
				"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else {
			MessageBox::Show(String::Format("Successfully assigned {0} workouts to client {1}",
				selectedWorkouts.size(), clientId),
				"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		textBox2->Text = "";
		for (int i = 0; i < checkedListBox1->Items->Count; i++) {
			checkedListBox1->SetItemChecked(i, false);
		}

		FillClientsDataGrid(trainer, dataGridView3);
	}
	private: System::Void tableLayoutPanel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Custom workout assigned successfully!");
	}
	private: System::Void dataGridView3_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	

private: System::Void newwork_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void viewcompletedworkout_Click_1(System::Object^ sender, System::EventArgs^ e) {

	pnlcompletedworkout->Controls->Clear();

	Panel^ scrollPanel = gcnew Panel();
	scrollPanel->Dock = DockStyle::Fill;
	scrollPanel->AutoScroll = true;

	// Create label for displaying output
	Label^ outputLabel = gcnew Label();
	outputLabel->AutoSize = true; // Allows dynamic height
	outputLabel->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10, FontStyle::Regular);
	outputLabel->TextAlign = ContentAlignment::TopLeft;

	// Add label to scroll panel
	scrollPanel->Controls->Add(outputLabel);
	pnlcompletedworkout->Controls->Add(scrollPanel);


	if (String::IsNullOrWhiteSpace(textBox1->Text)) {
		MessageBox::Show("Please enter a client ID", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	int clientID;
	if (!Int32::TryParse(textBox1->Text, clientID)) {
		outputLabel->Text = "Please enter a valid client ID.";
		return;
	}

	// Find the client
	int clientIndex = -1;
	for (int i = 0; i < trainer->numClients; i++) {
		if (trainer->clients[i].clientID == clientID) {
			clientIndex = i;
			break;
		}
	}

	if (clientIndex == -1) {
		outputLabel->Text = "Client not found.";
		return;
	}

	Client& selectedClient = trainer->clients[clientIndex];

	System::Text::StringBuilder^ output = gcnew System::Text::StringBuilder();
	output->AppendLine("------ Completed Workouts ------");

	if (selectedClient.numLogs == 0) {
		output->AppendLine("No progress logs for this client.\n");
	}
	else {
		for (int i = 0; i < selectedClient.numLogs; i++) {
			output->AppendLine((i + 1).ToString() + ". " + gcnew String(selectedClient.progressLogs[i].c_str()));
		}
	}

	output->AppendLine("\n------ Measurements ------");
	if (selectedClient.numMeasurements == 0) {
		output->AppendLine("No measurements added.");
	}
	else {
		for (int i = 0; i < selectedClient.numMeasurements; i++) {
			auto m = selectedClient.measurements[i];
			output->AppendLine(String::Format("{0}. Date: {1}/{2}/{3} | Weight: {4}kg | Height: {5}cm",
				i + 1, m.date.Day, m.date.Month, m.date.Year, m.weight, m.height));
		}
	}

	outputLabel->Text = output->ToString();

}

private: System::Void splitContainer1_Panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}

private: System::Void numExercises_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
		   panelExercises->Controls->Clear();

		   int count = (int)numExercises->Value;

		   for (int i = 0; i < count; i++) {
			   Label^ label = gcnew Label();
			   label->Text = "Exercise " + (i + 1) + ":";
			   label->AutoSize = true;

			   TextBox^ txt = gcnew TextBox();
			   txt->Name = "txtExercise" + i;
			   txt->Width = 200;

			   panelExercises->Controls->Add(label);
			   panelExercises->Controls->Add(txt);
		   }
	   }

private: System::Void btnSaveWorkout_Click(System::Object ^ sender, System::EventArgs ^ e) {
		if (numPredefinedWorkouts >= MAX_WORKOUTS) {
			MessageBox::Show("Maximum predefined workouts reached.");
			return;
		}

		Workout* newWorkout = new Workout();

		// Workout name
		String^ name = txtWorkoutName->Text;
		if (String::IsNullOrWhiteSpace(name)) {
			MessageBox::Show("Workout name is empty.");
			return;
		}
		newWorkout->workoutName = msclr::interop::marshal_as<std::string>(name);

		newWorkout->numExercises = (int)numExercises->Value;

		// Read exercise names from panelExercises
		int i = 0;
		for each (Control ^ ctrl in panelExercises->Controls) {
			if (TextBox^ txt = dynamic_cast<TextBox^>(ctrl)) {
				if (String::IsNullOrWhiteSpace(txt->Text)) {
					MessageBox::Show("Exercise " + (i + 1) + " is empty.");
					return;
				}
				newWorkout->exercises[i++] = msclr::interop::marshal_as<std::string>(txt->Text);
			}
		}

		// Read duration, sets, reps
		newWorkout->duration = (int)numDuration->Value;
		newWorkout->sets = (int)numSets->Value;
		newWorkout->reps = (int)numReps->Value;

		predefineWorkout[numPredefinedWorkouts] = *newWorkout;
		insertPredefinedWorkout(db, *newWorkout);
		numPredefinedWorkouts++;

		MessageBox::Show("Workout saved successfully!");
	}

private: System::Void numExercises1_ValueChanged(System::Object^ sender, System::EventArgs^ e) {
	panelExercises1->Controls->Clear();

	int count = (int)numExercises1->Value;

	for (int i = 0; i < count; i++) {
		Label^ label = gcnew Label();
		label->Text = "Exercise " + (i + 1) + ":";
		label->AutoSize = true;

		TextBox^ txt = gcnew TextBox();
		txt->Name = "txtExercise" + i;
		txt->Width = 200;

		panelExercises1->Controls->Add(label);
		panelExercises1->Controls->Add(txt);
	}
}

private: System::Void btnSaveWorkout1_Click(System::Object^ sender, System::EventArgs^ e) {
	// Get client ID
	String^ clientIdText = textBox3->Text;
	if (String::IsNullOrEmpty(clientIdText)) {
		MessageBox::Show("Please enter a client ID", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int clientId;
	if (!Int32::TryParse(clientIdText, clientId)) {
		MessageBox::Show("Please enter a valid numeric client ID", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Find the client
	Client* client = nullptr;
	for (int i = 0; i < trainer->numClients; i++) {
		if (trainer->clients[i].clientID == clientId) {
			client = &trainer->clients[i];
			break;
		}
	}

	if (client == nullptr) {
		MessageBox::Show("Client not found with ID: " + clientId, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Check if client can take more workouts
	if (client->numWorkouts >= MAX_WORKOUTS) {
		MessageBox::Show("Client has reached maximum number of workouts", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Create new workout
	Workout* newWorkout = new Workout();

	// Get workout name
	String^ name = txtWorkoutName1->Text;
	if (String::IsNullOrWhiteSpace(name)) {
		MessageBox::Show("Workout name is required", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	newWorkout->workoutName = msclr::interop::marshal_as<std::string>(name);

	// Get number of exercises
	newWorkout->numExercises = (int)numExercises1->Value;
	if (newWorkout->numExercises <= 0) {
		MessageBox::Show("Number of exercises must be at least 1", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Get exercise names from panelExercises1
	int exerciseCount = 0;
	for each (Control ^ ctrl in panelExercises1->Controls) {
		if (TextBox^ txt = dynamic_cast<TextBox^>(ctrl)) {
			if (String::IsNullOrWhiteSpace(txt->Text)) {
				MessageBox::Show("Exercise " + (exerciseCount + 1) + " is empty", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			newWorkout->exercises[exerciseCount++] = msclr::interop::marshal_as<std::string>(txt->Text);

			if (exerciseCount >= newWorkout->numExercises) break;
		}
	}

	// Get workout parameters
	newWorkout->duration = (int)numDuration1->Value;
	newWorkout->sets = (int)numSets1->Value;
	newWorkout->reps = (int)numReps1->Value;

	// Add workout to client
	newWorkout->istrue = "Pending";
	client->workoutPlans[client->numWorkouts] = *newWorkout;
	client->numWorkouts++;
	// Insert workout into database
	insertWorkout(db, *newWorkout, client->clientID);

	MessageBox::Show("Custom workout created and assigned to client successfully!",
		"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// Clear form
	txtWorkoutName1->Text = "";
	numExercises1->Value = 0;
	numDuration1->Value = 0;
	numSets1->Value = 0;
	numReps1->Value = 0;
	panelExercises1->Controls->Clear();
	textBox3->Text = "";

	// Refresh data grid
	FillClientsDataGrid(trainer, dataGridView4);
}


private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide(); // keeps app running
}

private: System::Void btnSaveWorkout1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	// Get client ID
	String^ clientIdText = textBox3->Text;
	if (String::IsNullOrEmpty(clientIdText)) {
		MessageBox::Show("Please enter a client ID", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int clientId;
	if (!Int32::TryParse(clientIdText, clientId)) {
		MessageBox::Show("Please enter a valid numeric client ID", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Find the client
	Client* client = nullptr;
	for (int i = 0; i < trainer->numClients; i++) {
		if (trainer->clients[i].clientID == clientId) {
			client = &trainer->clients[i];
			break;
		}
	}

	if (client == nullptr) {
		MessageBox::Show("Client not found with ID: " + clientId, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Check if client can take more workouts
	if (client->numWorkouts >= MAX_WORKOUTS) {
		MessageBox::Show("Client has reached maximum number of workouts", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	// Create new workout
	Workout *newWorkout=new Workout();

	// Get workout name
	String^ name = txtWorkoutName1->Text;
	if (String::IsNullOrWhiteSpace(name)) {
		MessageBox::Show("Workout name is required", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		delete newWorkout;
		return;
	}
	newWorkout->workoutName = msclr::interop::marshal_as<std::string>(name);

	// Get number of exercises
	newWorkout->numExercises = (int)numExercises1->Value;
	if (newWorkout->numExercises <= 0) {
		MessageBox::Show("Number of exercises must be at least 1", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		delete newWorkout;
		return;
	}

	// Get exercise names from panelExercises1
	int exerciseCount = 0;
	for each(Control ^ ctrl in panelExercises1->Controls) {
		if (TextBox^ txt = dynamic_cast<TextBox^>(ctrl)) {
			if (String::IsNullOrWhiteSpace(txt->Text)) {
				MessageBox::Show("Exercise " + (exerciseCount + 1) + " is empty", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				delete newWorkout;
				return;
			}
			newWorkout->exercises[exerciseCount++] = msclr::interop::marshal_as<std::string>(txt->Text);

			if (exerciseCount >= newWorkout->numExercises) break;
		}
	}

	// Check if duration, sets, reps are greater than 0
	if (numDuration1->Value == 0) {
		MessageBox::Show("Duration cannot be 0.");
		delete newWorkout;
		return;
	}

	if (numSets1->Value == 0) {
		MessageBox::Show("Sets cannot be 0.");
		delete newWorkout;
		return;
	}

	if (numReps1->Value == 0) {
		MessageBox::Show("Reps cannot be 0.");
		delete newWorkout;
		return;
	}


	// Get workout parameters
	newWorkout->duration = (int)numDuration1->Value;
	newWorkout->sets = (int)numSets1->Value;
	newWorkout->reps = (int)numReps1->Value;

	// Add workout to client
	newWorkout->istrue = "Pending";
	client->workoutPlans[client->numWorkouts] = *newWorkout;
	client->numWorkouts++;
	// Insert workout into database
	insertWorkout(db, *newWorkout, client->clientID);

	MessageBox::Show("Custom workout created and assigned to client successfully!",
		"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);

	// Clear form
	txtWorkoutName1->Text = "";
	numExercises1->Value = 0;
	numDuration1->Value = 0;
	numSets1->Value = 0;
	numReps1->Value = 0;
	panelExercises1->Controls->Clear();
	textBox3->Text = "";

	// Refresh data grid
	FillClientsDataGrid(trainer, dataGridView4);
	delete newWorkout;

}

private: System::Void numExercises1_ValueChanged_1(System::Object^ sender, System::EventArgs^ e) {
	int count = (int)numExercises1->Value;
	int currentCount = panelExercises1->Controls->Count / 2;

	// Add more exercises if needed
	for (int i = currentCount; i < count; i++) {
		Label^ label = gcnew Label();
		label->Text = "Exercise " + (i + 1) + ":";
		label->AutoSize = true;

		TextBox^ txt = gcnew TextBox();
		txt->Name = "txtExercise" + i;
		txt->Width = 200;

		panelExercises1->Controls->Add(label);
		panelExercises1->Controls->Add(txt);
	}

	// Remove extra exercises
	for (int i = currentCount - 1; i >= count; i--) {
		Control^ txt = panelExercises1->Controls["txtExercise" + i];
		if (txt != nullptr) {
			int index = panelExercises1->Controls->IndexOf(txt);
			if (index > 0) {
				panelExercises1->Controls->RemoveAt(index);       // Remove TextBox
				panelExercises1->Controls->RemoveAt(index - 1);   // Remove Label
			}
		}
	}
}


private: System::Void btnSaveWorkout_Click_1(System::Object^ sender, System::EventArgs^ e) {
	if (numPredefinedWorkouts >= MAX_WORKOUTS) {
		MessageBox::Show("Maximum predefined workouts reached.");
		return;
	}

	Workout* newWorkout = new Workout();

	// Workout name
	String^ name = txtWorkoutName->Text;
	if (String::IsNullOrWhiteSpace(name)) {
		MessageBox::Show("Workout name is empty.");
		delete newWorkout;
		return;
	}
	newWorkout->workoutName = msclr::interop::marshal_as<std::string>(name);

	newWorkout->numExercises = (int)numExercises->Value;

	// Read exercise names from panelExercises
	int i = 0;
	for each (Control ^ ctrl in panelExercises->Controls) {
		if (TextBox^ txt = dynamic_cast<TextBox^>(ctrl)) {
			if (String::IsNullOrWhiteSpace(txt->Text)) {
				MessageBox::Show("Exercise " + (i + 1) + " is empty.");
				delete newWorkout;
				return;
			}
			newWorkout->exercises[i++] = msclr::interop::marshal_as<std::string>(txt->Text);
		}
	}

	// Check if duration, sets, reps are greater than 0
	if (numDuration->Value == 0) {
		MessageBox::Show("Duration cannot be 0.");
		delete newWorkout;
		return;
	}

	if (numSets->Value == 0) {
		MessageBox::Show("Sets cannot be 0.");
		delete newWorkout;
		return;
	}

	if (numReps->Value == 0) {
		MessageBox::Show("Reps cannot be 0.");
		delete newWorkout;
		return;
	}

	// Read duration, sets, reps
	newWorkout->duration = (int)numDuration->Value;
	newWorkout->sets = (int)numSets->Value;
	newWorkout->reps = (int)numReps->Value;

	// Save the workout
	predefineWorkout[numPredefinedWorkouts] = *newWorkout;
	insertPredefinedWorkout(db, *newWorkout);
	numPredefinedWorkouts++;

	MessageBox::Show("Workout saved successfully!");

	txtWorkoutName->Text = "";
	numExercises->Value = 0;
	numDuration->Value = 0;
	numSets->Value = 0;
	numReps->Value = 0;
	panelExercises->Controls->Clear();
	

	delete newWorkout;
}

private: System::Void numExercises_ValueChanged_1(System::Object^ sender, System::EventArgs^ e) {
	int count = (int)numExercises->Value;
	int currentCount = panelExercises->Controls->Count / 2; // each exercise has Label + TextBox

	// 🟢 Add new exercises
	for (int i = currentCount; i < count; i++) {
		Label^ label = gcnew Label();
		label->Text = "Exercise " + (i + 1) + ":";
		label->AutoSize = true;
		label->Location = System::Drawing::Point(10, i * 40);  // Adjust spacing

		TextBox^ txt = gcnew TextBox();
		txt->Name = "txtExercise" + i;
		txt->Width = 200;
		txt->Location = System::Drawing::Point(100, i * 40);

		// Optional Fade-In animation (manual)
		txt->Visible = false;
		label->Visible = false;

		panelExercises->Controls->Add(label);
		panelExercises->Controls->Add(txt);

		// Use Timer or just show instantly for now
		label->Visible = true;
		txt->Visible = true;
	}

	// 🔴 Remove extra exercises
	if (currentCount > count) {
		for (int i = currentCount - 1; i >= count; i--) {
			// Remove TextBox
			Control^ txt = panelExercises->Controls["txtExercise" + i];
			if (txt != nullptr) {
				int index = panelExercises->Controls->IndexOf(txt);
				if (index > 0) {
					panelExercises->Controls->RemoveAt(index);       // Remove TextBox
					panelExercises->Controls->RemoveAt(index - 1);   // Remove its Label
				}
			}
		}

	}
}

private: System::Void button9_Click_1(System::Object^ sender, System::EventArgs^ e) {
	String^ clientIdText = textBox2->Text;
	if (String::IsNullOrEmpty(clientIdText)) {
		MessageBox::Show("Please enter a client ID", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int clientId;
	if (!Int32::TryParse(clientIdText, clientId)) {
		MessageBox::Show("Please enter a valid numeric client ID", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	Client* client = nullptr;
	for (int i = 0; i < trainer->numClients; i++) {
		if (trainer->clients[i].clientID == clientId) {
			client = &trainer->clients[i];
			break;
		}
	}

	if (client == nullptr) {
		MessageBox::Show("Client not found with ID: " + clientId, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (checkedListBox1->CheckedItems->Count == 0) {
		MessageBox::Show("Please select at least one workout", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	std::vector<Workout> selectedWorkouts;
	for each(System::Object ^ item in checkedListBox1->CheckedItems) {
		System::String^ workoutName = item->ToString();

		for (int i = 0; i < numPredefinedWorkouts; i++) {
			if (gcnew System::String(predefineWorkout[i].workoutName.c_str()) == workoutName) {
				selectedWorkouts.push_back(predefineWorkout[i]);
				break;
			}
		}
	}

	if (selectedWorkouts.empty()) {
		MessageBox::Show("No valid workouts were selected", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	for (Workout& workout : selectedWorkouts) {
		if (client->numWorkouts < MAX_WORKOUTS) {
			workout.istrue = "Pending";
			client->workoutPlans[client->numWorkouts] = workout;
			client->numWorkouts++;
			insertWorkout(db, workout, client->clientID);
		}
		else {
			MessageBox::Show("Client has reached maximum number of workouts", "Warning",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			break;
		}
	}


	if (selectedWorkouts.size() == 1) {
		MessageBox::Show(String::Format("Successfully assigned workout '{0}' to client {1}",
			gcnew String(selectedWorkouts[0].workoutName.c_str()), clientId),
			"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	else {
		MessageBox::Show(String::Format("Successfully assigned {0} workouts to client {1}",
			selectedWorkouts.size(), clientId),
			"Success", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	textBox2->Text = "";
	for (int i = 0; i < checkedListBox1->Items->Count; i++) {
		checkedListBox1->SetItemChecked(i, false);
	}

	FillClientsDataGrid(trainer, dataGridView3);
}


private: System::Void dataGridView3_CellFormatting(System::Object^ sender, System::Windows::Forms::DataGridViewCellFormattingEventArgs^ e) {
}
};
}
