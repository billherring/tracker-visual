#pragma once

#include "ble.h"

namespace Terminal {

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
            trackerConnected = BG::DISCONNECTED;
            
            setView( false );
            _serialComms = gcnew Ble( commsLog);

            serialTimer->Interval = 5;
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
	private: System::Windows::Forms::TextBox^  textStream;
	protected: 

	protected: 
	private: System::Windows::Forms::TextBox^  portNumber;
	private: System::Windows::Forms::Button^  connectButton;
	private: System::Windows::Forms::Label^  connectStatus;
	private: System::Windows::Forms::TextBox^  commsLog;
	private: System::Windows::Forms::Button^  logButton;
	private: System::Windows::Forms::Button^  sendButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
        int trackerConnected;
        Ble ^_serialComms;
	private: System::Windows::Forms::Timer^  serialTimer;
	private: System::ComponentModel::IContainer^  components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->textStream = (gcnew System::Windows::Forms::TextBox());
			this->portNumber = (gcnew System::Windows::Forms::TextBox());
			this->connectButton = (gcnew System::Windows::Forms::Button());
			this->connectStatus = (gcnew System::Windows::Forms::Label());
			this->commsLog = (gcnew System::Windows::Forms::TextBox());
			this->logButton = (gcnew System::Windows::Forms::Button());
			this->sendButton = (gcnew System::Windows::Forms::Button());
			this->serialTimer = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// textStream
			// 
			this->textStream->Location = System::Drawing::Point(62, 96);
			this->textStream->Multiline = true;
			this->textStream->Name = L"textStream";
			this->textStream->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textStream->Size = System::Drawing::Size(447, 363);
			this->textStream->TabIndex = 0;
			// 
			// portNumber
			// 
			this->portNumber->Location = System::Drawing::Point(62, 25);
			this->portNumber->Name = L"portNumber";
			this->portNumber->Size = System::Drawing::Size(32, 20);
			this->portNumber->TabIndex = 1;
			// 
			// connectButton
			// 
			this->connectButton->Location = System::Drawing::Point(139, 25);
			this->connectButton->Name = L"connectButton";
			this->connectButton->Size = System::Drawing::Size(82, 24);
			this->connectButton->TabIndex = 2;
			this->connectButton->Text = L"Connect";
			this->connectButton->UseVisualStyleBackColor = true;
			this->connectButton->Click += gcnew System::EventHandler(this, &Form1::connectButton_Click);
			// 
			// connectStatus
			// 
			this->connectStatus->AutoSize = true;
			this->connectStatus->Location = System::Drawing::Point(263, 25);
			this->connectStatus->Name = L"connectStatus";
			this->connectStatus->Size = System::Drawing::Size(73, 13);
			this->connectStatus->TabIndex = 3;
			this->connectStatus->Text = L"Disconnected";
			// 
			// commsLog
			// 
			this->commsLog->Location = System::Drawing::Point(595, 319);
			this->commsLog->Multiline = true;
			this->commsLog->Name = L"commsLog";
			this->commsLog->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->commsLog->Size = System::Drawing::Size(122, 127);
			this->commsLog->TabIndex = 4;
			// 
			// logButton
			// 
			this->logButton->Location = System::Drawing::Point(633, 461);
			this->logButton->Name = L"logButton";
			this->logButton->Size = System::Drawing::Size(84, 20);
			this->logButton->TabIndex = 5;
			this->logButton->Text = L"Show Log";
			this->logButton->UseVisualStyleBackColor = true;
			this->logButton->Click += gcnew System::EventHandler(this, &Form1::logButton_Click);
			// 
			// sendButton
			// 
			this->sendButton->Location = System::Drawing::Point(604, 96);
			this->sendButton->Name = L"sendButton";
			this->sendButton->Size = System::Drawing::Size(62, 25);
			this->sendButton->TabIndex = 6;
			this->sendButton->Text = L"Send";
			this->sendButton->UseVisualStyleBackColor = true;
			this->sendButton->Click += gcnew System::EventHandler(this, &Form1::sendButton_Click);
			// 
			// serialTimer
			// 
			this->serialTimer->Tick += gcnew System::EventHandler(this, &Form1::serialTimer_Tick);
			// 
			// Form1
			// 
			this->AcceptButton = this->sendButton;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(738, 520);
			this->Controls->Add(this->sendButton);
			this->Controls->Add(this->logButton);
			this->Controls->Add(this->commsLog);
			this->Controls->Add(this->connectStatus);
			this->Controls->Add(this->connectButton);
			this->Controls->Add(this->portNumber);
			this->Controls->Add(this->textStream);
			this->Name = L"Form1";
			this->Text = L"Form1";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void connectButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        if (portNumber->Text != "")
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
            connectStatus->Text = "Need port number";
        }
	}
    
    
    private: System::Void logButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
            commsLog->Visible = !commsLog->Visible;
            logButton->Text = commsLog->Visible == false ? "Show Log" : "Hide Log";
    }


    private: System::Void sendButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        int length = textStream->Lines->Length;
        array<String^>^ tempArray = gcnew array<String^>( length );
        tempArray = textStream->Lines;

        String^ out = gcnew String( "" );
        out = tempArray[length -1];

        String ^newline = gcnew String( "\x0d\x0a" );
        textStream->AppendText( newline );
        out = String::Concat( out, newline );

        length = out->Length;
        array<char>^ buffer = gcnew array<char>( length );
        for (int i = 0; i < length; ++i)
        {
            buffer[i] = (char)out[i];
        }

        _serialComms->writeTerminal( buffer, length );
    }


    private: System::Void serialTimer_Tick(System::Object^  sender, System::EventArgs^  e)
    {
        int length = _serialComms->terminalWaiting();
        
        
        if (length != 0)
        {
            array<char>^ buffer = gcnew array<char>( length );
            _serialComms->readTerminal( buffer, length );
            String^ in = gcnew String( "" );

            for (int i = 0; i < length; ++i )
            {
                char letter[2];
                char byte = (char)buffer[i];
                letter[0] = (char)byte;
                letter[1] = '\0';
                String ^temp = gcnew String( &letter[0] );
                in = String::Concat( in, temp );
            }

            
            textStream->AppendText( in );
        }
     

        String ^result = _serialComms->outFsm();
        if (result != "")
        {
            connectStatus->Text = result;
        }

        (void)_serialComms->inFsm();

        
        if (trackerConnected != _serialComms->isConnected())
        {
            trackerConnected = _serialComms->isConnected();
            
            setView( trackerConnected != BG::CONNECTED ? false : true );
        }
    }


    private: void setView( bool onOff )
    {
        switch (trackerConnected)
        {
            case BG::DISCONNECTED:
                connectButton->Text = "Connect";
                connectStatus->Text = "";
                break;
            case BG::SCANNING:
                connectButton->Text = "Stop Scan";
                connectStatus->Text = "Scanning";
                break;
            case BG::CONNECTED:
                connectButton->Text = "Disconnect";
                connectStatus->Text = "Ready";
                break;
        }
        
//        textStream->Enabled = onOff;
    }
};
}

