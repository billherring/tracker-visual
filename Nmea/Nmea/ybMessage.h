using namespace System;
using namespace System::Collections;

namespace MESSAGE_STATUS
{
    enum {STATUS_SENT, STATUS_NOT_SENT, STATUS_RECEIVED};
}

public ref class YbMessage
{
    public:
        /* Core */
        static const int SOH_SZ = 0;//1;
        static const int CSUM_SZ = 2;
        static const int LEN_SZ = 2;

        static const int FRAME_MIN_DATA_LEN = 3;// Command | Csum
        static const int FRAME_MIN_SZ = FRAME_MIN_DATA_LEN + SOH_SZ + LEN_SZ;

        static const int GET_CMD_PAYLOAD_SZ = 4;
        static const int SEND_CMD_PRE_TEXT_SZ = 6;
        static const int GET_RESPONSE_PRE_TEXT_SZ = 5;


        static const unsigned char SOT_VALUE = (unsigned char)1;
        static const unsigned char EOT_VALUE = (unsigned char)4;

        static const unsigned char OUT_TYPE_VALUE = (unsigned char)1;
        static const unsigned char REQUEST_TYPE_VALUE = (unsigned char)2;
        static const unsigned char CONFIRM_TYPE_VALUE = (unsigned char)0x80;
        static const unsigned char IN_TYPE_VALUE = (unsigned char)0x82;


        static const int SOT_POSN = 0;
        static const int LENGTH_HIGH_POSN = 0;//1;
        static const int LENGTH_LOW_POSN = 1;//2;
        static const int TYPE_POSN = 2;//3;
        static const int PAYLOAD_POSN = 3;//4;

        static const int SEND_RESPONSE_ID = PAYLOAD_POSN + 0;
        static const int GET_RESPONSE_TEXT = PAYLOAD_POSN + 5;
        static const int GET_RESPONSE_ID = PAYLOAD_POSN + 1;
        static const int GET_RESPONSE_MSG_COUNT = PAYLOAD_POSN + 0;


    public:
    
    YbMessage( void )
    {
        _myFrame = gcnew ArrayList();
    }
    
    
    YbMessage( String ^mac, int type )
    {
        
        int dataLength = FRAME_MIN_DATA_LEN + GET_CMD_PAYLOAD_SZ;

        _myFrame = gcnew ArrayList();
//        _myFrame->Add( SOT_VALUE );
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
//        insertMac( mac );
        _myFrame->Add( REQUEST_TYPE_VALUE );
        _myFrame->Add( (unsigned char)0U );
        _myFrame->Add( (unsigned char)0U );
        _myFrame->Add( (unsigned char)0U );
        _myFrame->Add( (unsigned char)0U );

        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
//        _myFrame->Add( EOT_VALUE );

        _status = MESSAGE_STATUS::STATUS_NOT_SENT;
    }
    
    YbMessage( String ^mac, String ^text, unsigned short id, bool sendNow )
    {

        int dataLength = FRAME_MIN_DATA_LEN + SEND_CMD_PRE_TEXT_SZ + text->Length;

        _myFrame = gcnew ArrayList();
//        _myFrame->Add( SOT_VALUE );
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
//        insertMac( mac );
        _myFrame->Add( OUT_TYPE_VALUE );
        _myFrame->Add( (unsigned char)(id >> 8) );
        _myFrame->Add( (unsigned char)id );
        _myFrame->Add( (unsigned char)0U );
        _myFrame->Add( (unsigned char)sendNow );
        _myFrame->Add( (unsigned char)0U );
        _myFrame->Add( (unsigned char)0U );
        insertString( text );
        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
//        _myFrame->Add( EOT_VALUE );

        _status = MESSAGE_STATUS::STATUS_NOT_SENT;
    }
    
    YbMessage( String ^mac, unsigned short id )
    {
        
        int dataLength = FRAME_MIN_DATA_LEN + GET_CMD_PAYLOAD_SZ;

        _myFrame = gcnew ArrayList();
//        _myFrame->Add( SOT_VALUE );
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
//        insertMac( mac );
        _myFrame->Add( REQUEST_TYPE_VALUE );
        _myFrame->Add( (unsigned char)0U );
        _myFrame->Add( (unsigned char)1U );
        _myFrame->Add( (unsigned char)(id >> 8) );
        _myFrame->Add( (unsigned char)id );

        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
//        _myFrame->Add( EOT_VALUE );

        _status = MESSAGE_STATUS::STATUS_NOT_SENT;
    }
    
    YbMessage( unsigned char type, unsigned char *block, int length )
    {
        
        int dataLength = FRAME_MIN_DATA_LEN + length;

        _myFrame = gcnew ArrayList();
//        _myFrame->Add( SOT_VALUE );
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
//        insertMac( mac );
        _myFrame->Add( type );
        for (int i = 0; i < length; ++i)
        {
            _myFrame->Add( block[i] );
        }

        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
//        _myFrame->Add( EOT_VALUE );

        _status = MESSAGE_STATUS::STATUS_NOT_SENT;
    }
    
    ~YbMessage( void )
    {
    }
    
    
    String ^getText( void )
    {

        String ^result = gcnew String("");

        int frameLength = ((unsigned char)_myFrame[LENGTH_HIGH_POSN] << 8) | (unsigned char)_myFrame[LENGTH_LOW_POSN];
        if (frameLength > (GET_RESPONSE_PRE_TEXT_SZ + FRAME_MIN_DATA_LEN))
        {
            int textLength = frameLength - FRAME_MIN_DATA_LEN - GET_RESPONSE_PRE_TEXT_SZ;
            for (int i = 0; i < textLength; ++i )
            {
                char letter[2];
                unsigned char byte = (unsigned char)_myFrame[GET_RESPONSE_TEXT + i];
                letter[0] = (char)byte;
                letter[1] = '\0';
                String ^temp = gcnew String( &letter[0] );
                result = String::Concat( result, temp );
            }
        }
        
        result = String::Concat( result, "\x0d\x0a" );
        return(result);
    }
    
    
    unsigned short getId( void )
    {

        int posn;
        
        switch (getType())
        {
            case 0x80:
                posn = SEND_RESPONSE_ID;
                break;

            case 0x82:
                posn = GET_RESPONSE_ID;
                break;
        }
        
        return(((unsigned char)_myFrame[posn] << 8) | (unsigned char)_myFrame[posn + 1]);
    }

                                              
    unsigned char getType( void )
    {
        return((unsigned char)_myFrame[TYPE_POSN]);
    }


    int frameLength( void )
    {
        return(_myFrame->Count);
    }


    bool addByte( unsigned char byte )
    {
        _myFrame->Add( byte );
        if (1)
//        if ((unsigned char)_myFrame[SOT_POSN] == SOT_VALUE)
        {
            return(isFrame());
        }
        else
        {
            _myFrame->Clear();
            return(false);
        }
    }


    unsigned char getByte( int posn )
    {
        return((unsigned char)_myFrame[posn]);
    }


    void reset( void )
    {
        _myFrame->Clear();
    }




    private:
        ArrayList ^_myFrame;
        int _status;
        
    void insertString( String ^str )
    {
        for (int i = 0; i < str->Length; ++i)
        {
            _myFrame->Add( (unsigned char)str[i] );
        }
    }

    void insertMac( String ^str )
    {
        int macLength = 0;
        
        for (int i = 0; (i < str->Length) && (macLength < 6); ++i)
        {
            unsigned char macByte;
            
            char byte = (char)str[i];
            byte = byte > '9' ? byte - 'A' + 10 : byte - '0';
            if (i & 1)
            {
                macByte = (macByte << 4) | (unsigned char)byte;
                _myFrame->Add( macByte );
                ++macLength;
            }
            else
            {
                macByte = (unsigned char)byte;
            }
        }
        
        for (; macLength < 6; ++macLength)
        {
            _myFrame->Add( (unsigned char)0U );
        }
    }

    unsigned short checksum( bool isCheck )
    {
        int posn = LENGTH_HIGH_POSN;
        int count = _myFrame->Count - SOH_SZ - ( isCheck ? CSUM_SZ : 0);
        unsigned short sum = 0U;
        
        while (count-- != 0)
        {
            sum += (unsigned char)_myFrame[posn];
            ++posn;
        }

        return sum; 
    }


    bool isFrame( void )
    {
        bool result = false;
        int frameSz = _myFrame->Count;
        
        if ( (frameSz >= FRAME_MIN_SZ)
             && 1//((unsigned char)_myFrame[SOT_POSN] == SOT_VALUE)
           )
        {
            int frameLength = ((unsigned char)_myFrame[LENGTH_HIGH_POSN] << 8) | (unsigned char)_myFrame[LENGTH_LOW_POSN];
            if ( 1//((unsigned char)_myFrame[frameSz - 1] == EOT_VALUE)
                 && (frameLength <= (frameSz - LEN_SZ)) )
//                 && ((frameLength - FRAME_MIN_DATA_LEN) == (frameSz - FRAME_MIN_SZ)) )
            {
                int crcPosn = frameLength + LEN_SZ - CSUM_SZ;
                unsigned short crc = ((unsigned char)_myFrame[crcPosn] << 8) | (unsigned char)_myFrame[crcPosn + 1];
//                unsigned short crc = ((unsigned char)_myFrame[frameSz - 2] << 8) | (unsigned char)_myFrame[frameSz - 1];
                if (crc = checksum( true ))
                {
                    if ((frameSz % 20) == 0)
                    {
                        /* Parses out any frame padding */
                        result = true;
                    }
                }
                else
                {
                    _myFrame->Clear();
                }
            }
        }
        
        return(result);
    }


};
