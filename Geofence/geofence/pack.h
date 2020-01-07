#include "stream_out.h"

using namespace System;

public ref class Pack
{
    public:
    
        Pack( char* name )
        {
            _packedFile = gcnew StreamOut( name );

            _bitPosn = (1U << 7);
            _byte = 0;
        }
    

        ~Pack( void )
        {
        }
        

        void save( void )
        {
            _packedFile->close();
        }
    
    
        //Insert 'numBits' from 'value' into the byte buffer starting at current
        //addressed bit
        void insert( unsigned int value, int numBits )
        {
            unsigned int valueBit = (1U << (numBits - 1));
            while (valueBit != 0)
            {
                _byte &= ~_bitPosn;
                _byte |= (((value & valueBit) != 0) ? _bitPosn : 0U);
                _bitPosn >>= 1;
                
                if (_bitPosn == 0U)
                {
                    //Reset bit position
                    _bitPosn = (1U << 7);
                    _packedFile->put( _byte );
                }
            
                valueBit >>= 1;
            }
        }


        #if 0
        //Extract 'numBits' from the byte buffer starting at current addressed
        //bit
        unsigned int extract( int numBits )
        {
            unsigned int valueBit = (1U << (numBits - 1));
            unsigned int value = 0U;

            while (valueBit != 0)
            {
                value |= (((_byte & _bitPosn) != 0) ? valueBit : 0U);
                _bitPosn >>= 1;
                
                if (_bitPosn == 0U)
                {
                    //Reset bit position
                    _bitPosn = (1U << 7);

                    //Get next byte
                }
            
                valueBit >>= 1;
            }
            
            return(value);
        }
        #endif


        //Pads to next byte boundary
        void pad( void )
        {
            if (_bitPosn != (unsigned char)(1U << 7))
            {
                //Finish with the current byte
                _bitPosn = (1U << 7);
                _packedFile->put( _byte );
            }
        }

        //Adjust a 'value' according to its decimal places compared to its desired
        //decimal places. E.g. 1 dp convert to 2 dp requires a x10
        unsigned int round( unsigned int value, int inDecimals, int outDecimals )
        {
            while (inDecimals < outDecimals)
            {
                value *= 10;
                ++inDecimals;
            }
            while (inDecimals > outDecimals)
            {
                value = (value + 5) / 10;
                --inDecimals;
            }

            return(value);
        }

    


    private:
        StreamOut^ _packedFile;

        unsigned char _bitPosn;//bit position within a byte
        int _byte;//byte under construction
        
};
