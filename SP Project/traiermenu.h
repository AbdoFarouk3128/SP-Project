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

				// ÅÖÇÝÉ ÕÝ ÌÏíÏ Ýí DataGrid
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
	private: System::Windows::Forms::Panel^ manage;
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
	private: System::Windows::Forms::Panel^ btn;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Panel^ assign;
	private: System::Windows::Forms::Panel^ customwork;
	private: System::Windows::Forms::Panel^ newwork;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::Button^ button9;

	private: System::Windows::Forms::Label^ label5;





	private: System::Windows::Forms::TextBox^ textBox3;













private: System::Windows::Forms::DataGridViewTextBoxColumn^ NAME;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ Age;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ gender;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ activitylevel;
private: System::Windows::Forms::DataGridViewTextBoxColumn^ workouts;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
private: System::Windows::Forms::Panel^ panel10;
private: System::Windows::Forms::Label^ label3;
private: System::Windows::Forms::Panel^ pnlcompletedworkout;
private: System::Windows::Forms::Button^ viewcompletedworkout;
private: System::Windows::Forms::Label^ label6;
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
private: System::Windows::Forms::SplitContainer^ splitContainer2;
private: System::Windows::Forms::TextBox^ txtWorkoutName1;

private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::Label^ label16;
private: System::Windows::Forms::Label^ label15;
private: System::Windows::Forms::Label^ label14;
private: System::Windows::Forms::Label^ label13;
private: System::Windows::Forms::NumericUpDown^ numReps1;
private: System::Windows::Forms::Button^ btnSaveWorkout1;



private: System::Windows::Forms::NumericUpDown^ numExercises1;

private: System::Windows::Forms::NumericUpDown^ numSets1;

private: System::Windows::Forms::NumericUpDown^ numDuration1;
private: System::Windows::Forms::FlowLayoutPanel^ panelExercises1;
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
			this->btn = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
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
			this->customwork = (gcnew System::Windows::Forms::Panel());
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
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->assign = (gcnew System::Windows::Forms::Panel());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->progress = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->pnlcompletedworkout = (gcnew System::Windows::Forms::Panel());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->viewcompletedworkout = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
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
			this->btn->SuspendLayout();
			this->newwork->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			this->splitContainer1->Panel1->SuspendLayout();
			this->splitContainer1->Panel2->SuspendLayout();
			this->splitContainer1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numExercises))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numReps))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numSets))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numDuration))->BeginInit();
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
			this->assign->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
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
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->panel1->Controls->Add(this->pictureBox4);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1179, 123);
			this->panel1->TabIndex = 0;
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->Location = System::Drawing::Point(20, 9);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(169, 111);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 1;
			this->pictureBox4->TabStop = false;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(396, 34);
			this->label1->Margin = System::Windows::Forms::Padding(267, 246, 267, 246);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(344, 52);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TRAINER MENU";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->panel2->Controls->Add(this->button7);
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 123);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(267, 691);
			this->panel2->TabIndex = 1;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(35, 618);
			this->button7->Margin = System::Windows::Forms::Padding(4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(195, 58);
			this->button7->TabIndex = 3;
			this->button7->Text = L"LOGOUT";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &traiermenu::button7_Click);
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->pictureBox3);
			this->panel6->Controls->Add(this->button3);
			this->panel6->Location = System::Drawing::Point(0, 398);
			this->panel6->Margin = System::Windows::Forms::Padding(13, 12, 13, 12);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(267, 199);
			this->panel6->TabIndex = 2;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(56, 12);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(133, 62);
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
			this->button3->Location = System::Drawing::Point(5, 101);
			this->button3->Margin = System::Windows::Forms::Padding(4);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(249, 65);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Client Progress";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &traiermenu::button3_Click);
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->pictureBox2);
			this->panel5->Controls->Add(this->button2);
			this->panel5->Location = System::Drawing::Point(0, 203);
			this->panel5->Margin = System::Windows::Forms::Padding(13, 12, 13, 12);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(267, 191);
			this->panel5->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(56, 25);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(133, 62);
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
			this->button2->Location = System::Drawing::Point(4, 94);
			this->button2->Margin = System::Windows::Forms::Padding(4);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(255, 65);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Manage Workouts";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &traiermenu::button2_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pictureBox1);
			this->panel4->Controls->Add(this->button1);
			this->panel4->Location = System::Drawing::Point(4, 0);
			this->panel4->Margin = System::Windows::Forms::Padding(13, 12, 13, 12);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(255, 190);
			this->panel4->TabIndex = 0;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::panel4_Paint);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(52, 12);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(133, 62);
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
			this->button1->Location = System::Drawing::Point(1, 97);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(253, 74);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Clients Information";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &traiermenu::button1_Click_1);
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->panel3->Controls->Add(this->manage);
			this->panel3->Controls->Add(this->progress);
			this->panel3->Controls->Add(this->clientinfo);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(267, 123);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(912, 691);
			this->panel3->TabIndex = 2;
			// 
			// manage
			// 
			this->manage->BackColor = System::Drawing::Color::White;
			this->manage->Controls->Add(this->btn);
			this->manage->Controls->Add(this->newwork);
			this->manage->Controls->Add(this->customwork);
			this->manage->Controls->Add(this->assign);
			this->manage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->manage->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->manage->Location = System::Drawing::Point(0, 0);
			this->manage->Margin = System::Windows::Forms::Padding(4);
			this->manage->Name = L"manage";
			this->manage->Size = System::Drawing::Size(912, 691);
			this->manage->TabIndex = 5;
			// 
			// btn
			// 
			this->btn->Controls->Add(this->button6);
			this->btn->Controls->Add(this->button5);
			this->btn->Controls->Add(this->button4);
			this->btn->Dock = System::Windows::Forms::DockStyle::Top;
			this->btn->Location = System::Drawing::Point(0, 0);
			this->btn->Margin = System::Windows::Forms::Padding(4);
			this->btn->Name = L"btn";
			this->btn->Size = System::Drawing::Size(912, 92);
			this->btn->TabIndex = 0;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(579, 12);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(317, 80);
			this->button6->TabIndex = 2;
			this->button6->Text = L"Create Custom Workout for Client";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &traiermenu::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(263, 12);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(308, 80);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Create New Predefined Workout";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &traiermenu::button5_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(8, 12);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(247, 80);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Assign Predefined Workout";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &traiermenu::button4_Click);
			// 
			// newwork
			// 
			this->newwork->Controls->Add(this->splitContainer1);
			this->newwork->Location = System::Drawing::Point(0, 107);
			this->newwork->Margin = System::Windows::Forms::Padding(4);
			this->newwork->Name = L"newwork";
			this->newwork->Size = System::Drawing::Size(912, 583);
			this->newwork->TabIndex = 3;
			this->newwork->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::newwork_Paint);
			// 
			// splitContainer1
			// 
			this->splitContainer1->Location = System::Drawing::Point(0, -4);
			this->splitContainer1->Margin = System::Windows::Forms::Padding(4);
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
			this->splitContainer1->Size = System::Drawing::Size(912, 587);
			this->splitContainer1->SplitterDistance = 422;
			this->splitContainer1->SplitterWidth = 5;
			this->splitContainer1->TabIndex = 0;
			// 
			// btnSaveWorkout
			// 
			this->btnSaveWorkout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->btnSaveWorkout->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSaveWorkout->ForeColor = System::Drawing::SystemColors::Control;
			this->btnSaveWorkout->Location = System::Drawing::Point(95, 324);
			this->btnSaveWorkout->Margin = System::Windows::Forms::Padding(4);
			this->btnSaveWorkout->Name = L"btnSaveWorkout";
			this->btnSaveWorkout->Size = System::Drawing::Size(235, 64);
			this->btnSaveWorkout->TabIndex = 10;
			this->btnSaveWorkout->Text = L"Save";
			this->btnSaveWorkout->UseVisualStyleBackColor = false;
			this->btnSaveWorkout->Click += gcnew System::EventHandler(this, &traiermenu::btnSaveWorkout_Click);
			// 
			// numExercises
			// 
			this->numExercises->Location = System::Drawing::Point(211, 231);
			this->numExercises->Margin = System::Windows::Forms::Padding(4);
			this->numExercises->Name = L"numExercises";
			this->numExercises->Size = System::Drawing::Size(180, 27);
			this->numExercises->TabIndex = 9;
			this->numExercises->ValueChanged += gcnew System::EventHandler(this, &traiermenu::numExercises_ValueChanged);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(12, 240);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(185, 21);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Number of Exercises";
			// 
			// numReps
			// 
			this->numReps->Location = System::Drawing::Point(211, 187);
			this->numReps->Margin = System::Windows::Forms::Padding(4);
			this->numReps->Name = L"numReps";
			this->numReps->Size = System::Drawing::Size(180, 27);
			this->numReps->TabIndex = 7;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(41, 190);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(52, 21);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Reps";
			// 
			// numSets
			// 
			this->numSets->Location = System::Drawing::Point(211, 134);
			this->numSets->Margin = System::Windows::Forms::Padding(4);
			this->numSets->Name = L"numSets";
			this->numSets->Size = System::Drawing::Size(180, 27);
			this->numSets->TabIndex = 5;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(41, 143);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(47, 21);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Sets";
			// 
			// numDuration
			// 
			this->numDuration->Location = System::Drawing::Point(211, 89);
			this->numDuration->Margin = System::Windows::Forms::Padding(4);
			this->numDuration->Name = L"numDuration";
			this->numDuration->Size = System::Drawing::Size(180, 27);
			this->numDuration->TabIndex = 3;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(43, 96);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(138, 21);
			this->label8->TabIndex = 2;
			this->label8->Text = L"Duration (min)";
			// 
			// txtWorkoutName
			// 
			this->txtWorkoutName->Location = System::Drawing::Point(211, 36);
			this->txtWorkoutName->Margin = System::Windows::Forms::Padding(4);
			this->txtWorkoutName->Name = L"txtWorkoutName";
			this->txtWorkoutName->Size = System::Drawing::Size(180, 27);
			this->txtWorkoutName->TabIndex = 1;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(43, 39);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(138, 21);
			this->label7->TabIndex = 0;
			this->label7->Text = L"Workout Name";
			// 
			// panelExercises
			// 
			this->panelExercises->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelExercises->Location = System::Drawing::Point(0, 0);
			this->panelExercises->Margin = System::Windows::Forms::Padding(4);
			this->panelExercises->Name = L"panelExercises";
			this->panelExercises->Size = System::Drawing::Size(485, 587);
			this->panelExercises->TabIndex = 0;
			// 
			// customwork
			// 
			this->customwork->Controls->Add(this->splitContainer2);
			this->customwork->Controls->Add(this->textBox3);
			this->customwork->Controls->Add(this->label5);
			this->customwork->Controls->Add(this->dataGridView4);
			this->customwork->Location = System::Drawing::Point(0, 103);
			this->customwork->Margin = System::Windows::Forms::Padding(4);
			this->customwork->Name = L"customwork";
			this->customwork->Size = System::Drawing::Size(912, 587);
			this->customwork->TabIndex = 2;
			// 
			// splitContainer2
			// 
			this->splitContainer2->Location = System::Drawing::Point(1, 273);
			this->splitContainer2->Margin = System::Windows::Forms::Padding(4);
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
			this->splitContainer2->Size = System::Drawing::Size(909, 313);
			this->splitContainer2->SplitterDistance = 434;
			this->splitContainer2->SplitterWidth = 5;
			this->splitContainer2->TabIndex = 6;
			// 
			// numExercises1
			// 
			this->numExercises1->Location = System::Drawing::Point(237, 185);
			this->numExercises1->Margin = System::Windows::Forms::Padding(4);
			this->numExercises1->Name = L"numExercises1";
			this->numExercises1->Size = System::Drawing::Size(177, 27);
			this->numExercises1->TabIndex = 21;
			this->numExercises1->ValueChanged += gcnew System::EventHandler(this, &traiermenu::numExercises1_ValueChanged);
			// 
			// numSets1
			// 
			this->numSets1->Location = System::Drawing::Point(237, 98);
			this->numSets1->Margin = System::Windows::Forms::Padding(4);
			this->numSets1->Name = L"numSets1";
			this->numSets1->Size = System::Drawing::Size(177, 27);
			this->numSets1->TabIndex = 20;
			// 
			// numDuration1
			// 
			this->numDuration1->Location = System::Drawing::Point(237, 60);
			this->numDuration1->Margin = System::Windows::Forms::Padding(4);
			this->numDuration1->Name = L"numDuration1";
			this->numDuration1->Size = System::Drawing::Size(177, 27);
			this->numDuration1->TabIndex = 19;
			// 
			// txtWorkoutName1
			// 
			this->txtWorkoutName1->Location = System::Drawing::Point(237, 21);
			this->txtWorkoutName1->Margin = System::Windows::Forms::Padding(4);
			this->txtWorkoutName1->Name = L"txtWorkoutName1";
			this->txtWorkoutName1->Size = System::Drawing::Size(176, 27);
			this->txtWorkoutName1->TabIndex = 18;
			// 
			// btnSaveWorkout1
			// 
			this->btnSaveWorkout1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->btnSaveWorkout1->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSaveWorkout1->ForeColor = System::Drawing::SystemColors::Control;
			this->btnSaveWorkout1->Location = System::Drawing::Point(93, 226);
			this->btnSaveWorkout1->Margin = System::Windows::Forms::Padding(4);
			this->btnSaveWorkout1->Name = L"btnSaveWorkout1";
			this->btnSaveWorkout1->Size = System::Drawing::Size(235, 64);
			this->btnSaveWorkout1->TabIndex = 11;
			this->btnSaveWorkout1->Text = L"Save";
			this->btnSaveWorkout1->UseVisualStyleBackColor = false;
			this->btnSaveWorkout1->Click += gcnew System::EventHandler(this, &traiermenu::btnSaveWorkout1_Click);
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(55, 146);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(52, 21);
			this->label17->TabIndex = 17;
			this->label17->Text = L"Reps";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(55, 101);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(47, 21);
			this->label16->TabIndex = 16;
			this->label16->Text = L"Sets";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(55, 63);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(138, 21);
			this->label15->TabIndex = 15;
			this->label15->Text = L"Duration (min)";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(53, 26);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(138, 21);
			this->label14->TabIndex = 14;
			this->label14->Text = L"Workout Name";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(25, 187);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(185, 21);
			this->label13->TabIndex = 13;
			this->label13->Text = L"Number of Exercises";
			// 
			// numReps1
			// 
			this->numReps1->Location = System::Drawing::Point(237, 140);
			this->numReps1->Margin = System::Windows::Forms::Padding(4);
			this->numReps1->Name = L"numReps1";
			this->numReps1->Size = System::Drawing::Size(177, 27);
			this->numReps1->TabIndex = 12;
			// 
			// panelExercises1
			// 
			this->panelExercises1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panelExercises1->Location = System::Drawing::Point(0, 0);
			this->panelExercises1->Margin = System::Windows::Forms::Padding(4);
			this->panelExercises1->Name = L"panelExercises1";
			this->panelExercises1->Size = System::Drawing::Size(470, 313);
			this->panelExercises1->TabIndex = 0;
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(601, 142);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(163, 36);
			this->textBox3->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(573, 100);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(210, 29);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Enter Client Id : ";
			// 
			// dataGridView4
			// 
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->dataGridView4->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView4->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView4->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn4,
					this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6
			});
			this->dataGridView4->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView4->Location = System::Drawing::Point(8, 22);
			this->dataGridView4->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->RowHeadersWidth = 51;
			this->dataGridView4->Size = System::Drawing::Size(468, 251);
			this->dataGridView4->TabIndex = 0;
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
			// assign
			// 
			this->assign->Controls->Add(this->button9);
			this->assign->Controls->Add(this->checkedListBox1);
			this->assign->Controls->Add(this->textBox2);
			this->assign->Controls->Add(this->label4);
			this->assign->Controls->Add(this->dataGridView3);
			this->assign->Location = System::Drawing::Point(0, 107);
			this->assign->Margin = System::Windows::Forms::Padding(4);
			this->assign->Name = L"assign";
			this->assign->Size = System::Drawing::Size(912, 583);
			this->assign->TabIndex = 1;
			this->assign->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::assign_Paint);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->button9->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->button9->Location = System::Drawing::Point(13, 433);
			this->button9->Margin = System::Windows::Forms::Padding(4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(151, 62);
			this->button9->TabIndex = 4;
			this->button9->Text = L"Submit";
			this->button9->UseVisualStyleBackColor = false;
			this->button9->Click += gcnew System::EventHandler(this, &traiermenu::button9_Click);
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->checkedListBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(17, 318);
			this->checkedListBox1->Margin = System::Windows::Forms::Padding(4);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(852, 92);
			this->checkedListBox1->Sorted = true;
			this->checkedListBox1->TabIndex = 3;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(229, 277);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(167, 27);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(17, 277);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(176, 24);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Enter Client Id : ";
			// 
			// dataGridView3
			// 
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->dataGridView3->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle3;
			this->dataGridView3->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle4->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView3->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Column2, this->Column3
			});
			this->dataGridView3->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView3->Location = System::Drawing::Point(8, 15);
			this->dataGridView3->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->Size = System::Drawing::Size(468, 240);
			this->dataGridView3->TabIndex = 0;
			this->dataGridView3->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &traiermenu::dataGridView3_CellContentClick);
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
			this->Column2->Width = 130;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Workout";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 80;
			// 
			// progress
			// 
			this->progress->BackColor = System::Drawing::Color::White;
			this->progress->Controls->Add(this->panel9);
			this->progress->Controls->Add(this->viewcompletedworkout);
			this->progress->Controls->Add(this->textBox1);
			this->progress->Controls->Add(this->label2);
			this->progress->Controls->Add(this->panel8);
			this->progress->Controls->Add(this->panel7);
			this->progress->Dock = System::Windows::Forms::DockStyle::Fill;
			this->progress->Location = System::Drawing::Point(0, 0);
			this->progress->Margin = System::Windows::Forms::Padding(4);
			this->progress->Name = L"progress";
			this->progress->Size = System::Drawing::Size(912, 691);
			this->progress->TabIndex = 4;
			// 
			// panel9
			// 
			this->panel9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->panel9->Controls->Add(this->tableLayoutPanel5);
			this->panel9->Location = System::Drawing::Point(4, 422);
			this->panel9->Margin = System::Windows::Forms::Padding(4);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(904, 255);
			this->panel9->TabIndex = 4;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->BackColor = System::Drawing::Color::Gainsboro;
			this->tableLayoutPanel5->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetDouble;
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				43.32344F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				56.67656F)));
			this->tableLayoutPanel5->Controls->Add(this->panel10, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->pnlcompletedworkout, 1, 0);
			this->tableLayoutPanel5->Location = System::Drawing::Point(4, 0);
			this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(899, 254);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->label3);
			this->panel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel10->Location = System::Drawing::Point(7, 7);
			this->panel10->Margin = System::Windows::Forms::Padding(4);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(377, 240);
			this->panel10->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Bottom;
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Gainsboro;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(100, 108);
			this->label3->Margin = System::Windows::Forms::Padding(333, 308, 333, 308);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(165, 36);
			this->label3->TabIndex = 1;
			this->label3->Text = L"Progress";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// pnlcompletedworkout
			// 
			this->pnlcompletedworkout->Controls->Add(this->label6);
			this->pnlcompletedworkout->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pnlcompletedworkout->Location = System::Drawing::Point(395, 7);
			this->pnlcompletedworkout->Margin = System::Windows::Forms::Padding(4);
			this->pnlcompletedworkout->Name = L"pnlcompletedworkout";
			this->pnlcompletedworkout->Size = System::Drawing::Size(495, 239);
			this->pnlcompletedworkout->TabIndex = 1;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(20, 11);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(0, 36);
			this->label6->TabIndex = 0;
			// 
			// viewcompletedworkout
			// 
			this->viewcompletedworkout->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->viewcompletedworkout->Location = System::Drawing::Point(537, 358);
			this->viewcompletedworkout->Margin = System::Windows::Forms::Padding(4);
			this->viewcompletedworkout->Name = L"viewcompletedworkout";
			this->viewcompletedworkout->Size = System::Drawing::Size(119, 44);
			this->viewcompletedworkout->TabIndex = 2;
			this->viewcompletedworkout->Text = L"View";
			this->viewcompletedworkout->UseVisualStyleBackColor = true;
			this->viewcompletedworkout->Click += gcnew System::EventHandler(this, &traiermenu::viewcompletedworkout_Click_1);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(229, 370);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(275, 27);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(8, 372);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(184, 23);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Enter Client Id :";
			// 
			// panel8
			// 
			this->panel8->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel8->Location = System::Drawing::Point(0, 679);
			this->panel8->Margin = System::Windows::Forms::Padding(4);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(912, 12);
			this->panel8->TabIndex = 1;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->dataGridView2);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel7->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel7->Location = System::Drawing::Point(0, 0);
			this->panel7->Margin = System::Windows::Forms::Padding(4);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(912, 343);
			this->panel7->TabIndex = 0;
			// 
			// dataGridView2
			// 
			dataGridViewCellStyle5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle5->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::Color::White;
			this->dataGridView2->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle5;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle6->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle6->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle6->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle6->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle6->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle6->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle6->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle6;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3
			});
			this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView2->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->Size = System::Drawing::Size(912, 343);
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
			// clientinfo
			// 
			this->clientinfo->Controls->Add(this->dataGridView1);
			this->clientinfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->clientinfo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clientinfo->Location = System::Drawing::Point(0, 0);
			this->clientinfo->Margin = System::Windows::Forms::Padding(267, 246, 267, 246);
			this->clientinfo->Name = L"clientinfo";
			this->clientinfo->Size = System::Drawing::Size(912, 691);
			this->clientinfo->TabIndex = 1;
			// 
			// dataGridView1
			// 
			dataGridViewCellStyle7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle7->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle7->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(128)));
			this->dataGridView1->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle7;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedHeaders;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle8->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle8->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle8->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle8->SelectionBackColor = System::Drawing::Color::Gainsboro;
			dataGridViewCellStyle8->SelectionForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			dataGridViewCellStyle8->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle8;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->NAME, this->ID,
					this->Age, this->gender, this->activitylevel, this->workouts
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->GridColor = System::Drawing::Color::Black;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(267, 246, 267, 246);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 45;
			this->dataGridView1->Size = System::Drawing::Size(912, 691);
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
			this->activitylevel->Width = 170;
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
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1179, 814);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4);
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
			this->btn->ResumeLayout(false);
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
			this->assign->ResumeLayout(false);
			this->assign->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
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

	// Clear previous content
	pnlcompletedworkout->Controls->Clear();

	// Create a new label with proper properties
	Label^ outputLabel = gcnew Label();
	outputLabel->AutoSize = false;
	outputLabel->Dock = DockStyle::Fill;
	outputLabel->Font = gcnew System::Drawing::Font("Microsoft Sans Serif", 10, FontStyle::Regular);
	outputLabel->TextAlign = ContentAlignment::TopLeft;

	// Add scroll functionality
	Panel^ scrollPanel = gcnew Panel();
	scrollPanel->Dock = DockStyle::Fill;
	scrollPanel->AutoScroll = true;
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

		Workout newWorkout;

		// Workout name
		String^ name = txtWorkoutName->Text;
		if (String::IsNullOrWhiteSpace(name)) {
			MessageBox::Show("Workout name is empty.");
			return;
		}
		newWorkout.workoutName = msclr::interop::marshal_as<std::string>(name);

		newWorkout.numExercises = (int)numExercises->Value;

		// Read exercise names from panelExercises
		int i = 0;
		for each (Control ^ ctrl in panelExercises->Controls) {
			if (TextBox^ txt = dynamic_cast<TextBox^>(ctrl)) {
				if (String::IsNullOrWhiteSpace(txt->Text)) {
					MessageBox::Show("Exercise " + (i + 1) + " is empty.");
					return;
				}
				newWorkout.exercises[i++] = msclr::interop::marshal_as<std::string>(txt->Text);
			}
		}

		// Read duration, sets, reps
		newWorkout.duration = (int)numDuration->Value;
		newWorkout.sets = (int)numSets->Value;
		newWorkout.reps = (int)numReps->Value;

		predefineWorkout[numPredefinedWorkouts] = newWorkout;
		insertPredefinedWorkout(db, newWorkout);
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
	Workout newWorkout;

	// Get workout name
	String^ name = txtWorkoutName1->Text;
	if (String::IsNullOrWhiteSpace(name)) {
		MessageBox::Show("Workout name is required", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	newWorkout.workoutName = msclr::interop::marshal_as<std::string>(name);

	// Get number of exercises
	newWorkout.numExercises = (int)numExercises1->Value;
	if (newWorkout.numExercises <= 0) {
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
			newWorkout.exercises[exerciseCount++] = msclr::interop::marshal_as<std::string>(txt->Text);

			if (exerciseCount >= newWorkout.numExercises) break;
		}
	}

	// Get workout parameters
	newWorkout.duration = (int)numDuration1->Value;
	newWorkout.sets = (int)numSets1->Value;
	newWorkout.reps = (int)numReps1->Value;

	// Add workout to client
	newWorkout.istrue = "Pending";
	client->workoutPlans[client->numWorkouts] = newWorkout;
	client->numWorkouts++;
	// Insert workout into database
	insertWorkout(db, newWorkout, client->clientID);

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
//private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
//	WelcomeForm^ wf = gcnew WelcomeForm();
//	wf->Show();
//	this->Hide(); // keeps app running
//}

private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
	Application::ExitThread();
}
};
}
