using namespace System;
using namespace System::Collections;
using namespace System::IO::Ports;
#include "fifo.h"

namespace BG
{
    const bool CTS_RTS_FLOW = false;
    
    /* Handles */
    const unsigned char GATT_HANDLE_SERIAL_RX = 38;
    const unsigned char GATT_HANDLE_SERIAL_TX = 41;
    const unsigned char GATT_HANDLE_SERIAL_RTS = 49;
    const unsigned char GATT_HANDLE_SERIAL_CTS = 45;
    const unsigned char GATT_HANDLE_TRACKING_ONOFF = 26;
    const unsigned char GATT_HANDLE_TRACKING_PERIOD = 22;
    const unsigned char GATT_HANDLE_STATUS = 30;
    const unsigned char GATT_HANDLE_BATTERY = 34;
    const unsigned char GATT_HANDLE_MESSAGE_COUNT = 52;

    const unsigned char GATT_HANDLE_PRODUCT = 3;
    const unsigned char GATT_HANDLE_MANUFACTURER = 8;
    const unsigned char GATT_HANDLE_MODEL = 11;
    const unsigned char GATT_HANDLE_SERIAL_NO = 14;
    const unsigned char GATT_HANDLE_SW_VERSION = 17;


    enum
    {
        HANDLE_SERIAL_RX = 0         ,
        HANDLE_SERIAL_TX             ,
        HANDLE_SERIAL_RTS            ,
        HANDLE_SERIAL_CTS            ,
        HANDLE_TRACKING_ONOFF        ,
        HANDLE_TRACKING_PERIOD       ,

        HANDLE_PRODUCT               ,
        HANDLE_MANUFACTURER          ,
        HANDLE_MODEL                 ,
        HANDLE_SERIAL_NO             ,
        HANDLE_SW_VERSION            ,
        
        HANDLE_STATUS,
        HANDLE_BATTERY,
        HANDLE_MESSAGE_COUNT,
    };


    const unsigned char BLE_RESPONSE = 0U;
    const unsigned char BLE_EVENT = 0x80U;

    enum
    {
        BLE_WRITE = 0,             
        BLE_WRITE_NOTIFY,       
        BLE_READ,       
        BLE_SCAN_SET,           
        BLE_SCAN_START,         
        BLE_CONNECT,            
        BLE_DISCONNECT,            
        BLE_SCAN_END,
        BLE_GET_STATUS,
        BLE_GET_INFO,
        BLE_GET_TYPES,
        BLE_SERIAL_WRITE,
        
        BLE_EVT_SCAN,     
        BLE_EVT_CONNECT,  
        BLE_EVT_DONE,     
        BLE_EVT_NEW_VALUE,
        BLE_EVT_DISCONNECT,
        BLE_EVT_INFO,
        BLE_EVT_TYPES,
        BLE_NONE,         
    };
    
    
    /* Fixed byte arrays for all commands */
    const unsigned char  attWrite[] = {8,0x00,0x05,0x04,0x05,0x00,0x00,0x00,0x01};
    const unsigned char  scanSet[] = {9,0x00,0x05,0x06,0x07,0xc8,0x00,0xc8,0x00,0x00};
    const unsigned char  scanStart[] = {5,0x00,0x01,0x06,0x02,0x02};
    const unsigned char  connectReq[] = {19,0x00,0x0f,0x06,0x03,0x27,0xbc,0x71,0x80,0x07,0x00,0x00,0x10,0x00,0x10,0x00,0x64,0x00,0x00,0x00};
//    const unsigned char  connectReq[] = {19,0x00,0x0f,0x06,0x03,0x5c,0xd3,0x60,0x80,0x07,0x00,0x00,0x3c,0x00,0x4c,0x00,0x64,0x00,0x00,0x00};
    const unsigned char  disconnect[] = {5,0x00,0x01,0x03,0x00,0x00};
    const unsigned char  scanEnd[] = {4,0x00,0x00,0x06,0x04};
    const unsigned char  getStatus[] = {5,0x00,0x01,0x03,0x07,0x00};
    const unsigned char  attRead[] = {7,0x00,0x03,0x04,0x04,0x00,0x00,0x00};
    const unsigned char  getInfo[] = {9,0x00,0x05,0x04,0x03,0x00,0x01,0x00,0x64,0x00};
    const unsigned char  getTypes[] = {27,0x00,0x17,0x04,0x00,0x00,0x01,0x00,0x64,0x00,0x01,0x29,0x0f, 0x54,0x72,0x61,0x63,0x6b,0x69,0x6e,0x67,0x20,0x50,0x65,0x72,0x69,0x6f,0x64};

    const unsigned char  testHost[] = {0x27,0xbc,0x71,0x80,0x07,0x00};
    const unsigned char  serialWrite[] = {8,0x00,0x05,0x04,0x05,0x00,0x00,0x00,0x01};


    /* Command byte array ptrs */
    const unsigned char * const commandHdrs[] = 
    {
        attWrite,   /* BLE_WRITE,        */
        attWrite,   /* BLE_WRITE_NOTIFY, */
        attRead,    /* BLE_READ,         */
        scanSet,    /* BLE_SCAN_SET,     */
        scanStart,  /* BLE_SCAN_START,   */
        connectReq, /* BLE_CONNECT,      */
        disconnect, /* BLE_DISCONNECT,   */
        scanEnd,    /* BLE_SCAN_END,     */
        getStatus,  /* BLE_GET_STATUS,   */
        getInfo,    /* BLE_GET_INFO,     */
        getTypes,   /* BLE_GET_TYPES,    */
        serialWrite,/* BLE_SERIAL_WRITE,    */
    };




    /* Fixed byte arrays for all responses */
    const unsigned char rspWrite[]      = {0x00,0x03,0x04,0x05};
    const unsigned char rspRead[]       = {0x00,0x03,0x04,0x04};
    const unsigned char rspScanSet[]    = {0x00,0x05,0x06,0x07};
    const unsigned char rspScanStart[]  = {0x00,0x01,0x06,0x02};
    const unsigned char rspConnect[]    = {0x00,0x0f,0x06,0x03};
    const unsigned char rspDisconnect[] = {0x00,0x03,0x03,0x00};
    const unsigned char rspScanEnd[]    = {0x00,0x02,0x06,0x04};
    const unsigned char rspGetStatus[]  = {0x00,0x01,0x03,0x07};
    const unsigned char rspGetInfo[]  = {0x00,0x03,0x04,0x03};
    const unsigned char rspGetTypes[]  = {0x00,0x03,0x04,0x00};
    const unsigned char rspSerialWrite[]  = {0x00,0x03,0x04,0x05};

    const unsigned char evtScan[]       = {0x80,0x20,0x06,0x00};
    const unsigned char evtConnect[]    = {0x80,0x10,0x03,0x00};
    const unsigned char evtDone[]       = {0x80,0x05,0x04,0x01};
    const unsigned char evtNewValue[]   = {0x80,0x06,0x04,0x05};
    const unsigned char evtDisconnect[] = {0x80,0x03,0x03,0x04};
    const unsigned char evtInfo[]       = {0x80,0x04,0x04,0x04};
    const unsigned char evtTypes[]       = {0x80,0x04,0x04,0x02};

    /* Handles */
    const unsigned char gattHandles[] = 
    {
        GATT_HANDLE_SERIAL_RX       , /* HANDLE_SERIAL_RX,       */
        GATT_HANDLE_SERIAL_TX       , /* HANDLE_SERIAL_TX,       */
        GATT_HANDLE_SERIAL_RTS      , /* HANDLE_SERIAL_RTS,      */
        GATT_HANDLE_SERIAL_CTS      , /* HANDLE_SERIAL_CTS,      */
        GATT_HANDLE_TRACKING_ONOFF  , /* HANDLE_TRACKING_ONOFF,  */
        GATT_HANDLE_TRACKING_PERIOD , /* HANDLE_TRACKING_PERIOD, */

        GATT_HANDLE_PRODUCT         , /* HANDLE_PRODUCT,         */
        GATT_HANDLE_MANUFACTURER    , /* HANDLE_MANUFACTURER,    */
        GATT_HANDLE_MODEL           , /* HANDLE_MODEL,           */
        GATT_HANDLE_SERIAL_NO       , /* HANDLE_SERIAL_NO,       */
        GATT_HANDLE_SW_VERSION      , /* HANDLE_SW_VERSION,      */

        GATT_HANDLE_STATUS          , /* HANDLE_STATUS,          */
        GATT_HANDLE_BATTERY         , /* HANDLE_BATTERY,         */
        GATT_HANDLE_MESSAGE_COUNT   , /* HANDLE_MESSAGE_COUNT,   */
    };
    

    /* Command byte array ptrs */
    const unsigned char * const responseHdrs[] = 
    {
        rspWrite,      /* BLE_WRITE,          */
        rspWrite,      /* BLE_WRITE_NOTIFY,   */
        rspRead,       /* BLE_READ,           */
        rspScanSet,    /* BLE_SCAN_SET,       */
        rspScanStart,  /* BLE_SCAN_START,     */
        rspConnect,    /* BLE_CONNECT,        */
        rspDisconnect, /* BLE_DISCONNECT,     */
        rspScanEnd,    /* BLE_SCAN_END,       */
        rspGetStatus,  /* BLE_GET_STATUS,     */
        rspGetInfo,    /* BLE_GET_INFO,       */
        rspGetTypes,   /* BLE_GET_TYPES,      */
        rspSerialWrite,/* BLE_SERIAL_WRITE,   */

        evtScan,       /* BLE_EVT_SCAN,       */
        evtConnect,    /* BLE_EVT_CONNECT,    */
        evtDone,       /* BLE_EVT_DONE,       */
        evtNewValue,   /* BLE_EVT_NEW_VALUE,  */
        evtDisconnect, /* BLE_EVT_DISCONNECT, */
        evtInfo,       /* BLE_EVT_INFO,       */
        evtTypes,      /* BLE_EVT_TYPES,      */
        0,             /* BLE_NONE,           */
    };


    const int finalResponse[] = 
    {
        BLE_EVT_DONE,       /* BLE_WRITE,        */
        BLE_EVT_DONE,       /* BLE_WRITE_NOTIFY, */
        BLE_EVT_NEW_VALUE,  /* BLE_READ,         */
        BLE_SCAN_SET,       /* BLE_SCAN_SET,     */
        BLE_EVT_SCAN,       /* BLE_SCAN_START,   */
        BLE_EVT_CONNECT,    /* BLE_CONNECT,      */
        BLE_EVT_DISCONNECT, /* BLE_DISCONNECT,   */
        BLE_SCAN_END,       /* BLE_SCAN_END,     */
        BLE_EVT_CONNECT,    /* BLE_GET_STATUS,   */
        BLE_EVT_DONE,       /* BLE_GET_INFO,     */
        BLE_EVT_DONE,       /* BLE_GET_TYPES,    */
        BLE_EVT_DONE,   /* BLE_SERIAL_WRITE, */
    };


    const char *handleStrings[] = 
    {
        "Serial"    , /* HANDLE_SERIAL_RX,       */
        "Serial"    , /* HANDLE_SERIAL_TX,       */
        "RTS"       , /* HANDLE_SERIAL_RTS,      */
        "CTS"       , /* HANDLE_SERIAL_CTS,      */
        "TrkStatus" , /* HANDLE_TRACKING_ONOFF,  */
        "TrkPeriod" , /* HANDLE_TRACKING_PERIOD, */

        ""          , /* HANDLE_PRODUCT,         */
        ""          , /* HANDLE_MANUFACTURER,    */
        ""          , /* HANDLE_MODEL,           */
        ""          , /* HANDLE_SERIAL_NO,       */
        ""          , /* HANDLE_SW_VERSION,      */

        ""          , /* HANDLE_STATUS,          */
        ""          , /* HANDLE_BATTERY,         */
        ""          , /* HANDLE_MESSAGE_COUNT,   */
    };


    const char *commandStrings[] = 
    {
        "Write",         /* BLE_WRITE,          */
        "WriteRaw",      /* BLE_WRITE_NOTIFY,   */
        "Read",          /* BLE_READ,           */
        "ScanSet",       /* BLE_SCAN_SET,       */
        "ScanStart",     /* BLE_SCAN_START,     */
        "Connect",       /* BLE_CONNECT,        */
        "Disconnect",    /* BLE_DISCONNECT,     */
        "ScanEnd",       /* BLE_SCAN_END,       */
        "GetStatus",     /* BLE_GET_STATUS,     */
        "GetInfo",       /* BLE_GET_INFO,       */
        "GetTypes",      /* BLE_GET_TYPES,      */
        "WriteSer",      /* BLE_SERIAL_WRITE,   */

        "ScanResponse",  /* BLE_EVT_SCAN,       */
        "ConnectStatus", /* BLE_EVT_CONNECT,    */
        "Done",          /* BLE_EVT_DONE,       */
        "NewValue",      /* BLE_EVT_NEW_VALUE,  */
        "Disconnected",  /* BLE_EVT_DISCONNECT, */
        "Info",          /* BLE_EVT_INFO,       */
        "Types",         /* BLE_EVT_TYPES,      */
        "?",             /* BLE_NONE,           */
    };



    enum
    {
        DISCONNECTED = 0,
        SCANNING,
        CONNECTED
    };


    const int TICK_INTERVAL = 5;/* ms */
    const int MAX_RESPONSE_TIME = 5;/* Secs */
    const int MAX_RESPONSE_POLLS = ((MAX_RESPONSE_TIME * 1000) / TICK_INTERVAL);

}    






namespace TX_STATE
{
    enum {SEND, RESPONSE};
}

public ref class Ble
{





    public:
    
    Ble( System::Windows::Forms::TextBox ^textBox )
    {
        _commsLog = textBox;
        _CommandQ = gcnew Fifo( 100 );
        _RxQ = gcnew Fifo( 500 );
        _TxQ = gcnew Fifo( 500 );
        _Incoming = gcnew ArrayList();
        _Outgoing = gcnew ArrayList();
        _HostAddress = gcnew ArrayList();

        _portReady = false;
        _connected = BG::DISCONNECTED;
        
        _txState = TX_STATE::SEND;
        _lastCommand = BG::BLE_NONE;
        _response = false;
        _ticker = 0;
        _time = 0;
        _frameSent = false;
    }
    
    
    
    ~Ble( void )
    {
    }
    


    /*
     * Function Name: Attaches to a specified serial COM port.
     * Description:
     * Parameters:
     * Return:
     * Notes:
     */

    String ^ attach( String ^com )
    {
        String ^result = "";
        
        if (!_portReady)
        {
            _ComPort = gcnew SerialPort();
            _portReady = true;
        }
        
        if (!_ComPort->IsOpen)
        {
            _ComPort->PortName = String::Concat( "COM", com );

            _ComPort->BaudRate = 256000;
            _ComPort->Parity = Parity::None;
            _ComPort->StopBits = StopBits::One;
            _ComPort->DataBits = 8;
            _ComPort->Handshake = Handshake::None;
        
            try
            {
                _ComPort->Open();
            }
            catch (System::IO::IOException ^)
            {
                result = "Reset the connection";
            }
            catch (UnauthorizedAccessException ^)
            {
                result = "No access";
            }
            catch (ArgumentOutOfRangeException ^)
            {
                result = "Illegal setting";
            }
            catch (ArgumentException ^)
            {
                result = "Invalid name";
            }
            catch (InvalidOperationException ^)
            {
                result = "Already open";
            }
        }
    
        if ((result == "") && (_ComPort->IsOpen))
        {
            /* Trigger the setup sequence */
            issueCommand( BG::BLE_GET_STATUS, 0 );
        }
        
        return(result);
    }
    
    
    void detach( void )
    {
        /* Disconnect command */
        issueCommand( BG::BLE_DISCONNECT, 0 );
    }
    

    void stopAttach( void )
    {
        /* Disconnect command */
        issueCommand( BG::BLE_SCAN_END, 0 );
    }
    

    bool isOpen( void )
    {
        return(_portReady && (_ComPort->IsOpen));
    }
    

    int isConnected( void )
    {
        return(_connected);
    }
    

    bool isAttached( void )
    {
        return(_portReady);
    }
    

    int bytesWaiting( void )
    {
        return(_RxQ->Count());
    }


    void read( array<unsigned char>^ buffer, int length )
    {
        for (int i = 0; i < length; ++i)
        {
            buffer[i] = (unsigned char)_RxQ->Dequeue();
        }
    }


    void write( array<unsigned char>^ buffer, int length )
    {
        int i;
        
        for (i = 0; i < length; ++i)
        {
            _TxQ->Enqueue( (unsigned char)buffer[i] );
        }
        

        if (1)
        {
            issueCommand( BG::BLE_SERIAL_WRITE, BG::HANDLE_SERIAL_RX );
//            issueCommand( BG::BLE_WRITE, BG::HANDLE_SERIAL_RX );
        }
        else
        {
            int packets = ((length - 1) / 20) + 1;
            for (i = 0; i < packets; ++i)
            {
                issueCommand( BG::BLE_WRITE, BG::HANDLE_SERIAL_RX );
            }
        }
    }


    void writeSetting( int handle, unsigned char byte )
    {
        _TxQ->Enqueue( byte );
        issueCommand( BG::BLE_WRITE, handle );
    }




    void sendTest( void )
    {
        issueCommand( BG::BLE_GET_TYPES, 0 );
    }


    String^ outFsm( void )
    {
        String^ result = "";
        
        ++_ticker;/* Our local 100ms tick counter */
        
        switch (_txState)
        {
            case TX_STATE::SEND:
                if (_CommandQ->Count() != 0)
                {
                    unsigned char handle;
                    int command = _CommandQ->Dequeue();

                    _Outgoing->Clear();
                    
                    _lastCommand = (command >> 8);
                    handle = (unsigned char)(command & 0xff);
                    
                    outCommand( _lastCommand );
                 
                    String ^msg;
                    switch (_lastCommand)
                    {
                        /* Add data to command if any */
                        
                        case BG::BLE_WRITE:
                            msg = gcnew String( BG::handleStrings[handle] );
                            _Outgoing[5] = BG::gattHandles[handle];
                            switch (handle)
                            {
                                case BG::HANDLE_SERIAL_RX:
                                    _Outgoing[1] = (unsigned char)24;
                                    _Outgoing[7] = (unsigned char)20;
                                   
                                    /* Output the next 20 serial bytes  - pad with 0s if necessary */
                                    for (int i = 0; i < 20; ++i)
                                    {
                                        if (_TxQ->Count() != 0)
                                        {
                                            _Outgoing->Add( (unsigned char)_TxQ->Dequeue() );
                                        }
                                        else
                                        {
                                            _Outgoing->Add( (unsigned char)0 );
                                        }
                                    }
                                    break;
                            
                                case BG::HANDLE_TRACKING_ONOFF:
                                case BG::HANDLE_TRACKING_PERIOD:
                                    if (_TxQ->Count() != 0)
                                    {
                                        _Outgoing->Add( (unsigned char)_TxQ->Dequeue() );
                                    }
                                    break;

                                case BG::HANDLE_SERIAL_RTS:
                                    _Outgoing->Add( (unsigned char)0 );
                                    break;

                            }
                            break;
                            
                        case BG::BLE_SERIAL_WRITE:
                            msg = gcnew String( BG::handleStrings[handle] );
                            _Outgoing[5] = BG::gattHandles[handle];
                            switch (handle)
                            {
                                case BG::HANDLE_SERIAL_RX:
                                    _Outgoing[1] = (unsigned char)24;
                                    _Outgoing[7] = (unsigned char)20;
                                   
                                    /* Output the next 20 serial bytes  - pad with 0s if necessary */
                                    for (int i = 0; i < 20; ++i)
                                    {
                                        if (_TxQ->Count() != 0)
                                        {
                                            _Outgoing->Add( (unsigned char)_TxQ->Dequeue() );
                                        }
                                        else
                                        {
                                            _Outgoing->Add( (unsigned char)0 );
                                        }
                                    }
                                    break;
                            }
                            break;
                            
                        case BG::BLE_WRITE_NOTIFY:
                            msg = String::Format( "SetNotify {0}", handle );
                            _Outgoing[5] = handle;
                            _Outgoing[1] = (unsigned char)6;
                            _Outgoing[7] = (unsigned char)2;
                            if ((!BG::CTS_RTS_FLOW) && (handle == BG::GATT_HANDLE_SERIAL_TX + 2))
                            {
                                /* For indications */
                                _Outgoing->Add( (unsigned char)2 );
                            }
                            else
                            {
                                /* For notifications */
                                _Outgoing->Add( (unsigned char)1 );
                            }
                            _Outgoing->Add( (unsigned char)0 );
                            break;

                        case BG::BLE_READ:
                            msg = gcnew String( BG::handleStrings[handle] );
                            _Outgoing[5] = BG::gattHandles[handle];
                            break;
                            
                        case BG::BLE_CONNECT:
                            msg = gcnew String( BG::commandStrings[_lastCommand] );
                            for (int i = 0; i < 6; ++i)
                            {
//                                _Outgoing[4 + i] = _HostAddress[i];
                            }
                            break;
                            
                        default:
                            msg = gcnew String( BG::commandStrings[_lastCommand] );
                            break;
                    }
                    
                    log( String::Concat( "-> ", msg ) );
                    
                    int length = _Outgoing->Count;
                    msg = "";
                    for (int i = 0; i < length; ++i)
                    {
                        msg = String::Concat( msg, String::Format( "{0:X2}", _Outgoing[i] ) );
                    }
                    log( msg );
                    
                    send();
                    _response = false;
                    _time = _ticker;
                    _txState = TX_STATE::RESPONSE;
                }
                break;

            case TX_STATE::RESPONSE:
                if ((_ticker - _time) < BG::MAX_RESPONSE_POLLS)
                {
                    if (_response)
                    {
                        _response = false;
                        _txState = TX_STATE::SEND;
                    }
                }
                else
                {
                    /* Timeout */
                    log( "Rsp timeout" );
                    _CommandQ->Clear();
                    result = "No response";
                    _txState = TX_STATE::SEND;
                }
                break;
        }

        return(result);
    }



    bool inFsm( void )
    {
        bool newSetting = false;
        int lastID;
        
        if (isOpen())
        {
            int length = _ComPort->BytesToRead;
            if (length != 0)
            {
                array<unsigned char>^ buffer = gcnew array<unsigned char>( length );
                _ComPort->Read( buffer, 0, length );

                for (int i = 0; i < length; ++i)
                {
                    _Incoming->Add( buffer[i] );
                    if (isResponse())
                    {
                        lastID = responseIn();
                        if (lastID == BG::finalResponse[_lastCommand])
                        {
                                    if (0)
//                                    if (_lastCommand == BG::BLE_SERIAL_WRITE)
                                    {
                                        log( "Fast Ack" );
                                        if (_TxQ->Count() != 0)
                                        {
                                            issueCommand( BG::BLE_SERIAL_WRITE, BG::HANDLE_SERIAL_RX );
                                        }
                                    }
                            _response = true;
                        }
                        
                        if (lastID == BG::BLE_EVT_NEW_VALUE)
                        {
                            if (isNewSetting())
                            {
                                log( "new set" );
                                newSetting = true;
                            }
                        }
                        
                    
                        /* Start again */
                        _Incoming->Clear();
                    }
                }
            }
        }
        
        return(newSetting);
    }


/*
 * Function Name:
 * Description: Convenience function to check completeness of a receved response
 * Parameters:
 * Return:
 * Notes:
 */

    int newHandle( void )
    {
        return(_newHandle);
    }


    int newSetting( void )
    {
        return(_newValue);
    }

    bool isFrameSent( void )
    {
        return(_frameSent);
    }

    private:
    System::Windows::Forms::TextBox ^_commsLog;
    Fifo ^_CommandQ;
    Fifo ^_RxQ;
    
    Fifo ^_TxQ;
    ArrayList ^_Incoming;
    ArrayList ^_Outgoing;
    ArrayList ^_HostAddress;
    SerialPort^ _ComPort;

    bool _portReady;
    int _connected;
    bool _response;
    int _lastResponse;
    int _txState;
    int _ticker;
    int _time;
    int _lastCommand;
    unsigned char _newHandle;
    unsigned char _newValue;
    bool _frameSent;
        


/*
 * Function Name:
 * Description: Convenience function to encapsulate sending a command via port
 * Parameters:
 * Return:
 * Notes:
 */

    String ^ send( void)
    {
        String^ result = "";
    
        int length = _Outgoing->Count;
        array<unsigned char>^ buffer = gcnew array<unsigned char>( length );
        for (int i = 0; i < length; ++i)
        {
            buffer[i] = (unsigned char)_Outgoing[i];
        }
        

        try
        {
            _ComPort->Write( buffer, 0, length );
        }
        catch (System::IO::IOException ^)
        {
            try
            {
                _ComPort->~SerialPort();
            }
            catch (System::IO::IOException ^)
            {
                result = "Reset the connection";
            }
            _portReady = false;
            _connected = BG::DISCONNECTED;
        }
        
    return(result);
    }





/*
 * Function Name:
 * Description:
 * Parameters:
 * Return:
 * Notes:
 */

    void issueCommand( int command, int handle )
    {
        _CommandQ->Enqueue( (command << 8) | handle );
    }


/*
 * Function Name:
 * Description: Convenience function to construct (most of) a command in the 
 *              'outgoin' buffer.
 * Parameters:
 * Return:
 * Notes:
 */

    void outCommand( int id )
    {
        const unsigned char * const p = BG::commandHdrs[id];

        int i;
        int length = (*p) + 1;
        
        for (i = 1; i < length; ++i)
        {
            _Outgoing->Add( p[i] );
        }
    }



/*
 * Function Name:
 * Description: Convenience function to encapsulate identification and actioning
 *              of a received command
 * Parameters:
 * Return:
 * Notes:
 */

    int responseIn( void )
    {
        int id = 0;
        const unsigned char * p;
        
        while (id != BG::BLE_NONE)
        {
            p = BG::responseHdrs[id];
            if ( (p[0] == (unsigned char)_Incoming[0])
                  && (p[2] == (unsigned char)_Incoming[2])
                  && (p[3] == (unsigned char)_Incoming[3]) )
            {
                String ^msg = gcnew String( BG::commandStrings[id] );
                log( String::Concat( "<- ", msg ) );
            
                switch (id)
                {
                    case BG::BLE_READ:
                    case BG::BLE_WRITE:
                    case BG::BLE_SERIAL_WRITE:
                    case BG::BLE_DISCONNECT:
                    case BG::BLE_GET_INFO:
                        if (((unsigned char)_Incoming[5] | ((unsigned char)_Incoming[6] << 8)) != 0)
                        {
                            /* Error */
                            String ^msg = String::Format( "ErrorWrite {0} {1}", (unsigned char)_Incoming[6], (unsigned char)_Incoming[5] );
                            log( msg );
                        }
                        break;
                        
                    case BG::BLE_SCAN_START:
                        if (((unsigned char)_Incoming[4] | ((unsigned char)_Incoming[5] << 8)) != 0)
                        {
                            /* Error */
                            String ^msg = String::Format( "ErrorScanStart {0} {1}", (unsigned char)_Incoming[5], (unsigned char)_Incoming[4] );
                            log( msg );
                        }
                        else
                        {
                            _connected = BG::SCANNING;
                        }
                        break;

                    case BG::BLE_SCAN_END:
                        if (((unsigned char)_Incoming[4] | ((unsigned char)_Incoming[5] << 8)) != 0)
                        {
                            /* Error */
                            String ^msg = String::Format( "ErrorScanEnd {0} {1}", (unsigned char)_Incoming[5], (unsigned char)_Incoming[4] );
                            log( msg );
                        }
                        else
                        {
                            /* Now close the port */
                            _connected = BG::DISCONNECTED;
                            _ComPort->Close();
                        }
                        break;
                        
                    case BG::BLE_SCAN_SET:
                    case BG::BLE_CONNECT:
                        if (((unsigned char)_Incoming[4] | ((unsigned char)_Incoming[5] << 8)) != 0)
                        {
                            /* Error */
                            String ^msg = String::Format( "ErrorConnect {0} {1}", (unsigned char)_Incoming[5], (unsigned char)_Incoming[4] );
                            log( msg );
                        }
                        break;
                        
                    case BG::BLE_EVT_SCAN:
                        /* Scan response . . so try connection */
                        {
                            int i;
                            _HostAddress->Clear();
                            for (i = 0; i < 6; ++i)
                            {
                                unsigned char testChar = BG::testHost[i];
                                unsigned char rxChar = (unsigned char)_Incoming[6 + i];
                                if (rxChar != testChar)
                                {
                                    break;
                                }
                                _HostAddress->Add( _Incoming[6 + i] );
                            }
                            
                            if (i == 6)
                            {
                                issueCommand( BG::BLE_CONNECT, 0 );
                            }
                        }
                        break;

                    case BG::BLE_EVT_DONE:
                        if (((unsigned char)_Incoming[5] | ((unsigned char)_Incoming[6] << 8)) != 0)
                        {
                            /* Error */
                            String ^msg = String::Format( "ErrorDone {0} {1}", (unsigned char)_Incoming[6], (unsigned char)_Incoming[5] );
                            log( msg );
                        }
                        else
                        {
                            switch ((unsigned char)_Incoming[7])
                            {
                                case BG::GATT_HANDLE_SERIAL_RX:
//                                    if (0)
                                    if (!BG::CTS_RTS_FLOW)
                                    {
                                        log( "Event Ack" );
                                        if (_TxQ->Count() != 0)
                                        {
                                            issueCommand( BG::BLE_SERIAL_WRITE, BG::HANDLE_SERIAL_RX );
                                            _frameSent = false;
                                        }
                                        else
                                        {
                                            _frameSent = true;
                                        }
                                    }
                                    break;
                            }
                        }
                        break;

                    case BG::BLE_EVT_DISCONNECT:
                        /* Now close the port */
                        _connected = BG::DISCONNECTED;
                        _ComPort->Close();
                        break;
                        
                    case BG::BLE_EVT_CONNECT:
                        if (((unsigned char)_Incoming[5] & 0x01) != 0)
                        {
                            /* Connected */
                            if (_connected != BG::CONNECTED)
                            {
                                /* Transition to 'connected' so do any connect housekeeping */
                                _connected = BG::CONNECTED;

                                issueCommand( BG::BLE_READ, BG::HANDLE_TRACKING_ONOFF );
                                issueCommand( BG::BLE_READ, BG::HANDLE_TRACKING_PERIOD );
                                issueCommand( BG::BLE_READ, BG::HANDLE_PRODUCT );
                                issueCommand( BG::BLE_READ, BG::HANDLE_MANUFACTURER );
                                issueCommand( BG::BLE_READ, BG::HANDLE_MODEL );
                                issueCommand( BG::BLE_READ, BG::HANDLE_SERIAL_NO );
//                                issueCommand( BG::BLE_READ, BG::HANDLE_SW_VERSION );
                                
                                issueCommand( BG::BLE_READ, BG::HANDLE_STATUS );
                                issueCommand( BG::BLE_READ, BG::HANDLE_BATTERY );
                                
                                issueCommand( BG::BLE_GET_INFO, 0 );
                                issueCommand( BG::BLE_READ, BG::HANDLE_MESSAGE_COUNT );
                            }
                        }
                        else
                        {
                            if (_connected == BG::DISCONNECTED)
                            {
                                log( "Sending connect . ." );
                                issueCommand( BG::BLE_SCAN_SET, 0 );
                                issueCommand( BG::BLE_SCAN_START, 0 );
                            }
                        }
                        break;
                        
                    case BG::BLE_EVT_NEW_VALUE:
                        switch ((unsigned char)_Incoming[5])
                        {
                            case BG::GATT_HANDLE_SERIAL_CTS:
                                /* Ack for last serial sent, so see if more to send */
                                log( "Cts" );
                                if (_TxQ->Count() != 0)
                                {
                                    issueCommand( BG::BLE_SERIAL_WRITE, BG::HANDLE_SERIAL_RX );
                                    _frameSent = false;
                                }
                                else
                                {
                                    _frameSent = true;
                                }
                                break;

                            case BG::GATT_HANDLE_SERIAL_TX:
                                /* Incoming serial, so add it to any previous */
                                log( "DataIn" );
                                for (int i = 0; i < 20; ++i)
                                {
                                    _RxQ->Enqueue((unsigned char)_Incoming[i + 9]);
                                }
                                
                                /* Ack what was received in case there is more to come */
                                if (BG::CTS_RTS_FLOW)
                                {
                                    issueCommand( BG::BLE_WRITE, BG::HANDLE_SERIAL_RTS );
                                }
                                break;
                                
                            default:
                                break;

                        }
                        break;
                        
                    case BG::BLE_EVT_INFO:
                        {
                            unsigned short uUID = (unsigned char)_Incoming[8] | ((unsigned char)_Incoming[9] << 8);
                            unsigned short handle = (unsigned char)_Incoming[5] | ((unsigned char)_Incoming[6] << 8);
                            String ^msg = String::Format( "Info = {0} {1} {2} {3}", handle, (unsigned char)_Incoming[8], (unsigned char)_Incoming[9], (unsigned char)_Incoming[7] );
                            if (uUID == 0x2902)
                            {
                                issueCommand( BG::BLE_WRITE_NOTIFY, handle );
                            }
                            log( msg );
                        }
                        break;
                        
                    case BG::BLE_EVT_TYPES:
                        {
                            String ^msg = String::Format( "Info = {0} {1} {2} {3} {4}",
                                                          (unsigned char)_Incoming[5] | ((unsigned char)_Incoming[6] << 8),
                                                          (unsigned char)_Incoming[7] | ((unsigned char)_Incoming[8] << 8),
                                                          (unsigned char)_Incoming[9],
                                                          (unsigned char)_Incoming[10],
                                                          (unsigned char)_Incoming[11] );
                            log( msg );
                        }
                        break;
                        
                        
                    default:
                        break;
                }
                break;
            }

            ++id;
        }

        if (id == BG::BLE_NONE)
        {
            String ^msg = String::Format( "Unknown Hdr {0} {1} {2} {3}", _Incoming[0], _Incoming[1], _Incoming[2], _Incoming[3] );
            log( msg );
        }
        else
        {
                    int length = _Incoming->Count;
                    String ^msg = "";
                    for (int i = 0; i < length; ++i)
                    {
                        msg = String::Concat( msg, String::Format( "{0:X2}", _Incoming[i] ) );
                    }
                    log( msg );
            
        }
        return(id);
    }
    
    

/*
 * Function Name:
 * Description: Convenience function to check completeness of a receved response
 * Parameters:
 * Return:
 * Notes:
 */

    bool isResponse( void )
    {
        if ( (_Incoming->Count > 4)
             && (((unsigned char)_Incoming[0] == BG::BLE_RESPONSE) || ((unsigned char)_Incoming[0] == BG::BLE_EVENT))
             && (_Incoming->Count == (unsigned char)_Incoming[1] + 4) )
        {
            return(true);
        }
        else
        {
            return(false);
        }
    }


    bool isNewSetting( void )
    {
        _newHandle = (unsigned char)_Incoming[5];
        if ( (0)
//        if ( (_newHandle == BG::GATT_HANDLE_SERIAL_CTS)
             || (_newHandle == BG::GATT_HANDLE_SERIAL_TX) )
        {
            return(false);
        }
        else
        {
            _newValue = (unsigned char)_Incoming[9];
            return(true);
        }
    }


    void log( String ^msg )
    {
        String ^newline = gcnew String( "\x0d\x0a" );
        _commsLog->AppendText( newline );
        _commsLog->AppendText( msg );
    }
};
