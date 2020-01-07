#pragma once
#include <cstring>
#include <cstdio>
#include <math.h>       /* sin */
#include <iostream>
#include <fstream>
#include <list>
#include "pack.h"
#include "vertex.h"
#include "stream_in.h"

const int MAX_ENTRY_SZ = 30;



const int LAT_DATUM = (90U * 100000U * 10U);/* x10 to match google position resolution */
const int LONG_DATUM = (180U * 100000U * 10U);


int Vertex::orderBy = Vertex::ORDER_BY_LATITUDE;


namespace geofence {

//    using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
    using namespace System::Collections::Generic;
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
	private: System::Windows::Forms::TextBox^  fenceData;
	private: System::Windows::Forms::Button^  generateButton;






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
			this->generateButton = (gcnew System::Windows::Forms::Button());
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
			this->convertButton->Size = System::Drawing::Size(62, 21);
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
			// generateButton
			// 
			this->generateButton->Location = System::Drawing::Point(285, 140);
			this->generateButton->Name = L"generateButton";
			this->generateButton->Size = System::Drawing::Size(62, 22);
			this->generateButton->TabIndex = 11;
			this->generateButton->Text = L"Generate";
			this->generateButton->UseVisualStyleBackColor = true;
			this->generateButton->Click += gcnew System::EventHandler(this, &Form1::generateButton_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1159, 425);
			this->Controls->Add(this->generateButton);
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
    
    const int NO_VERTEX = -1;
    
    
    const int BYTE_1  = 1;  /* 1 bytes */
    const int BYTE_2  = 2;  /* 2 bytes */
    const int BYTE_4  = 4;  /* 4 bytes */
    const int BYTE_8  = 8;  /* 8 bytes */
    const int BYTE_12 = 12; /* 12 bytes */
    const int BYTE_16 = 16; /* 16 bytes */
    const int BYTE_20 = 20; /* 20 bytes */



    const int FENCE_FIXED_PARAMETERS = 100;
    const int FENCE_ID_SZ = BYTE_2;
    const int FENCE_TYPE_SZ = BYTE_1;
    const int FENCE_VERTICES_SZ = BYTE_4;

    const int FENCE_COUNT_SZ = BYTE_2;
    const int FENCE_SIZE_SZ = BYTE_4;
    const int FENCE_INDEX_SZ = BYTE_2;


    const int BOX_BOUNDARY_LATITITUDE_SZ = BYTE_4;
    const int BOX_BOUNDARY_LONGITUDE_SZ = BYTE_4;
    const int NS_FENCE_INDEX_LIST_OFFSET_SZ = BYTE_4;
    const int EW_FENCE_INDEX_LIST_OFFSET_SZ = BYTE_4;


    const int VERTEX_LATITITUDE_SZ = BYTE_4;
    const int VERTEX_BAND_EDGE_LIST_OFFSET_SZ = BYTE_4;
    const int FENCE_ATTRIBUTE_BLOCK_UNUSED_SZ = (FENCE_FIXED_PARAMETERS
                                                            - FENCE_ID_SZ
                                                            - FENCE_TYPE_SZ
                                                            - FENCE_VERTICES_SZ);

    const int VERTEX_FILE_SZ_PER_VERTEX = (VERTEX_LATITITUDE_SZ
                                                    + VERTEX_BAND_EDGE_LIST_OFFSET_SZ);

    const int BOX_FILE_SZ_PER_FENCE = (BOX_BOUNDARY_LATITITUDE_SZ
                                                + BOX_BOUNDARY_LONGITUDE_SZ
                                                + NS_FENCE_INDEX_LIST_OFFSET_SZ
                                                + EW_FENCE_INDEX_LIST_OFFSET_SZ);

    int OFFSET_TO_EDGES( int v )
    {
        return(FENCE_FIXED_PARAMETERS + (VERTEX_FILE_SZ_PER_VERTEX * v));
    }

    int OFFSET_TO_INDEXES( int f )
    {
        return(FENCE_COUNT_SZ + (FENCE_SIZE_SZ * f) + (FENCE_ID_SZ * f)
               + (FENCE_INDEX_SZ * f) + (BOX_FILE_SZ_PER_FENCE * f * 2));
    }

    int OFFSET_TO_BOX_FILE( int f )
    {
        return(FENCE_COUNT_SZ + (FENCE_SIZE_SZ * f) + (FENCE_ID_SZ * f) + (FENCE_INDEX_SZ * f));
    }


    const double MASS_LATITUDE = 51.49600;
    const double MASS_LONGITUDE = -0.13500;
    const double MASS_RADIUS = 10000;
    const int MASS_POINTS = 500;


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
            std::fstream fileIn;/* file handle */
            std::fstream fileOut;/* file handle */

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
                        StreamIn^ csvFile = gcnew StreamIn( longName );

                        if (csvFile->isOpen() == true)
                        {
        
                            int fenceCount = 0;

                            if (csvFile->size() != 0)
                            {
                                //At this point:-
                                //csvBuffer is a buffer holding all the text read from the csv file.
                                //csvTextSize has the size in characters
                                //csvTextIndex will maintain the position in the buffer as conversion progresses
                                //fenceCount counts fences discovered in file as conversion progresses

                                Pack ^packer = gcnew Pack( "fence_a.bin" );

                                std::list<BoxBoundary> EWBoundaries;
                                std::list<BoxBoundary> NSBoundaries;
                                std::list<FenceSummary> fenceSummaryList;

                                fileOut.open( "poly.def", std::fstream::out | std::fstream::binary | std::fstream::trunc);

                                csvFile->bookmark();//Bookmark the start of initial fence

                                while (csvFile->isEnd() == false)
                                {
                                    Fence fenceMap;

                                    int vertices = 0;

                                    csvFile->setToBookmark();//Set to start of a fence
                                    parse( packer, csvFile, &vertices, &fenceMap );//1st parse (gets vertices)

                                    csvFile->setToBookmark();//Reset to start of the fence
                                    parse( packer, csvFile, &vertices, &fenceMap );//2nd parse (uses vertices)

                                    packer->pad();


                                    //****************** Initial fence header output ***********************

                                    fileWrite( &fileOut, FENCE_ID_SZ, fenceMap.id );

                                    fileWrite( &fileOut, FENCE_TYPE_SZ, fenceMap.behaviour );

                                    /* Filler zeroes for unused fence attributes */
                                    for (int i = 0; i < FENCE_ATTRIBUTE_BLOCK_UNUSED_SZ; ++i)
                                    {
                                        fileWrite( &fileOut, BYTE_1, 0xffU );
                                    }

                                    fileWrite( &fileOut, FENCE_VERTICES_SZ, fenceMap.vertexCount );


                                    //****************** Establish vertex links (edges) ********************

                                    /* Assumes they are listed in circular order */

                                    std::list<Vertex>::iterator iterVertex = fenceMap.vertices.begin();
                                    std::list<Vertex>::iterator iterVertex2 = fenceMap.vertices.begin();
                                    ++iterVertex2;

                                    while (iterVertex != fenceMap.vertices.end())
                                    {

                                        /* Use edge1 if link belongs to 'this' vertex, else it belongs to 'next' (use edge2) */
                                        if ((*iterVertex).latitude != (*iterVertex2).latitude)
                                        {
                                            Edge *edgePtr = ((*iterVertex).latitude > (*iterVertex2).latitude) ? &((*iterVertex2).edge2) : &((*iterVertex).edge1);

                                            if ((*iterVertex).longitude >= (*iterVertex2).longitude)
                                            {
                                                edgePtr->west = (*iterVertex2).index;
                                                edgePtr->east = (*iterVertex).index;
                                            }
                                            else
                                            {
                                                edgePtr->west = (*iterVertex).index;
                                                edgePtr->east = (*iterVertex2).index;
                                            }

                                        }
                                        else
                                        {
                                            /* Ignore the edge if horizontal */
                                            /* Pass on 'this' edge2 to next edge2 (since vertices are effectively the same) */
                                            (*iterVertex2).edge2 = (*iterVertex).edge2;
                                        }
                                        ++iterVertex;
                                        ++iterVertex2;
                                        if (iterVertex2 == fenceMap.vertices.end())
                                        {
                                            iterVertex2 = fenceMap.vertices.begin();
                                        }

                                    }


                                    //************** Sort vertices and establish box boundaries ************

                                    BoxBoundary boundary;

                                    // Box boundaries WE
                                    Vertex::orderBy = Vertex::ORDER_BY_LONGITUDE;
                                    fenceMap.vertices.sort();

                                    iterVertex = fenceMap.vertices.begin();
                                    boundary.position = (*iterVertex).longitude;
                                    boundary.index = fenceCount;
                                    EWBoundaries.push_back( boundary );

                                    iterVertex = fenceMap.vertices.end();
                                    --iterVertex;
                                    boundary.position = (*iterVertex).longitude;
                                    boundary.index = fenceCount;
                                    EWBoundaries.push_back( boundary );

                                    // Box boundaries SN
                                    Vertex::orderBy = Vertex::ORDER_BY_LATITUDE;
                                    fenceMap.vertices.sort();

                                    iterVertex = fenceMap.vertices.begin();
                                    boundary.position = (*iterVertex).latitude;
                                    boundary.index = fenceCount;
                                    NSBoundaries.push_back( boundary );

                                    iterVertex = fenceMap.vertices.end();
                                    --iterVertex;
                                    boundary.position = (*iterVertex).latitude;
                                    boundary.index = fenceCount;
                                    NSBoundaries.push_back( boundary );

                                    // Output ordered latitude (SN) */
                                    iterVertex = fenceMap.vertices.begin();
                                    while (iterVertex != fenceMap.vertices.end())
                                    {
                                        fileWrite( &fileOut, BYTE_4, (*iterVertex).latitude );
                                        ++iterVertex;
                                    }


                                    // Establish a vertex index cross ref between ordered and unordered
                                    int orderedIndex = 0;
                                    iterVertex = fenceMap.vertices.begin();
                                    while (iterVertex != fenceMap.vertices.end())
                                    {
                                        VertexCrossRef crossRef;

                                        crossRef.index = (*iterVertex).index;
                                        crossRef.orderedIndex = orderedIndex;
                                        fenceMap.crossRef.push_back( crossRef );
                                        ++iterVertex;
                                        ++orderedIndex;
                                    }
                                    fenceMap.crossRef.sort();



                                    //**** Complete latitude band edges and output latitude ordered list ***

                                    std::list<Edge> runningEdges;

                                    std::list<Edge> edgeBlock;

                                    int edgeOffset = 0;

                                    iterVertex = fenceMap.vertices.begin();
                                    while (iterVertex != fenceMap.vertices.end())
                                    {

                                        /* Set edge list offset for this vertex */
                                        (*iterVertex).edgeListOffset = edgeOffset;

                                        /* Band latitude */
                                        int vertexNum = (*iterVertex).index;


                                        /* Copy edges from previous list (if any) */
                                        /* Remove any that have no common link to this vertex number */
                                        std::list<Edge>::iterator iterRunning = runningEdges.begin();
                                        while (iterRunning != runningEdges.end())
                                        {
                                            if ( (vertexNum == (*iterRunning).west)
                                                 || (vertexNum == (*iterRunning).east) )
                                            {
                                                iterRunning = runningEdges.erase( iterRunning );
                                                if (runningEdges.empty())
                                                {
                                                    iterRunning = runningEdges.end();
                                                }
                                            }
                                            else
                                            {
                                                (*iterRunning).longitude = edgeLongitude( (*iterRunning).west, (*iterRunning).east, (*iterVertex).latitude, &fenceMap );
                                                ++iterRunning;
                                            }
                                        }

                                        /* Add edges for this vertex */
                                        Edge tempEdge;

                                        if ((*iterVertex).edge1.west != NO_VERTEX)
                                        {
                                            tempEdge = (*iterVertex).edge1;
                                            tempEdge.longitude = edgeLongitude( tempEdge.west, tempEdge.east, (*iterVertex).latitude, &fenceMap );
                                            runningEdges.push_back( tempEdge );
                                        }

                                        if ((*iterVertex).edge2.west != NO_VERTEX)
                                        {
                                            tempEdge = (*iterVertex).edge2;
                                            tempEdge.longitude = edgeLongitude( tempEdge.west, tempEdge.east, (*iterVertex).latitude, &fenceMap );
                                            runningEdges.push_back( tempEdge );
                                        }


                                        runningEdges.sort();

                                        /* Copy edges to edge block */
                                        iterRunning = runningEdges.begin();
                                        while (iterRunning != runningEdges.end())
                                        {
                                            edgeBlock.push_back( *iterRunning );
                                            ++iterRunning;

                                            ++edgeOffset;
                                        }

                                        ++iterVertex;
                                    }

                                    //********** Write edge list offsets & their edge lists ****************

                                    /* Write edge list offsets */
                                    int size = fenceMap.vertexCount;

                                    iterVertex = fenceMap.vertices.begin();
                                    while (iterVertex != fenceMap.vertices.end())
                                    {
                                        int edgeCount = (*iterVertex).edgeListOffset;
                                        fileWrite( &fileOut, BYTE_4, (edgeCount * BYTE_16) + OFFSET_TO_EDGES(size) );
                                        ++iterVertex;
                                    }


                                    /* Stream out the edge list */
                                    std::list<Edge>::iterator iterEdge = edgeBlock.begin();
                                    while (iterEdge != edgeBlock.end())
                                    {
                                        int band;

                                        std::list<VertexCrossRef>::iterator iterCrossRef;

                                        iterVertex = fenceMap.vertices.begin();
                                        iterCrossRef = fenceMap.crossRef.begin();
                                        band = (*iterEdge).west;
                                        advance( iterCrossRef, band );
                                        band = (*iterCrossRef).orderedIndex;
                                        advance( iterVertex, band );
                                        fileWrite( &fileOut, BYTE_4, (*iterVertex).latitude );
                                        fileWrite( &fileOut, BYTE_4, (*iterVertex).longitude );

                                        iterVertex = fenceMap.vertices.begin();
                                        iterCrossRef = fenceMap.crossRef.begin();
                                        band = (*iterEdge).east;
                                        advance( iterCrossRef, band );
                                        band = (*iterCrossRef).orderedIndex;
                                        advance( iterVertex, band );
                                        fileWrite( &fileOut, BYTE_4, (*iterVertex).latitude );
                                        fileWrite( &fileOut, BYTE_4, (*iterVertex).longitude );


                                        ++iterEdge;
                                    }


                                    //********** Update running fence summary list **************************
                                    FenceSummary f;

                                    f.offset = (int)fileOut.tellp();
                                    f.index = fenceCount;
                                    f.id = fenceMap.id;
                                    fenceSummaryList.push_back( f );

                                    //********** End of processing one fence *******************************
                                    ++fenceCount;
                                }

                                //Close poly file
                                fileOut.close();

                                //Create the box file
                                fileOut.open( "poly.box", std::fstream::out | std::fstream::binary | std::fstream::trunc);


                                //****** Write out box lat/longs and corresponding index list offsets ******
                                std::list<int> fenceIndexBlock;

                                fenceFileSortBoxes( &fileOut, &NSBoundaries, &fenceIndexBlock );
                                fenceFileSortBoxes( &fileOut, &EWBoundaries, &fenceIndexBlock );

                                fenceFileBoxIndexOffsets( &fileOut, &NSBoundaries );
                                fenceFileBoxIndexOffsets( &fileOut, &EWBoundaries );

                                // ************* Write out the fence index list block **********************
                                std::list<int>::iterator iterIndex = fenceIndexBlock.begin();
                                while (iterIndex != fenceIndexBlock.end())
                                {
                                    fileWrite( &fileOut, BYTE_2, *iterIndex );
                                    ++iterIndex;
                                }

                                int boxFileSize = (int)fileOut.tellp();

                                //Close poly file
                                fileOut.close();


                                //********** Consolidate files ********************************************

                                //Open final binary file
                                fileOut.open( "poly.bin", std::fstream::out | std::fstream::binary | std::fstream::trunc);
                                fileWrite( &fileOut, BYTE_2, fenceCount );


                                //Write out fence offsets
                                int fenceOffset = 0;

                                std::list<FenceSummary>::iterator iterSummary = fenceSummaryList.begin();
                                while (iterSummary != fenceSummaryList.end())
                                {
                                    fileWrite( &fileOut, BYTE_4, boxFileSize
                                                                  + OFFSET_TO_BOX_FILE(fenceCount)
                                                                  + fenceOffset );

                                    fenceOffset = (*iterSummary).offset;
                                    ++iterSummary;
                                }


                                //Write out sorted fence OTA ids
                                fenceSummaryList.sort();

                                iterSummary = fenceSummaryList.begin();
                                while (iterSummary != fenceSummaryList.end())
                                {
                                    fileWrite( &fileOut, BYTE_2, (*iterSummary).id );
                                    ++iterSummary;
                                }

                                //Write out sorted fence OTA indexes
                                iterSummary = fenceSummaryList.begin();
                                while (iterSummary != fenceSummaryList.end())
                                {
                                    fileWrite( &fileOut, BYTE_2, (*iterSummary).index );
                                    ++iterSummary;
                                }


                                /* Concatenate the box file */
                                fileIn.open( "poly.box", std::fstream::in | std::fstream::binary);
                                fileConcat( &fileOut, &fileIn );
                                fileIn.close();



                                /* Concatenate the polyfence file */
                                fileIn.open( "poly.def", std::fstream::in | std::fstream::binary);
                                fileConcat( &fileOut, &fileIn );
                                fileIn.close();

                                //Close binary file
                                fileOut.close();






                                //Raw Binary version of fences
                                packer->save();

                                csvFile->close();

                                status->Text = "Converted successfully";
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
    void parse( Pack ^packer, StreamIn^ csvFile, int *verticesCount, Fence *fenceMap )
    {
        Vertex vertex;
                    
    	char stringBuffer[MAX_ENTRY_SZ];/* to buffer strings parsed from input */
        int csvColumn = 0;
        int csvRows = 0;//counts rows found during parse
        bool endOfFence = false;//remembers when a fence is done

        int endPosn = 0;//Will return the current csv byte position at end of parse
        
        
        
        endOfFence = false;//remembers when a fence is done

        char character;
        if (csvFile->isEnd() == false)
        {
            character = csvFile->get();
        }
	    while ((csvFile->isEnd() == false) && (endOfFence == false))
	    {
	        int charCount = 0;//counts chars in a string
	        int integers = 0;//counts numbers before any dp

	        //Get a string from the input delimited by either a ',' or 'x0d' and ignoring any '.' */
            while ((character != '\x0d') && (character != '\x0a') && (character != ',') && (csvFile->isEnd() == false))
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
                character = csvFile->get();
            }
            //String done
            
            
            stringBuffer[charCount] = '\0';//Complete the string


            //Get next char
            if (csvFile->isEnd() == false)
            {
                character = csvFile->get();
            }

            //Or skip past to start of next line
            while (((character == '\x0d') || (character == '\x0a')) && (csvFile->isEnd() == false))
            {
            }
        
            if (charCount != 0)
            {
                if (*verticesCount != 0)
                {
                    //This is 2nd parse pass, so insert the values depending upon column
                    int value = (int)atol( stringBuffer );
                    
                    switch (csvColumn & 3)//modulo 4
                    {
                        case 0://ID
                            //Only the 1st fence row would have a value in this column
                            if (csvRows == 0)
                            {
                                //Must be 1st row so insert ID and inputted vertix count
                                packer->insert( value, 8 );//id
                                packer->insert( *verticesCount, 16 );
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
                            packer->insert( value << 1, 8 );
                            fenceMap->behaviour = value;
                            break;
                        case 2://LATITUDE
                            //Need to add datum and produce result rounded to 5dp
                            value = packer->round( value, charCount - integers, 6 );
                            value = packer->round( value + LAT_DATUM, 6, 5 );
                            packer->insert( value, 25 );
                            vertex.latitude = value;
                            break;
                        case 3://LONGITUDE
                            //Need to add datum and produce result rounded to 5dp
                            value = packer->round( value, charCount - integers, 6 );
                            value = packer->round( value + LONG_DATUM, 6, 5 );
                            packer->insert( value, 26 );
                            vertex.longitude = value;
                            vertex.edge1.west = NO_VERTEX;
                            vertex.edge1.east = NO_VERTEX;
                            vertex.edge2.west = NO_VERTEX;
                            vertex.edge2.east = NO_VERTEX;
                            vertex.index = csvRows;
                            fenceMap->vertices.push_back( vertex );
                            
                            //Bookmark the start of new line file position
                            //Note: We've already stepped passed by one
                            csvFile->bookmarkPrevious();
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
    }
    
    

    int edgeLongitude( int west, int east, int bandLatitude, Fence *map )
    {
        /*  longitude west +
            (((latitudeWest - latitude Band) / (latitudeWest - latitudeEast)) x (longitudeEast - longitudeWest))
        */

        int band;

        std::list<Vertex>::iterator iterVertex = map->vertices.begin();
        std::list<VertexCrossRef>::iterator iterCrossRef = map->crossRef.begin();
        advance( iterCrossRef, west );
        band = (*iterCrossRef).orderedIndex;
        advance( iterVertex, band );

        int latitudeWest = (*iterVertex).latitude;
        int longitudeWest = (*iterVertex).longitude;

        iterVertex = map->vertices.begin();
        iterCrossRef = map->crossRef.begin();
        advance( iterCrossRef, east );
        band = (*iterCrossRef).orderedIndex;
        advance( iterVertex, band );

        int latitudeEast = (*iterVertex).latitude;
        int longitudeEast = (*iterVertex).longitude;


        /* Use m, n as part calculations */
        int m = latitudeWest - bandLatitude;
        int n = latitudeWest - latitudeEast;
        if (bandLatitude > latitudeWest)
        {
            m = -m;
            n = -n;
        }

        m *= (longitudeEast - longitudeWest);
        m /= n;
        m += longitudeWest;

        return((int)m);
    }


    void fenceFileSortBoxes( std::fstream *fileOut, std::list<BoxBoundary> *boxBandList, std::list<int> *fenceIndexBlock )
    {

        boxBandList->sort();

        std::list<BoxBoundary>::iterator iterBox = boxBandList->begin();

        std::list<int> fenceIndexRun;

        while (iterBox != boxBandList->end())
        {
            fileWrite( fileOut, BYTE_4, (*iterBox).position );

            /* Update the running box number list */
            (*iterBox).boxListOffset = fenceIndexBlock->size();

            /* Add to index list or remove if already there */
            bool found = false;

            std::list<int>::iterator iterRun = fenceIndexRun.begin();
            while (iterRun != fenceIndexRun.end())
            {
                if ((*iterBox).index == *iterRun)
                {
                    //Found - so remove
                    iterRun = fenceIndexRun.erase( iterRun );
                    found = true;

                    break;
                }
                else
                {
                    ++iterRun;
                }
            }

            if (!found)
            {
                //Not found - so insert
                fenceIndexRun.push_back( (*iterBox).index );
            }


            /* Write sorted running box number list to stream out buffer */

            fenceIndexRun.sort();

            iterRun = fenceIndexRun.begin();
            while (iterRun != fenceIndexRun.end())
            {
                fenceIndexBlock->push_back( *iterRun );
                ++iterRun;
            }

            ++iterBox;
        }

    }


    void fenceFileBoxIndexOffsets( std::fstream *fileOut, std::list<BoxBoundary> *boxBandList )
    {
        /* Write out index list offsets */
        int boxCount = boxBandList->size() / 2;

        std::list<BoxBoundary>::iterator iterBox = boxBandList->begin();
        iterBox = boxBandList->begin();
        while (iterBox != boxBandList->end())
        {
            int offset = (*iterBox).boxListOffset;
            fileWrite( fileOut, BYTE_4, (offset * BYTE_2) + OFFSET_TO_INDEXES(boxCount) );

            ++iterBox;
        }
    }

    void fileConcat( std::fstream *fileOut, std::fstream *fileIn )
    {
        unsigned char buffer[128];
        int size;
        fileIn->seekp( 0, std::ios_base::end );
        size = (int)fileIn->tellp();

        fileIn->seekp( 0, std::ios_base::beg );

        do
        {
            int bytes = size < sizeof(buffer) ? size : sizeof(buffer);

            fileIn->read( ( char *)buffer, bytes );
            fileOut->write(( char *)buffer, bytes );

            size -= bytes;

        }
        while(size != 0);

    }


	void fileWrite( std::fstream *fileOut, int size, int value )
	{
        char buffer[4];

        int n = size;
        char *p = buffer;

        while (n != 0)
        {
            *p = (value >> ((n - 1) * 8)) & 0xff;
            ++p;
            --n;
        }
        fileOut->write(( char *)buffer, size );
	}


    void generateFence( std::fstream *fileOut, int id, double latitude, double longitude, double radius, int points )
    {

        #define PI 3.14159265
        #define DEG_TO_RADS (PI / 180)

        char buffer [100];

        #if defined TXT_FILE
        sprintf_s( buffer, 100, "type""\x09""latitude""\x09""longitude""\x09""name""\x09""desc""\x09""color""\x09""fill_opacity""\n" );
        fileOut->write(buffer, strlen( buffer ) );
        #endif

        for (int i = 0; i != points; ++i)
        {
            double radians = ((360 / (double)points) * (i + 1)) * DEG_TO_RADS;

            double pointLat = latitude + (cos( radians ) * radius);
            double pointLong = longitude + (sin( radians ) * radius);

            #if defined TXT_FILE
            if (false)
            #else
            if (i == 0)
            #endif
            {
                sprintf_s( buffer, 100, "%u,0,%f,%f""\n", id, pointLat, pointLong );
            }
            else
            {
                #if defined TXT_FILE
                sprintf_s( buffer, 100, "T""\x09""%f""\x09""%f""\n", pointLat, pointLong );
                #else
                sprintf_s( buffer, 100, ",,%f,%f""\n", pointLat, pointLong );
                #endif
            }
            fileOut->write(buffer, strlen( buffer ) );
        }

        #if defined TXT_FILE
        sprintf_s( buffer, 100, "\n" );
        fileOut->write(buffer, strlen( buffer ) );
        #endif
    }


    private: System::Void generateButton_Click(System::Object^  sender, System::EventArgs^  e)
    {
        std::fstream fileOut;/* file handle */

        #if defined TXT_FILE
        fileOut.open( "mass.txt", std::fstream::out | std::fstream::binary | std::fstream::trunc);
        #else
        fileOut.open( "mass.csv", std::fstream::out | std::fstream::binary | std::fstream::trunc);
        #endif

        double radius = MASS_RADIUS / 100000;

        double centreStep = (2 * radius) / 5;

        for (int i = 0; i < 10; ++i)
        {
            for (int j = 0; j < 10; ++j)
            {
                generateFence( &fileOut, (i * 10) + j, MASS_LATITUDE + (centreStep * i), MASS_LONGITUDE + (centreStep * j), radius, MASS_POINTS );
            }
        }



        fileOut.close();

        status->Text = "Generated successfully";
    }

};
}

