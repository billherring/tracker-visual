// crc1021.cpp : Defines the entry point for the console application.
//
// Calculate and insert a crc and App size to a tracker binary file.
// A tracker binary file is structured as follows:-
// 0 vector block (256 byte)
// 0x100 crc (4 bytes little endian)
// 0x104 App size (4 bytes little endian)
// 0x108 App name (16 bytes string)
// 0118 Application
// 
#include "stdafx.h"

#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>

unsigned short checksum( unsigned short sum, unsigned char *byteStream, int length );



using namespace std;

const int CHUNK_MAX_SIZE_BYTES = 256;// See 'byteStream'


//argv[1] has file name
//
int main(int argc, char** argv)
{
	fstream _fileHandle;// file handle

//	_fileHandle.open( "C:\\Users\\bill\\Development\\GitHub\\tracker-tigershark\\FLEET01\\Debug\\GRIFFIN1.BIN", fstream::in | fstream::out | fstream::binary);
	_fileHandle.open( argv[1], fstream::in | fstream::out | fstream::binary);


	if (_fileHandle.fail() != true)
	{
		unsigned char byteStream[CHUNK_MAX_SIZE_BYTES];// To efficiently read/process the file in chunks
	
		int fileSize;
		unsigned short crc;

        int vectorBlockSize = 256;

		if (argc > 2)
        {
            if ( (argc > 3) || (strcmp( argv[2], "-insert" ) != 0) )
            {
                vectorBlockSize = atoi( argv[3] );
            }
        }

        //Work out actual file size
        //
        _fileHandle.seekg( 0, ios_base::end ); 
        fileSize = (int)_fileHandle.tellg();


        // Prepare file byteStream with actual filesize bytes
        // 
        byteStream[0] = (unsigned char)fileSize;
        byteStream[1] = (unsigned char)(fileSize >> 8);
        byteStream[2] = (unsigned char)(fileSize >> 16);
        byteStream[3] = (unsigned char)(fileSize >> 24);


        //Compute crc
        //Omit the 256 byte vector block and the slot reserved for crc
        //Begin with the prepared calculated filesize byteStream and therefore
        //also omit the filesize slot which will be filled later with the
        //correct value
        //

        crc = 0;
        crc = checksum( crc, byteStream, 4 );


        int posn = vectorBlockSize + 8;

        _fileHandle.seekg( posn, ios_base::beg );

        do
        {
            //Read file & calc crc in chunks
            //
            int chunk = fileSize - posn;

            if (chunk > CHUNK_MAX_SIZE_BYTES)
            {
                chunk = CHUNK_MAX_SIZE_BYTES;
            }

            _fileHandle.read( (char *)byteStream, chunk );
            crc = checksum( crc, byteStream, chunk );
            posn += chunk;
        }
        while( posn < fileSize );
        


        //Insert the computed crc (4) and the App size (4) at location
        //0x100, i.e. after the vector block.
        //
        byteStream[0] = (unsigned char)crc;
        byteStream[1] = (unsigned char)(crc >> 8);
        byteStream[2] = (unsigned char)0;
        byteStream[3] = (unsigned char)0;

        byteStream[4] = (unsigned char)fileSize;
        byteStream[5] = (unsigned char)(fileSize >> 8);
        byteStream[6] = (unsigned char)(fileSize >> 16);
        byteStream[7] = (unsigned char)(fileSize >> 24);

        cout << "Insert crc " << hex << crc << "\n";
        cout << "Insert size " << hex << fileSize << "\n";

        _fileHandle.seekg( vectorBlockSize, ios_base::beg );
        _fileHandle.write( (char *)byteStream, 8 );



		//All done
		//
		_fileHandle.close();
	}
	else
	{
		cout << "Can't open file!" << "\n";
	}


	return 0;
}



//This is the crc1021 algorithm
//It supports incremental crc calculation (i.e. in chunks)
//
//runningCrc - the crc so far (should be 0 if just started)
//byteStream - location of byte byteStream to process into running crc
//length - byte length of byte byteStream
//
unsigned short checksum( unsigned short runningCrc, unsigned char *byteStream, int length )
{
	while (length != 0)
	{
		unsigned short x; 

		x = ((runningCrc >> 8) ^ *byteStream) & 0xff; 
		x ^= (x >> 4); 

		runningCrc = (runningCrc << 8) ^ (x << 12) ^ (x << 5) ^ x; 

		runningCrc &= 0xffff;
		++byteStream;
		--length;
	}

	return runningCrc; 
}

