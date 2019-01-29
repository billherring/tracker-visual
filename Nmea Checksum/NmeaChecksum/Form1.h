#pragma once
#include <cstdio>
#include <String>

namespace NmeaChecksum {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
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
	private: System::Windows::Forms::Button^  checksumButton;
	private: System::Windows::Forms::TextBox^  sentenceBox;
	protected: 

	protected: 

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  resultLabel;
	private: System::Windows::Forms::Button^  button1;
	private: System::IO::FileSystemWatcher^  fileSystemWatcher1;

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
			this->checksumButton = (gcnew System::Windows::Forms::Button());
			this->sentenceBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->resultLabel = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->fileSystemWatcher1 = (gcnew System::IO::FileSystemWatcher());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileSystemWatcher1))->BeginInit();
			this->SuspendLayout();
			// 
			// checksumButton
			// 
			this->checksumButton->Location = System::Drawing::Point(215, 199);
			this->checksumButton->Name = L"checksumButton";
			this->checksumButton->Size = System::Drawing::Size(66, 23);
			this->checksumButton->TabIndex = 0;
			this->checksumButton->Text = L"Checksum";
			this->checksumButton->UseVisualStyleBackColor = true;
			this->checksumButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// sentenceBox
			// 
			this->sentenceBox->Location = System::Drawing::Point(72, 81);
			this->sentenceBox->Name = L"sentenceBox";
			this->sentenceBox->Size = System::Drawing::Size(488, 20);
			this->sentenceBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(69, 65);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(111, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Enter nmea sentence:";
			// 
			// resultLabel
			// 
			this->resultLabel->AutoSize = true;
			this->resultLabel->Location = System::Drawing::Point(69, 135);
			this->resultLabel->Name = L"resultLabel";
			this->resultLabel->Size = System::Drawing::Size(13, 13);
			this->resultLabel->TabIndex = 3;
			this->resultLabel->Text = L"0";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(312, 199);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(58, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Fletcher";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click_1);
			// 
			// fileSystemWatcher1
			// 
			this->fileSystemWatcher1->EnableRaisingEvents = true;
			this->fileSystemWatcher1->SynchronizingObject = this;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(596, 262);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->resultLabel);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->sentenceBox);
			this->Controls->Add(this->checksumButton);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->fileSystemWatcher1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
			 {
				 char result[10];
				 int length = sentenceBox->Text->Length;
				 char sum = 0;

				 for (int i = 0; i < length; ++i)
				 {
					 sum ^= sentenceBox->Text[i];
				 }
				 char upper = (sum >> 4) & 0x0f;
				 upper +=  (upper < 10) ? '0' : 'a' - 0x0a;
				 result[0] = upper;
				 
				 char lower = sum & 0x0f;
				 lower +=  (lower < 10) ? '0' : 'a' - 0x0a;
				 result[1] = lower;
				 
				 result[2] = 0;
				 
				 String^ check = gcnew String( &result[0] );
				 resultLabel->Text = check;
			 }

    private: System::Void button1_Click_1(System::Object^  sender, System::EventArgs^  e)
    {
	    char result[10];
	    int length = sentenceBox->Text->Length;
	    char sumA = 0;
	    char sumB = 0;

	    for (int i = 0; i < length / 2; ++i)
	    {
            char byte = 0;
            
            for (int j = 0; j < 2; ++j)
            {
                char character = (char)sentenceBox->Text[(i * 2) + j];
                if (character >= 'A')
                {
                    character -= 'A';
                    character += 10;
                }
                else
                {
                    character -= '0';
                }
                
                byte <<= 4;
                byte |= character;
            }
            
            sumA += byte;
            sumB += sumA;
	    }
        
	    char digit;
	    
        digit = (sumA >> 4) & 0x0f;
	    digit +=  (digit < 10) ? '0' : 'A' - 10;
	    result[0] = digit;
	    
	    digit = sumA & 0x0f;
	    digit +=  (digit < 10) ? '0' : 'A' - 10;
	    result[1] = digit;
	    
	    digit = (sumB >> 4) & 0x0f;
	    digit +=  (digit < 10) ? '0' : 'A' - 10;
	    result[2] = digit;
	    
	    digit = sumB & 0x0f;
	    digit +=  (digit < 10) ? '0' : 'A' - 10;
	    result[3] = digit;
	    
	    result[4] = 0;
	    
	    String^ check = gcnew String( &result[0] );
	    resultLabel->Text = check;
	}
    
};

}