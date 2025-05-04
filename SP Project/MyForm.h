#pragma once
#include "core.h"
using namespace msclr::interop;
namespace SPProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
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
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::TextBox^ txtClientName;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::TextBox^ txtAge;
	private: System::Windows::Forms::ComboBox^ cmbGender;
	private: System::Windows::Forms::ComboBox^ cmbActivityLevel;





	private: System::Windows::Forms::ComboBox^ cmbTrainer;
	private: System::Windows::Forms::Button^ btnRegisterClient;


	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::TextBox^ txtUsername;









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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->txtClientName = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->txtAge = (gcnew System::Windows::Forms::TextBox());
			this->cmbGender = (gcnew System::Windows::Forms::ComboBox());
			this->cmbActivityLevel = (gcnew System::Windows::Forms::ComboBox());
			this->cmbTrainer = (gcnew System::Windows::Forms::ComboBox());
			this->btnRegisterClient = (gcnew System::Windows::Forms::Button());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label1->Location = System::Drawing::Point(128, 114);
			this->label1->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(67, 22);
			this->label1->TabIndex = 0;
			this->label1->Text = L"NAME";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label2->Location = System::Drawing::Point(128, 234);
			this->label2->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(124, 22);
			this->label2->TabIndex = 1;
			this->label2->Text = L"PASSWORD";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label3->Location = System::Drawing::Point(128, 295);
			this->label3->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(93, 22);
			this->label3->TabIndex = 2;
			this->label3->Text = L"GENDER";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label4->Location = System::Drawing::Point(128, 366);
			this->label4->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(52, 22);
			this->label4->TabIndex = 3;
			this->label4->Text = L"AGE";
			this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label5->Location = System::Drawing::Point(129, 442);
			this->label5->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(126, 22);
			this->label5->TabIndex = 4;
			this->label5->Text = L"\tActivity level";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label6->Location = System::Drawing::Point(128, 512);
			this->label6->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(157, 22);
			this->label6->TabIndex = 5;
			this->label6->Text = L"YOUR TRAINER";
			// 
			// label7
			// 
			this->label7->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 24, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label7->Location = System::Drawing::Point(281, 40);
			this->label7->Margin = System::Windows::Forms::Padding(5, 0, 5, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(294, 37);
			this->label7->TabIndex = 6;
			this->label7->Text = L"FITNESS CENTER";
			this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// txtClientName
			// 
			this->txtClientName->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtClientName->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtClientName->Location = System::Drawing::Point(392, 114);
			this->txtClientName->Name = L"txtClientName";
			this->txtClientName->Size = System::Drawing::Size(484, 26);
			this->txtClientName->TabIndex = 7;
			this->txtClientName->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			// 
			// txtPassword
			// 
			this->txtPassword->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtPassword->Location = System::Drawing::Point(392, 231);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(484, 26);
			this->txtPassword->TabIndex = 8;
			// 
			// txtAge
			// 
			this->txtAge->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->txtAge->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtAge->Location = System::Drawing::Point(392, 366);
			this->txtAge->Name = L"txtAge";
			this->txtAge->Size = System::Drawing::Size(484, 26);
			this->txtAge->TabIndex = 9;
			// 
			// cmbGender
			// 
			this->cmbGender->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cmbGender->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->cmbGender->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbGender->FormattingEnabled = true;
			this->cmbGender->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
			this->cmbGender->Location = System::Drawing::Point(392, 295);
			this->cmbGender->Name = L"cmbGender";
			this->cmbGender->Size = System::Drawing::Size(484, 26);
			this->cmbGender->TabIndex = 10;
			// 
			// cmbActivityLevel
			// 
			this->cmbActivityLevel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cmbActivityLevel->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->cmbActivityLevel->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbActivityLevel->FormattingEnabled = true;
			this->cmbActivityLevel->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Moderate", L"Light", L"Sedentary", L"Active",
					L"VeryActive"
			});
			this->cmbActivityLevel->Location = System::Drawing::Point(392, 438);
			this->cmbActivityLevel->Name = L"cmbActivityLevel";
			this->cmbActivityLevel->Size = System::Drawing::Size(484, 26);
			this->cmbActivityLevel->TabIndex = 11;
			// 
			// cmbTrainer
			// 
			this->cmbTrainer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cmbTrainer->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->cmbTrainer->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->cmbTrainer->FormattingEnabled = true;
			this->cmbTrainer->Location = System::Drawing::Point(392, 512);
			this->cmbTrainer->Name = L"cmbTrainer";
			this->cmbTrainer->Size = System::Drawing::Size(484, 26);
			this->cmbTrainer->TabIndex = 12;
			// 
			// btnRegisterClient
			// 
			this->btnRegisterClient->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnRegisterClient->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 22, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegisterClient->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)),
				static_cast<System::Int32>(static_cast<System::Byte>(73)), static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->btnRegisterClient->Location = System::Drawing::Point(302, 581);
			this->btnRegisterClient->Name = L"btnRegisterClient";
			this->btnRegisterClient->Size = System::Drawing::Size(273, 72);
			this->btnRegisterClient->TabIndex = 13;
			this->btnRegisterClient->Text = L"REGISTER";
			this->btnRegisterClient->UseVisualStyleBackColor = true;
			this->btnRegisterClient->Click += gcnew System::EventHandler(this, &MyForm::REGISTER_Click);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Italic));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->label8->Location = System::Drawing::Point(129, 172);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(103, 22);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Username";
			// 
			// txtUsername
			// 
			this->txtUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->txtUsername->Location = System::Drawing::Point(392, 169);
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(484, 26);
			this->txtUsername->TabIndex = 15;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(10, 18);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->ClientSize = System::Drawing::Size(956, 748);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->btnRegisterClient);
			this->Controls->Add(this->cmbTrainer);
			this->Controls->Add(this->cmbActivityLevel);
			this->Controls->Add(this->cmbGender);
			this->Controls->Add(this->txtAge);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtClientName);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Margin = System::Windows::Forms::Padding(5, 4, 5, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void REGISTER_Click(System::Object^ sender, System::EventArgs^ e) {
	System::String^ name = txtClientName->Text;
	System::String^ username = txtUsername->Text;
	System::String^ password = txtPassword->Text;
	System::String^ gender = cmbGender->Text;
	System::String^ activityLevel = cmbActivityLevel->Text;
	System::String^ ageText = txtAge->Text;
	System::String^ trainerName = cmbTrainer->Text;

	std::string nameStd = msclr::interop::marshal_as<std::string>(name);
	std::string usernameStd = msclr::interop::marshal_as<std::string>(username);
	std::string passwordStd = msclr::interop::marshal_as<std::string>(password);
	std::string genderStd = msclr::interop::marshal_as<std::string>(gender);
	std::string activityStd = msclr::interop::marshal_as<std::string>(activityLevel);
	std::string trainerNameStd = msclr::interop::marshal_as<std::string>(trainerName);

	if (nameStd.empty() || usernameStd.empty() || passwordStd.empty() || ageText->Length == 0) {
		MessageBox::Show("Please fill all fields.");
		return;
	}

	int age;
	if (!Int32::TryParse(ageText, age) || age <= 0) {
		MessageBox::Show("Please enter a valid positive age.");
		return;
	}
	if (isUsernameTaken(usernameStd)) {
		MessageBox::Show("This Username is taken.Please choose another.");
		return;
	}

	Client newClient;
	newClient.name = nameStd;
	newClient.username = usernameStd;
	newClient.password = passwordStd;
	newClient.gender = genderStd;
	newClient.activityLevel = activityStd;
	newClient.age = age;

	Trainer* selectedtrainer;
	for (int i = 0; i < trainerCount; i++)
	{
		if (trainerNameStd == trainers[i].name) {
			selectedtrainer = &trainers[i];
		}
	}
	newClient.trainerId = selectedtrainer->trainerID;
	if (selectedtrainer->numClients < MAX_CLIENTS) {
		newClient.clientID = clientCount + 1;
		selectedtrainer->clients[selectedtrainer->numClients] = newClient;
		insertClient(db, newClient);
		selectedtrainer->numClients++;
		clientCount++;
		MessageBox::Show("Client registered successfully!");
	}
	else {
		MessageBox::Show("Selected trainer is at full capacity.");
	}
}
};
}
