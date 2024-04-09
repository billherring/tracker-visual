#pragma once

#include <cstring>
#include <cstdio>
#include <cstdlib>

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

    const char numbersSet[] = "0123456789";
    const char lowercaseSet[] = "abcdefghijklmnopqrstuvwxyz";
    const char uppercaseSet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const char specialsSet[]= "+/!#()*?@;:";

    
    
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
            sizeBox->SelectedIndex = 10 - 6;
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

	private: System::Windows::Forms::Label^  hashText;


	private: System::Windows::Forms::Label^  label2;





	private: System::Windows::Forms::ComboBox^  sizeBox;
	private: System::Windows::Forms::ComboBox^  numbersBox;
	private: System::Windows::Forms::ComboBox^  specialsBox;




	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;


	private: System::Windows::Forms::Label^  numbersLabel;
	private: System::Windows::Forms::Label^  specialsLabel;







	private: System::Windows::Forms::ComboBox^  lowerCaseBox;
	private: System::Windows::Forms::Label^  lowerCaseLabel;

	private: System::Windows::Forms::ComboBox^  upperCaseBox;
	private: System::Windows::Forms::Label^  upperCaseLabel;
	private: System::Windows::Forms::CheckBox^  legacyCheck;
	private: System::Windows::Forms::CheckBox^  pinChexk;
	private: System::Windows::Forms::Label^  label1;











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
			this->hashText = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->sizeBox = (gcnew System::Windows::Forms::ComboBox());
			this->numbersBox = (gcnew System::Windows::Forms::ComboBox());
			this->specialsBox = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->numbersLabel = (gcnew System::Windows::Forms::Label());
			this->specialsLabel = (gcnew System::Windows::Forms::Label());
			this->lowerCaseBox = (gcnew System::Windows::Forms::ComboBox());
			this->lowerCaseLabel = (gcnew System::Windows::Forms::Label());
			this->upperCaseBox = (gcnew System::Windows::Forms::ComboBox());
			this->upperCaseLabel = (gcnew System::Windows::Forms::Label());
			this->legacyCheck = (gcnew System::Windows::Forms::CheckBox());
			this->pinChexk = (gcnew System::Windows::Forms::CheckBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// nameBox
			// 
			this->nameBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->nameBox->Location = System::Drawing::Point(49, 100);
			this->nameBox->Name = L"nameBox";
			this->nameBox->Size = System::Drawing::Size(321, 20);
			this->nameBox->TabIndex = 0;
			// 
			// hashButton
			// 
			this->hashButton->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hashButton->Location = System::Drawing::Point(49, 224);
			this->hashButton->Name = L"hashButton";
			this->hashButton->Size = System::Drawing::Size(97, 54);
			this->hashButton->TabIndex = 1;
			this->hashButton->Text = L"Get";
			this->hashButton->UseVisualStyleBackColor = true;
			this->hashButton->Click += gcnew System::EventHandler(this, &Form1::hashButton_Click);
			// 
			// keyBox
			// 
			this->keyBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->keyBox->Location = System::Drawing::Point(49, 167);
			this->keyBox->Name = L"keyBox";
			this->keyBox->Size = System::Drawing::Size(321, 20);
			this->keyBox->TabIndex = 2;
			// 
			// hashText
			// 
			this->hashText->AutoSize = true;
			this->hashText->Font = (gcnew System::Drawing::Font(L"Lucida Console", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->hashText->ForeColor = System::Drawing::Color::Red;
			this->hashText->Location = System::Drawing::Point(46, 37);
			this->hashText->Name = L"hashText";
			this->hashText->Size = System::Drawing::Size(105, 19);
			this->hashText->TabIndex = 4;
			this->hashText->Text = L"        ";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Lucida Console", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ControlText;
			this->label2->Location = System::Drawing::Point(46, 37);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 16);
			this->label2->TabIndex = 7;
			// 
			// sizeBox
			// 
			this->sizeBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->sizeBox->FormattingEnabled = true;
			this->sizeBox->Items->AddRange(gcnew cli::array< System::Object^  >(15) {
				L"6", L"7", L"8", L"9", L"10", L"11", L"12", L"13",
					L"14", L"15", L"16", L"17", L"18", L"19", L"20"
			});
			this->sizeBox->Location = System::Drawing::Point(320, 224);
			this->sizeBox->Name = L"sizeBox";
			this->sizeBox->Size = System::Drawing::Size(50, 21);
			this->sizeBox->TabIndex = 11;
			this->sizeBox->Text = L"6";
			// 
			// numbersBox
			// 
			this->numbersBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->numbersBox->FormattingEnabled = true;
			this->numbersBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Allow", L"Ensure", L"Exclude" });
			this->numbersBox->Location = System::Drawing::Point(49, 394);
			this->numbersBox->Name = L"numbersBox";
			this->numbersBox->Size = System::Drawing::Size(72, 21);
			this->numbersBox->TabIndex = 12;
			this->numbersBox->Text = L"Allow";
			// 
			// specialsBox
			// 
			this->specialsBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->specialsBox->FormattingEnabled = true;
			this->specialsBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Allow", L"Ensure", L"Exclude" });
			this->specialsBox->Location = System::Drawing::Point(49, 423);
			this->specialsBox->Name = L"specialsBox";
			this->specialsBox->Size = System::Drawing::Size(72, 21);
			this->specialsBox->TabIndex = 13;
			this->specialsBox->Text = L"Allow";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(46, 84);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(118, 13);
			this->label5->TabIndex = 17;
			this->label5->Text = L"Make password for:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(46, 151);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(118, 13);
			this->label6->TabIndex = 18;
			this->label6->Text = L"Provide secret text:";
			// 
			// numbersLabel
			// 
			this->numbersLabel->AutoSize = true;
			this->numbersLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->numbersLabel->Location = System::Drawing::Point(141, 394);
			this->numbersLabel->Name = L"numbersLabel";
			this->numbersLabel->Size = System::Drawing::Size(78, 13);
			this->numbersLabel->TabIndex = 21;
			this->numbersLabel->Text = L"Numbers 0-9";
			// 
			// specialsLabel
			// 
			this->specialsLabel->AutoSize = true;
			this->specialsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->specialsLabel->Location = System::Drawing::Point(142, 423);
			this->specialsLabel->Name = L"specialsLabel";
			this->specialsLabel->Size = System::Drawing::Size(55, 13);
			this->specialsLabel->TabIndex = 22;
			this->specialsLabel->Text = L"Specials";
			// 
			// lowerCaseBox
			// 
			this->lowerCaseBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->lowerCaseBox->FormattingEnabled = true;
			this->lowerCaseBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Allow", L"Ensure", L"Exclude" });
			this->lowerCaseBox->Location = System::Drawing::Point(49, 328);
			this->lowerCaseBox->Name = L"lowerCaseBox";
			this->lowerCaseBox->Size = System::Drawing::Size(72, 21);
			this->lowerCaseBox->TabIndex = 26;
			this->lowerCaseBox->Text = L"Allow";
			// 
			// lowerCaseLabel
			// 
			this->lowerCaseLabel->AutoSize = true;
			this->lowerCaseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->lowerCaseLabel->Location = System::Drawing::Point(141, 328);
			this->lowerCaseLabel->Name = L"lowerCaseLabel";
			this->lowerCaseLabel->Size = System::Drawing::Size(62, 13);
			this->lowerCaseLabel->TabIndex = 27;
			this->lowerCaseLabel->Text = L"Lower a-z";
			// 
			// upperCaseBox
			// 
			this->upperCaseBox->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(224)), static_cast<System::Int32>(static_cast<System::Byte>(224)),
				static_cast<System::Int32>(static_cast<System::Byte>(224)));
			this->upperCaseBox->FormattingEnabled = true;
			this->upperCaseBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Allow", L"Ensure", L"Exclude" });
			this->upperCaseBox->Location = System::Drawing::Point(49, 361);
			this->upperCaseBox->Name = L"upperCaseBox";
			this->upperCaseBox->Size = System::Drawing::Size(72, 21);
			this->upperCaseBox->TabIndex = 28;
			this->upperCaseBox->Text = L"Allow";
			// 
			// upperCaseLabel
			// 
			this->upperCaseLabel->AutoSize = true;
			this->upperCaseLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->upperCaseLabel->Location = System::Drawing::Point(141, 361);
			this->upperCaseLabel->Name = L"upperCaseLabel";
			this->upperCaseLabel->Size = System::Drawing::Size(65, 13);
			this->upperCaseLabel->TabIndex = 29;
			this->upperCaseLabel->Text = L"Upper A-Z";
			// 
			// legacyCheck
			// 
			this->legacyCheck->AutoSize = true;
			this->legacyCheck->Checked = true;
			this->legacyCheck->CheckState = System::Windows::Forms::CheckState::Checked;
			this->legacyCheck->Location = System::Drawing::Point(49, 501);
			this->legacyCheck->Name = L"legacyCheck";
			this->legacyCheck->Size = System::Drawing::Size(61, 17);
			this->legacyCheck->TabIndex = 30;
			this->legacyCheck->Text = L"Legacy";
			this->legacyCheck->UseVisualStyleBackColor = true;
			this->legacyCheck->Visible = false;
			// 
			// pinChexk
			// 
			this->pinChexk->AutoSize = true;
			this->pinChexk->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->pinChexk->Location = System::Drawing::Point(106, 469);
			this->pinChexk->Name = L"pinChexk";
			this->pinChexk->Size = System::Drawing::Size(15, 14);
			this->pinChexk->TabIndex = 31;
			this->pinChexk->UseVisualStyleBackColor = true;
			this->pinChexk->CheckedChanged += gcnew System::EventHandler(this, &Form1::pinChexk_CheckedChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(142, 469);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(77, 13);
			this->label1->TabIndex = 32;
			this->label1->Text = L"Fast PIN set";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(558, 548);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pinChexk);
			this->Controls->Add(this->legacyCheck);
			this->Controls->Add(this->upperCaseLabel);
			this->Controls->Add(this->upperCaseBox);
			this->Controls->Add(this->lowerCaseLabel);
			this->Controls->Add(this->lowerCaseBox);
			this->Controls->Add(this->specialsLabel);
			this->Controls->Add(this->numbersLabel);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->specialsBox);
			this->Controls->Add(this->numbersBox);
			this->Controls->Add(this->sizeBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->hashText);
			this->Controls->Add(this->keyBox);
			this->Controls->Add(this->hashButton);
			this->Controls->Add(this->nameBox);
			this->Name = L"Form1";
			this->Text = L"Kryptic";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

////////////////////////// Support Functions //////////////////////////////////
        private:
        
        private: void hash256( array<unsigned int>^ hash, String ^plainText )
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
            while (isBlock( i, plainText ))
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
                        W = plainWord32( i, j, plainText );
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
        private: unsigned int plainWord32( int block, int wordIndex, String ^plainText )
        {
            /* Padding = 1 x 0x80 + n x 0x00 (to 56 bytes) + 7 x 0x00 (binary length) + 1 x 0xLL (binary length) */
            int plainLength = plainText->Length;
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
                        word |= (unsigned char)plainText[posn];
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
        private: bool isBlock( int block, String ^plainText )
        {
            /* Padding = 1 x 0x80 + n x 0x00 (to 56 bytes) + 7 x 0x00 (binary length) + 1 x 0xLL (binary length) */
            int minLength = plainText->Length + 1 + 8;
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
        private: String^ hashToString( array<unsigned int>^ hash, int size, String^ characterSet )
        {
            String^ hashString = gcnew String("");
            int wordSize = legacyCheck->Checked == true ? 6 : 7;
            

            int h = 0;
            int temp = hash[h];
            int tempBits = 0;
            for (int i = 0; i < size; ++i)
            {
                unsigned int aWord = 0U;
                
                for (int j = 0; j < wordSize; ++j)
                {
                    aWord <<= 1;
                    aWord |= ((temp & 0x80000000) != 0U ? 1U : 0U);
                    temp <<= 1;
                    ++tempBits;
                    if (tempBits == 32)
                    {
                        ++h;
                        temp = hash[h];
                        tempBits = 0;
                    }
                }

                String ^ t;
                t = gcnew String( characterSet[(int)aWord % characterSet->Length], 1 );
                hashString = String::Concat( hashString, t );
            }

            return(hashString);
        }


        private: bool isNotCriteriaMet( String ^str )
        {
            return (    ((numbersBox->SelectedIndex == 1) && !isNumberInString( str )) ||
                        ((lowerCaseBox->SelectedIndex == 1) && !isLowerCaseInString( str )) ||
                        ((upperCaseBox->SelectedIndex == 1) && !isUpperCaseInString( str )) ||
                        ((specialsBox->SelectedIndex == 1) && !isSpecialInString( str ))   );
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
                if (strchr( specialsSet, str[i] ) != 0 )
                //if ((str[i] == '/') || (str[i] == '+'))
                {
                    break;
                }
            }
            
            return(i < str->Length);
        }
////////////////////////////////// End ////////////////////////////////////////


	    private: System::Void hashButton_Click(System::Object^  sender, System::EventArgs^  e)
        {
            String^ characterSet = gcnew String("");
            String^ numbers = gcnew String(numbersSet);
            String^ uppers = gcnew String(uppercaseSet);
            String^ lowers = gcnew String(lowercaseSet);
            String^ specials = gcnew String(specialsSet);
            hashText->Text = "";
         
            if (upperCaseBox->SelectedIndex != 2)
            {
                characterSet = String::Concat( characterSet, uppers );
            }
            if (lowerCaseBox->SelectedIndex != 2)
            {
                characterSet = String::Concat( characterSet, lowers );
            }
            if (numbersBox->SelectedIndex != 2)
            {
                characterSet = String::Concat( characterSet, numbers );
            }
            if (specialsBox->SelectedIndex != 2)
            {
                characterSet = String::Concat( characterSet, specials );
            }

            if (legacyCheck->Checked == false)
            {
                /* Increase likelihood of numbers and specials */
                if (numbersBox->SelectedIndex != 2)
                {
                    characterSet = String::Concat( characterSet, numbers );
                }
                if (specialsBox->SelectedIndex != 2)
                {
                    characterSet = String::Concat( characterSet, specials );
                }
            }

            String^ plainText = gcnew String("");
            String^ separatorString = gcnew String( "\\" );
            plainText = nameBox->Text;
            plainText = String::Concat( plainText, separatorString );
            plainText = String::Concat( plainText, keyBox->Text );

            array<unsigned int>^ hash = gcnew array<unsigned int>( 8 );
        
            
            int maxAttempts = 200;

            do
            {
                hash256( hash, plainText );

                hashText->Text = hashToString( hash, sizeBox->SelectedIndex + 6, characterSet );
                plainText = String::Concat( plainText, separatorString );
                --maxAttempts;
            }
            while((maxAttempts != 0) && isNotCriteriaMet( hashText->Text ));

            if (maxAttempts == 0)
            {
                hashText->Text = gcnew String("Error");
            }
	    }



        private: System::Void pinChexk_CheckedChanged(System::Object^  sender, System::EventArgs^  e)
        {
            if (pinChexk->Checked == true)
            {
                upperCaseBox->SelectedIndex = 2;
                lowerCaseBox->SelectedIndex = 2;
                numbersBox->SelectedIndex = 1;
                specialsBox->SelectedIndex = 2;
            }
            else
            {
                upperCaseBox->SelectedIndex = 0;
                lowerCaseBox->SelectedIndex = 0;
                numbersBox->SelectedIndex = 0;
                specialsBox->SelectedIndex = 0;
            }

        }
};



}
