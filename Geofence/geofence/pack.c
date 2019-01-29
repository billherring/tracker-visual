using namespace System;

public ref class Pack
{
    public:
    
        Pack( void )
        {
        }
    

        ~Pack( void )
        {
        }
        

        //Prepare packing variables
        //  binary - ptr to a binary buffer for output
        void initialise( unsigned char *binary )
        {
            _outPtr = binary;
            *_outPtr = 0U;
            _outBit = (unsigned char)(1U << 7);
            _byteCount = 0;
        }
    
    
        //Insert 'bits' from 'value' into out buffer starting at current addressed
        //out bit
        void insert( unsigned int value, int bits )
        {
            unsigned int inBit = (1U << (bits - 1));
            while (inBit != 0)
            {
                *_outPtr |= (unsigned char)(((value & inBit) != 0) ? _outBit : 0U);
                _outBit >>= 1;
                
                if (_outBit == 0U)
                {
                    //Reset out bit position
                    _outBit = (unsigned char)(1U << 7);
                    ++_outPtr;
                    *_outBit = 0U;//zero byte initially
                    ++_byteCount;
                }
            
                inBit >>= 1;
            }
        }


        //Provide total binary bytes
        int size( void )
        {
            return(_byteCount);
        }
    
        //Pads to next byte boundary
        void pad( void )
        {
            if (_outBit != (unsigned char)(1U << 7))
            {
                //Finish with the current byte
                _outBit = (unsigned char)(1U << 7);
                ++_outPtr;
                *_outPtr = 0U;
                ++_byteCount;
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
        unsigned char * _OutPtr;//ptr to output file
        unsigned char _outBit;//bit position within a byte
        int _byteCount;//count bytes outputted
        
};
