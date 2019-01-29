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
        

        //Prepare packing variables. Call this to start.
        //  binary - ptr to a binary buffer for output
        void initialise( unsigned char *binary )
        {
            _bytePtr = binary;
            _bitPosn = (1U << 7);
            _byteCount = 0;
        }
    
    
        //Insert 'numBits' from 'value' into the byte buffer starting at current
        //addressed bit
        void insert( unsigned int value, int numBits )
        {
            unsigned int valueBit = (1U << (numBits - 1));
            while (valueBit != 0)
            {
                *_bytePtr &= ~_bitPosn;
                *_bytePtr |= (((value & valueBit) != 0) ? _bitPosn : 0U);
                _bitPosn >>= 1;
                
                if (_bitPosn == 0U)
                {
                    //Reset bit position
                    _bitPosn = (1U << 7);
                    ++_bytePtr;
                    ++_byteCount;
                }
            
                valueBit >>= 1;
            }
        }


        //Extract 'numBits' from the byte buffer starting at current addressed
        //bit
        unsigned int extract( int numBits )
        {
            unsigned int valueBit = (1U << (numBits - 1));
            unsigned int value = 0U;

            while (valueBit != 0)
            {
                value |= (((*_bytePtr & _bitPosn) != 0) ? valueBit : 0U);
                _bitPosn >>= 1;
                
                if (_bitPosn == 0U)
                {
                    //Reset bit position
                    _bitPosn = (1U << 7);
                    ++_bytePtr;
                    ++_byteCount;
                }
            
                valueBit >>= 1;
            }
            
            return(value);
        }


        //Provide total binary bytes
        int size( void )
        {
            return(_byteCount);
        }
    
        //Pads to next byte boundary
        void pad( void )
        {
            if (_bitPosn != (unsigned char)(1U << 7))
            {
                //Finish with the current byte
                _bitPosn = (1U << 7);
                ++_bytePtr;
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
        unsigned char * _bytePtr;//ptr to output file
        unsigned char _bitPosn;//bit position within a byte
        int _byteCount;//count bytes outputted
        
};
