#pragma once
#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <list>
#include "pack.h"
#include "vertex.h"

const int MAX_ENTRY_SZ = 30;



const int LAT_DATUM = (90U * 100000U * 10U);/* x10 to match google position resolution */
const int LONG_DATUM = (180U * 100000U * 10U);

bool Vertex::orderByLatitude = true;



namespace geofence {

    using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
    using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/* Output file field structure */
    
    
    const int FILE_SIZE_SZ = 4;
    const int ID_SZ = 1;
    const int BEHAVIOUR_SZ = 1;
    const int VERTEX_COUNT_SZ = 2;


    const int LAT_LONG_SZ = 4;
    const int POINT_SZ = (LAT_LONG_SZ * 2);
    const int EDGE_SZ = (POINT_SZ * 2);
    
    const int EDGE_LOC_SZ = 4;
    const int EDGE_COUNT_SZ = 1;
    
    
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
            
            _packer = gcnew Pack();
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


	protected: 





	private: System::Windows::Forms::OpenFileDialog^  openFile;
	private: System::Windows::Forms::TextBox^  fileName;
	private: System::Windows::Forms::Button^  browseButton;
	private: System::Windows::Forms::Button^  convertButton;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;
        bool _isFileSelected;
        Pack ^_packer;
	private: System::Windows::Forms::TextBox^  fenceData;





	private: System::Windows::Forms::Label^  status;

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
			this->convertButton = (gcnew System::Windows::Forms::Button());
			this->status = (gcnew System::Windows::Forms::Label());
			this->fenceData = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// openFile
			// 
			this->openFile->FileName = L"openFileDialog1";
			this->openFile->FileOk += gcnew System::ComponentModel::CancelEventHandler(this, &Form1::openFile_FileOk);
			// 
			// fileName
			// 
			this->fileName->Location = System::Drawing::Point(35, 36);
			this->fileName->Name = L"fileName";
			this->fileName->Size = System::Drawing::Size(169, 20);
			this->fileName->TabIndex = 6;
			// 
			// browseButton
			// 
			this->browseButton->Location = System::Drawing::Point(35, 62);
			this->browseButton->Name = L"browseButton";
			this->browseButton->Size = System::Drawing::Size(54, 22);
			this->browseButton->TabIndex = 7;
			this->browseButton->Text = L"Browse";
			this->browseButton->UseVisualStyleBackColor = true;
			this->browseButton->Click += gcnew System::EventHandler(this, &Form1::browseButton_Click);
			// 
			// convertButton
			// 
			this->convertButton->Location = System::Drawing::Point(285, 36);
			this->convertButton->Name = L"convertButton";
			this->convertButton->Size = System::Drawing::Size(52, 21);
			this->convertButton->TabIndex = 8;
			this->convertButton->Text = L"Convert";
			this->convertButton->UseVisualStyleBackColor = true;
			this->convertButton->Click += gcnew System::EventHandler(this, &Form1::convertButton_Click);
			// 
			// status
			// 
			this->status->AutoSize = true;
			this->status->Location = System::Drawing::Point(419, 36);
			this->status->Name = L"status";
			this->status->Size = System::Drawing::Size(38, 13);
			this->status->TabIndex = 9;
			this->status->Text = L"Ready";
			// 
			// fenceData
			// 
			this->fenceData->Location = System::Drawing::Point(35, 205);
			this->fenceData->Multiline = true;
			this->fenceData->Name = L"fenceData";
			this->fenceData->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->fenceData->Size = System::Drawing::Size(1112, 195);
			this->fenceData->TabIndex = 10;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1159, 425);
			this->Controls->Add(this->fenceData);
			this->Controls->Add(this->status);
			this->Controls->Add(this->convertButton);
			this->Controls->Add(this->browseButton);
			this->Controls->Add(this->fileName);
			this->Name = L"Form1";
			this->Text = L"Form1";
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
            openFile->Filter = "Apps(*.csv)|*.csv";
            openFile->ShowDialog();
            if (_isFileSelected == true)
            {
                fileName->Text = openFile->FileName;
            }
            status->Text = "Ready";
    }

    private: System::Void convertButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
	        char longName[100];/* to buffer file names */
            fstream fileIn;/* file handle */
            fstream fileOut;/* file handle */

            if (_isFileSelected == true)
            {
                int nameSize = openFile->FileName->Length;
                for (int i = 0; i < nameSize; ++i )
                {
                    longName[i] = (char)openFile->FileName[i];
                }
                longName[nameSize] = '\0';
                
                char *ptr = strchr( longName, '.' );
                if (ptr != 0)
                {
                    ++ptr;
                    if (strcmp( ptr, "csv" ) == 0)
                    {
                        fileIn.open( longName, fstream::in | fstream::binary);
                        if (fileIn.fail() != true)
                        {
        
		                    int csvTextSize = 0;
		                    int csvTextIndex = 0;
                            int totalFences = 0;

                            char csvBuffer[1000];
                            unsigned char binBuffer[1000];
                            
                            fileIn.seekp( 0, ios_base::end );
                            csvTextSize = (int)fileIn.tellp();
            
		                    fileIn.seekp( 0, ios_base::beg );
		                    fileIn.read( csvBuffer, csvTextSize );
                            fileIn.close();

                            if (csvTextSize != 0)
                            {
                                //At this point:-
                                //csvBuffer is a buffer holding all the text read from the csv file.
                                //csvTextSize has the size in characters
                                //csvTextIndex will maintain the position in the buffer as conversion progresses
                                //totalFences counts fences discovered in file as conversion progresses


                                _packer->initialise( binBuffer );

                                fileOut.open( "fence.bin", fstream::out | fstream::binary | fstream::trunc);
                                
                                fenceData->Text = "";

                                int fileOutSizeNow = 0;
                                while (csvTextIndex < csvTextSize)
                                {
                                    /* Get a single fence */
                                    //This takes two parse passes - one to count vertices (without
                                    //outputting binary) and a second to actually output binary.
                                    Fence fenceMap;
                                    int vertices = 0;
    
                                    (void)parse( csvBuffer, csvTextSize, csvTextIndex, &vertices, &fenceMap );//1st (gets vertices)
                                    csvTextIndex = parse( csvBuffer, csvTextSize, csvTextIndex, &vertices, &fenceMap );//2nd (uses vertices)
    
                                    _packer->pad();

                                    
                                    std::list<Vertex>::iterator it1;
                                    std::list<Vertex>::iterator it2;
                                    std::list<Vertex>::iterator it3;
                                    
                                    /* Establish vertex links - assumes they are
                                       listed in circular order so each will pair
                                       with its pre link and with its post link.
                                       The preKey and postKey then represent an
                                       edge which is then ordered west to east */
                                    it1 = fenceMap.vertices.begin();
                                    it2 = fenceMap.vertices.end();
                                    --it2;
                                    it3 = fenceMap.vertices.begin();
                                    ++it3;
                                    while (it1 != fenceMap.vertices.end())
                                    {
                                        if ((*it2).longitude <= (*it3).longitude)
                                        {
                                            (*it1).preKey = (*it2).key;
                                            (*it1).postKey = (*it3).key;
                                        }
                                        else
                                        {
                                            (*it1).preKey = (*it3).key;
                                            (*it1).postKey = (*it2).key;
                                        }
                                        ++it1;
                                        ++it2;
                                        ++it3;
                                        if (it2 == fenceMap.vertices.end())
                                        {
                                            it2 = fenceMap.vertices.begin();
                                        }
                                        if (it3 == fenceMap.vertices.end())
                                        {
                                            it3 = fenceMap.vertices.begin();
                                        }
                                    }
                                    
                                    /* Sort by longitude from west to east in order
                                       to determine boundary box east & west */
                                    Vertex::orderByLatitude = false;
                                    fenceMap.vertices.sort();
                                    it1 = fenceMap.vertices.begin();
                                    int boxWest = (*it1).longitude;
                                    it1 = fenceMap.vertices.end();
                                    --it1;
                                    int boxEast = (*it1).longitude;
                                    
                                    /* Sort by latitude from south to north in order
                                       to determine boundary box north & south.
                                       This order is then retained */
                                    Vertex::orderByLatitude = true;
                                    fenceMap.vertices.sort();
                                    it1 = fenceMap.vertices.begin();
                                    int boxSouth = (*it1).latitude;
                                    it1 = fenceMap.vertices.end();
                                    --it1;
                                    int boxNorth = (*it1).latitude;
        
                                    /* Establish a lookup to cross reference the
                                       pre ordered vertex indexes to the post
                                       ordered vertex indexes. Used subsequently
                                       for re enumerating the indexes for
                                       consistency with new order*/ 
                                    unsigned int i = 0;

                                    it1 = fenceMap.vertices.begin();
                                    while (it1 != fenceMap.vertices.end())
                                    {
                                        it2 = fenceMap.vertices.begin();
                                        std::advance( it2, (*it1).key );
                                        (*it2).orderedKey = i;
                                        ++i;
                                        ++it1;
                                    }
                                    
                                    
                                    /* Re enumerate vertex links for the re ordered
                                       list so the new keys refer to the
                                       correct vertices in reordered S/N list */
                                    it1 = fenceMap.vertices.begin();
                                    while (it1 != fenceMap.vertices.end())
                                    {
                                        it2 = fenceMap.vertices.begin();
                                        
                                        std::advance( it2, (*it1).preKey );
                                        (*it1).preKey = (*it2).orderedKey;
                                        
                                        it2 = fenceMap.vertices.begin();
                                        std::advance( it2, (*it1).postKey );
                                        (*it1).postKey = (*it2).orderedKey;
                                        ++it1;
                                    }


                                    /* Make edge lists */
                                    Edge edge;
                                    unsigned int j = 0;
                                    it1 = fenceMap.vertices.begin();
                                    while (it1 != fenceMap.vertices.end())
                                    {
                                        /* Do edge 1 */
                                        it2 = fenceMap.vertices.begin();
                                        std::advance( it2, (*it1).preKey );
                                    
                                        if ((*it1).latitude < (*it2).latitude)
                                        {
                                            if ((*it1).longitude <= (*it2).longitude)
                                            {
                                                edge.vEast = j;
                                                edge.vWest = (*it1).preKey;
                                            }
                                            else
                                            {
                                                edge.vEast = (*it1).preKey;
                                                edge.vWest = j;
                                            }
                                            
                                            it2 = fenceMap.vertices.begin();
                                            std::advance( it2, edge.vEast );
                                            
                                            edge.latitudeEast = (*it2).latitude;
                                            edge.longitudeEast = (*it2).longitude;
                                            
                                            
                                            it2 = fenceMap.vertices.begin();
                                            std::advance( it2, edge.vWest );
                                            
                                            edge.latitudeWest = (*it2).latitude;
                                            edge.longitudeWest = (*it2).longitude;
                                            
                                            edge.baseLatitude = (*it1).latitude;

                                            (*it1).edges.push_back( edge );
                                        }

                                        /* Do edge 2 */
                                        it2 = fenceMap.vertices.begin();
                                        std::advance( it2, (*it1).postKey );
                                    
                                        if ((*it1).latitude < (*it2).latitude)
                                        {
                                            if ((*it1).longitude <= (*it2).longitude)
                                            {
                                                edge.vEast = j;
                                                edge.vWest = (*it1).postKey;
                                            }
                                            else
                                            {
                                                edge.vEast = (*it1).postKey;
                                                edge.vWest = j;
                                            }
                                            
                                            it2 = fenceMap.vertices.begin();
                                            std::advance( it2, edge.vEast );
                                            
                                            edge.latitudeEast = (*it2).latitude;
                                            edge.longitudeEast = (*it2).longitude;
                                            
                                            
                                            it2 = fenceMap.vertices.begin();
                                            std::advance( it2, edge.vWest );
                                            
                                            edge.latitudeWest = (*it2).latitude;
                                            edge.longitudeWest = (*it2).longitude;
                                            
                                            edge.baseLatitude = (*it1).latitude;

                                            (*it1).edges.push_back( edge );
                                        }
                                        
                                        /* Now take what is relevant from previous edge list */
                                        if (it1 != fenceMap.vertices.begin())
                                        {
                                            it2 = it1;
                                            --it2;
                                            
                                            if ((*it1).latitude != (*it2).latitude)
                                            {
                                                std::list<Edge>::iterator it4 = (*it2).edges.begin();
                                                while (it4 != (*it2).edges.end())
                                                {
                                                    if ( ((*it4).vEast != j)
                                                         && ((*it4).vWest) != j )
                                                    {
                                                        (*it1).edges.push_back( *it4 );
                                                    }
                                                    ++it4;
                                                }
                                            }
                                            else
                                            {
                                                /* Duplicate latitude (horizontal
                                                edge) so don't need previous vertex */
                                                fenceMap.vertices.erase( it2 );
                                            }
                                        }
                                        
                                        /* Finally sort the edges from west to east */
                                        (*it1).edges.sort();
                                        
                                        ++it1;
                                        ++j;
                                    }

                                    
                                    
                                    /* Report all the data */
                                    fenceData->Text = String::Concat( fenceData->Text, "Box " );
                                    
                                    String ^msg = String::Format( "{0} {1} {2} {3}""\x0d\x0a",
                                                                  boxNorth,
                                                                  boxSouth,
                                                                  boxEast,
                                                                  boxWest );
                                    
                                    fenceData->Text = String::Concat( fenceData->Text, msg );
		                            
                                    int totalOutSz = FILE_SIZE_SZ + ID_SZ +
                                                     BEHAVIOUR_SZ + EDGE_SZ +
                                                     VERTEX_COUNT_SZ +
                                                     ((LAT_LONG_SZ + EDGE_LOC_SZ + EDGE_COUNT_SZ) * fenceMap.vertexCount);
		                            
                                    it1 = fenceMap.vertices.begin();
                                    
                                    while (it1 != fenceMap.vertices.end())
                                    {
                                        totalOutSz += EDGE_SZ * (*it1).edges.size();
                                        ++it1;
                                    }
                                    
                                    fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, totalOutSz );
		                            fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, boxNorth );
		                            fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, boxSouth );
		                            fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, boxEast );
		                            fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, boxWest );
		                            fileOutSizeNow = writeOutFile8( &fileOut, fileOutSizeNow, binBuffer, fenceMap.id );
		                            fileOutSizeNow = writeOutFile8( &fileOut, fileOutSizeNow, binBuffer, fenceMap.behaviour );
		                            fileOutSizeNow = writeOutFile16( &fileOut, fileOutSizeNow, binBuffer, fenceMap.vertexCount );
                                    
                                    it1 = fenceMap.vertices.begin();
                                    
                                    while (it1 != fenceMap.vertices.end())
                                    {
                                        /* The basic vertex data */
                                        String ^msg = String::Format( "{0} {1} {2}, {3} {4} {5}",
                                                                      (*it1).latitude,
                                                                      (*it1).longitude,
                                                                      (*it1).key,
                                                                      (*it1).orderedKey,
                                                                      (*it1).preKey,
                                                                      (*it1).postKey
                                                                    );
                                                                
                                              
                                        fenceData->Text = String::Concat( fenceData->Text, msg );
                                        fenceData->Text = String::Concat( fenceData->Text, "     " );
                                        
                                        /* Enum for each edge */
                                        std::list<Edge>::iterator it3 = (*it1).edges.begin();
                                        
                                        while (it3 != (*it1).edges.end())
                                        {
                                            msg = String::Format( " {0} {1}",
                                                                  (*it3).vEast,
                                                                  (*it3).vWest );
                                            
                                            fenceData->Text = String::Concat( fenceData->Text, msg );
                                            
                                            ++it3;
                                        }
                                        
                                        
                                        #if 0
                                        /* Lat/long for each edge */
                                        it3 = (*it1).edges.begin();
                                        
                                        while (it3 != (*it1).edges.end())
                                        {
                                            msg = String::Format( " {0} {1} {2} {3}",
                                                                  (*it3).latitudeEast,
                                                                  (*it3).longitudeEast,
                                                                  (*it3).latitudeWest,
                                                                  (*it3).longitudeWest );
                                            
                                            fenceData->Text = String::Concat( fenceData->Text, msg );
                                            
                                            ++it3;
                                        }
                                        #endif
                                        
                                        fenceData->Text = String::Concat( fenceData->Text, "\x0d\x0a" );
                                        
                                        ++it1;
                                    }

                                    
                                    fenceData->Text = String::Concat( fenceData->Text, "\x0d\x0a" );
                                    
                                    
                                    /* Now add to output file */
                                    /* SN */
                                    it1 = fenceMap.vertices.begin();
                                    while (it1 != fenceMap.vertices.end())
                                    {
		                                fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, (*it1).latitude );
                                        
                                        ++it1;
                                    }
                                    
                                    /* Edge list counts */
                                    it1 = fenceMap.vertices.begin();
                                    while (it1 != fenceMap.vertices.end())
                                    {
		                                fileOutSizeNow = writeOutFile8( &fileOut, fileOutSizeNow, binBuffer, (*it1).edges.size() );
                                        
                                        ++it1;
                                    }

                                    /* Edge list locations */
                                    int edgesListOffset = fileOutSizeNow + (4 * fenceMap.vertexCount);
                                    
                                    it1 = fenceMap.vertices.begin();
                                    int edgesListSize = 0;
                                    while (it1 != fenceMap.vertices.end())
                                    {
		                                fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, edgesListOffset + edgesListSize );
                                        edgesListSize += 16 * (*it1).edges.size();
                                        
                                        ++it1;
                                    }

                                    /* Edge lists */
                                    it1 = fenceMap.vertices.begin();
                                    while (it1 != fenceMap.vertices.end())
                                    {
                                        std::list<Edge>::iterator it3 = (*it1).edges.begin();
                                        it3 = (*it1).edges.begin();
                                        while (it3 != (*it1).edges.end())
                                        {
		                                    fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, (*it3).latitudeEast );
		                                    fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, (*it3).longitudeEast );
		                                    fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, (*it3).latitudeWest );
		                                    fileOutSizeNow = writeOutFile32( &fileOut, fileOutSizeNow, binBuffer, (*it3).longitudeWest );
                                            ++it3;
                                        }
                                        
                                        ++it1;
                                    }
                                    ++totalFences;
                                }
		                        writeOutFileFinish( &fileOut, fileOutSizeNow, binBuffer );
                                fileOut.close();

                                

                                #if 0
                                fileOut.open( "fence.bin", fstream::out | fstream::binary | fstream::trunc);
                                if (fileOut.fail() != true)
                                {
		                            fileOut.write( (char *)binBuffer, _packer->size() );
                                    fileOut.close();
                                    status->Text = "Converted successfully";
                                }
                                else
                                {
                                    status->Text = "Can't open output file!";
                                }
                                #endif
                            }
                            else
                            {
                                status->Text = "Empty input file!";
                            }

                        }
                        else
                        {
                            status->Text = "Can't open input file!";
                        }
                    }
                    else
                    {
                        status->Text = "Not a csv file";
                    }
                }
                else
                {
                    status->Text = "No extension";
                }
            }
            else
            {
                status->Text = "No file selected!";
            }
    }


    //Parses strings from an 'csv' file and packs the string values into a binary object.
    //Also requires size of the csv and current byte position which will progress for each
    //fence call
    //The 'vertices' contents will be zero for a 1st pass call but non zero for a 2nd pass.
    //The csv file has 4 columns and accordingly the parsing maintains a state =
    //id/flags/lat/long which is simply a count modulo 4) 
    
    //Return the starting position of next fence csv (if any)
    int parse( char *csv, int csvSize, int csvPosn, int *verticesCount, Fence *fenceMap )
    {
        Vertex vertex;
                    
    	char stringBuffer[MAX_ENTRY_SZ];/* to buffer strings parsed from input */
        int csvColumn = 0;
        int csvRows = 0;//counts rows found during parse
        bool endOfFence = false;//remembers when a fence is done

        int endPosn = 0;//Will return the current csv byte position at end of parse
        
        
        
         endOfFence = false;//remembers when a fence is done

	    while ((csvPosn < csvSize) && (endOfFence == false))
	    {
	        int charCount = 0;//counts chars in a string
	        int integers = 0;//counts numbers before any dp

	        //Get a string from the input delimited by either a ',' or 'x0d' and ignoring any '.' */
            char character = csv[csvPosn];
            while ((character != '\x0d') && (character != '\x0a') && (character != ','))
            {
                if (character != '.')
                {
                    stringBuffer[charCount] = character;
                    ++charCount;
                }
                else
                {
                    integers = charCount;
                }
                ++csvPosn;
                character = csv[csvPosn];
            }
            //String done
            
            
            stringBuffer[charCount] = '\0';//Complete the string

            //Skip past last delimiter
            ++csvPosn;

            //End of a line?
            while (((csv[csvPosn] == '\x0d') || (csv[csvPosn] == '\x0a')) && (csvPosn < csvSize))
            {
                ++csvPosn;/* then skip past the 0xa to start of next line */
            }
        
            if (charCount != 0)
            {
                if (*verticesCount != 0)
                {
                    //This is 2nd parse pass, so insert the values depending upon column
                    unsigned int value = (unsigned int)atol( stringBuffer );
                    
                    switch (csvColumn & 3)//modulo 4
                    {
                        case 0://ID
                            //Only the 1st fence row would have a value in this column
                            if (csvRows == 0)
                            {
                                //Must be 1st row so insert ID and inputted vertix count
                                _packer->insert( value, 8 );//id
                                _packer->insert( *verticesCount, 16 );
                                fenceMap->id = value;
                                fenceMap->vertexCount = *verticesCount;
                            }
                            else
                            {
                                //Must be value for next fence - so end this fence (i.e. stop)
                                endOfFence = true;
                            }
                            break;
                        case 1://FLAGS
                            //Only the 1st fence row would have a value in this column
                            _packer->insert( value << 1, 8 );
                            fenceMap->behaviour = value;
                            break;
                        case 2://LATITUDE
                            //Need to add datum and produce result rounded to 5dp
                            value = _packer->round( value, charCount - integers, 6 );
                            value = _packer->round( value + LAT_DATUM, 6, 5 );
                            _packer->insert( value, 25 );
                            vertex.latitude = value;
                            break;
                        case 3://LONGITUDE
                            //Need to add datum and produce result rounded to 5dp
                            value = _packer->round( value, charCount - integers, 6 );
                            value = _packer->round( value + LONG_DATUM, 6, 5 );
                            _packer->insert( value, 26 );
                            vertex.longitude = value;
                            vertex.key = csvRows;
                            fenceMap->vertices.push_back( vertex );
                            
                            endPosn = csvPosn;//Remember potential end of a fence
                            ++csvRows;
                            break;
                    }
                }
                else
                {
                    //This is 1st parse pass, we are just counting rows until end of a fence
                    switch (csvColumn & 3)//modulo 4
                    {
                        case 0://ID
                            if (csvRows != 0)
                            {
                                //Must be 1st row so insert ID and inputted vertix count
                                endOfFence = true;
                            }
                            break;
                        case 1://FLAGS
                        case 2://LATITUDE
                            break;
                        case 3://LONGITUDE
                            //Count the row
                            ++csvRows;
                            break;
                    }
                    
                }
            }

            ++csvColumn;//cycle the column state
        }
        
        *verticesCount = csvRows;//vertix count must be no or rows encountered
        return(endPosn);
    }
    
    
	int writeOutFile8( fstream *fileOut, int sizeNow, unsigned char *binBuffer, int value )
	{
        if ((sizeNow + 1) > 1000)
        {
	        fileOut->write(( char *)binBuffer, sizeNow );
            sizeNow = 0;
        }

        binBuffer += sizeNow;
        
        *binBuffer = value & 0xff;

        return(sizeNow + 1);
	}
    
    
    int writeOutFile16( fstream *fileOut, int sizeNow, unsigned char *binBuffer, int value )
	{
        if ((sizeNow + 2) > 1000)
        {
	        fileOut->write(( char *)binBuffer, sizeNow );
            sizeNow = 0;
        }

        binBuffer += sizeNow;
        
        *binBuffer = (value >> 8) & 0xff;
        ++binBuffer;
        *binBuffer = value & 0xff;

        return(sizeNow + 2);
	}
    
    
	int writeOutFile32( fstream *fileOut, int sizeNow, unsigned char *binBuffer, int value )
	{
        if ((sizeNow + 4) > 1000)
        {
	        fileOut->write(( char *)binBuffer, sizeNow );
            sizeNow = 0;
        }

        binBuffer += sizeNow;
        
        *binBuffer = (value >> 24) & 0xff;
        ++binBuffer;
        *binBuffer = (value >> 16) & 0xff;
        ++binBuffer;
        *binBuffer = (value >> 8) & 0xff;
        ++binBuffer;
        *binBuffer = value & 0xff;

        return(sizeNow + 4);
	}



	void writeOutFileFinish( fstream *fileOut, int sizeNow, unsigned char *binBuffer )
	{
	    fileOut->write(( char *)binBuffer, sizeNow );
	}




};
}

