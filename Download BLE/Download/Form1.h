#pragma once

#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>

#include <windows.h>
#include "ybmessage.h"
#include "ble.h"


namespace Download {

//    using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO::Ports;
	using namespace System::Threading;

    const int MAX_NAME_SIZE = 100;/* */

    const unsigned char FILE_SEGMENT_COMMAND = (unsigned char)0x06;
    const unsigned char FILE_SEGMENT_RESPONSE = (unsigned char)0x06;

    const unsigned char FILE_GET_SEGMENT_COMMAND = (unsigned char)0x10;
    const unsigned char FILE_GET_SEGMENT_RESPONSE = (unsigned char)0x10;

    const unsigned char FILE_LIST_COMMAND = (unsigned char)0x11;
    const unsigned char FILE_LIST_PAYLOAD_SZ = 4;
    const unsigned char FILE_LIST_RESPONSE = (unsigned char)0x11;

    const unsigned char FILE_DETAIL_COMMAND = (unsigned char)0x12;
    const unsigned char FILE_DETAIL_PAYLOAD_SZ = 13;
    const unsigned char FILE_DETAIL_RESPONSE = (unsigned char)0x12;

    const int FILE_SEGMENT_SIZE = 256;
    const int FILE_SEGMENT_ADDRESS_SZ = 4;
    const int FILE_SEGMENT_SIZE_SZ = 0;//4;
    const int FILE_SEGMENT_NAME_SZ = 13;
    const int MAX_SHORT_NAME_SIZE = 12;
    const int TICK_INTERVAL = 5;/* ms */
    const int MAX_PROTOCOL_RESPONSE_TIME = 20;/* Secs */
    const int MAX_PROTOCOL_RESPONSE_POLLS = ((MAX_PROTOCOL_RESPONSE_TIME * 1000) / BG::TICK_INTERVAL);
    
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
	        _isFileSelected = false;
            trackerConnected = BG::DISCONNECTED;
            
            setView( false );
            
            _response = false;
            _incoming = gcnew YbMessage();
            _ewh = gcnew EventWaitHandle( false, EventResetMode::ManualReset );
            _serialComms = gcnew Ble( btoothDevices, scanList );
            serialTimer->Interval = TICK_INTERVAL;
            serialTimer->Enabled = true;
            serialTimer->Start();
            newFrame = false;
            _endOfFile = false;
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
	private: System::Windows::Forms::TextBox^  portNumber;
	protected: 

	protected: 
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::OpenFileDialog^  openFile;

	private: System::Windows::Forms::Button^  connectButton;
	private: System::Windows::Forms::Button^  downloadButton;
	private: System::Windows::Forms::Label^  downloadStatus;



	private:
		/// <summary>
		/// Required designer variable.
    private: SerialPort^ _trackerPort;
    private: int trackerConnected;
	private: bool _isFileSelected;
	private: int _filePosition;
    private: int _fileEnd;
	private: int _trackerState;
    YbMessage ^_incoming;
	static bool _response;
    static EventWaitHandle^ _ewh;
    Ble ^_serialComms;
    unsigned long _pollRef;
    int _sendFrameStart;
    unsigned long _pollTick;
    bool newFrame;
    bool _endOfFile;

    	 /// </summary>

	private: System::ComponentModel::IContainer^  components;
	private: System::Windows::Forms::TextBox^  macText;
	private: System::Windows::Forms::Label^  fileSize;

	private: System::Windows::Forms::ProgressBar^  progress;
	private: System::Windows::Forms::Label^  fileSizeLabel;
	private: System::Windows::Forms::TextBox^  fileName;
	private: System::Windows::Forms::Label^  fileNameLabel;

	private: System::Windows::Forms::Button^  browseButton;
	private: System::Windows::Forms::TextBox^  btoothDevices;
	private: System::Windows::Forms::Timer^  serialTimer;
	private: System::Windows::Forms::Label^  connectStatus;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  installButton;
	private: System::Windows::Forms::ListBox^  scanList;
	private: System::Windows::Forms::Button^  uploadButton;
	private: System::Windows::Forms::TextBox^  uploadSize;
	private: System::Windows::Forms::TextBox^  uploadPosition;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Button^  uploadListButton;
	private: System::Windows::Forms::Button^  uploadSegmentsButton;
	private: System::Windows::Forms::TextBox^  uploadInfo;
	private: System::Windows::Forms::TextBox^  listRange;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  testButton;







	private: System::Windows::Forms::Label^  label2;


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->portNumber = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->openFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->connectButton = (gcnew System::Windows::Forms::Button());
			this->downloadButton = (gcnew System::Windows::Forms::Button());
			this->downloadStatus = (gcnew System::Windows::Forms::Label());
			this->macText = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->fileSize = (gcnew System::Windows::Forms::Label());
			this->progress = (gcnew System::Windows::Forms::ProgressBar());
			this->fileSizeLabel = (gcnew System::Windows::Forms::Label());
			this->fileName = (gcnew System::Windows::Forms::TextBox());
			this->fileNameLabel = (gcnew System::Windows::Forms::Label());
			this->browseButton = (gcnew System::Windows::Forms::Button());
			this->btoothDevices = (gcnew System::Windows::Forms::TextBox());
			this->serialTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->connectStatus = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->installButton = (gcnew System::Windows::Forms::Button());
			this->scanList = (gcnew System::Windows::Forms::ListBox());
			this->uploadButton = (gcnew System::Windows::Forms::Button());
			this->uploadSize = (gcnew System::Windows::Forms::TextBox());
			this->uploadPosition = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->uploadListButton = (gcnew System::Windows::Forms::Button());
			this->uploadSegmentsButton = (gcnew System::Windows::Forms::Button());
			this->uploadInfo = (gcnew System::Windows::Forms::TextBox());
			this->listRange = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->testButton = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// portNumber
			// 
			this->portNumber->Location = System::Drawing::Point(12, 41);
			this->portNumber->Name = L"portNumber";
			this->portNumber->Size = System::Drawing::Size(40, 20);
			this->portNumber->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 25);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(29, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Port:";
			// 
			// openFile
			// 
			this->openFile->FileName = L"openFileDialog1";
			this->openFile->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFile_FileOk);
			// 
			// connectButton
			// 
			this->connectButton->Location = System::Drawing::Point(162, 41);
			this->connectButton->Name = L"connectButton";
			this->connectButton->Size = System::Drawing::Size(74, 20);
			this->connectButton->TabIndex = 2;
			this->connectButton->Text = L"Connect";
			this->connectButton->UseVisualStyleBackColor = true;
			this->connectButton->Click += gcnew System::EventHandler(this, &Form1::connectButton_Click);
			// 
			// downloadButton
			// 
			this->downloadButton->Location = System::Drawing::Point(15, 147);
			this->downloadButton->Name = L"downloadButton";
			this->downloadButton->Size = System::Drawing::Size(71, 24);
			this->downloadButton->TabIndex = 3;
			this->downloadButton->Text = L"Download";
			this->downloadButton->UseVisualStyleBackColor = true;
			this->downloadButton->Click += gcnew System::EventHandler(this, &Form1::downloadButton_Click);
			// 
			// downloadStatus
			// 
			this->downloadStatus->AutoSize = true;
			this->downloadStatus->Location = System::Drawing::Point(8, 475);
			this->downloadStatus->Name = L"downloadStatus";
			this->downloadStatus->Size = System::Drawing::Size(78, 13);
			this->downloadStatus->TabIndex = 4;
			this->downloadStatus->Text = L"Not connected";
			// 
			// macText
			// 
			this->macText->Location = System::Drawing::Point(58, 41);
			this->macText->Name = L"macText";
			this->macText->Size = System::Drawing::Size(98, 20);
			this->macText->TabIndex = 5;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(55, 25);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(33, 13);
			this->label2->TabIndex = 6;
			this->label2->Text = L"MAC:";
			// 
			// fileSize
			// 
			this->fileSize->AutoSize = true;
			this->fileSize->Location = System::Drawing::Point(112, 449);
			this->fileSize->Name = L"fileSize";
			this->fileSize->Size = System::Drawing::Size(13, 13);
			this->fileSize->TabIndex = 7;
			this->fileSize->Text = L"0";
			// 
			// progress
			// 
			this->progress->Location = System::Drawing::Point(11, 402);
			this->progress->Name = L"progress";
			this->progress->Size = System::Drawing::Size(496, 21);
			this->progress->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progress->TabIndex = 8;
			// 
			// fileSizeLabel
			// 
			this->fileSizeLabel->AutoSize = true;
			this->fileSizeLabel->Location = System::Drawing::Point(9, 449);
			this->fileSizeLabel->Name = L"fileSizeLabel";
			this->fileSizeLabel->Size = System::Drawing::Size(97, 13);
			this->fileSizeLabel->TabIndex = 9;
			this->fileSizeLabel->Text = L"Bytes downloaded:";
			// 
			// fileName
			// 
			this->fileName->Location = System::Drawing::Point(12, 107);
			this->fileName->Name = L"fileName";
			this->fileName->Size = System::Drawing::Size(495, 20);
			this->fileName->TabIndex = 10;
			// 
			// fileNameLabel
			// 
			this->fileNameLabel->AutoSize = true;
			this->fileNameLabel->Location = System::Drawing::Point(12, 88);
			this->fileNameLabel->Name = L"fileNameLabel";
			this->fileNameLabel->Size = System::Drawing::Size(26, 13);
			this->fileNameLabel->TabIndex = 11;
			this->fileNameLabel->Text = L"File:";
			// 
			// browseButton
			// 
			this->browseButton->Location = System::Drawing::Point(457, 133);
			this->browseButton->Name = L"browseButton";
			this->browseButton->Size = System::Drawing::Size(50, 20);
			this->browseButton->TabIndex = 12;
			this->browseButton->Text = L"Browse";
			this->browseButton->UseVisualStyleBackColor = true;
			this->browseButton->Click += gcnew System::EventHandler(this, &Form1::browseButton_Click);
			// 
			// btoothDevices
			// 
			this->btoothDevices->Location = System::Drawing::Point(365, 446);
			this->btoothDevices->Multiline = true;
			this->btoothDevices->Name = L"btoothDevices";
			this->btoothDevices->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->btoothDevices->Size = System::Drawing::Size(142, 66);
			this->btoothDevices->TabIndex = 13;
			// 
			// serialTimer
			// 
			this->serialTimer->Tick += gcnew System::EventHandler(this, &Form1::serialTimer_Tick);
			// 
			// connectStatus
			// 
			this->connectStatus->AutoSize = true;
			this->connectStatus->Location = System::Drawing::Point(159, 64);
			this->connectStatus->Name = L"connectStatus";
			this->connectStatus->Size = System::Drawing::Size(0, 13);
			this->connectStatus->TabIndex = 14;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(309, 492);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(50, 20);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Reset";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// installButton
			// 
			this->installButton->Location = System::Drawing::Point(15, 177);
			this->installButton->Name = L"installButton";
			this->installButton->Size = System::Drawing::Size(71, 22);
			this->installButton->TabIndex = 16;
			this->installButton->Text = L"Install";
			this->installButton->UseVisualStyleBackColor = true;
			this->installButton->Click += gcnew System::EventHandler(this, &Form1::installButton_Click);
			// 
			// scanList
			// 
			this->scanList->FormattingEnabled = true;
			this->scanList->Location = System::Drawing::Point(321, 24);
			this->scanList->Name = L"scanList";
			this->scanList->Size = System::Drawing::Size(136, 56);
			this->scanList->TabIndex = 17;
			this->scanList->DoubleClick += gcnew System::EventHandler(this, &Form1::scanList_DoubleClick);
			// 
			// uploadButton
			// 
			this->uploadButton->Location = System::Drawing::Point(15, 229);
			this->uploadButton->Name = L"uploadButton";
			this->uploadButton->Size = System::Drawing::Size(71, 37);
			this->uploadButton->TabIndex = 18;
			this->uploadButton->Text = L"Upload";
			this->uploadButton->UseVisualStyleBackColor = true;
			this->uploadButton->Click += gcnew System::EventHandler(this, &Form1::uploadButton_Click);
			// 
			// uploadSize
			// 
			this->uploadSize->Location = System::Drawing::Point(162, 245);
			this->uploadSize->Name = L"uploadSize";
			this->uploadSize->Size = System::Drawing::Size(51, 20);
			this->uploadSize->TabIndex = 19;
			// 
			// uploadPosition
			// 
			this->uploadPosition->Location = System::Drawing::Point(103, 245);
			this->uploadPosition->Name = L"uploadPosition";
			this->uploadPosition->Size = System::Drawing::Size(50, 20);
			this->uploadPosition->TabIndex = 20;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(100, 229);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(33, 13);
			this->label3->TabIndex = 21;
			this->label3->Text = L"From:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(159, 229);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"To:";
			// 
			// uploadListButton
			// 
			this->uploadListButton->Location = System::Drawing::Point(17, 283);
			this->uploadListButton->Name = L"uploadListButton";
			this->uploadListButton->Size = System::Drawing::Size(71, 36);
			this->uploadListButton->TabIndex = 23;
			this->uploadListButton->Text = L"List";
			this->uploadListButton->UseVisualStyleBackColor = true;
			this->uploadListButton->Click += gcnew System::EventHandler(this, &Form1::uploadListButton_Click);
			// 
			// uploadSegmentsButton
			// 
			this->uploadSegmentsButton->Location = System::Drawing::Point(17, 346);
			this->uploadSegmentsButton->Name = L"uploadSegmentsButton";
			this->uploadSegmentsButton->Size = System::Drawing::Size(71, 24);
			this->uploadSegmentsButton->TabIndex = 24;
			this->uploadSegmentsButton->Text = L"File Detail";
			this->uploadSegmentsButton->UseVisualStyleBackColor = true;
			this->uploadSegmentsButton->Click += gcnew System::EventHandler(this, &Form1::uploadSegmentsButton_Click);
			// 
			// uploadInfo
			// 
			this->uploadInfo->Location = System::Drawing::Point(365, 229);
			this->uploadInfo->Multiline = true;
			this->uploadInfo->Name = L"uploadInfo";
			this->uploadInfo->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->uploadInfo->Size = System::Drawing::Size(142, 141);
			this->uploadInfo->TabIndex = 25;
			// 
			// listRange
			// 
			this->listRange->Location = System::Drawing::Point(103, 299);
			this->listRange->Name = L"listRange";
			this->listRange->Size = System::Drawing::Size(34, 20);
			this->listRange->TabIndex = 26;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(100, 283);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(39, 13);
			this->label5->TabIndex = 27;
			this->label5->Text = L"Range";
			// 
			// testButton
			// 
			this->testButton->Location = System::Drawing::Point(190, 492);
			this->testButton->Name = L"testButton";
			this->testButton->Size = System::Drawing::Size(46, 19);
			this->testButton->TabIndex = 28;
			this->testButton->Text = L"Test";
			this->testButton->UseVisualStyleBackColor = true;
			this->testButton->Click += gcnew System::EventHandler(this, &Form1::testButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(536, 518);
			this->Controls->Add(this->testButton);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->listRange);
			this->Controls->Add(this->uploadInfo);
			this->Controls->Add(this->uploadSegmentsButton);
			this->Controls->Add(this->uploadListButton);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->uploadPosition);
			this->Controls->Add(this->uploadSize);
			this->Controls->Add(this->uploadButton);
			this->Controls->Add(this->scanList);
			this->Controls->Add(this->installButton);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->connectStatus);
			this->Controls->Add(this->btoothDevices);
			this->Controls->Add(this->browseButton);
			this->Controls->Add(this->fileNameLabel);
			this->Controls->Add(this->fileName);
			this->Controls->Add(this->fileSizeLabel);
			this->Controls->Add(this->progress);
			this->Controls->Add(this->fileSize);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->macText);
			this->Controls->Add(this->downloadStatus);
			this->Controls->Add(this->downloadButton);
			this->Controls->Add(this->connectButton);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->portNumber);
			this->Name = L"Form1";
			this->Text = L"File Manager";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void downloadButton_Click(System::Object^  sender, System::EventArgs^  e)
{
    _filePosition = 0;
    _endOfFile = false;
    sendFileSegment();
}


private: System::Void uploadButton_Click(System::Object^  sender, System::EventArgs^  e)
{
    _filePosition = Convert::ToInt32( uploadPosition->Text );
    _fileEnd =  Convert::ToInt32( uploadSize->Text );
    _endOfFile = false;
    getFileSegment();
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

private: System::Void openFile_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
{
    _isFileSelected = true;
}


private: void sendFileSegment( void )
{
	char longName[MAX_NAME_SIZE];/* to buffer file names */
    std::fstream _fileIn;/* file handle */

    unsigned char serialBuffer[FILE_SEGMENT_SIZE + FILE_SEGMENT_NAME_SZ + FILE_SEGMENT_ADDRESS_SZ + FILE_SEGMENT_SIZE_SZ];/* serial out buffer */
    unsigned char *ptr = serialBuffer;

    memset( serialBuffer, 0U, sizeof(serialBuffer) );
    
    if (_isFileSelected == true)
    {
        int nameSize = openFile->FileName->Length;
        for (int i = 0; i < nameSize; ++i )
        {
            longName[i] = (char)openFile->FileName[i];
        }
        longName[nameSize] = '\0';

        /* Isolate just the filename (without path) */
        char *shortName = longName + strlen( longName );
        while ((*shortName != (char)'\\') && (shortName != longName))
        {
            --shortName;
        }
        if (*shortName == '\\')
        {
            ++shortName;
        }
        
        if (strlen( shortName ) <= MAX_SHORT_NAME_SIZE)
        {
            /* Now open the file and send one segment at a time */
            _fileIn.open( longName, std::fstream::in | std::fstream::binary);
            if (_fileIn.fail() != true)
            {
                _fileIn.seekg( 0, std::ios_base::end ); 
                _fileEnd = (int)_fileIn.tellg();
                _fileIn.seekg( _filePosition, std::ios_base::beg );
                
                if (_filePosition == 0)
                {
                    progress->Visible = true;
                    progress->Minimum = 1;
                    progress->Maximum = (_fileEnd / FILE_SEGMENT_SIZE) + 1;
                    progress->Value = 1;
                    progress->Step = 1;
                }



                int size = _fileEnd - _filePosition;
                size = size > FILE_SEGMENT_SIZE ? FILE_SEGMENT_SIZE : size;

                ptr = &serialBuffer[0];
                strcpy_s( (char *)ptr, MAX_SHORT_NAME_SIZE + 1, shortName );

                ptr = &serialBuffer[13];

                *ptr++ = (unsigned char)(_filePosition >> 24);
                *ptr++ = (unsigned char)(_filePosition >> 16);
                *ptr++ = (unsigned char)(_filePosition >> 8);
                *ptr++ = (unsigned char)(_filePosition >> 0);

                _filePosition += size;

                _fileIn.read( (char *)ptr, size );
                String ^logMsg = String::Format( "Seg= {0} {1}", _filePosition, _fileEnd );
                log( logMsg );


                YbMessage ^msg = gcnew YbMessage( macText->Text, FILE_SEGMENT_COMMAND, serialBuffer, (ptr - serialBuffer) + size );

                int length = msg->frameLength();
                array<unsigned char>^ buffer = gcnew array<unsigned char>( length );
                for (int i = 0; i < length; ++i)
                {
                    buffer[i] = msg->getByte(i);
                }

        
                _serialComms->write( buffer, length );



                downloadStatus->Text = "Wait . . .";
                _pollRef = _pollTick;
                _sendFrameStart = _serialComms->timeReference();
                newFrame = true;
                _incoming->reset();
                
                _fileIn.close();
            }
            else
            {
                downloadStatus->Text = "Can't open file!";
            }
        }
        else
        {
            downloadStatus->Text = "File name too long!";
        }
    }
    else
    {
        downloadStatus->Text = "No file selected!";
    }

}    




private: void getFileSegment( void )
{
	char longName[MAX_NAME_SIZE];/* to buffer file names */

    unsigned char serialBuffer[FILE_SEGMENT_SIZE + FILE_SEGMENT_NAME_SZ + FILE_SEGMENT_ADDRESS_SZ];/* serial out buffer */
    unsigned char *ptr = serialBuffer;

    memset( serialBuffer, 0U, sizeof(serialBuffer) );
    
    int nameSize = fileName->Text->Length;
    for (int i = 0; i < nameSize; ++i )
    {
        longName[i] = (char)fileName->Text[i];
    }
    longName[nameSize] = '\0';
  
    if (nameSize <= MAX_SHORT_NAME_SIZE)
    {
        if (_filePosition == 0)
        {
            progress->Visible = true;
            progress->Minimum = 1;
            progress->Maximum = (_fileEnd / FILE_SEGMENT_SIZE) + 1;
            progress->Value = 1;
            progress->Step = 1;
        }

        ptr = &serialBuffer[0];
        strcpy_s( (char *)ptr, MAX_SHORT_NAME_SIZE + 1, longName );

        ptr = &serialBuffer[13];

        
        *ptr++ = (unsigned char)(_filePosition >> 24);
        *ptr++ = (unsigned char)(_filePosition >> 16);
        *ptr++ = (unsigned char)(_filePosition >> 8);
        *ptr++ = (unsigned char)(_filePosition >> 0);
        
        YbMessage ^msg = gcnew YbMessage( macText->Text, FILE_GET_SEGMENT_COMMAND, serialBuffer, (ptr - serialBuffer) );


        int length = msg->frameLength();
        array<unsigned char>^ buffer = gcnew array<unsigned char>( length );
        for (int i = 0; i < length; ++i)
        {
            buffer[i] = msg->getByte(i);
        }

    
        _serialComms->write( buffer, length );
        
        
        downloadStatus->Text = "Wait . . .";
        _pollRef = _pollTick;
        _sendFrameStart = _serialComms->timeReference();
        newFrame = true;
        _incoming->reset();
        
        
    }
    else
    {
        downloadStatus->Text = "File name too long!";
    }

}    




private: static void DataReceivedHandler( System::Object^ sender, System::IO::Ports::SerialDataReceivedEventArgs^ e)
{
    _response = true;
    _ewh->Set();
}


private: void receiveResponse( void )
{
    unsigned char type = 0;
    
    int length = _serialComms->bytesWaiting();
    
    ++_pollTick;                                                                                                                                  
    if (newFrame == true)
    {
        if (_serialComms->timeElapsedSince( _sendFrameStart ) < 3)
        {
            if (length != 0)
            {
                array<unsigned char>^ buffer = gcnew array<unsigned char>( length );
                _serialComms->read( buffer, length );


                for (int i = 0; i < length; ++i)
                {
                    if (_incoming->addByte( buffer[i] ) == true)
                    {
                        switch (_incoming->getType())
                        {
                            case FILE_SEGMENT_RESPONSE:
                                log( "Seg Rsp" );
                            
                                int trackerNextAddress;
                                trackerNextAddress = (_incoming->getByte( 9 ) << 24) | (_incoming->getByte( 10 ) << 16) | (_incoming->getByte( 11 ) << 8) | (_incoming->getByte( 12 ) << 0);
                                if (trackerNextAddress == _filePosition)
                                {
                                    char data[10];
                                    sprintf_s( data, 10, "%u", trackerNextAddress );
                	                String^ str = gcnew String( &data[0] );
                                    fileSize->Text = str;
                                    progress->PerformStep();
                                    if (_filePosition < _fileEnd)
                                    {
                                        sendFileSegment();
                                    }
                                    else if (_endOfFile == false)
                                    {
                                        _endOfFile = true;
                                        sendFileSegment();
                                    }
                                    else
                                    {
                                        _endOfFile = false;
                                        newFrame = false;
                                        downloadStatus->Text = "Done";
                                    }
                                }
                                else
                                {
                                    log( "Seg No Sync" );
                                    newFrame = false;
                                    downloadStatus->Text = "Lost file sync!";
                                }
                                break;

                            case FILE_GET_SEGMENT_RESPONSE:
                                {
                                    unsigned char serialBuffer[FILE_SEGMENT_SIZE];/* serial out buffer */
                                    unsigned char *ptr = serialBuffer;
                                    
                                    std::fstream _file;/* file handle */
                            
                                    int uploadSize = (_incoming->getByte( 26 ) << 24)
                                                     | (_incoming->getByte( 27 ) << 16)
                                                     | (_incoming->getByte( 28 ) << 8)
                                                     | (_incoming->getByte( 29 ) << 0);
                                
                                    if (uploadSize != 0)
                                    {
                                        progress->PerformStep();
                                    
                                
                                        /* Write to file */
	                                    
                                        /* Retrieve file name */
                                        char longName[MAX_NAME_SIZE];/* to buffer file names */
                                        int nameSize = fileName->Text->Length;
                                        for (int i = 0; i < nameSize; ++i )
                                        {
                                            longName[i] = (char)fileName->Text[i];
                                        }
                                        longName[nameSize] = '\0';
                                        
                                        
                                        /* Get the segment content */
                                        for (int i = 0; i < uploadSize; ++i )
                                        {
                                            *ptr = _incoming->getByte( 30 + i );
                                            ++ptr;
                                        }
                                        
                                        /* Write it to file */
                                        _file.open( longName, std::fstream::out | std::fstream::binary | std::fstream::app );
                                        if (_file.fail() != true)
                                        {
                                            if ((_filePosition + uploadSize) > _fileEnd)
                                            {
                                                /* Only take what we need */
                                                uploadSize = _fileEnd - _filePosition;
                                            }
                                            
                                            if (_filePosition < (int)_file.tellg())
                                            {
                                                _file.seekg( 0, std::ios_base::beg );
                                            }
                                            
                                            _file.write( (char *)serialBuffer, uploadSize );
                                        
                                            _file.close();
                                        
                                            _filePosition += uploadSize;
                                
                                            if (_filePosition < _fileEnd)
                                            {
                                                getFileSegment();
                                            }
                                            else
                                            {
                                                newFrame = false;
                                                downloadStatus->Text = "Done";
                                            }
                                        }
                                        else
                                        {
                                            newFrame = false;
                                            downloadStatus->Text = "File Error";
                                        }
                                
                                
                                    }
                                    else
                                    {
                                        newFrame = false;
                                        downloadStatus->Text = "No file or address";
                                    }
                                }
                                break;

                            case FILE_LIST_RESPONSE:
                            {
                                int length = _incoming->payloadLength() / 4;
                                
                                for (int i = 0; i < length; ++i)
                                {
                                    int offset = i * 4;
                                    
                                    int date = (_incoming->getByte( 9 + offset) << 24)
                                               | (_incoming->getByte( 10 + offset) << 16)
                                               | (_incoming->getByte( 11 + offset) << 8)
                                               | (_incoming->getByte( 12 +offset) << 0);
                                
                                    
                                    uploadInfo->Text = String::Concat( uploadInfo->Text, String::Format( "{0}", date ) );
                                    uploadInfo->Text = String::Concat( uploadInfo->Text, gcnew String( "\x0d\x0a" ) );

                                }
                                
                                newFrame = false;
                                downloadStatus->Text = "List done";
                            }
                                
                                break;
                        
                        
                            case FILE_DETAIL_RESPONSE:
                                
                                char fileName[13];
                                for (int i = 0; i < 13; ++i)
                                {
                                    fileName[i] = (unsigned char)_incoming->getByte( 9 + i );
                                }
                                
                                String ^temp = gcnew String( fileName );
                                
                                uploadInfo->Text = String::Concat( uploadInfo->Text, temp );
                                uploadInfo->Text = String::Concat( uploadInfo->Text, gcnew String( "\x0d\x0a" ) );
                                
                                if (_incoming->getByte( 22 ) == 0)
                                {
                                    for (int i = 0; i < 24; ++i)
                                    {
                                        int offset = i * 4;
                                    
                                        int position = (_incoming->getByte( 23 + offset) << 24)
                                                   | (_incoming->getByte( 24 + offset) << 16)
                                                   | (_incoming->getByte( 25 + offset) << 8)
                                                   | (_incoming->getByte( 26 +offset) << 0);
                                
                                    
                                        uploadInfo->Text = String::Concat( uploadInfo->Text, String::Format( "{0}", position ) );
                                        uploadInfo->Text = String::Concat( uploadInfo->Text, gcnew String( "\x0d\x0a" ) );
                                    }

                                    downloadStatus->Text = "Detail done";
                                }
                                else
                                {
                                    downloadStatus->Text = "Detail failure";
                                }
                                
                                
                                newFrame = false;
                                
                                break;
                        }
                        break;
                    }
                }
            }
        }
        else
        {
            newFrame = false;
            downloadStatus->Text = "No response!";
        }
        
        if (newFrame == false)
        {
            progress->Visible = false;
        }
    }
    
}


private: System::Void browseButton_Click(System::Object^  sender, System::EventArgs^  e)
{
    openFile->Filter = "Apps(*.bin)|*.bin|Install(*.bn)|*.bn|Presets(*.txt)|*.txt|Language(*.lan)|*.lan|Font(*.fnt)|*.fnt|Other(*.*)|*.*";
    openFile->ShowDialog();
    if (_isFileSelected == true)
    {
        fileName->Text = openFile->FileName;
        downloadButton->Visible = true;
        fileSize->Visible = true;
        fileSizeLabel->Visible = true;
        fileSize->Text = "0";
        downloadStatus->Text = "Ready";
    }
}


private: System::Void serialTimer_Tick(System::Object^  sender, System::EventArgs^  e)
{

    String ^result = _serialComms->outFsm();
    
    if (result != "")
    {
        connectStatus->Text = result;
    }
    
    _serialComms->inFsm();

    receiveResponse();


    if (trackerConnected != _serialComms->isConnected())
    {
        trackerConnected = _serialComms->isConnected();
    
        setView( trackerConnected != BG::CONNECTED ? false : true );
    }

    ++_pollTick;
}


void setView( bool onOff )
{
    switch (trackerConnected)
    {
        case BG::DISCONNECTED:
            connectButton->Text = "Connect";
            connectStatus->Text = "";
            scanList->Items->Clear();
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
    
    downloadButton->Visible = onOff;
    fileSize->Visible = onOff;
    fileSizeLabel->Visible = onOff;
    progress->Visible = onOff;
    fileName->Visible = onOff;
    fileNameLabel->Visible = onOff;
    browseButton->Visible = onOff;
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


    downloadStatus->Text = "Wait . . .";
    _pollRef = _pollTick;
    _sendFrameStart = _serialComms->timeReference();
    newFrame = true;
    _incoming->reset();
}


void getFilename( char * serialBuffer, int size )
{
	char longName[MAX_NAME_SIZE];/* to buffer file names */

    memset( serialBuffer, 0U, size );
    
    int nameSize = fileName->Text->Length;
    for (int i = 0; i < nameSize; ++i )
    {
        longName[i] = (char)fileName->Text[i];
    }
    longName[nameSize] = '\0';
  
    if (nameSize <= MAX_SHORT_NAME_SIZE)
    {
        strcpy_s( serialBuffer, MAX_SHORT_NAME_SIZE + 1, longName );
    }
}    


private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
{
    btoothDevices->Clear();
}

void log( String ^msg )
{
    String ^newline = gcnew String( "\x0d\x0a" );
    btoothDevices->AppendText( newline );
    btoothDevices->AppendText( msg );
}


private: System::Void installButton_Click(System::Object^  sender, System::EventArgs^  e)
{
    YbMessage ^msg = gcnew YbMessage( macText->Text, 2, YbMessage::ACTION_TYPE_VALUE );

    int length = msg->frameLength();
    array<unsigned char>^ buffer = gcnew array<unsigned char>( length );
    for (int i = 0; i < length; ++i)
    {
        buffer[i] = msg->getByte(i);
    }
    
    _serialComms->write( buffer, length );

            _pollRef = _pollTick;
            _sendFrameStart = _serialComms->timeReference();
            _incoming->reset();
            downloadStatus->Text = "Wait . . .";
}

private: System::Void scanList_DoubleClick(System::Object^  sender, System::EventArgs^  e)
{
    if ((scanList->Items->Count != 0) && (trackerConnected == BG::SCANNING))
    {
        _serialComms->connectToSelected();
    }
}



private: System::Void uploadListButton_Click(System::Object^  sender, System::EventArgs^  e)
{
    int date;
    int day;
    int month;
    int year;
    int range;

    range = Convert::ToInt32( listRange->Text );
    date = Convert::ToInt32( fileName->Text );

    day = date % 100;
    date /= 100;
    month = date % 100;
    date /= 100;
    year = date % 100;

    YbMessage ^msg = gcnew YbMessage( macText->Text, YbMessage::FRAME_MIN_DATA_LEN + FILE_LIST_PAYLOAD_SZ, FILE_LIST_COMMAND );
    msg->addByte( (unsigned char)year );
    msg->addByte( (unsigned char)month );
    msg->addByte( (unsigned char)day );
    msg->addByte( (unsigned char)range );
    msg->addChecksum();

    sendFrame( msg );

    uploadInfo->Clear();
}

private: System::Void uploadSegmentsButton_Click(System::Object^  sender, System::EventArgs^  e)
{
    unsigned char serialBuffer[FILE_SEGMENT_NAME_SZ];/* serial out buffer */
    getFilename( (char *)serialBuffer, FILE_SEGMENT_NAME_SZ );

    YbMessage ^msg = gcnew YbMessage( macText->Text, FILE_DETAIL_COMMAND, serialBuffer, FILE_DETAIL_PAYLOAD_SZ );

    sendFrame( msg );

    uploadInfo->Clear();
}



private: System::Void testButton_Click(System::Object^  sender, System::EventArgs^  e)
{

    unsigned char serialBuffer[FILE_SEGMENT_NAME_SZ];/* serial out buffer */
    getFilename( (char *)serialBuffer, FILE_SEGMENT_NAME_SZ );

    YbMessage ^msg = gcnew YbMessage( macText->Text, FILE_DETAIL_COMMAND, serialBuffer, FILE_DETAIL_PAYLOAD_SZ );

    sendFrame( msg );

    uploadInfo->Clear();

    _filePosition = Convert::ToInt32( uploadPosition->Text );
    _fileEnd =  Convert::ToInt32( uploadSize->Text );
    _endOfFile = false;
    getFileSegment();
    getFileSegment();
}




};

}

