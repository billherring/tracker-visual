#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace System;
using namespace System::Collections;
using namespace System::IO;

public ref class StreamOut
{
    public:
    
        StreamOut( char* name )
        {
            String^ nameString = gcnew String( name );
            _buffer = gcnew array<unsigned char>( BUFFER_SZ );
            _fs = File::OpenWrite( nameString );
            _fs->Position = 0;

            clearBuffer();
        }
    

        ~StreamOut( void )
        {
        }
        

        bool isOpen( void )
        {
            return (_fs->CanWrite == true);
        }
    
    
        void close( void )
        {
            _fs->Write( _buffer, 0, _bufferIndex );
            _fs->Close();
        }


        void put( char character )
        {
            _buffer[_bufferIndex] = character;
            ++_bufferIndex;
            if (_bufferIndex == BUFFER_SZ)
            {
                _fs->Write( _buffer, 0, BUFFER_SZ );
                clearBuffer();
            }
        }


    

    private:

        static const int BUFFER_SZ = 10;

        FileStream^ _fs;
        array<unsigned char>^ _buffer;

        int _bufferIndex;



        void clearBuffer( void )
        {
            _bufferIndex = 0;
        }
        
};

