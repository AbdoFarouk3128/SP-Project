#pragma once

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
		traiermenu(void)
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
	private: System::Windows::Forms::Button^ button4;









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
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel6->SuspendLayout();
			this->panel5->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(52)), static_cast<System::Int32>(static_cast<System::Byte>(73)),
				static_cast<System::Int32>(static_cast<System::Byte>(94)));
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(884, 100);
			this->panel1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(297, 28);
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
			this->panel2->Controls->Add(this->panel6);
			this->panel2->Controls->Add(this->panel5);
			this->panel2->Controls->Add(this->panel4);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 100);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(200, 561);
			this->panel2->TabIndex = 1;
			// 
			// panel6
			// 
			this->panel6->Controls->Add(this->pictureBox3);
			this->panel6->Controls->Add(this->button3);
			this->panel6->Location = System::Drawing::Point(0, 378);
			this->panel6->Margin = System::Windows::Forms::Padding(10);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(200, 171);
			this->panel6->TabIndex = 2;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(3, 109);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(187, 53);
			this->button3->TabIndex = 0;
			this->button3->Text = L"Client Progress";
			this->button3->UseVisualStyleBackColor = false;
			// 
			// panel5
			// 
			this->panel5->Controls->Add(this->pictureBox2);
			this->panel5->Controls->Add(this->button2);
			this->panel5->Location = System::Drawing::Point(0, 209);
			this->panel5->Margin = System::Windows::Forms::Padding(10);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(200, 144);
			this->panel5->TabIndex = 1;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(3, 76);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(191, 53);
			this->button2->TabIndex = 0;
			this->button2->Text = L"Manage Workouts";
			this->button2->UseVisualStyleBackColor = false;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->pictureBox1);
			this->panel4->Controls->Add(this->button1);
			this->panel4->Location = System::Drawing::Point(3, 10);
			this->panel4->Margin = System::Windows::Forms::Padding(10);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(191, 170);
			this->panel4->TabIndex = 0;
			this->panel4->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &traiermenu::panel4_Paint);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(50, 34);
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
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 15.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(-3, 124);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(190, 43);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Clients Information";
			this->button1->UseVisualStyleBackColor = false;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->panel3->Controls->Add(this->button4);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel3->Location = System::Drawing::Point(200, 100);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(684, 561);
			this->panel3->TabIndex = 2;
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(42, 20);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 50);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(42, 41);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(100, 50);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 1;
			this->pictureBox3->TabStop = false;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button4->AutoSize = true;
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(64)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(577, 487);
			this->button4->Margin = System::Windows::Forms::Padding(200);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(93, 53);
			this->button4->TabIndex = 0;
			this->button4->Text = L"LOGOUT";
			this->button4->UseVisualStyleBackColor = false;
			// 
			// traiermenu
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(884, 661);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"traiermenu";
			this->Text = L"traiermenu";
			this->Load += gcnew System::EventHandler(this, &traiermenu::traiermenu_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel6->ResumeLayout(false);
			this->panel5->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
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
};
}
