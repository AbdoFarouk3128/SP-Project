#pragma once
#include "core.h"
#include "LoginForm.h"
#include "MyForm.h"
#include "MyForm1.h"
namespace SPProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for WelcomeForm
	/// </summary>
	public ref class WelcomeForm : public System::Windows::Forms::Form
	{
	public:
		WelcomeForm(void)
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
		~WelcomeForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	protected:
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Button^ btnSignupuser;
	private: System::Windows::Forms::Button^ btnSignupTrainer;




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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WelcomeForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->btnSignupuser = (gcnew System::Windows::Forms::Button());
			this->btnSignupTrainer = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(230, 47);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(409, 336);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnLogin
			// 
			this->btnLogin->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnLogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->btnLogin->Location = System::Drawing::Point(333, 485);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(203, 60);
			this->btnLogin->TabIndex = 1;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &WelcomeForm::btnLogin_Click);
			// 
			// btnSignupuser
			// 
			this->btnSignupuser->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSignupuser->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSignupuser->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignupuser->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSignupuser->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->btnSignupuser->Location = System::Drawing::Point(447, 408);
			this->btnSignupuser->Name = L"btnSignupuser";
			this->btnSignupuser->Size = System::Drawing::Size(203, 60);
			this->btnSignupuser->TabIndex = 2;
			this->btnSignupuser->Text = L" Sign up Client";
			this->btnSignupuser->UseVisualStyleBackColor = true;
			this->btnSignupuser->Click += gcnew System::EventHandler(this, &WelcomeForm::btnSignup_Click);
			// 
			// btnSignupTrainer
			// 
			this->btnSignupTrainer->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->btnSignupTrainer->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnSignupTrainer->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnSignupTrainer->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnSignupTrainer->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)), static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->btnSignupTrainer->Location = System::Drawing::Point(216, 408);
			this->btnSignupTrainer->Name = L"btnSignupTrainer";
			this->btnSignupTrainer->Size = System::Drawing::Size(203, 60);
			this->btnSignupTrainer->TabIndex = 4;
			this->btnSignupTrainer->Text = L"Sign up Trainer";
			this->btnSignupTrainer->UseVisualStyleBackColor = true;
			this->btnSignupTrainer->Click += gcnew System::EventHandler(this, &WelcomeForm::btnSignupTrainer_Click);
			// 
			// WelcomeForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->ClientSize = System::Drawing::Size(884, 661);
			this->Controls->Add(this->btnSignupTrainer);
			this->Controls->Add(this->btnSignupuser);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"WelcomeForm";
			this->Text = L"WelcomeForm";
			this->Load += gcnew System::EventHandler(this, &WelcomeForm::WelcomeForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Hide();
		LoginForm^ lf = gcnew LoginForm();
		lf->ShowDialog();
		this->Show();
		return;
	}
private: System::Void btnSignup_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	MyForm^ sp = gcnew MyForm();
	sp->ShowDialog();
	this->Show();
	return;
}
private: System::Void WelcomeForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnSignupTrainer_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
	MyForm1^ tp = gcnew MyForm1();
	tp->ShowDialog();
	this->Show();
	return;
}
};
}
