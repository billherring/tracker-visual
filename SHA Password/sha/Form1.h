#pragma once


namespace sha {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

    const unsigned int K[] = 
    {
        0x428a2f98, 0x71374491, 0xb5c0fbcf, 0xe9b5dba5, 0x3956c25b, 0x59f111f1, 0x923f82a4, 0xab1c5ed5,
        0xd807aa98, 0x12835b01, 0x243185be, 0x550c7dc3, 0x72be5d74, 0x80deb1fe, 0x9bdc06a7, 0xc19bf174,
        0xe49b69c1, 0xefbe4786, 0x0fc19dc6, 0x240ca1cc, 0x2de92c6f, 0x4a7484aa, 0x5cb0a9dc, 0x76f988da,
        0x983e5152, 0xa831c66d, 0xb00327c8, 0xbf597fc7, 0xc6e00bf3, 0xd5a79147, 0x06ca6351, 0x14292967,
        0x27b70a85, 0x2e1b2138, 0x4d2c6dfc, 0x53380d13, 0x650a7354, 0x766a0abb, 0x81c2c92e, 0x92722c85,
        0xa2bfe8a1, 0xa81a664b, 0xc24b8b70, 0xc76c51a3, 0xd192e819, 0xd6990624, 0xf40e3585, 0x106aa070,
        0x19a4c116, 0x1e376c08, 0x2748774c, 0x34b0bcb5, 0x391c0cb3, 0x4ed8aa4a, 0x5b9cca4f, 0x682e6ff3,
        0x748f82ee, 0x78a5636f, 0x84c87814, 0x8cc70208, 0x90befffa, 0xa4506ceb, 0xbef9a3f7, 0xc67178f2,        
    };

    const char base64[] = " ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; 
    
    
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
			generateRadio->Checked = true;
            sizeBox->SelectedIndex = 10 - 6;
            _hashCount = 0;
            _continue = false;
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
	private: System::Windows::Forms::TextBox^  nameBox;
	protected: 

	private: System::Windows::Forms::Button^  hashButton;
	private: System::Windows::Forms::TextBox^  keyBox;
	private: System::Windows::Forms::Label^  plainText;
	private: System::Windows::Forms::Label^  hashText;

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;





	private: System::Windows::Forms::ComboBox^  sizeBox;
	private: System::Windows::Forms::ComboBox^  numbersBox;
	private: System::Windows::Forms::ComboBox^  specialsBox;
	private: System::Windows::Forms::RadioButton^  generateRadio;
	private: System::Windows::Forms::RadioButton^  recoverRadio;


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;

	private: System::Windows::Forms::Label^  numbersLabel;
	private: System::Windows::Forms::Label^  specialsLabel;
	private: System::Windows::Forms::Label^  appendLabel;






	private: System::Windows::Forms::ComboBox^  lowerCaseBox;
	private: System::Windows::Forms::Label^  lowerCaseLabel;

	private: System::Windows::Forms::ComboBox^  upperCaseBox;
	private: System::Windows::Forms::Label^  upperCaseLabel;


	private: System::Windows::Forms::TextBox^  hashCount;
	private: System::Windows::Forms::Label^  recoverKeyPrefix;

	private: System::Windows::Forms::Label^  recoverKeyLabel;




	protected: 

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
			this->nameBox = (gcnew System::Windows::Forms::TextBox());
			this->hashButton = (gcnew System::Windows::Forms::Button());
			this->keyBox = (gcnew System::Windows::Forms::TextBox());
			this->plainText = (gcnew System::Windows::Forms::Label());
			this->hashText = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->sizeBox = (gcnew System::Windows::Forms::ComboBox());
			this->numbersBox = (gcnew System::Windows::Forms::ComboBox());
			this->specialsBox = (gcnew System::Windows::Forms::ComboBox());
			this->generateRadio = (gcnew System::Windows::Forms::RadioButton());
			this->recoverRadio = (gcnew System::Windows::Forms::RadioButton());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->numbersLabel = (gcnew System::Windows::Forms::Label());
			this->specialsLabel = (gcnew System::Windows::Forms::Label());
			this->appendLabel = (gcnew System::Windows::Forms::Label());
			this->lowerCaseBox = (gcnew System::Windows::Forms::ComboBox());
			this->lowerCaseLabel = (gcnew System::Windows::Forms::Label());
			this->upperCaseBox = (gcnew System::Windows::Forms::ComboBox());
			this->upperCaseLabel = (gcnew System::Windows::Forms::Label());
			this->hashCount = (gcnew System::Windows::Forms::TextBox());
			this->recoverKeyPrefix = (gcnew System::Windows::Forms::Label());
			this->recoverKeyLabel = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// nameBox
			// 
			this->nameBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->nameBox->Location = System::Drawing::Point(129, 99);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(216, 20);
			this->nameBox->TabIndex = 0;
			this->nameBox->TextChanged += gcnew System::EventHandler(this, &Form1::nameBox_TextChanged);
			// 
			// hashButton
			// 
			this->hashButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->hashButton->Location = System::Drawing::Point(42, 320);
			this->hashButton->Name = L"hashButton";
			this->hashButton->Size = System::Drawing::Size(97, 69);
			this->hashButton->TabIndex = 1;
			this->hashButton->Text = L"Go";
			this->hashButton->UseVisualStyleBackColor = true;
			this->hashButton->Click += gcnew System::EventHandler(this, &Form1::hashButton_Click);
			// 
			// keyBox
			// 
			this->keyBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->keyBox->Location = System::Drawing::Point(129, 129);
			this->keyBox->Name = L"keyBox";
			this->keyBox->Size = System::Drawing::Size(401, 20);
			this->keyBox->TabIndex = 2;
			this->keyBox->TextChanged += gcnew System::EventHandler(this, &Form1::keyBox_TextChanged);
			// 
			// plainText
			// 
			this->plainText->AutoSize = true;
			this->plainText->Location = System::Drawing::Point(144, 32);
			this->plainText->Name = L"plainText";
			this->plainText->Size = System::Drawing::Size(25, 13);
			this->plainText->TabIndex = 3;
			this->plainText->Text = L"      ";
			this->plainText->Visible = false;
			// 
			// hashText
			// 
			this->hashText->AutoSize = true;
			this->hashText->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->hashText->ForeColor = System::Drawing::Color::Red;
			this->hashText->Location = System::Drawing::Point(141, 53);
			this->hashText->Name = L"hashText";
			this->hashText->Size = System::Drawing::Size(96, 16);
			this->hashText->TabIndex = 4;
			this->hashText->Text = L"        ";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(39, 32);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(66, 13);
			this->label1->TabIndex = 6;
			this->label1->Text = L"Master Text:";
			this->label1->Visible = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label2->Location = System::Drawing::Point(39, 55);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(96, 16);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Password";
			// 
			// sizeBox
			// 
			this->sizeBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->sizeBox->FormattingEnabled = true;
			this->sizeBox->Items->AddRange(gcnew cli::array< System::Object^  >(15) {L"6", L"7", L"8", L"9", L"10", L"11", L"12", L"13", 
				L"14", L"15", L"16", L"17", L"18", L"19", L"20"});
			this->sizeBox->Location = System::Drawing::Point(129, 158);
			this->sizeBox->Name = L"sizeBox";
			this->sizeBox->Size = System::Drawing::Size(50, 21);
			this->sizeBox->TabIndex = 11;
			this->sizeBox->Text = L"6";
			this->sizeBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::sizeBox_SelectedIndexChanged);
			// 
			// numbersBox
			// 
			this->numbersBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->numbersBox->FormattingEnabled = true;
			this->numbersBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Don\'t Care", L"Yes", L"No"});
			this->numbersBox->Location = System::Drawing::Point(42, 250);
			this->numbersBox->Name = L"numbersBox";
			this->numbersBox->Size = System::Drawing::Size(72, 21);
			this->numbersBox->TabIndex = 12;
			this->numbersBox->Text = L"Don\'t Care";
			this->numbersBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::numbersBox_SelectedIndexChanged);
			// 
			// specialsBox
			// 
			this->specialsBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->specialsBox->FormattingEnabled = true;
			this->specialsBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Don\'t Care", L"Yes", L"No"});
			this->specialsBox->Location = System::Drawing::Point(174, 250);
			this->specialsBox->Name = L"specialsBox";
			this->specialsBox->Size = System::Drawing::Size(72, 21);
			this->specialsBox->TabIndex = 13;
			this->specialsBox->Text = L"Don\'t Care";
			this->specialsBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::specialsBox_SelectedIndexChanged);
			// 
			// generateRadio
			// 
			this->generateRadio->AutoSize = true;
			this->generateRadio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->generateRadio->Location = System::Drawing::Point(164, 320);
			this->generateRadio->Name = L"generateRadio";
			this->generateRadio->Size = System::Drawing::Size(77, 17);
			this->generateRadio->TabIndex = 15;
			this->generateRadio->TabStop = true;
			this->generateRadio->Text = L"Generate";
			this->generateRadio->UseVisualStyleBackColor = true;
			this->generateRadio->CheckedChanged += gcnew System::EventHandler(this, &Form1::generateRadio_CheckedChanged);
			// 
			// recoverRadio
			// 
			this->recoverRadio->AutoSize = true;
			this->recoverRadio->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->recoverRadio->Location = System::Drawing::Point(164, 356);
			this->recoverRadio->Name = L"recoverRadio";
			this->recoverRadio->Size = System::Drawing::Size(73, 17);
			this->recoverRadio->TabIndex = 16;
			this->recoverRadio->TabStop = true;
			this->recoverRadio->Text = L"Recover";
			this->recoverRadio->UseVisualStyleBackColor = true;
			this->recoverRadio->CheckedChanged += gcnew System::EventHandler(this, &Form1::recoverRadio_CheckedChanged);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(39, 102);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(84, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Target Name:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(39, 132);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 13);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Secret:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(39, 161);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(35, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Size:";
			// 
			// numbersLabel
			// 
			this->numbersLabel->AutoSize = true;
			this->numbersLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->numbersLabel->Location = System::Drawing::Point(39, 234);
			this->numbersLabel->Name = L"numbersLabel";
			this->numbersLabel->Size = System::Drawing::Size(60, 13);
			this->numbersLabel->TabIndex = 21;
			this->numbersLabel->Text = L"Numbers:";
			// 
			// specialsLabel
			// 
			this->specialsLabel->AutoSize = true;
			this->specialsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->specialsLabel->Location = System::Drawing::Point(171, 234);
			this->specialsLabel->Name = L"specialsLabel";
			this->specialsLabel->Size = System::Drawing::Size(59, 13);
			this->specialsLabel->TabIndex = 22;
			this->specialsLabel->Text = L"Specials:";
			// 
			// appendLabel
			// 
			this->appendLabel->AutoSize = true;
			this->appendLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->appendLabel->Location = System::Drawing::Point(257, 358);
			this->appendLabel->Name = L"appendLabel";
			this->appendLabel->Size = System::Drawing::Size(36, 13);
			this->appendLabel->TabIndex = 23;
			this->appendLabel->Text = L"Index:";
			// 
			// lowerCaseBox
			// 
			this->lowerCaseBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lowerCaseBox->FormattingEnabled = true;
			this->lowerCaseBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Don\'t care", L"Yes", L"No"});
			this->lowerCaseBox->Location = System::Drawing::Point(304, 250);
			this->lowerCaseBox->Name = L"lowerCaseBox";
			this->lowerCaseBox->Size = System::Drawing::Size(72, 21);
			this->lowerCaseBox->TabIndex = 26;
			this->lowerCaseBox->Text = L"Don\'t care";
			this->lowerCaseBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::lowerCaseBox_SelectedIndexChanged);
			// 
			// lowerCaseLabel
			// 
			this->lowerCaseLabel->AutoSize = true;
			this->lowerCaseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->lowerCaseLabel->Location = System::Drawing::Point(301, 234);
			this->lowerCaseLabel->Name = L"lowerCaseLabel";
			this->lowerCaseLabel->Size = System::Drawing::Size(77, 13);
			this->lowerCaseLabel->TabIndex = 27;
			this->lowerCaseLabel->Text = L"Lower Case:";
			// 
			// upperCaseBox
			// 
			this->upperCaseBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->upperCaseBox->FormattingEnabled = true;
			this->upperCaseBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) {L"Don\'t Care", L"Yes", L"No"});
			this->upperCaseBox->Location = System::Drawing::Point(432, 250);
			this->upperCaseBox->Name = L"upperCaseBox";
			this->upperCaseBox->Size = System::Drawing::Size(81, 21);
			this->upperCaseBox->TabIndex = 28;
			this->upperCaseBox->Text = L"Don\'t Care";
			this->upperCaseBox->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::upperCaseBox_SelectedIndexChanged);
			// 
			// upperCaseLabel
			// 
			this->upperCaseLabel->AutoSize = true;
			this->upperCaseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->upperCaseLabel->Location = System::Drawing::Point(429, 234);
			this->upperCaseLabel->Name = L"upperCaseLabel";
			this->upperCaseLabel->Size = System::Drawing::Size(77, 13);
			this->upperCaseLabel->TabIndex = 29;
			this->upperCaseLabel->Text = L"Upper Case:";
			// 
			// hashCount
			// 
			this->hashCount->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)), 
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->hashCount->Location = System::Drawing::Point(305, 355);
			this->hashCount->Name = L"hashCount";
			this->hashCount->Size = System::Drawing::Size(52, 20);
			this->hashCount->TabIndex = 31;
			this->hashCount->TextChanged += gcnew System::EventHandler(this, &Form1::hashCount_TextChanged);
			// 
			// recoverKeyPrefix
			// 
			this->recoverKeyPrefix->AutoSize = true;
			this->recoverKeyPrefix->Location = System::Drawing::Point(373, 60);
			this->recoverKeyPrefix->Name = L"recoverKeyPrefix";
			this->recoverKeyPrefix->Size = System::Drawing::Size(85, 13);
			this->recoverKeyPrefix->TabIndex = 32;
			this->recoverKeyPrefix->Text = L"Recovery Index:";
			// 
			// recoverKeyLabel
			// 
			this->recoverKeyLabel->AutoSize = true;
			this->recoverKeyLabel->Location = System::Drawing::Point(464, 60);
			this->recoverKeyLabel->Name = L"recoverKeyLabel";
			this->recoverKeyLabel->Size = System::Drawing::Size(0, 13);
			this->recoverKeyLabel->TabIndex = 33;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 415);
			this->Controls->Add(this->recoverKeyLabel);
			this->Controls->Add(this->recoverKeyPrefix);
			this->Controls->Add(this->hashCount);
			this->Controls->Add(this->upperCaseLabel);
			this->Controls->Add(this->upperCaseBox);
			this->Controls->Add(this->lowerCaseLabel);
			this->Controls->Add(this->lowerCaseBox);
			this->Controls->Add(this->appendLabel);
			this->Controls->Add(this->specialsLabel);
			this->Controls->Add(this->numbersLabel);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->recoverRadio);
			this->Controls->Add(this->generateRadio);
			this->Controls->Add(this->specialsBox);
			this->Controls->Add(this->numbersBox);
			this->Controls->Add(this->sizeBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->hashText);
			this->Controls->Add(this->plainText);
			this->Controls->Add(this->keyBox);
			this->Controls->Add(this->hashButton);
			this->Controls->Add(this->nameBox);
			this->Name = L"Form1";
			this->Text = L"PASSWORD CENTER";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

////////////////////////// Support Functions //////////////////////////////////
        private:
            int _hashCount;
            bool _continue;
        
        private: void hash256( array<unsigned int>^ hash )
        {
            array<unsigned int>^ w = gcnew array<unsigned int>( 64 );
            
            hash[0] = 0x6a09e667;
            hash[1] = 0xbb67ae85;
            hash[2] = 0x3c6ef372;
            hash[3] = 0xa54ff53a;
            hash[4] = 0x510e527f;
            hash[5] = 0x9b05688c;
            hash[6] = 0x1f83d9ab;
            hash[7] = 0x5be0cd19;
            
            unsigned int aa;
            unsigned int bb;
            unsigned int cc;
            unsigned int dd;
            unsigned int ee;
            unsigned int ff;
            unsigned int gg;
            unsigned int hh;
            
            int i = 0;
            while (isBlock( i ))
            {
                aa = hash[0];
                bb = hash[1];
                cc = hash[2];
                dd = hash[3];
                ee = hash[4];
                ff =hash[5];
                gg = hash[6];
                hh = hash[7];
                
                for (int j = 0; j < 64; ++j)
                {
                    unsigned int W;
                    unsigned int T1;
                    unsigned int T2;
                    
                    if (j < 16)
                    {
                        W = plainWord32( i, j );
                    }
                    else
                    {
                        W = lsigma1( w[j - 2] ) + w[j - 7] + lsigma0( w[j - 15] ) + w[j - 16];
                    }
                    w[j] = W;
                    
                    T1 = hh + usigma1( ee ) + ch( ee, ff, gg) + K[j] + W;
                    T2 = usigma0( aa ) + maj( aa, bb, cc );
                    
                    hh = gg;
                    gg = ff;
                    ff = ee;
                    ee = dd + T1;
                    dd = cc;
                    cc = bb;
                    bb = aa;
                    aa = T1 + T2;
                }
                
                hash[0] = aa + hash[0];
                hash[1] = bb + hash[1];
                hash[2] = cc + hash[2];
                hash[3] = dd + hash[3];
                hash[4] = ee + hash[4];
                hash[5] = ff + hash[5];
                hash[6] = gg + hash[6];
                hash[7] = hh + hash[7];
                
                ++i;
            }
        }

        private: unsigned int usigma0( unsigned int x )
        {
            return (rotateRight( x, 2 ) ^ rotateRight( x, 13 ) ^ rotateRight( x, 22 ));
        }
        
        private: unsigned int usigma1( unsigned int x )
        {
            return (rotateRight( x, 6 ) ^ rotateRight( x, 11 ) ^ rotateRight( x, 25 ));
        }
        
        private: unsigned int lsigma0( unsigned int x )
        {
            return (rotateRight( x, 7 ) ^ rotateRight( x, 18 ) ^ (x >> 3));
        }
        
        private: unsigned int lsigma1( unsigned int x )
        {
            return (rotateRight( x, 17 ) ^ rotateRight( x, 19 ) ^ (x >> 10));
        }
        
        private: unsigned int ch( unsigned int x, unsigned int y, unsigned int z )
        {
            return ((x & y) ^ (((unsigned int)(~x)) & z));
        }
    
        private: unsigned int maj( unsigned int x, unsigned int y, unsigned int z )
        {
            return ((x & y) ^ (x & z) ^ (y & z));
        }

        /* Get plain word32 corrsponding to block and word index */
        private: unsigned int plainWord32( int block, int wordIndex )
        {
            /* Padding = 1 x 0x80 + n x 0x00 (to 56 bytes) + 7 x 0x00 (binary length) + 1 x 0xLL (binary length) */
            int plainLength = plainText->Text->Length;
            int minLength = plainLength + 1 + 8;
            int padding = (64 - (minLength % 64)) % 64;
            int totalLength = minLength + padding;
        
            int posn = (block * 64) + (wordIndex * 4);

            unsigned int word = 0U;
            if (posn < totalLength)
            {
                for (int i = 0; i < 4; ++i)
                {
                    word <<= 8;

                    if (posn < plainLength)
                    {
                        word |= (unsigned char)plainText->Text[posn];
                    }
                    else if (posn == plainLength)
                    {
                        word |= 0x80;
                    }
                    else if (posn < (totalLength - 2))
                    {
                        /* zero byte */
                    }
                    else if (posn < (totalLength - 1))
                    {
                        /* Length upper */
                        word |= (unsigned char)((plainLength * 8) >> 8);
                    }
                    else
                    {
                        /* Length lower */
                        word |= (unsigned char)(plainLength * 8);
                    }

                    ++posn;
                }
            }

            return(word);
        }


        /* Check if message is shorter than a specified block */
        private: bool isBlock( int block )
        {
            /* Padding = 1 x 0x80 + n x 0x00 (to 56 bytes) + 7 x 0x00 (binary length) + 1 x 0xLL (binary length) */
            int minLength = plainText->Text->Length + 1 + 8;
            int padding = (64 - (minLength % 64)) % 64;
            int totalLength = minLength + padding;
        
            int posn = (block * 64);
            return(posn == block);
        }


        /* Rotate a word32 */
        private: unsigned int rotateRight( unsigned int word, int shifts )
        {
            for (int i = 0; i < shifts; ++i)
            {
                bool odd = (word & 0x00000001) != 0U;
                word >>= 1;
                if (odd)
                {
                    word |= 0x80000000;
                }
            }
            return(word);
        }

        /* Convert hash array to base64 string */
        private: String^ hashToString( array<unsigned int>^ hash, int size )
        {
            String^ hashString = gcnew String("");
            
            int h = 0;
            int temp = hash[h];
            int tempBits = 0;
            for (int i = 0; i < size; ++i)
            {
                unsigned int word6 = 0U;
                
                for (int j = 0; j < 6; ++j)
                {
                    word6 <<= 1;
                    word6 |= ((temp & 0x80000000) != 0U ? 1U : 0U);
                    temp <<= 1;
                    ++tempBits;
                    if (tempBits == 32)
                    {
                        ++h;
                        temp = hash[h];
                        tempBits = 0;
                    }
                }
                
                String ^ t = gcnew String( base64[(int)word6 + 1], 1 );
                hashString = String::Concat( hashString, t );
            }

            return(hashString);
        }


        private: void reviewMasterText( void )
        {
            String^ separatorString = gcnew String( "\\" );
            plainText->Text = nameBox->Text;
            plainText->Text = String::Concat( plainText->Text, separatorString );
            plainText->Text = String::Concat( plainText->Text, keyBox->Text );
            
            
            if (recoverRadio->Checked)
            {
                if (hashCount->Text != "")
                {
                    plainText->Text = String::Concat( plainText->Text, separatorString );
                    recoverKeyLabel->Text = hashCount->Text;
                    plainText->Text = String::Concat( plainText->Text, recoverKeyLabel->Text );
                }
             
                numbersBox->Visible = false;
                numbersLabel->Visible = false;
                
                specialsBox->Visible = false;
                specialsLabel->Visible = false;

                hashCount->Visible = true;
                appendLabel->Visible = true;
                
                lowerCaseBox->Visible = false;
                upperCaseBox->Visible = false;
                lowerCaseLabel->Visible = false;
                upperCaseLabel->Visible = false;
                
                recoverKeyPrefix->Visible = false;
                recoverKeyLabel->Visible = false;
            }
            else
            {
                if (_hashCount != 0)
                {
                    plainText->Text = String::Concat( plainText->Text, separatorString );
                    recoverKeyLabel->Text = String::Format( "{0}", _hashCount );
                    plainText->Text = String::Concat( plainText->Text, recoverKeyLabel->Text );
                }
           
                numbersBox->Visible = true;
                numbersLabel->Visible = true;

                specialsBox->Visible = true;
                specialsLabel->Visible = true;

                hashCount->Visible = false;
                appendLabel->Visible = false;
                
                lowerCaseBox->Visible = true;
                upperCaseBox->Visible = true;
                lowerCaseLabel->Visible = true;
                upperCaseLabel->Visible = true;

                recoverKeyPrefix->Visible = (_hashCount != 0) ? true : false;
                recoverKeyLabel->Visible = (_hashCount != 0) ? true : false;
            }
            
            hashButton->Text = (_continue == false) ? "Go" : "Continue";
            
        }


        private: void resetView( void )
        {
            _hashCount = 0;
            _continue = false;
            hashCount->Text = "";
            plainText->Text = "";
            hashText->Text = "";
            reviewMasterText();
        }
        

        private: bool isCriteriaMet( String ^str )
        {
            bool success = true;
            
            switch (numbersBox->SelectedIndex)
            {
                case 1:
                    if (!isNumberInString( str ))
                    {
                        success = false;
                    }
                    break;
                case 2:
                    if (isNumberInString( str ))
                    {
                        success = false;
                    }
                    break;
                default:
                    break;
            }
        
            switch (specialsBox->SelectedIndex)
            {
                case 1:
                    if (!isSpecialInString( str ))
                    {
                        success = false;
                    }
                    break;
                case 2:
                    if (isSpecialInString( str ))
                    {
                        success = false;
                    }
                    break;
                default:
                    break;
            }
        
        
            switch (lowerCaseBox->SelectedIndex)
            {
                case 1:
                    if (!isLowerCaseInString( str ))
                    {
                        success = false;
                    }
                    break;
                case 2:
                    if (isLowerCaseInString( str ))
                    {
                        success = false;
                    }
                    break;
                default:
                    break;
            }
        
        
            switch (upperCaseBox->SelectedIndex)
            {
                case 1:
                    if (!isUpperCaseInString( str ))
                    {
                        success = false;
                    }
                    break;
                case 2:
                    if (isUpperCaseInString( str ))
                    {
                        success = false;
                    }
                    break;
                default:
                    break;
            }
        
        
            return(success);
        }
        
            
        private: bool isLowerCaseInString(String^ str)
        {
            int i;
            for (i = 0; i < str->Length; ++i)
            {
                if ((str[i] >= 'a') && (str[i] <= 'z'))
                {
                    break;
                }
            }
            
            return(i < str->Length);
        }
        
        
        private: bool isUpperCaseInString(String^ str)
        {
            int i;
            for (i = 0; i < str->Length; ++i)
            {
                if ((str[i] >= 'A') && (str[i] <= 'Z'))
                {
                    break;
                }
            }
            
            return(i < str->Length);
        }

        private: bool isNumberInString(String^ str)
        {
            int i;
            for (i = 0; i < str->Length; ++i)
            {
                if ((str[i] >= '0') && (str[i] <= '9'))
                {
                    break;
                }
            }
            
            return(i < str->Length);
        }
        
        
        private: bool isSpecialInString(String^ str)
        {
            int i;
            for (i = 0; i < str->Length; ++i)
            {
                if ((str[i] == '/') || (str[i] == '+'))
                {
                    break;
                }
            }
            
            return(i < str->Length);
        }
////////////////////////////////// End ////////////////////////////////////////


	    private: System::Void hashButton_Click(System::Object^  sender, System::EventArgs^  e)
        {
            recoverKeyLabel->Text = "";
            hashText->Text = "";
         
            if (plainText->Text->Length < 0x2000)
            {
                bool done = true;
                array<unsigned int>^ hash = gcnew array<unsigned int>( 8 );
            
                if (generateRadio->Checked)
                {
                    if (_continue == false)
                    {
                        _hashCount = 0;
                    }
                    done = false;
                }
                reviewMasterText();
                
                int count = 0;
                do
                {
                    hash256( hash );

                    hashText->Text = hashToString( hash, sizeBox->SelectedIndex + 6 );
                    if (generateRadio->Checked)
                    {
                        if (!isCriteriaMet( hashText->Text ))
                        {
                            ++_hashCount;
                            ++count;
                            reviewMasterText();
                        }
                        else
                        {
                            done = true;
                        }
                    }
                }
                while((!done) && (count < 1000));
                
                if (!done)
                {
                    hashText->Text = "Not found yet";
                    _continue = true;
                }
                else
                {
                    _continue = false;
                }
                
                reviewMasterText();
            }
            else
            {
                hashText->Text = "Too Long";
            }
	    }


        private: System::Void nameBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
        {
            resetView();
        }


        private: System::Void keyBox_TextChanged(System::Object^  sender, System::EventArgs^  e)
        {
            resetView();
        }
        
        
        private: System::Void generateRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
        {
            resetView();
        }
        
        
        private: System::Void recoverRadio_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
        {
            resetView();
        }
        
        private: System::Void hashCount_TextChanged(System::Object^  sender, System::EventArgs^  e)
        {
            reviewMasterText();
		}
        private: System::Void sizeBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
        {
            resetView();
		}
        private: System::Void numbersBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
        {
            resetView();
		}
        private: System::Void specialsBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
        {
            resetView();
		}
        private: System::Void lowerCaseBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
        {
            resetView();
		}
        private: System::Void upperCaseBox_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
        {
            resetView();
		}


};



}
