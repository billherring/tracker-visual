#pragma once
#include <cstring>
#include <cstdio>

#include "gps.h"
using namespace std;

#if 1
static const char *gpsGpInstrument[] =
{
    "$GPRMC,",
    //095629.00
    ".00,A,0012.87155,N,00012.87155,W,",
    //6.0
    ",315.0,",
    //<ddmmyy>
    ",0.0,W,A*",
    //RMC Check
    "\x0d\x0a",
    //
    "$GPGGA,",
    //<hhmmss>
    ".00,",
    //5135.00000
    ",",
    //N/S
    ",",
    //00019.00000
    ",",
    //E/W
    ",",
    //1
    ",12,2.0,",
    //<aaaaa>
    ",M,100.0,M,,*",
    //GGA Check
    "\x0d\x0a",
    //
    "$GPGSA,A,3,2,6,10,14,18,22,26,30,,,,,2.0,2.0,2.0*",
    //GSA Check
    "\x0d\x0a",
    
    0
};
#else
static const char *gpsGpInstrument[] =
{
    "$GPRMC,095629.00,A,0012.87155,N,00012.87155,W,6.0,315.0,090616,0.0,W,A*",
    //RMC Check
    "\x0d\x0a",
    //
    "$GPGGA,095629.00,5135.00000,N,00019.00000,W,1,12,2.0,27.0,M,100.0,M,,*",
    //GGA Check
    "\x0d\x0a",
    //
    "$GPGSA,A,3,2,6,10,14,18,22,26,30,,,,,2.0,2.0,2.0*",
    //GSA Check
    "\x0d\x0a",
    
    0
};
#endif

static const char *gpsGnInstrument[] =
{
    "$GNRMC,",
    //095629.00
    ".00,A,0012.87155,N,00012.87155,W,",
    //6.0
    ",315.0,",
    //<ddmmyy>
    ",0.0,W,A*",
    //RMC Check
    "\x0d\x0a",
    //
    "$GNGGA,",
    //<hhmmss>
    ".00,",
    //5135.00000
    ",",
    //N/S
    ",",
    //00019.00000
    ",",
    //E/W
    ",",
    //1
    ",12,2.0,",
    //<aaaaa>
    ",M,100.0,M,,*",
    //GGA Check
    "\x0d\x0a",
    //
    "$GNGSA,A,3,2,6,10,14,18,22,26,30,,,,,2.0,2.0,2.0*",
    //GSA Check
    "\x0d\x0a",
    
    0
};


namespace Nmea {
//    class GpsTrack;

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	using namespace System::IO::Ports;


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
            trackerConnected = false;
            testEvent = false;
            gpsTrack = gcnew GpsTrack();
            gpsTrack->setDirection( GPS_TRACK_DIRECTION::UP );
            gpsTrack->setAltitudeStep( "0" );
            upRadio->Checked = true;
            eastStepRadio->Checked = true;
            northStepRadio->Checked = true;
            northLatitudeRadio->Checked = true;
            eastLongitudeRadio->Checked = true;
            latitudeStepBox->Text = "0";
            longitudeStepBox->Text = "0";
            latitudeBox->Text = "5160526";
            longitudeBox->Text = "29768";
            speedStepBox->Text = "0";
            
            altitude = 0;
            latitude = Convert::ToInt32( latitudeBox->Text );
            longitude = Convert::ToInt32( longitudeBox->Text );
		    gpSelectRadio->Checked = true;
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
	private: System::Windows::Forms::TextBox^  comPortBox;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  altitudeBox;


	private: System::Windows::Forms::Button^  startButton;




	private: System::Windows::Forms::Timer^  secTicker;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
        SerialPort^ trackerPort;
		bool trackerConnected;
		bool testEvent;
        GpsTrack^ gpsTrack;
        DateTime^ timeNow;

        int altitude;
        int altitudeDirection;
        int altitudeStep;
        int latitude;
        int longitude;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::NumericUpDown^  altitudeStepBox;
	private: System::Windows::Forms::RadioButton^  upRadio;
	private: System::Windows::Forms::RadioButton^  downRadio;
	private: System::Windows::Forms::RadioButton^  pauseRadio;
	private: System::Windows::Forms::Label^  timeBox;
	private: System::Windows::Forms::Label^  dateBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::NumericUpDown^  hoursStepBox;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::NumericUpDown^  minutesStepBox;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;

	private: System::Windows::Forms::NumericUpDown^  secondsStepBox;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  latitudeBox;
	private: System::Windows::Forms::TextBox^  longitudeBox;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::NumericUpDown^  latitudeStepBox;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::NumericUpDown^  longitudeStepBox;
	private: System::Windows::Forms::GroupBox^  groupBox4;
	private: System::Windows::Forms::RadioButton^  southStepRadio;

	private: System::Windows::Forms::RadioButton^  northStepRadio;



	private: System::Windows::Forms::GroupBox^  groupBox5;
	private: System::Windows::Forms::RadioButton^  westStepRadio;

	private: System::Windows::Forms::RadioButton^  eastStepRadio;
	private: System::Windows::Forms::RadioButton^  southLatitudeRadio;





	private: System::Windows::Forms::RadioButton^  northLatitudeRadio;



	private: System::Windows::Forms::RadioButton^  westLongitudeRadio;


private: System::Windows::Forms::RadioButton^  eastLongitudeRadio;

	private: System::Windows::Forms::Button^  button1;
private: System::Windows::Forms::GroupBox^  groupBox7;
private: System::Windows::Forms::GroupBox^  groupBox6;
private: System::Windows::Forms::GroupBox^  groupBox9;
private: System::Windows::Forms::GroupBox^  groupBox8;
private: System::Windows::Forms::Label^  label10;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::CheckBox^  fixNoFixCheck;
private: System::Windows::Forms::TextBox^  speedBox;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::NumericUpDown^  speedStepBox;
private: System::Windows::Forms::RadioButton^  gnSelectRadio;
private: System::Windows::Forms::RadioButton^  gpSelectRadio;
private: System::Windows::Forms::Button^  testButton;
private: System::Windows::Forms::RadioButton^  deadRadioButton;












	private: System::Windows::Forms::Label^  connectStatus;

		/// </summary>



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->comPortBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->altitudeBox = (gcnew System::Windows::Forms::TextBox());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->secTicker = (gcnew System::Windows::Forms::Timer(this->components));
			this->connectStatus = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->altitudeStepBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->upRadio = (gcnew System::Windows::Forms::RadioButton());
			this->downRadio = (gcnew System::Windows::Forms::RadioButton());
			this->pauseRadio = (gcnew System::Windows::Forms::RadioButton());
			this->timeBox = (gcnew System::Windows::Forms::Label());
			this->dateBox = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->hoursStepBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->minutesStepBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->secondsStepBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->latitudeBox = (gcnew System::Windows::Forms::TextBox());
			this->longitudeBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->latitudeStepBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->longitudeStepBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
			this->northLatitudeRadio = (gcnew System::Windows::Forms::RadioButton());
			this->southLatitudeRadio = (gcnew System::Windows::Forms::RadioButton());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
			this->northStepRadio = (gcnew System::Windows::Forms::RadioButton());
			this->southStepRadio = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox5 = (gcnew System::Windows::Forms::GroupBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
			this->eastStepRadio = (gcnew System::Windows::Forms::RadioButton());
			this->westStepRadio = (gcnew System::Windows::Forms::RadioButton());
			this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
			this->westLongitudeRadio = (gcnew System::Windows::Forms::RadioButton());
			this->eastLongitudeRadio = (gcnew System::Windows::Forms::RadioButton());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->fixNoFixCheck = (gcnew System::Windows::Forms::CheckBox());
			this->speedBox = (gcnew System::Windows::Forms::TextBox());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->speedStepBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->gnSelectRadio = (gcnew System::Windows::Forms::RadioButton());
			this->gpSelectRadio = (gcnew System::Windows::Forms::RadioButton());
			this->testButton = (gcnew System::Windows::Forms::Button());
			this->deadRadioButton = (gcnew System::Windows::Forms::RadioButton());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->altitudeStepBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hoursStepBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->minutesStepBox))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->secondsStepBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->latitudeStepBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->longitudeStepBox))->BeginInit();
			this->groupBox4->SuspendLayout();
			this->groupBox7->SuspendLayout();
			this->groupBox6->SuspendLayout();
			this->groupBox5->SuspendLayout();
			this->groupBox9->SuspendLayout();
			this->groupBox8->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speedStepBox))->BeginInit();
			this->SuspendLayout();
			// 
			// comPortBox
			// 
			this->comPortBox->Location = System::Drawing::Point(471, 25);
			this->comPortBox->Name = L"comPortBox";
			this->comPortBox->Size = System::Drawing::Size(46, 20);
			this->comPortBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(409, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L" Com Port:";
			// 
			// altitudeBox
			// 
			this->altitudeBox->Location = System::Drawing::Point(9, 32);
			this->altitudeBox->Name = L"altitudeBox";
			this->altitudeBox->Size = System::Drawing::Size(62, 20);
			this->altitudeBox->TabIndex = 2;
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(12, 450);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(102, 34);
			this->startButton->TabIndex = 5;
			this->startButton->Text = L"Run";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::startButton_Click);
			// 
			// secTicker
			// 
			this->secTicker->Tick += gcnew System::EventHandler(this, &Form1::secTicker_Tick);
			// 
			// connectStatus
			// 
			this->connectStatus->AutoSize = true;
			this->connectStatus->Location = System::Drawing::Point(132, 450);
			this->connectStatus->Name = L"connectStatus";
			this->connectStatus->Size = System::Drawing::Size(77, 13);
			this->connectStatus->TabIndex = 10;
			this->connectStatus->Text = L"No connection";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(148, 16);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Step:";
			// 
			// altitudeStepBox
			// 
			this->altitudeStepBox->Location = System::Drawing::Point(151, 32);
			this->altitudeStepBox->Name = L"altitudeStepBox";
			this->altitudeStepBox->Size = System::Drawing::Size(46, 20);
			this->altitudeStepBox->TabIndex = 16;
			this->altitudeStepBox->ValueChanged += gcnew System::EventHandler(this, &Form1::altitudeStepBox_ValueChanged);
			// 
			// upRadio
			// 
			this->upRadio->AutoSize = true;
			this->upRadio->Location = System::Drawing::Point(214, 16);
			this->upRadio->Name = L"upRadio";
			this->upRadio->Size = System::Drawing::Size(39, 17);
			this->upRadio->TabIndex = 17;
			this->upRadio->TabStop = true;
			this->upRadio->Text = L"Up";
			this->upRadio->UseVisualStyleBackColor = true;
			this->upRadio->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton1_CheckedChanged);
			// 
			// downRadio
			// 
			this->downRadio->AutoSize = true;
			this->downRadio->Location = System::Drawing::Point(214, 33);
			this->downRadio->Name = L"downRadio";
			this->downRadio->Size = System::Drawing::Size(53, 17);
			this->downRadio->TabIndex = 18;
			this->downRadio->TabStop = true;
			this->downRadio->Text = L"Down";
			this->downRadio->UseVisualStyleBackColor = true;
			this->downRadio->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton2_CheckedChanged);
			// 
			// pauseRadio
			// 
			this->pauseRadio->AutoSize = true;
			this->pauseRadio->Location = System::Drawing::Point(214, 50);
			this->pauseRadio->Name = L"pauseRadio";
			this->pauseRadio->Size = System::Drawing::Size(55, 17);
			this->pauseRadio->TabIndex = 19;
			this->pauseRadio->TabStop = true;
			this->pauseRadio->Text = L"Pause";
			this->pauseRadio->UseVisualStyleBackColor = true;
			this->pauseRadio->CheckedChanged += gcnew System::EventHandler(this, &Form1::radioButton3_CheckedChanged);
			// 
			// timeBox
			// 
			this->timeBox->AutoSize = true;
			this->timeBox->Location = System::Drawing::Point(47, 25);
			this->timeBox->Name = L"timeBox";
			this->timeBox->Size = System::Drawing::Size(25, 13);
			this->timeBox->TabIndex = 20;
			this->timeBox->Text = L"------";
			// 
			// dateBox
			// 
			this->dateBox->AutoSize = true;
			this->dateBox->Location = System::Drawing::Point(154, 25);
			this->dateBox->Name = L"dateBox";
			this->dateBox->Size = System::Drawing::Size(25, 13);
			this->dateBox->TabIndex = 21;
			this->dateBox->Text = L"------";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(18, 25);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 22;
			this->label3->Text = L"Time:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(124, 25);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(33, 13);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Date:";
			// 
			// hoursStepBox
			// 
			this->hoursStepBox->Location = System::Drawing::Point(21, 44);
			this->hoursStepBox->Name = L"hoursStepBox";
			this->hoursStepBox->Size = System::Drawing::Size(44, 20);
			this->hoursStepBox->TabIndex = 24;
			this->hoursStepBox->ValueChanged += gcnew System::EventHandler(this, &Form1::hoursStepBox_ValueChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(18, 28);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Hours";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(92, 29);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 13);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Minutes";
			// 
			// minutesStepBox
			// 
			this->minutesStepBox->Location = System::Drawing::Point(95, 44);
			this->minutesStepBox->Name = L"minutesStepBox";
			this->minutesStepBox->Size = System::Drawing::Size(41, 20);
			this->minutesStepBox->TabIndex = 27;
			this->minutesStepBox->ValueChanged += gcnew System::EventHandler(this, &Form1::minutesStepBox_ValueChanged);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->altitudeBox);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->altitudeStepBox);
			this->groupBox1->Controls->Add(this->upRadio);
			this->groupBox1->Controls->Add(this->downRadio);
			this->groupBox1->Controls->Add(this->pauseRadio);
			this->groupBox1->Location = System::Drawing::Point(12, 67);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(277, 80);
			this->groupBox1->TabIndex = 28;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Altitude";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->secondsStepBox);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->Controls->Add(this->minutesStepBox);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->hoursStepBox);
			this->groupBox2->Location = System::Drawing::Point(326, 67);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(277, 80);
			this->groupBox2->TabIndex = 29;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Advance time";
			// 
			// secondsStepBox
			// 
			this->secondsStepBox->Location = System::Drawing::Point(170, 44);
			this->secondsStepBox->Name = L"secondsStepBox";
			this->secondsStepBox->Size = System::Drawing::Size(41, 20);
			this->secondsStepBox->TabIndex = 29;
			this->secondsStepBox->ValueChanged += gcnew System::EventHandler(this, &Form1::secondsStepBox_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(164, 29);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Seconds";
			// 
			// latitudeBox
			// 
			this->latitudeBox->Location = System::Drawing::Point(10, 31);
			this->latitudeBox->Name = L"latitudeBox";
			this->latitudeBox->Size = System::Drawing::Size(61, 20);
			this->latitudeBox->TabIndex = 32;
			this->latitudeBox->Text = L"5160526";
			// 
			// longitudeBox
			// 
			this->longitudeBox->Location = System::Drawing::Point(10, 34);
			this->longitudeBox->Name = L"longitudeBox";
			this->longitudeBox->Size = System::Drawing::Size(55, 20);
			this->longitudeBox->TabIndex = 33;
			this->longitudeBox->Text = L"29768";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(171, 16);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(32, 13);
			this->label8->TabIndex = 34;
			this->label8->Text = L"Step:";
			// 
			// latitudeStepBox
			// 
			this->latitudeStepBox->Location = System::Drawing::Point(173, 32);
			this->latitudeStepBox->Name = L"latitudeStepBox";
			this->latitudeStepBox->Size = System::Drawing::Size(46, 20);
			this->latitudeStepBox->TabIndex = 35;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(169, 16);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(32, 13);
			this->label9->TabIndex = 36;
			this->label9->Text = L"Step:";
			// 
			// longitudeStepBox
			// 
			this->longitudeStepBox->Location = System::Drawing::Point(172, 34);
			this->longitudeStepBox->Name = L"longitudeStepBox";
			this->longitudeStepBox->Size = System::Drawing::Size(46, 20);
			this->longitudeStepBox->TabIndex = 37;
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->groupBox7);
			this->groupBox4->Controls->Add(this->label11);
			this->groupBox4->Controls->Add(this->groupBox6);
			this->groupBox4->Controls->Add(this->label8);
			this->groupBox4->Controls->Add(this->latitudeStepBox);
			this->groupBox4->Controls->Add(this->latitudeBox);
			this->groupBox4->Location = System::Drawing::Point(12, 187);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(277, 125);
			this->groupBox4->TabIndex = 38;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Latitude";
			// 
			// groupBox7
			// 
			this->groupBox7->Controls->Add(this->northLatitudeRadio);
			this->groupBox7->Controls->Add(this->southLatitudeRadio);
			this->groupBox7->Location = System::Drawing::Point(74, 19);
			this->groupBox7->Name = L"groupBox7";
			this->groupBox7->Size = System::Drawing::Size(42, 53);
			this->groupBox7->TabIndex = 41;
			this->groupBox7->TabStop = false;
			// 
			// northLatitudeRadio
			// 
			this->northLatitudeRadio->AutoSize = true;
			this->northLatitudeRadio->Location = System::Drawing::Point(4, 11);
			this->northLatitudeRadio->Name = L"northLatitudeRadio";
			this->northLatitudeRadio->Size = System::Drawing::Size(33, 17);
			this->northLatitudeRadio->TabIndex = 41;
			this->northLatitudeRadio->TabStop = true;
			this->northLatitudeRadio->Text = L"N";
			this->northLatitudeRadio->UseVisualStyleBackColor = true;
			// 
			// southLatitudeRadio
			// 
			this->southLatitudeRadio->AutoSize = true;
			this->southLatitudeRadio->Location = System::Drawing::Point(4, 31);
			this->southLatitudeRadio->Name = L"southLatitudeRadio";
			this->southLatitudeRadio->Size = System::Drawing::Size(32, 17);
			this->southLatitudeRadio->TabIndex = 42;
			this->southLatitudeRadio->TabStop = true;
			this->southLatitudeRadio->Text = L"S";
			this->southLatitudeRadio->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(170, 96);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(101, 13);
			this->label11->TabIndex = 45;
			this->label11->Text = L"1 step = 4Km/hr NS";
			// 
			// groupBox6
			// 
			this->groupBox6->Controls->Add(this->northStepRadio);
			this->groupBox6->Controls->Add(this->southStepRadio);
			this->groupBox6->Location = System::Drawing::Point(225, 19);
			this->groupBox6->Name = L"groupBox6";
			this->groupBox6->Size = System::Drawing::Size(42, 54);
			this->groupBox6->TabIndex = 43;
			this->groupBox6->TabStop = false;
			// 
			// northStepRadio
			// 
			this->northStepRadio->AutoSize = true;
			this->northStepRadio->Location = System::Drawing::Point(6, 14);
			this->northStepRadio->Name = L"northStepRadio";
			this->northStepRadio->Size = System::Drawing::Size(33, 17);
			this->northStepRadio->TabIndex = 36;
			this->northStepRadio->TabStop = true;
			this->northStepRadio->Text = L"N";
			this->northStepRadio->UseVisualStyleBackColor = true;
			// 
			// southStepRadio
			// 
			this->southStepRadio->AutoSize = true;
			this->southStepRadio->Location = System::Drawing::Point(6, 31);
			this->southStepRadio->Name = L"southStepRadio";
			this->southStepRadio->Size = System::Drawing::Size(32, 17);
			this->southStepRadio->TabIndex = 40;
			this->southStepRadio->TabStop = true;
			this->southStepRadio->Text = L"S";
			this->southStepRadio->UseVisualStyleBackColor = true;
			// 
			// groupBox5
			// 
			this->groupBox5->Controls->Add(this->label10);
			this->groupBox5->Controls->Add(this->groupBox9);
			this->groupBox5->Controls->Add(this->groupBox8);
			this->groupBox5->Controls->Add(this->label9);
			this->groupBox5->Controls->Add(this->longitudeStepBox);
			this->groupBox5->Controls->Add(this->longitudeBox);
			this->groupBox5->Location = System::Drawing::Point(326, 187);
			this->groupBox5->Name = L"groupBox5";
			this->groupBox5->Size = System::Drawing::Size(277, 125);
			this->groupBox5->TabIndex = 39;
			this->groupBox5->TabStop = false;
			this->groupBox5->Text = L"Longitude";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(133, 96);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(139, 13);
			this->label10->TabIndex = 44;
			this->label10->Text = L"1 step = 4Km/hr EW at lat 0";
			// 
			// groupBox9
			// 
			this->groupBox9->Controls->Add(this->eastStepRadio);
			this->groupBox9->Controls->Add(this->westStepRadio);
			this->groupBox9->Location = System::Drawing::Point(225, 24);
			this->groupBox9->Name = L"groupBox9";
			this->groupBox9->Size = System::Drawing::Size(41, 51);
			this->groupBox9->TabIndex = 41;
			this->groupBox9->TabStop = false;
			// 
			// eastStepRadio
			// 
			this->eastStepRadio->AutoSize = true;
			this->eastStepRadio->Location = System::Drawing::Point(6, 10);
			this->eastStepRadio->Name = L"eastStepRadio";
			this->eastStepRadio->Size = System::Drawing::Size(32, 17);
			this->eastStepRadio->TabIndex = 42;
			this->eastStepRadio->TabStop = true;
			this->eastStepRadio->Text = L"E";
			this->eastStepRadio->UseVisualStyleBackColor = true;
			// 
			// westStepRadio
			// 
			this->westStepRadio->AutoSize = true;
			this->westStepRadio->Location = System::Drawing::Point(6, 29);
			this->westStepRadio->Name = L"westStepRadio";
			this->westStepRadio->Size = System::Drawing::Size(36, 17);
			this->westStepRadio->TabIndex = 41;
			this->westStepRadio->TabStop = true;
			this->westStepRadio->Text = L"W";
			this->westStepRadio->UseVisualStyleBackColor = true;
			// 
			// groupBox8
			// 
			this->groupBox8->Controls->Add(this->westLongitudeRadio);
			this->groupBox8->Controls->Add(this->eastLongitudeRadio);
			this->groupBox8->Location = System::Drawing::Point(73, 23);
			this->groupBox8->Name = L"groupBox8";
			this->groupBox8->Size = System::Drawing::Size(43, 53);
			this->groupBox8->TabIndex = 41;
			this->groupBox8->TabStop = false;
			// 
			// westLongitudeRadio
			// 
			this->westLongitudeRadio->AutoSize = true;
			this->westLongitudeRadio->Location = System::Drawing::Point(8, 30);
			this->westLongitudeRadio->Name = L"westLongitudeRadio";
			this->westLongitudeRadio->Size = System::Drawing::Size(36, 17);
			this->westLongitudeRadio->TabIndex = 43;
			this->westLongitudeRadio->TabStop = true;
			this->westLongitudeRadio->Text = L"W";
			this->westLongitudeRadio->UseVisualStyleBackColor = true;
			// 
			// eastLongitudeRadio
			// 
			this->eastLongitudeRadio->AutoSize = true;
			this->eastLongitudeRadio->Location = System::Drawing::Point(8, 9);
			this->eastLongitudeRadio->Name = L"eastLongitudeRadio";
			this->eastLongitudeRadio->Size = System::Drawing::Size(32, 17);
			this->eastLongitudeRadio->TabIndex = 44;
			this->eastLongitudeRadio->TabStop = true;
			this->eastLongitudeRadio->Text = L"E";
			this->eastLongitudeRadio->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(498, 450);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(105, 34);
			this->button1->TabIndex = 40;
			this->button1->Text = L"Reset";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// fixNoFixCheck
			// 
			this->fixNoFixCheck->AutoSize = true;
			this->fixNoFixCheck->Checked = true;
			this->fixNoFixCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->fixNoFixCheck->Location = System::Drawing::Point(12, 329);
			this->fixNoFixCheck->Name = L"fixNoFixCheck";
			this->fixNoFixCheck->Size = System::Drawing::Size(57, 17);
			this->fixNoFixCheck->TabIndex = 42;
			this->fixNoFixCheck->Text = L"Fix OK";
			this->fixNoFixCheck->UseVisualStyleBackColor = true;
			// 
			// speedBox
			// 
			this->speedBox->Location = System::Drawing::Point(399, 329);
			this->speedBox->Name = L"speedBox";
			this->speedBox->Size = System::Drawing::Size(85, 20);
			this->speedBox->TabIndex = 43;
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(263, 328);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(38, 13);
			this->label12->TabIndex = 44;
			this->label12->Text = L"Speed";
			// 
			// speedStepBox
			// 
			this->speedStepBox->Location = System::Drawing::Point(307, 328);
			this->speedStepBox->Name = L"speedStepBox";
			this->speedStepBox->Size = System::Drawing::Size(84, 20);
			this->speedStepBox->TabIndex = 45;
			// 
			// gnSelectRadio
			// 
			this->gnSelectRadio->AutoSize = true;
			this->gnSelectRadio->Location = System::Drawing::Point(106, 329);
			this->gnSelectRadio->Name = L"gnSelectRadio";
			this->gnSelectRadio->Size = System::Drawing::Size(41, 17);
			this->gnSelectRadio->TabIndex = 46;
			this->gnSelectRadio->TabStop = true;
			this->gnSelectRadio->Text = L"GN";
			this->gnSelectRadio->UseVisualStyleBackColor = true;
			// 
			// gpSelectRadio
			// 
			this->gpSelectRadio->AutoSize = true;
			this->gpSelectRadio->Location = System::Drawing::Point(106, 352);
			this->gpSelectRadio->Name = L"gpSelectRadio";
			this->gpSelectRadio->Size = System::Drawing::Size(40, 17);
			this->gpSelectRadio->TabIndex = 47;
			this->gpSelectRadio->TabStop = true;
			this->gpSelectRadio->Text = L"GP";
			this->gpSelectRadio->UseVisualStyleBackColor = true;
			// 
			// testButton
			// 
			this->testButton->Location = System::Drawing::Point(565, 329);
			this->testButton->Name = L"testButton";
			this->testButton->Size = System::Drawing::Size(38, 23);
			this->testButton->TabIndex = 48;
			this->testButton->Text = L"Test";
			this->testButton->UseVisualStyleBackColor = true;
			this->testButton->Click += gcnew System::EventHandler(this, &Form1::testButton_Click);
			// 
			// deadRadioButton
			// 
			this->deadRadioButton->AutoSize = true;
			this->deadRadioButton->Location = System::Drawing::Point(106, 375);
			this->deadRadioButton->Name = L"deadRadioButton";
			this->deadRadioButton->Size = System::Drawing::Size(51, 17);
			this->deadRadioButton->TabIndex = 49;
			this->deadRadioButton->TabStop = true;
			this->deadRadioButton->Text = L"Dead";
			this->deadRadioButton->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(618, 497);
			this->Controls->Add(this->deadRadioButton);
			this->Controls->Add(this->testButton);
			this->Controls->Add(this->gpSelectRadio);
			this->Controls->Add(this->gnSelectRadio);
			this->Controls->Add(this->speedStepBox);
			this->Controls->Add(this->label12);
			this->Controls->Add(this->speedBox);
			this->Controls->Add(this->fixNoFixCheck);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->groupBox5);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->timeBox);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->dateBox);
			this->Controls->Add(this->connectStatus);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comPortBox);
			this->DoubleBuffered = true;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->Name = L"Form1";
			this->Text = L"GPS Altitude Simulator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->altitudeStepBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->hoursStepBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->minutesStepBox))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->secondsStepBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->latitudeStepBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->longitudeStepBox))->EndInit();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
			this->groupBox7->ResumeLayout(false);
			this->groupBox7->PerformLayout();
			this->groupBox6->ResumeLayout(false);
			this->groupBox6->PerformLayout();
			this->groupBox5->ResumeLayout(false);
			this->groupBox5->PerformLayout();
			this->groupBox9->ResumeLayout(false);
			this->groupBox9->PerformLayout();
			this->groupBox8->ResumeLayout(false);
			this->groupBox8->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->speedStepBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e)
{
        if (!trackerConnected)
        {
            trackerPort = gcnew SerialPort();
            trackerConnected = true;
        }
        
        if (!trackerPort->IsOpen)
        {
            if (comPortBox->Text != "")
            {
                trackerPort->PortName = String::Concat( "COM", comPortBox->Text );

                trackerPort->BaudRate = 4800;
                trackerPort->Parity = Parity::None;
                trackerPort->StopBits = StopBits::One;
                trackerPort->DataBits = 8;
                trackerPort->Handshake = Handshake::None;
        
                try
                {
                    trackerPort->Open();
                    connectStatus->Text = "Ready";
                    startButton->Text = "Stop";
                    connectStatus->Text = "Running";
                    
                    if (altitudeBox->Text == "")
                    {
                        altitude = 0;
                    }
                    else
                    {
                        altitude = Convert::ToInt32( altitudeBox->Text );
                    }
                    latitude = Convert::ToInt32( latitudeBox->Text );
                    longitude = Convert::ToInt32( longitudeBox->Text );
                    
                    
                    
                    //Start
                    secTicker->Interval = 1000;
                    secTicker->Enabled = true;
                    secTicker->Start();
                    
                    altitudeBox->ReadOnly = true;
                }
                catch (System::IO::IOException ^ e)
                {
                    connectStatus->Text = e->Message;
//                    connectStatus->Text = "Com port: Reset the connection";
                }
                catch (UnauthorizedAccessException ^ f)
                {
                    connectStatus->Text = f->Message;
//                    connectStatus->Text = "Com port: No access";
                }
                catch (ArgumentOutOfRangeException ^)
                {
                    connectStatus->Text = "Com port: Illegal setting";
                }
                catch (ArgumentException ^)
                {
                    connectStatus->Text = "Com port: Invalid name";
                }
                catch (InvalidOperationException ^)
                {
                    connectStatus->Text = "Com port: Already open";
                }
            }
            else
            {
                connectStatus->Text = "Need port number";
            }
        }
        else
        {
            trackerPort->Close();
            startButton->Text = "Start";
            connectStatus->Text = "Idle";
            
            //Stop
            secTicker->Enabled = false;
            secTicker->Stop();
            altitudeBox->ReadOnly = false;
        }
}


private: System::Void secTicker_Tick(System::Object^  sender, System::EventArgs^  e)
{
    if (deadRadioButton->Checked == false)
    {
        const char * *pOut;
        int s = 0;
        char cStr[20];
        unsigned int degrees;
        unsigned int mins;
        unsigned int minsWhole;
        unsigned int minsFract;

        pOut = ((gnSelectRadio->Checked == true) ? gpsGnInstrument : gpsGpInstrument);
    
        altitudeStep = Convert::ToInt32( altitudeStepBox->Text );
        if (northStepRadio->Checked == northLatitudeRadio->Checked)
        {
            latitude += Convert::ToInt32( latitudeStepBox->Text );
        }
        else
        {
            latitude -= Convert::ToInt32( latitudeStepBox->Text );
            if (latitude < 0)
            {
                latitude = -latitude;
                if (northLatitudeRadio->Checked == true)
                {
                    southLatitudeRadio->Checked = true;
                }
                else
                {
                    northLatitudeRadio->Checked = true;
                }
            }
        }
        if (eastStepRadio->Checked == eastLongitudeRadio->Checked)
        {
            longitude += Convert::ToInt32( longitudeStepBox->Text );
        }
        else
        {
            longitude -= (int)Convert::ToInt32( longitudeStepBox->Text );
            if (longitude < 0)
            {
                longitude = -longitude;
                if (eastLongitudeRadio->Checked == true)
                {
                    westLongitudeRadio->Checked = true;
                }
                else
                {
                    eastLongitudeRadio->Checked = true;
                }
            }
        }

        //Time
        timeNow = DateTime::Now;
        timeNow = timeNow->AddHours( Convert::ToInt32( hoursStepBox->Text ) );
        timeNow = timeNow->AddMinutes( Convert::ToInt32( minutesStepBox->Text ) );
        timeNow = timeNow->AddSeconds( Convert::ToInt32( secondsStepBox->Text ) );

        unsigned char checksum = 0;
        while ((*pOut != 0) && (trackerConnected = true))
        {
            String ^time;
            try
            {
                const char *pString = *pOut;
                int length = strlen( pString );
                array<unsigned char>^ gpsString = gcnew array<unsigned char>( length );
                for (int i = 0; i < length; ++i)
                {
                    gpsString[i] = *pString;
                    ++pString;
                }
            
                checksum = runningCheck( *pOut, checksum );
                trackerPort->Write( gpsString, 0, length );

                switch (s)
                {
                    #if 1
                    case 1:
                        sprintf_s( cStr, sizeof(cStr), "%u"".00", Convert::ToInt32( speedStepBox->Text ) );
                        checksum = runningCheck( cStr, checksum );
                        break;
                    case 2:
                        sprintf_s( cStr, sizeof(cStr), "%02u", timeNow->Day );
                        sprintf_s( cStr + 2, sizeof(cStr) - 2, "%02u", timeNow->Month );
                        sprintf_s( cStr + 4, sizeof(cStr) - 4, "%02u", (timeNow->Year % 100) );
                        time = gcnew String( cStr );
                        dateBox->Text = time;
                        checksum = runningCheck( cStr, checksum );
                        break;

                    case 3:
                    case 12:
                    case 14:
                        //Check
                        checkString( cStr, checksum );
                        break;

                    case 0:
                    case 5:
                        sprintf_s( cStr, sizeof(cStr), "%02u", timeNow->Hour );
                        sprintf_s( cStr + 2, sizeof(cStr) - 2, "%02u", timeNow->Minute );
                        sprintf_s( cStr + 4, sizeof(cStr) - 4, "%02u", timeNow->Second );
                        time = gcnew String( cStr );
                        timeBox->Text = time;
                        checksum = runningCheck( cStr, checksum );
                        break;

                    case 6:
                        if (fixNoFixCheck->Checked == true)
                        {
                            degrees = latitude / 100000;
                            mins = (latitude % 100000) * 60;
                            minsWhole = mins / 100000; 
                            minsFract = mins % 100000; 
                            sprintf_s( cStr, sizeof(cStr), "%02u""%02u"".""%05u", degrees, minsWhole, minsFract );
                        }
                        else
                        {
                            strcpy_s( cStr, sizeof(cStr), "" );
                        }
                        checksum = runningCheck( cStr, checksum );
                        break;

                    case 7:
                        //North/South
                        strcpy_s( cStr, sizeof(cStr), (northLatitudeRadio->Checked == true) ? "N" : "S" );
                        checksum = runningCheck( cStr, checksum );
                        break;

                    case 8:
                        if (fixNoFixCheck->Checked == true)
                        {
                            degrees = longitude / 100000;
                            mins = (longitude % 100000) * 60;
                            minsWhole = mins / 100000; 
                            minsFract = mins % 100000; 
                            sprintf_s( cStr, sizeof(cStr), "%03u""%02u"".""%05u", degrees, minsWhole, minsFract );
                        }
                        else
                        {
                            strcpy_s( cStr, sizeof(cStr), "" );
                        }
                        checksum = runningCheck( cStr, checksum );
                        break;

                    case 9:
                        //East/West
                        strcpy_s( cStr, sizeof(cStr), (eastLongitudeRadio->Checked == true) ? "E" : "W" );
                        checksum = runningCheck( cStr, checksum );
                        break;

                    case 10:
                        //Fix/no fix
                        strcpy_s( cStr, sizeof(cStr), (fixNoFixCheck->Checked == true) ? "1" : "0" );
                        checksum = runningCheck( cStr, checksum );
                        break;

                    case 11:
                        Convert::ToInt32( s );
                        if (altitudeDirection == GPS_TRACK_DIRECTION::UP)
                        {
                            altitude += altitudeStep;
                        }
                        else if (altitudeDirection == GPS_TRACK_DIRECTION::DOWN)
                        {
                            altitude -= altitudeStep;
                        }
                        sprintf_s( cStr, sizeof(cStr), "%i", altitude );
                        altitudeBox->Text = Convert::ToString( altitude );
                        checksum = runningCheck( cStr, checksum );
                        break;

                    #else
                    case 0:
                        sprintf_s( cStr, sizeof(cStr), "%02u", timeNow->Hour );
                        sprintf_s( cStr + 2, sizeof(cStr) - 2, "%02u", timeNow->Minute );
                        sprintf_s( cStr + 4, sizeof(cStr) - 4, "%02u", timeNow->Second );
                        time = gcnew String( cStr );
                        timeBox->Text = time;
                    
                        sprintf_s( cStr, sizeof(cStr), "%02u", timeNow->Day );
                        sprintf_s( cStr + 2, sizeof(cStr) - 2, "%02u", timeNow->Month );
                        sprintf_s( cStr + 4, sizeof(cStr) - 4, "%02u", (timeNow->Year % 100) );
                        time = gcnew String( cStr );
                        dateBox->Text = time;
                    
                        //RMC Check
                        checkString( cStr, checksum );
                        break;

                    case 1:
                        //crlf
                        checksum = 0;
                        break;
                    
                    case 2:
                        //GGA Check
                        checkString( cStr, checksum );
                        break;
                
                    case 3:
                        //crlf
                        checksum = 0;
                        break;
                    
                    case 4:
                        //GSA Check
                        checkString( cStr, checksum );
                        break;
                
                    #endif
                
                    default:
                        checksum = 0;
                        cStr[0] = '\0';
                        break;
                }
                length = strlen( cStr );
                array<unsigned char>^ insertString = gcnew array<unsigned char>( length );
                for (int i = 0; i < length; ++i)
                {
                    insertString[i] = cStr[i];
                }
                trackerPort->Write( insertString, 0, insertString->Length );
                ++s;
            }
            catch (System::IO::IOException ^)
            {
                connectStatus->Text = "Reset the connection";
                try
                {
                    trackerPort->~SerialPort();
                }
                catch (System::IO::IOException ^)
                {
                }
                trackerConnected = false;

                startButton->Text = "Start";
            }
        
            ++pOut;
        }

        latitudeBox->Text = Convert::ToString( latitude );
        longitudeBox->Text = Convert::ToString( longitude );
    }
}


private: System::Void altitudeStepBox_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
    altitudeStep = Convert::ToInt32( altitudeStepBox->Text );
}


private: System::Void radioButton1_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
    altitudeDirection = GPS_TRACK_DIRECTION::UP;
}

private: System::Void radioButton2_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
    altitudeDirection = GPS_TRACK_DIRECTION::DOWN;
}

private: System::Void radioButton3_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
{
    altitudeDirection = GPS_TRACK_DIRECTION::PAUSE;
}

private: System::Void hoursStepBox_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
}

private: System::Void minutesStepBox_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
}


private: System::Void secondsStepBox_ValueChanged(System::Object^  sender, System::EventArgs^  e)
{
}


private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
    gpsTrack->setDirection( GPS_TRACK_DIRECTION::UP );
    gpsTrack->setAltitudeStep( "0" );
    upRadio->Checked = true;
    eastStepRadio->Checked = true;
    northStepRadio->Checked = true;
    northLatitudeRadio->Checked = true;
    eastLongitudeRadio->Checked = true;
    latitudeStepBox->Text = "0";
    longitudeStepBox->Text = "0";
    latitudeBox->Text = "5160526";
    longitudeBox->Text = "29768";
    altitudeBox->Text == "0";

    altitude = 0;
    latitude = Convert::ToInt32( latitudeBox->Text );
    longitude = Convert::ToInt32( longitudeBox->Text );
}





	private: unsigned char runningCheck( const char *p, unsigned char sum )
	{
        while (*p != '\0')
		{
            if ((*p != '$') && (*p != '*'))
            {
		        sum ^= *p;
            }
            
            ++p;
		}
        
        return(sum);
	}


	private: void checkString( char *p, unsigned char sum )
	{
        char upper = (sum >> 4) & 0x0f;
		upper +=  (upper < 10) ? '0' : 'a' - 0x0a;
        *p = upper;
        
        ++p;
		
		char lower = sum & 0x0f;
		lower +=  (lower < 10) ? '0' : 'a' - 0x0a;
        *p = lower;
        
        *p++;
        
        *p = '\0';
	}

    private: System::Void testButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
    }

};




}

