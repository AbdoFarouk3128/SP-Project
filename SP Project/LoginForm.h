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
		}

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
	private: System::Windows::Forms::Button^ btnLogin;
	private: System::Windows::Forms::Label^ lblusername;
	private: System::Windows::Forms::Label^ lblPassword;
	private: System::Windows::Forms::Label^ lblStatus;
	private: System::Windows::Forms::TextBox^ txtUsername;
	private: System::Windows::Forms::TextBox^ txtPassword;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(LoginForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->btnLogin = (gcnew System::Windows::Forms::Button());
			this->lblusername = (gcnew System::Windows::Forms::Label());
			this->lblPassword = (gcnew System::Windows::Forms::Label());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->txtUsername = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(234, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(395, 325);
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// btnLogin
			// 
			this->btnLogin->Cursor = System::Windows::Forms::Cursors::Hand;
			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnLogin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->btnLogin->Location = System::Drawing::Point(320, 475);
			this->btnLogin->Name = L"btnLogin";
			this->btnLogin->Size = System::Drawing::Size(236, 55);
			this->btnLogin->TabIndex = 1;
			this->btnLogin->Text = L"Login";
			this->btnLogin->UseVisualStyleBackColor = true;
			this->btnLogin->Click += gcnew System::EventHandler(this, &LoginForm::btnLogin_Click);
			// 
			// lblusername
			// 
			this->lblusername->AutoSize = true;
			this->lblusername->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblusername->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->lblusername->Location = System::Drawing::Point(175, 351);
			this->lblusername->Name = L"lblusername";
			this->lblusername->Size = System::Drawing::Size(132, 31);
			this->lblusername->TabIndex = 2;
			this->lblusername->Text = L"Username";
			// 
			// lblPassword
			// 
			this->lblPassword->AutoSize = true;
			this->lblPassword->Font = (gcnew System::Drawing::Font(L"Times New Roman", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblPassword->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->lblPassword->Location = System::Drawing::Point(175, 391);
			this->lblPassword->Name = L"lblPassword";
			this->lblPassword->Size = System::Drawing::Size(127, 31);
			this->lblPassword->TabIndex = 3;
			this->lblPassword->Text = L"Password";
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatus->ForeColor = System::Drawing::Color::Red;
			this->lblStatus->Location = System::Drawing::Point(274, 437);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(0, 26);
			this->lblStatus->TabIndex = 4;
			// 
			// txtUsername
			// 
			this->txtUsername->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->txtUsername->Font = (gcnew System::Drawing::Font(L"Times New Roman", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtUsername->Location = System::Drawing::Point(353, 361);
			this->txtUsername->MaxLength = 20;
			this->txtUsername->Name = L"txtUsername";
			this->txtUsername->Size = System::Drawing::Size(176, 26);
			this->txtUsername->TabIndex = 5;
			this->txtUsername->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// txtPassword
			// 
			this->txtPassword->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->txtPassword->Font = (gcnew System::Drawing::Font(L"Traditional Arabic", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtPassword->Location = System::Drawing::Point(353, 392);
			this->txtPassword->Margin = System::Windows::Forms::Padding(1);
			this->txtPassword->MaxLength = 20;
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->Size = System::Drawing::Size(176, 32);
			this->txtPassword->TabIndex = 6;
			this->txtPassword->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// LoginForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->ClientSize = System::Drawing::Size(884, 661);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtUsername);
			this->Controls->Add(this->lblStatus);
			this->Controls->Add(this->lblPassword);
			this->Controls->Add(this->lblusername);
			this->Controls->Add(this->btnLogin);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"LoginForm";
			this->Text = L"LoginForm";
			this->Load += gcnew System::EventHandler(this, &LoginForm::LoginForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user = txtUsername->Text;
		String^ pass = txtPassword->Text;

		std::string stdUser = msclr::interop::marshal_as<std::string>(user);
		std::string stdPass = msclr::interop::marshal_as<std::string>(pass);

		Client* c = clientLogin(stdUser, stdPass);
		if (c != nullptr)
		{
			lblStatus->Text = "Client login successful!";
			this->Hide();
			clientmenupage^ cf = gcnew clientmenupage(c);
			cf->ShowDialog();
			this->Show();
			return;
		}

		Trainer* t = trainerLogin(stdUser, stdPass);
		if (t != nullptr)
		{
			lblStatus->Text = "Trainer login successful!";
			this->Hide();
			traiermenu^ tf = gcnew traiermenu(t);
			tf->ShowDialog();
			this->Show();
			return;
		}

		lblStatus->Text = "Invalid username or password.";
	}
private: System::Void LoginForm_Load(System::Object^ sender, System::EventArgs^ e) {
}
};
}
