#pragma once
#include "core.h"
#include <msclr/marshal_cppstd.h>
#include "traiermenu.h"
#include "clientmenupage.h"
namespace SPProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for LoginForm
	/// </summary>
	public ref class LoginForm : public System::Windows::Forms::Form
	{
	public:
		LoginForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			for (int i = 0; i < trainerCount; ++i)
			{
				// Convert std::string to System::String^
				System::String^ trainerName = gcnew System::String(trainers[i].name.c_str());

				// Add to ComboBox
				cmbTrainer->Items->Add(trainerName);
			}
			originalImage = gcnew Bitmap(pictureBox1->Image);
			fadeAlpha = 0;
			pictureBox1->Image = gcnew Bitmap(originalImage->Width, originalImage->Height);
			fadeTimer->Start();


		}
	private:
		Bitmap^ originalImage = nullptr;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
		   int fadeAlpha = 0; // 0 = transparent, 255 = fully visible

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~LoginForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Panel^ panelSignup;



	private: System::Windows::Forms::Panel^ panelLogin;
	private: System::Windows::Forms::TextBox^ txtPassword1;
	private: System::Windows::Forms::TextBox^ txtUsername1;


	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnDoLogin;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::LinkLabel^ linkLabel1;
	private: System::Windows::Forms::Panel^ panelSignupClient;

	private: System::Windows::Forms::TextBox^ txtClientName;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtUsername;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::ComboBox^ cmbGender;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ComboBox^ cmbTrainer;
	private: System::Windows::Forms::ComboBox^ cmbActivityLevel;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Button^ btnRegisterClient;
	private: System::Windows::Forms::Panel^ panelSignUpTrainer;


	private: System::Windows::Forms::TextBox^ txtTrainerPassword;
	private: System::Windows::Forms::TextBox^ txtTrainerUsername;
	private: System::Windows::Forms::TextBox^ txtTrainerName;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Button^ btnClientSignUp;
	private: System::Windows::Forms::Button^ btnTrainerSignUp;
	private: System::Windows::Forms::Button^ btnBackToLogin;
	private: System::Windows::Forms::Button^ btnCreateTrainer;
	private: System::Windows::Forms::Timer^ fadeTimer;
	private: System::ComponentModel::IContainer^ components;









	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->panelSignup = (gcnew System::Windows::Forms::Panel());
			this->btnTrainerSignUp = (gcnew System::Windows::Forms::Button());
			this->btnClientSignUp = (gcnew System::Windows::Forms::Button());
			this->panelSignupClient = (gcnew System::Windows::Forms::Panel());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->btnRegisterClient = (gcnew System::Windows::Forms::Button());
			this->cmbTrainer = (gcnew System::Windows::Forms::ComboBox());
			this->cmbActivityLevel = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->cmbGender = (gcnew System::Windows::Forms::ComboBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtClientName = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->panelSignUpTrainer = (gcnew System::Windows::Forms::Panel());
			this->btnCreateTrainer = (gcnew System::Windows::Forms::Button());
			this->txtTrainerPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtTrainerUsername = (gcnew System::Windows::Forms::TextBox());
			this->txtTrainerName = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->panelLogin = (gcnew System::Windows::Forms::Panel());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->txtPassword1 = (gcnew System::Windows::Forms::TextBox());
			this->txtUsername1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnDoLogin = (gcnew System::Windows::Forms::Button());
			this->btnBackToLogin = (gcnew System::Windows::Forms::Button());
			this->fadeTimer = (gcnew System::Windows::Forms::Timer(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panelSignup->SuspendLayout();
			this->panelSignupClient->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->panelSignUpTrainer->SuspendLayout();
			this->panelLogin->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(226, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(432, 386);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &LoginForm::pictureBox1_Click);
			// 
			// panelSignup
			// 
			this->panelSignup->Controls->Add(this->btnTrainerSignUp);
			this->panelSignup->Controls->Add(this->btnClientSignUp);
			this->panelSignup->Controls->Add(this->panelSignupClient);
			this->panelSignup->Controls->Add(this->panelSignUpTrainer);
			this->panelSignup->Location = System::Drawing::Point(0, 314);
			this->panelSignup->Name = L"panelSignup";
			this->panelSignup->Size = System::Drawing::Size(889, 349);
			this->panelSignup->TabIndex = 1;
			// 
			// btnTrainerSignUp
			// 
			this->btnTrainerSignUp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btnTrainerSignUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTrainerSignUp->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTrainerSignUp->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->btnTrainerSignUp->Location = System::Drawing::Point(446, 9);
			this->btnTrainerSignUp->Name = L"btnTrainerSignUp";
			this->btnTrainerSignUp->Size = System::Drawing::Size(158, 35);
			this->btnTrainerSignUp->TabIndex = 3;
			this->btnTrainerSignUp->Text = L"Sign Up Trainer";
			this->btnTrainerSignUp->UseVisualStyleBackColor = false;
			this->btnTrainerSignUp->Click += gcnew System::EventHandler(this, &LoginForm::btnTrainerSignUp_Click);
			// 
			// btnClientSignUp
			// 
			this->btnClientSignUp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btnClientSignUp->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnClientSignUp->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnClientSignUp->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->btnClientSignUp->Location = System::Drawing::Point(259, 9);
			this->btnClientSignUp->Name = L"btnClientSignUp";
			this->btnClientSignUp->Size = System::Drawing::Size(149, 35);
			this->btnClientSignUp->TabIndex = 2;
			this->btnClientSignUp->Text = L"Sign Up Client";
			this->btnClientSignUp->UseVisualStyleBackColor = false;
			this->btnClientSignUp->Click += gcnew System::EventHandler(this, &LoginForm::btnClientSignUp_Click);
			// 
			// panelSignupClient
			// 
			this->panelSignupClient->Controls->Add(this->numericUpDown1);
			this->panelSignupClient->Controls->Add(this->btnRegisterClient);
			this->panelSignupClient->Controls->Add(this->cmbTrainer);
			this->panelSignupClient->Controls->Add(this->cmbActivityLevel);
			this->panelSignupClient->Controls->Add(this->label7);
			this->panelSignupClient->Controls->Add(this->label9);
			this->panelSignupClient->Controls->Add(this->label10);
			this->panelSignupClient->Controls->Add(this->txtUsername);
			this->panelSignupClient->Controls->Add(this->label8);
			this->panelSignupClient->Controls->Add(this->cmbGender);
			this->panelSignupClient->Controls->Add(this->txtPassword);
			this->panelSignupClient->Controls->Add(this->label5);
			this->panelSignupClient->Controls->Add(this->label6);
			this->panelSignupClient->Controls->Add(this->txtClientName);
			this->panelSignupClient->Controls->Add(this->label4);
			this->panelSignupClient->Location = System::Drawing::Point(0, 50);
			this->panelSignupClient->Name = L"panelSignupClient";
			this->panelSignupClient->Size = System::Drawing::Size(889, 296);
			this->panelSignupClient->TabIndex = 0;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numericUpDown1->Location = System::Drawing::Point(625, 43);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(190, 25);
			this->numericUpDown1->TabIndex = 29;
			// 
			// btnRegisterClient
			// 
			this->btnRegisterClient->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnRegisterClient->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btnRegisterClient->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnRegisterClient->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegisterClient->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->btnRegisterClient->Location = System::Drawing::Point(329, 222);
			this->btnRegisterClient->Name = L"btnRegisterClient";
			this->btnRegisterClient->Size = System::Drawing::Size(179, 38);
			this->btnRegisterClient->TabIndex = 28;
			this->btnRegisterClient->Text = L"REGISTER";
			this->btnRegisterClient->UseVisualStyleBackColor = false;
			this->btnRegisterClient->Click += gcnew System::EventHandler(this, &LoginForm::btnRegisterClient_Click);
			// 
			// cmbTrainer
			// 
			this->cmbTrainer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cmbTrainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->cmbTrainer->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTrainer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbTrainer->FormattingEnabled = true;
			this->cmbTrainer->Location = System::Drawing::Point(625, 153);
			this->cmbTrainer->Name = L"cmbTrainer";
			this->cmbTrainer->Size = System::Drawing::Size(190, 25);
			this->cmbTrainer->TabIndex = 27;
			// 
			// cmbActivityLevel
			// 
			this->cmbActivityLevel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cmbActivityLevel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->cmbActivityLevel->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbActivityLevel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbActivityLevel->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->cmbActivityLevel->FormattingEnabled = true;
			this->cmbActivityLevel->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Moderate", L"Light", L"Sedentary", L"Active",
					L"VeryActive"
			});
			this->cmbActivityLevel->Location = System::Drawing::Point(625, 99);
			this->cmbActivityLevel->Name = L"cmbActivityLevel";
			this->cmbActivityLevel->Size = System::Drawing::Size(190, 25);
			this->cmbActivityLevel->TabIndex = 26;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(456, 153);
			this->label7->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(148, 25);
			this->label7->TabIndex = 24;
			this->label7->Text = L"YOUR TRAINER";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(456, 99);
			this->label9->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(123, 25);
			this->label9->TabIndex = 23;
			this->label9->Text = L"\tActivity level";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::White;
			this->label10->Location = System::Drawing::Point(459, 42);
			this->label10->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(49, 25);
			this->label10->TabIndex = 22;
			this->label10->Text = L"AGE";
			// 
			// txtUsername
			// 
			this->txtUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsername->Location = System::Drawing::Point(147, 73);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(190, 25);
			this->txtUsername->TabIndex = 21;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(19, 69);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(101, 25);
			this->label8->TabIndex = 20;
			this->label8->Text = L"Username";
			// 
			// cmbGender
			// 
			this->cmbGender->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cmbGender->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->cmbGender->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbGender->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cmbGender->FormattingEnabled = true;
			this->cmbGender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
			this->cmbGender->Location = System::Drawing::Point(147, 174);
			this->cmbGender->Name = L"cmbGender";
			this->cmbGender->Size = System::Drawing::Size(190, 25);
			this->cmbGender->TabIndex = 19;
			// 
			// txtPassword
			// 
			this->txtPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->Location = System::Drawing::Point(147, 120);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(190, 25);
			this->txtPassword->TabIndex = 18;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(19, 173);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(87, 25);
			this->label5->TabIndex = 17;
			this->label5->Text = L"GENDER";
			this->label5->Click += gcnew System::EventHandler(this, &LoginForm::label5_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(19, 120);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(117, 25);
			this->label6->TabIndex = 16;
			this->label6->Text = L"PASSWORD";
			// 
			// txtClientName
			// 
			this->txtClientName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtClientName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtClientName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtClientName->Location = System::Drawing::Point(147, 20);
			this->txtClientName->Name = L"txtClientName";
			this->txtClientName->Size = System::Drawing::Size(190, 25);
			this->txtClientName->TabIndex = 9;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(19, 18);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(68, 25);
			this->label4->TabIndex = 8;
			this->label4->Text = L"NAME";
			// 
			// panelSignUpTrainer
			// 
			this->panelSignUpTrainer->Controls->Add(this->btnCreateTrainer);
			this->panelSignUpTrainer->Controls->Add(this->txtTrainerPassword);
			this->panelSignUpTrainer->Controls->Add(this->txtTrainerUsername);
			this->panelSignUpTrainer->Controls->Add(this->txtTrainerName);
			this->panelSignUpTrainer->Controls->Add(this->label11);
			this->panelSignUpTrainer->Controls->Add(this->label12);
			this->panelSignUpTrainer->Controls->Add(this->label13);
			this->panelSignUpTrainer->Location = System::Drawing::Point(0, 50);
			this->panelSignUpTrainer->Name = L"panelSignUpTrainer";
			this->panelSignUpTrainer->Size = System::Drawing::Size(889, 296);
			this->panelSignUpTrainer->TabIndex = 1;
			// 
			// btnCreateTrainer
			// 
			this->btnCreateTrainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btnCreateTrainer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnCreateTrainer->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnCreateTrainer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->btnCreateTrainer->Location = System::Drawing::Point(343, 162);
			this->btnCreateTrainer->Name = L"btnCreateTrainer";
			this->btnCreateTrainer->Size = System::Drawing::Size(166, 50);
			this->btnCreateTrainer->TabIndex = 18;
			this->btnCreateTrainer->Text = L"Register";
			this->btnCreateTrainer->UseVisualStyleBackColor = false;
			this->btnCreateTrainer->Click += gcnew System::EventHandler(this, &LoginForm::btnCreateTrainer_Click);
			// 
			// txtTrainerPassword
			// 
			this->txtTrainerPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtTrainerPassword->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTrainerPassword->Location = System::Drawing::Point(429, 123);
			this->txtTrainerPassword->Name = L"txtTrainerPassword";
			this->txtTrainerPassword->Size = System::Drawing::Size(238, 29);
			this->txtTrainerPassword->TabIndex = 17;
			// 
			// txtTrainerUsername
			// 
			this->txtTrainerUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtTrainerUsername->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTrainerUsername->Location = System::Drawing::Point(429, 79);
			this->txtTrainerUsername->Name = L"txtTrainerUsername";
			this->txtTrainerUsername->Size = System::Drawing::Size(238, 29);
			this->txtTrainerUsername->TabIndex = 16;
			// 
			// txtTrainerName
			// 
			this->txtTrainerName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtTrainerName->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTrainerName->Location = System::Drawing::Point(429, 36);
			this->txtTrainerName->Name = L"txtTrainerName";
			this->txtTrainerName->Size = System::Drawing::Size(238, 29);
			this->txtTrainerName->TabIndex = 15;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label11->Location = System::Drawing::Point(220, 117);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(147, 32);
			this->label11->TabIndex = 14;
			this->label11->Text = L"PASSWORD";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label12->Location = System::Drawing::Point(220, 76);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(145, 32);
			this->label12->TabIndex = 13;
			this->label12->Text = L"USERNAME";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label13->Location = System::Drawing::Point(220, 35);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(81, 32);
			this->label13->TabIndex = 12;
			this->label13->Text = L"Name";
			// 
			// panelLogin
			// 
			this->panelLogin->Controls->Add(this->linkLabel1);
			this->panelLogin->Controls->Add(this->label1);
			this->panelLogin->Controls->Add(this->txtPassword1);
			this->panelLogin->Controls->Add(this->txtUsername1);
			this->panelLogin->Controls->Add(this->label2);
			this->panelLogin->Controls->Add(this->label3);
			this->panelLogin->Controls->Add(this->btnDoLogin);
			this->panelLogin->Location = System::Drawing::Point(0, 314);
			this->panelLogin->Name = L"panelLogin";
			this->panelLogin->Size = System::Drawing::Size(886, 346);
			this->panelLogin->TabIndex = 13;
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->linkLabel1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->linkLabel1->LinkColor = System::Drawing::Color::WhiteSmoke;
			this->linkLabel1->Location = System::Drawing::Point(487, 208);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(56, 20);
			this->linkLabel1->TabIndex = 14;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Sign in";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &LoginForm::linkLabel1_LinkClicked);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(317, 208);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(170, 20);
			this->label1->TabIndex = 13;
			this->label1->Text = L"Don\'t have an account\?";
			// 
			// txtPassword1
			// 
			this->txtPassword1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtPassword1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtPassword1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->txtPassword1->Location = System::Drawing::Point(431, 88);
			this->txtPassword1->Margin = System::Windows::Forms::Padding(1);
			this->txtPassword1->MaxLength = 20;
			this->txtPassword1->Name = L"txtPassword1";
			this->txtPassword1->PasswordChar = '*';
			this->txtPassword1->Size = System::Drawing::Size(173, 29);
			this->txtPassword1->TabIndex = 12;
			this->txtPassword1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->txtPassword1->UseSystemPasswordChar = true;
			// 
			// txtUsername1
			// 
			this->txtUsername1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtUsername1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtUsername1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsername1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->txtUsername1->Location = System::Drawing::Point(431, 52);
			this->txtUsername1->MaxLength = 20;
			this->txtUsername1->Name = L"txtUsername1";
			this->txtUsername1->Size = System::Drawing::Size(173, 29);
			this->txtUsername1->TabIndex = 11;
			this->txtUsername1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label2->Location = System::Drawing::Point(253, 87);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(127, 31);
			this->label2->TabIndex = 9;
			this->label2->Text = L"Password";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label3->Location = System::Drawing::Point(253, 47);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 31);
			this->label3->TabIndex = 8;
			this->label3->Text = L"Username";
			// 
			// btnDoLogin
			// 
			this->btnDoLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnDoLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btnDoLogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnDoLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnDoLogin->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDoLogin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->btnDoLogin->Location = System::Drawing::Point(321, 147);
			this->btnDoLogin->Name = L"btnDoLogin";
			this->btnDoLogin->Size = System::Drawing::Size(233, 52);
			this->btnDoLogin->TabIndex = 7;
			this->btnDoLogin->Text = L"Login";
			this->btnDoLogin->UseVisualStyleBackColor = false;
			this->btnDoLogin->Click += gcnew System::EventHandler(this, &LoginForm::button1_Click);
			// 
			// btnBackToLogin
			// 
			this->btnBackToLogin->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->btnBackToLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnBackToLogin->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnBackToLogin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->btnBackToLogin->Location = System::Drawing::Point(20, 20);
			this->btnBackToLogin->Name = L"btnBackToLogin";
			this->btnBackToLogin->Size = System::Drawing::Size(150, 35);
			this->btnBackToLogin->TabIndex = 14;
			this->btnBackToLogin->Text = L"← Back to Login";
			this->btnBackToLogin->UseVisualStyleBackColor = false;
			this->btnBackToLogin->Visible = false;
			this->btnBackToLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnBackToLogin_Click);
			// 
			// fadeTimer
			// 
			this->fadeTimer->Interval = 30;
			this->fadeTimer->Tick += gcnew System::EventHandler(this, &LoginForm::fadeTimer_Tick);
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->ClientSize = System::Drawing::Size(884, 661);
			this->Controls->Add(this->btnBackToLogin);
			this->Controls->Add(this->panelLogin);
			this->Controls->Add(this->panelSignup);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"LoginForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LoginForm";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panelSignup->ResumeLayout(false);
			this->panelSignupClient->ResumeLayout(false);
			this->panelSignupClient->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->panelSignUpTrainer->ResumeLayout(false);
			this->panelSignUpTrainer->PerformLayout();
			this->panelLogin->ResumeLayout(false);
			this->panelLogin->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	//private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
	//	String^ user = txtUsername->Text;
	//	String^ pass = txtPassword->Text;

	//	std::string stdUser = msclr::interop::marshal_as<std::string>(user);
	//	std::string stdPass = msclr::interop::marshal_as<std::string>(pass);

	//	if (stdUser.empty() || stdPass.empty()) {
	//		MessageBox::Show("Please fill all fields.");
	//		return;
	//	}

	//	Client* c = clientLogin(stdUser, stdPass);
	//	if (c != nullptr)
	//	{
	//		lblStatus->Text = "Client login successful!";
	//		this->Hide();
	//		clientmenupage^ cf = gcnew clientmenupage(c);
	//		cf->ShowDialog();
	//		this->Show();
	//		return;
	//	}

	//	Trainer* t = trainerLogin(stdUser, stdPass);
	//	if (t != nullptr)
	//	{
	//		lblStatus->Text = "Trainer login successful!";
	//		this->Hide();
	//		traiermenu^ tf = gcnew traiermenu(t);
	//		tf->ShowDialog();
	//		this->Show();
	//		return;
	//	}

	//	lblStatus->Text = "Invalid username or password.";
	//}
	private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user = txtUsername1->Text;
		String^ pass = txtPassword1->Text;

		std::string stdUser = msclr::interop::marshal_as<std::string>(user);
		std::string stdPass = msclr::interop::marshal_as<std::string>(pass);

		if (stdUser.empty() || stdPass.empty()) {
			MessageBox::Show("Please fill all fields.");
			return;
		}

		Client* c = clientLogin(stdUser, stdPass);
		if (c != nullptr)
		{	
			this->Hide();
			clientmenupage^ cf = gcnew clientmenupage(c);
			cf->ShowDialog();
			this->Show();
			return;
		}

		Trainer* t = trainerLogin(stdUser, stdPass);
		if (t != nullptr)
		{
			this->Hide();
			traiermenu^ tf = gcnew traiermenu(t);
			tf->ShowDialog();
			this->Show();
			return;
		}

		MessageBox::Show("Invalid Username or Password.");
	}

private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
	panelSignup->BringToFront();
	btnBackToLogin->Visible = true;
}
private: System::Void label5_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnRegisterClient_Click(System::Object^ sender, System::EventArgs^ e) {
	// Get and trim all input values
	System::String^ name = txtClientName->Text->Trim();
	System::String^ username = txtUsername->Text->Trim();
	System::String^ password = txtPassword->Text->Trim();
	System::String^ gender = cmbGender->Text->Trim();
	System::String^ activityLevel = cmbActivityLevel->Text->Trim();
	System::String^ trainerName = cmbTrainer->Text->Trim();

	// Validate required fields
	if (String::IsNullOrEmpty(name) ||
		String::IsNullOrEmpty(username) ||
		String::IsNullOrEmpty(password) ||
		String::IsNullOrEmpty(gender) ||
		String::IsNullOrEmpty(activityLevel) ||
		String::IsNullOrEmpty(trainerName)) {
		MessageBox::Show("Please fill all fields.", "Validation Error",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	// Validate age
	int age= (int)numericUpDown1->Value;
	if ( age <= 0 || age > 120) {
		MessageBox::Show("Please enter a valid age between 1 and 120.", "Invalid Age",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	// Convert to std::string
	std::string nameStd = msclr::interop::marshal_as<std::string>(name);
	std::string usernameStd = msclr::interop::marshal_as<std::string>(username);
	std::string passwordStd = msclr::interop::marshal_as<std::string>(password);
	std::string genderStd = msclr::interop::marshal_as<std::string>(gender);
	std::string activityStd = msclr::interop::marshal_as<std::string>(activityLevel);
	std::string trainerNameStd = msclr::interop::marshal_as<std::string>(trainerName);

	// Check if username exists
	if (isUsernameTaken(usernameStd)) {
		MessageBox::Show("This username is already taken. Please choose another.",
			"Username Taken", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		// Clear form
		txtUsername->Text = "";	
		return;
	}

	// Find selected trainer
	Trainer* selectedTrainer = nullptr;
	for (int i = 0; i < trainerCount; i++) {
		if (trainerNameStd == trainers[i].name) {
			selectedTrainer = &trainers[i];
			break;
		}
	}

	// Check trainer capacity
	if (selectedTrainer->numClients >= MAX_CLIENTS) {
		MessageBox::Show("Selected trainer is at full capacity.", "Capacity Reached",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		// Clear form
		txtClientName->Text = "";
		txtUsername->Text = "";
		txtPassword->Text = "";
		numericUpDown1->Value = 0;
		cmbGender->SelectedIndex = -1;
		cmbActivityLevel->SelectedIndex = -1;
		cmbTrainer->SelectedIndex = -1;
		return;
	}

	// Create new client
	else {
		Client newClient;
		newClient.name = nameStd;
		newClient.username = usernameStd;
		newClient.password = passwordStd;
		newClient.gender = genderStd;
		newClient.activityLevel = activityStd;
		newClient.age = age;
		newClient.trainerId = selectedTrainer->trainerID;
		newClient.clientID = clientCount + 1;

		// Add to database
		insertClient(db, newClient);


		// Update in-memory data if DB operation succeeded
		selectedTrainer->clients[selectedTrainer->numClients] = newClient;
		selectedTrainer->numClients++;
		clientCount++;

		// Clear form
		txtClientName->Text = "";
		txtUsername->Text = "";
		txtPassword->Text = "";
		numericUpDown1->Value = 0;
		cmbGender->SelectedIndex = -1;
		cmbActivityLevel->SelectedIndex = -1;
		cmbTrainer->SelectedIndex = -1;

		MessageBox::Show("Client registered successfully!", "Success",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
}

private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show("Button clicked");
	if (txtTrainerName == nullptr) {
		MessageBox::Show("txtTrainerName is NULL");
		return;
	}
	if (txtTrainerUsername == nullptr) {
		MessageBox::Show("txtTrainerUsername is NULL");
		return;
	}
	if (txtTrainerPassword == nullptr) {
		MessageBox::Show("txtTrainerPassword is NULL");
		return;
	}
	if (db == nullptr) {
			MessageBox::Show("Database not initialized.");
			return;
	}
	try {
		System::String^ name = txtTrainerName->Text;
		System::String^ username = txtTrainerUsername->Text;
		System::String^ password = txtTrainerPassword->Text;



		std::string nameStd = msclr::interop::marshal_as<std::string>(name);
		std::string usernameStd = msclr::interop::marshal_as<std::string>(username);
		std::string passwordStd = msclr::interop::marshal_as<std::string>(password);

		if (nameStd.empty() || usernameStd.empty() || passwordStd.empty()) {
			MessageBox::Show("Please fill all fields.");
			return;
		}

		if (trainerCount >= MAX_TRAINERS) {
			MessageBox::Show("Maximum number of trainers reached.");

		}

		if (isUsernameTaken(usernameStd)) {
			MessageBox::Show("Username is already taken. Please choose another.");
		}

		else {

			Trainer *newTrainer=new Trainer();
			newTrainer->name = nameStd;
			newTrainer->username = usernameStd;
			newTrainer->password = passwordStd;
			newTrainer->trainerID = trainerCount + 1;

			trainers[trainerCount] = *newTrainer;
			try {
				insertTrainer(db, *newTrainer);
			}
			catch (const std::exception& ex) {
				MessageBox::Show("DB Error: " + gcnew String(ex.what()));
				delete newTrainer;
				return;
			}

			trainerCount++;

			MessageBox::Show("Trainer account created!");
			delete newTrainer;
		}

		txtTrainerName->Text = "";
		txtTrainerUsername->Text = "";
		txtTrainerPassword->Text = "";
		txtTrainerName->Focus();
	}
	catch (const std::exception& ex) {
		MessageBox::Show("Exception: " + gcnew String(ex.what()));
	}
	catch (...) {
		MessageBox::Show("Unknown crash occurred.");
	}
}

private: System::Void btnBackToLogin_Click(System::Object^ sender, System::EventArgs^ e) {
	panelLogin->BringToFront();

	// Optional: reset sign-up toggle
	panelSignupClient->Visible = true;
	panelSignUpTrainer->Visible = false;

	// Optional: reset sign-up tab button colors if you want
	btnClientSignUp->BackColor = Color::FromArgb(52, 152, 219);
	btnTrainerSignUp->BackColor = Color::FromArgb(41, 128, 185);

	btnBackToLogin->Visible = false;
}

private: System::Void btnClientSignUp_Click(System::Object^ sender, System::EventArgs^ e) {
	panelSignupClient->Visible = true;
	panelSignUpTrainer->Visible = false;

	btnClientSignUp->BackColor = Color::FromArgb(52, 152, 219);
	btnTrainerSignUp->BackColor = Color::FromArgb(41, 128, 185);
}

private: System::Void btnTrainerSignUp_Click(System::Object^ sender, System::EventArgs^ e) {
	panelSignupClient->Visible = false;
	panelSignUpTrainer->Visible = true;

	btnTrainerSignUp->BackColor = Color::FromArgb(52, 152, 219);
	btnClientSignUp->BackColor = Color::FromArgb(41, 128, 185);
}

private: System::Void btnCreateTrainer_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ name = txtTrainerName->Text;
	System::String^ username = txtTrainerUsername->Text;
	System::String^ password = txtTrainerPassword->Text;
	std::string nameStd = msclr::interop::marshal_as<std::string>(name);
	std::string usernameStd = msclr::interop::marshal_as<std::string>(username);
	std::string passwordStd = msclr::interop::marshal_as<std::string>(password);

	if (nameStd.empty() || usernameStd.empty() || passwordStd.empty()) {
		MessageBox::Show("Please fill all fields.");
		return;
	}

	if (trainerCount >= MAX_TRAINERS) {
		MessageBox::Show("Maximum number of trainers reached.");

	}

	if (isUsernameTaken(usernameStd)) {
		MessageBox::Show("Username is already taken. Please choose another.");
	}
	else {
		Trainer* newTrainer = new Trainer();
		newTrainer->name = nameStd;
		newTrainer->username = usernameStd;
		newTrainer->password = passwordStd;
		newTrainer->trainerID = trainerCount + 1;

		trainers[trainerCount] = *newTrainer;

		try {
			insertTrainer(db, *newTrainer);
		}
		catch (const std::exception& ex) {
			MessageBox::Show("DB Error: " + gcnew String(ex.what()));
			return;
		}

		trainerCount++;

		MessageBox::Show("Trainer account created!");
	}

}

private: System::Void fadeTimer_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (fadeAlpha < 255) {
		fadeAlpha += 5; // adjust speed of fade
		if (fadeAlpha > 255) fadeAlpha = 255;

		// Create a blank bitmap to draw the faded image into
		Bitmap^ faded = gcnew Bitmap(originalImage->Width, originalImage->Height);
		Graphics^ g = Graphics::FromImage(faded);

		// Set transparency using ColorMatrix
		System::Drawing::Imaging::ColorMatrix^ matrix = gcnew System::Drawing::Imaging::ColorMatrix();
		matrix->Matrix33 = fadeAlpha / 255.0f;

		System::Drawing::Imaging::ImageAttributes^ attr = gcnew System::Drawing::Imaging::ImageAttributes();
		attr->SetColorMatrix(matrix, System::Drawing::Imaging::ColorMatrixFlag::Default, System::Drawing::Imaging::ColorAdjustType::Bitmap);

		g->DrawImage(originalImage,
			System::Drawing::Rectangle(0, 0, originalImage->Width, originalImage->Height),
			0, 0, originalImage->Width, originalImage->Height,
			GraphicsUnit::Pixel,
			attr);

		pictureBox1->Image = faded;

		delete g;
		delete attr;
	}
	else {
		fadeTimer->Stop();
	}
}


private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
