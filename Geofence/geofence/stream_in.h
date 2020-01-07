#include <cstring>
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace System;
using namespace System::Collections;
using namespace System::IO;

public ref class StreamIn
{
    public:
    
        StreamIn( char* name )
        {
            String^ nameString = gcnew String( name );
            _buffer = gcnew array<unsigned char>( BUFFER_SZ );
            _fs = File::OpenRead( nameString );
            _fs->Position = 0;

            fillBuffer();
        }
    

        ~StreamIn( void )
        {
        }
        

        bool isOpen( void )
        {
            return (_fs->CanRead == true);
        }
    
    
        void close( void )
        {
            _fs->Close();
        }


        char get( void )
        {
            char character = 0;

            character = _buffer[_bufferIndex];
            ++_bufferIndex;
            if (_bufferIndex == BUFFER_SZ)
            {
                fillBuffer();
            }

            return (character);
        }


        void set( int position )
        {
            _fs->Position = position;
            fillBuffer();
        }
    

        void bookmark( void )
        {
            _bookmark = (int)((_fs->Position - _bufferWindowSz) + _bufferIndex);
        }
    

        void bookmarkPrevious( void )
        {
            bookmark();
            if (_bookmark != 0)
            {
                --_bookmark;
            }
        }
    

        void setToBookmark( void )
        {
            set( _bookmark );
        }
    

        bool isEnd( void )
        {
            return ((_fs->Position == _fs->Length) && (_bufferIndex == _bufferWindowSz));
        }
    

        int size( void )
        {
            return ((int)_fs->Length);
        }
    

    private:

        static const int BUFFER_SZ = 1000;

        FileStream^ _fs;
        array<unsigned char>^ _buffer;

        int _bufferIndex;
        int _bufferWindowSz;
        int _bookmark;



        void fillBuffer( void )
        {
            _bufferIndex = 0;
            _bufferWindowSz = _fs->Read( _buffer, _bufferIndex, BUFFER_SZ );
        }
        
};
