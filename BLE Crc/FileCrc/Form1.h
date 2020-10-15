#pragma once

#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>

namespace FileCrc
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

    const int CHUNK_SIZE_BYTES = 256;/* */
    const int MAX_NAME_SIZE = 100;/* */
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
	private: System::Windows::Forms::OpenFileDialog^  openFile;
	private: System::Windows::Forms::TextBox^  fileName;
	private: System::Windows::Forms::Button^  browseButton;
	private: System::Windows::Forms::Button^  goButton;
	protected: 

	private:
		/// <summary>
		/// Required designer variable.
    	private: bool _isFileSelected;
	private: System::Windows::Forms::Label^  status;

			 /// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFile = (gcnew System::Windows::Forms::OpenFileDialog());
			this->fileName = (gcnew System::Windows::Forms::TextBox());
			this->browseButton = (gcnew System::Windows::Forms::Button());
			this->goButton = (gcnew System::Windows::Forms::Button());
			this->status = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// openFile
			// 
			this->openFile->FileName = L"openFileDialog1";
			this->openFile->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFile_FileOk);
			// 
			// fileName
			// 
			this->fileName->Location = System::Drawing::Point(71, 72);
			this->fileName->Name = L"fileName";
			this->fileName->Size = System::Drawing::Size(395, 20);
			this->fileName->TabIndex = 0;
			// 
			// browseButton
			// 
			this->browseButton->Location = System::Drawing::Point(399, 98);
			this->browseButton->Name = L"browseButton";
			this->browseButton->Size = System::Drawing::Size(67, 24);
			this->browseButton->TabIndex = 1;
			this->browseButton->Text = L"Browse";
			this->browseButton->UseVisualStyleBackColor = true;
			this->browseButton->Click += gcnew System::EventHandler(this, &Form1::browseButton_Click);
			// 
			// goButton
			// 
			this->goButton->Location = System::Drawing::Point(399, 210);
			this->goButton->Name = L"goButton";
			this->goButton->Size = System::Drawing::Size(67, 22);
			this->goButton->TabIndex = 2;
			this->goButton->Text = L"Go";
			this->goButton->UseVisualStyleBackColor = true;
			this->goButton->Click += gcnew System::EventHandler(this, &Form1::goButton_Click);
			// 
			// status
			// 
			this->status->AutoSize = true;
			this->status->Location = System::Drawing::Point(72, 210);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(24, 13);
			this->status->TabIndex = 3;
			this->status->Text = L"Idle";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(578, 401);
			this->Controls->Add(this->status);
			this->Controls->Add(this->goButton);
			this->Controls->Add(this->browseButton);
			this->Controls->Add(this->fileName);
			this->Name = L"Form1";
			this->Text = L"File CRC Append";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	    private: System::Void openFile_FileOk(System::Object^  sender, System::ComponentModel::CancelEventArgs^  e)
        {
            _isFileSelected = true;
	    }
	    private: System::Void browseButton_Click(System::Object^  sender, System::EventArgs^  e)
        {
            openFile->Filter = "Apps(*.bin)|*.bin";
            openFile->ShowDialog();
            if (_isFileSelected == true)
            {
                fileName->Text = openFile->FileName;
            }
	    }
	    private: System::Void goButton_Click(System::Object^  sender, System::EventArgs^  e)
        {
	        char longName[MAX_NAME_SIZE];/* to buffer file names */
            std::fstream _fileIn;/* file handle */
            std::fstream _fileOut;/* file handle */

            if (_isFileSelected == true)
            {
                int nameSize = openFile->FileName->Length;
                for (int i = 0; i < nameSize; ++i )
                {
                    longName[i] = (char)openFile->FileName[i];
                }
                longName[nameSize] = '\0';
                
                _fileIn.open( longName, std::fstream::in | std::fstream::binary);
                if (_fileIn.fail() != true)
                {
                    char *ptr = strchr( longName, '.' );
                    if (ptr != 0)
                    {
                        ++ptr;
                        if (strcmp( ptr, "BIN" ) == 0)
                        {
                            strcpy_s( ptr, 3, "BN" );
                            _fileOut.open( longName, std::fstream::out | std::fstream::binary);
                            if (_fileOut.fail() != true)
                            {
                                unsigned short crc = 0U;
                                unsigned char stream[CHUNK_SIZE_BYTES];
                                int fileSize;
                                int posn = 0;
                
                                _fileIn.seekg( 0, std::ios_base::end ); 
                                fileSize = (int)_fileIn.tellg();
                                _fileIn.seekg( 0, std::ios_base::beg );

                                do
                                {
                                    int chunk = fileSize - 64 - posn;
                                    chunk = chunk > CHUNK_SIZE_BYTES ? CHUNK_SIZE_BYTES : chunk;
                                    _fileIn.read( (char *)stream, chunk );
                                    _fileOut.write( (char *)stream, chunk );
                                    crc = checksum( crc, stream, chunk );
                                    posn += chunk;
                                }
                                while( posn < (fileSize - 64));
//                                while( posn < fileSize );
                
                                    _fileIn.read( (char *)stream, 64 );
                                    _fileOut.write( (char *)stream, 64 );
                                _fileIn.close();

                                stream[0] = (unsigned char)crc;
                                stream[1] = (unsigned char)(crc >> 8);
                                _fileOut.write( (char *)stream, 2 );
                                _fileOut.close();

                                /* Isolate just the filename (without path) */
                                String ^msg = String::Format( "Created BN file and appended = {0:X4}", crc );
                                status->Text = msg;
                            }
                            else
                            {
                                status->Text = "Can't open output file!";
                            }
                        }
                        else
                        {
                            status->Text = "Not a bin file";
                        }
                    }
                    else
                    {
                        status->Text = "No extension";
                    }
                }
                else
                {
                    status->Text = "Can't open input file!";
                }
            }
            else
            {
                status->Text = "No file selected!";
            }
	    }
	
        unsigned short checksum( unsigned short sum, unsigned char *stream, int length )
        {
            while (length != 0)
            {
                unsigned short x; 

                x = ((sum >> 8) ^ *stream) & 0xff; 
                x ^= (x >> 4); 

                sum = (sum << 8) ^ (x << 12) ^ (x << 5) ^ x; 

                sum &= 0xffff;
                ++stream;
                --length;
            }

            return sum; 
        }

    };
}

