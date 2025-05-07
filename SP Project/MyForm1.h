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
	/// Summary for MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::TextBox^ txtTrainerName;

	private: System::Windows::Forms::TextBox^ txtTrainerUsername;

	private: System::Windows::Forms::TextBox^ txtTrainerPassword;

	private: System::Windows::Forms::Button^ button1;



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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm1::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->txtTrainerName = (gcnew System::Windows::Forms::TextBox());
			this->txtTrainerUsername = (gcnew System::Windows::Forms::TextBox());
			this->txtTrainerPassword = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(315, 33);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(545, 414);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label4->Location = System::Drawing::Point(233, 576);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(193, 34);
			this->label4->TabIndex = 7;
			this->label4->Text = L"PASSWORD";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label5->Location = System::Drawing::Point(233, 526);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(190, 34);
			this->label5->TabIndex = 6;
			this->label5->Text = L"USERNAME";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label6->Location = System::Drawing::Point(233, 476);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(101, 34);
			this->label6->TabIndex = 5;
			this->label6->Text = L"Name";
			// 
			// txtTrainerName
			// 
			this->txtTrainerName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtTrainerName->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTrainerName->Location = System::Drawing::Point(523, 473);
			this->txtTrainerName->Margin = System::Windows::Forms::Padding(4);
			this->txtTrainerName->Name = L"txtTrainerName";
			this->txtTrainerName->Size = System::Drawing::Size(316, 32);
			this->txtTrainerName->TabIndex = 8;
			// 
			// txtTrainerUsername
			// 
			this->txtTrainerUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtTrainerUsername->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTrainerUsername->Location = System::Drawing::Point(523, 526);
			this->txtTrainerUsername->Margin = System::Windows::Forms::Padding(4);
			this->txtTrainerUsername->Name = L"txtTrainerUsername";
			this->txtTrainerUsername->Size = System::Drawing::Size(316, 32);
			this->txtTrainerUsername->TabIndex = 9;
			// 
			// txtTrainerPassword
			// 
			this->txtTrainerPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtTrainerPassword->Font = (gcnew System::Drawing::Font(L"Tahoma", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtTrainerPassword->Location = System::Drawing::Point(523, 580);
			this->txtTrainerPassword->Margin = System::Windows::Forms::Padding(4);
			this->txtTrainerPassword->Name = L"txtTrainerPassword";
			this->txtTrainerPassword->Size = System::Drawing::Size(316, 32);
			this->txtTrainerPassword->TabIndex = 10;
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->button1->Location = System::Drawing::Point(387, 633);
			this->button1->Margin = System::Windows::Forms::Padding(4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(332, 55);
			this->button1->TabIndex = 11;
			this->button1->Text = L"REGISTER";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm1::button1_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->ClientSize = System::Drawing::Size(1179, 814);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->txtTrainerPassword);
			this->Controls->Add(this->txtTrainerUsername);
			this->Controls->Add(this->txtTrainerName);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->pictureBox1);
			this->Margin = System::Windows::Forms::Padding(4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MyForm1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MyForm1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
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

			Trainer newTrainer;
			newTrainer.name = nameStd;
			newTrainer.username = usernameStd;
			newTrainer.password = passwordStd;
			newTrainer.trainerID = trainerCount + 1;

			trainers[trainerCount] = newTrainer;
			try {
				insertTrainer(db, newTrainer);
			}
			catch (const std::exception& ex) {
				MessageBox::Show("DB Error: " + gcnew String(ex.what()));
				return;
			}

			trainerCount++;

			MessageBox::Show("Trainer account created!");
		}

		txtTrainerName->Text = "";
		txtTrainerUsername->Text = "";
		txtTrainerPassword->Text = "";
		txtTrainerName->Focus();
	}
};
}
