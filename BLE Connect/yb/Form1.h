#pragma once

#include "ybmessage.h"
#include "ble.h"

namespace yb {

	using namespace System;
    using namespace System::Collections;
	using namespace System::ComponentModel;
	using namespace System::IO::Ports;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

        enum
        {
            TRACKER_STATE_IDLE,
            TRACKER_STATE_SENT,
            TRACKER_STATE_RECEIVE,
        };
        

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
            _rxMsg = gcnew YbMessage();
            _trackerState = TRACKER_STATE_IDLE;
            trackerConnected = BG::DISCONNECTED;
            
            _settingsLocked = true;
            setView( false );
            _serialComms = gcnew Ble( commsLog, scanList );
		
            _incoming = gcnew YbMessage();
            _sentMessages = gcnew ArrayList();
            _sentIds = gcnew ArrayList();
            _sentStatus = gcnew ArrayList();
            _sendingFrame = false;
            _id = 1;
            _inboxActive = false;
            portNumber->Text = "7";
            macText->Text = "090909090963";

            _test = false;

            testEventTimer->Interval = 20000;
            testEventTimer->Enabled = true;
            testEventTimer->Stop();
            
            serialTimer->Interval = BG::TICK_INTERVAL;
            serialTimer->Enabled = true;
            serialTimer->Start();
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

	protected: 

	private: System::Windows::Forms::TextBox^  outMsg;
	private: System::Windows::Forms::Button^  sendButton;
	private: System::ComponentModel::IContainer^  components;









	private: System::Windows::Forms::TextBox^  inMsg;




	private:
		/// <summary>
		/// Required designer variable.
        unsigned short _id;
        YbMessage ^_rxMsg;
        int trackerConnected;
        Ble ^_serialComms;
        unsigned long _timerStart;
        unsigned long _timerNow;
        YbMessage ^_incoming;
        ArrayList ^_sentMessages;
        ArrayList ^_sentIds;
        ArrayList ^_sentStatus;
        int _sendFrameStart;
        bool _inboxActive;
        bool _test;
        bool _sendingFrame;
        bool _settingsLocked;
        


	private: System::Windows::Forms::Label^  sendStatus;



	private: System::Windows::Forms::Timer^  serialTimer;
	private: System::Windows::Forms::TextBox^  commsLog;
	private: System::Windows::Forms::Button^  resetLogButton;

	private: System::Windows::Forms::TextBox^  portNumber;
	private: System::Windows::Forms::TextBox^  macText;
	private: System::Windows::Forms::Label^  connectStatus;
	private: System::Windows::Forms::Button^  connectButton;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Button^  logButton;





	private: System::Windows::Forms::ComboBox^  trkStatusComboBox;
	private: System::Windows::Forms::ComboBox^  trkPeriodComboBox;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;

	private: System::Windows::Forms::TextBox^  composeMsg;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
private: System::Windows::Forms::TextBox^  inboxCount;

private: System::Windows::Forms::Button^  getButton;


private: System::Windows::Forms::Label^  gpsLabel;
private: System::Windows::Forms::Label^  iridiumLabel;
private: System::Windows::Forms::Label^  pinLockLabel;
private: System::Windows::Forms::TextBox^  unlockPinBox;
private: System::Windows::Forms::TextBox^  newPinBox;
private: System::Windows::Forms::Label^  label8;
private: System::Windows::Forms::Label^  label9;

private: System::Windows::Forms::Button^  submitButton;


private: System::Windows::Forms::Label^  label10;

private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::GroupBox^  messagingGroup;

private: System::Windows::Forms::GroupBox^  groupBox2;
private: System::Windows::Forms::GroupBox^  pinGroup;

private: System::Windows::Forms::TableLayoutPanel^  settingsTable;
private: System::Windows::Forms::ComboBox^  commandComboBox;


private: System::Windows::Forms::Label^  Imei;

private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::ComboBox^  externalTypeCombo;

private: System::Windows::Forms::ComboBox^  externalBaudCombo;
private: System::Windows::Forms::ComboBox^  externalSamplesCombo;

private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::Label^  label16;


private: System::Windows::Forms::TextBox^  serialText;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::TextBox^  modelText;
private: System::Windows::Forms::Button^  factorySetButton;
private: System::Windows::Forms::GroupBox^  factoryGroup;



private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::CheckBox^  androidCheck;
private: System::Windows::Forms::ComboBox^  alertEnum;


private: System::Windows::Forms::ComboBox^  externalMOBCombo;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  powerLabel;
private: System::Windows::Forms::Label^  shippingLabel;
private: System::Windows::Forms::Label^  productNameLabel;
private: System::Windows::Forms::Label^  versionLabel;
private: System::Windows::Forms::Label^  imeiLabel;
private: System::Windows::Forms::Label^  batteryLabel;
private: System::Windows::Forms::Label^  locationLabel;
private: System::Windows::Forms::GroupBox^  trackerDetailsGroup;

private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::GroupBox^  trackerStatusGroup;

private: System::Windows::Forms::Label^  label24;
private: System::Windows::Forms::Label^  label23;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  bleVersionLabel;
private: System::Windows::Forms::Label^  label25;

private: System::Windows::Forms::CheckBox^  alertPositionCheck;

private: System::Windows::Forms::Label^  rawLabel;
private: System::Windows::Forms::Label^  label27;
private: System::Windows::Forms::ComboBox^  burstFixCombo;
private: System::Windows::Forms::ComboBox^  burstTransmitCombo;
private: System::Windows::Forms::Label^  label28;
private: System::Windows::Forms::Label^  label29;
private: System::Windows::Forms::ComboBox^  gpsHotCombo;
private: System::Windows::Forms::Label^  label30;
private: System::Windows::Forms::ComboBox^  activityStatusCombo;
private: System::Windows::Forms::ComboBox^  trkCarrierCombo;

private: System::Windows::Forms::ComboBox^  activityLowCombo;
private: System::Windows::Forms::Label^  label31;
private: System::Windows::Forms::Label^  label32;
private: System::Windows::Forms::Label^  label33;
private: System::Windows::Forms::ComboBox^  geofStatusCombo;
private: System::Windows::Forms::ComboBox^  geofPeriodCombo;
private: System::Windows::Forms::ComboBox^  geofDistanceCombo;
private: System::Windows::Forms::Label^  label34;
private: System::Windows::Forms::Label^  label35;
private: System::Windows::Forms::Label^  label36;
private: System::Windows::Forms::ComboBox^  powerLimitCombo;
private: System::Windows::Forms::Label^  label37;
private: System::Windows::Forms::ComboBox^  notificationsCombo;

private: System::Windows::Forms::Label^  label38;





private: System::Windows::Forms::Label^  gprsLabel;
private: System::Windows::Forms::Label^  label40;

private: System::Windows::Forms::Label^  gprsStatus;
private: System::Windows::Forms::Label^  gprsSignal;
private: System::Windows::Forms::Label^  gprsLocation;
private: System::Windows::Forms::Label^  label46;
private: System::Windows::Forms::Label^  gprsMsisdn;
private: System::Windows::Forms::Label^  label45;
private: System::Windows::Forms::Label^  label44;
private: System::Windows::Forms::Label^  label43;
private: System::Windows::Forms::Label^  gprsSim;
private: System::Windows::Forms::Label^  label41;
private: System::Windows::Forms::Timer^  testEventTimer;







private: System::Windows::Forms::Label^  selfTest;
private: System::Windows::Forms::Label^  label42;
private: System::Windows::Forms::Button^  nmeaGrabButton;
private: System::Windows::Forms::TextBox^  nmeaGrabText;










private: System::Windows::Forms::ListBox^  scanList;
private: System::Windows::Forms::GroupBox^  nmeaGroup;
private: System::Windows::Forms::GroupBox^  generalCommandGroup;
private: System::Windows::Forms::GroupBox^  genericAlertGroup;

private: System::Windows::Forms::ComboBox^  extSensitivityCombo;
private: System::Windows::Forms::Label^  label26;


private: System::Windows::Forms::GroupBox^  gprsConfigurationGroup;





































private: System::Windows::Forms::Button^  gprsSetButton;

private: System::Windows::Forms::Button^  gprsGetButton;
private: System::Windows::Forms::Label^  label51;
private: System::Windows::Forms::ComboBox^  logoComboBox;

private: System::Windows::Forms::Label^  label52;
private: System::Windows::Forms::ComboBox^  rawCombo;
private: System::Windows::Forms::GroupBox^  statusGroup;

private: System::Windows::Forms::ComboBox^  getStatusCombo;
private: System::Windows::Forms::TextBox^  getStatusTextBox;
private: System::Windows::Forms::Label^  label39;
private: System::Windows::Forms::Label^  label47;
private: System::Windows::Forms::Label^  label48;
private: System::Windows::Forms::Label^  label49;
private: System::Windows::Forms::Label^  label50;
private: System::Windows::Forms::Label^  label53;
private: System::Windows::Forms::ComboBox^  autoTxCellCombo;
private: System::Windows::Forms::ComboBox^  burstTxCellCombo;
private: System::Windows::Forms::ComboBox^  burstFixCellCombo;
private: System::Windows::Forms::ComboBox^  autoTxDistressCombo;
private: System::Windows::Forms::ComboBox^  burstTxDistressCombo;
private: System::Windows::Forms::ComboBox^  burstFixDistressCombo;
private: System::Windows::Forms::ComboBox^  positionBlockCombo;
private: System::Windows::Forms::Label^  label54;
private: System::Windows::Forms::ComboBox^  gpxStatusCombo;
private: System::Windows::Forms::Label^  label55;
private: System::Windows::Forms::ComboBox^  gpxPeriodCombo;

private: System::Windows::Forms::Label^  label56;
private: System::Windows::Forms::Label^  locationLabel2;
private: System::Windows::Forms::CheckBox^  uuidCheck;
private: System::Windows::Forms::ComboBox^  mailCheckStatusCombo;
private: System::Windows::Forms::ComboBox^  mailCheckPeriodCombo;


private: System::Windows::Forms::Label^  label57;
private: System::Windows::Forms::Label^  label58;
private: System::Windows::Forms::ComboBox^  gpsPlatformCombo;
private: System::Windows::Forms::Label^  label59;
private: System::Windows::Forms::ComboBox^  configureName;
private: System::Windows::Forms::ComboBox^  configureValue;
private: System::Windows::Forms::GroupBox^  configureGroup;

private: System::Windows::Forms::Button^  configureButton;
private: System::Windows::Forms::Label^  label60;
private: System::Windows::Forms::ComboBox^  airAlertStatus;
private: System::Windows::Forms::Label^  label61;
private: System::Windows::Forms::ComboBox^  airAlertDescentSpeed;
private: System::Windows::Forms::ComboBox^  airAlertDescentTime;


private: System::Windows::Forms::Label^  label62;
private: System::Windows::Forms::ComboBox^  airAlertAscentSpeed;
private: System::Windows::Forms::ComboBox^  airAlertAscentTime;
private: System::Windows::Forms::Label^  label63;
private: System::Windows::Forms::Label^  label64;
private: System::Windows::Forms::Button^  configureGetButton;
private: System::Windows::Forms::TextBox^  gprsSetText;
private: System::Windows::Forms::ComboBox^  gprsSettings;
private: System::Windows::Forms::TableLayoutPanel^  settingsTableExtended;

private: System::Windows::Forms::ComboBox^  flightMode;
private: System::Windows::Forms::ComboBox^  flightVr;
private: System::Windows::Forms::ComboBox^  flightVs;




private: System::Windows::Forms::Label^  label65;
private: System::Windows::Forms::Label^  label66;
private: System::Windows::Forms::Label^  label67;
private: System::Windows::Forms::Label^  WatchStatusLabel;
private: System::Windows::Forms::Label^  TxContextLabel;
private: System::Windows::Forms::Label^  label68;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::ComboBox^  extButtons;
private: System::Windows::Forms::Label^  label69;
private: System::Windows::Forms::Label^  selfTestResult;
private: System::Windows::Forms::Label^  label70;
private: System::Windows::Forms::Button^  testButton;





















			 int _trackerState;
        
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->outMsg = (gcnew System::Windows::Forms::TextBox());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->sendStatus = (gcnew System::Windows::Forms::Label());
			this->inMsg = (gcnew System::Windows::Forms::TextBox());
			this->serialTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->commsLog = (gcnew System::Windows::Forms::TextBox());
			this->resetLogButton = (gcnew System::Windows::Forms::Button());
			this->portNumber = (gcnew System::Windows::Forms::TextBox());
			this->macText = (gcnew System::Windows::Forms::TextBox());
			this->connectStatus = (gcnew System::Windows::Forms::Label());
			this->connectButton = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->logButton = (gcnew System::Windows::Forms::Button());
			this->trkStatusComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->trkPeriodComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->composeMsg = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->inboxCount = (gcnew System::Windows::Forms::TextBox());
			this->getButton = (gcnew System::Windows::Forms::Button());
			this->gpsLabel = (gcnew System::Windows::Forms::Label());
			this->iridiumLabel = (gcnew System::Windows::Forms::Label());
			this->pinLockLabel = (gcnew System::Windows::Forms::Label());
			this->unlockPinBox = (gcnew System::Windows::Forms::TextBox());
			this->newPinBox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->submitButton = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->messagingGroup = (gcnew System::Windows::Forms::GroupBox());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->uuidCheck = (gcnew System::Windows::Forms::CheckBox());
			this->scanList = (gcnew System::Windows::Forms::ListBox());
			this->androidCheck = (gcnew System::Windows::Forms::CheckBox());
			this->pinGroup = (gcnew System::Windows::Forms::GroupBox());
			this->settingsTable = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->externalMOBCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->burstFixCombo = (gcnew System::Windows::Forms::ComboBox());
			this->burstTransmitCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label28 = (gcnew System::Windows::Forms::Label());
			this->label29 = (gcnew System::Windows::Forms::Label());
			this->gpsHotCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label30 = (gcnew System::Windows::Forms::Label());
			this->activityStatusCombo = (gcnew System::Windows::Forms::ComboBox());
			this->trkCarrierCombo = (gcnew System::Windows::Forms::ComboBox());
			this->activityLowCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label31 = (gcnew System::Windows::Forms::Label());
			this->label32 = (gcnew System::Windows::Forms::Label());
			this->label33 = (gcnew System::Windows::Forms::Label());
			this->geofStatusCombo = (gcnew System::Windows::Forms::ComboBox());
			this->geofPeriodCombo = (gcnew System::Windows::Forms::ComboBox());
			this->geofDistanceCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label34 = (gcnew System::Windows::Forms::Label());
			this->label35 = (gcnew System::Windows::Forms::Label());
			this->label36 = (gcnew System::Windows::Forms::Label());
			this->powerLimitCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label37 = (gcnew System::Windows::Forms::Label());
			this->notificationsCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label38 = (gcnew System::Windows::Forms::Label());
			this->externalBaudCombo = (gcnew System::Windows::Forms::ComboBox());
			this->externalSamplesCombo = (gcnew System::Windows::Forms::ComboBox());
			this->externalTypeCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->extSensitivityCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label26 = (gcnew System::Windows::Forms::Label());
			this->label39 = (gcnew System::Windows::Forms::Label());
			this->label47 = (gcnew System::Windows::Forms::Label());
			this->label48 = (gcnew System::Windows::Forms::Label());
			this->label49 = (gcnew System::Windows::Forms::Label());
			this->label50 = (gcnew System::Windows::Forms::Label());
			this->label53 = (gcnew System::Windows::Forms::Label());
			this->autoTxCellCombo = (gcnew System::Windows::Forms::ComboBox());
			this->burstTxCellCombo = (gcnew System::Windows::Forms::ComboBox());
			this->burstFixCellCombo = (gcnew System::Windows::Forms::ComboBox());
			this->autoTxDistressCombo = (gcnew System::Windows::Forms::ComboBox());
			this->burstTxDistressCombo = (gcnew System::Windows::Forms::ComboBox());
			this->burstFixDistressCombo = (gcnew System::Windows::Forms::ComboBox());
			this->positionBlockCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label54 = (gcnew System::Windows::Forms::Label());
			this->gpxStatusCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label55 = (gcnew System::Windows::Forms::Label());
			this->gpxPeriodCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label56 = (gcnew System::Windows::Forms::Label());
			this->mailCheckStatusCombo = (gcnew System::Windows::Forms::ComboBox());
			this->mailCheckPeriodCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label57 = (gcnew System::Windows::Forms::Label());
			this->label58 = (gcnew System::Windows::Forms::Label());
			this->gpsPlatformCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label59 = (gcnew System::Windows::Forms::Label());
			this->label60 = (gcnew System::Windows::Forms::Label());
			this->airAlertStatus = (gcnew System::Windows::Forms::ComboBox());
			this->label61 = (gcnew System::Windows::Forms::Label());
			this->airAlertDescentSpeed = (gcnew System::Windows::Forms::ComboBox());
			this->airAlertDescentTime = (gcnew System::Windows::Forms::ComboBox());
			this->label62 = (gcnew System::Windows::Forms::Label());
			this->airAlertAscentSpeed = (gcnew System::Windows::Forms::ComboBox());
			this->airAlertAscentTime = (gcnew System::Windows::Forms::ComboBox());
			this->label63 = (gcnew System::Windows::Forms::Label());
			this->label64 = (gcnew System::Windows::Forms::Label());
			this->commandComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->Imei = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->serialText = (gcnew System::Windows::Forms::TextBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->modelText = (gcnew System::Windows::Forms::TextBox());
			this->factorySetButton = (gcnew System::Windows::Forms::Button());
			this->factoryGroup = (gcnew System::Windows::Forms::GroupBox());
			this->label52 = (gcnew System::Windows::Forms::Label());
			this->rawCombo = (gcnew System::Windows::Forms::ComboBox());
			this->label51 = (gcnew System::Windows::Forms::Label());
			this->logoComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->alertEnum = (gcnew System::Windows::Forms::ComboBox());
			this->powerLabel = (gcnew System::Windows::Forms::Label());
			this->shippingLabel = (gcnew System::Windows::Forms::Label());
			this->productNameLabel = (gcnew System::Windows::Forms::Label());
			this->versionLabel = (gcnew System::Windows::Forms::Label());
			this->imeiLabel = (gcnew System::Windows::Forms::Label());
			this->batteryLabel = (gcnew System::Windows::Forms::Label());
			this->locationLabel = (gcnew System::Windows::Forms::Label());
			this->trackerDetailsGroup = (gcnew System::Windows::Forms::GroupBox());
			this->rawLabel = (gcnew System::Windows::Forms::Label());
			this->label27 = (gcnew System::Windows::Forms::Label());
			this->bleVersionLabel = (gcnew System::Windows::Forms::Label());
			this->label25 = (gcnew System::Windows::Forms::Label());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->trackerStatusGroup = (gcnew System::Windows::Forms::GroupBox());
			this->selfTestResult = (gcnew System::Windows::Forms::Label());
			this->label70 = (gcnew System::Windows::Forms::Label());
			this->WatchStatusLabel = (gcnew System::Windows::Forms::Label());
			this->TxContextLabel = (gcnew System::Windows::Forms::Label());
			this->label68 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->locationLabel2 = (gcnew System::Windows::Forms::Label());
			this->selfTest = (gcnew System::Windows::Forms::Label());
			this->label42 = (gcnew System::Windows::Forms::Label());
			this->gprsStatus = (gcnew System::Windows::Forms::Label());
			this->gprsSignal = (gcnew System::Windows::Forms::Label());
			this->gprsLocation = (gcnew System::Windows::Forms::Label());
			this->label46 = (gcnew System::Windows::Forms::Label());
			this->gprsMsisdn = (gcnew System::Windows::Forms::Label());
			this->label45 = (gcnew System::Windows::Forms::Label());
			this->label44 = (gcnew System::Windows::Forms::Label());
			this->label43 = (gcnew System::Windows::Forms::Label());
			this->gprsSim = (gcnew System::Windows::Forms::Label());
			this->label41 = (gcnew System::Windows::Forms::Label());
			this->gprsLabel = (gcnew System::Windows::Forms::Label());
			this->label40 = (gcnew System::Windows::Forms::Label());
			this->label24 = (gcnew System::Windows::Forms::Label());
			this->label23 = (gcnew System::Windows::Forms::Label());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->alertPositionCheck = (gcnew System::Windows::Forms::CheckBox());
			this->testEventTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->nmeaGrabButton = (gcnew System::Windows::Forms::Button());
			this->nmeaGrabText = (gcnew System::Windows::Forms::TextBox());
			this->nmeaGroup = (gcnew System::Windows::Forms::GroupBox());
			this->generalCommandGroup = (gcnew System::Windows::Forms::GroupBox());
			this->statusGroup = (gcnew System::Windows::Forms::GroupBox());
			this->getStatusCombo = (gcnew System::Windows::Forms::ComboBox());
			this->getStatusTextBox = (gcnew System::Windows::Forms::TextBox());
			this->genericAlertGroup = (gcnew System::Windows::Forms::GroupBox());
			this->gprsConfigurationGroup = (gcnew System::Windows::Forms::GroupBox());
			this->gprsSetText = (gcnew System::Windows::Forms::TextBox());
			this->gprsSettings = (gcnew System::Windows::Forms::ComboBox());
			this->gprsSetButton = (gcnew System::Windows::Forms::Button());
			this->gprsGetButton = (gcnew System::Windows::Forms::Button());
			this->configureName = (gcnew System::Windows::Forms::ComboBox());
			this->configureValue = (gcnew System::Windows::Forms::ComboBox());
			this->configureGroup = (gcnew System::Windows::Forms::GroupBox());
			this->configureGetButton = (gcnew System::Windows::Forms::Button());
			this->configureButton = (gcnew System::Windows::Forms::Button());
			this->settingsTableExtended = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->flightMode = (gcnew System::Windows::Forms::ComboBox());
			this->flightVr = (gcnew System::Windows::Forms::ComboBox());
			this->flightVs = (gcnew System::Windows::Forms::ComboBox());
			this->label65 = (gcnew System::Windows::Forms::Label());
			this->label66 = (gcnew System::Windows::Forms::Label());
			this->label67 = (gcnew System::Windows::Forms::Label());
			this->extButtons = (gcnew System::Windows::Forms::ComboBox());
			this->label69 = (gcnew System::Windows::Forms::Label());
			this->testButton = (gcnew System::Windows::Forms::Button());
			this->messagingGroup->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->pinGroup->SuspendLayout();
			this->settingsTable->SuspendLayout();
			this->factoryGroup->SuspendLayout();
			this->trackerDetailsGroup->SuspendLayout();
			this->trackerStatusGroup->SuspendLayout();
			this->nmeaGroup->SuspendLayout();
			this->generalCommandGroup->SuspendLayout();
			this->statusGroup->SuspendLayout();
			this->genericAlertGroup->SuspendLayout();
			this->gprsConfigurationGroup->SuspendLayout();
			this->configureGroup->SuspendLayout();
			this->settingsTableExtended->SuspendLayout();
			this->SuspendLayout();
			// 
			// outMsg
			// 
			this->outMsg->BackColor = System::Drawing::SystemColors::Window;
			this->outMsg->Location = System::Drawing::Point(6, 180);
			this->outMsg->Multiline = true;
			this->outMsg->Name = L"outMsg";
			this->outMsg->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->outMsg->Size = System::Drawing::Size(160, 82);
			this->outMsg->TabIndex = 0;
			// 
			// sendButton
			// 
			this->sendButton->Location = System::Drawing::Point(6, 129);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(44, 20);
			this->sendButton->TabIndex = 1;
			this->sendButton->Text = L"Send";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &Form1::sendButton_Click);
			// 
			// sendStatus
			// 
			this->sendStatus->AutoSize = true;
			this->sendStatus->Location = System::Drawing::Point(8, 21);
			this->sendStatus->Name = L"sendStatus";
			this->sendStatus->Size = System::Drawing::Size(24, 13);
			this->sendStatus->TabIndex = 2;
			this->sendStatus->Text = L"Idle";
			// 
			// inMsg
			// 
			this->inMsg->BackColor = System::Drawing::SystemColors::Window;
			this->inMsg->Enabled = false;
			this->inMsg->Location = System::Drawing::Point(10, 300);
			this->inMsg->Multiline = true;
			this->inMsg->Name = L"inMsg";
			this->inMsg->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->inMsg->Size = System::Drawing::Size(160, 72);
			this->inMsg->TabIndex = 0;
			// 
			// serialTimer
			// 
			this->serialTimer->Tick += gcnew System::EventHandler(this, &Form1::serialTimer_Tick);
			// 
			// commsLog
			// 
			this->commsLog->BackColor = System::Drawing::SystemColors::Window;
			this->commsLog->Location = System::Drawing::Point(10, 431);
			this->commsLog->Multiline = true;
			this->commsLog->Name = L"commsLog";
			this->commsLog->ScrollBars = System::Windows::Forms::ScrollBars::Both;
			this->commsLog->Size = System::Drawing::Size(192, 98);
			this->commsLog->TabIndex = 9;
			this->commsLog->Visible = false;
			// 
			// resetLogButton
			// 
			this->resetLogButton->Location = System::Drawing::Point(155, 535);
			this->resetLogButton->Name = L"resetLogButton";
			this->resetLogButton->Size = System::Drawing::Size(47, 19);
			this->resetLogButton->TabIndex = 10;
			this->resetLogButton->Text = L"Clear";
			this->resetLogButton->UseVisualStyleBackColor = true;
			this->resetLogButton->Visible = false;
			this->resetLogButton->Click += gcnew System::EventHandler(this, &Form1::resetLogButton_Click);
			// 
			// portNumber
			// 
			this->portNumber->Location = System::Drawing::Point(103, 35);
			this->portNumber->Name = L"portNumber";
			this->portNumber->Size = System::Drawing::Size(24, 20);
			this->portNumber->TabIndex = 5;
			// 
			// macText
			// 
			this->macText->Location = System::Drawing::Point(9, 37);
			this->macText->Name = L"macText";
			this->macText->Size = System::Drawing::Size(83, 20);
			this->macText->TabIndex = 2;
			// 
			// connectStatus
			// 
			this->connectStatus->AutoSize = true;
			this->connectStatus->BackColor = System::Drawing::SystemColors::Control;
			this->connectStatus->Location = System::Drawing::Point(6, 238);
			this->connectStatus->Name = L"connectStatus";
			this->connectStatus->Size = System::Drawing::Size(76, 13);
			this->connectStatus->TabIndex = 4;
			this->connectStatus->Text = L" Disconnected";
			// 
			// connectButton
			// 
			this->connectButton->Location = System::Drawing::Point(9, 192);
			this->connectButton->Name = L"connectButton";
			this->connectButton->Size = System::Drawing::Size(51, 20);
			this->connectButton->TabIndex = 3;
			this->connectButton->Text = L"Scan";
			this->connectButton->UseVisualStyleBackColor = true;
			this->connectButton->Click += gcnew System::EventHandler(this, &Form1::connectButton_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(54, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"This Mac:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(100, 21);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(29, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Port:";
			// 
			// logButton
			// 
			this->logButton->Location = System::Drawing::Point(10, 535);
			this->logButton->Name = L"logButton";
			this->logButton->Size = System::Drawing::Size(71, 19);
			this->logButton->TabIndex = 11;
			this->logButton->Text = L"Show Log";
			this->logButton->UseVisualStyleBackColor = true;
			this->logButton->Click += gcnew System::EventHandler(this, &Form1::logButton_Click);
			// 
			// trkStatusComboBox
			// 
			this->trkStatusComboBox->AllowDrop = true;
			this->trkStatusComboBox->FormattingEnabled = true;
			this->trkStatusComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Off", L"On"});
			this->trkStatusComboBox->Location = System::Drawing::Point(3, 3);
			this->trkStatusComboBox->Name = L"trkStatusComboBox";
			this->trkStatusComboBox->Size = System::Drawing::Size(86, 21);
			this->trkStatusComboBox->TabIndex = 15;
			this->trkStatusComboBox->SelectionChangeCommitted += gcnew System::EventHandler(this, &Form1::trkStatusComboBox_SelectionChangeCommitted);
			// 
			// trkPeriodComboBox
			// 
			this->trkPeriodComboBox->FormattingEnabled = true;
			this->trkPeriodComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(25) {L"Continuous", L"5 min", L"10 min", L"15 min", 
				L"20 min", L"30 min", L"1 hour", L"90 min", L"2 hour", L"3 hour", L"4 hour", L"6 hour", L"8 hour", L"12 hour", L"Burst", L"1 min", 
				L"2 min", L"3 min", L"4 min", L"24 hour", L"6 min", L"8 min", L"12 min", L"15 sec", L"30 sec"});
			this->trkPeriodComboBox->Location = System::Drawing::Point(3, 21);
			this->trkPeriodComboBox->Name = L"trkPeriodComboBox";
			this->trkPeriodComboBox->Size = System::Drawing::Size(86, 21);
			this->trkPeriodComboBox->TabIndex = 16;
			this->trkPeriodComboBox->SelectionChangeCommitted += gcnew System::EventHandler(this, &Form1::trkPeriodComboBox_SelectionChangeCommitted);
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(96, 2);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(82, 13);
			this->label3->TabIndex = 17;
			this->label3->Text = L"Tracking Status";
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(96, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(82, 13);
			this->label4->TabIndex = 18;
			this->label4->Text = L"Tracking Period";
			// 
			// composeMsg
			// 
			this->composeMsg->Location = System::Drawing::Point(6, 62);
			this->composeMsg->Multiline = true;
			this->composeMsg->Name = L"composeMsg";
			this->composeMsg->Size = System::Drawing::Size(164, 61);
			this->composeMsg->TabIndex = 20;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(6, 167);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(32, 13);
			this->label5->TabIndex = 21;
			this->label5->Text = L"Sent:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(7, 286);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(56, 13);
			this->label6->TabIndex = 22;
			this->label6->Text = L"Received:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(7, 46);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(54, 13);
			this->label7->TabIndex = 23;
			this->label7->Text = L"Compose:";
			// 
			// inboxCount
			// 
			this->inboxCount->Location = System::Drawing::Point(112, 380);
			this->inboxCount->Name = L"inboxCount";
			this->inboxCount->Size = System::Drawing::Size(58, 20);
			this->inboxCount->TabIndex = 24;
			// 
			// getButton
			// 
			this->getButton->Location = System::Drawing::Point(11, 377);
			this->getButton->Name = L"getButton";
			this->getButton->Size = System::Drawing::Size(39, 23);
			this->getButton->TabIndex = 26;
			this->getButton->Text = L"Get";
			this->getButton->UseVisualStyleBackColor = true;
			this->getButton->Click += gcnew System::EventHandler(this, &Form1::getButton_Click_1);
			// 
			// gpsLabel
			// 
			this->gpsLabel->AutoSize = true;
			this->gpsLabel->Location = System::Drawing::Point(83, 115);
			this->gpsLabel->Name = L"gpsLabel";
			this->gpsLabel->Size = System::Drawing::Size(24, 13);
			this->gpsLabel->TabIndex = 29;
			this->gpsLabel->Text = L"Idle";
			// 
			// iridiumLabel
			// 
			this->iridiumLabel->AutoSize = true;
			this->iridiumLabel->Location = System::Drawing::Point(83, 131);
			this->iridiumLabel->Name = L"iridiumLabel";
			this->iridiumLabel->Size = System::Drawing::Size(24, 13);
			this->iridiumLabel->TabIndex = 30;
			this->iridiumLabel->Text = L"Idle";
			// 
			// pinLockLabel
			// 
			this->pinLockLabel->AutoSize = true;
			this->pinLockLabel->Location = System::Drawing::Point(88, 84);
			this->pinLockLabel->Name = L"pinLockLabel";
			this->pinLockLabel->Size = System::Drawing::Size(43, 13);
			this->pinLockLabel->TabIndex = 31;
			this->pinLockLabel->Text = L"Locked";
			// 
			// unlockPinBox
			// 
			this->unlockPinBox->Location = System::Drawing::Point(9, 43);
			this->unlockPinBox->Name = L"unlockPinBox";
			this->unlockPinBox->Size = System::Drawing::Size(50, 20);
			this->unlockPinBox->TabIndex = 32;
			// 
			// newPinBox
			// 
			this->newPinBox->Location = System::Drawing::Point(81, 43);
			this->newPinBox->Name = L"newPinBox";
			this->newPinBox->Size = System::Drawing::Size(50, 20);
			this->newPinBox->TabIndex = 33;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 27);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(53, 13);
			this->label8->TabIndex = 34;
			this->label8->Text = L"Enter Pin:";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(78, 27);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(50, 13);
			this->label9->TabIndex = 35;
			this->label9->Text = L"New Pin:";
			// 
			// submitButton
			// 
			this->submitButton->Location = System::Drawing::Point(9, 75);
			this->submitButton->Name = L"submitButton";
			this->submitButton->Size = System::Drawing::Size(60, 22);
			this->submitButton->TabIndex = 37;
			this->submitButton->Text = L"Submit";
			this->submitButton->UseVisualStyleBackColor = true;
			this->submitButton->Click += gcnew System::EventHandler(this, &Form1::submitButton_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 16);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(54, 13);
			this->label10->TabIndex = 39;
			this->label10->Text = L"Battery%: ";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(6, 32);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(48, 13);
			this->label11->TabIndex = 41;
			this->label11->Text = L"Version: ";
			// 
			// messagingGroup
			// 
			this->messagingGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->messagingGroup->Controls->Add(this->inMsg);
			this->messagingGroup->Controls->Add(this->sendButton);
			this->messagingGroup->Controls->Add(this->sendStatus);
			this->messagingGroup->Controls->Add(this->outMsg);
			this->messagingGroup->Controls->Add(this->composeMsg);
			this->messagingGroup->Controls->Add(this->label5);
			this->messagingGroup->Controls->Add(this->label6);
			this->messagingGroup->Controls->Add(this->label7);
			this->messagingGroup->Controls->Add(this->inboxCount);
			this->messagingGroup->Controls->Add(this->getButton);
			this->messagingGroup->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->messagingGroup->Location = System::Drawing::Point(226, 12);
			this->messagingGroup->Name = L"messagingGroup";
			this->messagingGroup->Size = System::Drawing::Size(178, 415);
			this->messagingGroup->TabIndex = 42;
			this->messagingGroup->TabStop = false;
			this->messagingGroup->Text = L"Messaging";
			this->messagingGroup->Enter += gcnew System::EventHandler(this, &Form1::messagingGroup_Enter);
			// 
			// groupBox2
			// 
			this->groupBox2->BackColor = System::Drawing::SystemColors::ControlDark;
			this->groupBox2->Controls->Add(this->uuidCheck);
			this->groupBox2->Controls->Add(this->scanList);
			this->groupBox2->Controls->Add(this->androidCheck);
			this->groupBox2->Controls->Add(this->macText);
			this->groupBox2->Controls->Add(this->portNumber);
			this->groupBox2->Controls->Add(this->connectStatus);
			this->groupBox2->Controls->Add(this->connectButton);
			this->groupBox2->Controls->Add(this->label1);
			this->groupBox2->Controls->Add(this->label2);
			this->groupBox2->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->groupBox2->Location = System::Drawing::Point(10, 12);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(192, 261);
			this->groupBox2->TabIndex = 43;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Connection";
			// 
			// uuidCheck
			// 
			this->uuidCheck->AutoSize = true;
			this->uuidCheck->Location = System::Drawing::Point(87, 195);
			this->uuidCheck->Name = L"uuidCheck";
			this->uuidCheck->Size = System::Drawing::Size(51, 17);
			this->uuidCheck->TabIndex = 74;
			this->uuidCheck->Text = L"uuids";
			this->uuidCheck->UseVisualStyleBackColor = true;
			this->uuidCheck->CheckedChanged += gcnew System::EventHandler(this, &Form1::uuidCheck_CheckedChanged);
			// 
			// scanList
			// 
			this->scanList->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->scanList->FormattingEnabled = true;
			this->scanList->Location = System::Drawing::Point(9, 114);
			this->scanList->Name = L"scanList";
			this->scanList->ScrollAlwaysVisible = true;
			this->scanList->Size = System::Drawing::Size(168, 65);
			this->scanList->TabIndex = 73;
			this->scanList->DoubleClick += gcnew System::EventHandler(this, &Form1::scanList_DoubleClick);
			// 
			// androidCheck
			// 
			this->androidCheck->AutoSize = true;
			this->androidCheck->Location = System::Drawing::Point(11, 73);
			this->androidCheck->Name = L"androidCheck";
			this->androidCheck->Size = System::Drawing::Size(62, 17);
			this->androidCheck->TabIndex = 8;
			this->androidCheck->Text = L"Android";
			this->androidCheck->UseVisualStyleBackColor = true;
			this->androidCheck->CheckedChanged += gcnew System::EventHandler(this, &Form1::androidCheck_CheckedChanged);
			// 
			// pinGroup
			// 
			this->pinGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->pinGroup->Controls->Add(this->newPinBox);
			this->pinGroup->Controls->Add(this->pinLockLabel);
			this->pinGroup->Controls->Add(this->unlockPinBox);
			this->pinGroup->Controls->Add(this->label8);
			this->pinGroup->Controls->Add(this->label9);
			this->pinGroup->Controls->Add(this->submitButton);
			this->pinGroup->Location = System::Drawing::Point(12, 288);
			this->pinGroup->Name = L"pinGroup";
			this->pinGroup->Size = System::Drawing::Size(190, 110);
			this->pinGroup->TabIndex = 44;
			this->pinGroup->TabStop = false;
			this->pinGroup->Text = L"Pin";
			// 
			// settingsTable
			// 
			this->settingsTable->BackColor = System::Drawing::SystemColors::ControlDark;
			this->settingsTable->ColumnCount = 2;
			this->settingsTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				43.01994F)));
			this->settingsTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				56.98006F)));
			this->settingsTable->Controls->Add(this->label3, 1, 0);
			this->settingsTable->Controls->Add(this->label15, 1, 3);
			this->settingsTable->Controls->Add(this->label16, 1, 4);
			this->settingsTable->Controls->Add(this->externalMOBCombo, 0, 5);
			this->settingsTable->Controls->Add(this->label19, 1, 5);
			this->settingsTable->Controls->Add(this->burstFixCombo, 0, 6);
			this->settingsTable->Controls->Add(this->burstTransmitCombo, 0, 7);
			this->settingsTable->Controls->Add(this->label28, 1, 6);
			this->settingsTable->Controls->Add(this->label29, 1, 7);
			this->settingsTable->Controls->Add(this->gpsHotCombo, 0, 8);
			this->settingsTable->Controls->Add(this->label30, 1, 8);
			this->settingsTable->Controls->Add(this->activityStatusCombo, 0, 9);
			this->settingsTable->Controls->Add(this->trkCarrierCombo, 0, 10);
			this->settingsTable->Controls->Add(this->activityLowCombo, 0, 11);
			this->settingsTable->Controls->Add(this->label31, 1, 9);
			this->settingsTable->Controls->Add(this->label32, 1, 10);
			this->settingsTable->Controls->Add(this->label33, 1, 11);
			this->settingsTable->Controls->Add(this->geofStatusCombo, 0, 12);
			this->settingsTable->Controls->Add(this->geofPeriodCombo, 0, 13);
			this->settingsTable->Controls->Add(this->geofDistanceCombo, 0, 14);
			this->settingsTable->Controls->Add(this->label34, 1, 12);
			this->settingsTable->Controls->Add(this->label35, 1, 13);
			this->settingsTable->Controls->Add(this->label36, 1, 14);
			this->settingsTable->Controls->Add(this->powerLimitCombo, 0, 15);
			this->settingsTable->Controls->Add(this->label37, 1, 15);
			this->settingsTable->Controls->Add(this->notificationsCombo, 0, 16);
			this->settingsTable->Controls->Add(this->label38, 1, 16);
			this->settingsTable->Controls->Add(this->externalBaudCombo, 0, 3);
			this->settingsTable->Controls->Add(this->externalSamplesCombo, 0, 4);
			this->settingsTable->Controls->Add(this->trkStatusComboBox, 0, 0);
			this->settingsTable->Controls->Add(this->externalTypeCombo, 0, 2);
			this->settingsTable->Controls->Add(this->trkPeriodComboBox, 0, 1);
			this->settingsTable->Controls->Add(this->label14, 1, 2);
			this->settingsTable->Controls->Add(this->label4, 1, 1);
			this->settingsTable->Controls->Add(this->extSensitivityCombo, 0, 17);
			this->settingsTable->Controls->Add(this->label26, 1, 17);
			this->settingsTable->Controls->Add(this->label39, 1, 18);
			this->settingsTable->Controls->Add(this->label47, 1, 19);
			this->settingsTable->Controls->Add(this->label48, 1, 20);
			this->settingsTable->Controls->Add(this->label49, 1, 21);
			this->settingsTable->Controls->Add(this->label50, 1, 22);
			this->settingsTable->Controls->Add(this->label53, 1, 23);
			this->settingsTable->Controls->Add(this->autoTxCellCombo, 0, 18);
			this->settingsTable->Controls->Add(this->burstTxCellCombo, 0, 19);
			this->settingsTable->Controls->Add(this->burstFixCellCombo, 0, 20);
			this->settingsTable->Controls->Add(this->autoTxDistressCombo, 0, 21);
			this->settingsTable->Controls->Add(this->burstTxDistressCombo, 0, 22);
			this->settingsTable->Controls->Add(this->burstFixDistressCombo, 0, 23);
			this->settingsTable->Controls->Add(this->positionBlockCombo, 0, 24);
			this->settingsTable->Controls->Add(this->label54, 1, 24);
			this->settingsTable->Controls->Add(this->gpxStatusCombo, 0, 25);
			this->settingsTable->Controls->Add(this->label55, 1, 25);
			this->settingsTable->Controls->Add(this->gpxPeriodCombo, 0, 26);
			this->settingsTable->Controls->Add(this->label56, 1, 26);
			this->settingsTable->Controls->Add(this->mailCheckStatusCombo, 0, 27);
			this->settingsTable->Controls->Add(this->mailCheckPeriodCombo, 0, 28);
			this->settingsTable->Controls->Add(this->label57, 1, 27);
			this->settingsTable->Controls->Add(this->label58, 1, 28);
			this->settingsTable->Location = System::Drawing::Point(848, 12);
			this->settingsTable->Name = L"settingsTable";
			this->settingsTable->RowCount = 31;
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 18)));
			this->settingsTable->Size = System::Drawing::Size(217, 552);
			this->settingsTable->TabIndex = 45;
			// 
			// label15
			// 
			this->label15->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(96, 56);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(73, 13);
			this->label15->TabIndex = 24;
			this->label15->Text = L"External Baud";
			// 
			// label16
			// 
			this->label16->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(96, 74);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(88, 13);
			this->label16->TabIndex = 25;
			this->label16->Text = L"External Samples";
			// 
			// externalMOBCombo
			// 
			this->externalMOBCombo->FormattingEnabled = true;
			this->externalMOBCombo->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Off", L"On"});
			this->externalMOBCombo->Location = System::Drawing::Point(3, 93);
			this->externalMOBCombo->Name = L"externalMOBCombo";
			this->externalMOBCombo->Size = System::Drawing::Size(86, 21);
			this->externalMOBCombo->TabIndex = 26;
			this->externalMOBCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::externalMOBCombo_SelectedIndexChanged);
			// 
			// label19
			// 
			this->label19->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(96, 92);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(31, 13);
			this->label19->TabIndex = 27;
			this->label19->Text = L"MOB";
			// 
			// burstFixCombo
			// 
			this->burstFixCombo->FormattingEnabled = true;
			this->burstFixCombo->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"5 secs", L"10 secs", L"15 secs", L"20 secs", 
				L"30 secs", L"1 min", L"2 min", L"5 min", L"10 min", L"15 min", L"20 min"});
			this->burstFixCombo->Location = System::Drawing::Point(3, 111);
			this->burstFixCombo->Name = L"burstFixCombo";
			this->burstFixCombo->Size = System::Drawing::Size(86, 21);
			this->burstFixCombo->TabIndex = 28;
			this->burstFixCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::burstFixCombo_SelectedIndexChanged);
			// 
			// burstTransmitCombo
			// 
			this->burstTransmitCombo->FormattingEnabled = true;
			this->burstTransmitCombo->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"1 min", L"2 min", L"5 min", L"10 min", 
				L"15 min", L"30 min", L"60 min"});
			this->burstTransmitCombo->Location = System::Drawing::Point(3, 129);
			this->burstTransmitCombo->Name = L"burstTransmitCombo";
			this->burstTransmitCombo->Size = System::Drawing::Size(86, 21);
			this->burstTransmitCombo->TabIndex = 29;
			this->burstTransmitCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::burstTransmitCombo_SelectedIndexChanged);
			// 
			// label28
			// 
			this->label28->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label28->AutoSize = true;
			this->label28->Location = System::Drawing::Point(96, 110);
			this->label28->Name = L"label28";
			this->label28->Size = System::Drawing::Size(47, 13);
			this->label28->TabIndex = 30;
			this->label28->Text = L"Burst Fix";
			// 
			// label29
			// 
			this->label29->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label29->AutoSize = true;
			this->label29->Location = System::Drawing::Point(96, 128);
			this->label29->Name = L"label29";
			this->label29->Size = System::Drawing::Size(74, 13);
			this->label29->TabIndex = 31;
			this->label29->Text = L"Burst Transmit";
			// 
			// gpsHotCombo
			// 
			this->gpsHotCombo->FormattingEnabled = true;
			this->gpsHotCombo->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Off", L"On"});
			this->gpsHotCombo->Location = System::Drawing::Point(3, 147);
			this->gpsHotCombo->Name = L"gpsHotCombo";
			this->gpsHotCombo->Size = System::Drawing::Size(86, 21);
			this->gpsHotCombo->TabIndex = 32;
			this->gpsHotCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::gpsHotCombo_SelectedIndexChanged);
			// 
			// label30
			// 
			this->label30->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label30->AutoSize = true;
			this->label30->Location = System::Drawing::Point(96, 146);
			this->label30->Name = L"label30";
			this->label30->Size = System::Drawing::Size(49, 13);
			this->label30->TabIndex = 33;
			this->label30->Text = L"GPS Hot";
			// 
			// activityStatusCombo
			// 
			this->activityStatusCombo->FormattingEnabled = true;
			this->activityStatusCombo->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"Off", L"Power", L"Bump", L"SOG", L"Bump+SOG"});
			this->activityStatusCombo->Location = System::Drawing::Point(3, 165);
			this->activityStatusCombo->Name = L"activityStatusCombo";
			this->activityStatusCombo->Size = System::Drawing::Size(86, 21);
			this->activityStatusCombo->TabIndex = 34;
			this->activityStatusCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::activityStatusCombo_SelectedIndexChanged);
			// 
			// trkCarrierCombo
			// 
			this->trkCarrierCombo->FormattingEnabled = true;
			this->trkCarrierCombo->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Iridium Only", L"Gprs Only", L"Prefer Gprs"});
			this->trkCarrierCombo->Location = System::Drawing::Point(3, 183);
			this->trkCarrierCombo->Name = L"trkCarrierCombo";
			this->trkCarrierCombo->Size = System::Drawing::Size(86, 21);
			this->trkCarrierCombo->TabIndex = 35;
			this->trkCarrierCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::trkCarrierCombo_SelectedIndexChanged);
			// 
			// activityLowCombo
			// 
			this->activityLowCombo->FormattingEnabled = true;
			this->activityLowCombo->Items->AddRange(gcnew cli::array< System::Object^  >(37) {L"18", L"19", L"20", L"21", L"22", L"23", 
				L"24", L"25", L"26", L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", 
				L"42", L"43", L"44", L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54"});
			this->activityLowCombo->Location = System::Drawing::Point(3, 201);
			this->activityLowCombo->Name = L"activityLowCombo";
			this->activityLowCombo->Size = System::Drawing::Size(86, 21);
			this->activityLowCombo->TabIndex = 36;
			this->activityLowCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::activityLowCombo_SelectedIndexChanged);
			// 
			// label31
			// 
			this->label31->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label31->AutoSize = true;
			this->label31->Location = System::Drawing::Point(96, 164);
			this->label31->Name = L"label31";
			this->label31->Size = System::Drawing::Size(74, 13);
			this->label31->TabIndex = 37;
			this->label31->Text = L"Activity Status";
			// 
			// label32
			// 
			this->label32->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label32->AutoSize = true;
			this->label32->Location = System::Drawing::Point(96, 182);
			this->label32->Name = L"label32";
			this->label32->Size = System::Drawing::Size(76, 13);
			this->label32->TabIndex = 38;
			this->label32->Text = L"GPRS Stategy";
			// 
			// label33
			// 
			this->label33->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label33->AutoSize = true;
			this->label33->Location = System::Drawing::Point(96, 200);
			this->label33->Name = L"label33";
			this->label33->Size = System::Drawing::Size(64, 13);
			this->label33->TabIndex = 39;
			this->label33->Text = L"Activity Low";
			// 
			// geofStatusCombo
			// 
			this->geofStatusCombo->FormattingEnabled = true;
			this->geofStatusCombo->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Off", L"Monofence", L"Polyfence"});
			this->geofStatusCombo->Location = System::Drawing::Point(3, 219);
			this->geofStatusCombo->Name = L"geofStatusCombo";
			this->geofStatusCombo->Size = System::Drawing::Size(86, 21);
			this->geofStatusCombo->TabIndex = 40;
			this->geofStatusCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::geofStatusCombo_SelectedIndexChanged);
			// 
			// geofPeriodCombo
			// 
			this->geofPeriodCombo->FormattingEnabled = true;
			this->geofPeriodCombo->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"1 min", L"2 min", L"3 min", L"5 min", L"10 min", 
				L"15 min", L"30 min"});
			this->geofPeriodCombo->Location = System::Drawing::Point(3, 237);
			this->geofPeriodCombo->Name = L"geofPeriodCombo";
			this->geofPeriodCombo->Size = System::Drawing::Size(86, 21);
			this->geofPeriodCombo->TabIndex = 41;
			this->geofPeriodCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::geofPeriodCombo_SelectedIndexChanged);
			// 
			// geofDistanceCombo
			// 
			this->geofDistanceCombo->FormattingEnabled = true;
			this->geofDistanceCombo->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"25m", L"50m", L"100m", L"250m", L"1000m", 
				L"2000m", L"3000m"});
			this->geofDistanceCombo->Location = System::Drawing::Point(3, 255);
			this->geofDistanceCombo->Name = L"geofDistanceCombo";
			this->geofDistanceCombo->Size = System::Drawing::Size(86, 21);
			this->geofDistanceCombo->TabIndex = 42;
			this->geofDistanceCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::geofDistanceCombo_SelectedIndexChanged);
			// 
			// label34
			// 
			this->label34->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label34->AutoSize = true;
			this->label34->Location = System::Drawing::Point(96, 218);
			this->label34->Name = L"label34";
			this->label34->Size = System::Drawing::Size(87, 13);
			this->label34->TabIndex = 43;
			this->label34->Text = L"Geofence Status";
			// 
			// label35
			// 
			this->label35->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label35->AutoSize = true;
			this->label35->Location = System::Drawing::Point(96, 236);
			this->label35->Name = L"label35";
			this->label35->Size = System::Drawing::Size(87, 13);
			this->label35->TabIndex = 44;
			this->label35->Text = L"Geofence Period";
			// 
			// label36
			// 
			this->label36->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label36->AutoSize = true;
			this->label36->Location = System::Drawing::Point(96, 254);
			this->label36->Name = L"label36";
			this->label36->Size = System::Drawing::Size(99, 13);
			this->label36->TabIndex = 45;
			this->label36->Text = L"Geofence Distance";
			// 
			// powerLimitCombo
			// 
			this->powerLimitCombo->FormattingEnabled = true;
			this->powerLimitCombo->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Unlimited", L"Limited", L"Unlimited - power control"});
			this->powerLimitCombo->Location = System::Drawing::Point(3, 273);
			this->powerLimitCombo->Name = L"powerLimitCombo";
			this->powerLimitCombo->Size = System::Drawing::Size(86, 21);
			this->powerLimitCombo->TabIndex = 46;
			this->powerLimitCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::powerLimitCombo_SelectedIndexChanged);
			// 
			// label37
			// 
			this->label37->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label37->AutoSize = true;
			this->label37->Location = System::Drawing::Point(96, 272);
			this->label37->Name = L"label37";
			this->label37->Size = System::Drawing::Size(61, 13);
			this->label37->TabIndex = 47;
			this->label37->Text = L"Power Limit";
			// 
			// notificationsCombo
			// 
			this->notificationsCombo->FormattingEnabled = true;
			this->notificationsCombo->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Off", L"Audible", L"Visual", L"Both"});
			this->notificationsCombo->Location = System::Drawing::Point(3, 291);
			this->notificationsCombo->Name = L"notificationsCombo";
			this->notificationsCombo->Size = System::Drawing::Size(86, 21);
			this->notificationsCombo->TabIndex = 48;
			this->notificationsCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::notificationsCombo_SelectedIndexChanged);
			// 
			// label38
			// 
			this->label38->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label38->AutoSize = true;
			this->label38->Location = System::Drawing::Point(96, 293);
			this->label38->Name = L"label38";
			this->label38->Size = System::Drawing::Size(65, 13);
			this->label38->TabIndex = 49;
			this->label38->Text = L"Notifications";
			// 
			// externalBaudCombo
			// 
			this->externalBaudCombo->FormattingEnabled = true;
			this->externalBaudCombo->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"4800", L"9600", L"19200", L"38400", L"57600", 
				L"115200"});
			this->externalBaudCombo->Location = System::Drawing::Point(3, 57);
			this->externalBaudCombo->Name = L"externalBaudCombo";
			this->externalBaudCombo->Size = System::Drawing::Size(86, 21);
			this->externalBaudCombo->TabIndex = 22;
			this->externalBaudCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::externalBaudCombo_SelectedIndexChanged);
			// 
			// externalSamplesCombo
			// 
			this->externalSamplesCombo->FormattingEnabled = true;
			this->externalSamplesCombo->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"5 secs", L"10 secs", L"20 secs", L"40 secs", 
				L"60 secs"});
			this->externalSamplesCombo->Location = System::Drawing::Point(3, 75);
			this->externalSamplesCombo->Name = L"externalSamplesCombo";
			this->externalSamplesCombo->Size = System::Drawing::Size(86, 21);
			this->externalSamplesCombo->TabIndex = 23;
			this->externalSamplesCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::externalSamplesCombo_SelectedIndexChanged);
			// 
			// externalTypeCombo
			// 
			this->externalTypeCombo->FormattingEnabled = true;
			this->externalTypeCombo->Items->AddRange(gcnew cli::array< System::Object^  >(9) {L"Off", L"Nmea", L"Hydrosphere", L"API", 
				L"Maximet", L"Fugro", L"Wave", L"Fastout", L"Dalia"});
			this->externalTypeCombo->Location = System::Drawing::Point(3, 39);
			this->externalTypeCombo->Name = L"externalTypeCombo";
			this->externalTypeCombo->Size = System::Drawing::Size(86, 21);
			this->externalTypeCombo->TabIndex = 21;
			this->externalTypeCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::externalTypeCombo_SelectedIndexChanged);
			// 
			// label14
			// 
			this->label14->Anchor = System::Windows::Forms::AnchorStyles::Left;
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(96, 38);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(45, 13);
			this->label14->TabIndex = 20;
			this->label14->Text = L"External";
			// 
			// extSensitivityCombo
			// 
			this->extSensitivityCombo->FormattingEnabled = true;
			this->extSensitivityCombo->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"FFFF", L"FFFS", L"FFSS", L"FSSS", L"SSSS"});
			this->extSensitivityCombo->Location = System::Drawing::Point(3, 309);
			this->extSensitivityCombo->Name = L"extSensitivityCombo";
			this->extSensitivityCombo->Size = System::Drawing::Size(86, 21);
			this->extSensitivityCombo->TabIndex = 60;
			this->extSensitivityCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::extSensitivityCombo_SelectedIndexChanged);
			// 
			// label26
			// 
			this->label26->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label26->AutoSize = true;
			this->label26->Location = System::Drawing::Point(96, 311);
			this->label26->Name = L"label26";
			this->label26->Size = System::Drawing::Size(72, 13);
			this->label26->TabIndex = 61;
			this->label26->Text = L"Ext Sensitivity";
			// 
			// label39
			// 
			this->label39->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label39->AutoSize = true;
			this->label39->Location = System::Drawing::Point(96, 329);
			this->label39->Name = L"label39";
			this->label39->Size = System::Drawing::Size(64, 13);
			this->label39->TabIndex = 62;
			this->label39->Text = L"Auto Tx Cell";
			// 
			// label47
			// 
			this->label47->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label47->AutoSize = true;
			this->label47->Location = System::Drawing::Point(96, 347);
			this->label47->Name = L"label47";
			this->label47->Size = System::Drawing::Size(66, 13);
			this->label47->TabIndex = 63;
			this->label47->Text = L"Burst Tx Cell";
			// 
			// label48
			// 
			this->label48->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label48->AutoSize = true;
			this->label48->Location = System::Drawing::Point(96, 365);
			this->label48->Name = L"label48";
			this->label48->Size = System::Drawing::Size(67, 13);
			this->label48->TabIndex = 64;
			this->label48->Text = L"Burst Fix Cell";
			// 
			// label49
			// 
			this->label49->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label49->AutoSize = true;
			this->label49->Location = System::Drawing::Point(96, 383);
			this->label49->Name = L"label49";
			this->label49->Size = System::Drawing::Size(84, 13);
			this->label49->TabIndex = 65;
			this->label49->Text = L"Auto Tx Distress";
			// 
			// label50
			// 
			this->label50->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label50->AutoSize = true;
			this->label50->Location = System::Drawing::Point(96, 401);
			this->label50->Name = L"label50";
			this->label50->Size = System::Drawing::Size(86, 13);
			this->label50->TabIndex = 66;
			this->label50->Text = L"Burst Tx Distress";
			// 
			// label53
			// 
			this->label53->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label53->AutoSize = true;
			this->label53->Location = System::Drawing::Point(96, 419);
			this->label53->Name = L"label53";
			this->label53->Size = System::Drawing::Size(87, 13);
			this->label53->TabIndex = 67;
			this->label53->Text = L"Burst Fix Distress";
			// 
			// autoTxCellCombo
			// 
			this->autoTxCellCombo->FormattingEnabled = true;
			this->autoTxCellCombo->Items->AddRange(gcnew cli::array< System::Object^  >(25) {L"Continuous", L"5 min", L"10 min", L"15 min", 
				L"20 min", L"30 min", L"1 hour", L"90 min", L"2 hour", L"3 hour", L"4 hour", L"6 hour", L"8 hour", L"12 hour", L"Burst", L"1 min", 
				L"2 min", L"3 min", L"4 min", L"24 hour", L"6 min", L"8 min", L"12 min", L"15 sec", L"30 sec"});
			this->autoTxCellCombo->Location = System::Drawing::Point(3, 327);
			this->autoTxCellCombo->Name = L"autoTxCellCombo";
			this->autoTxCellCombo->Size = System::Drawing::Size(86, 21);
			this->autoTxCellCombo->TabIndex = 68;
			this->autoTxCellCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::autoTxCellCombo_SelectedIndexChanged);
			// 
			// burstTxCellCombo
			// 
			this->burstTxCellCombo->FormattingEnabled = true;
			this->burstTxCellCombo->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"1 min", L"2 min", L"5 min", L"10 min", 
				L"15 min", L"30 min", L"60 min"});
			this->burstTxCellCombo->Location = System::Drawing::Point(3, 345);
			this->burstTxCellCombo->Name = L"burstTxCellCombo";
			this->burstTxCellCombo->Size = System::Drawing::Size(86, 21);
			this->burstTxCellCombo->TabIndex = 69;
			this->burstTxCellCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::burstTxCellCombo_SelectedIndexChanged);
			// 
			// burstFixCellCombo
			// 
			this->burstFixCellCombo->FormattingEnabled = true;
			this->burstFixCellCombo->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"5 secs", L"10 secs", L"15 secs", L"20 secs", 
				L"30 secs", L"1 min", L"2 min", L"5 min", L"10 min", L"15 min", L"20 min"});
			this->burstFixCellCombo->Location = System::Drawing::Point(3, 363);
			this->burstFixCellCombo->Name = L"burstFixCellCombo";
			this->burstFixCellCombo->Size = System::Drawing::Size(86, 21);
			this->burstFixCellCombo->TabIndex = 70;
			this->burstFixCellCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::burstFixCellCombo_SelectedIndexChanged);
			// 
			// autoTxDistressCombo
			// 
			this->autoTxDistressCombo->FormattingEnabled = true;
			this->autoTxDistressCombo->Items->AddRange(gcnew cli::array< System::Object^  >(25) {L"Continuous", L"5 min", L"10 min", L"15 min", 
				L"20 min", L"30 min", L"1 hour", L"90 min", L"2 hour", L"3 hour", L"4 hour", L"6 hour", L"8 hour", L"12 hour", L"Burst", L"1 min", 
				L"2 min", L"3 min", L"4 min", L"24 hour", L"6 min", L"8 min", L"12 min", L"15 sec", L"30 sec"});
			this->autoTxDistressCombo->Location = System::Drawing::Point(3, 381);
			this->autoTxDistressCombo->Name = L"autoTxDistressCombo";
			this->autoTxDistressCombo->Size = System::Drawing::Size(86, 21);
			this->autoTxDistressCombo->TabIndex = 71;
			this->autoTxDistressCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::autoTxDistressCombo_SelectedIndexChanged);
			// 
			// burstTxDistressCombo
			// 
			this->burstTxDistressCombo->FormattingEnabled = true;
			this->burstTxDistressCombo->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"1 min", L"2 min", L"5 min", L"10 min", 
				L"15 min", L"30 min", L"60 min"});
			this->burstTxDistressCombo->Location = System::Drawing::Point(3, 399);
			this->burstTxDistressCombo->Name = L"burstTxDistressCombo";
			this->burstTxDistressCombo->Size = System::Drawing::Size(86, 21);
			this->burstTxDistressCombo->TabIndex = 72;
			this->burstTxDistressCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::burstTxDistressCombo_SelectedIndexChanged);
			// 
			// burstFixDistressCombo
			// 
			this->burstFixDistressCombo->FormattingEnabled = true;
			this->burstFixDistressCombo->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"5 secs", L"10 secs", L"15 secs", 
				L"20 secs", L"30 secs", L"1 min", L"2 min", L"5 min", L"10 min", L"15 min", L"20 min"});
			this->burstFixDistressCombo->Location = System::Drawing::Point(3, 417);
			this->burstFixDistressCombo->Name = L"burstFixDistressCombo";
			this->burstFixDistressCombo->Size = System::Drawing::Size(86, 21);
			this->burstFixDistressCombo->TabIndex = 73;
			this->burstFixDistressCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::burstFixDistressCombo_SelectedIndexChanged);
			// 
			// positionBlockCombo
			// 
			this->positionBlockCombo->FormattingEnabled = true;
			this->positionBlockCombo->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Standard", L"10 Byte Compact"});
			this->positionBlockCombo->Location = System::Drawing::Point(3, 435);
			this->positionBlockCombo->Name = L"positionBlockCombo";
			this->positionBlockCombo->Size = System::Drawing::Size(86, 21);
			this->positionBlockCombo->TabIndex = 74;
			this->positionBlockCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::positionBlockCombo_SelectedIndexChanged);
			// 
			// label54
			// 
			this->label54->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label54->AutoSize = true;
			this->label54->Location = System::Drawing::Point(96, 437);
			this->label54->Name = L"label54";
			this->label54->Size = System::Drawing::Size(109, 13);
			this->label54->TabIndex = 75;
			this->label54->Text = L"Position Block Format";
			// 
			// gpxStatusCombo
			// 
			this->gpxStatusCombo->FormattingEnabled = true;
			this->gpxStatusCombo->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Off", L"On"});
			this->gpxStatusCombo->Location = System::Drawing::Point(3, 453);
			this->gpxStatusCombo->Name = L"gpxStatusCombo";
			this->gpxStatusCombo->Size = System::Drawing::Size(86, 21);
			this->gpxStatusCombo->TabIndex = 76;
			this->gpxStatusCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::gpxStatusCombo_SelectedIndexChanged);
			// 
			// label55
			// 
			this->label55->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label55->AutoSize = true;
			this->label55->Location = System::Drawing::Point(96, 455);
			this->label55->Name = L"label55";
			this->label55->Size = System::Drawing::Size(59, 13);
			this->label55->TabIndex = 77;
			this->label55->Text = L"Gpx Status";
			// 
			// gpxPeriodCombo
			// 
			this->gpxPeriodCombo->FormattingEnabled = true;
			this->gpxPeriodCombo->Items->AddRange(gcnew cli::array< System::Object^  >(11) {L"1 sec", L"5 sec", L"10 sec", L"30 sec", 
				L"1 min", L"5 min", L"10 min", L"15 min", L"20 min", L"30 min", L"60 min"});
			this->gpxPeriodCombo->Location = System::Drawing::Point(3, 471);
			this->gpxPeriodCombo->Name = L"gpxPeriodCombo";
			this->gpxPeriodCombo->Size = System::Drawing::Size(86, 21);
			this->gpxPeriodCombo->TabIndex = 78;
			this->gpxPeriodCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::gpsPeriodCombo_SelectedIndexChanged);
			// 
			// label56
			// 
			this->label56->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label56->AutoSize = true;
			this->label56->Location = System::Drawing::Point(96, 473);
			this->label56->Name = L"label56";
			this->label56->Size = System::Drawing::Size(59, 13);
			this->label56->TabIndex = 79;
			this->label56->Text = L"Gpx Period";
			// 
			// mailCheckStatusCombo
			// 
			this->mailCheckStatusCombo->FormattingEnabled = true;
			this->mailCheckStatusCombo->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Off", L"On"});
			this->mailCheckStatusCombo->Location = System::Drawing::Point(3, 489);
			this->mailCheckStatusCombo->Name = L"mailCheckStatusCombo";
			this->mailCheckStatusCombo->Size = System::Drawing::Size(86, 21);
			this->mailCheckStatusCombo->TabIndex = 80;
			this->mailCheckStatusCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::mailCheckStatusCombo_SelectedIndexChanged);
			// 
			// mailCheckPeriodCombo
			// 
			this->mailCheckPeriodCombo->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->mailCheckPeriodCombo->FormattingEnabled = true;
			this->mailCheckPeriodCombo->Items->AddRange(gcnew cli::array< System::Object^  >(13) {L"5 min", L"10 min", L"15 min", L"20 min", 
				L"30 min", L"1 hour", L"90 min", L"2 hour", L"3 hour", L"4 hour", L"6 hour", L"8 hour", L"12 hour"});
			this->mailCheckPeriodCombo->Location = System::Drawing::Point(3, 507);
			this->mailCheckPeriodCombo->Name = L"mailCheckPeriodCombo";
			this->mailCheckPeriodCombo->Size = System::Drawing::Size(86, 21);
			this->mailCheckPeriodCombo->TabIndex = 81;
			this->mailCheckPeriodCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::mailCheckPeriodCombo_SelectedIndexChanged);
			// 
			// label57
			// 
			this->label57->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label57->AutoSize = true;
			this->label57->Location = System::Drawing::Point(96, 491);
			this->label57->Name = L"label57";
			this->label57->Size = System::Drawing::Size(93, 13);
			this->label57->TabIndex = 82;
			this->label57->Text = L"Mail Check Status";
			// 
			// label58
			// 
			this->label58->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label58->AutoSize = true;
			this->label58->Location = System::Drawing::Point(96, 509);
			this->label58->Name = L"label58";
			this->label58->Size = System::Drawing::Size(93, 13);
			this->label58->TabIndex = 83;
			this->label58->Text = L"Mail Check Period";
			// 
			// gpsPlatformCombo
			// 
			this->gpsPlatformCombo->FormattingEnabled = true;
			this->gpsPlatformCombo->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Portable", L"Automotive", L"Marine", L"Air"});
			this->gpsPlatformCombo->Location = System::Drawing::Point(3, 57);
			this->gpsPlatformCombo->Name = L"gpsPlatformCombo";
			this->gpsPlatformCombo->Size = System::Drawing::Size(87, 21);
			this->gpsPlatformCombo->TabIndex = 84;
			this->gpsPlatformCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::gpsPlatformCombo_SelectedIndexChanged);
			// 
			// label59
			// 
			this->label59->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label59->AutoSize = true;
			this->label59->Location = System::Drawing::Point(98, 59);
			this->label59->Name = L"label59";
			this->label59->Size = System::Drawing::Size(70, 13);
			this->label59->TabIndex = 85;
			this->label59->Text = L"GPS Platform";
			// 
			// label60
			// 
			this->label60->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label60->AutoSize = true;
			this->label60->Location = System::Drawing::Point(98, 77);
			this->label60->Name = L"label60";
			this->label60->Size = System::Drawing::Size(73, 13);
			this->label60->TabIndex = 86;
			this->label60->Text = L"Air Alert Mode";
			// 
			// airAlertStatus
			// 
			this->airAlertStatus->FormattingEnabled = true;
			this->airAlertStatus->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"Off", L"Descent Only", L"Ascent Only", L"Both"});
			this->airAlertStatus->Location = System::Drawing::Point(3, 75);
			this->airAlertStatus->Name = L"airAlertStatus";
			this->airAlertStatus->Size = System::Drawing::Size(87, 21);
			this->airAlertStatus->TabIndex = 87;
			this->airAlertStatus->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::airAlertStatus_SelectedIndexChanged);
			// 
			// label61
			// 
			this->label61->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label61->AutoSize = true;
			this->label61->Location = System::Drawing::Point(98, 95);
			this->label61->Name = L"label61";
			this->label61->Size = System::Drawing::Size(114, 13);
			this->label61->TabIndex = 88;
			this->label61->Text = L"Air Alert Descnt Speed";
			// 
			// airAlertDescentSpeed
			// 
			this->airAlertDescentSpeed->FormattingEnabled = true;
			this->airAlertDescentSpeed->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"1000fpm", L"1500fpm", L"2000fpm", 
				L"2500fpm", L"3000fpm"});
			this->airAlertDescentSpeed->Location = System::Drawing::Point(3, 93);
			this->airAlertDescentSpeed->Name = L"airAlertDescentSpeed";
			this->airAlertDescentSpeed->Size = System::Drawing::Size(87, 21);
			this->airAlertDescentSpeed->TabIndex = 89;
			this->airAlertDescentSpeed->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::airAlertDescentSpeed_SelectedIndexChanged);
			// 
			// airAlertDescentTime
			// 
			this->airAlertDescentTime->FormattingEnabled = true;
			this->airAlertDescentTime->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"5 secs", L"10 secs", L"15 secs", L"20 secs", 
				L"25 secs", L"30 secs"});
			this->airAlertDescentTime->Location = System::Drawing::Point(3, 111);
			this->airAlertDescentTime->Name = L"airAlertDescentTime";
			this->airAlertDescentTime->Size = System::Drawing::Size(87, 21);
			this->airAlertDescentTime->TabIndex = 90;
			this->airAlertDescentTime->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::airAlertDescentTime_SelectedIndexChanged);
			// 
			// label62
			// 
			this->label62->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label62->AutoSize = true;
			this->label62->Location = System::Drawing::Point(98, 113);
			this->label62->Name = L"label62";
			this->label62->Size = System::Drawing::Size(106, 13);
			this->label62->TabIndex = 91;
			this->label62->Text = L"Air Alert Descnt Time";
			// 
			// airAlertAscentSpeed
			// 
			this->airAlertAscentSpeed->FormattingEnabled = true;
			this->airAlertAscentSpeed->Items->AddRange(gcnew cli::array< System::Object^  >(5) {L"1000fpm", L"1500fpm", L"2000fpm", L"2500fpm", 
				L"3000fpm"});
			this->airAlertAscentSpeed->Location = System::Drawing::Point(3, 129);
			this->airAlertAscentSpeed->Name = L"airAlertAscentSpeed";
			this->airAlertAscentSpeed->Size = System::Drawing::Size(87, 21);
			this->airAlertAscentSpeed->TabIndex = 92;
			this->airAlertAscentSpeed->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::airAlertAscentSpeed_SelectedIndexChanged);
			// 
			// airAlertAscentTime
			// 
			this->airAlertAscentTime->FormattingEnabled = true;
			this->airAlertAscentTime->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"5 secs", L"10 secs", L"15 secs", L"20 secs", 
				L"25 secs", L"30 secs"});
			this->airAlertAscentTime->Location = System::Drawing::Point(3, 147);
			this->airAlertAscentTime->Name = L"airAlertAscentTime";
			this->airAlertAscentTime->Size = System::Drawing::Size(87, 21);
			this->airAlertAscentTime->TabIndex = 93;
			this->airAlertAscentTime->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::airAlertAscentTime_SelectedIndexChanged);
			// 
			// label63
			// 
			this->label63->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label63->AutoSize = true;
			this->label63->Location = System::Drawing::Point(98, 131);
			this->label63->Name = L"label63";
			this->label63->Size = System::Drawing::Size(113, 13);
			this->label63->TabIndex = 94;
			this->label63->Text = L"Air Alert Ascent Speed";
			// 
			// label64
			// 
			this->label64->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label64->AutoSize = true;
			this->label64->Location = System::Drawing::Point(98, 149);
			this->label64->Name = L"label64";
			this->label64->Size = System::Drawing::Size(105, 13);
			this->label64->TabIndex = 95;
			this->label64->Text = L"Air Alert Ascent Time";
			// 
			// commandComboBox
			// 
			this->commandComboBox->FormattingEnabled = true;
			this->commandComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(17) {L"Send Alert", L"Send Manual", L"Install Updates", 
				L"Check Mail", L"Update Sent", L"Get LKP", L"Refresh Location", L"Get Battery", L"Deactivate", L"Activate", L"Buzz", L"Factory Reset", 
				L"Geofence Center", L"GPRS Refresh", L"Alert Cancel", L"Self Test Reset", L"Griffen Watch Toggle"});
			this->commandComboBox->Location = System::Drawing::Point(15, 36);
			this->commandComboBox->Name = L"commandComboBox";
			this->commandComboBox->Size = System::Drawing::Size(92, 21);
			this->commandComboBox->TabIndex = 46;
			this->commandComboBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::commandComboBox_SelectedIndexChanged);
			// 
			// Imei
			// 
			this->Imei->AutoSize = true;
			this->Imei->Location = System::Drawing::Point(6, 49);
			this->Imei->Name = L"Imei";
			this->Imei->Size = System::Drawing::Size(32, 13);
			this->Imei->TabIndex = 49;
			this->Imei->Text = L"Imei: ";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(6, 16);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(81, 13);
			this->label13->TabIndex = 51;
			this->label13->Text = L"Product Name: ";
			// 
			// serialText
			// 
			this->serialText->Location = System::Drawing::Point(6, 19);
			this->serialText->Name = L"serialText";
			this->serialText->Size = System::Drawing::Size(92, 20);
			this->serialText->TabIndex = 53;
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(98, 19);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(33, 13);
			this->label17->TabIndex = 54;
			this->label17->Text = L"Serial";
			// 
			// modelText
			// 
			this->modelText->Location = System::Drawing::Point(6, 40);
			this->modelText->Name = L"modelText";
			this->modelText->Size = System::Drawing::Size(92, 20);
			this->modelText->TabIndex = 55;
			// 
			// factorySetButton
			// 
			this->factorySetButton->Location = System::Drawing::Point(6, 102);
			this->factorySetButton->Name = L"factorySetButton";
			this->factorySetButton->Size = System::Drawing::Size(35, 21);
			this->factorySetButton->TabIndex = 57;
			this->factorySetButton->Text = L"Set";
			this->factorySetButton->UseVisualStyleBackColor = true;
			this->factorySetButton->Click += gcnew System::EventHandler(this, &Form1::factorySetButton_Click);
			// 
			// factoryGroup
			// 
			this->factoryGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->factoryGroup->Controls->Add(this->label52);
			this->factoryGroup->Controls->Add(this->rawCombo);
			this->factoryGroup->Controls->Add(this->label51);
			this->factoryGroup->Controls->Add(this->logoComboBox);
			this->factoryGroup->Controls->Add(this->label18);
			this->factoryGroup->Controls->Add(this->serialText);
			this->factoryGroup->Controls->Add(this->factorySetButton);
			this->factoryGroup->Controls->Add(this->label17);
			this->factoryGroup->Controls->Add(this->modelText);
			this->factoryGroup->Location = System::Drawing::Point(427, 194);
			this->factoryGroup->Name = L"factoryGroup";
			this->factoryGroup->Size = System::Drawing::Size(152, 134);
			this->factoryGroup->TabIndex = 58;
			this->factoryGroup->TabStop = false;
			this->factoryGroup->Text = L"Factory Setup";
			// 
			// label52
			// 
			this->label52->AutoSize = true;
			this->label52->Location = System::Drawing::Point(98, 57);
			this->label52->Name = L"label52";
			this->label52->Size = System::Drawing::Size(29, 13);
			this->label52->TabIndex = 64;
			this->label52->Text = L"Raw";
			// 
			// rawCombo
			// 
			this->rawCombo->FormattingEnabled = true;
			this->rawCombo->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Disable", L"Enable", L"Don\'t Set"});
			this->rawCombo->Location = System::Drawing::Point(6, 58);
			this->rawCombo->Name = L"rawCombo";
			this->rawCombo->Size = System::Drawing::Size(92, 21);
			this->rawCombo->TabIndex = 63;
			// 
			// label51
			// 
			this->label51->AutoSize = true;
			this->label51->Location = System::Drawing::Point(98, 79);
			this->label51->Name = L"label51";
			this->label51->Size = System::Drawing::Size(31, 13);
			this->label51->TabIndex = 61;
			this->label51->Text = L"Logo";
			// 
			// logoComboBox
			// 
			this->logoComboBox->FormattingEnabled = true;
			this->logoComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Factory Yellowbrick", L"Yellowbrick", L"Xmarx", 
				L"Rockstar", L"Rental", L"Iridium360", L"Don\'t Set"});
			this->logoComboBox->Location = System::Drawing::Point(6, 79);
			this->logoComboBox->Name = L"logoComboBox";
			this->logoComboBox->Size = System::Drawing::Size(92, 21);
			this->logoComboBox->TabIndex = 60;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(98, 42);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(36, 13);
			this->label18->TabIndex = 58;
			this->label18->Text = L"Model";
			// 
			// alertEnum
			// 
			this->alertEnum->FormattingEnabled = true;
			this->alertEnum->Items->AddRange(gcnew cli::array< System::Object^  >(16) {L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
				L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15"});
			this->alertEnum->Location = System::Drawing::Point(8, 26);
			this->alertEnum->Name = L"alertEnum";
			this->alertEnum->Size = System::Drawing::Size(91, 21);
			this->alertEnum->TabIndex = 60;
			this->alertEnum->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::alertEnum_SelectedIndexChanged);
			// 
			// powerLabel
			// 
			this->powerLabel->AutoSize = true;
			this->powerLabel->Location = System::Drawing::Point(83, 90);
			this->powerLabel->Name = L"powerLabel";
			this->powerLabel->Size = System::Drawing::Size(40, 13);
			this->powerLabel->TabIndex = 61;
			this->powerLabel->Text = L"Battery";
			// 
			// shippingLabel
			// 
			this->shippingLabel->AutoSize = true;
			this->shippingLabel->Location = System::Drawing::Point(83, 75);
			this->shippingLabel->Name = L"shippingLabel";
			this->shippingLabel->Size = System::Drawing::Size(21, 13);
			this->shippingLabel->TabIndex = 62;
			this->shippingLabel->Text = L"No";
			// 
			// productNameLabel
			// 
			this->productNameLabel->AutoSize = true;
			this->productNameLabel->Location = System::Drawing::Point(93, 16);
			this->productNameLabel->Name = L"productNameLabel";
			this->productNameLabel->Size = System::Drawing::Size(13, 13);
			this->productNameLabel->TabIndex = 63;
			this->productNameLabel->Text = L"\?";
			// 
			// versionLabel
			// 
			this->versionLabel->AutoSize = true;
			this->versionLabel->Location = System::Drawing::Point(93, 32);
			this->versionLabel->Name = L"versionLabel";
			this->versionLabel->Size = System::Drawing::Size(13, 13);
			this->versionLabel->TabIndex = 64;
			this->versionLabel->Text = L"\?";
			// 
			// imeiLabel
			// 
			this->imeiLabel->AutoSize = true;
			this->imeiLabel->Location = System::Drawing::Point(93, 49);
			this->imeiLabel->Name = L"imeiLabel";
			this->imeiLabel->Size = System::Drawing::Size(13, 13);
			this->imeiLabel->TabIndex = 65;
			this->imeiLabel->Text = L"\?";
			// 
			// batteryLabel
			// 
			this->batteryLabel->AutoSize = true;
			this->batteryLabel->Location = System::Drawing::Point(83, 16);
			this->batteryLabel->Name = L"batteryLabel";
			this->batteryLabel->Size = System::Drawing::Size(13, 13);
			this->batteryLabel->TabIndex = 66;
			this->batteryLabel->Text = L"\?";
			// 
			// locationLabel
			// 
			this->locationLabel->AutoSize = true;
			this->locationLabel->Location = System::Drawing::Point(83, 29);
			this->locationLabel->Name = L"locationLabel";
			this->locationLabel->Size = System::Drawing::Size(13, 13);
			this->locationLabel->TabIndex = 67;
			this->locationLabel->Text = L"\?";
			// 
			// trackerDetailsGroup
			// 
			this->trackerDetailsGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->trackerDetailsGroup->Controls->Add(this->rawLabel);
			this->trackerDetailsGroup->Controls->Add(this->label27);
			this->trackerDetailsGroup->Controls->Add(this->bleVersionLabel);
			this->trackerDetailsGroup->Controls->Add(this->label25);
			this->trackerDetailsGroup->Controls->Add(this->label13);
			this->trackerDetailsGroup->Controls->Add(this->label11);
			this->trackerDetailsGroup->Controls->Add(this->Imei);
			this->trackerDetailsGroup->Controls->Add(this->imeiLabel);
			this->trackerDetailsGroup->Controls->Add(this->productNameLabel);
			this->trackerDetailsGroup->Controls->Add(this->versionLabel);
			this->trackerDetailsGroup->Location = System::Drawing::Point(607, 12);
			this->trackerDetailsGroup->Name = L"trackerDetailsGroup";
			this->trackerDetailsGroup->Size = System::Drawing::Size(227, 112);
			this->trackerDetailsGroup->TabIndex = 68;
			this->trackerDetailsGroup->TabStop = false;
			this->trackerDetailsGroup->Text = L"Tracker Details";
			// 
			// rawLabel
			// 
			this->rawLabel->AutoSize = true;
			this->rawLabel->Location = System::Drawing::Point(93, 95);
			this->rawLabel->Name = L"rawLabel";
			this->rawLabel->Size = System::Drawing::Size(13, 13);
			this->rawLabel->TabIndex = 69;
			this->rawLabel->Text = L"\?";
			// 
			// label27
			// 
			this->label27->AutoSize = true;
			this->label27->Location = System::Drawing::Point(6, 95);
			this->label27->Name = L"label27";
			this->label27->Size = System::Drawing::Size(55, 13);
			this->label27->TabIndex = 68;
			this->label27->Text = L"Raw Flag:";
			// 
			// bleVersionLabel
			// 
			this->bleVersionLabel->AutoSize = true;
			this->bleVersionLabel->Location = System::Drawing::Point(93, 71);
			this->bleVersionLabel->Name = L"bleVersionLabel";
			this->bleVersionLabel->Size = System::Drawing::Size(13, 13);
			this->bleVersionLabel->TabIndex = 67;
			this->bleVersionLabel->Text = L"\?";
			// 
			// label25
			// 
			this->label25->AutoSize = true;
			this->label25->Location = System::Drawing::Point(6, 74);
			this->label25->Name = L"label25";
			this->label25->Size = System::Drawing::Size(63, 13);
			this->label25->TabIndex = 66;
			this->label25->Text = L"Ble Version:";
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(6, 29);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(54, 13);
			this->label20->TabIndex = 69;
			this->label20->Text = L"Location: ";
			// 
			// trackerStatusGroup
			// 
			this->trackerStatusGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->trackerStatusGroup->Controls->Add(this->selfTestResult);
			this->trackerStatusGroup->Controls->Add(this->label70);
			this->trackerStatusGroup->Controls->Add(this->WatchStatusLabel);
			this->trackerStatusGroup->Controls->Add(this->TxContextLabel);
			this->trackerStatusGroup->Controls->Add(this->label68);
			this->trackerStatusGroup->Controls->Add(this->label12);
			this->trackerStatusGroup->Controls->Add(this->locationLabel2);
			this->trackerStatusGroup->Controls->Add(this->selfTest);
			this->trackerStatusGroup->Controls->Add(this->label42);
			this->trackerStatusGroup->Controls->Add(this->gprsStatus);
			this->trackerStatusGroup->Controls->Add(this->gprsSignal);
			this->trackerStatusGroup->Controls->Add(this->gprsLocation);
			this->trackerStatusGroup->Controls->Add(this->label46);
			this->trackerStatusGroup->Controls->Add(this->gprsMsisdn);
			this->trackerStatusGroup->Controls->Add(this->label45);
			this->trackerStatusGroup->Controls->Add(this->label44);
			this->trackerStatusGroup->Controls->Add(this->label43);
			this->trackerStatusGroup->Controls->Add(this->gprsSim);
			this->trackerStatusGroup->Controls->Add(this->label41);
			this->trackerStatusGroup->Controls->Add(this->gprsLabel);
			this->trackerStatusGroup->Controls->Add(this->label40);
			this->trackerStatusGroup->Controls->Add(this->label24);
			this->trackerStatusGroup->Controls->Add(this->label23);
			this->trackerStatusGroup->Controls->Add(this->label22);
			this->trackerStatusGroup->Controls->Add(this->label21);
			this->trackerStatusGroup->Controls->Add(this->label20);
			this->trackerStatusGroup->Controls->Add(this->gpsLabel);
			this->trackerStatusGroup->Controls->Add(this->iridiumLabel);
			this->trackerStatusGroup->Controls->Add(this->locationLabel);
			this->trackerStatusGroup->Controls->Add(this->label10);
			this->trackerStatusGroup->Controls->Add(this->batteryLabel);
			this->trackerStatusGroup->Controls->Add(this->powerLabel);
			this->trackerStatusGroup->Controls->Add(this->shippingLabel);
			this->trackerStatusGroup->Location = System::Drawing::Point(607, 129);
			this->trackerStatusGroup->Name = L"trackerStatusGroup";
			this->trackerStatusGroup->Size = System::Drawing::Size(227, 330);
			this->trackerStatusGroup->TabIndex = 70;
			this->trackerStatusGroup->TabStop = false;
			this->trackerStatusGroup->Text = L"Status";
			// 
			// selfTestResult
			// 
			this->selfTestResult->AutoSize = true;
			this->selfTestResult->Location = System::Drawing::Point(83, 311);
			this->selfTestResult->Name = L"selfTestResult";
			this->selfTestResult->Size = System::Drawing::Size(13, 13);
			this->selfTestResult->TabIndex = 94;
			this->selfTestResult->Text = L"\?";
			// 
			// label70
			// 
			this->label70->AutoSize = true;
			this->label70->Location = System::Drawing::Point(6, 311);
			this->label70->Name = L"label70";
			this->label70->Size = System::Drawing::Size(49, 13);
			this->label70->TabIndex = 93;
			this->label70->Text = L"Self Test";
			// 
			// WatchStatusLabel
			// 
			this->WatchStatusLabel->AutoSize = true;
			this->WatchStatusLabel->Location = System::Drawing::Point(83, 293);
			this->WatchStatusLabel->Name = L"WatchStatusLabel";
			this->WatchStatusLabel->Size = System::Drawing::Size(13, 13);
			this->WatchStatusLabel->TabIndex = 92;
			this->WatchStatusLabel->Text = L"\?";
			// 
			// TxContextLabel
			// 
			this->TxContextLabel->AutoSize = true;
			this->TxContextLabel->Location = System::Drawing::Point(83, 275);
			this->TxContextLabel->Name = L"TxContextLabel";
			this->TxContextLabel->Size = System::Drawing::Size(13, 13);
			this->TxContextLabel->TabIndex = 91;
			this->TxContextLabel->Text = L"\?";
			// 
			// label68
			// 
			this->label68->AutoSize = true;
			this->label68->Location = System::Drawing::Point(7, 293);
			this->label68->Name = L"label68";
			this->label68->Size = System::Drawing::Size(72, 13);
			this->label68->TabIndex = 90;
			this->label68->Text = L"Watch Status";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 276);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(60, 13);
			this->label12->TabIndex = 89;
			this->label12->Text = L"TX Context";
			// 
			// locationLabel2
			// 
			this->locationLabel2->AutoSize = true;
			this->locationLabel2->Location = System::Drawing::Point(83, 43);
			this->locationLabel2->Name = L"locationLabel2";
			this->locationLabel2->Size = System::Drawing::Size(13, 13);
			this->locationLabel2->TabIndex = 88;
			this->locationLabel2->Text = L"\?";
			// 
			// selfTest
			// 
			this->selfTest->AutoSize = true;
			this->selfTest->Location = System::Drawing::Point(83, 256);
			this->selfTest->Name = L"selfTest";
			this->selfTest->Size = System::Drawing::Size(13, 13);
			this->selfTest->TabIndex = 87;
			this->selfTest->Text = L"\?";
			// 
			// label42
			// 
			this->label42->AutoSize = true;
			this->label42->Location = System::Drawing::Point(6, 256);
			this->label42->Name = L"label42";
			this->label42->Size = System::Drawing::Size(49, 13);
			this->label42->TabIndex = 86;
			this->label42->Text = L"Self Test";
			// 
			// gprsStatus
			// 
			this->gprsStatus->AutoSize = true;
			this->gprsStatus->Location = System::Drawing::Point(83, 233);
			this->gprsStatus->Name = L"gprsStatus";
			this->gprsStatus->Size = System::Drawing::Size(13, 13);
			this->gprsStatus->TabIndex = 85;
			this->gprsStatus->Text = L"\?";
			// 
			// gprsSignal
			// 
			this->gprsSignal->AutoSize = true;
			this->gprsSignal->Location = System::Drawing::Point(83, 221);
			this->gprsSignal->Name = L"gprsSignal";
			this->gprsSignal->Size = System::Drawing::Size(13, 13);
			this->gprsSignal->TabIndex = 84;
			this->gprsSignal->Text = L"\?";
			// 
			// gprsLocation
			// 
			this->gprsLocation->AutoSize = true;
			this->gprsLocation->Location = System::Drawing::Point(83, 208);
			this->gprsLocation->Name = L"gprsLocation";
			this->gprsLocation->Size = System::Drawing::Size(13, 13);
			this->gprsLocation->TabIndex = 83;
			this->gprsLocation->Text = L"\?";
			// 
			// label46
			// 
			this->label46->AutoSize = true;
			this->label46->Location = System::Drawing::Point(6, 191);
			this->label46->Name = L"label46";
			this->label46->Size = System::Drawing::Size(60, 13);
			this->label46->TabIndex = 82;
			this->label46->Text = L"GPRS Sim:";
			// 
			// gprsMsisdn
			// 
			this->gprsMsisdn->AutoSize = true;
			this->gprsMsisdn->Location = System::Drawing::Point(83, 178);
			this->gprsMsisdn->Name = L"gprsMsisdn";
			this->gprsMsisdn->Size = System::Drawing::Size(13, 13);
			this->gprsMsisdn->TabIndex = 81;
			this->gprsMsisdn->Text = L"\?";
			// 
			// label45
			// 
			this->label45->AutoSize = true;
			this->label45->Location = System::Drawing::Point(6, 234);
			this->label45->Name = L"label45";
			this->label45->Size = System::Drawing::Size(73, 13);
			this->label45->TabIndex = 80;
			this->label45->Text = L"GPRS Status:";
			// 
			// label44
			// 
			this->label44->AutoSize = true;
			this->label44->Location = System::Drawing::Point(6, 221);
			this->label44->Name = L"label44";
			this->label44->Size = System::Drawing::Size(72, 13);
			this->label44->TabIndex = 79;
			this->label44->Text = L"GPRS Signal:";
			// 
			// label43
			// 
			this->label43->AutoSize = true;
			this->label43->Location = System::Drawing::Point(6, 208);
			this->label43->Name = L"label43";
			this->label43->Size = System::Drawing::Size(84, 13);
			this->label43->TabIndex = 78;
			this->label43->Text = L"GPRS Location:";
			// 
			// gprsSim
			// 
			this->gprsSim->AutoSize = true;
			this->gprsSim->Location = System::Drawing::Point(83, 191);
			this->gprsSim->Name = L"gprsSim";
			this->gprsSim->Size = System::Drawing::Size(13, 13);
			this->gprsSim->TabIndex = 77;
			this->gprsSim->Text = L"\?";
			// 
			// label41
			// 
			this->label41->AutoSize = true;
			this->label41->Location = System::Drawing::Point(6, 178);
			this->label41->Name = L"label41";
			this->label41->Size = System::Drawing::Size(76, 13);
			this->label41->TabIndex = 76;
			this->label41->Text = L"GPRS Msisdn:";
			// 
			// gprsLabel
			// 
			this->gprsLabel->AutoSize = true;
			this->gprsLabel->Location = System::Drawing::Point(83, 151);
			this->gprsLabel->Name = L"gprsLabel";
			this->gprsLabel->Size = System::Drawing::Size(21, 13);
			this->gprsLabel->TabIndex = 75;
			this->gprsLabel->Text = L"No";
			// 
			// label40
			// 
			this->label40->AutoSize = true;
			this->label40->Location = System::Drawing::Point(6, 151);
			this->label40->Name = L"label40";
			this->label40->Size = System::Drawing::Size(71, 13);
			this->label40->TabIndex = 74;
			this->label40->Text = L"GPRS Board:";
			// 
			// label24
			// 
			this->label24->AutoSize = true;
			this->label24->Location = System::Drawing::Point(6, 131);
			this->label24->Name = L"label24";
			this->label24->Size = System::Drawing::Size(43, 13);
			this->label24->TabIndex = 73;
			this->label24->Text = L"Iridium: ";
			// 
			// label23
			// 
			this->label23->AutoSize = true;
			this->label23->Location = System::Drawing::Point(6, 115);
			this->label23->Name = L"label23";
			this->label23->Size = System::Drawing::Size(35, 13);
			this->label23->TabIndex = 72;
			this->label23->Text = L"GPS: ";
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(6, 90);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(43, 13);
			this->label22->TabIndex = 71;
			this->label22->Text = L"Power: ";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(6, 75);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(54, 13);
			this->label21->TabIndex = 70;
			this->label21->Text = L"Shipping: ";
			// 
			// alertPositionCheck
			// 
			this->alertPositionCheck->AutoSize = true;
			this->alertPositionCheck->Location = System::Drawing::Point(8, 53);
			this->alertPositionCheck->Name = L"alertPositionCheck";
			this->alertPositionCheck->Size = System::Drawing::Size(88, 17);
			this->alertPositionCheck->TabIndex = 71;
			this->alertPositionCheck->Text = L"With Position";
			this->alertPositionCheck->UseVisualStyleBackColor = true;
			// 
			// testEventTimer
			// 
			this->testEventTimer->Tick += gcnew System::EventHandler(this, &Form1::testEventTimer_Tick);
			// 
			// nmeaGrabButton
			// 
			this->nmeaGrabButton->Location = System::Drawing::Point(9, 77);
			this->nmeaGrabButton->Name = L"nmeaGrabButton";
			this->nmeaGrabButton->Size = System::Drawing::Size(73, 19);
			this->nmeaGrabButton->TabIndex = 74;
			this->nmeaGrabButton->Text = L" Grab";
			this->nmeaGrabButton->UseVisualStyleBackColor = true;
			this->nmeaGrabButton->Click += gcnew System::EventHandler(this, &Form1::nmeaGrabButton_Click);
			// 
			// nmeaGrabText
			// 
			this->nmeaGrabText->Location = System::Drawing::Point(6, 16);
			this->nmeaGrabText->Multiline = true;
			this->nmeaGrabText->Name = L"nmeaGrabText";
			this->nmeaGrabText->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->nmeaGrabText->Size = System::Drawing::Size(164, 57);
			this->nmeaGrabText->TabIndex = 75;
			// 
			// nmeaGroup
			// 
			this->nmeaGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->nmeaGroup->Controls->Add(this->nmeaGrabText);
			this->nmeaGroup->Controls->Add(this->nmeaGrabButton);
			this->nmeaGroup->Location = System::Drawing::Point(226, 450);
			this->nmeaGroup->Name = L"nmeaGroup";
			this->nmeaGroup->Size = System::Drawing::Size(178, 104);
			this->nmeaGroup->TabIndex = 76;
			this->nmeaGroup->TabStop = false;
			this->nmeaGroup->Text = L"Nmea Spy";
			// 
			// generalCommandGroup
			// 
			this->generalCommandGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->generalCommandGroup->Controls->Add(this->commandComboBox);
			this->generalCommandGroup->Location = System::Drawing::Point(427, 12);
			this->generalCommandGroup->Name = L"generalCommandGroup";
			this->generalCommandGroup->Size = System::Drawing::Size(152, 70);
			this->generalCommandGroup->TabIndex = 77;
			this->generalCommandGroup->TabStop = false;
			this->generalCommandGroup->Text = L"Protocol Actions";
			// 
			// statusGroup
			// 
			this->statusGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->statusGroup->Controls->Add(this->getStatusCombo);
			this->statusGroup->Controls->Add(this->getStatusTextBox);
			this->statusGroup->Location = System::Drawing::Point(427, 345);
			this->statusGroup->Name = L"statusGroup";
			this->statusGroup->Size = System::Drawing::Size(152, 79);
			this->statusGroup->TabIndex = 80;
			this->statusGroup->TabStop = false;
			this->statusGroup->Text = L"Get Status";
			// 
			// getStatusCombo
			// 
			this->getStatusCombo->FormattingEnabled = true;
			this->getStatusCombo->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Logo", L"Spare"});
			this->getStatusCombo->Location = System::Drawing::Point(6, 23);
			this->getStatusCombo->Name = L"getStatusCombo";
			this->getStatusCombo->Size = System::Drawing::Size(96, 21);
			this->getStatusCombo->TabIndex = 78;
			this->getStatusCombo->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::getStatusCombo_SelectedIndexChanged);
			// 
			// getStatusTextBox
			// 
			this->getStatusTextBox->Location = System::Drawing::Point(6, 50);
			this->getStatusTextBox->Name = L"getStatusTextBox";
			this->getStatusTextBox->Size = System::Drawing::Size(96, 20);
			this->getStatusTextBox->TabIndex = 79;
			// 
			// genericAlertGroup
			// 
			this->genericAlertGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->genericAlertGroup->Controls->Add(this->alertEnum);
			this->genericAlertGroup->Controls->Add(this->alertPositionCheck);
			this->genericAlertGroup->Location = System::Drawing::Point(427, 95);
			this->genericAlertGroup->Name = L"genericAlertGroup";
			this->genericAlertGroup->Size = System::Drawing::Size(152, 79);
			this->genericAlertGroup->TabIndex = 77;
			this->genericAlertGroup->TabStop = false;
			this->genericAlertGroup->Text = L"Generic Alert";
			// 
			// gprsConfigurationGroup
			// 
			this->gprsConfigurationGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->gprsConfigurationGroup->Controls->Add(this->gprsSetText);
			this->gprsConfigurationGroup->Controls->Add(this->gprsSettings);
			this->gprsConfigurationGroup->Controls->Add(this->gprsSetButton);
			this->gprsConfigurationGroup->Controls->Add(this->gprsGetButton);
			this->gprsConfigurationGroup->Location = System::Drawing::Point(427, 446);
			this->gprsConfigurationGroup->Name = L"gprsConfigurationGroup";
			this->gprsConfigurationGroup->Size = System::Drawing::Size(152, 108);
			this->gprsConfigurationGroup->TabIndex = 78;
			this->gprsConfigurationGroup->TabStop = false;
			this->gprsConfigurationGroup->Text = L"GPRS Configuration";
			// 
			// gprsSetText
			// 
			this->gprsSetText->Location = System::Drawing::Point(6, 46);
			this->gprsSetText->Name = L"gprsSetText";
			this->gprsSetText->Size = System::Drawing::Size(112, 20);
			this->gprsSetText->TabIndex = 29;
			// 
			// gprsSettings
			// 
			this->gprsSettings->FormattingEnabled = true;
			this->gprsSettings->Items->AddRange(gcnew cli::array< System::Object^  >(8) {L"Remote Host 1", L"Remote Host 2", L"Remote Host 3", 
				L"Host Port 1", L"Host Port 2", L"Host Port 3", L"Username", L"Password"});
			this->gprsSettings->Location = System::Drawing::Point(6, 19);
			this->gprsSettings->Name = L"gprsSettings";
			this->gprsSettings->Size = System::Drawing::Size(116, 21);
			this->gprsSettings->TabIndex = 28;
			// 
			// gprsSetButton
			// 
			this->gprsSetButton->Location = System::Drawing::Point(52, 73);
			this->gprsSetButton->Name = L"gprsSetButton";
			this->gprsSetButton->Size = System::Drawing::Size(35, 19);
			this->gprsSetButton->TabIndex = 27;
			this->gprsSetButton->Text = L"Set";
			this->gprsSetButton->UseVisualStyleBackColor = true;
			this->gprsSetButton->Click += gcnew System::EventHandler(this, &Form1::gprsSetButton_Click);
			// 
			// gprsGetButton
			// 
			this->gprsGetButton->Location = System::Drawing::Point(6, 73);
			this->gprsGetButton->Name = L"gprsGetButton";
			this->gprsGetButton->Size = System::Drawing::Size(35, 19);
			this->gprsGetButton->TabIndex = 26;
			this->gprsGetButton->Text = L"Get";
			this->gprsGetButton->UseVisualStyleBackColor = true;
			this->gprsGetButton->Click += gcnew System::EventHandler(this, &Form1::gprsGetButton_Click);
			// 
			// configureName
			// 
			this->configureName->FormattingEnabled = true;
			this->configureName->Items->AddRange(gcnew cli::array< System::Object^  >(81) {L"Name", L"Appearance", L"Serial number", L"Sw version", 
				L"Gps status", L"Iridium status", L"Tracking period", L"Gps early wakeup time", L"Burst tx period cell", L"Tracking onoff", L"Pin lock", 
				L"Burst fix", L"Serial cts", L"Burst transmit", L"Serial rts", L"Gps hot", L"Mail check period", L"Mail check status", L"Gps fix quality", 
				L"Gps sequential fixes", L"Activity status", L"Gprs strategy", L"Activity low", L"Tracking report", L"Imei", L"Serial rx", L"Serial tx", 
				L"Message count", L"Outbox status", L"Battery", L"Temperature alert status", L"Temperature alert high threshold", L"Temperature alert low threshold", 
				L"Temperature alert check period", L"Burst tx period distress", L"Power loss alert status", L"Power limit", L"Geof status", L"Geof distance", 
				L"Geof period", L"Notifications", L"Collision status", L"Collision threshold", L"Collision duration", L"Ext type", L"Ext samples", 
				L"Ext baud", L"Gpx period", L"Gpx status", L"Burst fix period cell", L"Android", L"Raw", L"Mob", L"Power", L"Burst fix period distress", 
				L"D boards", L"Ble version", L"Gprs signal", L"Gprs status", L"Gprs msisdn", L"Gprs sim", L"Gprs location", L"Ext sense", L"Tracking period cell", 
				L"Tracking period distress", L"Position block format", L"Self test", L"Spare 1", L"Air alert status", L"Air alert ascent speed", 
				L"Air alert descent speed", L"Air alert ascent time", L"Air alert descent time", L"Gps platform", L"Logging", L"Auto Resume Status", 
				L"Auto Resume Distance", L"Flight Alert Status", L"Flight Vr", L"Flight Vs", L"Battery Model"});
			this->configureName->Location = System::Drawing::Point(10, 19);
			this->configureName->Name = L"configureName";
			this->configureName->Size = System::Drawing::Size(133, 21);
			this->configureName->TabIndex = 79;
			// 
			// configureValue
			// 
			this->configureValue->FormattingEnabled = true;
			this->configureValue->Items->AddRange(gcnew cli::array< System::Object^  >(30) {L"0", L"1", L"2", L"3", L"4", L"5", L"6", 
				L"7", L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"23", L"24", L"25", L"26", 
				L"27", L"28", L"29", L"30"});
			this->configureValue->Location = System::Drawing::Point(10, 46);
			this->configureValue->Name = L"configureValue";
			this->configureValue->Size = System::Drawing::Size(50, 21);
			this->configureValue->TabIndex = 80;
			// 
			// configureGroup
			// 
			this->configureGroup->BackColor = System::Drawing::SystemColors::ControlDark;
			this->configureGroup->Controls->Add(this->configureGetButton);
			this->configureGroup->Controls->Add(this->configureButton);
			this->configureGroup->Controls->Add(this->configureName);
			this->configureGroup->Controls->Add(this->configureValue);
			this->configureGroup->Location = System::Drawing::Point(607, 465);
			this->configureGroup->Name = L"configureGroup";
			this->configureGroup->Size = System::Drawing::Size(227, 89);
			this->configureGroup->TabIndex = 81;
			this->configureGroup->TabStop = false;
			this->configureGroup->Text = L"Configure";
			// 
			// configureGetButton
			// 
			this->configureGetButton->Location = System::Drawing::Point(109, 48);
			this->configureGetButton->Name = L"configureGetButton";
			this->configureGetButton->Size = System::Drawing::Size(34, 19);
			this->configureGetButton->TabIndex = 82;
			this->configureGetButton->Text = L"Get";
			this->configureGetButton->UseVisualStyleBackColor = true;
			this->configureGetButton->Click += gcnew System::EventHandler(this, &Form1::configureGetButton_Click);
			// 
			// configureButton
			// 
			this->configureButton->Location = System::Drawing::Point(64, 48);
			this->configureButton->Name = L"configureButton";
			this->configureButton->Size = System::Drawing::Size(34, 19);
			this->configureButton->TabIndex = 81;
			this->configureButton->Text = L"Set";
			this->configureButton->UseVisualStyleBackColor = true;
			this->configureButton->Click += gcnew System::EventHandler(this, &Form1::configureButton_Click);
			// 
			// settingsTableExtended
			// 
			this->settingsTableExtended->BackColor = System::Drawing::SystemColors::ControlDark;
			this->settingsTableExtended->ColumnCount = 2;
			this->settingsTableExtended->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				44.44444F)));
			this->settingsTableExtended->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 
				55.55556F)));
			this->settingsTableExtended->Controls->Add(this->flightMode, 0, 0);
			this->settingsTableExtended->Controls->Add(this->flightVr, 0, 1);
			this->settingsTableExtended->Controls->Add(this->flightVs, 0, 2);
			this->settingsTableExtended->Controls->Add(this->label65, 1, 0);
			this->settingsTableExtended->Controls->Add(this->label66, 1, 1);
			this->settingsTableExtended->Controls->Add(this->label67, 1, 2);
			this->settingsTableExtended->Controls->Add(this->gpsPlatformCombo, 0, 3);
			this->settingsTableExtended->Controls->Add(this->label59, 1, 3);
			this->settingsTableExtended->Controls->Add(this->airAlertStatus, 0, 4);
			this->settingsTableExtended->Controls->Add(this->label60, 1, 4);
			this->settingsTableExtended->Controls->Add(this->airAlertDescentSpeed, 0, 5);
			this->settingsTableExtended->Controls->Add(this->label61, 1, 5);
			this->settingsTableExtended->Controls->Add(this->airAlertDescentTime, 0, 6);
			this->settingsTableExtended->Controls->Add(this->label62, 1, 6);
			this->settingsTableExtended->Controls->Add(this->airAlertAscentSpeed, 0, 7);
			this->settingsTableExtended->Controls->Add(this->label63, 1, 7);
			this->settingsTableExtended->Controls->Add(this->airAlertAscentTime, 0, 8);
			this->settingsTableExtended->Controls->Add(this->label64, 1, 8);
			this->settingsTableExtended->Controls->Add(this->extButtons, 0, 9);
			this->settingsTableExtended->Controls->Add(this->label69, 1, 9);
			this->settingsTableExtended->Location = System::Drawing::Point(1066, 13);
			this->settingsTableExtended->Name = L"settingsTableExtended";
			this->settingsTableExtended->RowCount = 10;
			this->settingsTableExtended->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				18)));
			this->settingsTableExtended->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				18)));
			this->settingsTableExtended->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				18)));
			this->settingsTableExtended->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				18)));
			this->settingsTableExtended->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				18)));
			this->settingsTableExtended->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				18)));
			this->settingsTableExtended->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				18)));
			this->settingsTableExtended->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				18)));
			this->settingsTableExtended->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				18)));
			this->settingsTableExtended->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Absolute, 
				18)));
			this->settingsTableExtended->Size = System::Drawing::Size(216, 210);
			this->settingsTableExtended->TabIndex = 82;
			// 
			// flightMode
			// 
			this->flightMode->FormattingEnabled = true;
			this->flightMode->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Off", L"Hover", L"Fixed Wing"});
			this->flightMode->Location = System::Drawing::Point(3, 3);
			this->flightMode->Name = L"flightMode";
			this->flightMode->Size = System::Drawing::Size(86, 21);
			this->flightMode->TabIndex = 0;
			this->flightMode->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::flightMode_SelectedIndexChanged);
			// 
			// flightVr
			// 
			this->flightVr->FormattingEnabled = true;
			this->flightVr->Items->AddRange(gcnew cli::array< System::Object^  >(128) {L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
				L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26", 
				L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43", L"44", 
				L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59", L"60", L"61", L"62", 
				L"63", L"64", L"65", L"66", L"67", L"68", L"69", L"70", L"71", L"72", L"73", L"74", L"75", L"76", L"77", L"78", L"79", L"80", 
				L"81", L"82", L"83", L"84", L"85", L"86", L"87", L"88", L"89", L"90", L"91", L"92", L"93", L"94", L"95", L"96", L"97", L"98", 
				L"99", L"100", L"101", L"102", L"103", L"104", L"105", L"106", L"107", L"108", L"109", L"110", L"111", L"112", L"113", L"114", 
				L"115", L"116", L"117", L"118", L"119", L"120", L"121", L"122", L"123", L"124", L"125", L"126", L"127"});
			this->flightVr->Location = System::Drawing::Point(3, 21);
			this->flightVr->Name = L"flightVr";
			this->flightVr->Size = System::Drawing::Size(86, 21);
			this->flightVr->TabIndex = 1;
			this->flightVr->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::flightVr_SelectedIndexChanged);
			// 
			// flightVs
			// 
			this->flightVs->FormattingEnabled = true;
			this->flightVs->Items->AddRange(gcnew cli::array< System::Object^  >(64) {L"0", L"1", L"2", L"3", L"4", L"5", L"6", L"7", 
				L"8", L"9", L"10", L"11", L"12", L"13", L"14", L"15", L"16", L"17", L"18", L"19", L"20", L"21", L"22", L"23", L"24", L"25", L"26", 
				L"27", L"28", L"29", L"30", L"31", L"32", L"33", L"34", L"35", L"36", L"37", L"38", L"39", L"40", L"41", L"42", L"43", L"44", 
				L"45", L"46", L"47", L"48", L"49", L"50", L"51", L"52", L"53", L"54", L"55", L"56", L"57", L"58", L"59", L"60", L"61", L"62", 
				L"63"});
			this->flightVs->Location = System::Drawing::Point(3, 39);
			this->flightVs->Name = L"flightVs";
			this->flightVs->Size = System::Drawing::Size(86, 21);
			this->flightVs->TabIndex = 2;
			this->flightVs->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::flightVs_SelectedIndexChanged);
			// 
			// label65
			// 
			this->label65->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label65->AutoSize = true;
			this->label65->Location = System::Drawing::Point(98, 5);
			this->label65->Name = L"label65";
			this->label65->Size = System::Drawing::Size(62, 13);
			this->label65->TabIndex = 4;
			this->label65->Text = L"Flight Mode";
			// 
			// label66
			// 
			this->label66->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label66->AutoSize = true;
			this->label66->Location = System::Drawing::Point(98, 23);
			this->label66->Name = L"label66";
			this->label66->Size = System::Drawing::Size(45, 13);
			this->label66->TabIndex = 5;
			this->label66->Text = L"Flight Vr";
			// 
			// label67
			// 
			this->label67->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->label67->AutoSize = true;
			this->label67->Location = System::Drawing::Point(98, 41);
			this->label67->Name = L"label67";
			this->label67->Size = System::Drawing::Size(47, 13);
			this->label67->TabIndex = 6;
			this->label67->Text = L"Flight Vs";
			// 
			// extButtons
			// 
			this->extButtons->FormattingEnabled = true;
			this->extButtons->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"Off", L"On"});
			this->extButtons->Location = System::Drawing::Point(3, 165);
			this->extButtons->Name = L"extButtons";
			this->extButtons->Size = System::Drawing::Size(89, 21);
			this->extButtons->TabIndex = 96;
			this->extButtons->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::extButtons_SelectedIndexChanged);
			// 
			// label69
			// 
			this->label69->AutoSize = true;
			this->label69->Location = System::Drawing::Point(98, 162);
			this->label69->Name = L"label69";
			this->label69->Size = System::Drawing::Size(61, 13);
			this->label69->TabIndex = 97;
			this->label69->Text = L"Ext Buttons";
			// 
			// testButton
			// 
			this->testButton->Location = System::Drawing::Point(1077, 401);
			this->testButton->Name = L"testButton";
			this->testButton->Size = System::Drawing::Size(48, 22);
			this->testButton->TabIndex = 83;
			this->testButton->Text = L"Test";
			this->testButton->UseVisualStyleBackColor = true;
			this->testButton->Click += gcnew System::EventHandler(this, &Form1::testButton_Click_1);
			// 
			// Form1
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSize = true;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->BackColor = System::Drawing::SystemColors::ControlDark;
			this->ClientSize = System::Drawing::Size(1295, 627);
			this->Controls->Add(this->testButton);
			this->Controls->Add(this->commsLog);
			this->Controls->Add(this->logButton);
			this->Controls->Add(this->genericAlertGroup);
			this->Controls->Add(this->resetLogButton);
			this->Controls->Add(this->statusGroup);
			this->Controls->Add(this->factoryGroup);
			this->Controls->Add(this->settingsTableExtended);
			this->Controls->Add(this->configureGroup);
			this->Controls->Add(this->nmeaGroup);
			this->Controls->Add(this->gprsConfigurationGroup);
			this->Controls->Add(this->generalCommandGroup);
			this->Controls->Add(this->trackerStatusGroup);
			this->Controls->Add(this->trackerDetailsGroup);
			this->Controls->Add(this->settingsTable);
			this->Controls->Add(this->pinGroup);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->messagingGroup);
			this->Name = L"Form1";
			this->ShowIcon = false;
			this->Text = L"Tracker Connect";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->messagingGroup->ResumeLayout(false);
			this->messagingGroup->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->pinGroup->ResumeLayout(false);
			this->pinGroup->PerformLayout();
			this->settingsTable->ResumeLayout(false);
			this->settingsTable->PerformLayout();
			this->factoryGroup->ResumeLayout(false);
			this->factoryGroup->PerformLayout();
			this->trackerDetailsGroup->ResumeLayout(false);
			this->trackerDetailsGroup->PerformLayout();
			this->trackerStatusGroup->ResumeLayout(false);
			this->trackerStatusGroup->PerformLayout();
			this->nmeaGroup->ResumeLayout(false);
			this->nmeaGroup->PerformLayout();
			this->generalCommandGroup->ResumeLayout(false);
			this->statusGroup->ResumeLayout(false);
			this->statusGroup->PerformLayout();
			this->genericAlertGroup->ResumeLayout(false);
			this->genericAlertGroup->PerformLayout();
			this->gprsConfigurationGroup->ResumeLayout(false);
			this->gprsConfigurationGroup->PerformLayout();
			this->configureGroup->ResumeLayout(false);
			this->settingsTableExtended->ResumeLayout(false);
			this->settingsTableExtended->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	private: System::Void sendButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        sendMessage( false );
	}

	
    private: System::Void sendUrgentButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        sendMessage( true );
	}
    
    
    private: System::Void connectButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
 
        if ((portNumber->Text != "") && (macText->Text != ""))
        {
            if (trackerConnected == BG::DISCONNECTED)
            {
                connectStatus->Text = _serialComms->attach( portNumber->Text );
            }
            else if (trackerConnected == BG::SCANNING)
            {
                _serialComms->stopAttach();
            }
            else
            {
                _serialComms->detach();
            }
        }
        else
        {
            connectStatus->Text = "Need port number and MAC";
        }

	}


    private: static void DataReceivedHandler( System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e)
    {
        SerialPort^ sp = (SerialPort^)sender;
    }

    private: System::Void getButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        getMessages();
	}
    

    private: System::Void getButton_Click_1(System::Object^  sender, System::EventArgs^  e)
    {
        getMessages();
	}
    

    private: System::Void getMessages( void )
    {
        YbMessage ^msg = gcnew YbMessage( macText->Text, YbMessage::REQUEST_TYPE_VALUE );

        sendFrame( msg );
	}
    


    private: System::Void serialTimer_Tick(System::Object^  sender, System::EventArgs^  e)
    {
        incomingFsm();

        int result = _serialComms->outFsm();
        
        if (result != BG::OUT_OK)
        {
            if (result == BG::OUT_WRITE_DIRECT)
            {
                /* Set attribute via protocol */
                sendDirectWrite( _serialComms->currentHandle(), _serialComms->currentSetting() );
            }
            if (result == BG::OUT_READ_DIRECT)
            {
                /* Get attribute via protocol */
                sendDirectRead( _serialComms->currentHandle() );
            }
            else
            {
                connectStatus->Text = "No response";
            }
        }
        
        if (_serialComms->inFsm() == true)
        {
            int setting = (int)_serialComms->newSetting( 0 );
            int handle = (int)_serialComms->newHandle();
            doSetting( handle, setting );
            
        }
        
        if (!_serialComms->isAttached())
        {
            _trackerState = TRACKER_STATE_IDLE;
        }

        if (trackerConnected != _serialComms->isConnected())
        {
            trackerConnected = _serialComms->isConnected();
            
            setView( trackerConnected != BG::CONNECTED ? false : true );
        }
	}
    
    private: System::Void resetLogButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        commsLog->Clear();
    }


    void setView( bool onOff )
    {
        switch (trackerConnected)
        {
            case BG::DISCONNECTED:
                connectButton->Text = "Scan";
                connectStatus->Text = "";
                scanList->Items->Clear();
                scanList->Enabled = false;
                break;
            case BG::SCANNING:
                connectButton->Text = "Stop Scan";
                connectStatus->Text = "Scanning";
                scanList->Enabled = true;
                break;
            case BG::CONNECTED:
                connectButton->Text = "Disconnect";
                connectStatus->Text = "Ready";
                scanList->Enabled = false;
                break;
        }
        

        trackerDetailsGroup->Visible = onOff;
        trackerStatusGroup->Visible = onOff;
        generalCommandGroup->Visible = onOff;
        gprsConfigurationGroup->Visible = onOff;
        messagingGroup->Visible = onOff;
        pinGroup->Visible = onOff;
        configureGroup->Visible = onOff;

        nmeaGroup->Visible = onOff;
        genericAlertGroup->Visible = onOff;
        statusGroup->Visible = onOff;
        factoryGroup->Visible = onOff;
        
        if (onOff == false)
        {
            unlockPinBox->Text = "";
            newPinBox->Text = "";
            _settingsLocked = true;
            pinLockLabel->Text = "Locked";

            settingsTable->Visible = false;
            settingsTableExtended->Visible = false;
        }
        else
        {
            settingsTable->Visible = (_settingsLocked == false) ? true : false;
            settingsTableExtended->Visible = (_settingsLocked == false) ? true : false;
        }

    }
    

    void incomingFsm( void )
    {
        int length = _serialComms->bytesWaiting();
        
        if (_sendingFrame == true)
        {
            if (_serialComms->timeElapsedSince( _sendFrameStart ) < 3)
            {
                if (length != 0)
                {
                    array<unsigned char>^ buffer = gcnew array<unsigned char>( length );

                    for (int i = 0; i < length; ++i)
                    {
                        if (_incoming->addByte( _serialComms->readByte() ))
                        {
                            switch (_incoming->getType())
                            {
                                case YbMessage::CONFIRM_TYPE_VALUE:
                                    sendStatus->Text = "SENT DONE";
                                    break;

                                case YbMessage::IN_TYPE_VALUE:
                                    if (_incoming->getId() == 0)
                                    {
                                        sendStatus->Text = "NO MESSAGE";
                                    }
                                    else
                                    {
                                        inMsg->Text = String::Concat( inMsg->Text, _incoming->getText( YbMessage::GET_RESPONSE_PRE_TEXT_SZ ) );
                            
                                        /* Request another */
                                        YbMessage ^msg = gcnew YbMessage( macText->Text, _incoming->getId(), YbMessage::DELETE_TYPE_VALUE );
                            
                                        sendFrame( msg );
                                    }
                                    break;

                                case YbMessage::ACK_SENT_TYPE_VALUE:
                                    {
                                        unsigned short id = _incoming->getId();
                                        int i = 0;
                                        while (i < _sentIds->Count)
                                        {
                                            unsigned short oldId = (unsigned short)_sentIds[i];
                                            if (id == oldId)
                                            {
                                                break;
                                            }
                                            else
                                            {
                                                ++i;
                                            }
                                        }
                                    
                                        if (i < _sentIds->Count)
                                        {
                                            _sentStatus[i] = (unsigned char)1U;
                                            showAllSent();
                                        }
                                    }
                                    break;

                                case YbMessage::DELETE_TYPE_VALUE:
                                    sendStatus->Text = "DELETE DONE";
                                    break;

                                case YbMessage::PIN_TYPE_VALUE:
                                    sendStatus->Text = "PIN DONE";
                                    break;

                                case YbMessage::ACTION_TYPE_VALUE:
                                    sendStatus->Text = "COMMAND DONE";
                                    break;

                                case YbMessage::NMEA_GRAB_TYPE_VALUE:
                                    nmeaGrabText->Text = _incoming->getText( 0 );
                                    break;

                                case YbMessage::GPRS_REQUEST_TYPE_VALUE:
                                    gprsUnpack();
                                    break;

                                case YbMessage::STATUS_TYPE_VALUE:
                                    statusRetrieve();
                                    sendStatus->Text = "STATUS DONE";
                                    break;

                                case YbMessage::CONFIGURE_GET_TYPE_VALUE:
                                {
                                    unsigned int handle;
                                    unsigned int setting;
                                    int status;
                                    
                                    handle = (_incoming->getPayloadByte( 0 ) << 8);
                                    handle |= _incoming->getPayloadByte( 1 );
                                    
                                    status = _incoming->getPayloadByte( 2);
                                    setting = _incoming->getPayloadByte( 3 );
                                    if (_incoming->payloadLength() > 4)
                                    {
                                        setting <<= 8;
                                        setting |= _incoming->getPayloadByte( 4 );
                                    }
                                    
                                    if (status != 0)
                                    {
                                        doSetting( handle, setting );
                                    }
                                }
                                    break;

                                default:
                                    sendStatus->Text = "INVALID";
                                    break;
                            }
                            _incoming->reset();
                            break;
                        }
                    }
                }
            }
            else
            {
                _incoming->reset();
                sendStatus->Text = "FINISHED";
                _sendingFrame = false;
            }
        }
    }


    private: System::Void logButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        resetLogButton->Visible = !resetLogButton->Visible;
        commsLog->Visible = !commsLog->Visible;
        logButton->Text = resetLogButton->Visible == false ? "Show Log" : "Hide Log";
	}



    private: System::Void trkStatusComboBox_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
    {
        int trkStatus = trkStatusComboBox->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_TRACKING_ONOFF, trkStatus );
	}
    
    private: System::Void trkPeriodComboBox_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
    {
        int trkPeriod = trkPeriodComboBox->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_TRACKING_PERIOD, trkPeriod );
	}
    
    
    private: System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e)
    {
    }
    private: System::Void externalTypeCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int extType = externalTypeCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_EXT_TYPE, extType );
    }
    private: System::Void externalBaudCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int extBaud = externalBaudCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_EXT_BAUD, extBaud );
    }
    private: System::Void externalSamplesCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int extSamples = externalSamplesCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_EXT_SAMPLES, extSamples );
    }
    private: System::Void externalMOBCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int mob = externalMOBCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_MOB, mob );
	}
    
    
    private: System::Void burstFixCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int burstFix = burstFixCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_BURST_FIX, burstFix );
    }
    private: System::Void burstTransmitCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int burstTransmit = burstTransmitCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_BURST_TRANSMIT, burstTransmit );
    }
    
    private: System::Void gpsHotCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int hotStatus = gpsHotCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_GPS_HOT, hotStatus );
    }
    
    private: System::Void activityStatusCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int activityStatus = activityStatusCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_ACTIVITY_STATUS, activityStatus );
    }
    private: System::Void trkCarrierCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int carrier = trkCarrierCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_GPRS_STRATEGY, carrier );
    }
    private: System::Void activityLowCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int activityLow = activityLowCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_ACTIVITY_LOW, activityLow );
    }
    private: System::Void geofStatusCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int geofStatus = geofStatusCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_GEOF_STATUS, geofStatus );
    }
    private: System::Void geofPeriodCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int geofPeriod = geofPeriodCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_GEOF_PERIOD, geofPeriod );
    }
    private: System::Void geofDistanceCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int geofDistance = geofDistanceCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_GEOF_DISTANCE, geofDistance );
    }
    private: System::Void powerLimitCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int powerLimit = powerLimitCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_POWER_LIMIT, powerLimit );
    }
    private: System::Void notificationsCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int notifications = notificationsCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_NOTIFICATIONS, notifications );
    }
    private: System::Void extSensitivityCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int sense = extSensitivityCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_EXT_SENSE, sense );
    }

    private: System::Void autoTxCellCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int autoTxCell = autoTxCellCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_TRACKING_PERIOD_CELL, autoTxCell );
    }
    private: System::Void burstTxCellCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int burstTxCell = burstTxCellCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_BURST_TX_PERIOD_CELL, burstTxCell );
    }
    private: System::Void burstFixCellCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int burstFixCell = burstFixCellCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_BURST_FIX_PERIOD_CELL, burstFixCell );
    }
    private: System::Void autoTxDistressCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int autoTxDistress = autoTxDistressCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_TRACKING_PERIOD_DISTRESS, autoTxDistress );
    }
    private: System::Void burstTxDistressCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int burstTxDistress = burstTxDistressCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_BURST_TX_PERIOD_DISTRESS, burstTxDistress );
    }
    private: System::Void burstFixDistressCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int burstFixDistress = burstFixDistressCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_BURST_FIX_PERIOD_DISTRESS, burstFixDistress );
    }
    private: System::Void positionBlockCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_POSITION_BLOCK_FORMAT, positionBlockCombo->SelectedIndex );
	}
    private: System::Void gpxStatusCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int gpxStatus = gpxStatusCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_GPX_STATUS, gpxStatus );
	}
    private: System::Void gpsPeriodCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        int gpxPeriod = gpxPeriodCombo->SelectedIndex;
        _serialComms->writeSetting( BG::HANDLE_GPX_PERIOD, gpxPeriod );
	}
    private: System::Void mailCheckStatusCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_MAIL_CHECK_STATUS, mailCheckStatusCombo->SelectedIndex );
	}
    private: System::Void mailCheckPeriodCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_MAIL_CHECK_PERIOD, mailCheckPeriodCombo->SelectedIndex );
	}
    private: System::Void gpsPlatformCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_GPS_PLATFORM, gpsPlatformCombo->SelectedIndex );
    }
    private: System::Void airAlertStatus_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_AIR_VERT_ALERT_STATUS, airAlertStatus->SelectedIndex );
	}
    private: System::Void airAlertDescentSpeed_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_AIR_DESCENT_ALERT_SPEED, airAlertDescentSpeed->SelectedIndex );
	}
    private: System::Void airAlertDescentTime_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_AIR_DESCENT_ALERT_TIME, airAlertDescentTime->SelectedIndex );
	}
    private: System::Void airAlertAscentSpeed_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_AIR_ASCENT_ALERT_SPEED, airAlertAscentSpeed->SelectedIndex );
	}
    private: System::Void airAlertAscentTime_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_AIR_ASCENT_ALERT_TIME, airAlertAscentTime->SelectedIndex );
	}
    private: System::Void flightMode_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_FLIGHT_ALERT_STATUS, flightMode->SelectedIndex );
	}
    private: System::Void flightVr_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_FLIGHT_VR, flightVr->SelectedIndex );
	}
    private: System::Void flightVs_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->writeSetting( BG::HANDLE_FLIGHT_VS, flightVs->SelectedIndex );
	}
    private: System::Void extButtons_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
    }

    

    
    
    void showAllSent( void )
    {
        int i = _sentMessages->Count;
        String ^newline = gcnew String( "\x0d\x0a" );
        
        outMsg->Text = "";
        
        for (int i = 0; i < _sentMessages->Count; ++i)
        {
            outMsg->AppendText( String::Format( "{0}", _sentIds[i] ) );
            outMsg->AppendText( String::Format( " {0} ", _sentStatus[i] ) );
            outMsg->AppendText( (String ^)_sentMessages[i] );
            outMsg->AppendText( newline );
        }
    }


    void showLocation( ArrayList ^location )
    {
        #if 0
        String ^newline = gcnew String( ", " );

        String ^result = "";
        result = result + String::Format( "{0}", extractLocationBits( location, 0, 25 ) );
        result = result + newline;
        result = result + String::Format( "{0}", extractLocationBits( location, 25, 26 ) );
        result = result + newline;
        result = result + String::Format( "{0}", extractLocationBits( location, 51, 17 ) );
        result = result + newline;
        result = result + String::Format( "{0}", extractLocationBits( location, 68, 7 ) );
        result = result + newline;
        result = result + String::Format( "{0}", extractLocationBits( location, 75, 9 ) );
        result = result + newline;
        result = result + String::Format( "{0}", extractLocationBits( location, 84, 10 ) );
        result = result + newline;
        result = result + String::Format( "{0}", extractLocationBits( location, 94, 14 ) );
        result = result + newline;
        result = result + String::Format( "{0}", extractLocationBits( location, 108, 11 ) );
        result = result + newline;
        result = result + String::Format( "{0}", extractLocationBits( location, 119, 9 ) );
        locationLabel->Text = result;
        locationLabel2->Text = "";
        #else
        String ^result = "";
        for (int i = 0; i < 10; ++i)
        {
            result = String::Concat( result, String::Format( "{0:X2}", location[i] ) );
        }
        locationLabel->Text = result;

        result = "";
        for (int i = 10; i < 20; ++i)
        {
            result = String::Concat( result, String::Format( "{0:X2}", location[i] ) );
        }
        locationLabel2->Text = result;
        #endif
    }
    
    
    unsigned int extractLocationBits( ArrayList ^location, int startBit, int bits )
    {
        unsigned int result = 0U;
        int i = startBit / 8;
        unsigned char mask = ((unsigned char)1U) << (7 - (startBit % 8));
        
        while (bits != 0)
        {
            if (mask == 0)
            {
                ++i;
                mask = 0x80U;
            }

            result <<= 1;
            if (((unsigned char)location[i] & mask) != 0)
            {
                result |= 1U;
            }

            mask >>= 1;
            --bits;
        }

        return(result);
    }    


    
    void ackSentMessages( ArrayList ^id )
    {
        YbMessage ^msg = gcnew YbMessage( id, 8, YbMessage::ACK_SENT_TYPE_VALUE );

        sendFrame( msg );
	}
    

    void rsuMessage( void )
    {
	}

    void sendMessage( bool urgency )
    {
        _sentMessages->Add( composeMsg->Text );
        _sentIds->Add( _id );
        _sentStatus->Add( (unsigned char)0U );
        showAllSent();
        
        YbMessage ^msg = gcnew YbMessage( macText->Text, composeMsg->Text, _id, urgency );
        composeMsg->Text = "";

        sendFrame( msg );
        ++_id;
    }
    

    void sendFrame( YbMessage ^msg )
    {
        int length = msg->frameLength();
        array<unsigned char>^ buffer = gcnew array<unsigned char>( length );
        for (int i = 0; i < length; ++i)
        {
            buffer[i] = msg->getByte(i);
        }
        
        _serialComms->write( buffer, length );

        _sendingFrame = true;
        _sendFrameStart = _serialComms->timeReference();
        sendStatus->Text = "WAIT . . .";

        _trackerState = TRACKER_STATE_RECEIVE;
    }

    private: System::Void submitButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        if (textIsValidInt( unlockPinBox->Text, 4 ) && textIsValidInt( newPinBox->Text, 4 ))
        {
            YbMessage ^msg = gcnew YbMessage( macText->Text, textToInt( unlockPinBox->Text ), textToInt( newPinBox->Text ), YbMessage::PIN_TYPE_VALUE );

            sendFrame( msg );
        }
        else
        {
            sendStatus->Text = "INVALID PIN";
        }

	}
    
    


    int textToInt( String ^text )
    {
        int result = 0;
        
        for (int i = 0; i < text->Length; ++i)
        {
            char byte = (char)text[i];
            byte = ((byte >= '0') && (byte <= '9')) ? byte - '0' : 0;
            result *= 10;
            result += byte;
        }
        
        return(result);
    }


    bool textIsValidInt( String ^text, int maxLength )
    {
        int i = 0;
        int length = text->Length;
        
        if (length <= maxLength)
        {
            for (; i < length; ++i)
            {
                char byte = (char)text[i];
                if ((byte < '0') && (byte > '9'))
                {
                    break;
                }
            }
        }
        
        
        bool result = (i == length);
        return(result);
    }


    private: void sendNmeaGrab( void )
    {
        YbMessage ^msg = gcnew YbMessage( macText->Text, YbMessage::NMEA_GRAB_TYPE_VALUE );

        sendFrame( msg );
	}

    private: System::Void commandComboBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        sendCommand( (unsigned char)commandComboBox->SelectedIndex );
	}



    private: System::Void getStatusCombo_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        sendGetStatus( (unsigned char)getStatusCombo->SelectedIndex );
	}
    
    
    private: System::Void factorySetButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        YbMessage ^msg = gcnew YbMessage( macText->Text, 27, YbMessage::FACTORY_TYPE_VALUE );
        
        msg->addByte( rawCombo->SelectedIndex );/* raw iridium */
        msg->insertString( serialText->Text, 6);/* serial */
        msg->insertString( modelText->Text, 10);/* model */
        msg->addByte( logoComboBox->SelectedIndex );/* logo */
        msg->addChecksum();

        sendFrame( msg );
    }
    
    private: System::Void androidCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
    {
        if (_serialComms->isConnected() != BG::CONNECTED)
        {
            _serialComms->android( androidCheck->Checked );
        }
        else
        {
            androidCheck->Checked = !androidCheck->Checked;
        }
	}

    
    private: System::Void alertEnum_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
    {
        YbMessage ^msg = gcnew YbMessage( macText->Text, 11, YbMessage::GENERIC_ALERT_TYPE_VALUE );
        msg->addByte( (unsigned char)alertEnum->SelectedIndex );/* event */
        msg->addByte( alertPositionCheck->Checked == false ? 0U : 1U );/* position request */
        msg->addChecksum();

        sendFrame( msg );
	}



    private: System::Void scanList_DoubleClick(System::Object^  sender, System::EventArgs^  e)
    {
        if ((scanList->Items->Count != 0) && (trackerConnected == BG::SCANNING))
        {
            _serialComms->connectToSelected();
        }
	}


    private: System::Void testEventTimer_Tick(System::Object^  sender, System::EventArgs^  e)
    {
        sendCommand( (unsigned char)13 );
	}


    private: System::Void testButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        if (_test)
        {
            testEventTimer->Stop();
            _test = false;
        }
        else
        {
            testEventTimer->Start();
            _test = true;
        }
	}
    

    private: System::Void nmeaGrabButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        sendNmeaGrab();
	}
    




    private: System::Void gprsGetButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        gprsRequest();
    }

    private: System::Void gprsSetButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        gprsPack();
    }



    void gprsRequest( void )
    {
        YbMessage ^msg = gcnew YbMessage( macText->Text, 0, YbMessage::GPRS_REQUEST_TYPE_VALUE );
        int frameLength = msg->frameLength();

            
        msg->addByte( gprsSettings->SelectedIndex );

        msg->setLength( msg->frameLength() - frameLength );
        msg->addChecksum();

        sendFrame( msg );
    }

    void gprsUnpack( void )
    {
        int payloadLength = _incoming->payloadLength();
        int posn = 0;
        
        while (posn <= (payloadLength - 2))
        {
            int id;
            int settingLength;

            /* ID and length . . */
            id = _incoming->getPayloadByte( posn );
            ++posn;

            settingLength = _incoming->getPayloadByte( posn );
            ++posn;
        
            if (posn + settingLength <= payloadLength)
            {
                char buffer[50];
                
                int i = 0;
                for (; i < settingLength; ++i)
                {
                    buffer[i] = _incoming->getPayloadByte( posn );
                    ++posn;
                }
                buffer[i] = '\0';
                
                String ^tempStr = gcnew String( buffer );
                
                if (id = gprsSettings->SelectedIndex)
                {
                    gprsSetText->Text = tempStr;
                }
            }
            else
            {
                /* Error */
                break;
            }
        }
    }


    void gprsPack( void )
    {
        YbMessage ^msg = gcnew YbMessage( macText->Text, 0, YbMessage::GPRS_SET_TYPE_VALUE );
        int frameLength = msg->frameLength();
        
        String ^str = gprsSetText->Text;
        
        msg->addByte( gprsSettings->SelectedIndex );
        msg->addByte( str->Length );
        msg->insertString( str, str->Length);
     
        msg->setLength( msg->frameLength() - frameLength );
        msg->addChecksum();

        sendFrame( msg );
    }
 

    void statusRetrieve( void )
    {
        int payloadLength = _incoming->payloadLength();
        
        if (payloadLength > 1)
        {
            String ^msg = String::Format( "{0}", _incoming->getPayloadByte( 1 ) );
            getStatusTextBox->Text = msg;
        }
        else
        {
            getStatusTextBox->Text = "";
        }
    }


    private: void sendCommand( unsigned char command )
    {
        YbMessage ^msg = gcnew YbMessage( macText->Text, command, YbMessage::ACTION_TYPE_VALUE );

        sendFrame( msg );
	}

    private: void sendGetStatus( unsigned char status )
    {
        YbMessage ^msg = gcnew YbMessage( macText->Text, status, YbMessage::STATUS_TYPE_VALUE );

        sendFrame( msg );
	}



    private: System::Void uuidCheck_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
    {
        _serialComms->uuids( uuidCheck->Checked );
    }

    private: System::Void configureButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        sendDirectWrite( _serialComms->getHandle( (unsigned char)configureName->SelectedIndex ), (unsigned char)configureValue->SelectedIndex );
	}
    
	private: System::Void configureGetButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        sendDirectRead( _serialComms->getHandle( (unsigned char)configureName->SelectedIndex ) );
	}
    
    
    
    
    private: void sendDirectWrite( int handle, unsigned char setting )
    {
        YbMessage ^msg = gcnew YbMessage( macText->Text, 12, YbMessage::CONFIGURE_TYPE_VALUE );
        msg->addByte( (unsigned char)(handle >> 8) );
        msg->addByte( (unsigned char) handle );
        msg->addByte( setting );
        msg->addChecksum();

        sendFrame( msg );
    }
    
    private: void sendDirectRead( int handle )
    {
        YbMessage ^msg = gcnew YbMessage( macText->Text, 11, YbMessage::CONFIGURE_GET_TYPE_VALUE );
        msg->addByte( (unsigned char)(handle >> 8) );
        msg->addByte( (unsigned char) handle );
        msg->addChecksum();

        sendFrame( msg );
    }
    
    private: System::Void messagingGroup_Enter(System::Object^  sender, System::EventArgs^  e)
    {
	}


    private: void doSetting( int handle, int setting )
    {
            switch (handle)
            {
                case BG::GATT_HANDLE_TRACKING_ONOFF:
                    if (setting != 0xff)
                    {
                        trkStatusComboBox->SelectedIndex = setting;
                    }
                    break;

                case BG::GATT_HANDLE_TRACKING_PERIOD:
                    if (setting != 0xff)
                    {
                        trkPeriodComboBox->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_BURST_FIX:
                    if (setting != 0xff)
                    {
                        burstFixCombo->SelectedIndex = setting;
                    }
                    break;

                case BG::GATT_HANDLE_BURST_TRANSMIT:
                    if (setting != 0xff)
                    {
                        burstTransmitCombo->SelectedIndex = setting;
                    }
                    break;

                case BG::GATT_HANDLE_GPS_HOT:
                    if (setting != 0xff)
                    {
                        gpsHotCombo->SelectedIndex = setting;
                    }
                    break;

                    case BG::GATT_HANDLE_MESSAGE_COUNT:
                    inboxCount->Text = String::Format( "{0}", (int)_serialComms->newSetting( 0 ) );
                    if ((setting != 0) && (setting != 0xff))
                    {
                        getMessages();
                    }
                    break;
                    

                    case BG::GATT_HANDLE_OUTBOX_STATUS:
                    {
                        ArrayList ^id = gcnew ArrayList();
                        for (int i = 0; i < 9; ++i)
                        {
                            id->Add( (unsigned char)_serialComms->newSetting( i ) );
                        }
                    
                        ackSentMessages( id );
                    }
                    break;
                    

                    case BG::GATT_HANDLE_GPS_STATUS:
                    gpsLabel->Text = String::Format( "{0}", (int)_serialComms->newSetting( 0 ) );
//                    gpsLabel->Text = (setting == 0) ? "Idle" : "Running";
                    break;

                    case BG::GATT_HANDLE_IRIDIUM_STATUS:
                    iridiumLabel->Text = String::Format( "{0}", (int)_serialComms->newSetting( 0 ) );
                    #if 0
                    switch (setting)
                    {
                        case 0:
                            iridiumLabel->Text = "Idle";
                            break;
                        case 1:
                            iridiumLabel->Text = "Transmitting";
                            break;
                        case 2:
                            iridiumLabel->Text = "On";
                            break;
                    }
                    #endif
                    break;

                    case BG::GATT_HANDLE_TRACKING_REPORT:
                    {
                    ArrayList ^location = gcnew ArrayList();
                    for (int i = 0; i < 20; ++i)
                    {
                        location->Add( (unsigned char)_serialComms->newSetting( i ) );
                    }
                    showLocation( location );
                    }
                    break;
                    
                    case BG::GATT_HANDLE_SW_VERSION:
                    {
                            char version[17];
                            int i = 0;
                            for (; i < 16; ++i)
                            {
                                version[i] = (unsigned char)_serialComms->newSetting( i );
                                if (version[i] == 0)
                                {
                                    break;
                                }
                            }
                            version[i] = 0;
                            String ^temp = gcnew String( version );
                            versionLabel->Text = temp;
                    }
                    break;
                    
                    case BG::GATT_HANDLE_BATTERY:
                    {
                        batteryLabel->Text = String::Format( "{0}", (int)_serialComms->newSetting( 0 ) );
                        _serialComms->reset();
                    }
                    break;

                    case BG::GATT_HANDLE_PIN_LOCK:
                        _settingsLocked = (setting == 0) ? false : true;
                        pinLockLabel->Text = (setting == 0) ? "UnLocked" : "Locked";
                        setView( trackerConnected != BG::CONNECTED ? false : true );
                    break;
                    
                    case BG::GATT_HANDLE_IMEI:
                    {
                        char imei[17];
                        for (int i = 0; i < 17; ++i)
                        {
                            imei[i] = (unsigned char)_serialComms->newSetting( i );
                        }
                        imei[17] = 0;
                        String ^temp = gcnew String( imei );
                        imeiLabel->Text = temp;
                    }
                    break;

                    case BG::GATT_HANDLE_NAME:
                    {
                        char name[20];
                        int i = 0;
                        for (; i < 17; ++i)
                        {
                            name[i] = (unsigned char)_serialComms->newSetting( i );
                            if (name[i] == 0)
                            {
                                break;
                            }
                        }
                        name[i] = 0;
                        String ^temp = gcnew String( name );
                        productNameLabel->Text = temp;
                    }
                    break;

                case BG::GATT_HANDLE_EXT_TYPE:
                    if (setting != 0xff)
                    {
                        externalTypeCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_EXT_BAUD:
                    if (setting != 0xff)
                    {
                        externalBaudCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_EXT_SAMPLES:
                    if (setting != 0xff)
                    {
                        externalSamplesCombo->SelectedIndex = setting;
                    }
                    break;

                  case BG::GATT_HANDLE_POWER:
                    powerLabel->Text = (setting == 0) ? "Battery" : "External";
                    break;
                    
                case BG::GATT_HANDLE_MOB:
                    if (setting != 0xff)
                    {
                        externalMOBCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_BLE_VERSION:
                    bleVersionLabel->Text = String::Format( "{0}", (int)_serialComms->newSetting( 0 ) );
                    break;

                case BG::GATT_HANDLE_RAW:
                    rawLabel->Text = String::Format( "{0}", (int)_serialComms->newSetting( 0 ) );
                    break;
                case BG::GATT_HANDLE_ACTIVITY_STATUS:
                    if (setting != 0xff)
                    {
                        activityStatusCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_GPRS_STRATEGY:
                    if (setting != 0xff)
                    {
                        trkCarrierCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_ACTIVITY_LOW:
                    if (setting != 0xff)
                    {
                        activityLowCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_GEOF_STATUS:
                    if (setting != 0xff)
                    {
                        geofStatusCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_GEOF_PERIOD:
                    if (setting != 0xff)
                    {
                        geofPeriodCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_GEOF_DISTANCE:
                    if (setting != 0xff)
                    {
                        geofDistanceCombo->SelectedIndex = setting;
                    }
                    break;

                case BG::GATT_HANDLE_POWER_LIMIT:
                    if (setting != 0xff)
                    {
                        powerLimitCombo->SelectedIndex = setting;
                    }
                    break;

                case BG::GATT_HANDLE_NOTIFICATIONS:
                    if (setting != 0xff)
                    {
                        notificationsCombo->SelectedIndex = setting;
                    }
                    break;

                case BG::GATT_HANDLE_D_BOARDS:
                    gprsLabel->Text = String::Format( "{0}", (int)_serialComms->newSetting( 0 ) );
                    break;
                    
                case BG::GATT_HANDLE_GPRS_MSISDN:
                {
                        char msisdn[15];
                        int i = 0;
                        for (; i < 14; ++i)
                        {
                            msisdn[i] = (unsigned char)_serialComms->newSetting( i );
                            if (msisdn[i] == 0)
                            {
                                break;
                            }
                        }
                        msisdn[i] = 0;
                        String ^temp = gcnew String( msisdn );
                        gprsMsisdn->Text = temp;
                }
                break;
                    
                case BG::GATT_HANDLE_GPRS_SIM:
                {
                        char sim[21];
                        int i = 0;
                        for (; i < 20; ++i)
                        {
                            sim[i] = (unsigned char)_serialComms->newSetting( i );
                            if (sim[i] == 0)
                            {
                                break;
                            }
                        }
                        sim[i] = 0;
                        String ^temp = gcnew String( sim );
                        gprsSim->Text = temp;
                }
                break;

                case BG::GATT_HANDLE_GPRS_LOCATION:
                {
                        char location[21];
                        int i = 0;
                        for (; i < 20; ++i)
                        {
                            location[i] = (unsigned char)_serialComms->newSetting( i );
                            if (location[i] == 0)
                            {
                                break;
                            }
                        }
                        location[i] = 0;
                        String ^temp = gcnew String( location );
                        gprsLocation->Text = temp;
                }
                break;
            
                case BG::GATT_HANDLE_GPRS_SIGNAL:
                    gprsSignal->Text = String::Format( "{0}", (int)_serialComms->newSetting( 0 ) );
                    break;
                    
                case BG::GATT_HANDLE_GPRS_STATUS:
                    gprsStatus->Text = String::Format( "{0}", (int)_serialComms->newSetting( 0 ) );
                    break;

                case BG::GATT_HANDLE_EXT_SENSE:
                    if (setting != 0xff)
                    {
                        extSensitivityCombo->SelectedIndex = setting;
                    }
                    break;
            
                
                case BG::GATT_HANDLE_BURST_TX_PERIOD_CELL:
                    if (setting != 0xff)
                    {
                        burstTxCellCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_BURST_TX_PERIOD_DISTRESS:
                    if (setting != 0xff)
                    {
                        burstTxDistressCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_BURST_FIX_PERIOD_DISTRESS:
                    if (setting != 0xff)
                    {
                        burstFixDistressCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_BURST_FIX_PERIOD_CELL:
                    if (setting != 0xff)
                    {
                        burstFixCellCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_TRACKING_PERIOD_CELL:
                    if (setting != 0xff)
                    {
                        autoTxCellCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_TRACKING_PERIOD_DISTRESS:
                    if (setting != 0xff)
                    {
                        autoTxDistressCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_POSITION_BLOCK_FORMAT:
                    if (setting != 0xff)
                    {
                        positionBlockCombo->SelectedIndex = setting;
                    }
                    break;
                case BG::GATT_HANDLE_GPX_STATUS:
                    if (setting != 0xff)
                    {
                        gpxStatusCombo->SelectedIndex = setting;
                    }
                    break;
                case BG::GATT_HANDLE_GPX_PERIOD:
                    if (setting != 0xff)
                    {
                        gpxPeriodCombo->SelectedIndex = setting;
                    }
                    break;
                case BG::GATT_HANDLE_MAIL_CHECK_STATUS:
                    if (setting != 0xff)
                    {
                        mailCheckStatusCombo->SelectedIndex = setting;
                    }
                    break;
                case BG::GATT_HANDLE_MAIL_CHECK_PERIOD:
                    if (setting != 0xff)
                    {
                        mailCheckPeriodCombo->SelectedIndex = setting;
                    }
                    break;
                case BG::GATT_HANDLE_GPS_PLATFORM:
                    if (setting != 0xff)
                    {
                        gpsPlatformCombo->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_AIR_VERT_ALERT_STATUS:
                    if (setting != 0xff)
                    {
                        airAlertStatus->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_AIR_DESCENT_ALERT_SPEED:
                    if (setting != 0xff)
                    {
                        airAlertDescentSpeed->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_AIR_DESCENT_ALERT_TIME:
                    if (setting != 0xff)
                    {
                        airAlertDescentTime->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_AIR_ASCENT_ALERT_SPEED:
                    if (setting != 0xff)
                    {
                        airAlertAscentSpeed->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_AIR_ASCENT_ALERT_TIME:
                    if (setting != 0xff)
                    {
                        airAlertAscentTime->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_FLIGHT_ALERT_STATUS:
                    if (setting != 0xff)
                    {
                        flightMode->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_FLIGHT_VR:
                    if (setting != 0xff)
                    {
                        flightVr->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_FLIGHT_VS:
                    if (setting != 0xff)
                    {
                        flightVs->SelectedIndex = setting;
                    }
                    break;
                    
                case BG::GATT_HANDLE_TX_CONTEXT:
                {
                    switch (setting)
                    {
                        case 0:
                            TxContextLabel->Text = "No TX";
                            break;
                        case 1:
                            TxContextLabel->Text = "Distress";
                            break;
                        case 2:
                            TxContextLabel->Text = "Cell";
                            break;
                        default:
                            TxContextLabel->Text = "Sbd";
                            break;
                    }
                }
                break;

                case BG::GATT_HANDLE_WATCH_STATUS:
                {
                    switch (setting)
                    {
                        case 0:
                        case 3:
                            WatchStatusLabel->Text = "Off";
                            break;
                        default:
                            WatchStatusLabel->Text = "On";
                            break;
                    }
                }
                break;

                case BG::GATT_HANDLE_TEST_STATUS:
                {
                    String ^msg = String::Format( "{0}", setting );
                    selfTestResult->Text = msg;
                }
                    break;
                    
            }            
        
    }



    private: System::Void testButton_Click_1(System::Object^  sender, System::EventArgs^  e)
    {
        int handle = BG::GATT_HANDLE_TEST_STATUS;
        
        YbMessage ^msg = gcnew YbMessage( macText->Text, 13, YbMessage::CONFIGURE_TYPE_VALUE );
        msg->addByte( (unsigned char)(handle >> 8) );
        msg->addByte( (unsigned char) handle );
        msg->addByte( 0 );
        msg->addByte( 0 );
        msg->addChecksum();

        sendFrame( msg );
    }
};
}