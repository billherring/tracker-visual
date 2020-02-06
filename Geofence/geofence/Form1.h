#pragma once
#include <cstring>
#include <cstdio>
#include <math.h>       /* sin */
#include <iostream>
#include <fstream>
#include <list>
#include "pack.h"
#include "vertex.h"
#include "stream_in.h"
//#include <algorithm>    // std::stable_sort

const int MAX_ENTRY_SZ = 30;



const int LAT_DATUM = (90U * 100000U * 10U);/* x10 to match google position resolution */
const int LONG_DATUM = (180U * 100000U * 10U);
const int SECONDS_IN_DAY = (24 * 60 * 60);


int Vertex::orderBy = Vertex::ORDER_BY_LATITUDE;


namespace geofence {

//    using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
    using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

    
    
    /// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
            
	        _isFileSelected = false;
	        _fenceIndex = 0;
            fenceAttributeGroup->Visible = false;
            _datePickLocked = false;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}


	protected: 





	private: System::Windows::Forms::OpenFileDialog^  openFile;
	private: System::Windows::Forms::TextBox^  fileName;
	private: System::Windows::Forms::Button^  browseButton;
	private: System::Windows::Forms::Button^  convertButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
        bool _isFileSelected;
        bool _datePickLocked;
        int _fenceIndex;

	private: System::Windows::Forms::Button^  generateButton;
	private: System::Windows::Forms::Button^  viewAttributesButton;
	private: System::Windows::Forms::Button^  writeAttributesButton;






	private: System::Windows::Forms::TextBox^  attributeID;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  attributeFloor;
	private: System::Windows::Forms::TextBox^  attributeCeiling;
	private: System::Windows::Forms::TextBox^  attributeStartDate;
	private: System::Windows::Forms::TextBox^  attributeStopDate;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;








	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  attributeSpeed;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::Label^  label18;







	private: System::Windows::Forms::Label^  label19;
	private: System::Windows::Forms::GroupBox^  fenceAttributeGroup;
	private: System::Windows::Forms::Label^  fenceTotal;

	private: System::Windows::Forms::Label^  label22;
	private: System::Windows::Forms::Label^  fenceNumber;

	private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Button^  viewBackAttributesButton;












private: System::Windows::Forms::Button^  resetSpeed;
private: System::Windows::Forms::Button^  resetStopDate;
private: System::Windows::Forms::Button^  resetStartDate;
private: System::Windows::Forms::Button^  resetCeiling;
private: System::Windows::Forms::Button^  resetFloor;

private: System::Windows::Forms::DateTimePicker^  startDataPicker;
private: System::Windows::Forms::DateTimePicker^  stopDatePicker;
private: System::Windows::Forms::ComboBox^  attributeSbdTx;
private: System::Windows::Forms::ComboBox^  attributeSlowCellBurstTx;
private: System::Windows::Forms::ComboBox^  attributeSlowCellBurstFix;
private: System::Windows::Forms::ComboBox^  attributeSlowCellTx;
private: System::Windows::Forms::ComboBox^  attributeSlowSbdBurstTx;
private: System::Windows::Forms::ComboBox^  attributeSlowSbdBurstFix;
private: System::Windows::Forms::ComboBox^  attributeSlowSbdTx;
private: System::Windows::Forms::ComboBox^  attributeCellBurstTx;
private: System::Windows::Forms::ComboBox^  attributeCellBurstFix;
private: System::Windows::Forms::ComboBox^  attributeCellTx;
private: System::Windows::Forms::ComboBox^  attributeSbdBurstTx;
private: System::Windows::Forms::ComboBox^  attributeSbdBurstFix;
private: System::Windows::Forms::DateTimePicker^  startTimePicker;
private: System::Windows::Forms::DateTimePicker^  stopTimePicker;
private: System::Windows::Forms::ComboBox^  attributeBehaviour;











	private: System::Windows::Forms::Label^  status;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fileName = (gcnew System::Windows::Forms::TextBox());
			this->browseButton = (gcnew System::Windows::Forms::Button());
			this->convertButton = (gcnew System::Windows::Forms::Button());
			this->status = (gcnew System::Windows::Forms::Label());
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->viewAttributesButton = (gcnew System::Windows::Forms::Button());
			this->writeAttributesButton = (gcnew System::Windows::Forms::Button());
			this->attributeID = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->attributeFloor = (gcnew System::Windows::Forms::TextBox());
			this->attributeCeiling = (gcnew System::Windows::Forms::TextBox());
			this->attributeStartDate = (gcnew System::Windows::Forms::TextBox());
			this->attributeStopDate = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->attributeSpeed = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->fenceAttributeGroup = (gcnew System::Windows::Forms::GroupBox());
			this->attributeBehaviour = (gcnew System::Windows::Forms::ComboBox());
			this->stopTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->startTimePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->attributeSlowCellBurstTx = (gcnew System::Windows::Forms::ComboBox());
			this->attributeSlowCellBurstFix = (gcnew System::Windows::Forms::ComboBox());
			this->attributeSlowCellTx = (gcnew System::Windows::Forms::ComboBox());
			this->attributeSlowSbdBurstTx = (gcnew System::Windows::Forms::ComboBox());
			this->attributeSlowSbdBurstFix = (gcnew System::Windows::Forms::ComboBox());
			this->attributeSlowSbdTx = (gcnew System::Windows::Forms::ComboBox());
			this->attributeCellBurstTx = (gcnew System::Windows::Forms::ComboBox());
			this->attributeCellBurstFix = (gcnew System::Windows::Forms::ComboBox());
			this->attributeCellTx = (gcnew System::Windows::Forms::ComboBox());
			this->attributeSbdBurstTx = (gcnew System::Windows::Forms::ComboBox());
			this->attributeSbdBurstFix = (gcnew System::Windows::Forms::ComboBox());
			this->attributeSbdTx = (gcnew System::Windows::Forms::ComboBox());
			this->stopDatePicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->startDataPicker = (gcnew System::Windows::Forms::DateTimePicker());
			this->resetSpeed = (gcnew System::Windows::Forms::Button());
			this->resetStopDate = (gcnew System::Windows::Forms::Button());
			this->resetStartDate = (gcnew System::Windows::Forms::Button());
			this->resetCeiling = (gcnew System::Windows::Forms::Button());
			this->resetFloor = (gcnew System::Windows::Forms::Button());
			this->viewBackAttributesButton = (gcnew System::Windows::Forms::Button());
			this->fenceTotal = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->fenceNumber = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->fenceAttributeGroup->SuspendLayout();
			this->SuspendLayout();
			// 
			// openFile
			// 
			this->openFile->FileName = L"openFileDialog1";
			this->openFile->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFile_FileOk);
			// 
			// fileName
			// 
			this->fileName->Location = System::Drawing::Point(35, 36);
			this->fileName->Name = L"fileName";
			this->fileName->Size = System::Drawing::Size(476, 20);
			this->fileName->TabIndex = 6;
			// 
			// browseButton
			// 
			this->browseButton->Location = System::Drawing::Point(35, 62);
			this->browseButton->Name = L"browseButton";
			this->browseButton->Size = System::Drawing::Size(54, 22);
			this->browseButton->TabIndex = 7;
			this->browseButton->Text = L"Browse";
			this->browseButton->UseVisualStyleBackColor = true;
			this->browseButton->Click += gcnew System::EventHandler(this, &Form1::browseButton_Click);
			// 
			// convertButton
			// 
			this->convertButton->Location = System::Drawing::Point(530, 36);
			this->convertButton->Name = L"convertButton";
			this->convertButton->Size = System::Drawing::Size(118, 22);
			this->convertButton->TabIndex = 8;
			this->convertButton->Text = L"Convert CSV to BIN";
			this->convertButton->UseVisualStyleBackColor = true;
			this->convertButton->Click += gcnew System::EventHandler(this, &Form1::convertButton_Click);
			// 
			// status
			// 
			this->status->AutoSize = true;
			this->status->Location = System::Drawing::Point(672, 36);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(38, 13);
			this->status->TabIndex = 9;
			this->status->Text = L"Ready";
			// 
			// generateButton
			// 
			this->generateButton->Location = System::Drawing::Point(530, 74);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(118, 22);
			this->generateButton->TabIndex = 11;
			this->generateButton->Text = L"Test CSV Generation";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &Form1::generateButton_Click);
			// 
			// viewAttributesButton
			// 
			this->viewAttributesButton->Location = System::Drawing::Point(355, 13);
			this->viewAttributesButton->Name = L"viewAttributesButton";
			this->viewAttributesButton->Size = System::Drawing::Size(42, 24);
			this->viewAttributesButton->TabIndex = 12;
			this->viewAttributesButton->Text = L">>";
			this->viewAttributesButton->UseVisualStyleBackColor = true;
			this->viewAttributesButton->Click += gcnew System::EventHandler(this, &Form1::viewAttributesButton_Click);
			// 
			// writeAttributesButton
			// 
			this->writeAttributesButton->Location = System::Drawing::Point(278, 384);
			this->writeAttributesButton->Name = L"writeAttributesButton";
			this->writeAttributesButton->Size = System::Drawing::Size(110, 24);
			this->writeAttributesButton->TabIndex = 13;
			this->writeAttributesButton->Text = L"Update This Fence";
			this->writeAttributesButton->UseVisualStyleBackColor = true;
			this->writeAttributesButton->Click += gcnew System::EventHandler(this, &Form1::writeAttributesButton_Click);
			// 
			// attributeID
			// 
			this->attributeID->Location = System::Drawing::Point(105, 61);
			this->attributeID->Name = L"attributeID";
			this->attributeID->Size = System::Drawing::Size(85, 20);
			this->attributeID->TabIndex = 14;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(72, 61);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 15;
			this->label1->Text = L"ID";
			// 
			// attributeFloor
			// 
			this->attributeFloor->Location = System::Drawing::Point(105, 117);
			this->attributeFloor->Name = L"attributeFloor";
			this->attributeFloor->Size = System::Drawing::Size(85, 20);
			this->attributeFloor->TabIndex = 16;
			// 
			// attributeCeiling
			// 
			this->attributeCeiling->Location = System::Drawing::Point(105, 143);
			this->attributeCeiling->Name = L"attributeCeiling";
			this->attributeCeiling->Size = System::Drawing::Size(85, 20);
			this->attributeCeiling->TabIndex = 17;
			// 
			// attributeStartDate
			// 
			this->attributeStartDate->Location = System::Drawing::Point(105, 266);
			this->attributeStartDate->Name = L"attributeStartDate";
			this->attributeStartDate->ReadOnly = true;
			this->attributeStartDate->Size = System::Drawing::Size(84, 20);
			this->attributeStartDate->TabIndex = 18;
			// 
			// attributeStopDate
			// 
			this->attributeStopDate->Location = System::Drawing::Point(105, 348);
			this->attributeStopDate->Name = L"attributeStopDate";
			this->attributeStopDate->ReadOnly = true;
			this->attributeStopDate->Size = System::Drawing::Size(84, 20);
			this->attributeStopDate->TabIndex = 19;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(20, 117);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Floor (meters)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 143);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Ceiling (metres)";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(60, 216);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(29, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Start";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(61, 301);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(29, 13);
			this->label5->TabIndex = 24;
			this->label5->Text = L"Stop";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 170);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(83, 13);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Slow (kn tenths)";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(273, 65);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(46, 13);
			this->label7->TabIndex = 32;
			this->label7->Text = L"SBD TX";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(247, 90);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(72, 13);
			this->label8->TabIndex = 33;
			this->label8->Text = L"SBD Burst Fix";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(246, 112);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(73, 13);
			this->label9->TabIndex = 34;
			this->label9->Text = L"SBD Burst TX";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(278, 136);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(41, 13);
			this->label10->TabIndex = 35;
			this->label10->Text = L"Cell TX";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(252, 162);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(67, 13);
			this->label11->TabIndex = 36;
			this->label11->Text = L"Cell Burst Fix";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(251, 188);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(68, 13);
			this->label12->TabIndex = 37;
			this->label12->Text = L"Cell Burst TX";
			// 
			// attributeSpeed
			// 
			this->attributeSpeed->Location = System::Drawing::Point(105, 170);
			this->attributeSpeed->Name = L"attributeSpeed";
			this->attributeSpeed->Size = System::Drawing::Size(85, 20);
			this->attributeSpeed->TabIndex = 38;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(475, 189);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(94, 13);
			this->label13->TabIndex = 50;
			this->label13->Text = L"Slow Cell Burst TX";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(476, 163);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(93, 13);
			this->label14->TabIndex = 49;
			this->label14->Text = L"Slow Cell Burst Fix";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(502, 137);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(67, 13);
			this->label15->TabIndex = 48;
			this->label15->Text = L"Slow Cell TX";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(470, 113);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(99, 13);
			this->label16->TabIndex = 47;
			this->label16->Text = L"Slow SBD Burst TX";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(471, 91);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(98, 13);
			this->label17->TabIndex = 46;
			this->label17->Text = L"Slow SBD Burst Fix";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(497, 66);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(72, 13);
			this->label18->TabIndex = 45;
			this->label18->Text = L"Slow SBD TX";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(35, 88);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(55, 13);
			this->label19->TabIndex = 52;
			this->label19->Text = L"Behaviour";
			// 
			// fenceAttributeGroup
			// 
			this->fenceAttributeGroup->Controls->Add(this->attributeBehaviour);
			this->fenceAttributeGroup->Controls->Add(this->stopTimePicker);
			this->fenceAttributeGroup->Controls->Add(this->startTimePicker);
			this->fenceAttributeGroup->Controls->Add(this->attributeSlowCellBurstTx);
			this->fenceAttributeGroup->Controls->Add(this->attributeSlowCellBurstFix);
			this->fenceAttributeGroup->Controls->Add(this->attributeSlowCellTx);
			this->fenceAttributeGroup->Controls->Add(this->attributeSlowSbdBurstTx);
			this->fenceAttributeGroup->Controls->Add(this->attributeSlowSbdBurstFix);
			this->fenceAttributeGroup->Controls->Add(this->attributeSlowSbdTx);
			this->fenceAttributeGroup->Controls->Add(this->attributeCellBurstTx);
			this->fenceAttributeGroup->Controls->Add(this->attributeCellBurstFix);
			this->fenceAttributeGroup->Controls->Add(this->attributeCellTx);
			this->fenceAttributeGroup->Controls->Add(this->attributeSbdBurstTx);
			this->fenceAttributeGroup->Controls->Add(this->attributeSbdBurstFix);
			this->fenceAttributeGroup->Controls->Add(this->attributeSbdTx);
			this->fenceAttributeGroup->Controls->Add(this->stopDatePicker);
			this->fenceAttributeGroup->Controls->Add(this->startDataPicker);
			this->fenceAttributeGroup->Controls->Add(this->attributeStartDate);
			this->fenceAttributeGroup->Controls->Add(this->resetSpeed);
			this->fenceAttributeGroup->Controls->Add(this->resetStopDate);
			this->fenceAttributeGroup->Controls->Add(this->resetStartDate);
			this->fenceAttributeGroup->Controls->Add(this->resetCeiling);
			this->fenceAttributeGroup->Controls->Add(this->resetFloor);
			this->fenceAttributeGroup->Controls->Add(this->viewBackAttributesButton);
			this->fenceAttributeGroup->Controls->Add(this->fenceTotal);
			this->fenceAttributeGroup->Controls->Add(this->label22);
			this->fenceAttributeGroup->Controls->Add(this->fenceNumber);
			this->fenceAttributeGroup->Controls->Add(this->label20);
			this->fenceAttributeGroup->Controls->Add(this->label19);
			this->fenceAttributeGroup->Controls->Add(this->label13);
			this->fenceAttributeGroup->Controls->Add(this->label14);
			this->fenceAttributeGroup->Controls->Add(this->label15);
			this->fenceAttributeGroup->Controls->Add(this->label16);
			this->fenceAttributeGroup->Controls->Add(this->label17);
			this->fenceAttributeGroup->Controls->Add(this->label18);
			this->fenceAttributeGroup->Controls->Add(this->attributeSpeed);
			this->fenceAttributeGroup->Controls->Add(this->label12);
			this->fenceAttributeGroup->Controls->Add(this->label11);
			this->fenceAttributeGroup->Controls->Add(this->label10);
			this->fenceAttributeGroup->Controls->Add(this->label9);
			this->fenceAttributeGroup->Controls->Add(this->label8);
			this->fenceAttributeGroup->Controls->Add(this->label7);
			this->fenceAttributeGroup->Controls->Add(this->label6);
			this->fenceAttributeGroup->Controls->Add(this->label5);
			this->fenceAttributeGroup->Controls->Add(this->label4);
			this->fenceAttributeGroup->Controls->Add(this->label3);
			this->fenceAttributeGroup->Controls->Add(this->label2);
			this->fenceAttributeGroup->Controls->Add(this->attributeStopDate);
			this->fenceAttributeGroup->Controls->Add(this->attributeCeiling);
			this->fenceAttributeGroup->Controls->Add(this->attributeFloor);
			this->fenceAttributeGroup->Controls->Add(this->label1);
			this->fenceAttributeGroup->Controls->Add(this->attributeID);
			this->fenceAttributeGroup->Controls->Add(this->writeAttributesButton);
			this->fenceAttributeGroup->Controls->Add(this->viewAttributesButton);
			this->fenceAttributeGroup->Location = System::Drawing::Point(35, 128);
			this->fenceAttributeGroup->Name = L"fenceAttributeGroup";
			this->fenceAttributeGroup->Size = System::Drawing::Size(699, 436);
			this->fenceAttributeGroup->TabIndex = 53;
			this->fenceAttributeGroup->TabStop = false;
			this->fenceAttributeGroup->Text = L"Fence Attributes";
			// 
			// attributeBehaviour
			// 
			this->attributeBehaviour->FormattingEnabled = true;
			this->attributeBehaviour->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Entry+Exit", L"Entry", L"Exit", L"Entry+Disable",
					L"None"
			});
			this->attributeBehaviour->Location = System::Drawing::Point(105, 88);
			this->attributeBehaviour->Name = L"attributeBehaviour";
			this->attributeBehaviour->Size = System::Drawing::Size(85, 21);
			this->attributeBehaviour->TabIndex = 91;
			// 
			// stopTimePicker
			// 
			this->stopTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->stopTimePicker->Location = System::Drawing::Point(105, 325);
			this->stopTimePicker->Name = L"stopTimePicker";
			this->stopTimePicker->ShowUpDown = true;
			this->stopTimePicker->Size = System::Drawing::Size(84, 20);
			this->stopTimePicker->TabIndex = 90;
			this->stopTimePicker->ValueChanged += gcnew System::EventHandler(this, &Form1::stopTimePicker_ValueChanged);
			// 
			// startTimePicker
			// 
			this->startTimePicker->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->startTimePicker->Location = System::Drawing::Point(105, 241);
			this->startTimePicker->Name = L"startTimePicker";
			this->startTimePicker->ShowUpDown = true;
			this->startTimePicker->Size = System::Drawing::Size(84, 20);
			this->startTimePicker->TabIndex = 89;
			this->startTimePicker->ValueChanged += gcnew System::EventHandler(this, &Form1::startTimePicker_ValueChanged);
			// 
			// attributeSlowCellBurstTx
			// 
			this->attributeSlowCellBurstTx->FormattingEnabled = true;
			this->attributeSlowCellBurstTx->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"1 min", L"2 min", L"5 min", L"10 min",
					L"15 min", L"30 min", L"60 min", L"NOT SET"
			});
			this->attributeSlowCellBurstTx->Location = System::Drawing::Point(578, 185);
			this->attributeSlowCellBurstTx->Name = L"attributeSlowCellBurstTx";
			this->attributeSlowCellBurstTx->Size = System::Drawing::Size(75, 21);
			this->attributeSlowCellBurstTx->TabIndex = 88;
			// 
			// attributeSlowCellBurstFix
			// 
			this->attributeSlowCellBurstFix->FormattingEnabled = true;
			this->attributeSlowCellBurstFix->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"5 secs", L"10 secs", L"15 secs",
					L"20 secs", L"30 secs", L"1 min", L"2 min", L"5 min", L"10 min", L"15 min", L"20 min", L"NOT SET"
			});
			this->attributeSlowCellBurstFix->Location = System::Drawing::Point(578, 159);
			this->attributeSlowCellBurstFix->Name = L"attributeSlowCellBurstFix";
			this->attributeSlowCellBurstFix->Size = System::Drawing::Size(75, 21);
			this->attributeSlowCellBurstFix->TabIndex = 87;
			// 
			// attributeSlowCellTx
			// 
			this->attributeSlowCellTx->FormattingEnabled = true;
			this->attributeSlowCellTx->Items->AddRange(gcnew cli::array< System::Object^  >(26) {
				L"Continuous", L"5 min", L"10 min", L"15 min",
					L"20 min", L"30 min", L"1 hour", L"90 min", L"2 hour", L"3 hour", L"4 hour", L"6 hour", L"8 hour", L"12 hour", L"Burst", L"1 min",
					L"2 min", L"3 min", L"4 min", L"24 hour", L"6 min", L"8 min", L"12 min", L"15 sec", L"30 sec", L"NOT SET"
			});
			this->attributeSlowCellTx->Location = System::Drawing::Point(578, 133);
			this->attributeSlowCellTx->Name = L"attributeSlowCellTx";
			this->attributeSlowCellTx->Size = System::Drawing::Size(75, 21);
			this->attributeSlowCellTx->TabIndex = 86;
			// 
			// attributeSlowSbdBurstTx
			// 
			this->attributeSlowSbdBurstTx->FormattingEnabled = true;
			this->attributeSlowSbdBurstTx->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"1 min", L"2 min", L"5 min", L"10 min",
					L"15 min", L"30 min", L"60 min", L"NOT SET"
			});
			this->attributeSlowSbdBurstTx->Location = System::Drawing::Point(578, 109);
			this->attributeSlowSbdBurstTx->Name = L"attributeSlowSbdBurstTx";
			this->attributeSlowSbdBurstTx->Size = System::Drawing::Size(75, 21);
			this->attributeSlowSbdBurstTx->TabIndex = 85;
			// 
			// attributeSlowSbdBurstFix
			// 
			this->attributeSlowSbdBurstFix->FormattingEnabled = true;
			this->attributeSlowSbdBurstFix->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"5 secs", L"10 secs", L"15 secs",
					L"20 secs", L"30 secs", L"1 min", L"2 min", L"5 min", L"10 min", L"15 min", L"20 min", L"NOT SET"
			});
			this->attributeSlowSbdBurstFix->Location = System::Drawing::Point(578, 85);
			this->attributeSlowSbdBurstFix->Name = L"attributeSlowSbdBurstFix";
			this->attributeSlowSbdBurstFix->Size = System::Drawing::Size(75, 21);
			this->attributeSlowSbdBurstFix->TabIndex = 84;
			// 
			// attributeSlowSbdTx
			// 
			this->attributeSlowSbdTx->FormattingEnabled = true;
			this->attributeSlowSbdTx->Items->AddRange(gcnew cli::array< System::Object^  >(26) {
				L"Continuous", L"5 min", L"10 min", L"15 min",
					L"20 min", L"30 min", L"1 hour", L"90 min", L"2 hour", L"3 hour", L"4 hour", L"6 hour", L"8 hour", L"12 hour", L"Burst", L"1 min",
					L"2 min", L"3 min", L"4 min", L"24 hour", L"6 min", L"8 min", L"12 min", L"15 sec", L"30 sec", L"NOT SET"
			});
			this->attributeSlowSbdTx->Location = System::Drawing::Point(578, 61);
			this->attributeSlowSbdTx->Name = L"attributeSlowSbdTx";
			this->attributeSlowSbdTx->Size = System::Drawing::Size(75, 21);
			this->attributeSlowSbdTx->TabIndex = 83;
			// 
			// attributeCellBurstTx
			// 
			this->attributeCellBurstTx->FormattingEnabled = true;
			this->attributeCellBurstTx->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"1 min", L"2 min", L"5 min", L"10 min",
					L"15 min", L"30 min", L"60 min", L"NOT SET"
			});
			this->attributeCellBurstTx->Location = System::Drawing::Point(332, 186);
			this->attributeCellBurstTx->Name = L"attributeCellBurstTx";
			this->attributeCellBurstTx->Size = System::Drawing::Size(75, 21);
			this->attributeCellBurstTx->TabIndex = 82;
			// 
			// attributeCellBurstFix
			// 
			this->attributeCellBurstFix->FormattingEnabled = true;
			this->attributeCellBurstFix->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"5 secs", L"10 secs", L"15 secs",
					L"20 secs", L"30 secs", L"1 min", L"2 min", L"5 min", L"10 min", L"15 min", L"20 min", L"NOT SET"
			});
			this->attributeCellBurstFix->Location = System::Drawing::Point(332, 159);
			this->attributeCellBurstFix->Name = L"attributeCellBurstFix";
			this->attributeCellBurstFix->Size = System::Drawing::Size(75, 21);
			this->attributeCellBurstFix->TabIndex = 81;
			// 
			// attributeCellTx
			// 
			this->attributeCellTx->FormattingEnabled = true;
			this->attributeCellTx->Items->AddRange(gcnew cli::array< System::Object^  >(26) {
				L"Continuous", L"5 min", L"10 min", L"15 min",
					L"20 min", L"30 min", L"1 hour", L"90 min", L"2 hour", L"3 hour", L"4 hour", L"6 hour", L"8 hour", L"12 hour", L"Burst", L"1 min",
					L"2 min", L"3 min", L"4 min", L"24 hour", L"6 min", L"8 min", L"12 min", L"15 sec", L"30 sec", L"NOT SET"
			});
			this->attributeCellTx->Location = System::Drawing::Point(332, 133);
			this->attributeCellTx->Name = L"attributeCellTx";
			this->attributeCellTx->Size = System::Drawing::Size(75, 21);
			this->attributeCellTx->TabIndex = 80;
			// 
			// attributeSbdBurstTx
			// 
			this->attributeSbdBurstTx->FormattingEnabled = true;
			this->attributeSbdBurstTx->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"1 min", L"2 min", L"5 min", L"10 min",
					L"15 min", L"30 min", L"60 min", L"NOT SET"
			});
			this->attributeSbdBurstTx->Location = System::Drawing::Point(332, 109);
			this->attributeSbdBurstTx->Name = L"attributeSbdBurstTx";
			this->attributeSbdBurstTx->Size = System::Drawing::Size(75, 21);
			this->attributeSbdBurstTx->TabIndex = 79;
			// 
			// attributeSbdBurstFix
			// 
			this->attributeSbdBurstFix->FormattingEnabled = true;
			this->attributeSbdBurstFix->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				L"5 secs", L"10 secs", L"15 secs", L"20 secs",
					L"30 secs", L"1 min", L"2 min", L"5 min", L"10 min", L"15 min", L"20 min", L"NOT SET"
			});
			this->attributeSbdBurstFix->Location = System::Drawing::Point(332, 85);
			this->attributeSbdBurstFix->Name = L"attributeSbdBurstFix";
			this->attributeSbdBurstFix->Size = System::Drawing::Size(75, 21);
			this->attributeSbdBurstFix->TabIndex = 78;
			// 
			// attributeSbdTx
			// 
			this->attributeSbdTx->FormattingEnabled = true;
			this->attributeSbdTx->Items->AddRange(gcnew cli::array< System::Object^  >(26) {
				L"Continuous", L"5 min", L"10 min", L"15 min",
					L"20 min", L"30 min", L"1 hour", L"90 min", L"2 hour", L"3 hour", L"4 hour", L"6 hour", L"8 hour", L"12 hour", L"Burst", L"1 min",
					L"2 min", L"3 min", L"4 min", L"24 hour", L"6 min", L"8 min", L"12 min", L"15 sec", L"30 sec", L"NOT SET"
			});
			this->attributeSbdTx->Location = System::Drawing::Point(332, 60);
			this->attributeSbdTx->Name = L"attributeSbdTx";
			this->attributeSbdTx->Size = System::Drawing::Size(75, 21);
			this->attributeSbdTx->TabIndex = 77;
			// 
			// stopDatePicker
			// 
			this->stopDatePicker->Location = System::Drawing::Point(105, 301);
			this->stopDatePicker->Name = L"stopDatePicker";
			this->stopDatePicker->Size = System::Drawing::Size(120, 20);
			this->stopDatePicker->TabIndex = 76;
			this->stopDatePicker->ValueChanged += gcnew System::EventHandler(this, &Form1::stopDatePicker_ValueChanged);
			// 
			// startDataPicker
			// 
			this->startDataPicker->Location = System::Drawing::Point(105, 216);
			this->startDataPicker->Name = L"startDataPicker";
			this->startDataPicker->Size = System::Drawing::Size(123, 20);
			this->startDataPicker->TabIndex = 54;
			this->startDataPicker->ValueChanged += gcnew System::EventHandler(this, &Form1::startDataPicker_ValueChanged);
			// 
			// resetSpeed
			// 
			this->resetSpeed->Location = System::Drawing::Point(196, 170);
			this->resetSpeed->Name = L"resetSpeed";
			this->resetSpeed->Size = System::Drawing::Size(14, 10);
			this->resetSpeed->TabIndex = 62;
			this->resetSpeed->Text = L"button5";
			this->resetSpeed->UseVisualStyleBackColor = true;
			this->resetSpeed->Click += gcnew System::EventHandler(this, &Form1::resetSpeed_Click);
			// 
			// resetStopDate
			// 
			this->resetStopDate->Location = System::Drawing::Point(196, 348);
			this->resetStopDate->Name = L"resetStopDate";
			this->resetStopDate->Size = System::Drawing::Size(14, 10);
			this->resetStopDate->TabIndex = 61;
			this->resetStopDate->Text = L"button4";
			this->resetStopDate->UseVisualStyleBackColor = true;
			this->resetStopDate->Click += gcnew System::EventHandler(this, &Form1::resetStopDate_Click);
			// 
			// resetStartDate
			// 
			this->resetStartDate->Location = System::Drawing::Point(196, 266);
			this->resetStartDate->Name = L"resetStartDate";
			this->resetStartDate->Size = System::Drawing::Size(14, 10);
			this->resetStartDate->TabIndex = 60;
			this->resetStartDate->Text = L"button3";
			this->resetStartDate->UseVisualStyleBackColor = true;
			this->resetStartDate->Click += gcnew System::EventHandler(this, &Form1::resetStartDate_Click);
			// 
			// resetCeiling
			// 
			this->resetCeiling->Location = System::Drawing::Point(196, 143);
			this->resetCeiling->Name = L"resetCeiling";
			this->resetCeiling->Size = System::Drawing::Size(14, 10);
			this->resetCeiling->TabIndex = 59;
			this->resetCeiling->Text = L"button2";
			this->resetCeiling->UseVisualStyleBackColor = true;
			this->resetCeiling->Click += gcnew System::EventHandler(this, &Form1::resetCeiling_Click);
			// 
			// resetFloor
			// 
			this->resetFloor->Location = System::Drawing::Point(196, 117);
			this->resetFloor->Name = L"resetFloor";
			this->resetFloor->Size = System::Drawing::Size(14, 10);
			this->resetFloor->TabIndex = 58;
			this->resetFloor->Text = L"button1";
			this->resetFloor->UseVisualStyleBackColor = true;
			this->resetFloor->Click += gcnew System::EventHandler(this, &Form1::resetFloor_Click);
			// 
			// viewBackAttributesButton
			// 
			this->viewBackAttributesButton->Location = System::Drawing::Point(325, 13);
			this->viewBackAttributesButton->Name = L"viewBackAttributesButton";
			this->viewBackAttributesButton->Size = System::Drawing::Size(38, 24);
			this->viewBackAttributesButton->TabIndex = 57;
			this->viewBackAttributesButton->Text = L"<<";
			this->viewBackAttributesButton->UseVisualStyleBackColor = true;
			this->viewBackAttributesButton->Click += gcnew System::EventHandler(this, &Form1::viewBackAttributesButton_Click);
			// 
			// fenceTotal
			// 
			this->fenceTotal->AutoSize = true;
			this->fenceTotal->Location = System::Drawing::Point(288, 16);
			this->fenceTotal->Name = L"fenceTotal";
			this->fenceTotal->Size = System::Drawing::Size(31, 13);
			this->fenceTotal->TabIndex = 56;
			this->fenceTotal->Text = L"____";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(275, 16);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(16, 13);
			this->label22->TabIndex = 55;
			this->label22->Text = L"of";
			// 
			// fenceNumber
			// 
			this->fenceNumber->AutoSize = true;
			this->fenceNumber->Location = System::Drawing::Point(252, 16);
			this->fenceNumber->Name = L"fenceNumber";
			this->fenceNumber->Size = System::Drawing::Size(25, 13);
			this->fenceNumber->TabIndex = 54;
			this->fenceNumber->Text = L"___";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(218, 16);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(37, 13);
			this->label20->TabIndex = 53;
			this->label20->Text = L"Fence";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(776, 576);
			this->Controls->Add(this->fenceAttributeGroup);
			this->Controls->Add(this->generateButton);
			this->Controls->Add(this->status);
			this->Controls->Add(this->convertButton);
			this->Controls->Add(this->browseButton);
			this->Controls->Add(this->fileName);
			this->Name = L"Form1";
			this->Text = L"Geofence Generator";
			this->fenceAttributeGroup->ResumeLayout(false);
			this->fenceAttributeGroup->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
    
    const int NO_VERTEX = -1;
    
    
    const int BYTE_1  = 1;  /* 1 bytes */
    const int BYTE_2  = 2;  /* 2 bytes */
    const int BYTE_4  = 4;  /* 4 bytes */
    const int BYTE_8  = 8;  /* 8 bytes */
    const int BYTE_12 = 12; /* 12 bytes */
    const int BYTE_16 = 16; /* 16 bytes */
    const int BYTE_20 = 20; /* 20 bytes */



    const int FENCE_FIXED_PARAMETERS = 100;
    const int FENCE_ID_SZ = BYTE_2;
    const int FENCE_TYPE_SZ = BYTE_1;
    const int FENCE_VERTICES_SZ = BYTE_4;

    const int FENCE_COUNT_SZ = BYTE_2;
    const int FENCE_SIZE_SZ = BYTE_4;
    const int FENCE_INDEX_SZ = BYTE_2;


    const int BOX_BOUNDARY_LATITITUDE_SZ = BYTE_4;
    const int BOX_BOUNDARY_LONGITUDE_SZ = BYTE_4;
    const int NS_FENCE_INDEX_LIST_OFFSET_SZ = BYTE_4;
    const int EW_FENCE_INDEX_LIST_OFFSET_SZ = BYTE_4;


    const int VERTEX_LATITITUDE_SZ = BYTE_4;
    const int VERTEX_BAND_EDGE_LIST_OFFSET_SZ = BYTE_4;
    const int FENCE_ATTRIBUTE_BLOCK_UNUSED_SZ = (FENCE_FIXED_PARAMETERS
                                                            - FENCE_ID_SZ
                                                            - FENCE_TYPE_SZ
                                                            - FENCE_VERTICES_SZ);

    const int VERTEX_FILE_SZ_PER_VERTEX = (VERTEX_LATITITUDE_SZ
                                                    + VERTEX_BAND_EDGE_LIST_OFFSET_SZ);

    const int BOX_FILE_SZ_PER_FENCE = (BOX_BOUNDARY_LATITITUDE_SZ
                                                + BOX_BOUNDARY_LONGITUDE_SZ
                                                + NS_FENCE_INDEX_LIST_OFFSET_SZ
                                                + EW_FENCE_INDEX_LIST_OFFSET_SZ);

    int OFFSET_TO_EDGES( int v )
    {
        return(FENCE_FIXED_PARAMETERS + (VERTEX_FILE_SZ_PER_VERTEX * v));
    }

    int OFFSET_TO_INDEXES( int f )
    {
        return(FENCE_COUNT_SZ + (FENCE_SIZE_SZ * f) + (FENCE_ID_SZ * f)
               + (FENCE_INDEX_SZ * f) + (BOX_FILE_SZ_PER_FENCE * f * 2));
    }

    int OFFSET_TO_BOX_FILE( int f )
    {
        return(FENCE_COUNT_SZ + (FENCE_SIZE_SZ * f) + (FENCE_ID_SZ * f) + (FENCE_INDEX_SZ * f));
    }


    const double MASS_LATITUDE = 51.49600;
    const double MASS_LONGITUDE = -0.13500;
    const double MASS_RADIUS = 10000;
    const int MASS_POINTS = 500;


    private: System::Void openFile_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
    {
        _isFileSelected = true;
        _fenceIndex = 0;
        if (getAttributes())
        {
            fenceAttributeGroup->Visible = true;
        }
        else
        {
            fenceAttributeGroup->Visible = false;
        }
    }

    private: System::Void browseButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
            openFile->Filter = "Apps(*.csv)|*.csv|All Files(*.*)|*.*";
            openFile->ShowDialog();
            if (_isFileSelected == true)
            {
                fileName->Text = openFile->FileName;
            }
            status->Text = "Ready";
    }

    private: System::Void convertButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
	        char longName[100];/* to buffer file names */
            std::fstream fileIn;/* file handle */
            std::fstream fileOut;/* file handle */

            if (_isFileSelected == true)
            {
                int nameSize = openFile->FileName->Length;
                for (int i = 0; i < nameSize; ++i )
                {
                    longName[i] = (char)openFile->FileName[i];
                }
                longName[nameSize] = '\0';
                
                char *ptr = strchr( longName, '.' );
                if (ptr != 0)
                {
                    ++ptr;
                    if (strcmp( ptr, "csv" ) == 0)
                    {
                        StreamIn^ csvFile = gcnew StreamIn( longName );

                        if (csvFile->isOpen() == true)
                        {
        
                            int fenceCount = 0;

                            if (csvFile->size() != 0)
                            {
                                //At this point:-
                                //csvBuffer is a buffer holding all the text read from the csv file.
                                //csvTextSize has the size in characters
                                //csvTextIndex will maintain the position in the buffer as conversion progresses
                                //fenceCount counts fences discovered in file as conversion progresses

                                Pack ^packer = gcnew Pack( "fence_a.bin" );

                                std::list<BoxBoundary> EWBoundaries;
                                std::list<BoxBoundary> NSBoundaries;
                                std::list<FenceSummary> fenceSummaryList;

                                fileOut.open( "poly.def", std::fstream::out | std::fstream::binary | std::fstream::trunc);

                                csvFile->bookmark();//Bookmark the start of initial fence

                                while (csvFile->isEnd() == false)
                                {
                                    Fence fenceMap;

                                    int vertices = 0;

                                    csvFile->setToBookmark();//Set to start of a fence
                                    parse( packer, csvFile, &vertices, &fenceMap );//1st parse (gets vertices)

                                    csvFile->setToBookmark();//Reset to start of the fence
                                    parse( packer, csvFile, &vertices, &fenceMap );//2nd parse (uses vertices)

                                    packer->pad();


                                    //****************** Initial fence header output ***********************

                                    fileWrite( &fileOut, FENCE_ID_SZ, fenceMap.id );

                                    fileWrite( &fileOut, FENCE_TYPE_SZ, fenceMap.behaviour );

                                    /* Filler zeroes for unused fence attributes */
                                    for (int i = 0; i < FENCE_ATTRIBUTE_BLOCK_UNUSED_SZ; ++i)
                                    {
                                        fileWrite( &fileOut, BYTE_1, 0xffU );
                                    }

                                    fileWrite( &fileOut, FENCE_VERTICES_SZ, fenceMap.vertexCount );


                                    //****************** Establish vertex links (edges) ********************

                                    // Assumes they are listed in circular order

                                    std::list<Vertex>::iterator iterVertex = fenceMap.vertices.begin();
                                    std::list<Vertex>::iterator iterVertex2 = fenceMap.vertices.begin();
                                    ++iterVertex2;

                                    while (iterVertex != fenceMap.vertices.end())
                                    {

                                        // Use edge1 if link belongs to 'this' vertex, else it belongs to 'next' (use edge2)
                                        if ((*iterVertex).latitude != (*iterVertex2).latitude)
                                        {
                                            Edge *edgePtr = ((*iterVertex).latitude > (*iterVertex2).latitude) ? &((*iterVertex2).edge2) : &((*iterVertex).edge1);

                                            if ((*iterVertex).longitude >= (*iterVertex2).longitude)
                                            {
                                                edgePtr->west = (*iterVertex2).index;
                                                edgePtr->east = (*iterVertex).index;
                                            }
                                            else
                                            {
                                                edgePtr->west = (*iterVertex).index;
                                                edgePtr->east = (*iterVertex2).index;
                                            }

                                        }
                                        ++iterVertex;
                                        ++iterVertex2;

                                        //Link last back to first
                                        if (iterVertex2 == fenceMap.vertices.end())
                                        {
                                            iterVertex2 = fenceMap.vertices.begin();
                                        }

                                    }


                                    //************** Sort vertices and establish box boundaries ************

                                    BoxBoundary boundary;

                                    // Box boundaries WE
                                    Vertex::orderBy = Vertex::ORDER_BY_LONGITUDE;
                                    fenceMap.vertices.sort();

                                    iterVertex = fenceMap.vertices.begin();
                                    boundary.position = (*iterVertex).longitude;
                                    boundary.index = fenceCount;
                                    EWBoundaries.push_back( boundary );

                                    iterVertex = fenceMap.vertices.end();
                                    --iterVertex;
                                    boundary.position = (*iterVertex).longitude;
                                    boundary.index = fenceCount;
                                    EWBoundaries.push_back( boundary );

                                    // Box boundaries SN
                                    Vertex::orderBy = Vertex::ORDER_BY_LATITUDE;
                                    fenceMap.vertices.sort();


                                    iterVertex = fenceMap.vertices.begin();
                                    boundary.position = (*iterVertex).latitude;
                                    boundary.index = fenceCount;
                                    NSBoundaries.push_back( boundary );

                                    iterVertex = fenceMap.vertices.end();
                                    --iterVertex;
                                    boundary.position = (*iterVertex).latitude;
                                    boundary.index = fenceCount;
                                    NSBoundaries.push_back( boundary );

                                    // Establish a vertex index cross ref between ordered and unordered
                                    int orderedIndex = 0;
                                    iterVertex = fenceMap.vertices.begin();
                                    while (iterVertex != fenceMap.vertices.end())
                                    {
                                        VertexCrossRef crossRef;

                                        fileWrite( &fileOut, BYTE_4, (*iterVertex).latitude );
                                        crossRef.index = (*iterVertex).index;
                                        crossRef.orderedIndex = orderedIndex;
                                        fenceMap.crossRef.push_back( crossRef );
                                        ++iterVertex;
                                        ++orderedIndex;
                                    }
                                    fenceMap.crossRef.sort();



                                    //**** Complete latitude band edges and output latitude ordered list ***

                                    std::list<Edge> runningEdges;

                                    std::list<Edge> edgeBlock;

                                    int edgeOffset = 0;

                                    iterVertex = fenceMap.vertices.begin();
                                    iterVertex2 = iterVertex;

                                    while (iterVertex != fenceMap.vertices.end())
                                    {
                                        std::list<Edge>::iterator iterRunning;
                                        int currentLatitude = (*iterVertex).latitude;
                                        int newLatitude = currentLatitude;

                                        ///////Find next latitude///////////////
                                        std::list<Vertex>::iterator iterVertexStop = iterVertex;
                                        do
                                        {
                                            ++iterVertexStop;

                                            if (iterVertexStop != fenceMap.vertices.end())
                                            {
                                                newLatitude = (*iterVertexStop).latitude;
                                            }
                                            else
                                            {
                                                newLatitude = currentLatitude;
                                            }

                                        } while ((iterVertexStop != fenceMap.vertices.end()) && (newLatitude == currentLatitude));


                                        int midBandLatitude = (currentLatitude + newLatitude) / 2;
                                        ///////Find next latitude///////////////


                                        while (iterVertex2 != iterVertexStop)
                                        {
                                            /* Band latitude */
                                            int vertexNum = (*iterVertex2).index;


                                            // Copy edges from previous list (if any)
                                            // Remove any that have no common link to this vertex number
                                            iterRunning = runningEdges.begin();
                                            while (iterRunning != runningEdges.end())
                                            {
                                                if ( (vertexNum == (*iterRunning).west)
                                                     || (vertexNum == (*iterRunning).east) )
                                                {
                                                    iterRunning = runningEdges.erase( iterRunning );
                                                    if (runningEdges.empty())
                                                    {
                                                        iterRunning = runningEdges.end();
                                                    }
                                                }
                                                else
                                                {
                                                    (*iterRunning).longitude = edgeLongitude( (*iterRunning).west, (*iterRunning).east, midBandLatitude, &fenceMap );
                                                    ++iterRunning;
                                                }
                                            }

                                            //Add edges for this vertex
                                            Edge tempEdge;

                                            if ((*iterVertex2).edge1.west != NO_VERTEX)
                                            {
                                                tempEdge = (*iterVertex2).edge1;
                                                tempEdge.longitude = edgeLongitude( tempEdge.west, tempEdge.east, midBandLatitude, &fenceMap );
                                                runningEdges.push_back( tempEdge );
                                            }

                                            if ((*iterVertex2).edge2.west != NO_VERTEX)
                                            {
                                                tempEdge = (*iterVertex2).edge2;
                                                tempEdge.longitude = edgeLongitude( tempEdge.west, tempEdge.east, midBandLatitude, &fenceMap );
                                                runningEdges.push_back( tempEdge );
                                            }

                                            ++iterVertex2;

                                            //Update running edges with next vertex if it is same latitude
                                        }


                                        runningEdges.sort();


                                        // Copy running edge list (note: for one or more vertices) to edge block
                                        while (iterVertex != iterVertex2)
                                        {
                                            // Set edge list offset for vertex
                                            (*iterVertex).edgeListOffset = edgeOffset;

                                            iterRunning = runningEdges.begin();
                                            while (iterRunning != runningEdges.end())
                                            {
                                                edgeBlock.push_back( *iterRunning );
                                                ++iterRunning;

                                                ++edgeOffset;
                                            }

                                            ++iterVertex;
                                        }

                                    }

                                    //********** Write edge list offsets & their edge lists ****************

                                    /* Write edge list offsets */
                                    int size = fenceMap.vertexCount;

                                    iterVertex = fenceMap.vertices.begin();
                                    while (iterVertex != fenceMap.vertices.end())
                                    {
                                        int edgeCount = (*iterVertex).edgeListOffset;
                                        fileWrite( &fileOut, BYTE_4, (edgeCount * BYTE_16) + OFFSET_TO_EDGES(size) );
                                        ++iterVertex;
                                    }


                                    /* Stream out the edge list */
                                    std::list<Edge>::iterator iterEdge = edgeBlock.begin();
                                    while (iterEdge != edgeBlock.end())
                                    {
                                        int band;

                                        std::list<VertexCrossRef>::iterator iterCrossRef;

                                        iterVertex = fenceMap.vertices.begin();
                                        iterCrossRef = fenceMap.crossRef.begin();
                                        band = (*iterEdge).west;
                                        advance( iterCrossRef, band );
                                        band = (*iterCrossRef).orderedIndex;
                                        advance( iterVertex, band );
                                        fileWrite( &fileOut, BYTE_4, (*iterVertex).latitude );
                                        fileWrite( &fileOut, BYTE_4, (*iterVertex).longitude );

                                        iterVertex = fenceMap.vertices.begin();
                                        iterCrossRef = fenceMap.crossRef.begin();
                                        band = (*iterEdge).east;
                                        advance( iterCrossRef, band );
                                        band = (*iterCrossRef).orderedIndex;
                                        advance( iterVertex, band );
                                        fileWrite( &fileOut, BYTE_4, (*iterVertex).latitude );
                                        fileWrite( &fileOut, BYTE_4, (*iterVertex).longitude );


                                        ++iterEdge;
                                    }


                                    //********** Update running fence summary list **************************
                                    FenceSummary f;

                                    f.offset = (int)fileOut.tellp();
                                    f.index = fenceCount;
                                    f.id = fenceMap.id;
                                    fenceSummaryList.push_back( f );

                                    //********** End of processing one fence *******************************
                                    ++fenceCount;
                                }

                                //Close poly file
                                fileOut.close();

                                //Create the box file
                                fileOut.open( "poly.box", std::fstream::out | std::fstream::binary | std::fstream::trunc);


                                //****** Write out box lat/longs and corresponding index list offsets ******
                                std::list<int> fenceIndexBlock;

                                fenceFileSortBoxes( &fileOut, &NSBoundaries, &fenceIndexBlock );
                                fenceFileSortBoxes( &fileOut, &EWBoundaries, &fenceIndexBlock );

                                fenceFileBoxIndexOffsets( &fileOut, &NSBoundaries );
                                fenceFileBoxIndexOffsets( &fileOut, &EWBoundaries );

                                // ************* Write out the fence index list block **********************
                                std::list<int>::iterator iterIndex = fenceIndexBlock.begin();
                                while (iterIndex != fenceIndexBlock.end())
                                {
                                    fileWrite( &fileOut, BYTE_2, *iterIndex );
                                    ++iterIndex;
                                }

                                int boxFileSize = (int)fileOut.tellp();

                                //Close poly file
                                fileOut.close();


                                //********** Consolidate files ********************************************

                                //Open final binary file
                                fileOut.open( "poly.bin", std::fstream::out | std::fstream::binary | std::fstream::trunc);
                                fileWrite( &fileOut, BYTE_2, fenceCount );


                                //Write out fence offsets
                                int fenceOffset = 0;

                                std::list<FenceSummary>::iterator iterSummary = fenceSummaryList.begin();
                                while (iterSummary != fenceSummaryList.end())
                                {
                                    fileWrite( &fileOut, BYTE_4, boxFileSize
                                                                  + OFFSET_TO_BOX_FILE(fenceCount)
                                                                  + fenceOffset );

                                    fenceOffset = (*iterSummary).offset;
                                    ++iterSummary;
                                }


                                //Write out sorted fence OTA ids
                                fenceSummaryList.sort();

                                iterSummary = fenceSummaryList.begin();
                                while (iterSummary != fenceSummaryList.end())
                                {
                                    fileWrite( &fileOut, BYTE_2, (*iterSummary).id );
                                    ++iterSummary;
                                }

                                //Write out sorted fence OTA indexes
                                iterSummary = fenceSummaryList.begin();
                                while (iterSummary != fenceSummaryList.end())
                                {
                                    fileWrite( &fileOut, BYTE_2, (*iterSummary).index );
                                    ++iterSummary;
                                }


                                /* Concatenate the box file */
                                fileIn.open( "poly.box", std::fstream::in | std::fstream::binary);
                                fileConcat( &fileOut, &fileIn );
                                fileIn.close();



                                /* Concatenate the polyfence file */
                                fileIn.open( "poly.def", std::fstream::in | std::fstream::binary);
                                fileConcat( &fileOut, &fileIn );
                                fileIn.close();

                                //Close binary file
                                fileOut.close();






                                //Raw Binary version of fences
                                packer->save();

                                csvFile->close();

                                status->Text = "Converted successfully";
                            }
                            else
                            {
                                status->Text = "Empty input file!";
                            }

                        }
                        else
                        {
                            status->Text = "Can't open input file!";
                        }
                    }
                    else
                    {
                        status->Text = "Not a csv file";
                    }
                }
                else
                {
                    status->Text = "No extension";
                }
            }
            else
            {
                status->Text = "No file selected!";
            }
    }


    private: System::Void viewAttributesButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        ++_fenceIndex;
        (void)getAttributes();
    }


    private: System::Void viewBackAttributesButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        --_fenceIndex;
        (void)getAttributes();
    }

    private: System::Void writeAttributesButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        putAttributes();
    }


    private: System::Void resetFloor_Click(System::Object^  sender, System::EventArgs^  e)
    {
        attributeFloor->Text = String::Format( "{0}", 0xffffU );
    }
    private: System::Void resetCeiling_Click(System::Object^  sender, System::EventArgs^  e)
    {
        attributeCeiling->Text = String::Format( "{0}", 0xffffU );
    }
    private: System::Void resetStartDate_Click(System::Object^  sender, System::EventArgs^  e)
    {
        unsigned int startDateElapsedTime = 0xffffffffU;
        attributeStartDate->Text = String::Format( "{0}", startDateElapsedTime );
        DateTime^ centuryBegin = gcnew DateTime(2000, 1, 1);

        _datePickLocked = true;
        startDataPicker->Value = centuryBegin->AddSeconds( startDateElapsedTime );
        startDateElapsedTime -= (startDateElapsedTime % SECONDS_IN_DAY);
        startTimePicker->Value = centuryBegin->AddSeconds( startDateElapsedTime );
        _datePickLocked = false;
    }
    private: System::Void resetStopDate_Click(System::Object^  sender, System::EventArgs^  e)
    {
        unsigned int stopDateElapsedTime = 0xffffffffU;
        attributeStopDate->Text = String::Format( "{0}", stopDateElapsedTime );
        DateTime^ centuryBegin = gcnew DateTime(2000, 1, 1);

        _datePickLocked = true;
        stopDatePicker->Value = centuryBegin->AddSeconds( stopDateElapsedTime );
        stopDateElapsedTime -= (stopDateElapsedTime % SECONDS_IN_DAY);
        stopTimePicker->Value = centuryBegin->AddSeconds( stopDateElapsedTime );
        _datePickLocked = false;
    }
    private: System::Void resetSpeed_Click(System::Object^  sender, System::EventArgs^  e)
    {
        attributeSpeed->Text = String::Format( "{0}", 0xffffU );
    }

    //----------------------------Support Functions ---------------------------
    //
    //Parses strings from an 'csv' file and packs the string values into a binary object.
    //Also requires size of the csv and current byte position which will progress for each
    //fence call
    //The 'vertices' contents will be zero for a 1st pass call but non zero for a 2nd pass.
    //The csv file has 4 columns and accordingly the parsing maintains a state =
    //id/flags/lat/long which is simply a count modulo 4) 
    
    //Return the starting position of next fence csv (if any)
    void parse( Pack ^packer, StreamIn^ csvFile, int *verticesCount, Fence *fenceMap )
    {
        Vertex vertex;
                    
    	char stringBuffer[MAX_ENTRY_SZ];/* to buffer strings parsed from input */
        int csvColumn = 0;
        int csvRows = 0;//counts rows found during parse
        bool endOfFence = false;//remembers when a fence is done

        int endPosn = 0;//Will return the current csv byte position at end of parse
        
        
        
        endOfFence = false;//remembers when a fence is done

        char character;
        if (csvFile->isEnd() == false)
        {
            character = csvFile->get();
        }
	    while ((csvFile->isEnd() == false) && (endOfFence == false))
	    {
	        int charCount = 0;//counts chars in a string
	        int integers = 0;//counts numbers before any dp

	        //Get a string from the input delimited by either a ',' or 'x0d' and ignoring any '.' */
            while ((character != '\x0d') && (character != '\x0a') && (character != ',') && (csvFile->isEnd() == false))
            {
                if (character != '.')
                {
                    stringBuffer[charCount] = character;
                    ++charCount;
                }
                else
                {
                    integers = charCount;
                }
                character = csvFile->get();
            }
            //String done
            
            
            stringBuffer[charCount] = '\0';//Complete the string


            //Get next char
            if (csvFile->isEnd() == false)
            {
                character = csvFile->get();
            }

            //Or skip past to start of next line
            while (((character == '\x0d') || (character == '\x0a')) && (csvFile->isEnd() == false))
            {
                character = csvFile->get();
            }
        
            if (charCount != 0)
            {
                if (*verticesCount != 0)
                {
                    //This is 2nd parse pass, so insert the values depending upon column
                    int value = (int)atol( stringBuffer );
                    
                    switch (csvColumn & 3)//modulo 4
                    {
                        case 0://ID
                            //Only the 1st fence row would have a value in this column
                            if (csvRows == 0)
                            {
                                //Must be 1st row so insert ID and inputted vertix count
                                packer->insert( value, 8 );//id
                                packer->insert( *verticesCount, 16 );
                                fenceMap->id = value;
                                fenceMap->vertexCount = *verticesCount;
                            }
                            else
                            {
                                //Must be value for next fence - so end this fence (i.e. stop)
                                endOfFence = true;
                            }
                            break;
                        case 1://FLAGS
                            //Only the 1st fence row would have a value in this column
                            packer->insert( value << 1, 8 );
                            fenceMap->behaviour = value;
                            break;
                        case 2://LATITUDE
                            //Need to add datum and produce result rounded to 5dp
                            value = packer->round( value, charCount - integers, 6 );
                            value = packer->round( value + LAT_DATUM, 6, 5 );
                            packer->insert( value, 25 );
                            vertex.latitude = value;
                            break;
                        case 3://LONGITUDE
                            //Need to add datum and produce result rounded to 5dp
                            value = packer->round( value, charCount - integers, 6 );
                            value = packer->round( value + LONG_DATUM, 6, 5 );
                            packer->insert( value, 26 );
                            vertex.longitude = value;
                            vertex.edge1.west = NO_VERTEX;
                            vertex.edge1.east = NO_VERTEX;
                            vertex.edge2.west = NO_VERTEX;
                            vertex.edge2.east = NO_VERTEX;
                            vertex.index = csvRows;
                            fenceMap->vertices.push_back( vertex );
                            
                            //Bookmark the start of new line file position
                            //Note: We've already stepped passed by one
                            csvFile->bookmarkPrevious();
                            ++csvRows;
                            break;
                    }
                }
                else
                {
                    //This is 1st parse pass, we are just counting rows until end of a fence
                    switch (csvColumn & 3)//modulo 4
                    {
                        case 0://ID
                            if (csvRows != 0)
                            {
                                //Must be 1st row so insert ID and inputted vertix count
                                endOfFence = true;
                            }
                            break;
                        case 1://FLAGS
                        case 2://LATITUDE
                            break;
                        case 3://LONGITUDE
                            //Count the row
                            ++csvRows;
                            break;
                    }
                    
                }
            }

            ++csvColumn;//cycle the column state
        }
        
        *verticesCount = csvRows;//vertix count must be no or rows encountered
    }
    
    

    //Reads and presents attributes in bin file
    //Return - is a bin file (true/false)
    bool getAttributes( void )
    {
        char longName[100];/* to buffer file names */
        std::fstream fileIn;/* file handle */

        bool isBinFile = false;

        if (_isFileSelected == true)
        {
            int nameSize = openFile->FileName->Length;
            for (int i = 0; i < nameSize; ++i )
            {
                longName[i] = (char)openFile->FileName[i];
            }
            longName[nameSize] = '\0';

            char *ptr = strchr( longName, '.' );
            if (ptr != 0)
            {
                ++ptr;
                if (strcmp( ptr, "bin" ) == 0)
                {
                    fileIn.open( longName, std::fstream::in | std::fstream::binary);

                    if (true)
                    {
                        int offset;

                        fileIn.seekp( 0, std::ios_base::beg );

                        int allFences = fileRead( &fileIn, BYTE_2 );

                        if (_fenceIndex < 0)
                        {
                            _fenceIndex = allFences - 1;
                        }

                        fileIn.seekp( (_fenceIndex % allFences) * BYTE_4, std::ios_base::cur );
                        offset = fileRead( &fileIn, BYTE_4 );
                        fileIn.seekp( offset, std::ios_base::beg );

                        attributeID->Text = String::Format( "{0}", fileRead( &fileIn, BYTE_2 ) );
                        setIntoDropDown( attributeBehaviour, fileRead( &fileIn, BYTE_1 ) );
                        attributeFloor->Text = String::Format( "{0}", fileRead( &fileIn, BYTE_2 ) );
                        attributeCeiling->Text = String::Format( "{0}", fileRead( &fileIn, BYTE_2 ) );

                        DateTime^ centuryBegin = gcnew DateTime(2000, 1, 1);
                        _datePickLocked = true;


                        unsigned int elapsedTime;

                        elapsedTime = fileRead( &fileIn, BYTE_4 );
                        attributeStartDate->Text = String::Format( "{0}", elapsedTime );
                        startDataPicker->Value = centuryBegin->AddSeconds( elapsedTime );
                        elapsedTime %= SECONDS_IN_DAY;
                        startTimePicker->Value = centuryBegin->AddSeconds( elapsedTime );

                        elapsedTime = fileRead( &fileIn, BYTE_4 );
                        attributeStopDate->Text = String::Format( "{0}", elapsedTime );
                        stopDatePicker->Value = centuryBegin->AddSeconds( elapsedTime );
                        elapsedTime %= SECONDS_IN_DAY;
                        stopTimePicker->Value = centuryBegin->AddSeconds( elapsedTime );

                        _datePickLocked = false;


                        attributeSpeed->Text = String::Format( "{0}", fileRead( &fileIn, BYTE_2 ) );

                        setIntoDropDown( attributeSbdTx, fileRead( &fileIn, BYTE_1 ) );

                        setIntoDropDown( attributeSbdBurstFix, fileRead( &fileIn, BYTE_1 ) );
                        setIntoDropDown( attributeSbdBurstTx, fileRead( &fileIn, BYTE_1 ) );

                        setIntoDropDown( attributeCellTx, fileRead( &fileIn, BYTE_1 ) );
                        setIntoDropDown( attributeCellBurstFix, fileRead( &fileIn, BYTE_1 ) );
                        setIntoDropDown( attributeCellBurstTx, fileRead( &fileIn, BYTE_1 ) );

                        setIntoDropDown( attributeSlowSbdTx, fileRead( &fileIn, BYTE_1 ) );
                        setIntoDropDown( attributeSlowSbdBurstFix, fileRead( &fileIn, BYTE_1 ) );
                        setIntoDropDown( attributeSlowSbdBurstTx, fileRead( &fileIn, BYTE_1 ) );

                        setIntoDropDown( attributeSlowCellTx, fileRead( &fileIn, BYTE_1 ) );
                        setIntoDropDown( attributeSlowCellBurstFix, fileRead( &fileIn, BYTE_1 ) );
                        setIntoDropDown( attributeSlowCellBurstTx, fileRead( &fileIn, BYTE_1 ) );

                        fileIn.close();

                        fenceNumber->Text = String::Format( "{0}", (_fenceIndex % allFences) + 1 );
                        fenceTotal->Text = String::Format( "{0}", allFences );

                        isBinFile = true;
                    }
                    else
                    {
                        status->Text = "Can't open input file!";
                    }
                }
                else
                {
                    //status->Text = "Not a bin file";
                }
            }
            else
            {
                status->Text = "No extension";
            }
        }
        else
        {
            status->Text = "No file selected!";
        }

        return (isBinFile);
    }


    void setIntoDropDown( ComboBox^  attribute, unsigned int setting )
    {
        if (setting == 0xff)
        {
            setting = (attribute->Items->Count - 1);
        }
        attribute->SelectedIndex = setting;
    }


    unsigned int getFromDropDown( ComboBox^  attribute )
    {
        unsigned int setting = attribute->SelectedIndex;
        if (setting == (attribute->Items->Count - 1))
        {
            setting = 0xff;
        }
        return (setting);
    }


    //Writes presented attributes to bin file
    void putAttributes( void )
    {
        char longName[100];/* to buffer file names */
        std::fstream fileOut;/* file handle */

        bool isBinFile = false;

        if (_isFileSelected == true)
        {
            int nameSize = openFile->FileName->Length;
            for (int i = 0; i < nameSize; ++i )
            {
                longName[i] = (char)openFile->FileName[i];
            }
            longName[nameSize] = '\0';

            char *ptr = strchr( longName, '.' );
            if (ptr != 0)
            {
                ++ptr;
                if (strcmp( ptr, "bin" ) == 0)
                {
                    fileOut.open( longName, std::fstream::in | std::fstream::out | std::fstream::binary);

                    if (true)
                    {
                        int offset;

                        fileOut.seekp( 0, std::ios_base::beg );

                        int allFences = fileRead( &fileOut, BYTE_2 );

                        fileOut.seekp( (_fenceIndex % allFences) * BYTE_4, std::ios_base::cur );
                        offset = fileRead( &fileOut, BYTE_4 );
                        fileOut.seekp( offset, std::ios_base::beg );

                        fileWrite( &fileOut, BYTE_2, (int)Int64::Parse( attributeID->Text ) );

                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeBehaviour ) );
                        fileWrite( &fileOut, BYTE_2, (int)Int64::Parse( attributeFloor->Text ) );
                        fileWrite( &fileOut, BYTE_2, (int)Int64::Parse( attributeCeiling->Text ) );
                        fileWrite( &fileOut, BYTE_4, (int)Int64::Parse( attributeStartDate->Text ) );
                        fileWrite( &fileOut, BYTE_4, (int)Int64::Parse( attributeStopDate->Text ) );
                        fileWrite( &fileOut, BYTE_2, (int)Int64::Parse( attributeSpeed->Text ) );

                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeSbdTx ) );

                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeSbdBurstFix ) );
                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeSbdBurstTx ) );

                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeCellTx ) );
                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeCellBurstFix ) );
                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeCellBurstTx ) );

                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeSlowSbdTx ) );
                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeSlowSbdBurstFix ) );
                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeSlowSbdBurstTx ) );

                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeSlowCellTx ) );
                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeSlowCellBurstFix ) );
                        fileWrite( &fileOut, BYTE_1, getFromDropDown( attributeSlowCellBurstTx ) );

                        fileOut.close();
                    }
                    else
                    {
                        status->Text = "Can't open input file!";
                    }
                }
                else
                {
                    //status->Text = "Not a bin file";
                }
            }
            else
            {
                status->Text = "No extension";
            }
        }
        else
        {
            status->Text = "No file selected!";
        }

    }


    int edgeLongitude( int west, int east, int bandLatitude, Fence *map )
    {
        /*  longitude west +
            (((latitudeWest - latitude Band) / (latitudeWest - latitudeEast)) x (longitudeEast - longitudeWest))
        */

        int band;

        std::list<Vertex>::iterator iterVertex = map->vertices.begin();
        std::list<VertexCrossRef>::iterator iterCrossRef = map->crossRef.begin();
        advance( iterCrossRef, west );
        band = (*iterCrossRef).orderedIndex;
        advance( iterVertex, band );

        int latitudeWest = (*iterVertex).latitude;
        int longitudeWest = (*iterVertex).longitude;

        iterVertex = map->vertices.begin();
        iterCrossRef = map->crossRef.begin();
        advance( iterCrossRef, east );
        band = (*iterCrossRef).orderedIndex;
        advance( iterVertex, band );

        int latitudeEast = (*iterVertex).latitude;
        int longitudeEast = (*iterVertex).longitude;


        /* Use m, n as part calculations */
        int m = latitudeWest - bandLatitude;
        int n = latitudeWest - latitudeEast;
        if (bandLatitude > latitudeWest)
        {
            m = -m;
            n = -n;
        }

        m *= (longitudeEast - longitudeWest);
        m /= n;
        m += longitudeWest;

        return((int)m);
    }


    void fenceFileSortBoxes( std::fstream *fileOut, std::list<BoxBoundary> *boxBandList, std::list<int> *fenceIndexBlock )
    {

        boxBandList->sort();

        std::list<BoxBoundary>::iterator iterBox = boxBandList->begin();

        std::list<int> fenceIndexRun;

        while (iterBox != boxBandList->end())
        {
            fileWrite( fileOut, BYTE_4, (*iterBox).position );

            /* Update the running box number list */
            (*iterBox).boxListOffset = fenceIndexBlock->size();

            /* Add to index list or remove if already there */
            bool found = false;

            std::list<int>::iterator iterRun = fenceIndexRun.begin();
            while (iterRun != fenceIndexRun.end())
            {
                if ((*iterBox).index == *iterRun)
                {
                    //Found - so remove
                    iterRun = fenceIndexRun.erase( iterRun );
                    found = true;

                    break;
                }
                else
                {
                    ++iterRun;
                }
            }

            if (!found)
            {
                //Not found - so insert
                fenceIndexRun.push_back( (*iterBox).index );
            }


            /* Write sorted running box number list to stream out buffer */

            fenceIndexRun.sort();

            iterRun = fenceIndexRun.begin();
            while (iterRun != fenceIndexRun.end())
            {
                fenceIndexBlock->push_back( *iterRun );
                ++iterRun;
            }

            ++iterBox;
        }

    }


    void fenceFileBoxIndexOffsets( std::fstream *fileOut, std::list<BoxBoundary> *boxBandList )
    {
        /* Write out index list offsets */
        int boxCount = boxBandList->size() / 2;

        std::list<BoxBoundary>::iterator iterBox = boxBandList->begin();
        iterBox = boxBandList->begin();
        while (iterBox != boxBandList->end())
        {
            int offset = (*iterBox).boxListOffset;
            fileWrite( fileOut, BYTE_4, (offset * BYTE_2) + OFFSET_TO_INDEXES(boxCount) );

            ++iterBox;
        }
    }

    void fileConcat( std::fstream *fileOut, std::fstream *fileIn )
    {
        unsigned char buffer[128];
        int size;
        fileIn->seekp( 0, std::ios_base::end );
        size = (int)fileIn->tellp();

        fileIn->seekp( 0, std::ios_base::beg );

        do
        {
            int bytes = size < sizeof(buffer) ? size : sizeof(buffer);

            fileIn->read( ( char *)buffer, bytes );
            fileOut->write(( char *)buffer, bytes );

            size -= bytes;

        }
        while(size != 0);

    }


	void fileWrite( std::fstream *fileOut, int size, unsigned int value )
	{
        char buffer[4];

        int n = size;
        char *p = buffer;

        while (n != 0)
        {
            *p = (value >> ((n - 1) * 8)) & 0xff;
            ++p;
            --n;
        }
        fileOut->write(( char *)buffer, size );
	}


	unsigned int fileRead( std::fstream *fileIn, int size )
	{
        unsigned char buffer[4];
        unsigned char *p = buffer;
        unsigned int value = 0;

        fileIn->read(( char *)buffer, size );

        while (size != 0)
        {
            value <<= 8;
            value |= *p;
            ++p;
            --size;
        }

        return (value);
	}


    //#define TXT_FILE
    #define NON_CIRCULAR
    void generateFence( std::fstream *fileOut, int id, double latitude, double longitude, double radius, int points )
    {


        #define PI 3.14159265
        #define DEG_TO_RADS (PI / 180)

        char buffer [100];

        #if defined TXT_FILE
        sprintf_s( buffer, 100, "type""\x09""latitude""\x09""longitude""\x09""name""\x09""desc""\x09""color""\x09""fill_opacity""\n" );
        fileOut->write(buffer, strlen( buffer ) );
        #endif

        #if defined NON_CIRCULAR
        int percent = ((rand() % 100) + 1);
        #else
        int percent = 100;
        #endif

        int firstPercent = percent;
        int j = 0;

        for (int i = 0; i != points; ++i)
        {
            double radians = ((360 / (double)points) * (i + 1)) * DEG_TO_RADS;

            //Change radius every 'n' angle steps
            ++j;
            if (j == 50)
            {
                #if defined NON_CIRCULAR
                percent = ((rand() % 100) + 1);
                #else
                percent = 100;
                #endif
                j = 0;
            }

            //Make final radius same as the very first
            if (i == (points - 1))
            {
                percent = firstPercent;
            }

            double pointLat = latitude + (cos( radians ) * ((radius * percent) / 100));
            double pointLong = longitude + (sin( radians ) * ((radius * percent) / 100));

            #if defined TXT_FILE
            if (false)
            #else
            if (i == 0)
            #endif
            {
                sprintf_s( buffer, 100, "%u,0,%f,%f""\n", id, pointLat, pointLong );
            }
            else
            {
                #if defined TXT_FILE
                sprintf_s( buffer, 100, "T""\x09""%f""\x09""%f""\n", pointLat, pointLong );
                #else
                sprintf_s( buffer, 100, ",,%f,%f""\n", pointLat, pointLong );
                #endif
            }
            fileOut->write(buffer, strlen( buffer ) );
        }

        #if defined TXT_FILE
        sprintf_s( buffer, 100, "\n" );
        fileOut->write(buffer, strlen( buffer ) );
        #endif
    }


    private: System::Void generateButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        std::fstream fileOut;/* file handle */

        #if defined TXT_FILE
        fileOut.open( "mass.txt", std::fstream::out | std::fstream::binary | std::fstream::trunc);
        #else
        fileOut.open( "mass.csv", std::fstream::out | std::fstream::binary | std::fstream::trunc);
        #endif

        double radius = MASS_RADIUS / 100000;

        double centreStep = (2 * radius) / 3;

        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                generateFence( &fileOut, (i * 10) + j, MASS_LATITUDE + (centreStep * i), MASS_LONGITUDE + (centreStep * j), radius, MASS_POINTS );
            }
        }



        fileOut.close();

        status->Text = "Generated successfully";
    }





    private: System::Void startDataPicker_ValueChanged(System::Object^  sender, System::EventArgs^  e)
    {

        if (!_datePickLocked)
        {
            DateTime^ centuryBegin = gcnew DateTime(2000, 1, 1);

            long long int elapsedTime = startDataPicker->Value.Ticks - centuryBegin->Ticks;//Ticks
            elapsedTime /= 10000000;//Seconds

            elapsedTime /= SECONDS_IN_DAY;
            elapsedTime *= SECONDS_IN_DAY;

            elapsedTime += (startTimePicker->Value.TimeOfDay.Ticks / 10000000);

            attributeStartDate->Text = String::Format( "{0}", elapsedTime );
        }
    }
    private: System::Void stopDatePicker_ValueChanged(System::Object^  sender, System::EventArgs^  e)
    {
        if (!_datePickLocked)
        {
            DateTime^ centuryBegin = gcnew DateTime(2000, 1, 1);

            long long int elapsedTime = stopDatePicker->Value.Ticks - centuryBegin->Ticks;//Ticks
            elapsedTime /= 10000000;//Seconds

            elapsedTime /= SECONDS_IN_DAY;
            elapsedTime *= SECONDS_IN_DAY;

            elapsedTime += (stopTimePicker->Value.TimeOfDay.Ticks / 10000000);

            attributeStopDate->Text = String::Format( "{0}", elapsedTime );
        }
    }

	private: System::Void startTimePicker_ValueChanged(System::Object^  sender, System::EventArgs^  e)
    {
        if (!_datePickLocked)
        {
            DateTime^ centuryBegin = gcnew DateTime(2000, 1, 1);

            long long int elapsedTime = startDataPicker->Value.Ticks - centuryBegin->Ticks;//Ticks
            elapsedTime /= 10000000;//Seconds

            elapsedTime /= SECONDS_IN_DAY;
            elapsedTime *= SECONDS_IN_DAY;

            elapsedTime += (startTimePicker->Value.TimeOfDay.Ticks / 10000000);

            attributeStartDate->Text = String::Format( "{0}", elapsedTime );
        }
	}

    private: System::Void stopTimePicker_ValueChanged(System::Object^  sender, System::EventArgs^  e)
    {
        if (!_datePickLocked)
        {
            DateTime^ centuryBegin = gcnew DateTime(2000, 1, 1);

            long long int elapsedTime = stopDatePicker->Value.Ticks - centuryBegin->Ticks;//Ticks
            elapsedTime /= 10000000;//Seconds

            elapsedTime /= SECONDS_IN_DAY;
            elapsedTime *= SECONDS_IN_DAY;

            elapsedTime += (stopTimePicker->Value.TimeOfDay.Ticks / 10000000);

            attributeStopDate->Text = String::Format( "{0}", elapsedTime );
        }
    }
};

}




