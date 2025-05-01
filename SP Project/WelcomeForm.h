//#pragma once
//#include "core.h"
//#include "LoginForm.h"
//namespace SPProject {
//
//	using namespace System;
//	using namespace System::ComponentModel;
//	using namespace System::Collections;
//	using namespace System::Windows::Forms;
//	using namespace System::Data;
//	using namespace System::Drawing;
//
//	/// <summary>
//	/// Summary for WelcomeForm
//	/// </summary>
//	public ref class WelcomeForm : public System::Windows::Forms::Form
//	{
//	public:
//		WelcomeForm(void)
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
//		~WelcomeForm()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//	private: System::Windows::Forms::PictureBox^ pictureBox1;
//	protected:
//	private: System::Windows::Forms::Button^ btnLogin;
//	private: System::Windows::Forms::Button^ btnSignup;
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
//			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(WelcomeForm::typeid));
//			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
//			this->btnLogin = (gcnew System::Windows::Forms::Button());
//			this->btnSignup = (gcnew System::Windows::Forms::Button());
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
//			this->SuspendLayout();
//			// 
//			// pictureBox1
//			// 
//			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
//			this->pictureBox1->Location = System::Drawing::Point(230, 47);
//			this->pictureBox1->Name = L"pictureBox1";
//			this->pictureBox1->Size = System::Drawing::Size(409, 336);
//			this->pictureBox1->TabIndex = 0;
//			this->pictureBox1->TabStop = false;
//			// 
//			// btnLogin
//			// 
//			this->btnLogin->Cursor = System::Windows::Forms::Cursors::Hand;
//			this->btnLogin->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
//			this->btnLogin->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->btnLogin->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
//				static_cast<System::Int32>(static_cast<System::Byte>(241)));
//			this->btnLogin->Location = System::Drawing::Point(216, 408);
//			this->btnLogin->Name = L"btnLogin";
//			this->btnLogin->Size = System::Drawing::Size(203, 60);
//			this->btnLogin->TabIndex = 1;
//			this->btnLogin->Text = L"Login";
//			this->btnLogin->UseVisualStyleBackColor = true;
//			this->btnLogin->Click += gcnew System::EventHandler(this, &WelcomeForm::btnLogin_Click);
//			// 
//			// btnSignup
//			// 
//			this->btnSignup->Cursor = System::Windows::Forms::Cursors::Hand;
//			this->btnSignup->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
//			this->btnSignup->Font = (gcnew System::Drawing::Font(L"Times New Roman", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->btnSignup->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
//				static_cast<System::Int32>(static_cast<System::Byte>(241)));
//			this->btnSignup->Location = System::Drawing::Point(447, 408);
//			this->btnSignup->Name = L"btnSignup";
//			this->btnSignup->Size = System::Drawing::Size(203, 60);
//			this->btnSignup->TabIndex = 2;
//			this->btnSignup->Text = L"Sign up";
//			this->btnSignup->UseVisualStyleBackColor = true;
//			// 
//			// WelcomeForm
//			// 
//			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
//				static_cast<System::Int32>(static_cast<System::Byte>(94)));
//			this->ClientSize = System::Drawing::Size(884, 661);
//			this->Controls->Add(this->btnSignup);
//			this->Controls->Add(this->btnLogin);
//			this->Controls->Add(this->pictureBox1);
//			this->Name = L"WelcomeForm";
//			this->Text = L"WelcomeForm";
//			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
//			this->ResumeLayout(false);
//
//		}
//#pragma endregion
//	private: System::Void btnLogin_Click(System::Object^ sender, System::EventArgs^ e) {
//		this->Hide();
//		LoginForm^ lf = gcnew LoginForm();
//		lf->ShowDialog();
//		this->Show();
//		return;
//	}
//};
//}
