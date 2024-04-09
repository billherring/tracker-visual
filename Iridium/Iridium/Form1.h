#pragma once
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

namespace HAYES
{
    enum
    {
        CMD_ATTENTION  = 0 ,
        CMD_WRITE_BINARY            ,
        CMD_RADIO_ON                ,
        CMD_TIME                    ,
        CMD_SIGNAL                  ,
        CMD_SESSION                 ,
        CMD_SESSION_MK2             ,
        CMD_READ_BINARY             ,
        CMD_CLEAR                   ,
        CMD_RADIO_OFF               ,
        CMD_SERIAL_NO               ,
        CMD_REVISION                ,
        CMD_POWER_OFF               ,
        CMD_RINGS_ON                ,
        CMD_RINGS_OFF               ,

        GPRS_CMD_APN                ,
        GPRS_CMD_DYNAMIC_ADDRESS    ,
        GPRS_CMD_DNS_PRIMARY        ,
        GPRS_CMD_DNS_SECONDARY      ,
        GPRS_CMD_USERNAME           ,
        GPRS_CMD_PASSWORD           ,
        GPRS_CMD_CHAP               ,           
        GPRS_CMD_SET_PSD_PROFILE    , 
        GPRS_CMD_MAP_PSD_PROFILE    ,
        GPRS_CMD_ACTIVATE_PROFILE   ,
        GPRS_CMD_CREATE_SOCKET      ,
        GPRS_CMD_CONNECT_SOCKET     ,
        GPRS_CMD_SOCKET_WRITE       ,
        GPRS_CMD_SOCKET_DATA        ,
        GPRS_CMD_SOCKET_READ        ,
        GPRS_CMD_SOCKET_CLOSE       ,
        GPRS_CMD_DEACTIVATE_PROFILE ,
        GPRS_CMD_SIGNAL             ,
        GPRS_CMD_MSISDN             ,
        GPRS_CMD_STATUS             ,
        GPRS_CMD_GPRS_STATUS        ,
        GPRS_CMD_SIM_NO             ,
        GPRS_CMD_IMEI               ,
        GPRS_CMD_OPERATOR_2         ,
        GPRS_CMD_OPERATOR           ,
        GPRS_CMD_COUNTRY            ,
        GPRS_CMD_DEREGISTER         ,
        GPRS_CMD_POWEROFF           ,
        GPRS_CMD_SIGN_OFF           ,
        GPRS_CMD_CELLULAR_ON        ,
        GPRS_CMD_DNS_TEST           ,
        GPRS_CMD_EVENT_URC          ,
        GPRS_CMD_STATUS_URC         ,
        GPRS_CMD_GPRS_STATUS_URC    ,
        GPRS_CMD_VERBOSE            ,
        GPRS_CMD_DISABLE_WI         ,
        GPRS_CMD_OPERATOR_ALPHA     ,  
        GPRS_CMD_OPERATOR_NUMERIC   ,
        GPRS_CMD_HEX_MODE           ,
        GPRS_CMD_DISABLE_HEX_MODE   ,
        CMD_HELLO                   ,

        CMD_SESSION_FINISH          ,
        CMD_RING                    ,
        
        GPRS_RSP_NOT_REG_URC        ,     
        GPRS_RSP_REGISTERED_URC     ,   
        GPRS_RSP_EVENT_URC          ,         
        GPRS_RSP_UMWI_URC           ,      
        GPRS_RSP_PSD_CONTEXT_URC    ,      
        
        CMD_END                     ,
    };


    const char *hayesIn[] =
    {
        "ATE0",        /* CMD_ATTENTION      = 0, */
        "AT+SBDWB=",   /* CMD_WRITE_BINARY   , */
        "AT*R1",       /* CMD_RADIO_ON       , */
        "AT-MSSTM",    /* CMD_TIME           , */
        "AT+CSQ",      /* CMD_SIGNAL         , */
        "AT+SBDIX",    /* CMD_SESSION        , */
        "AT+SBDI",     /* CMD_SESSION_MK"    , */
        "AT+SBDRB",    /* CMD_READ_BINARY    , */
        "AT+SBDD2",    /* CMD_CLEAR          , */
        "AT*R0",       /* CMD_RADIO_OFF      , */
        "AT+CGSN",     /* CMD_SERIAL_NO      , */
        "ATI3",     /* CMD_REVISION      , */
        "AT*F",        /* CMD_POWER_OFF      , */
        "AT+SBDMTA=1", /* CMD_RINGS_ON       , */
        "AT+SBDMTA=0", /* CMD_RINGS_OFF      , */

        "AT+UPSD=0,1",  /* GPRS_CMD_APN,                */
        "AT+UPSD=0,7",  /* GPRS_CMD_DYNAMIC_ADDRESS,    */
        "AT+UPSD=0,4",  /* GPRS_CMD_DNS_PRIMARY,        */
        "AT+UPSD=0,5",  /* GPRS_CMD_DNS_SECONDARY,      */
        "AT+UPSD=0,2",  /* GPRS_CMD_USERNAME,           */
        "AT+UPSD=0,3",  /* GPRS_CMD_PASSWORD,           */
        "AT+UPSD=0,6",    /* GPRS_CMD_CHAP,             */
        "AT+UPSD=0,0,0",  /* GPRS_CMD_SET_PSD_PROFILE   */
        "AT+UPSD=0,100,1",/* GPRS_CMD_MAP_PSD_PROFILE,  */
        "AT+UPSDA=0,3", /* GPRS_CMD_ACTIVATE_PROFILE,   */
        "AT+USOCR=6",   /* GPRS_CMD_CREATE_SOCKET,      */
        "AT+USOCO=0",   /* GPRS_CMD_CONNECT_SOCKET,     */
        "AT+USOWR=0",   /* GPRS_CMD_SOCKET_WRITE,       */
        "ATSPIDATA",    /* GPRS_CMD_SOCKET_DATA,        */
        "AT+USORD",     /* GPRS_CMD_SOCKET_READ,        */
        "AT+USOCL=0",   /* GPRS_CMD_SOCKET_CLOSE,       */
        "AT+UPSDA=0,4", /* GPRS_CMD_DEACTIVATE_PROFILE, */
        "AT+CSQ",       /* GPRS_CMD_SIGNAL,             */
        "AT+CNUM",      /* GPRS_CMD_MSISDN,             */
        "AT+CREG?",     /* GPRS_CMD_STATUS,             */
        "AT+CGREG?",    /* GPRS_CMD_GPRS_STATUS,        */
        "AT+CCID",      /* GPRS_CMD_SIM_NO,             */
        "AT+CGSN",      /* GPRS_CMD_IMEI,               */
        "AT+COPS?",     /* GPRS_CMD_OPERATOR_2,         */
        "AT+UDOPN=4",   /* GPRS_CMD_OPERATOR,           */
        "AT+UDOPN=0",   /* GPRS_CMD_COUNTRY,            */
        "AT+CGATT=0",   /* GPRS_CMD_DEREGISTER,         */
        "AT+CPWROFF",   /* GPRS_CMD_POWEROFF,           */
        "AT+CFUN=0",    /* GPRS_CMD_SIGN_OFF,           */
        "AT+CFUN=1",    /* GPRS_CMD_CELLULAR_ON,        */
        "AT+UDNSRN=0",  /* GPRS_CMD_DNS_TEST,           */
        "AT+CGEREP=0",  /* GPRS_CMD_EVENT_URC,          */
        "AT+CREG=1",    /* GPRS_CMD_STATUS_URC,         */
        "AT+CGREG=1",   /* GPRS_CMD_GPRS_STATUS_URC,    */
        "AT+CMEE=1",    /* GPRS_CMD_VERBOSE,            */
        "AT+UMWI=0",    /* GPRS_CMD_DISABLE_WI,         */
        "AT+COPS=3,0",  /* GPRS_CMD_OPERATOR_ALPHA,     */
        "AT+COPS+3,2",  /* GPRS_CMD_OPERATOR_NUMERIC,   */
        "AT+UDCONF=1,1",/* GPRS_CMD_HEX_MODE,           */
        "AT+UDCONF=1,0",/* GPRS_CMD_DISABLE_HEX_MODE,   */
        "AT",           /* CMD_HELLO          ,         */
                                                        
        0,              /* CMD_SESSION_FINISH ,         */
        0               /* CMD_END            ,         */
    };


    const char *hayesOut[] =
    {
        "\x0d\x0a""OK""\x0d\x0a",                                 /* CMD_ATTENTION      = 0, */
        "\x0d\x0a""READY""\x0d\x0a",                              /* CMD_WRITE_BINARY   , */
        "\x0d\x0a""OK""\x0d\x0a",                                 /* CMD_RADIO_ON       , */
        "\x0d\x0a""-MSSTM:xxxxxxxx""\x0d\x0a""OK""\x0d\x0a",      /* CMD_TIME           , */
        "\x0d\x0a""+CSQ:5""\x0d\x0a""OK""\x0d\x0a",               /* CMD_SIGNAL         , */
        "\x0d\x0a""+SBDIX:",                                      /* CMD_SESSION        , */
        "\x0d\x0a""+SBDI:",                                       /* CMD_SESSION_MK2    , */
        "\x0d\x0a""\x06\x3e\x09\x09\x09\x09\x09\x63",             /* CMD_READ_BINARY    , */
        "\x0d\x0a""0""\x0d\x0a""OK""\x0d\x0a",                    /* CMD_CLEAR          , */
        "\x0d\x0a""OK""\x0d\x0a",                                 /* CMD_RADIO_OFF      , */
        "\x0d\x0a""787878787878""\x0d\x0a""OK""\x0d\x0a",         /* CMD_SERIAL_NO      , */
        "\x0d\x0a""REV1234""\x0d\x0a""OK""\x0d\x0a",         /* CMD_REVISION      , */
        "\x0d\x0a""OK""\x0d\x0a",                                 /* CMD_POWER_OFF      , */
        "\x0d\x0a""OK""\x0d\x0a",                                 /* CMD_RINGS_ON       , */
        "\x0d\x0a""OK""\x0d\x0a",                                 /* CMD_RINGS_OFF      , */

        "OK""\x0d\x0a",                                 /* GPRS_CMD_APN,                */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_DYNAMIC_ADDRESS,    */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_DNS_PRIMARY,        */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_DNS_SECONDARY,      */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_USERNAME,           */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_PASSWORD,           */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_CHAP,               */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_SET_PSD_PROFILE     */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_MAP_PSD_PROFILE,    */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_ACTIVATE_PROFILE,   */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_CREATE_SOCKET,      */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_CONNECT_SOCKET,     */
        "@""\x0d\x0a",                                  /* GPRS_CMD_SOCKET_WRITE,       */
        "+UUSORD: 0,",                                  /* GPRS_CMD_SOCKET_DATA,        *//* Completed dynamically depending upon reply size */
        "+USORD: 0,",                                   /* GPRS_CMD_SOCKET_READ,        */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_SOCKET_CLOSE,       */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_DEACTIVATE_PROFILE, */
        "CSQ: 15,15""\x0d\x0a",                         /* GPRS_CMD_SIGNAL,             */
        "+CNUM: \"Bill\",\"+0123\"""\x0d\x0a",          /* GPRS_CMD_MSISDN,             */
        "+CREG: 0,",                                    /* GPRS_CMD_STATUS,             *//* Completed dynamically depending upon 'gprsNoNetwork' checkbox */
        "+CGREG: 0,",                                   /* GPRS_CMD_GPRS_STATUS,        *//* Completed dynamically depending upon 'gprsNoNetwork' checkbox */
        "+CCID: \"7777777777777777777\"""\x0d\x0a",     /* GPRS_CMD_SIM_NO,             */
        "99998888777766""\x0d\x0a",                     /* GPRS_CMD_IMEI,               */
        "+COPS: 0,0,\"SPI_NET\"""\x0d\x0a",             /* GPRS_CMD_OPERATOR_2,         */
        "+UDOPN: 4,\"SPI_NET\"""\x0d\x0a",              /* GPRS_CMD_OPERATOR,           */
        "+UDOPN: 4,\"123\"""\x0d\x0a",                  /* GPRS_CMD_COUNTRY,            */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_DEREGISTER,         */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_POWEROFF,           */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_SIGN_OFF,           */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_CELLULAR_ON,        */
        "+UDNSRN:\"1.1.1.1\"""\x0d\x0a""OK""\x0d\x0a",  /* GPRS_CMD_DNS_TEST,           */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_EVENT_URC,          */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_STATUS_URC,         */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_GPRS_STATUS_URC,    */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_VERBOSE,            */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_DISABLE_WI,         */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_OPERATOR_ALPHA,     */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_OPERATOR_NUMERIC,   */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_HEX_MODE,           */
        "OK""\x0d\x0a",                                 /* GPRS_CMD_DISABLE_HEX_MODE,   */
        "OK""\x0d\x0a",                                 /* CMD_HELLO          ,         */
        
        "\x0d\x0a""OK""\x0d\x0a",                       /* CMD_SESSION_FINISH ,         */
        "\x0d\x0a""SBDRING""\x0d\x0a",                            /* CMD_RING           ,         */

        "+CGREG: 0""\x0d\x0a",                          /* GPRS_RSP_NOT_REG_URC,        */
        "+CGREG: 5""\x0d\x0a",                          /* GPRS_RSP_REGISTERED_URC,     */
        "+CGEV: NW DEACT""\x0d\x0a",                    /* GPRS_RSP_EVENT_URC,          */
        "+UMWI: 1,1,3""\x0d\x0a",                       /* GPRS_RSP_UMWI_URC,           */
        "+UUPSDD: 0""\x0d\x0a",                         /* GPRS_RSP_PSD_CONTEXT_URC,    */

        0                                               /* CMD_END            ,         */
    };
}


namespace OBFUSCATE
{
    /* Randomised substitutions for 0-9 digits */
    const int obfuscateSubs[] = 
    {
        4,1,6,2,3,7,8,5,9,0
    };


    /* Inverse substitutions for 0-9 numerical text digits */
    const int obfuscateInverseSubs[] = 
    {
        9,1,3,4,0,7,2,5,6,8
    };

    /* Randomised position dependent offsets to add to numerical text digits */
    const int obfuscateOffsets[] = 
    {
        7,8,9,3,9,7,4,7,2,4,2,9,2,9,5,3
    };
}    


namespace BINARY_REPLY
{
//    const int PREAMBLE_LENGTH = 2;
    const int PREAMBLE_LENGTH = 8;
    const int LENGTH_LENGTH = 2;
    const int CSUM_LENGTH = 2;
}    


namespace Iridium {

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
            _Incoming = gcnew ArrayList();
            _portReady = false;
            _writeBinary = false;
            _writeGprs = false;
            _binaryLength = 0;
            _lastLength = 0;
            _commandSize = 0;
            _mimsn = 1;/* Non zero */
            _momsn = 1;/* Non zero */

            _networkUrcEnable = false;
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
	private: System::Windows::Forms::TextBox^  comPort;
	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Button^  startButton;
	private: System::Windows::Forms::Label^  connectStatus;
	private: System::Windows::Forms::Timer^  ticker;
	private: System::ComponentModel::IContainer^  components;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
    ArrayList ^_Incoming;
    SerialPort^ _ComPort;
	bool _portReady;
    bool _writeBinary;
    bool _writeGprs;
    bool _networkUrcEnable;
	int _binaryLength;
    int _lastLength;
    unsigned int _commandSize;
    int _mimsn;
    int _momsn;
    
	private: System::Windows::Forms::TextBox^  logText;


	private: System::Windows::Forms::Button^  clearLogButton;
	private: System::Windows::Forms::TextBox^  receiveBox;
	private: System::Windows::Forms::Button^  testButton;
	private: System::Windows::Forms::CheckBox^  noNetworkCheck;
	private: System::Windows::Forms::Button^  ringButton;
	private: System::Windows::Forms::TextBox^  imeiBox;
	private: System::Windows::Forms::Label^  obfuscateLabel;

	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  moClearButton;
	private: System::Windows::Forms::Button^  mtClearButton;
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  gprsTrackerLogClear;

	private: System::Windows::Forms::CheckBox^  gprsDetachedCheck;
	private: System::Windows::Forms::CheckBox^  gprsNoNetworkCheck;
	private: System::Windows::Forms::CheckBox^  gprsErrorCheck;

	private: System::Windows::Forms::CheckBox^  gprsPDPCheck;
	private: System::Windows::Forms::TextBox^  trackerLog;

	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::CheckBox^  logEnable;





	private: System::Windows::Forms::TextBox^  sendBox;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->comPort = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->startButton = (gcnew System::Windows::Forms::Button());
			this->connectStatus = (gcnew System::Windows::Forms::Label());
			this->ticker = (gcnew System::Windows::Forms::Timer(this->components));
			this->logText = (gcnew System::Windows::Forms::TextBox());
			this->clearLogButton = (gcnew System::Windows::Forms::Button());
			this->receiveBox = (gcnew System::Windows::Forms::TextBox());
			this->sendBox = (gcnew System::Windows::Forms::TextBox());
			this->testButton = (gcnew System::Windows::Forms::Button());
			this->noNetworkCheck = (gcnew System::Windows::Forms::CheckBox());
			this->ringButton = (gcnew System::Windows::Forms::Button());
			this->imeiBox = (gcnew System::Windows::Forms::TextBox());
			this->obfuscateLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->moClearButton = (gcnew System::Windows::Forms::Button());
			this->mtClearButton = (gcnew System::Windows::Forms::Button());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->gprsPDPCheck = (gcnew System::Windows::Forms::CheckBox());
			this->gprsErrorCheck = (gcnew System::Windows::Forms::CheckBox());
			this->gprsDetachedCheck = (gcnew System::Windows::Forms::CheckBox());
			this->gprsNoNetworkCheck = (gcnew System::Windows::Forms::CheckBox());
			this->gprsTrackerLogClear = (gcnew System::Windows::Forms::Button());
			this->trackerLog = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->logEnable = (gcnew System::Windows::Forms::CheckBox());
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// comPort
			// 
			this->comPort->Location = System::Drawing::Point(1048, 12);
			this->comPort->Name = L"comPort";
			this->comPort->Size = System::Drawing::Size(51, 20);
			this->comPort->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(989, 12);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(53, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Com Port:";
			// 
			// startButton
			// 
			this->startButton->Location = System::Drawing::Point(763, 12);
			this->startButton->Name = L"startButton";
			this->startButton->Size = System::Drawing::Size(160, 24);
			this->startButton->TabIndex = 2;
			this->startButton->Text = L"Start";
			this->startButton->UseVisualStyleBackColor = true;
			this->startButton->Click += gcnew System::EventHandler(this, &Form1::startButton_Click);
			// 
			// connectStatus
			// 
			this->connectStatus->AutoSize = true;
			this->connectStatus->Location = System::Drawing::Point(760, 39);
			this->connectStatus->Name = L"connectStatus";
			this->connectStatus->Size = System::Drawing::Size(24, 13);
			this->connectStatus->TabIndex = 3;
			this->connectStatus->Text = L"Idle";
			// 
			// ticker
			// 
			this->ticker->Tick += gcnew System::EventHandler(this, &Form1::ticker_Tick);
			// 
			// logText
			// 
			this->logText->Location = System::Drawing::Point(354, 288);
			this->logText->Multiline = true;
			this->logText->Name = L"logText";
			this->logText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->logText->Size = System::Drawing::Size(235, 210);
			this->logText->TabIndex = 4;
			// 
			// clearLogButton
			// 
			this->clearLogButton->Location = System::Drawing::Point(549, 508);
			this->clearLogButton->Name = L"clearLogButton";
			this->clearLogButton->Size = System::Drawing::Size(40, 24);
			this->clearLogButton->TabIndex = 6;
			this->clearLogButton->Text = L"Clear";
			this->clearLogButton->UseVisualStyleBackColor = true;
			this->clearLogButton->Click += gcnew System::EventHandler(this, &Form1::clearLogButton_Click);
			// 
			// receiveBox
			// 
			this->receiveBox->Location = System::Drawing::Point(47, 79);
			this->receiveBox->Multiline = true;
			this->receiveBox->Name = L"receiveBox";
			this->receiveBox->ReadOnly = true;
			this->receiveBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->receiveBox->Size = System::Drawing::Size(242, 185);
			this->receiveBox->TabIndex = 7;
			// 
			// sendBox
			// 
			this->sendBox->Location = System::Drawing::Point(354, 80);
			this->sendBox->Multiline = true;
			this->sendBox->Name = L"sendBox";
			this->sendBox->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->sendBox->Size = System::Drawing::Size(235, 184);
			this->sendBox->TabIndex = 8;
			// 
			// testButton
			// 
			this->testButton->Location = System::Drawing::Point(47, 509);
			this->testButton->Name = L"testButton";
			this->testButton->Size = System::Drawing::Size(69, 22);
			this->testButton->TabIndex = 9;
			this->testButton->Text = L"Obfusticate";
			this->testButton->UseVisualStyleBackColor = true;
			this->testButton->Click += gcnew System::EventHandler(this, &Form1::testButton_Click);
			// 
			// noNetworkCheck
			// 
			this->noNetworkCheck->AutoSize = true;
			this->noNetworkCheck->Location = System::Drawing::Point(6, 26);
			this->noNetworkCheck->Name = L"noNetworkCheck";
			this->noNetworkCheck->Size = System::Drawing::Size(83, 17);
			this->noNetworkCheck->TabIndex = 10;
			this->noNetworkCheck->Text = L"No Network";
			this->noNetworkCheck->UseVisualStyleBackColor = true;
			// 
			// ringButton
			// 
			this->ringButton->Location = System::Drawing::Point(6, 49);
			this->ringButton->Name = L"ringButton";
			this->ringButton->Size = System::Drawing::Size(39, 22);
			this->ringButton->TabIndex = 11;
			this->ringButton->Text = L"Ring";
			this->ringButton->UseVisualStyleBackColor = true;
			this->ringButton->Click += gcnew System::EventHandler(this, &Form1::ringButton_Click);
			// 
			// imeiBox
			// 
			this->imeiBox->Location = System::Drawing::Point(47, 483);
			this->imeiBox->Name = L"imeiBox";
			this->imeiBox->Size = System::Drawing::Size(138, 20);
			this->imeiBox->TabIndex = 12;
			// 
			// obfuscateLabel
			// 
			this->obfuscateLabel->AutoSize = true;
			this->obfuscateLabel->Location = System::Drawing::Point(122, 518);
			this->obfuscateLabel->Name = L"obfuscateLabel";
			this->obfuscateLabel->Size = System::Drawing::Size(10, 13);
			this->obfuscateLabel->TabIndex = 13;
			this->obfuscateLabel->Text = L" ";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(47, 56);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 13);
			this->label3->TabIndex = 15;
			this->label3->Text = L"MO";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(351, 56);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 13);
			this->label4->TabIndex = 16;
			this->label4->Text = L"MT";
			// 
			// moClearButton
			// 
			this->moClearButton->Location = System::Drawing::Point(241, 56);
			this->moClearButton->Name = L"moClearButton";
			this->moClearButton->Size = System::Drawing::Size(48, 21);
			this->moClearButton->TabIndex = 17;
			this->moClearButton->Text = L"Clear";
			this->moClearButton->UseVisualStyleBackColor = true;
			this->moClearButton->Click += gcnew System::EventHandler(this, &Form1::moClearButton_Click);
			// 
			// mtClearButton
			// 
			this->mtClearButton->Location = System::Drawing::Point(547, 56);
			this->mtClearButton->Name = L"mtClearButton";
			this->mtClearButton->Size = System::Drawing::Size(42, 21);
			this->mtClearButton->TabIndex = 18;
			this->mtClearButton->Text = L"Clear";
			this->mtClearButton->UseVisualStyleBackColor = true;
			this->mtClearButton->Click += gcnew System::EventHandler(this, &Form1::mtClearButton_Click);
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->ringButton);
			this->groupBox1->Controls->Add(this->noNetworkCheck);
			this->groupBox1->Location = System::Drawing::Point(47, 288);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(108, 125);
			this->groupBox1->TabIndex = 19;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Iridium";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->gprsPDPCheck);
			this->groupBox2->Controls->Add(this->gprsErrorCheck);
			this->groupBox2->Controls->Add(this->gprsDetachedCheck);
			this->groupBox2->Controls->Add(this->gprsNoNetworkCheck);
			this->groupBox2->Location = System::Drawing::Point(184, 288);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(118, 125);
			this->groupBox2->TabIndex = 20;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Gprs";
			// 
			// gprsPDPCheck
			// 
			this->gprsPDPCheck->AutoSize = true;
			this->gprsPDPCheck->Location = System::Drawing::Point(6, 95);
			this->gprsPDPCheck->Name = L"gprsPDPCheck";
			this->gprsPDPCheck->Size = System::Drawing::Size(110, 17);
			this->gprsPDPCheck->TabIndex = 4;
			this->gprsPDPCheck->Text = L"Lost PDP Context";
			this->gprsPDPCheck->UseVisualStyleBackColor = true;
			this->gprsPDPCheck->CheckedChanged += gcnew System::EventHandler(this, &Form1::gprsPDPCheck_CheckedChanged);
			// 
			// gprsErrorCheck
			// 
			this->gprsErrorCheck->AutoSize = true;
			this->gprsErrorCheck->Location = System::Drawing::Point(6, 72);
			this->gprsErrorCheck->Name = L"gprsErrorCheck";
			this->gprsErrorCheck->Size = System::Drawing::Size(91, 17);
			this->gprsErrorCheck->TabIndex = 3;
			this->gprsErrorCheck->Text = L"Network Error";
			this->gprsErrorCheck->UseVisualStyleBackColor = true;
			// 
			// gprsDetachedCheck
			// 
			this->gprsDetachedCheck->AutoSize = true;
			this->gprsDetachedCheck->Location = System::Drawing::Point(6, 49);
			this->gprsDetachedCheck->Name = L"gprsDetachedCheck";
			this->gprsDetachedCheck->Size = System::Drawing::Size(116, 17);
			this->gprsDetachedCheck->TabIndex = 1;
			this->gprsDetachedCheck->Text = L"Network Detached";
			this->gprsDetachedCheck->UseVisualStyleBackColor = true;
			this->gprsDetachedCheck->CheckedChanged += gcnew System::EventHandler(this, &Form1::gprsDetachedCheck_CheckedChanged);
			// 
			// gprsNoNetworkCheck
			// 
			this->gprsNoNetworkCheck->AutoSize = true;
			this->gprsNoNetworkCheck->Location = System::Drawing::Point(6, 26);
			this->gprsNoNetworkCheck->Name = L"gprsNoNetworkCheck";
			this->gprsNoNetworkCheck->Size = System::Drawing::Size(83, 17);
			this->gprsNoNetworkCheck->TabIndex = 0;
			this->gprsNoNetworkCheck->Text = L"No Network";
			this->gprsNoNetworkCheck->UseVisualStyleBackColor = true;
			this->gprsNoNetworkCheck->CheckedChanged += gcnew System::EventHandler(this, &Form1::gprsNoNetworkCheck_CheckedChanged);
			// 
			// gprsTrackerLogClear
			// 
			this->gprsTrackerLogClear->Location = System::Drawing::Point(1057, 510);
			this->gprsTrackerLogClear->Name = L"gprsTrackerLogClear";
			this->gprsTrackerLogClear->Size = System::Drawing::Size(42, 22);
			this->gprsTrackerLogClear->TabIndex = 2;
			this->gprsTrackerLogClear->Text = L"Clear";
			this->gprsTrackerLogClear->UseVisualStyleBackColor = true;
			this->gprsTrackerLogClear->Click += gcnew System::EventHandler(this, &Form1::gprsTrackerLogClear_Click);
			// 
			// trackerLog
			// 
			this->trackerLog->AcceptsReturn = true;
			this->trackerLog->Location = System::Drawing::Point(639, 79);
			this->trackerLog->Multiline = true;
			this->trackerLog->Name = L"trackerLog";
			this->trackerLog->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->trackerLog->Size = System::Drawing::Size(460, 419);
			this->trackerLog->TabIndex = 21;
			this->trackerLog->WordWrap = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(351, 510);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(85, 13);
			this->label2->TabIndex = 23;
			this->label2->Text = L"Iridium/Gprs Log";
			// 
			// logEnable
			// 
			this->logEnable->AutoSize = true;
			this->logEnable->Location = System::Drawing::Point(639, 517);
			this->logEnable->Name = L"logEnable";
			this->logEnable->Size = System::Drawing::Size(104, 17);
			this->logEnable->TabIndex = 24;
			this->logEnable->Text = L"Tracker Logging";
			this->logEnable->UseVisualStyleBackColor = true;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1155, 552);
			this->Controls->Add(this->logEnable);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->trackerLog);
			this->Controls->Add(this->gprsTrackerLogClear);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->mtClearButton);
			this->Controls->Add(this->moClearButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->obfuscateLabel);
			this->Controls->Add(this->imeiBox);
			this->Controls->Add(this->testButton);
			this->Controls->Add(this->sendBox);
			this->Controls->Add(this->receiveBox);
			this->Controls->Add(this->clearLogButton);
			this->Controls->Add(this->logText);
			this->Controls->Add(this->connectStatus);
			this->Controls->Add(this->startButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->comPort);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion



/* -------------------------------- Main functionality ---------------------*/

	/* Start initialisation */
    private: void start( void )
	{
        if (!_portReady)
        {
            _ComPort = gcnew SerialPort();
            _portReady = true;
        }
        
        if (!_ComPort->IsOpen)
        {
            if (comPort->Text != "")
            {
                _ComPort->PortName = String::Concat( "COM", comPort->Text );

                _ComPort->BaudRate = 4800;
                _ComPort->Parity = Parity::None;
                _ComPort->StopBits = StopBits::One;
                _ComPort->DataBits = 8;
                _ComPort->Handshake = Handshake::None;
        
                try
                {
                    _ComPort->Open();
                    startButton->Text = "Stop";
                    connectStatus->Text = "Running";
                
                    ticker->Interval = 100;
                    ticker->Enabled = true;
                    ticker->Start();
                }
                catch (System::IO::IOException ^)
                {
                    connectStatus->Text = "Com port: Reset the connection";
                }
                catch (UnauthorizedAccessException ^)
                {
                    connectStatus->Text = "Com port: No access";
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
            _ComPort->Close();
            startButton->Text = "Start";
            connectStatus->Text = "Idle";
        
            ticker->Enabled = false;
            ticker->Stop();
        }
	}


	/* Receive comms */
    private: void receive( void )
    {
        if (_ComPort->IsOpen)
        {
            int length = _ComPort->BytesToRead;
            if (length != 0)
            {
                /* Allow com input to settle */
                if (length == _lastLength)
                {
                    String ^s;
                
                    _lastLength = 0;
                    
                    /* Get received bytes */
                    array<unsigned char>^ commandIn = gcnew array<unsigned char>( 350 );

                    if (logEnable->Checked)
                    {
                        array<unsigned char>^ receiveIn = gcnew array<unsigned char>( length );
                        _ComPort->Read( receiveIn, 0, length );
                        length = arrayToLogText( receiveIn, commandIn );
                    }
                    else
                    {
                        _ComPort->Read( commandIn, 0, length );
                    }

                    if ((_Incoming->Count != 0) || (commandIn[0] == 'A') || (_writeBinary == true) || (_writeGprs == true))
                    {
                        if (commandIn[0] == 'A')
                        {
                            /* Got a start character */
                            _Incoming->Clear();/* To start again */
                        }
                        else
                        {
                            /* Still looking for line end */
                        }
                        
                        /* Each character until a line feed (ignoring CRs . . */
                        for (int i = 0; i < length; ++i)
                        {
                            if ((_writeBinary == false) && (_writeGprs == false))
                            {
                                unsigned char character = commandIn[i];
                                if ((character != '\x0a') && (character != '\x0d'))
                                {
                                    _Incoming->Add( character );
                                }
                                else if (_Incoming->Count != 0)
                                {
                                    /* We have a command */
                        
                                    /* Convert to ascii string */
                                    char in[20];/* To build a text string */
                        
                                    int j = 0;
                                    for ( ; j < _Incoming->Count; ++j)
                                    {
                                        in[j] = (unsigned char)_Incoming[j];
                                    }
                                    in[j] = '\0';
                        
                                    _Incoming->Clear();/* To start again */
                            
                                    /* Identify the command using hayes table */
                                    int cmd = 0;
                                    bool found = false;
                                    while ((found == false) && (HAYES::hayesIn[cmd] != 0))
                                    {
                                        found = strstr( in, HAYES::hayesIn[cmd] ) != 0 ? true : false;
                                        ++cmd;
                                    }
                        
                                    s = gcnew String( in );
                                    if (found == true)
                                    {
                                        --cmd;
                                        /* Identified the command */
                            
                                        switch (cmd)
                                        {
                                            case HAYES::CMD_WRITE_BINARY:
                                                {
                                                    char *ptr = strchr( in, '=' );
                                                    if (ptr != 0)
                                                    {
                                                        ++ptr;
                                                        _binaryLength = atol( ptr ) + 2;
                                                        _writeBinary = true;
                                                        log( "Bin set" );
                                                    }
                                                }
                                                break;
                                            
                                            case HAYES::GPRS_CMD_SOCKET_WRITE:
                                                _writeGprs = true;
                                                break;
                                      
                                        }
                            
                                        log( String::Concat( "<- ", s ) );
                                     
                                        /* Prepare and send response */
                                        int msgSize = outMessageSize();
                                        array<unsigned char>^ buffer;
                                        if ((cmd == HAYES::CMD_READ_BINARY) || (cmd == HAYES::GPRS_CMD_SOCKET_READ))
                                        {
                                            /* Prepare a binary only response */
                                            buffer = gcnew array<unsigned char>( BINARY_REPLY::LENGTH_LENGTH + BINARY_REPLY::PREAMBLE_LENGTH + msgSize + BINARY_REPLY::CSUM_LENGTH );
                                            if ((msgSize > 0) || (cmd == HAYES::GPRS_CMD_SOCKET_READ))
                                            {
                                                if ((isNextMessageHex()) || (cmd == HAYES::GPRS_CMD_SOCKET_READ))
                                                {
                                                    if (cmd == HAYES::GPRS_CMD_SOCKET_READ)
                                                    {
                                                        String ^message;
                                                        message = gcnew String( "\"41" );
                                                        
                                                        s = gcnew String( HAYES::hayesOut[HAYES::GPRS_CMD_SOCKET_READ] );
                                                        s = String::Concat( s, String::Format( "{0}"",", msgSize + 1 ) );
                                                        s = String::Concat( s, message );
                                                        
                                                        if (msgSize != 0)
                                                        {
                                                            s = String::Concat( s, outNextMessage() );
                                                        }
                                                        s = String::Concat( s, "\"\x0d\x0a" );
                            
                                                        buffer = stringToArray( s );
                                                        
                                                    }
                                                    else
                                                    {
                                                        array<unsigned char>^ lenArray;
                                                    
                                                        array<unsigned char>^ msgArray;

                                                        msgSize /= 2;
                                                        lenArray = wordToArray( msgSize );
                                                    
                                                        msgArray = hexStringToArray( outNextMessage() );

                                                        lenArray->CopyTo( buffer, 0 );
                                                        msgArray->CopyTo( buffer, BINARY_REPLY::LENGTH_LENGTH );
                                                        array<unsigned char>^ csumArray = calcArrayChecksum( buffer, BINARY_REPLY::LENGTH_LENGTH, msgSize );
                                                        csumArray->CopyTo( buffer, BINARY_REPLY::LENGTH_LENGTH + msgSize );
                                                    }
                                                
                                                }
                                                else
                                                {
                                                    array<unsigned char>^ preAmbleArray = charBlockToArray( HAYES::hayesOut[cmd], BINARY_REPLY::PREAMBLE_LENGTH );
                                                    array<unsigned char>^ lenArray = wordToArray( BINARY_REPLY::PREAMBLE_LENGTH + msgSize );
                                                
                                                    array<unsigned char>^ msgArray = stringToArray( outNextMessage() );
                                                
                                                    lenArray->CopyTo( buffer, 0 );
                                                    preAmbleArray->CopyTo( buffer, BINARY_REPLY::LENGTH_LENGTH );
                                                    msgArray->CopyTo( buffer, BINARY_REPLY::LENGTH_LENGTH + BINARY_REPLY::PREAMBLE_LENGTH );
                                                    array<unsigned char>^ csumArray = calcArrayChecksum( buffer, BINARY_REPLY::LENGTH_LENGTH, BINARY_REPLY::PREAMBLE_LENGTH + msgSize );
                                                    csumArray->CopyTo( buffer, BINARY_REPLY::LENGTH_LENGTH + BINARY_REPLY::PREAMBLE_LENGTH + msgSize );
                                                }
                                        
                                        
                                                if (outMessagesAvailable() != 0)
                                                {
                                                    ++_mimsn;
                                                }
                                            
                                               
                                                log( "Bin reply" );
                                                log( String::Format("{0} {1} {2} {3}", buffer[2], buffer[3], buffer[4], buffer[5] ) );
                                                removeOutMessage();
                                            }
                                        }
                                        else
                                        {
                                            /* Prepare an ascii response */
                                            s = gcnew String( HAYES::hayesOut[cmd] );

                                            /* Now do any command specific management . . */
                                            switch (cmd)
                                            {
                                                case HAYES::CMD_SESSION:
                                                case HAYES::CMD_SESSION_MK2:
                                                    {
                                                        int lines = 0;
                                            
                                                        if (isNextMessageHex())
                                                        {
                                                            msgSize /= 2;
                                                        }
                                                        log( String::Format("Message size= {0} count= {1}", msgSize, outMessagesAvailable() ) );
                                                        s = String::Concat( s, String::Format( "{0}"",""{1}"",""{2}"",""{3}"",""{4}"",""{5}",
                                                                                                noNetworkCheck->Checked == false ? (cmd == HAYES::CMD_SESSION ? 0 : 1) : (cmd == HAYES::CMD_SESSION ? 18 : 2),
                                                                                                _momsn,
                                                                                                (outMessagesAvailable() == 0) ? ((noNetworkCheck->Checked == false) ? 0 : 2) : ((noNetworkCheck->Checked == false) ? 1 : 2),
                                                                                                _mimsn,
                                                                                                (outMessagesAvailable() == 0) ? 0 : (msgSize + (isNextMessageHex() ? 0 : BINARY_REPLY::PREAMBLE_LENGTH)),
                                                                                                (outMessagesAvailable() > 0) ? outMessagesAvailable() - 1 : 0 ) );
                                                        String^ temp = gcnew String( HAYES::hayesOut[HAYES::CMD_SESSION_FINISH] );
                                                        s = String::Concat( s, temp );
                                                    
                                                    }
                                                    break;
                                                
                                                case HAYES::GPRS_CMD_STATUS:
                                                case HAYES::GPRS_CMD_GPRS_STATUS:
                                                    s = String::Concat( s, String::Format( "{0}""\x0d\x0a", gprsNoNetworkCheck->Checked == false ? 5 : 0 ) );
                                                    break;
                                                
                                                case HAYES::GPRS_CMD_ACTIVATE_PROFILE:
                                                    if (gprsDetachedCheck->Checked == true)
                                                    {
                                                        s = "+CME ERROR""\x0d\x0a";
                                                    }
                                                    break;
                                                    
                                                case HAYES::GPRS_CMD_CREATE_SOCKET:
                                                case HAYES::GPRS_CMD_CONNECT_SOCKET:
                                                case HAYES::GPRS_CMD_SOCKET_WRITE:
                                                case HAYES::GPRS_CMD_SOCKET_DATA:
                                                case HAYES::GPRS_CMD_SOCKET_READ:
                                                case HAYES::GPRS_CMD_SOCKET_CLOSE:
                                                    if ((gprsErrorCheck->Checked == true) || (gprsNoNetworkCheck->Checked == true))
                                                    {
                                                        //gprsErrorCheck->Checked = false;
                                                        s = "+CME ERROR""\x0d\x0a";
                                                    }
                                                    break;
                                                
                                                
                                                case HAYES::GPRS_CMD_STATUS_URC:
                                                case HAYES::GPRS_CMD_GPRS_STATUS_URC:
                                                    _networkUrcEnable = true;
                                                    break;


                                                case HAYES::GPRS_CMD_POWEROFF:
                                                    _networkUrcEnable = false;
                                                    break;

                                                default:
                                                    break;
                                            }

                                            buffer = stringToArray( s );
                                            
                                            log( String::Concat( "-> ", s ) );
                                        }
                                    
                                        sendResponse( buffer );
                                    }
                                    else
                                    {
                                        /* Command not identified */
                                        log( String::Concat( "? ", s ) );
                                    }
                                }
                            }
                            else if (_writeBinary == true)
                            {
                                /* Binary expected */
                                unsigned char packet[500];
                        
                                _Incoming->Add( commandIn[i] );
                                if (i == (_binaryLength - 1))
                                {
                                    /* Finished = make the data packet */
                                    int j = 0;
                                    for ( ; j < _Incoming->Count - 2; ++j)
                                    {
                                        packet[j] = (unsigned char)_Incoming[j];
                                        if ((j < 8) || (packet[1] != 64))
                                        {
                                            /* Hex */
                                            receiveBox->AppendText( String::Format( "{0:X2}", _Incoming[j] ) );
                                        }
                                    }

                                    /* length - ignore if not at least a few */
                                    if (j > 1)
                                    {
                                        switch (packet[1])
                                        {
                                            case 64:/* MO_64 text with header of 8 */
                                                if (j > 8)
                                                {
                                                    packet[j] = '\0';
                                                    s = gcnew String( (char *)&packet[8] );
                                                    receiveBox->AppendText( s );
                                                    receiveBox->AppendText( "\x0d\x0a" );
                                                }
                                                break;
                                            
                                            default:
                                                    receiveBox->AppendText( "\x0d\x0a" );
                                                break;
                                        }
                                    }

                                    _Incoming->Clear();/* To start again */
                                    _writeBinary = false;
                                    ++_momsn;
                                    log( "Bin done" );

                                    /* Prepare and send response */
                                    s = gcnew String( HAYES::hayesOut[HAYES::CMD_CLEAR] );
                                    log( String::Concat( "-> ", s ) );
                            
                                    array<unsigned char>^ buffer = stringToArray( s );
                                    sendResponse( buffer );
                                }
                        
                            }
                            else
                            {
                                    _Incoming->Clear();/* To start again */
                                    _writeGprs = false;

                                    /* Prepare and send response */
                                    int msgSize = outMessageSize() / 2;
                                    s = gcnew String( HAYES::hayesOut[HAYES::GPRS_CMD_SOCKET_DATA] );
                                    s = String::Concat( s, String::Format( "{0}""\x0d\x0a", msgSize + 1 ) );
                            
                                    array<unsigned char>^ buffer = stringToArray( s );
                                    sendResponse( buffer );
                            }
                        }
                    }
                    else
                    {
                        _Incoming->Clear();/* To start again */
                    }
                }
                else
                {
                    /* Com input not settled */
                    _lastLength = length;
                }
            }
        }
	}


    private: void sendResponse( array<unsigned char>^ bufferOut )
    {
        try
        {
            _ComPort->Write( bufferOut, 0, bufferOut->Length );
        }
        catch (System::IO::IOException ^)
        {
            try
            {
                _ComPort->~SerialPort();
            }
            catch (System::IO::IOException ^)
            {
                connectStatus->Text = "Reset the connection";
            }

            /* Cancel all related to being connected */
            _portReady = false;
            startButton->Text = "Start";
            connectStatus->Text = "Idle";
    
            ticker->Enabled = false;
            ticker->Stop();
        }
    
    }
    

    private: void log( String ^msg )
    {
        String ^newline = gcnew String( "\x0d\x0a" );
        logText->AppendText( newline );
        logText->AppendText( msg );
    }


    
    /* Returns message count in a text box string */
    private: int outMessagesAvailable( void )
    {
        int count = 0;
        int length = sendBox->Text->Length;
        if (length != 0)
        {
            int pos = -1;

            do
            {
                pos = sendBox->Text->IndexOf( 0x0a, pos + 1 );
                if (pos != -1)
                {
                    ++count;
                }
            }
            while ((pos != -1) && ((pos + 1) < length));
        }
        
        return(count);
    }


    /* Returns character count of first text box message */
    private: int outMessageSize( void )
    {
        int count = 0;
        int length = sendBox->Text->Length;
        if (length != 0)
        {
            int pos = sendBox->Text->IndexOf( 0x0d );
            
            count = (pos == -1) ? 0 : pos;
        }
        
        return(count);
    }


    /* Indicates if the next messahe is hex or text */
    private: bool isNextMessageHex( void )
    {
        return((sendBox->Text->Length != 0) && (sendBox->Text[0] == '0'));
    }
    
    
    /* Removes first text box message */
    private: void removeOutMessage( void )
    {
        if (outMessagesAvailable() > 0)
        {
            sendBox->Text = sendBox->Text->Remove( 0, outMessageSize() + 2 );
        }
        else
        {
//            sendBox->Text = sendBox->Text->Remove( 0 );
        }
    }

    
    private: String ^outNextMessage( void )
    {
        String ^out;
        
        if (outMessagesAvailable() > 0)
        {
            out = sendBox->Text->Substring( 0, outMessageSize() );
        }
        else
        {
            out = gcnew String( "" );
        }
        
        return(out);
    }


    /* Makes a character array from a string object containing normal text */
    private:array<unsigned char> ^stringToArray( String ^s )
    {
        int length = s->Length;
        
        array<unsigned char>^ bufferOut = gcnew array<unsigned char>( length );
        
        for (int i = 0; i < length; ++i)
        {
            bufferOut[i] = (unsigned char)s[i];
        }
        
        return(bufferOut);
    }


    /* Makes a character array from a string object containing hex encoded text */
    private:array<unsigned char> ^hexStringToArray( String ^s )
    {
        int length = s->Length;
        bool msb = true;
        
        array<unsigned char>^ bufferOut = gcnew array<unsigned char>( length / 2 );
        
        int j = 0;
        for (int i = 0; i < length; ++i)
        {
            unsigned char character = (unsigned char)s[i];
            unsigned char value = ((character > '9') ? ((character > 'Z') ? (character - 'a' + 0xa) : (character - 'A' + 0xa)) : (character - '0'));
            if (msb)
            {
                bufferOut[j] = value << 4;
            }
            else
            {
                bufferOut[j] |= value;
                ++j;
            }
            msb = !msb;
        }
        
        return(bufferOut);
    }


    /* Makes a character array from a C character block */
    private:array<unsigned char> ^charBlockToArray( const char *p, int length )
    {
        array<unsigned char>^ bufferOut = gcnew array<unsigned char>( length );
        
        for (int i = 0; i < length; ++i)
        {
            bufferOut[i] = (unsigned char)p[i];
        }
        
        return(bufferOut);
    }


    /* Makes a character array from a 16 bit word */
    private: array<unsigned char> ^wordToArray( unsigned int word )
    {
        array<unsigned char>^ wordArray = gcnew array<unsigned char>( 2 );
        wordArray[0] = (char)((word >> 8) & 0x0ff);
        wordArray[1] = (char)(word & 0x0ff);
        return(wordArray);
    }



    /* Forms an character array from a checksum calculated on a specified part of an array */
    private: array<unsigned char> ^calcArrayChecksum( array<unsigned char> ^a, int start, int length )
    {
        unsigned int checksum = 0;
        for (int i = 0; i < length; ++i)
        {
            checksum += a[i + start];
        }
        
        return(wordToArray( checksum ));
    }

/* -----------------------------End Main functionality ----------------------*/




	private: System::Void startButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        start();
	}




	private: System::Void ticker_Tick(System::Object^  sender, System::EventArgs^  e)
    {
        receive();
	}
    
    
    private: System::Void clearLogButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        logText->Clear();
	}


    private: System::Void testButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        obfuscateLabel->Text = obfuscateNumText( imeiBox->Text);
    }

    private: System::Void ringButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        array<unsigned char>^ buffer;
        String ^s;
        
        s = gcnew String( HAYES::hayesOut[HAYES::CMD_RING] );
        buffer = stringToArray( s );
        log( String::Concat( "-> ", s ) );
        sendResponse( buffer );
	}
    


    private: String^ obfuscateNumText( String ^text )
    {
        String ^result = gcnew String( "" );
        char s[20];
        
        int len = text->Length;
        
    
        if (len > 0)
        {
            for (int i = 0; i < 20; ++i)
            {
                s[i] = 0;
            }
            for (int i = 0; i < len; ++i)
            {
                s[i] = (char)text[i];
            }

            char *ptr = s + len - 1;
            int previousDigit = 0;

            do
            {
                int num;
                num = ((*ptr) - '0') % 10;
                int offset = ptr - s - 1;
                num = (num + OBFUSCATE::obfuscateOffsets[ptr - s - 1] + previousDigit) % 10;
                num = OBFUSCATE::obfuscateSubs[num];
                previousDigit = (*ptr) - '0';
                *ptr = num + '0';
                --ptr;
            }
            while (ptr != s);
            
            String ^temp = gcnew String( s );
            result = temp;
        }
        
        return(result);
    }    



    private: System::Void moClearButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        receiveBox->Clear();
	}
    
    
    private: System::Void mtClearButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        sendBox->Clear();
	}
    

    private: System::Void gprsTrackerLogClear_Click(System::Object^  sender, System::EventArgs^  e)
    {
        trackerLog->Clear();
    }
    
    
    private: System::Void gprsNoNetworkCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
    {
        if (_networkUrcEnable)
        {
            array<unsigned char>^ buffer;
            String ^s;
            
            int messageNo = (gprsNoNetworkCheck->Checked == false) ? HAYES::GPRS_RSP_REGISTERED_URC : HAYES::GPRS_RSP_NOT_REG_URC;
            
            s = gcnew String( HAYES::hayesOut[messageNo] );
            buffer = stringToArray( s );
            log( String::Concat( "-> ", s ) );
            sendResponse( buffer );
        }
	}
    
    
    private: System::Void gprsDetachedCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
    {
        if (gprsDetachedCheck->Checked == true)
        {
            array<unsigned char>^ buffer;
            String ^s;
        
            s = gcnew String( HAYES::hayesOut[HAYES::GPRS_RSP_EVENT_URC] );
            buffer = stringToArray( s );
            log( String::Concat( "-> ", s ) );
            sendResponse( buffer );
        }
	}
    
    private: System::Void gprsPDPCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
    {
        if (gprsPDPCheck->Checked == true)
        {
            array<unsigned char>^ buffer;
            String ^s;
        
            s = gcnew String( HAYES::hayesOut[HAYES::GPRS_RSP_PSD_CONTEXT_URC] );
            buffer = stringToArray( s );
            log( String::Concat( "-> ", s ) );
            sendResponse( buffer );
        }
    }


    //Timing
    int timeReference( void )
    {
        DateTime ^timeNow = DateTime::Now;
        return(timeNow->Second);
    }


    int timeElapsedSince( int startTime )
    {
        return((60 + timeReference() - startTime) % 60);
    }


    //Log stream splitting
    private:int arrayToLogText( array<unsigned char> ^receive, array<unsigned char> ^command )
    {
        int receiveLength = receive->Length;

        char logBuffer[1000];

        int i = 0;
        int j = 0;
        int k = 0;

        while (i < receiveLength)
        {
            char character = (char)receive[i];
            ++i;

            if ((character == '$') && (_commandSize == 0))
            {
                _commandSize = (char)receive[i];
                ++i;
                _commandSize += ((char)receive[i] << 8);
                ++i;
            }
            else
            {
                if (_commandSize != 0)
                {
                    //Command
                    command[k] = character;
                    ++k;
                    --_commandSize;
                }
                else
                {
                    //Logging

                    if (character == '\x0a')
                    {
                        logBuffer[j] = '\r';
                        ++j;
                        logBuffer[j] = '\n';
                        ++j;
                    }
                    else
                    {
                        logBuffer[j] = character;
                        ++j;
                    }
                }


                if ( ((j != 0) && (i == receiveLength)) )
                {
                    logBuffer[j] = '\0';
                    j = 0;

                    String^ s = gcnew String( logBuffer );

                    int sizeNow = trackerLog->Text->Length;
                    if (sizeNow > 0x4000)
                    {
                        trackerLog->Text = trackerLog->Text->Substring( sizeNow);
                    }

                    trackerLog->AppendText( s );
                }
            }
        }

        return (k);

    }

                                                                        
};


}

