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
	/// Summary for traiermenu
	/// </summary>
	public ref class traiermenu : public System::Windows::Forms::Form
	{
	public:
		Trainer *trainer;
	//public:
	//	// Â‰« ‰÷⁄ «·œ«·… «·„⁄œ·…
	//	void ViewMeasurements(Trainer* trainer, DataGridView^ dataGridView) {
	//		dataGridView->Rows->Clear();

	//		if (trainer->numMeasurements == 0) {
	//			MessageBox::Show("No measurements recorded yet.", "Information",
	//				MessageBoxButtons::OK, MessageBoxIcon::Information);
	//			return;
	//		}

	//		// ≈÷«›… «·√⁄„œ… ≈–« ·„  ﬂ‰ „ÊÃÊœ…
	//		if (dataGridView->Columns->Count == 0) {
	//			dataGridView->Columns->Add("colNumber", "#");
	//			dataGridView->Columns->Add("colDate", "Date");
	//			dataGridView->Columns->Add("colWeight", "Weight (kg)");
	//			dataGridView->Columns->Add("colHeight", "Height (cm)");
	//		}

	//		//  ⁄»∆… «·»Ì«‰« 
	//		for (int i = 0; i < trainer->numMeasurements; i++) {
	//			String^ dateStr = String::Format("{0}/{1}/{2}",
	//				trainer->measurements[i].date.Day,
	//				trainer->measurements[i].date.Month,
	//				trainer->measurements[i].date.Year);

	//			dataGridView->Rows->Add(
	//				(i + 1).ToString(),
	//				dateStr,
	//				trainer->measurements[i].weight.ToString(),
	//				trainer->measurements[i].height.ToString()
	//			);
	//		}
	//	}
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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ NAME;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ ID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Age;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ gender;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ activitylevel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ workouts;
	private: System::Windows::Forms::Panel^ manage;
	private: System::Windows::Forms::Panel^ progress;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ workout;
	private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::FlowLayoutPanel^ flowLayoutPanel1;



























































	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(traiermenu::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
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
			this->flowLayoutPanel1 = (gcnew System::Windows::Forms::FlowLayoutPanel());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->workout = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->progress = (gcnew System::Windows::Forms::Panel());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->label3 = (gcnew System::Windows::Forms::Label());
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
			this->panel2->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->panel5->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			this->manage->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->progress->SuspendLayout();
			this->panel9->SuspendLayout();
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
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1326, 154);
			this->panel1->TabIndex = 0;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::panel1_Paint);
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(446, 43);
			this->label1->Margin = System::Windows::Forms::Padding(300, 308, 300, 308);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(413, 64);
			this->label1->TabIndex = 0;
			this->label1->Text = L"TRAINER MENU";
			this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 154);
			this->panel2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(300, 863);
			this->panel2->TabIndex = 1;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->pictureBox3);
			this->panel6->Controls->Add(this->button3);
			this->panel6->Location = System::Drawing::Point(0, 582);
			this->panel6->Margin = System::Windows::Forms::Padding(15, 15, 15, 15);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(300, 263);
			this->panel6->TabIndex = 2;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(63, 63);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(150, 77);
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
			this->button3->Location = System::Drawing::Point(4, 168);
			this->button3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(280, 82);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Client Progress";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &traiermenu::button3_Click);
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->pictureBox2);
			this->panel5->Controls->Add(this->button2);
			this->panel5->Location = System::Drawing::Point(0, 322);
			this->panel5->Margin = System::Windows::Forms::Padding(15, 15, 15, 15);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(300, 222);
			this->panel5->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(63, 31);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(150, 77);
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
			this->button2->Location = System::Drawing::Point(4, 117);
			this->button2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(286, 82);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Manage Workouts";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &traiermenu::button2_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pictureBox1);
			this->panel4->Controls->Add(this->button1);
			this->panel4->Location = System::Drawing::Point(4, 15);
			this->panel4->Margin = System::Windows::Forms::Padding(15, 15, 15, 15);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(286, 262);
			this->panel4->TabIndex = 0;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::panel4_Paint);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(58, 55);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(150, 77);
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
			this->button1->Location = System::Drawing::Point(-4, 191);
			this->button1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(285, 66);
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
			this->panel3->Location = System::Drawing::Point(300, 154);
			this->panel3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(1026, 863);
			this->panel3->TabIndex = 2;
			// 
			// manage
			// 
			this->manage->BackColor = System::Drawing::Color::White;
			this->manage->Controls->Add(this->flowLayoutPanel1);
			this->manage->Controls->Add(this->button4);
			this->manage->Controls->Add(this->dataGridView3);
			this->manage->Controls->Add(this->comboBox1);
			this->manage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->manage->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->manage->Location = System::Drawing::Point(0, 0);
			this->manage->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->manage->Name = L"manage";
			this->manage->Size = System::Drawing::Size(1026, 863);
			this->manage->TabIndex = 5;
			// 
			// flowLayoutPanel1
			// 
			this->flowLayoutPanel1->Location = System::Drawing::Point(592, 168);
			this->flowLayoutPanel1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->flowLayoutPanel1->Name = L"flowLayoutPanel1";
			this->flowLayoutPanel1->Size = System::Drawing::Size(352, 257);
			this->flowLayoutPanel1->TabIndex = 3;
			this->flowLayoutPanel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::flowLayoutPanel1_Paint);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(682, 5);
			this->button4->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(214, 35);
			this->button4->TabIndex = 2;
			this->button4->Text = L"Next";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &traiermenu::button4_Click);
			// 
			// dataGridView3
			// 
			this->dataGridView3->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn4,
					this->dataGridViewTextBoxColumn5, this->workout
			});
			this->dataGridView3->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView3->Location = System::Drawing::Point(20, 146);
			this->dataGridView3->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 62;
			this->dataGridView3->Size = System::Drawing::Size(519, 397);
			this->dataGridView3->TabIndex = 1;
			this->dataGridView3->Visible = false;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"Id";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			this->dataGridViewTextBoxColumn4->Width = 150;
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Name";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			this->dataGridViewTextBoxColumn5->Width = 150;
			// 
			// workout
			// 
			this->workout->HeaderText = L"Workout";
			this->workout->MinimumWidth = 8;
			this->workout->Name = L"workout";
			this->workout->Width = 150;
			// 
			// comboBox1
			// 
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				L"1-Assign Predefined Workout ", L"2-Creat New Predefined Workout ",
					L"3-Create Custom Workout For Client "
			});
			this->comboBox1->Location = System::Drawing::Point(0, 0);
			this->comboBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(556, 32);
			this->comboBox1->TabIndex = 0;
			this->comboBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &traiermenu::comboBox1_SelectedIndexChanged);
			// 
			// progress
			// 
			this->progress->BackColor = System::Drawing::Color::White;
			this->progress->Controls->Add(this->panel9);
			this->progress->Controls->Add(this->textBox1);
			this->progress->Controls->Add(this->label2);
			this->progress->Controls->Add(this->panel8);
			this->progress->Controls->Add(this->panel7);
			this->progress->Dock = System::Windows::Forms::DockStyle::Fill;
			this->progress->Location = System::Drawing::Point(0, 0);
			this->progress->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->progress->Name = L"progress";
			this->progress->Size = System::Drawing::Size(1026, 863);
			this->progress->TabIndex = 4;
			// 
			// panel9
			// 
			this->panel9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->panel9->Controls->Add(this->label3);
			this->panel9->Location = System::Drawing::Point(4, 526);
			this->panel9->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(1017, 318);
			this->panel9->TabIndex = 4;
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Verdana", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(340, 20);
			this->label3->Margin = System::Windows::Forms::Padding(300, 308, 300, 308);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(338, 35);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Completed Workout";
			this->label3->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(258, 463);
			this->textBox1->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(308, 31);
			this->textBox1->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Verdana", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(9, 465);
			this->label2->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(216, 28);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Enter Client Id :";
			// 
			// panel8
			// 
			this->panel8->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel8->Location = System::Drawing::Point(0, 848);
			this->panel8->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(1026, 15);
			this->panel8->TabIndex = 1;
			// 
			// panel7
			// 
			this->panel7->Controls->Add(this->dataGridView2);
			this->panel7->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel7->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panel7->Location = System::Drawing::Point(0, 0);
			this->panel7->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(1026, 429);
			this->panel7->TabIndex = 0;
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
			this->dataGridView2->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 62;
			this->dataGridView2->Size = System::Drawing::Size(1026, 429);
			this->dataGridView2->TabIndex = 0;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Id";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 150;
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Name";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			this->dataGridViewTextBoxColumn2->Width = 150;
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Workouts";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 8;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			this->dataGridViewTextBoxColumn3->Width = 150;
			// 
			// clientinfo
			// 
			this->clientinfo->Controls->Add(this->dataGridView1);
			this->clientinfo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->clientinfo->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clientinfo->Location = System::Drawing::Point(0, 0);
			this->clientinfo->Margin = System::Windows::Forms::Padding(300, 308, 300, 308);
			this->clientinfo->Name = L"clientinfo";
			this->clientinfo->Size = System::Drawing::Size(1026, 863);
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
			this->dataGridView1->Margin = System::Windows::Forms::Padding(300, 308, 300, 308);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersWidth = 45;
			this->dataGridView1->Size = System::Drawing::Size(1026, 863);
			this->dataGridView1->TabIndex = 0;
			// 
			// NAME
			// 
			this->NAME->HeaderText = L"Name";
			this->NAME->MinimumWidth = 8;
			this->NAME->Name = L"NAME";
			this->NAME->ReadOnly = true;
			this->NAME->Width = 120;
			// 
			// ID
			// 
			this->ID->HeaderText = L"Id";
			this->ID->MinimumWidth = 8;
			this->ID->Name = L"ID";
			this->ID->ReadOnly = true;
			this->ID->Width = 70;
			// 
			// Age
			// 
			this->Age->HeaderText = L"Age";
			this->Age->MinimumWidth = 8;
			this->Age->Name = L"Age";
			this->Age->ReadOnly = true;
			this->Age->Width = 70;
			// 
			// gender
			// 
			this->gender->HeaderText = L"Gender";
			this->gender->MinimumWidth = 8;
			this->gender->Name = L"gender";
			this->gender->ReadOnly = true;
			this->gender->Width = 150;
			// 
			// activitylevel
			// 
			this->activitylevel->HeaderText = L"Activity Level";
			this->activitylevel->MinimumWidth = 8;
			this->activitylevel->Name = L"activitylevel";
			this->activitylevel->ReadOnly = true;
			this->activitylevel->Width = 170;
			// 
			// workouts
			// 
			this->workouts->HeaderText = L"Workouts";
			this->workouts->MinimumWidth = 8;
			this->workouts->Name = L"workouts";
			this->workouts->ReadOnly = true;
			this->workouts->Width = 80;
			// 
			// traiermenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1326, 1017);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(4, 5, 4, 5);
			this->Name = L"traiermenu";
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
			this->manage->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			this->progress->ResumeLayout(false);
			this->progress->PerformLayout();
			this->panel9->ResumeLayout(false);
			this->panel9->PerformLayout();
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
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	manage->BringToFront();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	progress->BringToFront();
}
private: System::Void progress_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void dataGridView2_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
	String^ selected = comboBox1->SelectedItem->ToString();
	if (selected == "1-Assign Predefined Workout ")
	{

	}
}
private: System::Void comboBox1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void flowLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
