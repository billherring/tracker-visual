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

        static const int FRAME_MIN_DATA_LEN = 3 + 6;// Command | MAC | Csum
        static const int FRAME_MIN_SZ = FRAME_MIN_DATA_LEN + SOH_SZ + LEN_SZ;

        static const int GET_CMD_PAYLOAD_SZ = 2;
        static const int ACK_SENT_PAYLOAD_SZ = 2;
        static const int SEND_CMD_PRE_TEXT_SZ = 2;
        static const int PIN_CMD_PAYLOAD_SZ = 4;
        static const int FACTORY_TYPE_VALUE = 5;
        static const int ACTION_CMD_PAYLOAD_SZ = 1;
        static const int GET_RESPONSE_PRE_TEXT_SZ = 2;


        static const unsigned char SOT_VALUE = (unsigned char)1;
        static const unsigned char EOT_VALUE = (unsigned char)4;

        static const unsigned char OUT_TYPE_VALUE = (unsigned char)1;
        static const unsigned char REQUEST_TYPE_VALUE = (unsigned char)2;
        static const unsigned char ACK_SENT_TYPE_VALUE = (unsigned char)4;
        static const unsigned char DELETE_TYPE_VALUE = (unsigned char)3;
        static const unsigned char PIN_TYPE_VALUE = (unsigned char)7;
        static const unsigned char ACTION_TYPE_VALUE = (unsigned char)8;
        static const unsigned char GENERIC_ALERT_TYPE_VALUE = (unsigned char)9;
        static const unsigned char NMEA_GRAB_TYPE_VALUE = (unsigned char)10;
        static const unsigned char GPRS_SET_TYPE_VALUE = (unsigned char)11;
        static const unsigned char GPRS_REQUEST_TYPE_VALUE = (unsigned char)12;
        static const unsigned char STATUS_TYPE_VALUE = (unsigned char)13;
        static const unsigned char CONFIGURE_TYPE_VALUE = (unsigned char)14;
        static const unsigned char CONFIGURE_GET_TYPE_VALUE = (unsigned char)15;

        static const unsigned char CONFIRM_TYPE_VALUE = (unsigned char)0x01;
        static const unsigned char IN_TYPE_VALUE = (unsigned char)0x02;


        static const int SOT_POSN = 0;
        static const int LENGTH_HIGH_POSN = 0;//1;
        static const int LENGTH_LOW_POSN = 1;//2;
        static const int TYPE_POSN = 2;//3;
        static const int MAC_POSN = 3;//4;
        static const int PAYLOAD_POSN = 9;//4;

        static const int SEND_RESPONSE_ID = PAYLOAD_POSN + 0;
        static const int GET_RESPONSE_TEXT = PAYLOAD_POSN + 2;
        static const int GET_RESPONSE_ID = PAYLOAD_POSN + 0;
        static const int GET_RESPONSE_MSG_COUNT = PAYLOAD_POSN + 0;


    public:
    
    YbMessage( void )
    {
        _myFrame = gcnew ArrayList();
    }
    
    
    YbMessage( String ^mac, int dataLength, unsigned char type )
    {
        

        _myFrame = gcnew ArrayList();
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
        _myFrame->Add( (unsigned char)type );
        insertMac( mac );
    }
    

    YbMessage( String ^mac, unsigned char type )
    {
        
        int dataLength = FRAME_MIN_DATA_LEN;

        _myFrame = gcnew ArrayList();
//        _myFrame->Add( SOT_VALUE );
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
        _myFrame->Add( (unsigned char)type );
        insertMac( mac );

        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
        while ((_myFrame->Count % 20) != 0)
        {
            _myFrame->Add( (unsigned char)0 );
        }
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
        _myFrame->Add( (unsigned char)OUT_TYPE_VALUE );
        insertMac( mac );
        _myFrame->Add( (unsigned char)(id >> 8) );
        _myFrame->Add( (unsigned char)id );
        insertString( text, text->Length );
        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
        while ((_myFrame->Count % 20) != 0)
        {
            _myFrame->Add( (unsigned char)0 );
        }
//        _myFrame->Add( EOT_VALUE );

        _status = MESSAGE_STATUS::STATUS_NOT_SENT;
    }
    
    YbMessage( String ^mac, unsigned short id, unsigned char type)
    {
        
        int dataLength = FRAME_MIN_DATA_LEN + GET_CMD_PAYLOAD_SZ;

        _myFrame = gcnew ArrayList();
//        _myFrame->Add( SOT_VALUE );
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
        _myFrame->Add( (unsigned char)type );
        insertMac( mac );
        _myFrame->Add( (unsigned char)(id >> 8) );
        _myFrame->Add( (unsigned char)id );

        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
        while ((_myFrame->Count % 20) != 0)
        {
            _myFrame->Add( (unsigned char)0 );
        }
//        _myFrame->Add( EOT_VALUE );

        _status = MESSAGE_STATUS::STATUS_NOT_SENT;
    }
    
    YbMessage( String ^mac, unsigned char type, unsigned char *block, int length )
    {
        
        int dataLength = FRAME_MIN_DATA_LEN + length;

        _myFrame = gcnew ArrayList();
//        _myFrame->Add( SOT_VALUE );
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
        _myFrame->Add( (unsigned char)type );
        insertMac( mac );
        for (int i = 0; i < length; ++i)
        {
            _myFrame->Add( block[i] );
        }

        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
        while ((_myFrame->Count % 20) != 0)
        {
            _myFrame->Add( (unsigned char)0 );
        }
//        _myFrame->Add( EOT_VALUE );

        _status = MESSAGE_STATUS::STATUS_NOT_SENT;
    }
    
    YbMessage( ArrayList ^mac, int length, int type )
    {
        
        int dataLength = FRAME_MIN_DATA_LEN + ACK_SENT_PAYLOAD_SZ;

        _myFrame = gcnew ArrayList();
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
        _myFrame->Add( (unsigned char)type );
        for (int i = 0; i < length; ++i)
        {
            _myFrame->Add( (unsigned char)mac[i] );
        }

        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
        while ((_myFrame->Count % 20) != 0)
        {
            _myFrame->Add( (unsigned char)0 );
        }
//        _myFrame->Add( EOT_VALUE );

        _status = MESSAGE_STATUS::STATUS_NOT_SENT;
    }
    



    YbMessage( String ^mac, int unlockPin, int newPin, unsigned char type )
    {
        
        int dataLength = FRAME_MIN_DATA_LEN + PIN_CMD_PAYLOAD_SZ;

        _myFrame = gcnew ArrayList();
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
        _myFrame->Add( type );
        insertMac( mac );
        _myFrame->Add( (unsigned char)(unlockPin >> 8) );
        _myFrame->Add( (unsigned char)unlockPin );
        _myFrame->Add( (unsigned char)(newPin >> 8) );
        _myFrame->Add( (unsigned char)newPin );

        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
        while ((_myFrame->Count % 20) != 0)
        {
            _myFrame->Add( (unsigned char)0 );
        }
//        _myFrame->Add( EOT_VALUE );

        _status = MESSAGE_STATUS::STATUS_NOT_SENT;
    }
    

    YbMessage( String ^mac, unsigned char command, unsigned char type )
    {
        
        int dataLength = FRAME_MIN_DATA_LEN + ACTION_CMD_PAYLOAD_SZ;

        _myFrame = gcnew ArrayList();
        _myFrame->Add( (unsigned char)(dataLength >> 8) );
        _myFrame->Add( (unsigned char)dataLength );
        _myFrame->Add( type );
        insertMac( mac );
        _myFrame->Add( (unsigned char)command );

        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
        while ((_myFrame->Count % 20) != 0)
        {
            _myFrame->Add( (unsigned char)0 );
        }
//        _myFrame->Add( EOT_VALUE );

        _status = MESSAGE_STATUS::STATUS_NOT_SENT;
    }

    ~YbMessage( void )
    {
    }
    
    
    void addChecksum( void )
    {
        unsigned short check = checksum( false );
        _myFrame->Add( (unsigned char)(check >> 8) );
        _myFrame->Add( (unsigned char)check );
        while ((_myFrame->Count % 20) != 0)
        {
            _myFrame->Add( (unsigned char)0 );
        }
    }

    String ^getText( int preTextSz )
    {

        String ^result = gcnew String("");

        int frameLength = ((unsigned char)_myFrame[LENGTH_HIGH_POSN] << 8) | (unsigned char)_myFrame[LENGTH_LOW_POSN];
        if (frameLength > (preTextSz + FRAME_MIN_DATA_LEN))
        {
            int textLength = frameLength - FRAME_MIN_DATA_LEN - preTextSz;
            for (int i = 0; i < textLength; ++i )
            {
                char letter[2];
                unsigned char byte = (unsigned char)_myFrame[PAYLOAD_POSN + preTextSz + i];
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
            case 0x01:
                posn = SEND_RESPONSE_ID;
                break;

            case 0x02:
            case 0x04:
                posn = GET_RESPONSE_ID;
                break;
        }
        
        return(((unsigned char)_myFrame[posn] << 8) | (unsigned char)_myFrame[posn + 1]);
    }

                                              
    unsigned char getType( void )
    {
        return((unsigned char)_myFrame[TYPE_POSN]);
    }


    void setLength( int length )
    {
        length += FRAME_MIN_DATA_LEN;
        _myFrame[LENGTH_HIGH_POSN] = (unsigned char)(length >> 8);
        _myFrame[LENGTH_LOW_POSN] = (unsigned char)(length);
    }


    int frameLength( void )
    {
        return(_myFrame->Count);
    }


    int payloadLength( void )
    {
        int frameLength = ((unsigned char)_myFrame[LENGTH_HIGH_POSN] << 8) | (unsigned char)_myFrame[LENGTH_LOW_POSN];
        return(frameLength - FRAME_MIN_DATA_LEN);
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


    unsigned char getPayloadByte( int posn )
    {
        return((unsigned char)_myFrame[posn + PAYLOAD_POSN]);
    }


    void reset( void )
    {
        _myFrame->Clear();
    }


    void insertString( String ^str, int length )
    {
        int pad = 0;
        
        if (length > str->Length)
        {
            pad = length - str->Length;
            length = str->Length;
        }

        for (int i = 0; i < length; ++i)
        {
            _myFrame->Add( (unsigned char)str[i] );
        }

        for (int i = 0; i < pad; ++i)
        {
            _myFrame->Add( (unsigned char)0U );
        }
    }



    private:
        ArrayList ^_myFrame;
        int _status;
        
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
        int length = 0;
        int count = 0;
        if (_myFrame->Count > LEN_SZ)
        {
            length = ((unsigned char)_myFrame[0] << 8) | (unsigned char)_myFrame[1];
            if (length > 2)
            {
                count = length - SOH_SZ;
            }
        }
        unsigned short sum = 0U;
        
        #if 0
        while (count-- != 0)
        {
            sum += (unsigned char)_myFrame[posn];
            ++posn;
        }
        #else
        while (count != 0)
        {
            unsigned short x; 

            x = ((sum >> 8) ^ (unsigned char)_myFrame[posn]) & 0xff; 
            x ^= (x >> 4); 

            sum = (sum << 8) ^ (x << 12) ^ (x << 5) ^ x; 

            sum &= 0xffff;
            ++posn;
            --count;
        }
        #endif

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
                if (crc == checksum( true ))
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
