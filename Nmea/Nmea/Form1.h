#pragma once
#include <cstring>
#include <cstdio>
#include <cstdlib>

#include "gps.h"
using namespace std;

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



namespace GPS_TRACK_DIRECTION
{
        enum
        {
            UP,
            DOWN,
            PAUSE,
        };
}

namespace Nmea
{
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
            bigTicks = 0;
            gpsTrack = gcnew GpsTrack();
            resetCourse();
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
            GpsTrack^ gpsTrack;
            DateTime^ timeNow;

            int altitude;
            int altitudeDirection;
            int altitudeStep;
            int _lastLength;
            int bigTicks;




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
































    	private: System::Windows::Forms::Button^  button1;




        private: System::Windows::Forms::Label^  showLongitude;

        private: System::Windows::Forms::Label^  showLatitude;



        private: System::Windows::Forms::Label^  label12;
        private: System::Windows::Forms::NumericUpDown^  speedStepBox;


        private: System::Windows::Forms::Button^  testButton;

        private: System::Windows::Forms::TextBox^  courseBox;

        private: System::Windows::Forms::Label^  label9;
        private: System::Windows::Forms::Label^  label10;

        private: System::Windows::Forms::GroupBox^  groupBox3;
        private: System::Windows::Forms::CheckBox^  trackPauseCheckBox;

private: System::Windows::Forms::Label^  showSpeed;
private: System::Windows::Forms::Label^  showAltitude;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::Label^  label13;



private: System::Windows::Forms::TextBox^  log;
private: System::Windows::Forms::TextBox^  instrumentBox;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::GroupBox^  groupBox4;
private: System::Windows::Forms::RadioButton^  instrument;

private: System::Windows::Forms::RadioButton^  gpsDead;
private: System::Windows::Forms::RadioButton^  gpsOk;
private: System::Windows::Forms::Button^  instrumentSend;
private: System::Windows::Forms::ComboBox^  outputPeriod;















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
			this->showLatitude = (gcnew System::Windows::Forms::Label());
			this->showLongitude = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->speedStepBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->testButton = (gcnew System::Windows::Forms::Button());
			this->courseBox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->showSpeed = (gcnew System::Windows::Forms::Label());
			this->showAltitude = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->trackPauseCheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->log = (gcnew System::Windows::Forms::TextBox());
			this->instrumentBox = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
			this->instrument = (gcnew System::Windows::Forms::RadioButton());
			this->gpsDead = (gcnew System::Windows::Forms::RadioButton());
			this->gpsOk = (gcnew System::Windows::Forms::RadioButton());
			this->instrumentSend = (gcnew System::Windows::Forms::Button());
			this->outputPeriod = (gcnew System::Windows::Forms::ComboBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->altitudeStepBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hoursStepBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minutesStepBox))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->secondsStepBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->speedStepBox))->BeginInit();
			this->groupBox3->SuspendLayout();
			this->groupBox4->SuspendLayout();
			this->SuspendLayout();
			// 
			// comPortBox
			// 
			this->comPortBox->Location = System::Drawing::Point(313, 22);
			this->comPortBox->Name = L"comPortBox";
			this->comPortBox->Size = System::Drawing::Size(46, 20);
			this->comPortBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(251, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L" Com Port:";
			// 
			// altitudeBox
			// 
			this->altitudeBox->Location = System::Drawing::Point(11, 24);
			this->altitudeBox->Name = L"altitudeBox";
			this->altitudeBox->Size = System::Drawing::Size(62, 20);
			this->altitudeBox->TabIndex = 2;
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(21, 499);
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
			this->connectStatus->Location = System::Drawing::Point(18, 549);
			this->connectStatus->Name = L"connectStatus";
			this->connectStatus->Size = System::Drawing::Size(77, 13);
			this->connectStatus->TabIndex = 10;
			this->connectStatus->Text = L"No connection";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(8, 59);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 13);
			this->label5->TabIndex = 15;
			this->label5->Text = L"Step:";
			// 
			// altitudeStepBox
			// 
			this->altitudeStepBox->Location = System::Drawing::Point(46, 59);
			this->altitudeStepBox->Name = L"altitudeStepBox";
			this->altitudeStepBox->Size = System::Drawing::Size(46, 20);
			this->altitudeStepBox->TabIndex = 16;
			this->altitudeStepBox->ValueChanged += gcnew System::EventHandler(this, &Form1::altitudeStepBox_ValueChanged);
			// 
			// upRadio
			// 
			this->upRadio->AutoSize = true;
			this->upRadio->Location = System::Drawing::Point(11, 81);
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
			this->downRadio->Location = System::Drawing::Point(11, 102);
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
			this->pauseRadio->Location = System::Drawing::Point(11, 125);
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
			this->hoursStepBox->Location = System::Drawing::Point(60, 29);
			this->hoursStepBox->Name = L"hoursStepBox";
			this->hoursStepBox->Size = System::Drawing::Size(40, 20);
			this->hoursStepBox->TabIndex = 24;
			this->hoursStepBox->ValueChanged += gcnew System::EventHandler(this, &Form1::hoursStepBox_ValueChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(10, 29);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(35, 13);
			this->label6->TabIndex = 25;
			this->label6->Text = L"Hours";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(10, 55);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(44, 13);
			this->label7->TabIndex = 26;
			this->label7->Text = L"Minutes";
			// 
			// minutesStepBox
			// 
			this->minutesStepBox->Location = System::Drawing::Point(60, 55);
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
			this->groupBox1->Location = System::Drawing::Point(253, 77);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(106, 154);
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
			this->groupBox2->Location = System::Drawing::Point(253, 272);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(106, 124);
			this->groupBox2->TabIndex = 29;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Advance time";
			// 
			// secondsStepBox
			// 
			this->secondsStepBox->Location = System::Drawing::Point(60, 82);
			this->secondsStepBox->Name = L"secondsStepBox";
			this->secondsStepBox->Size = System::Drawing::Size(41, 20);
			this->secondsStepBox->TabIndex = 29;
			this->secondsStepBox->ValueChanged += gcnew System::EventHandler(this, &Form1::secondsStepBox_ValueChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(10, 82);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(49, 13);
			this->label2->TabIndex = 28;
			this->label2->Text = L"Seconds";
			// 
			// showLatitude
			// 
			this->showLatitude->AutoSize = true;
			this->showLatitude->Location = System::Drawing::Point(58, 177);
			this->showLatitude->Name = L"showLatitude";
			this->showLatitude->Size = System::Drawing::Size(13, 13);
			this->showLatitude->TabIndex = 45;
			this->showLatitude->Text = L"0";
			// 
			// showLongitude
			// 
			this->showLongitude->AutoSize = true;
			this->showLongitude->Location = System::Drawing::Point(58, 190);
			this->showLongitude->Name = L"showLongitude";
			this->showLongitude->Size = System::Drawing::Size(13, 13);
			this->showLongitude->TabIndex = 44;
			this->showLongitude->Text = L"0";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(93, 264);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(53, 34);
			this->button1->TabIndex = 40;
			this->button1->Text = L"Reset";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(7, 144);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(74, 13);
			this->label12->TabIndex = 44;
			this->label12->Text = L"Speed (Knots)";
			// 
			// speedStepBox
			// 
			this->speedStepBox->Location = System::Drawing::Point(87, 144);
			this->speedStepBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000, 0, 0, 0 });
			this->speedStepBox->Name = L"speedStepBox";
			this->speedStepBox->Size = System::Drawing::Size(59, 20);
			this->speedStepBox->TabIndex = 45;
			// 
			// testButton
			// 
			this->testButton->Location = System::Drawing::Point(200, 499);
			this->testButton->Name = L"testButton";
			this->testButton->Size = System::Drawing::Size(38, 23);
			this->testButton->TabIndex = 48;
			this->testButton->Text = L"Test";
			this->testButton->UseVisualStyleBackColor = true;
			this->testButton->Click += gcnew System::EventHandler(this, &Form1::testButton_Click);
			// 
			// courseBox
			// 
			this->courseBox->Location = System::Drawing::Point(10, 35);
			this->courseBox->Multiline = true;
			this->courseBox->Name = L"courseBox";
			this->courseBox->Size = System::Drawing::Size(136, 91);
			this->courseBox->TabIndex = 50;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(7, 177);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(45, 13);
			this->label9->TabIndex = 52;
			this->label9->Text = L"Latitude";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(8, 190);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(54, 13);
			this->label10->TabIndex = 53;
			this->label10->Text = L"Longitude";
			// 
			// groupBox3
			// 
			this->groupBox3->Controls->Add(this->label14);
			this->groupBox3->Controls->Add(this->label13);
			this->groupBox3->Controls->Add(this->showSpeed);
			this->groupBox3->Controls->Add(this->showAltitude);
			this->groupBox3->Controls->Add(this->label11);
			this->groupBox3->Controls->Add(this->label8);
			this->groupBox3->Controls->Add(this->trackPauseCheckBox);
			this->groupBox3->Controls->Add(this->button1);
			this->groupBox3->Controls->Add(this->label10);
			this->groupBox3->Controls->Add(this->label9);
			this->groupBox3->Controls->Add(this->showLongitude);
			this->groupBox3->Controls->Add(this->courseBox);
			this->groupBox3->Controls->Add(this->showLatitude);
			this->groupBox3->Controls->Add(this->speedStepBox);
			this->groupBox3->Controls->Add(this->label12);
			this->groupBox3->Location = System::Drawing::Point(21, 77);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(179, 319);
			this->groupBox3->TabIndex = 55;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Ground Track";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(77, 216);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(34, 13);
			this->label14->TabIndex = 60;
			this->label14->Text = L"Knots";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(77, 203);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(39, 13);
			this->label13->TabIndex = 59;
			this->label13->Text = L"Meters";
			// 
			// showSpeed
			// 
			this->showSpeed->AutoSize = true;
			this->showSpeed->Location = System::Drawing::Point(58, 216);
			this->showSpeed->Name = L"showSpeed";
			this->showSpeed->Size = System::Drawing::Size(13, 13);
			this->showSpeed->TabIndex = 58;
			this->showSpeed->Text = L"0";
			// 
			// showAltitude
			// 
			this->showAltitude->AutoSize = true;
			this->showAltitude->Location = System::Drawing::Point(58, 203);
			this->showAltitude->Name = L"showAltitude";
			this->showAltitude->Size = System::Drawing::Size(13, 13);
			this->showAltitude->TabIndex = 57;
			this->showAltitude->Text = L"0";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(8, 216);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(38, 13);
			this->label11->TabIndex = 56;
			this->label11->Text = L"Speed";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(8, 203);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(42, 13);
			this->label8->TabIndex = 55;
			this->label8->Text = L"Altitude";
			// 
			// trackPauseCheckBox
			// 
			this->trackPauseCheckBox->AutoSize = true;
			this->trackPauseCheckBox->Location = System::Drawing::Point(11, 274);
			this->trackPauseCheckBox->Name = L"trackPauseCheckBox";
			this->trackPauseCheckBox->Size = System::Drawing::Size(56, 17);
			this->trackPauseCheckBox->TabIndex = 54;
			this->trackPauseCheckBox->Text = L"Pause";
			this->trackPauseCheckBox->UseVisualStyleBackColor = true;
			// 
			// log
			// 
			this->log->AcceptsReturn = true;
			this->log->AcceptsTab = true;
			this->log->Location = System::Drawing::Point(452, 172);
			this->log->Multiline = true;
			this->log->Name = L"log";
			this->log->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->log->Size = System::Drawing::Size(462, 372);
			this->log->TabIndex = 60;
			// 
			// instrumentBox
			// 
			this->instrumentBox->Location = System::Drawing::Point(452, 34);
			this->instrumentBox->Multiline = true;
			this->instrumentBox->Name = L"instrumentBox";
			this->instrumentBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->instrumentBox->Size = System::Drawing::Size(462, 87);
			this->instrumentBox->TabIndex = 57;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(449, 18);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(87, 13);
			this->label15->TabIndex = 61;
			this->label15->Text = L"Instrument Nmea";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(448, 159);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(65, 13);
			this->label16->TabIndex = 62;
			this->label16->Text = L"Tracker Log";
			// 
			// groupBox4
			// 
			this->groupBox4->Controls->Add(this->instrument);
			this->groupBox4->Controls->Add(this->gpsDead);
			this->groupBox4->Controls->Add(this->gpsOk);
			this->groupBox4->Location = System::Drawing::Point(21, 402);
			this->groupBox4->Name = L"groupBox4";
			this->groupBox4->Size = System::Drawing::Size(179, 77);
			this->groupBox4->TabIndex = 63;
			this->groupBox4->TabStop = false;
			this->groupBox4->Text = L"Mode";
			// 
			// instrument
			// 
			this->instrument->AutoSize = true;
			this->instrument->Location = System::Drawing::Point(14, 49);
			this->instrument->Name = L"instrument";
			this->instrument->Size = System::Drawing::Size(125, 17);
			this->instrument->TabIndex = 2;
			this->instrument->Text = L"Instrument Input Only";
			this->instrument->UseVisualStyleBackColor = true;
			// 
			// gpsDead
			// 
			this->gpsDead->AutoSize = true;
			this->gpsDead->Location = System::Drawing::Point(14, 34);
			this->gpsDead->Name = L"gpsDead";
			this->gpsDead->Size = System::Drawing::Size(76, 17);
			this->gpsDead->TabIndex = 1;
			this->gpsDead->Text = L"GPS Dead";
			this->gpsDead->UseVisualStyleBackColor = true;
			// 
			// gpsOk
			// 
			this->gpsOk->AutoSize = true;
			this->gpsOk->Checked = true;
			this->gpsOk->Location = System::Drawing::Point(14, 19);
			this->gpsOk->Name = L"gpsOk";
			this->gpsOk->Size = System::Drawing::Size(64, 17);
			this->gpsOk->TabIndex = 0;
			this->gpsOk->TabStop = true;
			this->gpsOk->Text = L"GPS Ok";
			this->gpsOk->UseVisualStyleBackColor = true;
			// 
			// instrumentSend
			// 
			this->instrumentSend->Location = System::Drawing::Point(863, 127);
			this->instrumentSend->Name = L"instrumentSend";
			this->instrumentSend->Size = System::Drawing::Size(51, 20);
			this->instrumentSend->TabIndex = 64;
			this->instrumentSend->Text = L"Send";
			this->instrumentSend->UseVisualStyleBackColor = true;
			this->instrumentSend->Click += gcnew System::EventHandler(this, &Form1::instrumentSend_Click);
			// 
			// outputPeriod
			// 
			this->outputPeriod->FormattingEnabled = true;
			this->outputPeriod->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				L"100", L"200", L"300", L"400", L"500", L"600",
					L"700", L"800", L"900", L"1000"
			});
			this->outputPeriod->Location = System::Drawing::Point(310, 462);
			this->outputPeriod->Name = L"outputPeriod";
			this->outputPeriod->Size = System::Drawing::Size(65, 21);
			this->outputPeriod->TabIndex = 65;
			this->outputPeriod->Text = L"Period";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(926, 585);
			this->Controls->Add(this->outputPeriod);
			this->Controls->Add(this->instrumentSend);
			this->Controls->Add(this->groupBox4);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->label15);
			this->Controls->Add(this->instrumentBox);
			this->Controls->Add(this->log);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->testButton);
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
			this->Text = L"GPS Simulator";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->altitudeStepBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->hoursStepBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->minutesStepBox))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->secondsStepBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->speedStepBox))->EndInit();
			this->groupBox3->ResumeLayout(false);
			this->groupBox3->PerformLayout();
			this->groupBox4->ResumeLayout(false);
			this->groupBox4->PerformLayout();
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

                        gpsTrack->start( courseBox->Text, speedStepBox->Text );
                        
                        
                        
                        //Start
                        secTicker->Interval = 100;
                        secTicker->Enabled = true;
                        secTicker->Start();
                        
                        altitudeBox->ReadOnly = true;
                    }
                    catch (System::IO::IOException ^ e)
                    {
                        connectStatus->Text = e->Message;
                    }
                    catch (UnauthorizedAccessException ^ f)
                    {
                        connectStatus->Text = f->Message;
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
            int length = trackerPort->BytesToRead;
            if (length != 0)
            {
                /* Allow com input to settle */
                if (length == _lastLength)
                {
                    _lastLength = 0;
                    
                    /* Get received bytes */
                    array<unsigned char>^ a = gcnew array<unsigned char>( length );
                    trackerPort->Read( a, 0, length );
                    arrayToLogText( a );
                }
                else
                {
                    /* Com input not settled */
                    _lastLength = length;
                }
            }
                

            ++bigTicks;
            if (bigTicks >= outputPeriod->SelectedIndex)
            {
                bigTicks = 0;
                if (instrument->Checked == true)
                {
                    array<unsigned char>^ buffer = stringToArray( instrumentBox->Text );
                    trackerPort->Write( buffer, 0, buffer->Length );
                }
                else if (gpsDead->Checked == false)
                {
                    const char * *pOut;
                    int s = 0;
                    char cStr[20];
                    unsigned int degrees;
                    unsigned int mins;
                    unsigned int minsWhole;
                    unsigned int minsFract;

                    pOut = gpsGpInstrument;
                
                    altitudeStep = Convert::ToInt32( altitudeStepBox->Text );


                    int speed;

                    if (gpsTrack->isTrackSpeed())
                    {
                        speed = gpsTrack->speed();
                    }
                    else
                    {
                        speed = Convert::ToInt32( speedStepBox->Text );
                    }

                    if (trackPauseCheckBox->Checked == false)
                    {
                        gpsTrack->nextPosition( speed );
                    }
                    int latitude = gpsTrack->latitude();
                    int longitude = gpsTrack->longitude();

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
                            case 1:
                                    {

                                        sprintf_s( cStr, sizeof(cStr), "%u"".00", speed );
                                        checksum = runningCheck( cStr, checksum );
                                    }
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
                                    //checkString( cStr, 0 );
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
                                    if (gpsOk->Checked == true)
                                    {
                                        degrees = abs( latitude ) / 100000;
                                        mins = (abs( latitude ) % 100000) * 60;
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
                                    strcpy_s( cStr, sizeof(cStr), (latitude >= 0) ? "N" : "S" );
                                    checksum = runningCheck( cStr, checksum );
                                    break;

                                case 8:
                                    if (gpsOk->Checked == true)
                                    {
                                        degrees = abs( longitude ) / 100000;
                                        mins = (abs( longitude ) % 100000) * 60;
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
                                    strcpy_s( cStr, sizeof(cStr), (longitude >= 0) ? "E" : "W" );
                                    checksum = runningCheck( cStr, checksum );
                                    break;

                                case 10:
                                    //Fix/no fix
                                    strcpy_s( cStr, sizeof(cStr), (gpsOk->Checked == true) ? "1" : "0" );
                                    checksum = runningCheck( cStr, checksum );
                                    break;

                            case 11:
                                    if (gpsTrack->isTrackHeight())
                                    {
                                        altitude = gpsTrack->altitude();
                                    }
                                    else
                                    {
                                        Convert::ToInt32( s );
                                        if (altitudeDirection == GPS_TRACK_DIRECTION::UP)
                                        {
                                            altitude += altitudeStep;
                                        }
                                        else if (altitudeDirection == GPS_TRACK_DIRECTION::DOWN)
                                        {
                                            altitude -= altitudeStep;
                                        }

                                        altitudeBox->Text = Convert::ToString( altitude );
                                    }
                                    sprintf_s( cStr, sizeof(cStr), "%i", altitude );
                                    checksum = runningCheck( cStr, checksum );
                                    break;

                            
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

                            showLatitude->Text = Convert::ToString( latitude );
                            showLongitude->Text = Convert::ToString( longitude );
                            showAltitude->Text = Convert::ToString( altitude );
                            showSpeed->Text = Convert::ToString( speed );
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

                }
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
            resetCourse();
            gpsTrack->start( courseBox->Text, speedStepBox->Text );
        }





       private: void resetCourse( void )
       {
           upRadio->Checked = true;
           altitudeBox->Text == "0";

           altitude = 0;
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

        /* Makes a character array from a string object containing normal text */
        private:array<unsigned char> ^stringToArray( String ^s )
        {
            int length = s->Length;

            array<unsigned char>^ a = gcnew array<unsigned char>( length );

            for (int i = 0; i < length; ++i)
            {
                a[i] = (unsigned char)s[i];
            }

            return(a);
        }


        private:void arrayToLogText( array<unsigned char> ^a )
        {
            int length = a->Length;

            char buffer[100];

            int i = 0;
            int b = 0;

            while (i < length)
            {
                char character = (char)a[i];
                if (character == '\x0a')
                {
                    buffer[b] = '\x0d';
                    ++b;
                }
                ++i;

                if (character != '\x0d')
                {
                    buffer[b] = character;
                    ++b;
                }

                if ((b >= 80) || (i == length))
                {
                    buffer[b] = '\0';
                    b = 0;

                    String^ s = gcnew String( buffer );

                    int sizeNow = log->Text->Length;
                    if (sizeNow > 0x4000)
                    {
                        log->Text = log->Text->Substring( sizeNow);
                    }

                    log->AppendText( s );


                }
            }

        }


        private: System::Void testButton_Click(System::Object^  sender, System::EventArgs^  e)
        {
            log->Clear();
        }







        private: System::Void instrumentSend_Click(System::Object^  sender, System::EventArgs^  e)
        {
            if (gpsDead->Checked == true)
            {
                array<unsigned char>^ buffer = stringToArray( instrumentBox->Text );
                trackerPort->Write( buffer, 0, buffer->Length );
            }
        }
};




}

