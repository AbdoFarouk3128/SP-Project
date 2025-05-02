//#pragma once
//
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
//	/// Summary for SIGNTRAINER
//	/// </summary>
//	public ref class SIGNTRAINER : public System::Windows::Forms::Form
//	{
//	public:
//		SIGNTRAINER(void)
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
//		~SIGNTRAINER()
//		{
//			if (components)
//			{
//				delete components;
//			}
//		}
//	private: System::Windows::Forms::Label^ label1;
//	protected:
//	private: System::Windows::Forms::Label^ label2;
//	private: System::Windows::Forms::Label^ label3;
//	private: System::Windows::Forms::Label^ label4;
//	private: System::Windows::Forms::TextBox^ textBox1;
//	private: System::Windows::Forms::TextBox^ textBox2;
//	private: System::Windows::Forms::TextBox^ textBox3;
//	private: System::Windows::Forms::Button^ button1;
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
//			this->label1 = (gcnew System::Windows::Forms::Label());
//			this->label2 = (gcnew System::Windows::Forms::Label());
//			this->label3 = (gcnew System::Windows::Forms::Label());
//			this->label4 = (gcnew System::Windows::Forms::Label());
//			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
//			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
//			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
//			this->button1 = (gcnew System::Windows::Forms::Button());
//			this->SuspendLayout();
//			// 
//			// label1
//			// 
//			this->label1->AutoSize = true;
//			this->label1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
//				static_cast<System::Int32>(static_cast<System::Byte>(224)));
//			this->label1->Location = System::Drawing::Point(109, 98);
//			this->label1->Name = L"label1";
//			this->label1->Size = System::Drawing::Size(94, 32);
//			this->label1->TabIndex = 0;
//			this->label1->Text = L"Name";
//			// 
//			// label2
//			// 
//			this->label2->AutoSize = true;
//			this->label2->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
//				static_cast<System::Int32>(static_cast<System::Byte>(224)));
//			this->label2->Location = System::Drawing::Point(90, 178);
//			this->label2->Name = L"label2";
//			this->label2->Size = System::Drawing::Size(176, 32);
//			this->label2->TabIndex = 1;
//			this->label2->Text = L"USERNAME";
//			// 
//			// label3
//			// 
//			this->label3->AutoSize = true;
//			this->label3->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
//				static_cast<System::Int32>(static_cast<System::Byte>(224)));
//			this->label3->Location = System::Drawing::Point(86, 254);
//			this->label3->Name = L"label3";
//			this->label3->Size = System::Drawing::Size(180, 32);
//			this->label3->TabIndex = 2;
//			this->label3->Text = L"PASSWORD";
//			// 
//			// label4
//			// 
//			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Top;
//			this->label4->AutoSize = true;
//			this->label4->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 22, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
//				static_cast<System::Int32>(static_cast<System::Byte>(224)));
//			this->label4->Location = System::Drawing::Point(230, 28);
//			this->label4->Name = L"label4";
//			this->label4->Size = System::Drawing::Size(406, 51);
//			this->label4->TabIndex = 3;
//			this->label4->Text = L"FITNESS CENTER";
//			// 
//			// textBox1
//			// 
//			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
//				| System::Windows::Forms::AnchorStyles::Left)
//				| System::Windows::Forms::AnchorStyles::Right));
//			this->textBox1->Location = System::Drawing::Point(336, 105);
//			this->textBox1->Name = L"textBox1";
//			this->textBox1->Size = System::Drawing::Size(351, 26);
//			this->textBox1->TabIndex = 4;
//			// 
//			// textBox2
//			// 
//			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
//				| System::Windows::Forms::AnchorStyles::Left)
//				| System::Windows::Forms::AnchorStyles::Right));
//			this->textBox2->Location = System::Drawing::Point(336, 185);
//			this->textBox2->Name = L"textBox2";
//			this->textBox2->Size = System::Drawing::Size(351, 26);
//			this->textBox2->TabIndex = 5;
//			// 
//			// textBox3
//			// 
//			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
//				| System::Windows::Forms::AnchorStyles::Left)
//				| System::Windows::Forms::AnchorStyles::Right));
//			this->textBox3->Location = System::Drawing::Point(336, 260);
//			this->textBox3->Name = L"textBox3";
//			this->textBox3->Size = System::Drawing::Size(351, 26);
//			this->textBox3->TabIndex = 6;
//			// 
//			// button1
//			// 
//			this->button1->Anchor = System::Windows::Forms::AnchorStyles::None;
//			this->button1->Font = (gcnew System::Drawing::Font(L"Arial Rounded MT Bold", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
//				static_cast<System::Byte>(0)));
//			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
//				static_cast<System::Int32>(static_cast<System::Byte>(94)));
//			this->button1->Location = System::Drawing::Point(336, 313);
//			this->button1->Name = L"button1";
//			this->button1->Size = System::Drawing::Size(219, 52);
//			this->button1->TabIndex = 7;
//			this->button1->Text = L"REGISTER";
//			this->button1->UseVisualStyleBackColor = true;
//			// 
//			// SIGNTRAINER
//			// 
//			this->AutoScaleDimensions = System::Drawing::SizeF(9, 20);
//			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
//			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
//				static_cast<System::Int32>(static_cast<System::Byte>(94)));
//			this->ClientSize = System::Drawing::Size(795, 404);
//			this->Controls->Add(this->button1);
//			this->Controls->Add(this->textBox3);
//			this->Controls->Add(this->textBox2);
//			this->Controls->Add(this->textBox1);
//			this->Controls->Add(this->label4);
//			this->Controls->Add(this->label3);
//			this->Controls->Add(this->label2);
//			this->Controls->Add(this->label1);
//			this->Name = L"SIGNTRAINER";
//			this->Text = L"SIGNTRAINER";
//			this->Load += gcnew System::EventHandler(this, &SIGNTRAINER::SIGNTRAINER_Load);
//			this->ResumeLayout(false);
//			this->PerformLayout();
//
//		}
//#pragma endregion
//	private: System::Void SIGNTRAINER_Load(System::Object^ sender, System::EventArgs^ e) {
//	}
//};
//}
