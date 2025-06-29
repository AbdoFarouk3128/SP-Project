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
	using namespace msclr::interop;
	using namespace System::Windows::Forms::DataVisualization::Charting;




	/// <summary>
	/// Summary for clientmenupage
	/// </summary>
	public ref class clientmenupage : public System::Windows::Forms::Form
	{

	public:
		Client* client;
	public:
		clientmenupage(Client* c)
		{
			client = c;
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			// 
			

			this->bViewWorkouts->Click += gcnew System::EventHandler(this, &clientmenupage::OnButtonClick);
			this->bLogCompletedWorkout->Click += gcnew System::EventHandler(this, &clientmenupage::OnButtonClick);
			this->bLog_Measurments->Click += gcnew System::EventHandler(this, &clientmenupage::OnButtonClick);
			this->bHealth_Summary->Click += gcnew System::EventHandler(this, &clientmenupage::OnButtonClick);
			this->bView_Measurments->Click += gcnew System::EventHandler(this, &clientmenupage::OnButtonClick);

			  


		/*	this->bViewWorkouts->MouseEnter += gcnew System::EventHandler(this, &clientmenupage::OnButtonHover);
			this->bViewWorkouts->MouseLeave += gcnew System::EventHandler(this, &clientmenupage::OnButtonLeave);

			
			this->bLogCompletedWorkout->MouseEnter += gcnew System::EventHandler(this, &clientmenupage::OnButtonHover);
			this->bLogCompletedWorkout->MouseLeave += gcnew System::EventHandler(this, &clientmenupage::OnButtonLeave);

			this->bLog_Measurments->MouseEnter += gcnew System::EventHandler(this, &clientmenupage::OnButtonHover);
			this->bLog_Measurments->MouseLeave += gcnew System::EventHandler(this, &clientmenupage::OnButtonLeave);


			this->bHealth_Summary->MouseEnter += gcnew System::EventHandler(this, &clientmenupage::OnButtonHover);
			this->bHealth_Summary->MouseLeave += gcnew System::EventHandler(this, &clientmenupage::OnButtonLeave);

			
			this->bView_Measurments->MouseEnter += gcnew System::EventHandler(this, &clientmenupage::OnButtonHover);
			this->bView_Measurments->MouseLeave += gcnew System::EventHandler(this, &clientmenupage::OnButtonLeave);
*/

		}
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ logo;
	private: System::Windows::Forms::PictureBox^ clientlogo;
	public:
	private:
		Button^ lastClickedButton = nullptr;

		void OnButtonClick(System::Object^ sender, System::EventArgs^ e) {
			Button^ clickedButton = dynamic_cast<Button^>(sender);

			if (clickedButton == nullptr)
				return;

			// رجّع الزر السابق للونه العادي
			if (lastClickedButton != nullptr && lastClickedButton != clickedButton) {
				lastClickedButton->ForeColor = System::Drawing::Color::Black;
				lastClickedButton->BackColor = normalColor;
			}

			// حدّث الزر الحالي
			clickedButton->ForeColor = System::Drawing::Color::White;
			clickedButton->BackColor = hoverColor;

			// خزّنه كآخر زر
			lastClickedButton = clickedButton;
		}
	private:
		System::Drawing::Color normalColor = System::Drawing::Color::FromArgb(236, 241, 240);
	private: System::Windows::Forms::Timer^ hoverTimer;

		   System::Drawing::Color hoverColor = System::Drawing::Color::LightSkyBlue;

		void OnButtonHover(System::Object^ sender, System::EventArgs^ e) {
			Button^ btn = dynamic_cast<Button^>(sender);
			if (btn != nullptr) {
				btn->BackColor = hoverColor;
			}
		}

		void OnButtonLeave(System::Object^ sender, System::EventArgs^ e) {
			Button^ btn = dynamic_cast<Button^>(sender);
			if (btn != nullptr) {
				btn->BackColor = normalColor;
			}
		}
	

		



	public:
		
		void ViewMeasurements(Client* client, DataGridView^ dataGridView) {
			dataGridView->Rows->Clear();

			if (client->numMeasurements == 0) {
				MessageBox::Show("No measurements recorded yet.", "Information",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			
			if (dataGridView->Columns->Count == 0) {
				dataGridView->Columns->Add("colNumber", "#");
				dataGridView->Columns->Add("colDate", "Date");
				dataGridView->Columns->Add("colWeight", "Weight (kg)");
				dataGridView->Columns->Add("colHeight", "Height (cm)");
			}

			
			for (int i = 0; i < client->numMeasurements; i++) {
				String^ dateStr = String::Format("{0}/{1}/{2}",
					client->measurements[i].date.Day,
					client->measurements[i].date.Month,
					client->measurements[i].date.Year);

				dataGridView->Rows->Add(
					(i + 1).ToString(),
					dateStr,
					client->measurements[i].weight.ToString(),
					client->measurements[i].height.ToString()
				);
			}
		}

	private:

		void ShowLastMeasurement() {
			panelLastMeasurement->Controls->Clear();

			if (client->numMeasurements == 0) {
				panelLastMeasurement->Visible = false;
				return;
			}
			
			Measurement last = client->measurements[client->numMeasurements - 1];
			Label^ lastLabel = gcnew Label();
			lastLabel->Text =
				"Last Measurement:\n"
				+ "Weight: " + last.weight.ToString("F1") + " kg\n"
				+ "Height: " + last.height.ToString("F1") + " cm\n"
				+ "Date: " + last.date.Day + "/" + last.date.Month + "/" + last.date.Year;

			lastLabel->Font = gcnew System::Drawing::Font("Microsoft Uighur", 20, FontStyle:: Bold);
			lastLabel->AutoSize = true;
			lastLabel->Location = System::Drawing::Point(15, 10);
			lastLabel->ForeColor = System::Drawing::Color::FromArgb(0, 0, 0);

			panelLastMeasurement->Controls->Add(lastLabel);
			panelLastMeasurement->Visible = true;
			
		}

		void LogMeasurement() {
			
			if (client->numMeasurements >= MAX_MEASUREMENTS) {
				MessageBox::Show("Measurements limit reached!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			
			double weight;
			if (!Double::TryParse(tB_weight->Text, weight) || weight <= 0) {
				MessageBox::Show("Please enter a valid weight!", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}
			if (!Double::TryParse(tB_weight->Text, weight) || weight < 30) {
				MessageBox::Show("Please enter a realistic weight (minimum is 30 kg)", "Invalid Weight",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			
			double height;
			if (client->numMeasurements == 0) {
				if (!Double::TryParse(tB_height->Text, height) || height <= 0) {
					MessageBox::Show("Please enter a valid height!", "Error",
						MessageBoxButtons::OK, MessageBoxIcon::Error);
					return;
				}
			}
			else {
				height = client->measurements[client->numMeasurements - 1].height;
			}

			if (client->numMeasurements > 0) {
				DateTime lastDate = DateTime(
					client->measurements[client->numMeasurements - 1].date.Year,
					client->measurements[client->numMeasurements - 1].date.Month,
					client->measurements[client->numMeasurements - 1].date.Day
				).Date;

				DateTime newDate = Date->Value.Date;

				if (newDate <= lastDate) {
					MessageBox::Show("The date must not be earlier than the last recorded date!", "Invalid Date",
						MessageBoxButtons::OK, MessageBoxIcon::Warning);
					return;
				}
			}
			
			Measurement newMeasure;
			newMeasure.weight = weight;
			newMeasure.height = height;
			newMeasure.date.Day = Date->Value.Day;
			newMeasure.date.Month = Date->Value.Month;
			newMeasure.date.Year = Date->Value.Year;

			
			client->measurements[client->numMeasurements++] = newMeasure;

			
			insertMeasurement(db, newMeasure, client->clientID);

			
			MessageBox::Show("Measurements added successfully!", "Success",
				MessageBoxButtons::OK, MessageBoxIcon::Information);

		
			tB_weight->Text = "";
			if (client->numMeasurements == 1) {
				tB_height->Text = "";
			}
			ShowLastMeasurement();

		}
	
		
	private:
		void ValidateWeightInput(System::Object^ sender, System::EventArgs^ e) {
			double result;
			if (!Double::TryParse(tB_weight->Text, result) || result <= 0) {
				tB_weight->ForeColor = Color::Red;
			}
			else {
				tB_weight->ForeColor = Color::Black;
			}
		}


	private: 
		void ViewWorkouts(Client* client, ListView^ listViewWorkouts) {
			listViewWorkouts->Items->Clear();
			listViewWorkouts->View = View::Details;
			listViewWorkouts->FullRowSelect = true;
			listViewWorkouts->GridLines = true;

			// تأكد إن الأعمدة مضافة مرة واحدة فقط
			if (listViewWorkouts->Columns->Count == 0) {
				listViewWorkouts->Columns->Add("Workout Info", 300);
				listViewWorkouts->Columns->Add("Status", 100);
			}

			if (client->numWorkouts == 0) {
				ListViewItem^ item = gcnew ListViewItem("No workouts assigned yet...");
				listViewWorkouts->Items->Add(item);
				return;
			}

			for (int i = 0; i < client->numWorkouts; i++) {
				String^ workoutName = gcnew String(client->workoutPlans[i].workoutName.c_str());
				String^ status = gcnew String(client->workoutPlans[i].istrue.c_str());
				int duration = client->workoutPlans[i].duration;

				// العنوان الأساسي
				String^ workoutInfo = String::Format("{0}. {1} ({2} min)", i + 1, workoutName, duration);

				ListViewItem^ mainItem = gcnew ListViewItem(workoutInfo);
				mainItem->SubItems->Add(status);

				
				// تلوين الـ Status
				if (status->ToLower() == "done")
					mainItem->ForeColor = Color::Green;
				else if (status->ToLower() == "pending")
					mainItem->ForeColor = Color::Red;

				listViewWorkouts->Items->Add(mainItem);

				// التمارين الفرعية
				for (int j = 0; j < client->workoutPlans[i].numExercises; j++) {
					String^ exercise = gcnew String(client->workoutPlans[i].exercises[j].c_str());
					ListViewItem^ exerciseItem = gcnew ListViewItem("   - " + exercise);
					listViewWorkouts->Items->Add(exerciseItem);
				}

				// التفاصيل
				String^ details = String::Format("   Sets: {0} | Reps: {1}",
					client->workoutPlans[i].sets,
					client->workoutPlans[i].reps);

				ListViewItem^ detailsItem = gcnew ListViewItem(details);
				listViewWorkouts->Items->Add(detailsItem);

				// سطر فاصل
				listViewWorkouts->Items->Add(gcnew ListViewItem(""));
			}
		}

		/*void ViewWorkouts(Client* client, ListBox^ listBoxWorkouts) {
			listBoxWorkouts->Items->Clear(); 
			if (client->numWorkouts == 0) {
				listBoxWorkouts->Items->Add("No workouts assigned yet...");
				return;
			}

			for (int i = 0; i < client->numWorkouts; i++) {
				
				String^ workoutName = gcnew String(client->workoutPlans[i].workoutName.c_str());
				String^ status = gcnew String(client->workoutPlans[i].istrue.c_str());

				
				String^ workoutInfo = String::Format("{0}. {1} ({2} min)",
					i + 1,
					workoutName,
					client->workoutPlans[i].duration);

				listBoxWorkouts->Items->Add(workoutInfo);

				
				for (int j = 0; j < client->workoutPlans[i].numExercises; j++) {
					String^ exercise = gcnew String(client->workoutPlans[i].exercises[j].c_str());
					listBoxWorkouts->Items->Add("   - " + exercise);
				}

				
				String^ details = String::Format("   Sets: {0} | Reps: {1} | Status: {2}",
					client->workoutPlans[i].sets,
					client->workoutPlans[i].reps,
					status);

				listBoxWorkouts->Items->Add(details);
				listBoxWorkouts->Items->Add(""); 
			}
		}*/
	private:
		void LogWorkout(Client* client,
			ListView^ listViewWorkouts,
			Label^ lblStatus,
			TextBox^ txtWorkoutNumber,
			Button^ btnLogWorkout)
		{
			
			listViewWorkouts->Items->Clear();
			txtWorkoutNumber->Text = "";
			lblStatus->Text = "";

			
			if (client->numWorkouts == 0) {
				lblStatus->Text = "No workouts assigned yet.";
				txtWorkoutNumber->Enabled = false;
				btnLogWorkout->Enabled = false;
				return;
			}

			
			if (client->numLogs >= MAX_LOGS) {
				lblStatus->Text = "Log limit reached!";
				txtWorkoutNumber->Enabled = false;
				btnLogWorkout->Enabled = false;
				return;
			}

			
			ViewWorkouts(client, listViewWorkouts);

			
			txtWorkoutNumber->Enabled = true;
			btnLogWorkout->Enabled = true;
			lblStatus->Text = "Enter workout number and click Log";
			
		}
		/*private:
			void SetupButtonHover(Button^ btn)
			{
				Color normalColor = Color::White;
				Color hoverColor = Color::LightSteelBlue;

				btn->BackColor = normalColor;
				btn->FlatStyle = FlatStyle::Flat;
				btn->FlatAppearance->BorderSize = 0;
				btn->Cursor = Cursors::Hand;

				btn->MouseEnter += gcnew EventHandler(
					[btn, hoverColor](Object^ sender, EventArgs^ e) {
						btn->BackColor = hoverColor;
					});

				btn->MouseLeave += gcnew EventHandler(
					[btn, normalColor](Object^ sender, EventArgs^ e) {
						btn->BackColor = normalColor;
					});
			}*/
		
		private: 
			void ShowHealthSummary(Client* client,
				Label^ lbBMIvalue, Label^ lblStatus,
				Label^ lblBMR, Label^ lblTDEE,
				Label^ lblProtein, Label^ lblCarbs, Label^ lblFats,
				Chart^ chartMacros)
			{
				if (client->numMeasurements == 0) {
					MessageBox::Show("No measurements recorded yet.", "Information",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}

				double activityMulti = getActivityMultiplier(*client);
				double bmr = calculateBMR(*client);
				double tdee = calculateTDEE(bmr, activityMulti);
				double bmi = calculateBMI(*client);
				String^ status = marshal_as<String^>(getBMICategory(bmi));
				Measurement::Macros macros = calculateMacros(tdee, *client);

				// عرض القيم النصية
				lbBMIvalue->Text = String::Format("{0:F2}", bmi);
				lblStatus->Text = status;
				lblBMR->Text = String::Format("{0:F2} calories", bmr);
				lblTDEE->Text = String::Format("{0:F2} calories", tdee);
				lblProtein->Text = String::Format("{0:F2}g", macros.protein);
				lblCarbs->Text = String::Format("{0:F2}g", macros.carbs);
				lblFats->Text = String::Format("{0:F2}g", macros.fats);

				// تغيير لون الخلفية حسب الحالة
				if (lblStatus != nullptr) {
					lblStatus->ForeColor = Color::Black;

					if (status == "Underweight") {
						lblStatus->BackColor = Color::LightBlue;
					}
					else if (status == "Normal") {
						lblStatus->BackColor = Color::LightGreen;
					}
					else if (status == "Overweight") {
						lblStatus->BackColor = Color::Tomato;
					}
					else {
						lblStatus->BackColor = Color::White;
					}
				}

				
				// تحديث الرسم البياني لتوزيع الماكروز
				if (chartMacros != nullptr) {
					chartMacros->Series->Clear();
					chartMacros->ChartAreas[0]->AxisX->LabelStyle->Enabled = false;
					chartMacros->ChartAreas[0]->AxisY->MajorGrid->Enabled = false;

					Series^ series = gcnew Series("Macros");
					series->ChartType = SeriesChartType::Pie;
					series->Points->AddXY("Protein", macros.protein);
					series->Points->AddXY("Carbs", macros.carbs);
					series->Points->AddXY("Fats", macros.fats);

					chartMacros->Series->Add(series);
				}
			}





			/*void ShowHealthSummary(Client* client,
				Label^ lbBMIvalue, Label^ lblStatus,
				Label^ lblBMR, Label^ lblTDEE,
				Label^ lblProtein, Label^ lblCarbs, Label^ lblFats)
			{
				if (client->numMeasurements == 0) {
					MessageBox::Show("No measurements recorded yet.", "Information",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}

				double activityMulti =getActivityMultiplier(*client);
				double bmr = calculateBMR(*client);
				double tdee = calculateTDEE(bmr, activityMulti);
				double bmi = calculateBMI(*client);
				String^ status = marshal_as<String^>(getBMICategory(bmi));
				Measurement::Macros macros = calculateMacros(tdee,*client);

				
				lbBMIvalue->Text = String::Format("{0:F2}", bmi);
				lblStatus->Text = String::Format("{0}", status);
				lblBMR->Text = String::Format("{0:F2} calories", bmr);
				lblTDEE->Text = String::Format("{0:F2} calories", tdee);
				lblProtein->Text = String::Format("{0:F2}g", macros.protein);
				lblCarbs->Text = String::Format("{0:F2}g", macros.carbs);
				lblFats->Text = String::Format("{0:F2}g", macros.fats);
				
				if (lblStatus != nullptr) {
					lblStatus->ForeColor = Color::Black; 

					if (status == "Underweight") {
						lblStatus->BackColor = Color::LightBlue; 
					}
					else if (status == "Normal") {
						lblStatus->BackColor = Color::LightGreen; 
					}
					else if (status == "Overweight") {
						lblStatus->BackColor = Color::Red; 
					}
					
					else {
						lblStatus->BackColor = Color::White;
					}
				}
			
			}*/
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~clientmenupage()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::Windows::Forms::Panel^ Title;
protected:


	protected:
	private: System::Windows::Forms::Panel^ panel2;
private: System::Windows::Forms::Panel^ p_measurment;
private: System::Windows::Forms::Panel^ p_workout;
private: System::Windows::Forms::Panel^ p_logworkouts;



private: System::Windows::Forms::Panel^ p_logmeasurments;

private: System::Windows::Forms::Panel^ p_health;








	private: System::Windows::Forms::Panel^ mainpage;
private: System::Windows::Forms::Panel^ logoutp;

private: System::Windows::Forms::Button^ Logout;

	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
private: System::Windows::Forms::Label^ CLIENTM;

	private: System::Windows::Forms::Button^ bLogCompletedWorkout;

	private: System::Windows::Forms::Button^ bLog_Measurments;

	private: System::Windows::Forms::Button^ bHealth_Summary;

	private: System::Windows::Forms::Button^ bView_Measurments;
	private: System::Windows::Forms::Button^ bViewWorkouts;


	private: System::Windows::Forms::Panel^ VIEWmeasurment;



	private: System::Windows::Forms::Panel^ HEALTHsummary;










private: System::Windows::Forms::Label^ lblProteinValue;


private: System::Windows::Forms::Label^ lblFatsValue;

private: System::Windows::Forms::Label^ lblCarbsValue;
private: System::Windows::Forms::Label^ lbFatsValue;

private: System::Windows::Forms::Label^ lbCarbsValue;

private: System::Windows::Forms::Label^ lbProteinValue;






private: System::Windows::Forms::Panel^ LOGmeasurment;






private: System::Windows::Forms::DateTimePicker^ Date;





private: System::Windows::Forms::Button^ LOGm;
private: System::Windows::Forms::Panel^ LOGcomworkout;
private: System::Windows::Forms::Label^ lblStatus;
private: System::Windows::Forms::TextBox^ txtWorkoutNumber;




private: System::Windows::Forms::Button^ bt_Logw;



private: System::Windows::Forms::Panel^ VIEWworkouts;




private: System::Windows::Forms::ListView^ listViewWorkouts;


private: System::Windows::Forms::ListView^ WORKOUTS;


private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartMacros;

private: System::Windows::Forms::Label^ lbBMRValue;
private: System::Windows::Forms::Label^ lbTDEEValue;
private: System::Windows::Forms::Label^ lbStatusValue;
private: System::Windows::Forms::Label^ lbBMIValue;
private: System::Windows::Forms::Label^ label7;
private: System::Windows::Forms::Label^ lblStatusValue;
private: System::Windows::Forms::Label^ lblBMRValue;
private: System::Windows::Forms::Label^ lblBMIValue;
protected: System::Windows::Forms::DataGridView^ dgv_ViewMeasurment;
private: System::Windows::Forms::PictureBox^ pictureBox6;
private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
private: System::Windows::Forms::Label^ lbl_weight;
private: System::Windows::Forms::Label^ lbl_height;
private: System::Windows::Forms::TextBox^ tB_height;
private: System::Windows::Forms::TextBox^ tB_weight;
private: System::Windows::Forms::Label^ lbl_date;
private: System::Windows::Forms::Panel^ panelLastMeasurement;
private: System::ComponentModel::IContainer^ components;






protected:
private:


















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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(clientmenupage::typeid));
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle16 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle17 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle18 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle19 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle20 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->Title = (gcnew System::Windows::Forms::Panel());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->CLIENTM = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->p_logworkouts = (gcnew System::Windows::Forms::Panel());
			this->bLogCompletedWorkout = (gcnew System::Windows::Forms::Button());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->p_logmeasurments = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->bLog_Measurments = (gcnew System::Windows::Forms::Button());
			this->p_health = (gcnew System::Windows::Forms::Panel());
			this->bHealth_Summary = (gcnew System::Windows::Forms::Button());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->p_measurment = (gcnew System::Windows::Forms::Panel());
			this->bView_Measurments = (gcnew System::Windows::Forms::Button());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->p_workout = (gcnew System::Windows::Forms::Panel());
			this->bViewWorkouts = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->mainpage = (gcnew System::Windows::Forms::Panel());
			this->VIEWworkouts = (gcnew System::Windows::Forms::Panel());
			this->listViewWorkouts = (gcnew System::Windows::Forms::ListView());
			this->LOGcomworkout = (gcnew System::Windows::Forms::Panel());
			this->WORKOUTS = (gcnew System::Windows::Forms::ListView());
			this->bt_Logw = (gcnew System::Windows::Forms::Button());
			this->lblStatus = (gcnew System::Windows::Forms::Label());
			this->txtWorkoutNumber = (gcnew System::Windows::Forms::TextBox());
			this->LOGmeasurment = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panelLastMeasurement = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->lbl_weight = (gcnew System::Windows::Forms::Label());
			this->lbl_height = (gcnew System::Windows::Forms::Label());
			this->Date = (gcnew System::Windows::Forms::DateTimePicker());
			this->tB_height = (gcnew System::Windows::Forms::TextBox());
			this->lbl_date = (gcnew System::Windows::Forms::Label());
			this->tB_weight = (gcnew System::Windows::Forms::TextBox());
			this->LOGm = (gcnew System::Windows::Forms::Button());
			this->HEALTHsummary = (gcnew System::Windows::Forms::Panel());
			this->chartMacros = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->lbFatsValue = (gcnew System::Windows::Forms::Label());
			this->lbCarbsValue = (gcnew System::Windows::Forms::Label());
			this->lbProteinValue = (gcnew System::Windows::Forms::Label());
			this->lbBMRValue = (gcnew System::Windows::Forms::Label());
			this->lbTDEEValue = (gcnew System::Windows::Forms::Label());
			this->lbStatusValue = (gcnew System::Windows::Forms::Label());
			this->lbBMIValue = (gcnew System::Windows::Forms::Label());
			this->lblFatsValue = (gcnew System::Windows::Forms::Label());
			this->lblCarbsValue = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->lblProteinValue = (gcnew System::Windows::Forms::Label());
			this->lblStatusValue = (gcnew System::Windows::Forms::Label());
			this->lblBMRValue = (gcnew System::Windows::Forms::Label());
			this->lblBMIValue = (gcnew System::Windows::Forms::Label());
			this->VIEWmeasurment = (gcnew System::Windows::Forms::Panel());
			this->dgv_ViewMeasurment = (gcnew System::Windows::Forms::DataGridView());
			this->logo = (gcnew System::Windows::Forms::Panel());
			this->clientlogo = (gcnew System::Windows::Forms::PictureBox());
			this->logoutp = (gcnew System::Windows::Forms::Panel());
			this->Logout = (gcnew System::Windows::Forms::Button());
			this->hoverTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->Title->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			this->panel2->SuspendLayout();
			this->p_logworkouts->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->p_logmeasurments->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->p_health->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->p_measurment->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			this->p_workout->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->mainpage->SuspendLayout();
			this->VIEWworkouts->SuspendLayout();
			this->LOGcomworkout->SuspendLayout();
			this->LOGmeasurment->SuspendLayout();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->HEALTHsummary->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMacros))->BeginInit();
			this->VIEWmeasurment->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_ViewMeasurment))->BeginInit();
			this->logo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clientlogo))->BeginInit();
			this->logoutp->SuspendLayout();
			this->SuspendLayout();
			// 
			// Title
			// 
			this->Title->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->Title->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->Title->Controls->Add(this->pictureBox6);
			this->Title->Controls->Add(this->CLIENTM);
			this->Title->Dock = System::Windows::Forms::DockStyle::Top;
			this->Title->Location = System::Drawing::Point(0, 0);
			this->Title->Margin = System::Windows::Forms::Padding(4);
			this->Title->Name = L"Title";
			this->Title->Size = System::Drawing::Size(1179, 123);
			this->Title->TabIndex = 0;
			// 
			// pictureBox6
			// 
			this->pictureBox6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
			this->pictureBox6->Location = System::Drawing::Point(3, 12);
			this->pictureBox6->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(336, 123);
			this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox6->TabIndex = 1;
			this->pictureBox6->TabStop = false;
			// 
			// CLIENTM
			// 
			this->CLIENTM->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->CLIENTM->AutoSize = true;
			this->CLIENTM->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 36, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->CLIENTM->ForeColor = System::Drawing::Color::White;
			this->CLIENTM->Location = System::Drawing::Point(405, 25);
			this->CLIENTM->Margin = System::Windows::Forms::Padding(267, 246, 267, 246);
			this->CLIENTM->Name = L"CLIENTM";
			this->CLIENTM->Size = System::Drawing::Size(383, 78);
			this->CLIENTM->TabIndex = 0;
			this->CLIENTM->Text = L"Client Menu";
			this->CLIENTM->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->panel2->Controls->Add(this->p_logworkouts);
			this->panel2->Controls->Add(this->p_logmeasurments);
			this->panel2->Controls->Add(this->p_health);
			this->panel2->Controls->Add(this->p_measurment);
			this->panel2->Controls->Add(this->p_workout);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel2->Location = System::Drawing::Point(0, 123);
			this->panel2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(336, 691);
			this->panel2->TabIndex = 1;
			// 
			// p_logworkouts
			// 
			this->p_logworkouts->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->p_logworkouts->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->p_logworkouts->Controls->Add(this->bLogCompletedWorkout);
			this->p_logworkouts->Controls->Add(this->pictureBox3);
			this->p_logworkouts->Location = System::Drawing::Point(3, 148);
			this->p_logworkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->p_logworkouts->Name = L"p_logworkouts";
			this->p_logworkouts->Size = System::Drawing::Size(327, 134);
			this->p_logworkouts->TabIndex = 1;
			// 
			// bLogCompletedWorkout
			// 
			this->bLogCompletedWorkout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->bLogCompletedWorkout->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bLogCompletedWorkout->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bLogCompletedWorkout->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->bLogCompletedWorkout->Location = System::Drawing::Point(125, 16);
			this->bLogCompletedWorkout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bLogCompletedWorkout->Name = L"bLogCompletedWorkout";
			this->bLogCompletedWorkout->Size = System::Drawing::Size(187, 94);
			this->bLogCompletedWorkout->TabIndex = 2;
			this->bLogCompletedWorkout->Text = L"Log Completed Workout";
			this->bLogCompletedWorkout->UseVisualStyleBackColor = false;
			this->bLogCompletedWorkout->Click += gcnew System::EventHandler(this, &clientmenupage::bLogCompletedWorkout_Click);
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(11, 14);
			this->pictureBox3->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(100, 98);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox3->TabIndex = 2;
			this->pictureBox3->TabStop = false;
			// 
			// p_logmeasurments
			// 
			this->p_logmeasurments->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->p_logmeasurments->Controls->Add(this->pictureBox2);
			this->p_logmeasurments->Controls->Add(this->bLog_Measurments);
			this->p_logmeasurments->Location = System::Drawing::Point(3, 286);
			this->p_logmeasurments->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->p_logmeasurments->Name = L"p_logmeasurments";
			this->p_logmeasurments->Size = System::Drawing::Size(327, 130);
			this->p_logmeasurments->TabIndex = 1;
			this->p_logmeasurments->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &clientmenupage::panel11_Paint);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(11, 12);
			this->pictureBox2->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(100, 98);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// bLog_Measurments
			// 
			this->bLog_Measurments->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->bLog_Measurments->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bLog_Measurments->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bLog_Measurments->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->bLog_Measurments->Location = System::Drawing::Point(125, 15);
			this->bLog_Measurments->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bLog_Measurments->Name = L"bLog_Measurments";
			this->bLog_Measurments->Size = System::Drawing::Size(187, 95);
			this->bLog_Measurments->TabIndex = 3;
			this->bLog_Measurments->Text = L"Log Measurements";
			this->bLog_Measurments->UseVisualStyleBackColor = false;
			this->bLog_Measurments->Click += gcnew System::EventHandler(this, &clientmenupage::bLog_Measurments_Click);
			// 
			// p_health
			// 
			this->p_health->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->p_health->Controls->Add(this->bHealth_Summary);
			this->p_health->Controls->Add(this->pictureBox4);
			this->p_health->Location = System::Drawing::Point(3, 420);
			this->p_health->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->p_health->Name = L"p_health";
			this->p_health->Size = System::Drawing::Size(327, 142);
			this->p_health->TabIndex = 1;
			// 
			// bHealth_Summary
			// 
			this->bHealth_Summary->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->bHealth_Summary->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bHealth_Summary->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bHealth_Summary->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->bHealth_Summary->Location = System::Drawing::Point(125, 15);
			this->bHealth_Summary->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bHealth_Summary->Name = L"bHealth_Summary";
			this->bHealth_Summary->Size = System::Drawing::Size(187, 103);
			this->bHealth_Summary->TabIndex = 4;
			this->bHealth_Summary->Text = L"Health Summary";
			this->bHealth_Summary->UseVisualStyleBackColor = false;
			this->bHealth_Summary->Click += gcnew System::EventHandler(this, &clientmenupage::bHealth_Summary_Click);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
			this->pictureBox4->InitialImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.InitialImage")));
			this->pictureBox4->Location = System::Drawing::Point(11, 15);
			this->pictureBox4->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 103);
			this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox4->TabIndex = 2;
			this->pictureBox4->TabStop = false;
			// 
			// p_measurment
			// 
			this->p_measurment->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->p_measurment->Controls->Add(this->bView_Measurments);
			this->p_measurment->Controls->Add(this->pictureBox5);
			this->p_measurment->Location = System::Drawing::Point(3, 566);
			this->p_measurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->p_measurment->Name = L"p_measurment";
			this->p_measurment->Size = System::Drawing::Size(327, 127);
			this->p_measurment->TabIndex = 1;
			// 
			// bView_Measurments
			// 
			this->bView_Measurments->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->bView_Measurments->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bView_Measurments->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bView_Measurments->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)),
				static_cast<System::Int32>(static_cast<System::Byte>(29)), static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->bView_Measurments->Location = System::Drawing::Point(125, 20);
			this->bView_Measurments->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bView_Measurments->Name = L"bView_Measurments";
			this->bView_Measurments->Size = System::Drawing::Size(187, 92);
			this->bView_Measurments->TabIndex = 5;
			this->bView_Measurments->Text = L"View Measurements";
			this->bView_Measurments->UseVisualStyleBackColor = false;
			this->bView_Measurments->Click += gcnew System::EventHandler(this, &clientmenupage::button6_Click);
			// 
			// pictureBox5
			// 
			this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
			this->pictureBox5->Location = System::Drawing::Point(11, 14);
			this->pictureBox5->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(100, 98);
			this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox5->TabIndex = 2;
			this->pictureBox5->TabStop = false;
			// 
			// p_workout
			// 
			this->p_workout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->p_workout->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->p_workout->Controls->Add(this->bViewWorkouts);
			this->p_workout->Controls->Add(this->pictureBox1);
			this->p_workout->Location = System::Drawing::Point(3, 4);
			this->p_workout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->p_workout->Name = L"p_workout";
			this->p_workout->Size = System::Drawing::Size(327, 139);
			this->p_workout->TabIndex = 0;
			// 
			// bViewWorkouts
			// 
			this->bViewWorkouts->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->bViewWorkouts->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bViewWorkouts->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bViewWorkouts->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->bViewWorkouts->Location = System::Drawing::Point(125, 14);
			this->bViewWorkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bViewWorkouts->Name = L"bViewWorkouts";
			this->bViewWorkouts->Size = System::Drawing::Size(187, 103);
			this->bViewWorkouts->TabIndex = 1;
			this->bViewWorkouts->Text = L"View Workouts";
			this->bViewWorkouts->UseVisualStyleBackColor = false;
			this->bViewWorkouts->Click += gcnew System::EventHandler(this, &clientmenupage::bViewWorkouts_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(11, 14);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(100, 103);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// mainpage
			// 
			this->mainpage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(240)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)));
			this->mainpage->Controls->Add(this->logo);
			this->mainpage->Controls->Add(this->VIEWworkouts);
			this->mainpage->Controls->Add(this->LOGcomworkout);
			this->mainpage->Controls->Add(this->LOGmeasurment);
			this->mainpage->Controls->Add(this->HEALTHsummary);
			this->mainpage->Controls->Add(this->VIEWmeasurment);
			this->mainpage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->mainpage->Location = System::Drawing::Point(336, 123);
			this->mainpage->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->mainpage->Name = L"mainpage";
			this->mainpage->Size = System::Drawing::Size(843, 691);
			this->mainpage->TabIndex = 2;
			// 
			// VIEWworkouts
			// 
			this->VIEWworkouts->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->VIEWworkouts->Controls->Add(this->listViewWorkouts);
			this->VIEWworkouts->Dock = System::Windows::Forms::DockStyle::Fill;
			this->VIEWworkouts->Location = System::Drawing::Point(0, 0);
			this->VIEWworkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->VIEWworkouts->Name = L"VIEWworkouts";
			this->VIEWworkouts->Size = System::Drawing::Size(843, 691);
			this->VIEWworkouts->TabIndex = 7;
			// 
			// listViewWorkouts
			// 
			this->listViewWorkouts->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->listViewWorkouts->GridLines = true;
			this->listViewWorkouts->HideSelection = false;
			this->listViewWorkouts->ImeMode = System::Windows::Forms::ImeMode::On;
			this->listViewWorkouts->Location = System::Drawing::Point(28, 15);
			this->listViewWorkouts->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->listViewWorkouts->Name = L"listViewWorkouts";
			this->listViewWorkouts->Size = System::Drawing::Size(787, 547);
			this->listViewWorkouts->TabIndex = 3;
			this->listViewWorkouts->UseCompatibleStateImageBehavior = false;
			this->listViewWorkouts->SelectedIndexChanged += gcnew System::EventHandler(this, &clientmenupage::listViewWorkouts_SelectedIndexChanged);
			// 
			// LOGcomworkout
			// 
			this->LOGcomworkout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->LOGcomworkout->Controls->Add(this->WORKOUTS);
			this->LOGcomworkout->Controls->Add(this->bt_Logw);
			this->LOGcomworkout->Controls->Add(this->lblStatus);
			this->LOGcomworkout->Controls->Add(this->txtWorkoutNumber);
			this->LOGcomworkout->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LOGcomworkout->Location = System::Drawing::Point(0, 0);
			this->LOGcomworkout->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LOGcomworkout->Name = L"LOGcomworkout";
			this->LOGcomworkout->Padding = System::Windows::Forms::Padding(13, 12, 13, 12);
			this->LOGcomworkout->Size = System::Drawing::Size(843, 691);
			this->LOGcomworkout->TabIndex = 6;
			// 
			// WORKOUTS
			// 
			this->WORKOUTS->Font = (gcnew System::Drawing::Font(L"Microsoft JhengHei UI", 13.8F, System::Drawing::FontStyle::Bold));
			this->WORKOUTS->HideSelection = false;
			this->WORKOUTS->Location = System::Drawing::Point(47, 15);
			this->WORKOUTS->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->WORKOUTS->Name = L"WORKOUTS";
			this->WORKOUTS->Size = System::Drawing::Size(745, 372);
			this->WORKOUTS->TabIndex = 7;
			this->WORKOUTS->UseCompatibleStateImageBehavior = false;
			// 
			// bt_Logw
			// 
			this->bt_Logw->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->bt_Logw->Cursor = System::Windows::Forms::Cursors::Hand;
			this->bt_Logw->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->bt_Logw->ForeColor = System::Drawing::Color::White;
			this->bt_Logw->Location = System::Drawing::Point(652, 480);
			this->bt_Logw->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->bt_Logw->Name = L"bt_Logw";
			this->bt_Logw->Size = System::Drawing::Size(109, 60);
			this->bt_Logw->TabIndex = 6;
			this->bt_Logw->Text = L"Log";
			this->bt_Logw->UseVisualStyleBackColor = false;
			this->bt_Logw->Click += gcnew System::EventHandler(this, &clientmenupage::bt_Logw_Click);
			// 
			// lblStatus
			// 
			this->lblStatus->AutoSize = true;
			this->lblStatus->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatus->Location = System::Drawing::Point(20, 417);
			this->lblStatus->Name = L"lblStatus";
			this->lblStatus->Size = System::Drawing::Size(387, 37);
			this->lblStatus->TabIndex = 4;
			this->lblStatus->Text = L"Enter number of workout you completed :";
			// 
			// txtWorkoutNumber
			// 
			this->txtWorkoutNumber->Font = (gcnew System::Drawing::Font(L"Tahoma", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txtWorkoutNumber->Location = System::Drawing::Point(453, 423);
			this->txtWorkoutNumber->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->txtWorkoutNumber->Name = L"txtWorkoutNumber";
			this->txtWorkoutNumber->Size = System::Drawing::Size(87, 27);
			this->txtWorkoutNumber->TabIndex = 3;
			this->txtWorkoutNumber->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// LOGmeasurment
			// 
			this->LOGmeasurment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->LOGmeasurment->Controls->Add(this->panel1);
			this->LOGmeasurment->Controls->Add(this->tableLayoutPanel1);
			this->LOGmeasurment->Controls->Add(this->LOGm);
			this->LOGmeasurment->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LOGmeasurment->Location = System::Drawing::Point(0, 0);
			this->LOGmeasurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LOGmeasurment->Name = L"LOGmeasurment";
			this->LOGmeasurment->Size = System::Drawing::Size(843, 691);
			this->LOGmeasurment->TabIndex = 5;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->panel1->Controls->Add(this->panelLastMeasurement);
			this->panel1->Location = System::Drawing::Point(509, 138);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(322, 220);
			this->panel1->TabIndex = 11;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &clientmenupage::panel1_Paint);
			// 
			// panelLastMeasurement
			// 
			this->panelLastMeasurement->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->panelLastMeasurement->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->panelLastMeasurement->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 24, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->panelLastMeasurement->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)),
				static_cast<System::Int32>(static_cast<System::Byte>(225)), static_cast<System::Int32>(static_cast<System::Byte>(209)));
			this->panelLastMeasurement->Location = System::Drawing::Point(16, 10);
			this->panelLastMeasurement->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->panelLastMeasurement->Name = L"panelLastMeasurement";
			this->panelLastMeasurement->Size = System::Drawing::Size(289, 201);
			this->panelLastMeasurement->TabIndex = 10;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->ColumnCount = 1;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->lbl_weight, 0, 2);
			this->tableLayoutPanel1->Controls->Add(this->lbl_height, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->Date, 0, 5);
			this->tableLayoutPanel1->Controls->Add(this->tB_height, 0, 1);
			this->tableLayoutPanel1->Controls->Add(this->lbl_date, 0, 4);
			this->tableLayoutPanel1->Controls->Add(this->tB_weight, 0, 3);
			this->tableLayoutPanel1->Location = System::Drawing::Point(16, 15);
			this->tableLayoutPanel1->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 6;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 55.10204F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 44.89796F)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 91)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 73)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 89)));
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 85)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(461, 486);
			this->tableLayoutPanel1->TabIndex = 9;
			// 
			// lbl_weight
			// 
			this->lbl_weight->AutoSize = true;
			this->lbl_weight->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_weight->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_weight->Location = System::Drawing::Point(3, 147);
			this->lbl_weight->Name = L"lbl_weight";
			this->lbl_weight->Size = System::Drawing::Size(284, 53);
			this->lbl_weight->TabIndex = 2;
			this->lbl_weight->Text = L"Enter Your Weight :";
			// 
			// lbl_height
			// 
			this->lbl_height->AutoSize = true;
			this->lbl_height->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_height->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_height->Location = System::Drawing::Point(3, 0);
			this->lbl_height->Name = L"lbl_height";
			this->lbl_height->Size = System::Drawing::Size(278, 53);
			this->lbl_height->TabIndex = 4;
			this->lbl_height->Text = L"Enter Your Height :";
			// 
			// Date
			// 
			this->Date->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Date->Location = System::Drawing::Point(3, 402);
			this->Date->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Date->Name = L"Date";
			this->Date->Size = System::Drawing::Size(421, 34);
			this->Date->TabIndex = 7;
			// 
			// tB_height
			// 
			this->tB_height->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tB_height->Location = System::Drawing::Point(3, 83);
			this->tB_height->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tB_height->Name = L"tB_height";
			this->tB_height->Size = System::Drawing::Size(435, 28);
			this->tB_height->TabIndex = 6;
			// 
			// lbl_date
			// 
			this->lbl_date->AutoSize = true;
			this->lbl_date->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lbl_date->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 25.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbl_date->Location = System::Drawing::Point(3, 311);
			this->lbl_date->Name = L"lbl_date";
			this->lbl_date->Size = System::Drawing::Size(176, 53);
			this->lbl_date->TabIndex = 3;
			this->lbl_date->Text = L"Enter Date :";
			// 
			// tB_weight
			// 
			this->tB_weight->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->tB_weight->Location = System::Drawing::Point(3, 240);
			this->tB_weight->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->tB_weight->Name = L"tB_weight";
			this->tB_weight->Size = System::Drawing::Size(435, 28);
			this->tB_weight->TabIndex = 5;
			// 
			// LOGm
			// 
			this->LOGm->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->LOGm->Cursor = System::Windows::Forms::Cursors::Hand;
			this->LOGm->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LOGm->ForeColor = System::Drawing::Color::White;
			this->LOGm->Location = System::Drawing::Point(652, 441);
			this->LOGm->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->LOGm->Name = L"LOGm";
			this->LOGm->Size = System::Drawing::Size(100, 50);
			this->LOGm->TabIndex = 8;
			this->LOGm->Text = L"Log";
			this->LOGm->UseVisualStyleBackColor = false;
			this->LOGm->Click += gcnew System::EventHandler(this, &clientmenupage::button2_Click);
			// 
			// HEALTHsummary
			// 
			this->HEALTHsummary->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->HEALTHsummary->Controls->Add(this->chartMacros);
			this->HEALTHsummary->Controls->Add(this->lbFatsValue);
			this->HEALTHsummary->Controls->Add(this->lbCarbsValue);
			this->HEALTHsummary->Controls->Add(this->lbProteinValue);
			this->HEALTHsummary->Controls->Add(this->lbBMRValue);
			this->HEALTHsummary->Controls->Add(this->lbTDEEValue);
			this->HEALTHsummary->Controls->Add(this->lbStatusValue);
			this->HEALTHsummary->Controls->Add(this->lbBMIValue);
			this->HEALTHsummary->Controls->Add(this->lblFatsValue);
			this->HEALTHsummary->Controls->Add(this->lblCarbsValue);
			this->HEALTHsummary->Controls->Add(this->label7);
			this->HEALTHsummary->Controls->Add(this->lblProteinValue);
			this->HEALTHsummary->Controls->Add(this->lblStatusValue);
			this->HEALTHsummary->Controls->Add(this->lblBMRValue);
			this->HEALTHsummary->Controls->Add(this->lblBMIValue);
			this->HEALTHsummary->Dock = System::Windows::Forms::DockStyle::Fill;
			this->HEALTHsummary->Location = System::Drawing::Point(0, 0);
			this->HEALTHsummary->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->HEALTHsummary->Name = L"HEALTHsummary";
			this->HEALTHsummary->Size = System::Drawing::Size(843, 691);
			this->HEALTHsummary->TabIndex = 4;
			// 
			// chartMacros
			// 
			this->chartMacros->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			chartArea4->Name = L"ChartArea1";
			this->chartMacros->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->chartMacros->Legends->Add(legend4);
			this->chartMacros->Location = System::Drawing::Point(403, 258);
			this->chartMacros->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->chartMacros->Name = L"chartMacros";
			series4->ChartArea = L"ChartArea1";
			series4->Legend = L"Legend1";
			series4->Name = L"Series1";
			this->chartMacros->Series->Add(series4);
			this->chartMacros->Size = System::Drawing::Size(376, 306);
			this->chartMacros->TabIndex = 18;
			this->chartMacros->Text = L"chart1";
			this->chartMacros->Click += gcnew System::EventHandler(this, &clientmenupage::chartMacros_Click);
			// 
			// lbFatsValue
			// 
			this->lbFatsValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbFatsValue->AutoSize = true;
			this->lbFatsValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbFatsValue->Location = System::Drawing::Point(139, 466);
			this->lbFatsValue->Name = L"lbFatsValue";
			this->lbFatsValue->Size = System::Drawing::Size(72, 38);
			this->lbFatsValue->TabIndex = 17;
			this->lbFatsValue->Text = L"-----";
			this->lbFatsValue->Click += gcnew System::EventHandler(this, &clientmenupage::lbFatsValue_Click);
			// 
			// lbCarbsValue
			// 
			this->lbCarbsValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbCarbsValue->AutoSize = true;
			this->lbCarbsValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbCarbsValue->Location = System::Drawing::Point(165, 372);
			this->lbCarbsValue->Name = L"lbCarbsValue";
			this->lbCarbsValue->Size = System::Drawing::Size(72, 38);
			this->lbCarbsValue->TabIndex = 16;
			this->lbCarbsValue->Text = L"-----";
			// 
			// lbProteinValue
			// 
			this->lbProteinValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbProteinValue->AutoSize = true;
			this->lbProteinValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 19.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbProteinValue->Location = System::Drawing::Point(200, 274);
			this->lbProteinValue->Name = L"lbProteinValue";
			this->lbProteinValue->Size = System::Drawing::Size(72, 38);
			this->lbProteinValue->TabIndex = 15;
			this->lbProteinValue->Text = L"-----";
			// 
			// lbBMRValue
			// 
			this->lbBMRValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbBMRValue->AutoSize = true;
			this->lbBMRValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBMRValue->Location = System::Drawing::Point(149, 143);
			this->lbBMRValue->Name = L"lbBMRValue";
			this->lbBMRValue->Size = System::Drawing::Size(65, 36);
			this->lbBMRValue->TabIndex = 14;
			this->lbBMRValue->Text = L"-----";
			// 
			// lbTDEEValue
			// 
			this->lbTDEEValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbTDEEValue->AutoSize = true;
			this->lbTDEEValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbTDEEValue->Location = System::Drawing::Point(579, 143);
			this->lbTDEEValue->Name = L"lbTDEEValue";
			this->lbTDEEValue->Size = System::Drawing::Size(65, 36);
			this->lbTDEEValue->TabIndex = 13;
			this->lbTDEEValue->Text = L"-----";
			// 
			// lbStatusValue
			// 
			this->lbStatusValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbStatusValue->AutoSize = true;
			this->lbStatusValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbStatusValue->Location = System::Drawing::Point(592, 25);
			this->lbStatusValue->Name = L"lbStatusValue";
			this->lbStatusValue->Size = System::Drawing::Size(65, 36);
			this->lbStatusValue->TabIndex = 12;
			this->lbStatusValue->Text = L"-----";
			// 
			// lbBMIValue
			// 
			this->lbBMIValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lbBMIValue->AutoSize = true;
			this->lbBMIValue->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lbBMIValue->Location = System::Drawing::Point(149, 25);
			this->lbBMIValue->Name = L"lbBMIValue";
			this->lbBMIValue->Size = System::Drawing::Size(65, 36);
			this->lbBMIValue->TabIndex = 11;
			this->lbBMIValue->Text = L"-----";
			// 
			// lblFatsValue
			// 
			this->lblFatsValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblFatsValue->AutoSize = true;
			this->lblFatsValue->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblFatsValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblFatsValue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->lblFatsValue->Location = System::Drawing::Point(13, 466);
			this->lblFatsValue->Name = L"lblFatsValue";
			this->lblFatsValue->Size = System::Drawing::Size(91, 58);
			this->lblFatsValue->TabIndex = 10;
			this->lblFatsValue->Text = L"Fats:";
			// 
			// lblCarbsValue
			// 
			this->lblCarbsValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblCarbsValue->AutoSize = true;
			this->lblCarbsValue->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblCarbsValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblCarbsValue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->lblCarbsValue->Location = System::Drawing::Point(13, 372);
			this->lblCarbsValue->Name = L"lblCarbsValue";
			this->lblCarbsValue->Size = System::Drawing::Size(115, 58);
			this->lblCarbsValue->TabIndex = 9;
			this->lblCarbsValue->Text = L"Carbs:";
			this->lblCarbsValue->Click += gcnew System::EventHandler(this, &clientmenupage::lblCarbsValue_Click);
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->label7->Location = System::Drawing::Point(423, 138);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(121, 58);
			this->label7->TabIndex = 8;
			this->label7->Text = L"TDEE:";
			// 
			// lblProteinValue
			// 
			this->lblProteinValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblProteinValue->AutoSize = true;
			this->lblProteinValue->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblProteinValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblProteinValue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->lblProteinValue->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->lblProteinValue->Location = System::Drawing::Point(16, 274);
			this->lblProteinValue->Name = L"lblProteinValue";
			this->lblProteinValue->Size = System::Drawing::Size(140, 58);
			this->lblProteinValue->TabIndex = 7;
			this->lblProteinValue->Text = L"Protein:";
			this->lblProteinValue->Click += gcnew System::EventHandler(this, &clientmenupage::lblProteinValue_Click);
			// 
			// lblStatusValue
			// 
			this->lblStatusValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblStatusValue->AutoSize = true;
			this->lblStatusValue->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblStatusValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblStatusValue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->lblStatusValue->Location = System::Drawing::Point(423, 20);
			this->lblStatusValue->Name = L"lblStatusValue";
			this->lblStatusValue->Size = System::Drawing::Size(119, 58);
			this->lblStatusValue->TabIndex = 6;
			this->lblStatusValue->Text = L"Status:";
			// 
			// lblBMRValue
			// 
			this->lblBMRValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblBMRValue->AutoSize = true;
			this->lblBMRValue->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblBMRValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBMRValue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->lblBMRValue->Location = System::Drawing::Point(16, 138);
			this->lblBMRValue->Name = L"lblBMRValue";
			this->lblBMRValue->Size = System::Drawing::Size(108, 58);
			this->lblBMRValue->TabIndex = 5;
			this->lblBMRValue->Text = L"BMR:";
			this->lblBMRValue->Click += gcnew System::EventHandler(this, &clientmenupage::lblBMRValue_Click_1);
			// 
			// lblBMIValue
			// 
			this->lblBMIValue->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->lblBMIValue->AutoSize = true;
			this->lblBMIValue->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->lblBMIValue->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 28.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lblBMIValue->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->lblBMIValue->Location = System::Drawing::Point(16, 15);
			this->lblBMIValue->Name = L"lblBMIValue";
			this->lblBMIValue->Size = System::Drawing::Size(97, 58);
			this->lblBMIValue->TabIndex = 4;
			this->lblBMIValue->Text = L"BMI:";
			this->lblBMIValue->Click += gcnew System::EventHandler(this, &clientmenupage::lblBMIValue_Click_1);
			// 
			// VIEWmeasurment
			// 
			this->VIEWmeasurment->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->VIEWmeasurment->Controls->Add(this->dgv_ViewMeasurment);
			this->VIEWmeasurment->Dock = System::Windows::Forms::DockStyle::Fill;
			this->VIEWmeasurment->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->VIEWmeasurment->Location = System::Drawing::Point(0, 0);
			this->VIEWmeasurment->Margin = System::Windows::Forms::Padding(5);
			this->VIEWmeasurment->Name = L"VIEWmeasurment";
			this->VIEWmeasurment->Size = System::Drawing::Size(843, 691);
			this->VIEWmeasurment->TabIndex = 3;
			this->VIEWmeasurment->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &clientmenupage::VIEWmeasurment_Paint);
			// 
			// dgv_ViewMeasurment
			// 
			this->dgv_ViewMeasurment->AllowUserToResizeColumns = false;
			this->dgv_ViewMeasurment->AllowUserToResizeRows = false;
			dataGridViewCellStyle16->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle16->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle16->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle16->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			dataGridViewCellStyle16->SelectionForeColor = System::Drawing::Color::Black;
			this->dgv_ViewMeasurment->AlternatingRowsDefaultCellStyle = dataGridViewCellStyle16;
			this->dgv_ViewMeasurment->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->dgv_ViewMeasurment->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dgv_ViewMeasurment->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->dgv_ViewMeasurment->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dgv_ViewMeasurment->CellBorderStyle = System::Windows::Forms::DataGridViewCellBorderStyle::Raised;
			dataGridViewCellStyle17->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle17->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle17->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle17->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			dataGridViewCellStyle17->Padding = System::Windows::Forms::Padding(5);
			dataGridViewCellStyle17->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)),
				static_cast<System::Int32>(static_cast<System::Byte>(241)), static_cast<System::Int32>(static_cast<System::Byte>(240)));
			dataGridViewCellStyle17->SelectionForeColor = System::Drawing::SystemColors::ControlText;
			this->dgv_ViewMeasurment->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle17;
			this->dgv_ViewMeasurment->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle18->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle18->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle18->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle18->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle18->Padding = System::Windows::Forms::Padding(3);
			dataGridViewCellStyle18->SelectionBackColor = System::Drawing::Color::LightBlue;
			dataGridViewCellStyle18->SelectionForeColor = System::Drawing::SystemColors::Desktop;
			dataGridViewCellStyle18->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dgv_ViewMeasurment->DefaultCellStyle = dataGridViewCellStyle18;
			this->dgv_ViewMeasurment->GridColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)),
				static_cast<System::Int32>(static_cast<System::Byte>(36)), static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->dgv_ViewMeasurment->Location = System::Drawing::Point(62, 98);
			this->dgv_ViewMeasurment->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->dgv_ViewMeasurment->Name = L"dgv_ViewMeasurment";
			dataGridViewCellStyle19->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle19->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			dataGridViewCellStyle19->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle19->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle19->Padding = System::Windows::Forms::Padding(5);
			dataGridViewCellStyle19->SelectionBackColor = System::Drawing::SystemColors::ButtonShadow;
			dataGridViewCellStyle19->SelectionForeColor = System::Drawing::SystemColors::Desktop;
			this->dgv_ViewMeasurment->RowHeadersDefaultCellStyle = dataGridViewCellStyle19;
			this->dgv_ViewMeasurment->RowHeadersWidthSizeMode = System::Windows::Forms::DataGridViewRowHeadersWidthSizeMode::AutoSizeToAllHeaders;
			dataGridViewCellStyle20->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle20->BackColor = System::Drawing::Color::White;
			dataGridViewCellStyle20->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle20->ForeColor = System::Drawing::Color::Black;
			dataGridViewCellStyle20->Padding = System::Windows::Forms::Padding(5);
			dataGridViewCellStyle20->SelectionBackColor = System::Drawing::Color::SkyBlue;
			dataGridViewCellStyle20->SelectionForeColor = System::Drawing::Color::White;
			this->dgv_ViewMeasurment->RowsDefaultCellStyle = dataGridViewCellStyle20;
			this->dgv_ViewMeasurment->RowTemplate->Height = 30;
			this->dgv_ViewMeasurment->Size = System::Drawing::Size(717, 410);
			this->dgv_ViewMeasurment->TabIndex = 0;
			this->dgv_ViewMeasurment->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &clientmenupage::dataGridView1_CellContentClick_1);
			// 
			// logo
			// 
			this->logo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->logo->Controls->Add(this->clientlogo);
			this->logo->Dock = System::Windows::Forms::DockStyle::Fill;
			this->logo->Location = System::Drawing::Point(0, 0);
			this->logo->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->logo->Name = L"logo";
			this->logo->Size = System::Drawing::Size(843, 691);
			this->logo->TabIndex = 8;
			// 
			// clientlogo
			// 
			this->clientlogo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"clientlogo.Image")));
			this->clientlogo->Location = System::Drawing::Point(3, 7);
			this->clientlogo->Name = L"clientlogo";
			this->clientlogo->Size = System::Drawing::Size(843, 581);
			this->clientlogo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->clientlogo->TabIndex = 0;
			this->clientlogo->TabStop = false;
			// 
			// logoutp
			// 
			this->logoutp->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(1)), static_cast<System::Int32>(static_cast<System::Byte>(36)),
				static_cast<System::Int32>(static_cast<System::Byte>(67)));
			this->logoutp->Controls->Add(this->Logout);
			this->logoutp->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->logoutp->Location = System::Drawing::Point(336, 714);
			this->logoutp->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->logoutp->Name = L"logoutp";
			this->logoutp->Size = System::Drawing::Size(843, 100);
			this->logoutp->TabIndex = 3;
			// 
			// Logout
			// 
			this->Logout->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->Logout->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(236)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(240)));
			this->Logout->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Logout->Font = (gcnew System::Drawing::Font(L"Microsoft Uighur", 19.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logout->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(29)),
				static_cast<System::Int32>(static_cast<System::Byte>(44)));
			this->Logout->Location = System::Drawing::Point(695, 25);
			this->Logout->Margin = System::Windows::Forms::Padding(0);
			this->Logout->Name = L"Logout";
			this->Logout->Size = System::Drawing::Size(120, 60);
			this->Logout->TabIndex = 0;
			this->Logout->Text = L"Logout";
			this->Logout->UseVisualStyleBackColor = false;
			this->Logout->Click += gcnew System::EventHandler(this, &clientmenupage::Logout_Click);
			// 
			// clientmenupage
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(1179, 814);
			this->Controls->Add(this->logoutp);
			this->Controls->Add(this->mainpage);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->Title);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"clientmenupage";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"clientmenupage";
			this->Title->ResumeLayout(false);
			this->Title->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			this->panel2->ResumeLayout(false);
			this->p_logworkouts->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->p_logmeasurments->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->p_health->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->p_measurment->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			this->p_workout->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->mainpage->ResumeLayout(false);
			this->VIEWworkouts->ResumeLayout(false);
			this->LOGcomworkout->ResumeLayout(false);
			this->LOGcomworkout->PerformLayout();
			this->LOGmeasurment->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->tableLayoutPanel1->PerformLayout();
			this->HEALTHsummary->ResumeLayout(false);
			this->HEALTHsummary->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartMacros))->EndInit();
			this->VIEWmeasurment->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgv_ViewMeasurment))->EndInit();
			this->logo->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->clientlogo))->EndInit();
			this->logoutp->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void panel11_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
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
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		VIEWmeasurment->BringToFront();
		ViewMeasurements(client, dgv_ViewMeasurment);
	}
	private: System::Void Logout_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
	}
	private: System::Void VIEWmeasurment_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void bHealth_Summary_Click(System::Object^ sender, System::EventArgs^ e) {
		HEALTHsummary->BringToFront();
		ShowHealthSummary(client,
			lbBMIValue,
			lbStatusValue,
			lbBMRValue,
			lbTDEEValue,
			lbProteinValue,
			lbCarbsValue,
			lbFatsValue,
			chartMacros
			);
	
	}
private: System::Void bLog_Measurments_Click(System::Object^ sender, System::EventArgs^ e) {
	LOGmeasurment->BringToFront();
	ShowLastMeasurement();
	if (client->numMeasurements > 0) {
		tB_height->Visible = false;
		lbl_height->Visible = false;
	}
	else {
		tB_height->Visible = true;
		lbl_height->Visible = true;
	}
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	
	LogMeasurement(); 
	if (client->numMeasurements > 0) {
		tB_height->Visible = false;
		lbl_height->Visible = false;
	}
	else {
		tB_height->Visible = true;
		lbl_height->Visible = true;
	}
}
private: System::Void bLogCompletedWorkout_Click(System::Object^ sender, System::EventArgs^ e) {
	LOGcomworkout->BringToFront();
	ViewWorkouts(client, WORKOUTS);

}
	
private: System::Void bViewWorkouts_Click(System::Object^ sender, System::EventArgs^ e) {

	VIEWworkouts->BringToFront();
	ViewWorkouts(client, listViewWorkouts);
}
private: System::Void LOGO_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void bt_Logw_Click(System::Object^ sender, System::EventArgs^ e) {
	
	if (client == nullptr) {
		MessageBox::Show("Client data not loaded.", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (String::IsNullOrWhiteSpace(txtWorkoutNumber->Text)) {
		MessageBox::Show("Please enter a workout number.", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	int log;
	if (!Int32::TryParse(txtWorkoutNumber->Text, log)) {
		MessageBox::Show("Please enter a valid number.", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (log < 1 || log > client->numWorkouts) {
		MessageBox::Show(String::Format("Invalid workout number. Please enter between 1 and {0}.", client->numWorkouts),
			"Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}

	if (client->workoutPlans[log - 1].istrue == "Done") {
		MessageBox::Show("This workout has been done before. Choose another one.",
			"Information",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
		return;
	}

	try {
		// Update client data
		client->progressLogs[client->numLogs++] = client->workoutPlans[log - 1].workoutName;
		client->workoutPlans[log - 1].istrue = "Done";

		// Update database
		updateClientProgressLogs(db, client->clientID, joinLogs(client->progressLogs, client->numLogs));
		updatetheworkoutstatus(db, client->workoutPlans[log - 1].workoutID);

		// Refresh UI
		LogWorkout(client, listViewWorkouts, lblStatus, txtWorkoutNumber, bt_Logw);
		MessageBox::Show("Workout logged successfully!", "Success",
			MessageBoxButtons::OK, MessageBoxIcon::Information);
	}
	catch (Exception^ ex) {
		MessageBox::Show("An error occurred: " + ex->Message, "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
	ViewWorkouts(client, WORKOUTS);
}

private: System::Void lbFatsValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblCarbsValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pbBMI_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void lblBMIValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblStatusValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblBMRValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbStatusValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lbTDEEValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void dataGridView1_CellContentClick_1(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
private: System::Void lbl_date_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void groupBox1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblBMIValue_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblBMRValue_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void lblProteinValue_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void chartMacros_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void listViewWorkouts_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
}
};
}
