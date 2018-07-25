#pragma once

#include "RayCasting.h"
#include "AngelMethodHeader.h"
#include "BadouelTriangle.h"

#include <iostream>
#include <chrono>
#include <string>
#include <msclr\marshal_cppstd.h>

using namespace std;
using namespace System;
using namespace System::Windows::Forms;
using  ns = chrono::nanoseconds;
using get_time = chrono::steady_clock;

namespace Project1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;

	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:
		MyForm2()
		{

			InitializeComponent();
		}

	protected:
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}

	public: System::Windows::Forms::TextBox^  textBoxLat;
	public: System::Windows::Forms::TextBox^  textBoxLong;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  buttonCalculate;
	private: System::ComponentModel::Container ^components;
	private: System::Windows::Forms::Label^  labelResult;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog;
	private: System::Windows::Forms::Label^  fileNameLabel;
	private: System::Windows::Forms::RadioButton^  radioButtonRayCasting;
	private: System::Windows::Forms::RadioButton^  radioButtonSubAng;

	private: System::Windows::Forms::Label^  labelExTime;
	private: System::Windows::Forms::Label^  labelShowExTime;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::RadioButton^  TriangleAlgorithmRbutton;
	private: System::Windows::Forms::TextBox^  messageBox;

#pragma region Windows Form Designer generated code
			 void InitializeComponent(void)
			 {
				 System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm2::typeid));
				 this->textBoxLat = (gcnew System::Windows::Forms::TextBox());
				 this->textBoxLong = (gcnew System::Windows::Forms::TextBox());
				 this->label1 = (gcnew System::Windows::Forms::Label());
				 this->label2 = (gcnew System::Windows::Forms::Label());
				 this->label3 = (gcnew System::Windows::Forms::Label());
				 this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
				 this->buttonCalculate = (gcnew System::Windows::Forms::Button());
				 this->messageBox = (gcnew System::Windows::Forms::TextBox());
				 this->labelResult = (gcnew System::Windows::Forms::Label());
				 this->label4 = (gcnew System::Windows::Forms::Label());
				 this->button1 = (gcnew System::Windows::Forms::Button());
				 this->openFileDialog = (gcnew System::Windows::Forms::OpenFileDialog());
				 this->fileNameLabel = (gcnew System::Windows::Forms::Label());
				 this->radioButtonRayCasting = (gcnew System::Windows::Forms::RadioButton());
				 this->radioButtonSubAng = (gcnew System::Windows::Forms::RadioButton());
				 this->labelExTime = (gcnew System::Windows::Forms::Label());
				 this->labelShowExTime = (gcnew System::Windows::Forms::Label());
				 this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
				 this->TriangleAlgorithmRbutton = (gcnew System::Windows::Forms::RadioButton());
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
				 this->groupBox1->SuspendLayout();
				 this->SuspendLayout();
				 // 
				 // textBoxLat
				 // 
				 this->textBoxLat->Location = System::Drawing::Point(90, 178);
				 this->textBoxLat->Name = L"textBoxLat";
				 this->textBoxLat->Size = System::Drawing::Size(141, 20);
				 this->textBoxLat->TabIndex = 0;
				 this->textBoxLat->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBox1_TextChanged);
				 // 
				 // textBoxLong
				 // 
				 this->textBoxLong->Location = System::Drawing::Point(90, 208);
				 this->textBoxLong->Name = L"textBoxLong";
				 this->textBoxLong->Size = System::Drawing::Size(141, 20);
				 this->textBoxLong->TabIndex = 1;
				 this->textBoxLong->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBox2_TextChanged);
				 // 
				 // label1
				 // 
				 this->label1->AutoSize = true;
				 this->label1->Location = System::Drawing::Point(87, 143);
				 this->label1->Name = L"label1";
				 this->label1->Size = System::Drawing::Size(144, 13);
				 this->label1->TabIndex = 2;
				 this->label1->Text = L"Enter Latitude and Longitude";
				 this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 this->label1->Click += gcnew System::EventHandler(this, &MyForm2::label1_Click);
				 // 
				 // label2
				 // 
				 this->label2->AutoSize = true;
				 this->label2->Location = System::Drawing::Point(21, 181);
				 this->label2->Name = L"label2";
				 this->label2->Size = System::Drawing::Size(45, 13);
				 this->label2->TabIndex = 3;
				 this->label2->Text = L"Latitude";
				 // 
				 // label3
				 // 
				 this->label3->AutoSize = true;
				 this->label3->Location = System::Drawing::Point(21, 211);
				 this->label3->Name = L"label3";
				 this->label3->Size = System::Drawing::Size(54, 13);
				 this->label3->TabIndex = 4;
				 this->label3->Text = L"Longitude";
				 this->label3->Click += gcnew System::EventHandler(this, &MyForm2::label3_Click);
				 // 
				 // pictureBox1
				 // 
				 this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
				 this->pictureBox1->Location = System::Drawing::Point(1, 0);
				 this->pictureBox1->Name = L"pictureBox1";
				 this->pictureBox1->Size = System::Drawing::Size(554, 118);
				 this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
				 this->pictureBox1->TabIndex = 5;
				 this->pictureBox1->TabStop = false;
				 this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm2::pictureBox1_Click_1);
				 // 
				 // buttonCalculate
				 // 
				 this->buttonCalculate->Location = System::Drawing::Point(90, 234);
				 this->buttonCalculate->Name = L"buttonCalculate";
				 this->buttonCalculate->Size = System::Drawing::Size(141, 23);
				 this->buttonCalculate->TabIndex = 6;
				 this->buttonCalculate->Text = L"Calculate";
				 this->buttonCalculate->UseVisualStyleBackColor = true;
				 this->buttonCalculate->Click += gcnew System::EventHandler(this, &MyForm2::buttonCalculate_Click);
				 // 
				 // messageBox
				 // 
				 this->messageBox->Location = System::Drawing::Point(90, 281);
				 this->messageBox->Name = L"messageBox";
				 this->messageBox->Size = System::Drawing::Size(141, 20);
				 this->messageBox->TabIndex = 7;
				 this->messageBox->TextChanged += gcnew System::EventHandler(this, &MyForm2::messageBox_TextChanged);
				 // 
				 // labelResult
				 // 
				 this->labelResult->AutoSize = true;
				 this->labelResult->Location = System::Drawing::Point(21, 284);
				 this->labelResult->Name = L"labelResult";
				 this->labelResult->Size = System::Drawing::Size(37, 13);
				 this->labelResult->TabIndex = 8;
				 this->labelResult->Text = L"Result";
				 // 
				 // label4
				 // 
				 this->label4->AutoSize = true;
				 this->label4->Location = System::Drawing::Point(311, 181);
				 this->label4->Name = L"label4";
				 this->label4->Size = System::Drawing::Size(83, 13);
				 this->label4->TabIndex = 9;
				 this->label4->Text = L"Select  CSV File";
				 this->label4->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
				 // 
				 // button1
				 // 
				 this->button1->Location = System::Drawing::Point(416, 174);
				 this->button1->Name = L"button1";
				 this->button1->Size = System::Drawing::Size(99, 27);
				 this->button1->TabIndex = 10;
				 this->button1->Text = L"Select";
				 this->button1->UseVisualStyleBackColor = true;
				 this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
				 // 
				 // openFileDialog
				 // 
				 this->openFileDialog->DefaultExt = L"*.csv";
				 this->openFileDialog->FileName = L"openFileDialog";
				 this->openFileDialog->Filter = L"csv files (*.csv)|*.csv";
				 this->openFileDialog->FilterIndex = 2;
				 this->openFileDialog->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &MyForm2::openFileDialog_FileOk);
				 // 
				 // fileNameLabel
				 // 
				 this->fileNameLabel->Location = System::Drawing::Point(311, 211);
				 this->fileNameLabel->Name = L"fileNameLabel";
				 this->fileNameLabel->Size = System::Drawing::Size(200, 13);
				 this->fileNameLabel->TabIndex = 2;
				 this->fileNameLabel->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
				 this->fileNameLabel->Click += gcnew System::EventHandler(this, &MyForm2::label1_Click);
				 // 
				 // radioButtonRayCasting
				 // 
				 this->radioButtonRayCasting->AutoSize = true;
				 this->radioButtonRayCasting->Location = System::Drawing::Point(17, 27);
				 this->radioButtonRayCasting->Name = L"radioButtonRayCasting";
				 this->radioButtonRayCasting->Size = System::Drawing::Size(128, 17);
				 this->radioButtonRayCasting->TabIndex = 11;
				 this->radioButtonRayCasting->TabStop = true;
				 this->radioButtonRayCasting->Text = L"Ray Casting Algorithm";
				 this->radioButtonRayCasting->UseVisualStyleBackColor = true;
				 this->radioButtonRayCasting->CheckedChanged += gcnew System::EventHandler(this, &MyForm2::radioButtonRayCasting_CheckedChanged);
				 // 
				 // radioButtonSubAng
				 // 
				 this->radioButtonSubAng->AutoSize = true;
				 this->radioButtonSubAng->Location = System::Drawing::Point(17, 50);
				 this->radioButtonSubAng->Name = L"radioButtonSubAng";
				 this->radioButtonSubAng->Size = System::Drawing::Size(120, 17);
				 this->radioButtonSubAng->TabIndex = 11;
				 this->radioButtonSubAng->TabStop = true;
				 this->radioButtonSubAng->Text = L"Sum-Angle Algorithm";
				 this->radioButtonSubAng->UseVisualStyleBackColor = true;
				 this->radioButtonSubAng->CheckedChanged += gcnew System::EventHandler(this, &MyForm2::radioButtonSubAng_CheckedChanged);
				 // 
				 // labelExTime
				 // 
				 this->labelExTime->AutoSize = true;
				 this->labelExTime->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
					 static_cast<System::Byte>(162)));
				 this->labelExTime->Location = System::Drawing::Point(21, 326);
				 this->labelExTime->Name = L"labelExTime";
				 this->labelExTime->Size = System::Drawing::Size(94, 13);
				 this->labelExTime->TabIndex = 4;
				 this->labelExTime->Text = L"Execution Time";
				 this->labelExTime->Click += gcnew System::EventHandler(this, &MyForm2::label3_Click);
				 // 
				 // labelShowExTime
				 // 
				 this->labelShowExTime->AutoSize = true;
				 this->labelShowExTime->BackColor = System::Drawing::SystemColors::Control;
				 this->labelShowExTime->Location = System::Drawing::Point(121, 326);
				 this->labelShowExTime->Name = L"labelShowExTime";
				 this->labelShowExTime->Size = System::Drawing::Size(0, 13);
				 this->labelShowExTime->TabIndex = 4;
				 this->labelShowExTime->Click += gcnew System::EventHandler(this, &MyForm2::label3_Click);
				 // 
				 // groupBox1
				 // 
				 this->groupBox1->Controls->Add(this->TriangleAlgorithmRbutton);
				 this->groupBox1->Controls->Add(this->radioButtonSubAng);
				 this->groupBox1->Controls->Add(this->radioButtonRayCasting);
				 this->groupBox1->Location = System::Drawing::Point(314, 251);
				 this->groupBox1->Name = L"groupBox1";
				 this->groupBox1->Size = System::Drawing::Size(208, 117);
				 this->groupBox1->TabIndex = 12;
				 this->groupBox1->TabStop = false;
				 this->groupBox1->Text = L"Algorithms";
				 // 
				 // TriangleAlgorithmRbutton
				 // 
				 this->TriangleAlgorithmRbutton->AutoSize = true;
				 this->TriangleAlgorithmRbutton->Location = System::Drawing::Point(17, 75);
				 this->TriangleAlgorithmRbutton->Name = L"TriangleAlgorithmRbutton";
				 this->TriangleAlgorithmRbutton->Size = System::Drawing::Size(151, 17);
				 this->TriangleAlgorithmRbutton->TabIndex = 11;
				 this->TriangleAlgorithmRbutton->TabStop = true;
				 this->TriangleAlgorithmRbutton->Text = L"Badouel Triangle Algorithm";
				 this->TriangleAlgorithmRbutton->UseVisualStyleBackColor = true;
				 this->TriangleAlgorithmRbutton->CheckedChanged += gcnew System::EventHandler(this, &MyForm2::radioButtonSubAng_CheckedChanged);
				 // 
				 // MyForm2
				 // 
				 this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
				 this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
				 this->ClientSize = System::Drawing::Size(552, 426);
				 this->Controls->Add(this->groupBox1);
				 this->Controls->Add(this->button1);
				 this->Controls->Add(this->label4);
				 this->Controls->Add(this->labelResult);
				 this->Controls->Add(this->messageBox);
				 this->Controls->Add(this->buttonCalculate);
				 this->Controls->Add(this->pictureBox1);
				 this->Controls->Add(this->labelShowExTime);
				 this->Controls->Add(this->labelExTime);
				 this->Controls->Add(this->label3);
				 this->Controls->Add(this->label2);
				 this->Controls->Add(this->fileNameLabel);
				 this->Controls->Add(this->label1);
				 this->Controls->Add(this->textBoxLong);
				 this->Controls->Add(this->textBoxLat);
				 this->Name = L"MyForm2";
				 this->ShowInTaskbar = false;
				 this->Text = L"Application Test";
				 this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
				 (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
				 this->groupBox1->ResumeLayout(false);
				 this->groupBox1->PerformLayout();
				 this->ResumeLayout(false);
				 this->PerformLayout();

			 }

#pragma endregion
	private: System::Void MyForm2_Load(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void pictureBox1_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void label3_Click(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void pictureBox1_Click_1(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void fontDialog1_Apply(System::Object^  sender, System::EventArgs^  e) {
	}
	private: System::Void messageBox_TextChanged(System::Object^  sender, System::EventArgs^  e) {
	}


	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {

				 /***  Calls fileDialog window  ***/
				 openFileDialog->ShowDialog();
				 fileNameLabel->Text = openFileDialog->SafeFileName + " selected.";

	}

	private: System::Void buttonCalculate_Click(System::Object^  sender, System::EventArgs^  e) {

				 msclr::interop::marshal_context context;
				 std::ifstream fileSource_(context.marshal_as<std::string>(openFileDialog->FileName));

				 if ((textBoxLat->Text != "") && (textBoxLong->Text != "")){
					 if (radioButtonRayCasting->Checked){
						 auto start1 = chrono::high_resolution_clock::now();

						 if (RayCasting::isInside(ReadFile::readFile(fileSource_), Convert::ToDouble(textBoxLat->Text), Convert::ToDouble(textBoxLong->Text))) messageBox->Text = "Inside";
						 else messageBox->Text = "Outside";

						 auto end1 = chrono::high_resolution_clock::now();
						 auto diff1(end1 - start1);
						 labelShowExTime->Text = Convert::ToString((end1 - start1).count());
					 }

					 else if (radioButtonSubAng->Checked) {
						 auto start2 = get_time::now();

						 if (AngelMethodHeader::subOfAngels(ReadFile::readFile(fileSource_), Convert::ToDouble(textBoxLat->Text), Convert::ToDouble(textBoxLong->Text))) messageBox->Text = "Inside";
						 else messageBox->Text = "Outside";

						 auto end2 = get_time::now();
						 auto diff2(end2 - start2);
						 labelShowExTime->Text = Convert::ToString(chrono::duration_cast<ns>(diff2).count());
					 }

					 else if (TriangleAlgorithmRbutton->Checked) {
						 auto start2 = get_time::now();

						 if (BadouelTriangle::BadouelTriangleTest(ReadFile::readFile(fileSource_), Convert::ToDouble(textBoxLat->Text), Convert::ToDouble(textBoxLong->Text))) messageBox->Text = "Inside";
						 else messageBox->Text = "Outside";

						 auto end2 = get_time::now();
						 auto diff2(end2 - start2);
						 labelShowExTime->Text = Convert::ToString(chrono::duration_cast<ns>(diff2).count());
					 }

					 else{
						 messageBox->Text = "Please Fill All Blanks!";
					 }
				 }
				 else{
					 messageBox->Text = "Please Fill All Blanks!";
				 }
	}

	private: System::Void openFileDialog_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e) {
				 OpenFileDialog ofd;
				 ofd.Filter = "csv files (*.csv)|*.csv";
				 ofd.FilterIndex = 2;
				 ofd.CheckFileExists;
				 ofd.CheckPathExists;
	}
	private: System::Void radioButtonSubAng_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
	}
private: System::Void radioButtonRayCasting_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
}
};
}