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
		void DisplayClients(Trainer* trainer, DataGridView^ dgvClients) {
			dgvClients->Rows->Clear();
			

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
			for (int i = 0; i < trainer->numClients; i++) {
				String^ clientID = trainer->clients[i].clientID.ToString();
				String^ name = gcnew String(trainer->clients[i].name.c_str());
				String^ workouts = trainer->clients[i].numWorkouts.ToString();

				// ≈÷«›… ’› ÃœÌœ ›Ì DataGrid
				data->Rows->Add(clientID, name, workouts);
			}
		}
		void LoadWorkoutsToCheckedListBox() {
			checkedListBox1->Items->Clear();

			for (int i = 0; i < numPredefinedWorkouts; i++) {

				std::string nativeItem = predefineWorkout[i].workoutName + " (" + std::to_string(predefineWorkout[i].duration) +
					"minutes)";
				String^ item = gcnew String(nativeItem.c_str());
				checkedListBox1->Items->Add(item);
			}
			checkedListBox1->CheckOnClick = true;
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



	private: System::Windows::Forms::DataGridView^ dataGridView4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Button^ button7;


	private: System::Windows::Forms::Button^ button9;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel3;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox6;
	private: System::Windows::Forms::Label^ label17;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown5;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown6;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown8;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel4;
	private: System::Windows::Forms::Button^ button10;

	private: System::Windows::Forms::TextBox^ textBox7;

	private: System::Windows::Forms::NumericUpDown^ numericUpDown7;
	private: System::Windows::Forms::TextBox^ textBox8;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ compelet;


	private: System::Windows::Forms::Button^ viewcompletedworkout;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::CheckedListBox^ checkedListBox1;
	private: System::Windows::Forms::TableLayoutPanel^ excercise;
	private: System::Windows::Forms::TextBox^ txtReps;
	private: System::Windows::Forms::TextBox^ txtSets;
	private: System::Windows::Forms::TextBox^ txtDuration;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ txtWorkoutName;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Panel^ panel10;
	private: System::Windows::Forms::Button^ generate;
	private: System::Windows::Forms::NumericUpDown^ numExercises;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NAME;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Age;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ gender;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ activitylevel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ workouts;









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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
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
			this->clientinfo = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->NAME = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->ID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Age = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->gender = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->activitylevel = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->workouts = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->manage = (gcnew System::Windows::Forms::Panel());
			this->btn = (gcnew System::Windows::Forms::Panel());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->newwork = (gcnew System::Windows::Forms::Panel());
			this->excercise = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->numExercises = (gcnew System::Windows::Forms::NumericUpDown());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtReps = (gcnew System::Windows::Forms::TextBox());
			this->txtSets = (gcnew System::Windows::Forms::TextBox());
			this->txtDuration = (gcnew System::Windows::Forms::TextBox());
			this->txtWorkoutName = (gcnew System::Windows::Forms::TextBox());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->generate = (gcnew System::Windows::Forms::Button());
			this->assign = (gcnew System::Windows::Forms::Panel());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->customwork = (gcnew System::Windows::Forms::Panel());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel3 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown5 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown7 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown6 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown8 = (gcnew System::Windows::Forms::NumericUpDown());
			this->tableLayoutPanel4 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->progress = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel5 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->compelet = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->viewcompletedworkout = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			this->clientinfo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->manage->SuspendLayout();
			this->btn->SuspendLayout();
			this->newwork->SuspendLayout();
			this->excercise->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numExercises))->BeginInit();
			this->panel10->SuspendLayout();
			this->assign->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->customwork->SuspendLayout();
			this->tableLayoutPanel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown8))->BeginInit();
			this->tableLayoutPanel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			this->progress->SuspendLayout();
			this->panel9->SuspendLayout();
			this->tableLayoutPanel5->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(884, 70);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(490, 28);
			this->label1->Margin = System::Windows::Forms::Padding(200);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(275, 42);
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
			this->panel2->Location = System::Drawing::Point(0, 70);
			this->panel2->Margin = System::Windows::Forms::Padding(4);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 591);
			this->panel2->TabIndex = 1;
			// 
			// button7
			// 
			this->button7->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button7->Location = System::Drawing::Point(35, 618);
			this->button7->Margin = System::Windows::Forms::Padding(4);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(146, 47);
			this->button7->TabIndex = 3;
			this->button7->Text = L"LOGOUT";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->pictureBox3);
			this->panel6->Controls->Add(this->button3);
			this->panel6->Location = System::Drawing::Point(0, 323);
			this->panel6->Margin = System::Windows::Forms::Padding(10);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(200, 162);
			this->panel6->TabIndex = 2;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(56, 12);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(100, 50);
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
			this->panel5->Size = System::Drawing::Size(200, 155);
			this->panel5->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(56, 25);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 50);
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
			this->panel4->Size = System::Drawing::Size(191, 154);
			this->panel4->TabIndex = 0;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::panel4_Paint);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(52, 12);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &traiermenu::pictureBox1_Click_1);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(1, 97);
			this->button1->Margin = System::Windows::Forms::Padding(4);
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
			this->panel3->Controls->Add(this->clientinfo);
			this->panel3->Controls->Add(this->manage);
			this->panel3->Controls->Add(this->progress);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(200, 70);
			this->panel3->Margin = System::Windows::Forms::Padding(4);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(684, 591);
			this->panel3->TabIndex = 2;
			// 
			// clientinfo
			// 
			this->clientinfo->Controls->Add(this->dataGridView1);
			this->clientinfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->clientinfo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clientinfo->Location = System::Drawing::Point(0, 0);
			this->clientinfo->Margin = System::Windows::Forms::Padding(200);
			this->clientinfo->Name = L"clientinfo";
			this->clientinfo->Size = System::Drawing::Size(684, 591);
			this->clientinfo->TabIndex = 1;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::DisplayedHeaders;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::White;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->NAME, this->ID,
					this->Age, this->gender, this->activitylevel, this->workouts
			});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->GridColor = System::Drawing::Color::Black;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(200);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 45;
			this->dataGridView1->Size = System::Drawing::Size(684, 591);
			this->dataGridView1->TabIndex = 0;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &traiermenu::dataGridView1_CellContentClick);
			// 
			// NAME
			// 
			this->NAME->HeaderText = L"Name";
			this->NAME->MinimumWidth = 6;
			this->NAME->Name = L"NAME";
			this->NAME->ReadOnly = true;
			this->NAME->Width = 150;
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
			this->gender->Width = 110;
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
			// manage
			// 
			this->manage->BackColor = System::Drawing::Color::White;
			this->manage->Controls->Add(this->btn);
			this->manage->Controls->Add(this->newwork);
			this->manage->Controls->Add(this->assign);
			this->manage->Controls->Add(this->customwork);
			this->manage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->manage->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->manage->Location = System::Drawing::Point(0, 0);
			this->manage->Margin = System::Windows::Forms::Padding(4);
			this->manage->Name = L"manage";
			this->manage->Size = System::Drawing::Size(684, 591);
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
			this->btn->Size = System::Drawing::Size(684, 100);
			this->btn->TabIndex = 0;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(434, 10);
			this->button6->Margin = System::Windows::Forms::Padding(4);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(238, 65);
			this->button6->TabIndex = 2;
			this->button6->Text = L"Create Custom Workout for Client";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &traiermenu::button6_Click);
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(197, 10);
			this->button5->Margin = System::Windows::Forms::Padding(4);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(231, 65);
			this->button5->TabIndex = 1;
			this->button5->Text = L"Create New Predefined Workout";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &traiermenu::button5_Click);
			// 
			// button4
			// 
			this->button4->Font = (gcnew System::Drawing::Font(L"Tahoma", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(6, 10);
			this->button4->Margin = System::Windows::Forms::Padding(4);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(185, 65);
			this->button4->TabIndex = 0;
			this->button4->Text = L"Assign Predefined Workout";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &traiermenu::button4_Click);
			// 
			// newwork
			// 
			this->newwork->Controls->Add(this->excercise);
			this->newwork->Location = System::Drawing::Point(0, 97);
			this->newwork->Margin = System::Windows::Forms::Padding(4);
			this->newwork->Name = L"newwork";
			this->newwork->Size = System::Drawing::Size(684, 461);
			this->newwork->TabIndex = 3;
			this->newwork->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::newwork_Paint);
			// 
			// excercise
			// 
			this->excercise->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->excercise->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetPartial;
			this->excercise->ColumnCount = 2;
			this->excercise->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->excercise->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->excercise->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->excercise->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->excercise->Controls->Add(this->txtReps, 1, 5);
			this->excercise->Controls->Add(this->txtSets, 1, 4);
			this->excercise->Controls->Add(this->txtDuration, 1, 3);
			this->excercise->Controls->Add(this->textBox4, 1, 2);
			this->excercise->Controls->Add(this->txtWorkoutName, 1, 0);
			this->excercise->Controls->Add(this->label8, 0, 2);
			this->excercise->Controls->Add(this->label9, 0, 3);
			this->excercise->Controls->Add(this->label10, 0, 4);
			this->excercise->Controls->Add(this->label11, 0, 5);
			this->excercise->Controls->Add(this->button8, 0, 6);
			this->excercise->Controls->Add(this->label6, 0, 0);
			this->excercise->Controls->Add(this->label7, 0, 1);
			this->excercise->Controls->Add(this->panel10, 1, 1);
			this->excercise->Dock = System::Windows::Forms::DockStyle::Fill;
			this->excercise->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->excercise->Location = System::Drawing::Point(0, 0);
			this->excercise->Margin = System::Windows::Forms::Padding(4);
			this->excercise->Name = L"excercise";
			this->excercise->RowCount = 7;
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 45.90164F)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 54.09836F)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 73)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 66)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 81)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 98)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 79)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 45.90164F)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 54.09836F)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 48)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 44)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 54)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 65)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 52)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 45.90164F)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 54.09836F)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 59)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 54)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 66)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 80)));
			this->excercise->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 64)));
			this->excercise->Size = System::Drawing::Size(684, 461);
			this->excercise->TabIndex = 0;
			this->excercise->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::tableLayoutPanel1_Paint);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::SystemColors::Window;
			this->textBox4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox4->Location = System::Drawing::Point(347, 52);
			this->textBox4->Margin = System::Windows::Forms::Padding(4);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(330, 30);
			this->textBox4->TabIndex = 1;
			// 
			// numExercises
			// 
			this->numExercises->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numExercises->Location = System::Drawing::Point(0, 0);
			this->numExercises->Margin = System::Windows::Forms::Padding(4);
			this->numExercises->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numExercises->Name = L"numExercises";
			this->numExercises->Size = System::Drawing::Size(334, 30);
			this->numExercises->TabIndex = 0;
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(27, 24);
			this->label7->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(289, 21);
			this->label7->TabIndex = 2;
			this->label7->Text = L"Enter number of exercises     (max 10):";
			// 
			// label8
			// 
			this->label8->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(87, 73);
			this->label8->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(169, 23);
			this->label8->TabIndex = 4;
			this->label8->Text = L"Exercise Name : ";
			// 
			// label9
			// 
			this->label9->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(71, 145);
			this->label9->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(201, 23);
			this->label9->TabIndex = 6;
			this->label9->Text = L"Duration (minutes):";
			// 
			// label10
			// 
			this->label10->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(90, 222);
			this->label10->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(163, 23);
			this->label10->TabIndex = 7;
			this->label10->Text = L"Number of sets:";
			// 
			// label11
			// 
			this->label11->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(89, 314);
			this->label11->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(165, 23);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Number of reps:";
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->button8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->button8->Location = System::Drawing::Point(7, 382);
			this->button8->Margin = System::Windows::Forms::Padding(4);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(329, 72);
			this->button8->TabIndex = 12;
			this->button8->Text = L"Save";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &traiermenu::button8_Click);
			// 
			// label6
			// 
			this->label6->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(54, 3);
			this->label6->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(235, 18);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Enter workout name:";
			this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtReps
			// 
			this->txtReps->BackColor = System::Drawing::SystemColors::Window;
			this->txtReps->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtReps->Location = System::Drawing::Point(345, 279);
			this->txtReps->Margin = System::Windows::Forms::Padding(2);
			this->txtReps->Name = L"txtReps";
			this->txtReps->Size = System::Drawing::Size(334, 30);
			this->txtReps->TabIndex = 17;
			// 
			// txtSets
			// 
			this->txtSets->BackColor = System::Drawing::SystemColors::Window;
			this->txtSets->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtSets->Location = System::Drawing::Point(345, 195);
			this->txtSets->Margin = System::Windows::Forms::Padding(2);
			this->txtSets->Name = L"txtSets";
			this->txtSets->Size = System::Drawing::Size(334, 30);
			this->txtSets->TabIndex = 16;
			// 
			// txtDuration
			// 
			this->txtDuration->BackColor = System::Drawing::SystemColors::Window;
			this->txtDuration->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtDuration->Location = System::Drawing::Point(345, 126);
			this->txtDuration->Margin = System::Windows::Forms::Padding(2);
			this->txtDuration->Name = L"txtDuration";
			this->txtDuration->Size = System::Drawing::Size(334, 30);
			this->txtDuration->TabIndex = 15;
			// 
			// txtWorkoutName
			// 
			this->txtWorkoutName->BackColor = System::Drawing::SystemColors::Window;
			this->txtWorkoutName->Dock = System::Windows::Forms::DockStyle::Fill;
			this->txtWorkoutName->Location = System::Drawing::Point(345, 5);
			this->txtWorkoutName->Margin = System::Windows::Forms::Padding(2);
			this->txtWorkoutName->Name = L"txtWorkoutName";
			this->txtWorkoutName->Size = System::Drawing::Size(334, 30);
			this->txtWorkoutName->TabIndex = 1;
			this->txtWorkoutName->TextChanged += gcnew System::EventHandler(this, &traiermenu::textBox4_TextChanged);
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->generate);
			this->panel10->Controls->Add(this->numExercises);
			this->panel10->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel10->Location = System::Drawing::Point(345, 26);
			this->panel10->Margin = System::Windows::Forms::Padding(2);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(334, 17);
			this->panel10->TabIndex = 13;
			// 
			// generate
			// 
			this->generate->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->generate->Location = System::Drawing::Point(164, 13);
			this->generate->Margin = System::Windows::Forms::Padding(2);
			this->generate->Name = L"generate";
			this->generate->Size = System::Drawing::Size(80, 26);
			this->generate->TabIndex = 1;
			this->generate->Text = L"Next";
			this->generate->UseVisualStyleBackColor = true;
			this->generate->Click += gcnew System::EventHandler(this, &traiermenu::generate_Click);
			// 
			// assign
			// 
			this->assign->Controls->Add(this->checkedListBox1);
			this->assign->Controls->Add(this->button9);
			this->assign->Controls->Add(this->textBox2);
			this->assign->Controls->Add(this->label4);
			this->assign->Controls->Add(this->dataGridView3);
			this->assign->Dock = System::Windows::Forms::DockStyle::Fill;
			this->assign->Location = System::Drawing::Point(0, 0);
			this->assign->Margin = System::Windows::Forms::Padding(4);
			this->assign->Name = L"assign";
			this->assign->Size = System::Drawing::Size(684, 591);
			this->assign->TabIndex = 1;
			this->assign->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::assign_Paint);
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->button9->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button9->Location = System::Drawing::Point(10, 352);
			this->button9->Margin = System::Windows::Forms::Padding(4);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(113, 50);
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
			this->checkedListBox1->Items->AddRange(gcnew cli::array< System::Object^  >(6) {
				L"1. Morning Cardio (30 mins),Jumping Jack,High Knees,Sets: 3 | Reps: 15",
					L"2. Strength Training (45 mins),Push-Ups,Squats,Sets: 4 | Reps: 12", L"3. Full Body Workout (60 mins),Burpees,Lunges,Plank,Sets: 3 | Reps: 10",
					L"1. Morning Cardio (30 mins),Jumping Jack,High Knees,Sets: 3 | Reps: 15", L"2. Strength Training (45 mins),Push-Ups,Squats,Sets: 4 | Reps: 12",
					L"3. Full Body Workout (60 mins),Burpees,Lunges,Plank,Sets: 3 | Reps: 10"
			});
			this->checkedListBox1->Location = System::Drawing::Point(13, 254);
			this->checkedListBox1->Margin = System::Windows::Forms::Padding(4);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(640, 76);
			this->checkedListBox1->TabIndex = 3;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &traiermenu::button9_Click);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(172, 225);
			this->textBox2->Margin = System::Windows::Forms::Padding(4);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(126, 23);
			this->textBox2->TabIndex = 2;
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &traiermenu::textBox2_TextChanged_1);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Gainsboro;
			this->label4->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(13, 225);
			this->label4->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(144, 19);
			this->label4->TabIndex = 1;
			this->label4->Text = L"Enter Client Id : ";
			// 
			// dataGridView3
			// 
			this->dataGridView3->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView3->Location = System::Drawing::Point(12, 10);
			this->dataGridView3->Margin = System::Windows::Forms::Padding(4);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->Size = System::Drawing::Size(444, 238);
			this->dataGridView3->TabIndex = 0;
			// 
			// customwork
			// 
			this->customwork->Controls->Add(this->button10);
			this->customwork->Controls->Add(this->textBox3);
			this->customwork->Controls->Add(this->label5);
			this->customwork->Controls->Add(this->tableLayoutPanel3);
			this->customwork->Controls->Add(this->dataGridView4);
			this->customwork->Location = System::Drawing::Point(0, 97);
			this->customwork->Margin = System::Windows::Forms::Padding(4);
			this->customwork->Name = L"customwork";
			this->customwork->Size = System::Drawing::Size(684, 479);
			this->customwork->TabIndex = 2;
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->button10->Location = System::Drawing::Point(530, 163);
			this->button10->Margin = System::Windows::Forms::Padding(4);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(142, 51);
			this->button10->TabIndex = 5;
			this->button10->Text = L"Submit";
			this->button10->UseVisualStyleBackColor = false;
			this->button10->Click += gcnew System::EventHandler(this, &traiermenu::button10_Click);
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(530, 18);
			this->textBox3->Margin = System::Windows::Forms::Padding(4);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(123, 23);
			this->textBox3->TabIndex = 4;
			// 
			// label5
			// 
			this->label5->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(355, 18);
			this->label5->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(169, 23);
			this->label5->TabIndex = 0;
			this->label5->Text = L"Enter Client Id : ";
			// 
			// tableLayoutPanel3
			// 
			this->tableLayoutPanel3->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->tableLayoutPanel3->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetDouble;
			this->tableLayoutPanel3->ColumnCount = 2;
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel3->Controls->Add(this->textBox6, 1, 0);
			this->tableLayoutPanel3->Controls->Add(this->label12, 0, 0);
			this->tableLayoutPanel3->Controls->Add(this->label13, 0, 1);
			this->tableLayoutPanel3->Controls->Add(this->label14, 0, 2);
			this->tableLayoutPanel3->Controls->Add(this->label15, 0, 3);
			this->tableLayoutPanel3->Controls->Add(this->label16, 0, 4);
			this->tableLayoutPanel3->Controls->Add(this->label17, 0, 5);
			this->tableLayoutPanel3->Controls->Add(this->numericUpDown5, 1, 1);
			this->tableLayoutPanel3->Controls->Add(this->numericUpDown7, 1, 5);
			this->tableLayoutPanel3->Controls->Add(this->numericUpDown6, 1, 4);
			this->tableLayoutPanel3->Controls->Add(this->numericUpDown8, 1, 3);
			this->tableLayoutPanel3->Controls->Add(this->tableLayoutPanel4, 1, 2);
			this->tableLayoutPanel3->Location = System::Drawing::Point(3, 224);
			this->tableLayoutPanel3->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel3->Name = L"tableLayoutPanel3";
			this->tableLayoutPanel3->RowCount = 6;
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 46.34146F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 53.65854F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 68)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 46)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 53)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 25)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 59.18367F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 40.81633F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 46)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 27)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 23)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 28)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 16)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 46.34146F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 53.65854F)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 55)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 37)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 30)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 43)));
			this->tableLayoutPanel3->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 20)));
			this->tableLayoutPanel3->Size = System::Drawing::Size(681, 239);
			this->tableLayoutPanel3->TabIndex = 3;
			this->tableLayoutPanel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::tableLayoutPanel3_Paint);
			// 
			// textBox6
			// 
			this->textBox6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->textBox6->Location = System::Drawing::Point(346, 7);
			this->textBox6->Margin = System::Windows::Forms::Padding(4);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(328, 23);
			this->textBox6->TabIndex = 7;
			// 
			// label12
			// 
			this->label12->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->Location = System::Drawing::Point(65, 3);
			this->label12->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(212, 6);
			this->label12->TabIndex = 1;
			this->label12->Text = L"Enter workout name:";
			// 
			// label13
			// 
			this->label13->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->Location = System::Drawing::Point(38, 12);
			this->label13->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(266, 7);
			this->label13->TabIndex = 2;
			this->label13->Text = L"Enter number of exercises:";
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->Location = System::Drawing::Point(86, 44);
			this->label14->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(169, 23);
			this->label14->TabIndex = 3;
			this->label14->Text = L"Exercise Name : ";
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(70, 104);
			this->label15->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(201, 23);
			this->label15->TabIndex = 4;
			this->label15->Text = L"Duration (minutes):";
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->Location = System::Drawing::Point(142, 149);
			this->label16->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(58, 23);
			this->label16->TabIndex = 5;
			this->label16->Text = L"Sets:";
			// 
			// label17
			// 
			this->label17->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label17->AutoSize = true;
			this->label17->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label17->Location = System::Drawing::Point(139, 197);
			this->label17->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(64, 23);
			this->label17->TabIndex = 6;
			this->label17->Text = L"Reps:";
			// 
			// numericUpDown5
			// 
			this->numericUpDown5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown5->Location = System::Drawing::Point(346, 16);
			this->numericUpDown5->Margin = System::Windows::Forms::Padding(4);
			this->numericUpDown5->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 10, 0, 0, 0 });
			this->numericUpDown5->Name = L"numericUpDown5";
			this->numericUpDown5->Size = System::Drawing::Size(328, 23);
			this->numericUpDown5->TabIndex = 8;
			// 
			// numericUpDown7
			// 
			this->numericUpDown7->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown7->Location = System::Drawing::Point(346, 186);
			this->numericUpDown7->Margin = System::Windows::Forms::Padding(4);
			this->numericUpDown7->Name = L"numericUpDown7";
			this->numericUpDown7->Size = System::Drawing::Size(328, 23);
			this->numericUpDown7->TabIndex = 10;
			// 
			// numericUpDown6
			// 
			this->numericUpDown6->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown6->Location = System::Drawing::Point(346, 146);
			this->numericUpDown6->Margin = System::Windows::Forms::Padding(4);
			this->numericUpDown6->Name = L"numericUpDown6";
			this->numericUpDown6->Size = System::Drawing::Size(328, 23);
			this->numericUpDown6->TabIndex = 9;
			// 
			// numericUpDown8
			// 
			this->numericUpDown8->Dock = System::Windows::Forms::DockStyle::Fill;
			this->numericUpDown8->Location = System::Drawing::Point(346, 97);
			this->numericUpDown8->Margin = System::Windows::Forms::Padding(4);
			this->numericUpDown8->Name = L"numericUpDown8";
			this->numericUpDown8->Size = System::Drawing::Size(328, 23);
			this->numericUpDown8->TabIndex = 11;
			// 
			// tableLayoutPanel4
			// 
			this->tableLayoutPanel4->ColumnCount = 1;
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel4->Controls->Add(this->textBox8, 0, 1);
			this->tableLayoutPanel4->Controls->Add(this->textBox7, 0, 0);
			this->tableLayoutPanel4->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel4->Location = System::Drawing::Point(346, 26);
			this->tableLayoutPanel4->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel4->Name = L"tableLayoutPanel4";
			this->tableLayoutPanel4->RowCount = 2;
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel4->Size = System::Drawing::Size(328, 60);
			this->tableLayoutPanel4->TabIndex = 12;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(4, 34);
			this->textBox8->Margin = System::Windows::Forms::Padding(4);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(320, 23);
			this->textBox8->TabIndex = 1;
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(4, 4);
			this->textBox7->Margin = System::Windows::Forms::Padding(4);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(320, 23);
			this->textBox7->TabIndex = 0;
			// 
			// dataGridView4
			// 
			this->dataGridView4->BackgroundColor = System::Drawing::SystemColors::ButtonFace;
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn4,
					this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6
			});
			this->dataGridView4->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView4->Location = System::Drawing::Point(6, 19);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->RowHeadersWidth = 51;
			this->dataGridView4->Size = System::Drawing::Size(327, 203);
			this->dataGridView4->TabIndex = 0;
			this->dataGridView4->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &traiermenu::dataGridView4_CellContentClick);
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
			// progress
			// 
			this->progress->BackColor = System::Drawing::Color::White;
			this->progress->Controls->Add(this->panel9);
			this->progress->Controls->Add(this->textBox1);
			this->progress->Controls->Add(this->label2);
			this->progress->Controls->Add(this->panel8);
			this->progress->Controls->Add(this->panel7);
			this->progress->Location = System::Drawing::Point(0, 0);
			this->progress->Margin = System::Windows::Forms::Padding(4);
			this->progress->Name = L"progress";
			this->progress->Size = System::Drawing::Size(684, 561);
			this->progress->TabIndex = 4;
			// 
			// panel9
			// 
			this->panel9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->panel9->Controls->Add(this->tableLayoutPanel5);
			this->panel9->Location = System::Drawing::Point(4, 407);
			this->panel9->Margin = System::Windows::Forms::Padding(4);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(678, 219);
			this->panel9->TabIndex = 4;
			// 
			// tableLayoutPanel5
			// 
			this->tableLayoutPanel5->BackColor = System::Drawing::Color::WhiteSmoke;
			this->tableLayoutPanel5->CellBorderStyle = System::Windows::Forms::TableLayoutPanelCellBorderStyle::OutsetDouble;
			this->tableLayoutPanel5->ColumnCount = 2;
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				40.11799F)));
			this->tableLayoutPanel5->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				59.88201F)));
			this->tableLayoutPanel5->Controls->Add(this->label3, 0, 0);
			this->tableLayoutPanel5->Controls->Add(this->compelet, 1, 0);
			this->tableLayoutPanel5->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tableLayoutPanel5->Location = System::Drawing::Point(0, 0);
			this->tableLayoutPanel5->Margin = System::Windows::Forms::Padding(4);
			this->tableLayoutPanel5->Name = L"tableLayoutPanel5";
			this->tableLayoutPanel5->RowCount = 1;
			this->tableLayoutPanel5->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel5->Size = System::Drawing::Size(678, 219);
			this->tableLayoutPanel5->TabIndex = 0;
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Tahoma", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(36, 98);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(202, 23);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Completed Workout";
			// 
			// compelet
			// 
			this->compelet->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->compelet->AutoSize = true;
			this->compelet->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->compelet->Location = System::Drawing::Point(474, 100);
			this->compelet->Name = L"compelet";
			this->compelet->Size = System::Drawing::Size(0, 19);
			this->compelet->TabIndex = 1;
			this->compelet->Click += gcnew System::EventHandler(this, &traiermenu::label18_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(229, 370);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(207, 23);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(6, 302);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 18);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Enter Client Id :";
			// 
			// panel8
			// 
			this->panel8->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel8->Location = System::Drawing::Point(0, 551);
			this->panel8->Margin = System::Windows::Forms::Padding(4);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(684, 10);
			this->panel8->TabIndex = 1;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->viewcompletedworkout);
			this->panel7->Controls->Add(this->dataGridView2);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel7->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel7->Location = System::Drawing::Point(0, 0);
			this->panel7->Margin = System::Windows::Forms::Padding(4);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(684, 279);
			this->panel7->TabIndex = 0;
			// 
			// viewcompletedworkout
			// 
			this->viewcompletedworkout->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->viewcompletedworkout->Location = System::Drawing::Point(518, 219);
			this->viewcompletedworkout->Margin = System::Windows::Forms::Padding(2);
			this->viewcompletedworkout->Name = L"viewcompletedworkout";
			this->viewcompletedworkout->Size = System::Drawing::Size(135, 53);
			this->viewcompletedworkout->TabIndex = 5;
			this->viewcompletedworkout->Text = L"View";
			this->viewcompletedworkout->UseVisualStyleBackColor = true;
			this->viewcompletedworkout->Click += gcnew System::EventHandler(this, &traiermenu::viewcompletedworkout_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->BackgroundColor = System::Drawing::SystemColors::ButtonHighlight;
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
			this->dataGridView2->Size = System::Drawing::Size(684, 279);
			this->dataGridView2->TabIndex = 0;
			this->dataGridView2->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &traiermenu::dataGridView2_CellContentClick_1);
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
			this->dataGridViewTextBoxColumn2->Width = 125;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Workouts";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 125;
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
			this->Column2->Width = 150;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Workout";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			this->Column3->Width = 80;
			// 
			// traiermenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 661);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::SizableToolWindow;
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"traiermenu";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"traiermenu";
			this->Load += gcnew System::EventHandler(this, &traiermenu::traiermenu_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->panel5->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->clientinfo->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->manage->ResumeLayout(false);
			this->btn->ResumeLayout(false);
			this->newwork->ResumeLayout(false);
			this->excercise->ResumeLayout(false);
			this->excercise->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numExercises))->EndInit();
			this->panel10->ResumeLayout(false);
			this->assign->ResumeLayout(false);
			this->assign->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->customwork->ResumeLayout(false);
			this->customwork->PerformLayout();
			this->tableLayoutPanel3->ResumeLayout(false);
			this->tableLayoutPanel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown8))->EndInit();
			this->tableLayoutPanel4->ResumeLayout(false);
			this->tableLayoutPanel4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->progress->ResumeLayout(false);
			this->progress->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->tableLayoutPanel5->ResumeLayout(false);
			this->tableLayoutPanel5->PerformLayout();
			this->panel7->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
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
		assign->BringToFront();
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

	}
	private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
		if (textBox2->Text == "") {
			MessageBox::Show("You should enter client Id");
			return;
		}

		int clientID;
		try {
			clientID = Convert::ToInt32(textBox2->Text);
		}
		catch (...) {
			MessageBox::Show("You should enter number");
			return;
		}

		// «·»ÕÀ ⁄‰ «·⁄„Ì·
		Client* selectedClient = nullptr;
		for (int i = 0; i < trainer->numClients; i++) {
			if (trainer->clients[i].clientID == clientID) {
				selectedClient = &trainer->clients[i];
				break;
			}
		}
		if (selectedClient == nullptr) {
			MessageBox::Show("Client Not Found!");
			return;
		}

		if (checkedListBox1->CheckedItems->Count == 0) {
			MessageBox::Show("You must enter at least one workout ");
			return;
		}

		//  ⁄ÌÌ‰ «· „«—Ì‰ «·„Œ «—…
		for each (String ^ selectedWorkout in checkedListBox1->CheckedItems) {
			String^ workoutNameOnly = selectedWorkout->Split('(')[0]->Trim();
			for (int i = 0; i < numPredefinedWorkouts; i++) {
				if (gcnew String(predefineWorkout[i].workoutName.c_str()) == workoutNameOnly) {
					if (selectedClient->numWorkouts < MAX_WORKOUTS) {
						selectedClient->workoutPlans[selectedClient->numWorkouts] = predefineWorkout[i];
						selectedClient->workoutPlans[selectedClient->numWorkouts].istrue = "Pending";
						selectedClient->numWorkouts++;
						insertWorkout(db, predefineWorkout[i], selectedClient->clientID);
					}
				}
			}
		}
		MessageBox::Show("Workout assigned successfully!");



	}

	private: System::Void tableLayoutPanel3_Paint(System::Object^
		sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show("Custom workout assigned successfully!");
	}
	private: System::Void newwork_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void panel10_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label18_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void tableLayoutPanel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void viewcompletedworkout_Click(System::Object^ sender, System::EventArgs^ e) {
		compelet->Text = "";

		int clientID;
		if (!Int32::TryParse(textBox1->Text, clientID)) {
			MessageBox::Show("Please enter a valid client ID.");
			return;
		}

		// Find the client without using an additional pointer
		int clientIndex = -1;
		for (int i = 0; i < trainer->numClients; i++) {
			if (trainer->clients[i].clientID == clientID) {
				clientIndex = i;
				break;
			}
		}

		if (clientIndex == -1) {
			compelet->Text = "Client not found.";
			return;
		}

		// Use the client directly from the array
		Client& selectedClient = trainer->clients[clientIndex];

		String^ output = "------ Completed Workouts ------\n";
		if (selectedClient.numLogs == 0) {
			output += "No progress logs for this client.\n\n";
		}
		else {
			for (int i = 0; i < selectedClient.numLogs; i++) {
				output += (i + 1).ToString() + ". " + gcnew String(selectedClient.progressLogs[i].c_str()) + Environment::NewLine;
			}
		}

		output += "\n------ Measurements ------\n";
		if (selectedClient.numMeasurements == 0) {
			output += "No measurements added.\n";
		}
		else {
			for (int i = 0; i < selectedClient.numMeasurements; i++) {
				auto m = selectedClient.measurements[i];
				output += String::Format("{0}. Date: {1}/{2}/{3} | Weight: {4}kg | Height: {5}cm\n",
					i + 1, m.date.Day, m.date.Month, m.date.Year, m.weight, m.height);
			}
		}

		compelet->Text = output;
	}
	private: System::Void dataGridView2_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void dataGridView3_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}

	private: System::Void checkedListBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		LoadWorkoutsToCheckedListBox();

	}
	private: System::Void textBox2_TextChanged_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dataGridView4_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void checkedListBox1_SelectedIndexChanged_1(System::Object^ sender, System::EventArgs^ e) {
		LoadWorkoutsToCheckedListBox();
	}
	private: System::Void generate_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}