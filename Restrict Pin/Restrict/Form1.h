#pragma once
#include <cstring>
#include <String>
#include <string>

namespace Restrict {

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
	private: System::Windows::Forms::Button^  generateButton;
	protected: 
	private: System::Windows::Forms::Button^  clearButton;
	private: System::Windows::Forms::TextBox^  challengeText;
	private: System::Windows::Forms::TextBox^  resultText;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;

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
			this->generateButton = (gcnew System::Windows::Forms::Button());
			this->clearButton = (gcnew System::Windows::Forms::Button());
			this->challengeText = (gcnew System::Windows::Forms::TextBox());
			this->resultText = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// generateButton
			// 
			this->generateButton->Location = System::Drawing::Point(282, 166);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(75, 23);
			this->generateButton->TabIndex = 0;
			this->generateButton->Text = L"Get Code";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &Form1::generateButton_Click);
			// 
			// clearButton
			// 
			this->clearButton->Location = System::Drawing::Point(454, 166);
			this->clearButton->Name = L"clearButton";
			this->clearButton->Size = System::Drawing::Size(75, 23);
			this->clearButton->TabIndex = 1;
			this->clearButton->Text = L"Clear All";
			this->clearButton->UseVisualStyleBackColor = true;
			this->clearButton->Click += gcnew System::EventHandler(this, &Form1::clearButton_Click);
			// 
			// challengeText
			// 
			this->challengeText->Cursor = System::Windows::Forms::Cursors::SizeAll;
			this->challengeText->Location = System::Drawing::Point(102, 75);
			this->challengeText->Name = L"challengeText";
			this->challengeText->Size = System::Drawing::Size(133, 20);
			this->challengeText->TabIndex = 2;
			// 
			// resultText
			// 
			this->resultText->Location = System::Drawing::Point(102, 166);
			this->resultText->Name = L"resultText";
			this->resultText->ReadOnly = true;
			this->resultText->Size = System::Drawing::Size(133, 20);
			this->resultText->TabIndex = 3;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(99, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(55, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Screen ID";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(99, 150);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(32, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Code";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(634, 280);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->resultText);
			this->Controls->Add(this->challengeText);
			this->Controls->Add(this->clearButton);
			this->Controls->Add(this->generateButton);
			this->Name = L"Form1";
			this->Text = L"Yellowbrick Engineers code";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void generateButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
		char buffer[10];/* to buffer */
		int length = challengeText->Text->Length;
        for (int i = 0; i < length; ++i )
        {
            buffer[i] = (char)challengeText->Text[i];
        }
        buffer[length] = '\0';

        unsigned int challenge = atol( buffer );

        unsigned int result = (challenge * challenge) % 65521U;
        result = (result * challenge) % 65521U;
        sprintf( buffer, "%05u", result );
    	String^ msg = gcnew String( &buffer[0] );
        resultText->Text = msg;
	}
    
    
    private: System::Void clearButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        challengeText->Text = "";
        resultText->Text = "";
	}
};
}

