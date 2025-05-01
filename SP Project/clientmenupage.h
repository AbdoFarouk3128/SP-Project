//#pragma once
////
////namespace SPProject {
//
//	using namespace System;
//	using namespace System::ComponentModel;
//	using namespace System::Collections;
//	using namespace System::Windows::Forms;
//	using namespace System::Data;
//	using namespace System::Drawing;
//
//	/// <summary>
//	/// Summary for clientmenupage
//	/// </summary>
//	public ref class clientmenupage : public System::Windows::Forms::Form
//	{
//	public:
//		clientmenupage(void)
//		{
//			InitializeComponent();
//			//
//			//TODO: Add the constructor code here
//			//
//		}
//
//	protected:
//		/// <summary>
//		/// Clean up any resources being used.
//		/// </summary>
//		~clientmenupage()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//	private: System::Windows::Forms::Panel^ panel1;
//	protected:
//	private: System::Windows::Forms::Panel^ panel2;
//	private: System::Windows::Forms::Panel^ panel13;
//	private: System::Windows::Forms::Panel^ panel4;
//
//
//
//
//
//	private: System::Windows::Forms::Panel^ panel10;
//	private: System::Windows::Forms::Panel^ panel11;
//	private: System::Windows::Forms::Panel^ panel12;
//	private: System::Windows::Forms::Panel^ mainpage;
//	private: System::Windows::Forms::Panel^ panel3;
//	private: System::Windows::Forms::Button^ button1;
//	private: System::Windows::Forms::PictureBox^ pictureBox3;
//	private: System::Windows::Forms::PictureBox^ pictureBox2;
//	private: System::Windows::Forms::PictureBox^ pictureBox4;
//	private: System::Windows::Forms::PictureBox^ pictureBox5;
//	private: System::Windows::Forms::PictureBox^ pictureBox1;
//	private: System::Windows::Forms::Label^ label1;
//	private: System::Windows::Forms::Button^ button3;
//	private: System::Windows::Forms::Button^ button4;
//	private: System::Windows::Forms::Button^ button5;
//	private: System::Windows::Forms::Button^ button6;
//	private: System::Windows::Forms::Button^ button2;
//	private: System::Windows::Forms::Panel^ VIEWworkout;
//	private: System::Windows::Forms::Panel^ LOGworkout;
//	private: System::Windows::Forms::Panel^ LOGmeasurment;
//	private: System::Windows::Forms::Panel^ HEALTHsummry;
//	private: System::Windows::Forms::Panel^ VIEWmeasurment;
//	private: System::Windows::Forms::Panel^ LOGO;
//	private: System::Windows::Forms::PictureBox^ pictureBox6;
//
//
//
//
//
//
//	protected:
//
//	private:
//		/// <summary>
//		/// Required designer variable.
//		/// </summary>
//		System::ComponentModel::Container ^components;
//
//#pragma region Windows Form Designer generated code
//		/// <summary>
//		/// Required method for Designer support - do not modify
//		/// the contents of this method with the code editor.
//		/// </summary>
//		void InitializeComponent(void)
//		{
//			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(clientmenupage::typeid));
//			this->panel1 = (gcnew System::Windows::Forms::Panel());
//			this->label1 = (gcnew System::Windows::Forms::Label());
//			this->panel2 = (gcnew System::Windows::Forms::Panel());
//			this->panel10 = (gcnew System::Windows::Forms::Panel());
//			this->button3 = (gcnew System::Windows::Forms::Button());
//			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
//			this->panel11 = (gcnew System::Windows::Forms::Panel());
//			this->button4 = (gcnew System::Windows::Forms::Button());
//			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
//			this->panel12 = (gcnew System::Windows::Forms::Panel());
//			this->button5 = (gcnew System::Windows::Forms::Button());
//			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
//			this->panel13 = (gcnew System::Windows::Forms::Panel());
//			this->button6 = (gcnew System::Windows::Forms::Button());
//			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
//			this->panel4 = (gcnew System::Windows::Forms::Panel());
//			this->button2 = (gcnew System::Windows::Forms::Button());
//			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
//			this->mainpage = (gcnew System::Windows::Forms::Panel());
//			this->LOGO = (gcnew System::Windows::Forms::Panel());
//			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
//			this->VIEWworkout = (gcnew System::Windows::Forms::Panel());
//			this->LOGworkout = (gcnew System::Windows::Forms::Panel());
//			this->LOGmeasurment = (gcnew System::Windows::Forms::Panel());
//			this->HEALTHsummry = (gcnew System::Windows::Forms::Panel());
//			this->VIEWmeasurment = (gcnew System::Windows::Forms::Panel());
//			this->panel3 = (gcnew System::Windows::Forms::Panel());
//			this->button1 = (gcnew System::Windows::Forms::Button());
//			this->panel1->SuspendLayout();
//			this->panel2->SuspendLayout();
//			this->panel10->SuspendLayout();
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
//			this->panel11->SuspendLayout();
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
//			this->panel12->SuspendLayout();
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
//			this->panel13->SuspendLayout();
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
//			this->panel4->SuspendLayout();
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
//			this->mainpage->SuspendLayout();
//			this->LOGO->SuspendLayout();
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
//			this->panel3->SuspendLayout();
//			this->SuspendLayout();
//			// 
//			// panel1
//			// 
//			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
//				static_cast<System::Int32>(static_cast<System::Byte>(94)));
//			this->panel1->Controls->Add(this->label1);
//			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
//			this->panel1->Location = System::Drawing::Point(0, 0);
//			this->panel1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->panel1->Name = L"panel1";
//			this->panel1->Size = System::Drawing::Size(992, 125);
//			this->panel1->TabIndex = 0;
//			// 
//			// label1
//			// 
//			this->label1->AutoSize = true;
//			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
//			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->label1->ForeColor = System::Drawing::Color::White;
//			this->label1->Location = System::Drawing::Point(343, 29);
//			this->label1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->label1->Name = L"label1";
//			this->label1->Size = System::Drawing::Size(321, 66);
//			this->label1->TabIndex = 0;
//			this->label1->Text = L"Client Menu";
//			// 
//			// panel2
//			// 
//			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
//				static_cast<System::Int32>(static_cast<System::Byte>(94)));
//			this->panel2->Controls->Add(this->panel10);
//			this->panel2->Controls->Add(this->panel11);
//			this->panel2->Controls->Add(this->panel12);
//			this->panel2->Controls->Add(this->panel13);
//			this->panel2->Controls->Add(this->panel4);
//			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
//			this->panel2->Location = System::Drawing::Point(0, 125);
//			this->panel2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->panel2->Name = L"panel2";
//			this->panel2->Size = System::Drawing::Size(378, 691);
//			this->panel2->TabIndex = 1;
//			// 
//			// panel10
//			// 
//			this->panel10->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
//			this->panel10->Controls->Add(this->button3);
//			this->panel10->Controls->Add(this->pictureBox3);
//			this->panel10->Location = System::Drawing::Point(3, 149);
//			this->panel10->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->panel10->Name = L"panel10";
//			this->panel10->Size = System::Drawing::Size(367, 129);
//			this->panel10->TabIndex = 1;
//			// 
//			// button3
//			// 
//			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->button3->Location = System::Drawing::Point(142, 4);
//			this->button3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->button3->Name = L"button3";
//			this->button3->Size = System::Drawing::Size(210, 118);
//			this->button3->TabIndex = 2;
//			this->button3->Text = L"Log Completed Workout";
//			this->button3->UseVisualStyleBackColor = true;
//			this->button3->Click += gcnew System::EventHandler(this, &clientmenupage::button3_Click);
//			// 
//			// pictureBox3
//			// 
//			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
//			this->pictureBox3->Location = System::Drawing::Point(3, 4);
//			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->pictureBox3->Name = L"pictureBox3";
//			this->pictureBox3->Size = System::Drawing::Size(112, 122);
//			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
//			this->pictureBox3->TabIndex = 2;
//			this->pictureBox3->TabStop = false;
//			// 
//			// panel11
//			// 
//			this->panel11->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
//			this->panel11->Controls->Add(this->button4);
//			this->panel11->Controls->Add(this->pictureBox2);
//			this->panel11->Location = System::Drawing::Point(3, 284);
//			this->panel11->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->panel11->Name = L"panel11";
//			this->panel11->Size = System::Drawing::Size(367, 125);
//			this->panel11->TabIndex = 1;
//			this->panel11->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &clientmenupage::panel11_Paint);
//			// 
//			// button4
//			// 
//			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->button4->Location = System::Drawing::Point(142, 4);
//			this->button4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->button4->Name = L"button4";
//			this->button4->Size = System::Drawing::Size(210, 119);
//			this->button4->TabIndex = 3;
//			this->button4->Text = L"Log Measurments";
//			this->button4->UseVisualStyleBackColor = true;
//			this->button4->Click += gcnew System::EventHandler(this, &clientmenupage::button4_Click);
//			// 
//			// pictureBox2
//			// 
//			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
//			this->pictureBox2->Location = System::Drawing::Point(3, 0);
//			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->pictureBox2->Name = L"pictureBox2";
//			this->pictureBox2->Size = System::Drawing::Size(112, 122);
//			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
//			this->pictureBox2->TabIndex = 1;
//			this->pictureBox2->TabStop = false;
//			// 
//			// panel12
//			// 
//			this->panel12->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
//			this->panel12->Controls->Add(this->button5);
//			this->panel12->Controls->Add(this->pictureBox4);
//			this->panel12->Location = System::Drawing::Point(3, 418);
//			this->panel12->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->panel12->Name = L"panel12";
//			this->panel12->Size = System::Drawing::Size(367, 136);
//			this->panel12->TabIndex = 1;
//			// 
//			// button5
//			// 
//			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->button5->Location = System::Drawing::Point(142, 4);
//			this->button5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->button5->Name = L"button5";
//			this->button5->Size = System::Drawing::Size(210, 130);
//			this->button5->TabIndex = 4;
//			this->button5->Text = L"Health Summary";
//			this->button5->UseVisualStyleBackColor = true;
//			this->button5->Click += gcnew System::EventHandler(this, &clientmenupage::button5_Click);
//			// 
//			// pictureBox4
//			// 
//			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
//			this->pictureBox4->Location = System::Drawing::Point(3, 4);
//			this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->pictureBox4->Name = L"pictureBox4";
//			this->pictureBox4->Size = System::Drawing::Size(112, 130);
//			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
//			this->pictureBox4->TabIndex = 2;
//			this->pictureBox4->TabStop = false;
//			// 
//			// panel13
//			// 
//			this->panel13->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
//			this->panel13->Controls->Add(this->button6);
//			this->panel13->Controls->Add(this->pictureBox5);
//			this->panel13->Location = System::Drawing::Point(3, 562);
//			this->panel13->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->panel13->Name = L"panel13";
//			this->panel13->Size = System::Drawing::Size(367, 124);
//			this->panel13->TabIndex = 1;
//			// 
//			// button6
//			// 
//			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->button6->Location = System::Drawing::Point(142, 6);
//			this->button6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->button6->Name = L"button6";
//			this->button6->Size = System::Drawing::Size(210, 115);
//			this->button6->TabIndex = 5;
//			this->button6->Text = L"View Measurments";
//			this->button6->UseVisualStyleBackColor = true;
//			this->button6->Click += gcnew System::EventHandler(this, &clientmenupage::button6_Click);
//			// 
//			// pictureBox5
//			// 
//			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
//			this->pictureBox5->Location = System::Drawing::Point(3, 6);
//			this->pictureBox5->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->pictureBox5->Name = L"pictureBox5";
//			this->pictureBox5->Size = System::Drawing::Size(112, 122);
//			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
//			this->pictureBox5->TabIndex = 2;
//			this->pictureBox5->TabStop = false;
//			// 
//			// panel4
//			// 
//			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
//			this->panel4->Controls->Add(this->button2);
//			this->panel4->Controls->Add(this->pictureBox1);
//			this->panel4->Location = System::Drawing::Point(3, 5);
//			this->panel4->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->panel4->Name = L"panel4";
//			this->panel4->Size = System::Drawing::Size(367, 135);
//			this->panel4->TabIndex = 0;
//			// 
//			// button2
//			// 
//			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->button2->Location = System::Drawing::Point(142, 4);
//			this->button2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->button2->Name = L"button2";
//			this->button2->Size = System::Drawing::Size(210, 129);
//			this->button2->TabIndex = 1;
//			this->button2->Text = L"View Workouts";
//			this->button2->UseVisualStyleBackColor = true;
//			this->button2->Click += gcnew System::EventHandler(this, &clientmenupage::button2_Click);
//			// 
//			// pictureBox1
//			// 
//			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
//			this->pictureBox1->Location = System::Drawing::Point(3, 4);
//			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->pictureBox1->Name = L"pictureBox1";
//			this->pictureBox1->Size = System::Drawing::Size(112, 129);
//			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
//			this->pictureBox1->TabIndex = 0;
//			this->pictureBox1->TabStop = false;
//			// 
//			// mainpage
//			// 
//			this->mainpage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
//				static_cast<System::Int32>(static_cast<System::Byte>(241)));
//			this->mainpage->Controls->Add(this->LOGO);
//			this->mainpage->Controls->Add(this->VIEWworkout);
//			this->mainpage->Controls->Add(this->LOGworkout);
//			this->mainpage->Controls->Add(this->LOGmeasurment);
//			this->mainpage->Controls->Add(this->HEALTHsummry);
//			this->mainpage->Controls->Add(this->VIEWmeasurment);
//			this->mainpage->Dock = System::Windows::Forms::DockStyle::Fill;
//			this->mainpage->Location = System::Drawing::Point(378, 125);
//			this->mainpage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->mainpage->Name = L"mainpage";
//			this->mainpage->Size = System::Drawing::Size(614, 691);
//			this->mainpage->TabIndex = 2;
//			// 
//			// LOGO
//			// 
//			this->LOGO->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
//				static_cast<System::Int32>(static_cast<System::Byte>(94)));
//			this->LOGO->Controls->Add(this->pictureBox6);
//			this->LOGO->Dock = System::Windows::Forms::DockStyle::Fill;
//			this->LOGO->Location = System::Drawing::Point(0, 0);
//			this->LOGO->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->LOGO->Name = L"LOGO";
//			this->LOGO->Size = System::Drawing::Size(614, 691);
//			this->LOGO->TabIndex = 8;
//			// 
//			// pictureBox6
//			// 
//			this->pictureBox6->Dock = System::Windows::Forms::DockStyle::Fill;
//			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
//			this->pictureBox6->Location = System::Drawing::Point(0, 0);
//			this->pictureBox6->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->pictureBox6->Name = L"pictureBox6";
//			this->pictureBox6->Size = System::Drawing::Size(614, 691);
//			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
//			this->pictureBox6->TabIndex = 0;
//			this->pictureBox6->TabStop = false;
//			this->pictureBox6->Click += gcnew System::EventHandler(this, &clientmenupage::pictureBox6_Click);
//			// 
//			// VIEWworkout
//			// 
//			this->VIEWworkout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(128)),
//				static_cast<System::Int32>(static_cast<System::Byte>(0)));
//			this->VIEWworkout->Location = System::Drawing::Point(0, 0);
//			this->VIEWworkout->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->VIEWworkout->Name = L"VIEWworkout";
//			this->VIEWworkout->Size = System::Drawing::Size(614, 691);
//			this->VIEWworkout->TabIndex = 7;
//			// 
//			// LOGworkout
//			// 
//			this->LOGworkout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
//				static_cast<System::Int32>(static_cast<System::Byte>(255)));
//			this->LOGworkout->Dock = System::Windows::Forms::DockStyle::Fill;
//			this->LOGworkout->Location = System::Drawing::Point(0, 0);
//			this->LOGworkout->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->LOGworkout->Name = L"LOGworkout";
//			this->LOGworkout->Size = System::Drawing::Size(614, 691);
//			this->LOGworkout->TabIndex = 6;
//			// 
//			// LOGmeasurment
//			// 
//			this->LOGmeasurment->BackColor = System::Drawing::Color::Olive;
//			this->LOGmeasurment->Dock = System::Windows::Forms::DockStyle::Fill;
//			this->LOGmeasurment->Location = System::Drawing::Point(0, 0);
//			this->LOGmeasurment->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->LOGmeasurment->Name = L"LOGmeasurment";
//			this->LOGmeasurment->Size = System::Drawing::Size(614, 691);
//			this->LOGmeasurment->TabIndex = 5;
//			// 
//			// HEALTHsummry
//			// 
//			this->HEALTHsummry->BackColor = System::Drawing::Color::Maroon;
//			this->HEALTHsummry->Dock = System::Windows::Forms::DockStyle::Fill;
//			this->HEALTHsummry->Location = System::Drawing::Point(0, 0);
//			this->HEALTHsummry->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->HEALTHsummry->Name = L"HEALTHsummry";
//			this->HEALTHsummry->Size = System::Drawing::Size(614, 691);
//			this->HEALTHsummry->TabIndex = 4;
//			// 
//			// VIEWmeasurment
//			// 
//			this->VIEWmeasurment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
//				static_cast<System::Int32>(static_cast<System::Byte>(192)));
//			this->VIEWmeasurment->Dock = System::Windows::Forms::DockStyle::Fill;
//			this->VIEWmeasurment->Location = System::Drawing::Point(0, 0);
//			this->VIEWmeasurment->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->VIEWmeasurment->Name = L"VIEWmeasurment";
//			this->VIEWmeasurment->Size = System::Drawing::Size(614, 691);
//			this->VIEWmeasurment->TabIndex = 3;
//			// 
//			// panel3
//			// 
//			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
//				static_cast<System::Int32>(static_cast<System::Byte>(94)));
//			this->panel3->Controls->Add(this->button1);
//			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
//			this->panel3->Location = System::Drawing::Point(378, 691);
//			this->panel3->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->panel3->Name = L"panel3";
//			this->panel3->Size = System::Drawing::Size(614, 125);
//			this->panel3->TabIndex = 3;
//			// 
//			// button1
//			// 
//			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
//			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
//				static_cast<System::Int32>(static_cast<System::Byte>(94)));
//			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->button1->ForeColor = System::Drawing::Color::White;
//			this->button1->Location = System::Drawing::Point(449, 30);
//			this->button1->Margin = System::Windows::Forms::Padding(0);
//			this->button1->Name = L"button1";
//			this->button1->Size = System::Drawing::Size(135, 75);
//			this->button1->TabIndex = 0;
//			this->button1->Text = L"Logout";
//			this->button1->UseVisualStyleBackColor = false;
//			this->button1->Click += gcnew System::EventHandler(this, &clientmenupage::button1_Click);
//			// 
//			// clientmenupage
//			// 
//			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->ClientSize = System::Drawing::Size(992, 816);
//			this->Controls->Add(this->panel3);
//			this->Controls->Add(this->mainpage);
//			this->Controls->Add(this->panel2);
//			this->Controls->Add(this->panel1);
//			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
//			this->Name = L"clientmenupage";
//			this->Text = L"clientmenupage";
//			this->panel1->ResumeLayout(false);
//			this->panel1->PerformLayout();
//			this->panel2->ResumeLayout(false);
//			this->panel10->ResumeLayout(false);
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
//			this->panel11->ResumeLayout(false);
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
//			this->panel12->ResumeLayout(false);
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
//			this->panel13->ResumeLayout(false);
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
//			this->panel4->ResumeLayout(false);
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
//			this->mainpage->ResumeLayout(false);
//			this->LOGO->ResumeLayout(false);
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
//			this->panel3->ResumeLayout(false);
//			this->ResumeLayout(false);
//
//		}
//#pragma endregion
//	private: System::Void panel11_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
//	}
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
//private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
//	VIEWmeasurment->BringToFront();
//}
//private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
//	Application::Exit();
//}
//private: System::Void pictureBox6_Click(System::Object^ sender, System::EventArgs^ e) {
//}
//};
//}
