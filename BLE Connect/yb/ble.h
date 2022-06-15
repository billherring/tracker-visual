using namespace System;
using namespace System::Collections;
using namespace System::IO::Ports;
#include "fifo.h"

namespace BG
{
    const bool CTS_RTS_FLOW = false;
    
    /* Handles */
    const int GATT_HANDLE_NAME                               = 3  ;
    const int GATT_HANDLE_APPEARANCE                         = 5  ;
    const int GATT_HANDLE_SERIAL_NUMBER                      = 8  ;
    const int GATT_HANDLE_SW_VERSION                         = 11 ;
    const int GATT_HANDLE_GPS_STATUS                         = 15 ;
    const int GATT_HANDLE_IRIDIUM_STATUS                     = 19 ;
    const int GATT_HANDLE_TRACKING_PERIOD                    = 23 ;
    const int GATT_HANDLE_GPS_EARLY_WAKEUP_TIME              = 27 ;
    const int GATT_HANDLE_BURST_TX_PERIOD_CELL               = 31 ;
    const int GATT_HANDLE_TRACKING_ONOFF                     = 35 ;
    const int GATT_HANDLE_PIN_LOCK                           = 39 ;
    const int GATT_HANDLE_BURST_FIX                          = 43 ;
    const int GATT_HANDLE_SERIAL_CTS                         = 45 ;
    const int GATT_HANDLE_BURST_TRANSMIT                     = 47 ;
    const int GATT_HANDLE_SERIAL_RTS                         = 49 ;
    const int GATT_HANDLE_GPS_HOT                            = 51 ;
    const int GATT_HANDLE_MAIL_CHECK_PERIOD                  = 55 ;
    const int GATT_HANDLE_MAIL_CHECK_STATUS                  = 59 ;
    const int GATT_HANDLE_GPS_FIX_QUALITY                    = 63 ;
    const int GATT_HANDLE_GPS_SEQUENTIAL_FIXES               = 67 ;
    const int GATT_HANDLE_ACTIVITY_STATUS                    = 71 ;
    const int GATT_HANDLE_GPRS_STRATEGY                      = 75 ;
    const int GATT_HANDLE_ACTIVITY_LOW                       = 79 ;
    const int GATT_HANDLE_TRACKING_REPORT                    = 83 ;
    const int GATT_HANDLE_IMEI                               = 87 ;
    const int GATT_HANDLE_SERIAL_RX                          = 91 ;
    const int GATT_HANDLE_SERIAL_TX                          = 94 ;
    const int GATT_HANDLE_MESSAGE_COUNT                      = 98 ;
    const int GATT_HANDLE_OUTBOX_STATUS                      = 102;
    const int GATT_HANDLE_BATTERY                            = 106;
    const int GATT_HANDLE_TEMPERATURE_ALERT_STATUS           = 111;
    const int GATT_HANDLE_TEMPERATURE_ALERT_HIGH_THRESHOLD   = 115;
    const int GATT_HANDLE_TEMPERATURE_ALERT_LOW_THRESHOLD    = 119;
    const int GATT_HANDLE_TEMPERATURE_ALERT_CHECK_PERIOD     = 123;
    const int GATT_HANDLE_BURST_TX_PERIOD_DISTRESS           = 127;
    const int GATT_HANDLE_POWER_LOSS_ALERT_STATUS            = 131;
    const int GATT_HANDLE_POWER_LIMIT                        = 135;
    const int GATT_HANDLE_GEOF_STATUS                        = 139;
    const int GATT_HANDLE_GEOF_DISTANCE                      = 143;
    const int GATT_HANDLE_GEOF_PERIOD                        = 147;
    const int GATT_HANDLE_NOTIFICATIONS                      = 151;
    const int GATT_HANDLE_COLLISION_STATUS                   = 155;
    const int GATT_HANDLE_COLLISION_THRESHOLD                = 159;
    const int GATT_HANDLE_COLLISION_DURATION                 = 163;
    const int GATT_HANDLE_EXT_TYPE                           = 167;
    const int GATT_HANDLE_EXT_SAMPLES                        = 171;
    const int GATT_HANDLE_EXT_BAUD                           = 175;
    const int GATT_HANDLE_GPX_PERIOD                         = 179;
    const int GATT_HANDLE_GPX_STATUS                         = 183;
    const int GATT_HANDLE_BURST_FIX_PERIOD_CELL              = 187;
    const int GATT_HANDLE_ANDROID                            = 191;
    const int GATT_HANDLE_RAW                                = 195;
    const int GATT_HANDLE_MOB                                = 198;
    const int GATT_HANDLE_POWER                              = 202;
    const int GATT_HANDLE_BURST_FIX_PERIOD_DISTRESS          = 206;
    const int GATT_HANDLE_D_BOARDS                           = 210;
    const int GATT_HANDLE_BLE_VERSION                        = 214;
    const int GATT_HANDLE_GPRS_SIGNAL                        = 217;
    const int GATT_HANDLE_GPRS_STATUS                        = 221;
    const int GATT_HANDLE_GPRS_MSISDN                        = 225;
    const int GATT_HANDLE_GPRS_SIM                           = 228;
    const int GATT_HANDLE_GPRS_LOCATION                      = 231;
    const int GATT_HANDLE_EXT_SENSE                          = 235;
    const int GATT_HANDLE_TRACKING_PERIOD_CELL               = 239;
    const int GATT_HANDLE_TRACKING_PERIOD_DISTRESS           = 243;
    const int GATT_HANDLE_POSITION_BLOCK_FORMAT              = 247;
    const int GATT_HANDLE_SELF_TEST                          = 250;
    const int GATT_HANDLE_SPARE_1                            = 253;
    const int GATT_HANDLE_AIR_VERT_ALERT_STATUS              = 256;
    const int GATT_HANDLE_AIR_ASCENT_ALERT_SPEED             = 257;
    const int GATT_HANDLE_AIR_DESCENT_ALERT_SPEED            = 258;
    const int GATT_HANDLE_AIR_ASCENT_ALERT_TIME              = 259;
    const int GATT_HANDLE_AIR_DESCENT_ALERT_TIME             = 260;
    const int GATT_HANDLE_GPS_PLATFORM                       = 261;
    const int GATT_HANDLE_LOGGING                            = 262;
    const int GATT_HANDLE_AUTO_RESUME_STATUS                 = 263;
    const int GATT_HANDLE_AUTO_RESUME_RADIUS                 = 264;
    const int GATT_HANDLE_FLIGHT_ALERT_STATUS                = 265;
    const int GATT_HANDLE_FLIGHT_VR                          = 266;
    const int GATT_HANDLE_FLIGHT_VS                          = 267;
    const int GATT_HANDLE_BATTERY_MODEL                      = 268;
    const int GATT_HANDLE_TX_CONTEXT                         = 269;
    const int GATT_HANDLE_WATCH_STATUS                       = 270;
    const int GATT_HANDLE_TEST_STATUS                        = 271;
    const int GATT_HANDLE_EXT_SWITCH_STATUS                  = 272;
    const int GATT_HANDLE_SIGNAL_LOSS                        = 273;


//Leopard
    const unsigned char _hostLP[] = {0x0E, 0x4E, 0x1B, 0x80, 0x07, 0x00};
//Tigershark
    const unsigned char _hostTS[] = {0x84, 0x4B, 0x13, 0x80, 0x07, 0x00};
    enum
    {
        HANDLE_NAME                               = 0 ,
        HANDLE_APPEARANCE                         ,
        HANDLE_SERIAL_NUMBER                      ,
        HANDLE_SW_VERSION                         ,
        HANDLE_GPS_STATUS                         ,
        HANDLE_IRIDIUM_STATUS                     ,
        HANDLE_TRACKING_PERIOD                    ,
        HANDLE_GPS_EARLY_WAKEUP_TIME              ,
        HANDLE_BURST_TX_PERIOD_CELL               ,
        HANDLE_TRACKING_ONOFF                     ,
        HANDLE_PIN_LOCK                           ,
        HANDLE_BURST_FIX                          ,
        HANDLE_SERIAL_CTS                         ,
        HANDLE_BURST_TRANSMIT                     ,
        HANDLE_SERIAL_RTS                         ,
        HANDLE_GPS_HOT                            ,
        HANDLE_MAIL_CHECK_PERIOD                  ,
        HANDLE_MAIL_CHECK_STATUS                  ,
        HANDLE_GPS_FIX_QUALITY                    ,
        HANDLE_GPS_SEQUENTIAL_FIXES               ,
        HANDLE_ACTIVITY_STATUS                    ,
        HANDLE_GPRS_STRATEGY                      ,
        HANDLE_ACTIVITY_LOW                       ,
        HANDLE_TRACKING_REPORT                    ,
        HANDLE_IMEI                               ,
        HANDLE_SERIAL_RX                          ,
        HANDLE_SERIAL_TX                          ,
        HANDLE_MESSAGE_COUNT                      ,
        HANDLE_OUTBOX_STATUS                      ,
        HANDLE_BATTERY                            ,
        HANDLE_TEMPERATURE_ALERT_STATUS           ,
        HANDLE_TEMPERATURE_ALERT_HIGH_THRESHOLD   ,
        HANDLE_TEMPERATURE_ALERT_LOW_THRESHOLD    ,
        HANDLE_TEMPERATURE_ALERT_CHECK_PERIOD     ,
        HANDLE_BURST_TX_PERIOD_DISTRESS           ,
        HANDLE_POWER_LOSS_ALERT_STATUS            ,
        HANDLE_POWER_LIMIT                        ,
        HANDLE_GEOF_STATUS                        ,
        HANDLE_GEOF_DISTANCE                      ,
        HANDLE_GEOF_PERIOD                        ,
        HANDLE_NOTIFICATIONS                      ,
        HANDLE_COLLISION_STATUS                   ,
        HANDLE_COLLISION_THRESHOLD                ,
        HANDLE_COLLISION_DURATION                 ,
        HANDLE_EXT_TYPE                           ,
        HANDLE_EXT_SAMPLES                        ,
        HANDLE_EXT_BAUD                           ,
        HANDLE_GPX_PERIOD                         ,
        HANDLE_GPX_STATUS                         ,
        HANDLE_BURST_FIX_PERIOD_CELL              ,
        HANDLE_ANDROID                            ,
        HANDLE_RAW                                ,
        HANDLE_MOB                                ,
        HANDLE_POWER                              ,
        HANDLE_BURST_FIX_PERIOD_DISTRESS          ,
        HANDLE_D_BOARDS                           ,
        HANDLE_BLE_VERSION                        ,
        HANDLE_GPRS_SIGNAL                        ,
        HANDLE_GPRS_STATUS                        ,
        HANDLE_GPRS_MSISDN                        ,
        HANDLE_GPRS_SIM                           ,
        HANDLE_GPRS_LOCATION                      ,
        HANDLE_EXT_SENSE                          ,
        HANDLE_TRACKING_PERIOD_CELL               ,
        HANDLE_TRACKING_PERIOD_DISTRESS           ,
        HANDLE_POSITION_BLOCK_FORMAT              ,
        HANDLE_SELF_TEST                          ,
        HANDLE_SPARE_1                            ,
        HANDLE_AIR_VERT_ALERT_STATUS              ,
        HANDLE_AIR_ASCENT_ALERT_SPEED             ,
        HANDLE_AIR_DESCENT_ALERT_SPEED            ,
        HANDLE_AIR_ASCENT_ALERT_TIME              ,
        HANDLE_AIR_DESCENT_ALERT_TIME             ,
        HANDLE_GPS_PLATFORM                       ,
        HANDLE_LOGGING                            ,
        HANDLE_AUTO_RESUME_STATUS                 ,
        HANDLE_AUTO_RESUME_RADIUS                 ,
        HANDLE_FLIGHT_ALERT_STATUS                ,
        HANDLE_FLIGHT_VR                          ,
        HANDLE_FLIGHT_VS                          ,
        HANDLE_BATTERY_MODEL                      ,
        HANDLE_TX_CONTEXT                         ,
        HANDLE_WATCH_STATUS                       ,
        HANDLE_TEST_STATUS                        ,
        HANDLE_EXT_SWITCH_STATUS                  ,
        HANDLE_SIGNAL_LOSS                        ,
        HANDLE_LAST                               ,
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
        BLE_GET_HANDLES,
        
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
    const unsigned char  connectReq[] = {19,0x00,0x0f,0x06,0x03,0x5c,0xd3,0x60,0x80,0x07,0x00,0x00,0x10,0x00,0x10,0x00,0x64,0x00,0x00,0x00};
//    const unsigned char  connectReq[] = {19,0x00,0x0f,0x06,0x03,0x5c,0xd3,0x60,0x80,0x07,0x00,0x00,0x3c,0x00,0x4c,0x00,0x64,0x00,0x00,0x00};
    const unsigned char  disconnect[] = {5,0x00,0x01,0x03,0x00,0x00};
    const unsigned char  scanEnd[] = {4,0x00,0x00,0x06,0x04};
    const unsigned char  getStatus[] = {5,0x00,0x01,0x03,0x07,0x00};
    const unsigned char  attRead[] = {7,0x00,0x03,0x04,0x04,0x00,0x00,0x00};
    const unsigned char  getInfo[] = {9,0x00,0x05,0x04,0x03,0x00,0x01,0x00,0x2c,0x01};
    const unsigned char  getTypes[] = {27,0x00,0x17,0x04,0x00,0x00,0x01,0x00,0x64,0x00,0x01,0x29,0x0f, 0x54,0x72,0x61,0x63,0x6b,0x69,0x6e,0x67,0x20,0x50,0x65,0x72,0x69,0x6f,0x64};
    const unsigned char  getHandles[] = {26,0x00,0x16,0x04,0x02,0x00,0x01,0x00,0x64,0x00,0x10,0x51,0xab,0x98,0x5f,0x30,0xfb,0x19,0xaf,0xb1,0x47,0x41,0x7e,0x59,0x18,0x70,0xd0};

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
        getHandles, /* BLE_GET_HANDLES,  */
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
    const unsigned char rspGetHandles[]  = {0x00,0x03,0x04,0x02};

    const unsigned char evtScan[]       = {0x80,0x20,0x06,0x00};
    const unsigned char evtConnect[]    = {0x80,0x10,0x03,0x00};
    const unsigned char evtDone[]       = {0x80,0x05,0x04,0x01};
    const unsigned char evtNewValue[]   = {0x80,0x06,0x04,0x05};
    const unsigned char evtDisconnect[] = {0x80,0x03,0x03,0x04};
    const unsigned char evtInfo[]       = {0x80,0x04,0x04,0x04};
    const unsigned char evtTypes[]       = {0x80,0x04,0x04,0x02};

    /* Handles */
    const int gattHandles[] = 
    {
        GATT_HANDLE_NAME                               , /* HANDLE_NAME                               */
        GATT_HANDLE_APPEARANCE                         , /* HANDLE_APPEARANCE                         */
        GATT_HANDLE_SERIAL_NUMBER                      , /* HANDLE_SERIAL_NUMBER                      */
        GATT_HANDLE_SW_VERSION                         , /* HANDLE_SW_VERSION                         */
        GATT_HANDLE_GPS_STATUS                         , /* HANDLE_GPS_STATUS                         */
        GATT_HANDLE_IRIDIUM_STATUS                     , /* HANDLE_IRIDIUM_STATUS                     */
        GATT_HANDLE_TRACKING_PERIOD                    , /* HANDLE_TRACKING_PERIOD                    */
        GATT_HANDLE_GPS_EARLY_WAKEUP_TIME              , /* HANDLE_GPS_EARLY_WAKEUP_TIME              */
        GATT_HANDLE_BURST_TX_PERIOD_CELL               , /* HANDLE_BURST_TX_PERIOD_CELL               */
        GATT_HANDLE_TRACKING_ONOFF                     , /* HANDLE_TRACKING_ONOFF                     */
        GATT_HANDLE_PIN_LOCK                           , /* HANDLE_PIN_LOCK                           */
        GATT_HANDLE_BURST_FIX                          , /* HANDLE_BURST_FIX                          */
        GATT_HANDLE_SERIAL_CTS                         , /* HANDLE_SERIAL_CTS                         */
        GATT_HANDLE_BURST_TRANSMIT                     , /* HANDLE_BURST_TRANSMIT                     */
        GATT_HANDLE_SERIAL_RTS                         , /* HANDLE_SERIAL_RTS                         */
        GATT_HANDLE_GPS_HOT                            , /* HANDLE_GPS_HOT                            */
        GATT_HANDLE_MAIL_CHECK_PERIOD                  , /* HANDLE_MAIL_CHECK_PERIOD                  */
        GATT_HANDLE_MAIL_CHECK_STATUS                  , /* HANDLE_MAIL_CHECK_STATUS                  */
        GATT_HANDLE_GPS_FIX_QUALITY                    , /* HANDLE_GPS_FIX_QUALITY                    */
        GATT_HANDLE_GPS_SEQUENTIAL_FIXES               , /* HANDLE_GPS_SEQUENTIAL_FIXES               */
        GATT_HANDLE_ACTIVITY_STATUS                    , /* HANDLE_ACTIVITY_STATUS                    */
        GATT_HANDLE_GPRS_STRATEGY                      , /* HANDLE_GPRS_STRATEGY                      */
        GATT_HANDLE_ACTIVITY_LOW                       , /* HANDLE_ACTIVITY_LOW                       */
        GATT_HANDLE_TRACKING_REPORT                    , /* HANDLE_TRACKING_REPORT                    */
        GATT_HANDLE_IMEI                               , /* HANDLE_IMEI                               */
        GATT_HANDLE_SERIAL_RX                          , /* HANDLE_SERIAL_RX                          */
        GATT_HANDLE_SERIAL_TX                          , /* HANDLE_SERIAL_TX                          */
        GATT_HANDLE_MESSAGE_COUNT                      , /* HANDLE_MESSAGE_COUNT                      */
        GATT_HANDLE_OUTBOX_STATUS                      , /* HANDLE_OUTBOX_STATUS                      */
        GATT_HANDLE_BATTERY                            , /* HANDLE_BATTERY                            */
        GATT_HANDLE_TEMPERATURE_ALERT_STATUS           , /* HANDLE_TEMPERATURE_ALERT_STATUS           */
        GATT_HANDLE_TEMPERATURE_ALERT_HIGH_THRESHOLD   , /* HANDLE_TEMPERATURE_ALERT_HIGH_THRESHOLD   */
        GATT_HANDLE_TEMPERATURE_ALERT_LOW_THRESHOLD    , /* HANDLE_TEMPERATURE_ALERT_LOW_THRESHOLD    */
        GATT_HANDLE_TEMPERATURE_ALERT_CHECK_PERIOD     , /* HANDLE_TEMPERATURE_ALERT_CHECK_PERIOD     */
        GATT_HANDLE_BURST_TX_PERIOD_DISTRESS           , /* HANDLE_BURST_TX_PERIOD_DISTRESS           */
        GATT_HANDLE_POWER_LOSS_ALERT_STATUS            , /* HANDLE_POWER_LOSS_ALERT_STATUS            */
        GATT_HANDLE_POWER_LIMIT                        , /* HANDLE_POWER_LIMIT                        */
        GATT_HANDLE_GEOF_STATUS                        , /* HANDLE_GEOF_STATUS                        */
        GATT_HANDLE_GEOF_DISTANCE                      , /* HANDLE_GEOF_DISTANCE                      */
        GATT_HANDLE_GEOF_PERIOD                        , /* HANDLE_GEOF_PERIOD                        */
        GATT_HANDLE_NOTIFICATIONS                      , /* HANDLE_NOTIFICATIONS                      */
        GATT_HANDLE_COLLISION_STATUS                   , /* HANDLE_COLLISION_STATUS                   */
        GATT_HANDLE_COLLISION_THRESHOLD                , /* HANDLE_COLLISION_THRESHOLD                */
        GATT_HANDLE_COLLISION_DURATION                 , /* HANDLE_COLLISION_DURATION                 */
        GATT_HANDLE_EXT_TYPE                           , /* HANDLE_EXT_TYPE                           */
        GATT_HANDLE_EXT_SAMPLES                        , /* HANDLE_EXT_SAMPLES                        */
        GATT_HANDLE_EXT_BAUD                           , /* HANDLE_EXT_BAUD                           */
        GATT_HANDLE_GPX_PERIOD                         , /* HANDLE_GPX_PERIOD                         */
        GATT_HANDLE_GPX_STATUS                         , /* HANDLE_GPX_STATUS                         */
        GATT_HANDLE_BURST_FIX_PERIOD_CELL              , /* HANDLE_BURST_FIX_PERIOD_CELL              */
        GATT_HANDLE_ANDROID                            , /* HANDLE_ANDROID                            */
        GATT_HANDLE_RAW                                , /* HANDLE_RAW                                */
        GATT_HANDLE_MOB                                , /* HANDLE_MOB                                */
        GATT_HANDLE_POWER                              , /* HANDLE_POWER                              */
        GATT_HANDLE_BURST_FIX_PERIOD_DISTRESS          , /* HANDLE_BURST_FIX_PERIOD_DISTRESS          */
        GATT_HANDLE_D_BOARDS                           , /* HANDLE_D_BOARDS                           */
        GATT_HANDLE_BLE_VERSION                        , /* HANDLE_BLE_VERSION                        */     
        GATT_HANDLE_GPRS_SIGNAL                        , /* HANDLE_GPRS_SIGNAL                        */     
        GATT_HANDLE_GPRS_STATUS                        , /* HANDLE_GPRS_STATUS                        */     
        GATT_HANDLE_GPRS_MSISDN                        , /* HANDLE_GPRS_MSISDN                        */     
        GATT_HANDLE_GPRS_SIM                           , /* HANDLE_GPRS_SIM                           */     
        GATT_HANDLE_GPRS_LOCATION                      , /* HANDLE_GPRS_LOCATION                      */     
        GATT_HANDLE_EXT_SENSE                          , /* HANDLE_EXT_SENSE                          */     
        GATT_HANDLE_TRACKING_PERIOD_CELL               , /* HANDLE_TRACKING_PERIOD_CELL               */     
        GATT_HANDLE_TRACKING_PERIOD_DISTRESS           , /* HANDLE_TRACKING_PERIOD_DISTRESS           */     
        GATT_HANDLE_POSITION_BLOCK_FORMAT              , /* HANDLE_POSITION_BLOCK_FORMAT              */     
        GATT_HANDLE_SELF_TEST                          , /* HANDLE_SELF_TEST                          */     
        GATT_HANDLE_SPARE_1                            , /* HANDLE_SPARE_1                            */     
        GATT_HANDLE_AIR_VERT_ALERT_STATUS              , /* HANDLE_AIR_VERT_ALERT_STATUS              */     
        GATT_HANDLE_AIR_ASCENT_ALERT_SPEED             , /* HANDLE_AIR_ASCENT_ALERT_SPEED             */     
        GATT_HANDLE_AIR_DESCENT_ALERT_SPEED            , /* HANDLE_AIR_DESCENT_ALERT_SPEED            */     
        GATT_HANDLE_AIR_ASCENT_ALERT_TIME              , /* HANDLE_AIR_ASCENT_ALERT_TIME              */     
        GATT_HANDLE_AIR_DESCENT_ALERT_TIME             , /* HANDLE_AIR_DESCENT_ALERT_TIME             */     
        GATT_HANDLE_GPS_PLATFORM                       , /* HANDLE_GPS_PLATFORM                       */     
        GATT_HANDLE_LOGGING                            , /* HANDLE_LOGGING                            */     
        GATT_HANDLE_AUTO_RESUME_STATUS                 , /* HANDLE_AUTO_RESUME_STATUS                 */     
        GATT_HANDLE_AUTO_RESUME_RADIUS                 , /* HANDLE_AUTO_RESUME_RADIUS                 */     
        GATT_HANDLE_FLIGHT_ALERT_STATUS                , /* HANDLE_FLIGHT_ALERT_STATUS                */     
        GATT_HANDLE_FLIGHT_VR                          , /* HANDLE_FLIGHT_VR                          */     
        GATT_HANDLE_FLIGHT_VS                          , /* HANDLE_FLIGHT_VS                          */     
        GATT_HANDLE_BATTERY_MODEL                      , /* HANDLE_BATTERY_MODEL                      */     
        GATT_HANDLE_TX_CONTEXT                         , /* HANDLE_TX_CONTEXT                         */     
        GATT_HANDLE_WATCH_STATUS                       , /* HANDLE_WATCH_STATUS                       */     
        GATT_HANDLE_TEST_STATUS                        , /* HANDLE_TEST_STATUS                        */     
        GATT_HANDLE_EXT_SWITCH_STATUS                  , /* HANDLE_EXT_SWITCH_STATUS                  */     
        GATT_HANDLE_SIGNAL_LOSS                        , /* HANDLE_SIGNAL_LOSS                        */     
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
        rspGetHandles, /* BLE_GET_HANDLES,    */

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
        BLE_SCAN_START,     /* BLE_SCAN_START,   */
        BLE_EVT_CONNECT,    /* BLE_CONNECT,      */
        BLE_EVT_DISCONNECT, /* BLE_DISCONNECT,   */
        BLE_SCAN_END,       /* BLE_SCAN_END,     */
        BLE_EVT_CONNECT,    /* BLE_GET_STATUS,   */
        BLE_EVT_DONE,       /* BLE_GET_INFO,     */
        BLE_EVT_DONE,       /* BLE_GET_TYPES,    */
        BLE_EVT_DONE,       /* BLE_GET_HANDLES,  */
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
        "GetHandles",    /* BLE_GET_HANDLES,    */

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


    enum
    {
        OUT_OK = 0,
        OUT_WRITE_DIRECT,
        OUT_READ_DIRECT,
        OUT_ERROR
    };


    const int TICK_INTERVAL = 1;/* ms */
    const int MAX_RESPONSE_TIME = 4;/* Secs */
    const int MAX_RESPONSE_POLLS = ((MAX_RESPONSE_TIME * 1000) / TICK_INTERVAL);

}    






namespace TX_STATE
{
    enum {SEND, RESPONSE};
}

public ref class Ble
{





    public:
    
    Ble( System::Windows::Forms::TextBox ^textBox, System::Windows::Forms::ListBox ^listBox )
    {
        _commsLog = textBox;
        _scanList = listBox;
        _CommandQ = gcnew Fifo( 100 );
        _SettingQ = gcnew Fifo( 100 );
        _RxQ = gcnew Fifo( 500 );
        _TxQ = gcnew Fifo( 500 );
        _AllReceived = gcnew ArrayList();
        _Incoming = gcnew ArrayList();
        _Outgoing = gcnew ArrayList();
        _NewSetting = gcnew ArrayList();
        _HostAddress = gcnew ArrayList();

        _portReady = false;
        _connected = BG::DISCONNECTED;
        
        _txState = TX_STATE::SEND;
        _lastCommand = BG::BLE_NONE;
        _lastHandle = 0;
        _gattHandle = 0;
        _response = false;
        _ticker = 0;
        _time = 0;
        
        _test = false;
        _frameSent = false;
        _androidSimulate = false;
        _uuids = false;
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
    

    void connectToSelected( void )
    {
        String^ selectedHost = (String ^)_scanList->SelectedItem;
        for (int i = 0; i < 6; ++i)
        {
            unsigned char chr;
            unsigned char byte;
            
            chr = (unsigned char)selectedHost[10 - (i * 2)];
            byte = (chr <= '9') ? chr - '0' : chr - 'A' + 0x0A;
            byte <<= 4;
            chr = (unsigned char)selectedHost[11 - (i * 2)];
            byte |= (chr <= '9') ? chr - '0' : chr - 'A' + 0x0A;
            _HostAddress->Add( byte );
        }
        issueCommand( BG::BLE_CONNECT, 0 );
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


    unsigned char readByte( void )
    {
        return((unsigned char)_RxQ->Dequeue());
    }


    void write( array<unsigned char>^ buffer, int length )
    {
        if (length != 0)
        {
            for (int i = 0; i < length; ++i)
            {
                _TxQ->Enqueue( (unsigned char)buffer[i] );
            }
            issueCommand( BG::BLE_WRITE, BG::HANDLE_SERIAL_RX );
        }
    }


    void writeSetting( int handle, unsigned char byte )
    {
        _SettingQ->Enqueue( byte );
        issueCommand( BG::BLE_WRITE, handle );
    }




    void sendTest( void )
    {
        _AllReceived->Clear();
    }


    void stopTest( void )
    {
    }

    void reset( void )
    {
        issueCommand( BG::BLE_READ, BG::GATT_HANDLE_NAME );
        issueCommand( BG::BLE_READ, BG::GATT_HANDLE_RAW );
    }




    //Timing
    int timeReference( void )
    {
        DateTime ^timeNow = DateTime::Now;
        return(timeNow->Second);
    }
    
    
    int timeElapsedSince( int startTime )
    {
        return((60 + timeReference() - startTime) % 60);
    }
    

    int outFsm( void )
    {
        int result = BG::OUT_OK;
        
        ++_ticker;/* Our local 100ms tick counter */
        
        switch (_txState)
        {
            case TX_STATE::SEND:
                if (_CommandQ->Count() != 0)
                {
                    int handle;
                    int command = _CommandQ->Dequeue();

                    _Outgoing->Clear();
                    
                    _lastCommand = (command >> 16);
                    handle = (command & 0xffff);
                    _lastHandle = handle;
                    
                    outCommand( _lastCommand );
                 
                    String ^msg;
                    switch (_lastCommand)
                    {
                        /* Add data to command if any */
                        
                        case BG::BLE_WRITE:
                            msg = "";
                            
                            _gattHandle = BG::gattHandles[handle];
                            _Outgoing[5] = (unsigned char)_gattHandle;
                            _Outgoing[6] = (unsigned char)(_gattHandle >> 8);
                            switch (handle)
                            {
                                case BG::HANDLE_SERIAL_RX:
                                    {
                                        /* Output the next 20 serial bytes  - pad with 0s if necessary */
                                        int i;
                                        for (i = 0; i < 20; ++i)
                                        {
                                            if (_TxQ->Count() != 0)
                                            {
                                                _Outgoing->Add( (unsigned char)_TxQ->Dequeue() );
                                            }
                                            else
                                            {
                                                break;
                                            }
                                        }
                                        if (i == 0)
                                        {
                                            _Outgoing->Clear();
                                        }
                                        else
                                        {
                                            _Outgoing[1] = (unsigned char)(i + 4);
                                            _Outgoing[7] = (unsigned char)i;
                                        }
                                    }
                                    break;
                            
                                case BG::HANDLE_TRACKING_ONOFF:
                                case BG::HANDLE_TRACKING_PERIOD:
                                case BG::HANDLE_BURST_FIX:
                                case BG::HANDLE_BURST_TRANSMIT:
                                case BG::HANDLE_GPS_HOT:
                                case BG::HANDLE_EXT_TYPE:
                                case BG::HANDLE_EXT_BAUD:
                                case BG::HANDLE_EXT_SAMPLES:
                                case BG::HANDLE_MOB:
                                case BG::HANDLE_ACTIVITY_STATUS:
                                case BG::HANDLE_GPRS_STRATEGY:
                                case BG::HANDLE_ACTIVITY_LOW:
                                case BG::HANDLE_GEOF_STATUS:
                                case BG::HANDLE_GEOF_PERIOD:
                                case BG::HANDLE_GEOF_DISTANCE:
                                case BG::HANDLE_POWER_LIMIT:
                                case BG::HANDLE_NOTIFICATIONS:
                                case BG::HANDLE_EXT_SENSE:
                                case BG::HANDLE_BURST_TX_PERIOD_CELL     :
                                case BG::HANDLE_BURST_TX_PERIOD_DISTRESS :
                                case BG::HANDLE_BURST_FIX_PERIOD_DISTRESS:
                                case BG::HANDLE_BURST_FIX_PERIOD_CELL    :
                                case BG::HANDLE_TRACKING_PERIOD_CELL     :
                                case BG::HANDLE_TRACKING_PERIOD_DISTRESS :
                                case BG::HANDLE_POSITION_BLOCK_FORMAT    :
                                case BG::HANDLE_GPX_STATUS               :
                                case BG::HANDLE_GPX_PERIOD               :
                                case BG::HANDLE_MAIL_CHECK_STATUS        :
                                case BG::HANDLE_MAIL_CHECK_PERIOD        :
                                case BG::HANDLE_AIR_VERT_ALERT_STATUS    :
                                case BG::HANDLE_AIR_ASCENT_ALERT_SPEED   :
                                case BG::HANDLE_AIR_DESCENT_ALERT_SPEED  :
                                case BG::HANDLE_AIR_ASCENT_ALERT_TIME    :
                                case BG::HANDLE_AIR_DESCENT_ALERT_TIME   :
                                case BG::HANDLE_GPS_PLATFORM             :
                                case BG::HANDLE_LOGGING                  :
                                case BG::HANDLE_AUTO_RESUME_STATUS       :
                                case BG::HANDLE_AUTO_RESUME_RADIUS       :
                                case BG::HANDLE_FLIGHT_ALERT_STATUS      :
                                case BG::HANDLE_FLIGHT_VR                :
                                case BG::HANDLE_FLIGHT_VS                :
                                case BG::HANDLE_BATTERY_MODEL            :
                                    if (_gattHandle < 256)
                                    {
                                        if (_SettingQ->Count() != 0)
                                        {
                                            _Outgoing->Add( (unsigned char)_SettingQ->Dequeue() );
                                        }
                                    }
                                    else
                                    {
                                        _Outgoing->Clear();
                                        result = BG::OUT_WRITE_DIRECT;
                                    }
                                    break;

                                case BG::HANDLE_SERIAL_RTS:
                                    _Outgoing->Add( (unsigned char)0 );
                                    break;

                            }
                            break;
                            
                        case BG::BLE_WRITE_NOTIFY:
                            msg = String::Format( "SetNotify {0}", handle );
                            _Outgoing[5] = (unsigned char)handle;
                            _Outgoing[1] = (unsigned char)6;
                            _Outgoing[7] = (unsigned char)2;
                            if (attributeGroup( BG::GATT_HANDLE_SERIAL_TX, handle ) || attributeGroup( BG::GATT_HANDLE_OUTBOX_STATUS, handle ))
                            {
                                /* For indications */
                                _Outgoing->Add( (unsigned char)2 );
                            }
                            else
                            {
                                /* For notifications */
                                if (_androidSimulate)
                                {
                                    if (attributeGroup( BG::GATT_HANDLE_MESSAGE_COUNT, handle ) || attributeGroup( BG::GATT_HANDLE_ANDROID, handle ))
                                    {
                                        _Outgoing->Add( (unsigned char)1 );
                                    }
                                    else
                                    {
                                        _Outgoing->Add( (unsigned char)0 );
                                    }
                                }
                                else/* IOS */
                                {
                                    if (attributeGroup( BG::GATT_HANDLE_ANDROID, handle ))
                                    {
                                        _Outgoing->Add( (unsigned char)1 );
//                                        _Outgoing->Add( (unsigned char)0 );
                                    }
                                    else
                                    {
                                        _Outgoing->Add( (unsigned char)1 );
                                    }
                                }
                            }
                            _Outgoing->Add( (unsigned char)0 );
                            break;

                        case BG::BLE_READ:
                            _gattHandle = handle;
                            if (_gattHandle < 256)
                            {
                                msg = "";
                                _Outgoing[5] = (unsigned char)handle;
                            }
                            else
                            {
                                _Outgoing->Clear();
                                result = BG::OUT_READ_DIRECT;
                            }
                            break;
                            
                        case BG::BLE_CONNECT:
                            msg = gcnew String( BG::commandStrings[_lastCommand] );
                            for (int i = 0; i < 6; ++i)
                            {
                                _Outgoing[4 + i] = _HostAddress[i];
                            }
                            break;
                            
                        default:
                            msg = gcnew String( BG::commandStrings[_lastCommand] );
                            break;
                    }
                    
                    
                    int length = _Outgoing->Count;
                    
                    if (length != 0)
                    {
                        log( String::Concat( "-> ", msg ) );
                        msg = "";
                        for (int i = 0; i < length; ++i)
                        {
                            msg = String::Concat( msg, String::Format( "{0:X2}", _Outgoing[i] ) );
                        }
                        
                        log( msg );

                        send();
                        _response = false;
                        _time = timeReference();
                        _txState = TX_STATE::RESPONSE;
                    
                    }
                }
                break;

            case TX_STATE::RESPONSE:
                if (timeElapsedSince( _time ) < 10)
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
                    _txState = TX_STATE::SEND;
//                    stopAttach();
//                    _connected = BG::DISCONNECTED;
                    result = BG::OUT_ERROR;
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
            if (_ComPort->BytesToRead != 0)
            {
                array<unsigned char>^ buffer = gcnew array<unsigned char>( 1 );

                while (isOpen() && (_ComPort->BytesToRead != 0) && (_response == false) && (newSetting == false))
                {
                    _ComPort->Read( buffer, 0, 1 );
                    _Incoming->Add( buffer[0] );
                    _AllReceived->Add( buffer[0] );
                    if (isResponse())
                    {
                        int reqdResponse = BG::finalResponse[_lastCommand];
                        lastID = responseIn();
                        if (lastID == reqdResponse)
                        {
                            if (reqdResponse == BG::BLE_EVT_NEW_VALUE)
                            {
                                unsigned char handle = (unsigned char)_Incoming[5];
                                if (handle == _lastHandle)
                                {
                                    _response = true;
                                }
                            }
                            else
                            {
                                _response = true;
                            }
                        }
                        
                        if (lastID == BG::BLE_EVT_DONE)
                        {
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


    int newHandle( void )
    {
        return(_newHandle);
    }


    int currentHandle( void )
    {
        return(_gattHandle);
    }


    unsigned char currentSetting( void )
    {
        return((unsigned char)_SettingQ->Dequeue());
    }


    int getHandle( int id )
    {
        return(BG::gattHandles[id]);
    }


    unsigned char newSetting( int posn )
    {
        return((unsigned char)_NewSetting[posn]);
    }



    void test( void )
    {
        issueCommand( BG::BLE_READ, BG::HANDLE_MESSAGE_COUNT );
    }


    void log( String ^msg )
    {
        String ^newline = gcnew String( "\x0d\x0a" );
        _commsLog->AppendText( newline );
        _commsLog->AppendText( msg );
    }


    bool isFrameSent( void )
    {
        return(_frameSent);
    }
    
    void android( bool status )
    {
        _androidSimulate = status;
    }


    void uuids( bool status )
    {
        _uuids = status;
    }


    private:
    System::Windows::Forms::TextBox ^_commsLog;
    System::Windows::Forms::ListBox ^_scanList;
    Fifo ^_CommandQ;
    Fifo ^_SettingQ;
    Fifo ^_RxQ;
    
    Fifo ^_TxQ;
    ArrayList ^_AllReceived;
    ArrayList ^_Incoming;
    ArrayList ^_Outgoing;
    ArrayList ^_HostAddress;
    ArrayList ^_NewSetting;
    SerialPort^ _ComPort;

    bool _portReady;
    int _connected;
    bool _response;
    int _lastResponse;
    int _txState;
    int _ticker;
    int _time;
    int _lastCommand;
    int _lastHandle;
    int _gattHandle;
    unsigned char _newHandle;
    unsigned char _newValue;
    bool _test;
    bool _frameSent;
    bool _androidSimulate;
    bool _uuids;
    String ^ _targetMacString;


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
        

        if (_ComPort->IsOpen)
        {
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
        }
        else
        {
            result = "No comms";
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
        _CommandQ->Enqueue( (command << 16) | handle );
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
                        {
                            /* Scan response . . so try connection */
                            int i;
                            _HostAddress->Clear();
                            String ^msg = "";
                            
                            if (_uuids == false)
                            {
                                for (i = 0; i < 6; ++i)
                                {
                                    msg = String::Concat( msg, String::Format( "{0:X2}", _Incoming[11 - i] ) );// Reverse the little endian 
                                }
                            }
                            else
                            {
                                unsigned char inLength = (unsigned char)_Incoming[14] + 1;
                                for (i = 0; i < inLength; ++i)
                                {
                                    msg = String::Concat( msg, String::Format( "{0:X2}", _Incoming[14 + i] ) );
                                }
                            }
                            
                            for (i = 0; i < _scanList->Items->Count; ++i)
                            {
                                if (String::Compare( (String ^)_scanList->Items[i], msg ) == 0)
                                {
                                    break;
                                }
                            }
                            
                            if (i == _scanList->Items->Count)
                            {
                                _scanList->Items->Add( msg );
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
                                    if (!BG::CTS_RTS_FLOW)
                                    {
                                        log( "Event Ack" );
                                        if (_TxQ->Count() != 0)
                                        {
                                            issueCommand( BG::BLE_WRITE, BG::HANDLE_SERIAL_RX );
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

                                issueCommand( BG::BLE_GET_INFO, 0 );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_BATTERY );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_SW_VERSION );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_IMEI );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_NAME );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_BLE_VERSION );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_RAW );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_POWER );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_D_BOARDS );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_GPRS_MSISDN );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_GPRS_SIM );
                                
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_GPRS_SIGNAL );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_GPRS_STATUS );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_GPRS_LOCATION );
                                
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_TX_CONTEXT   );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_WATCH_STATUS );
                                issueCommand( BG::BLE_READ, BG::GATT_HANDLE_TEST_STATUS );
                                
                                
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
                                        issueCommand( BG::BLE_WRITE, BG::HANDLE_SERIAL_RX );
                                    }
                                    break;

                                case BG::GATT_HANDLE_SERIAL_TX:
                                {
                                    /* Incoming serial, so add it to any previous */
                                    log( "DataIn" );
                                    int length = (unsigned char)_Incoming[8];
                                    for (int i = 0; i < length; ++i)
                                    {
                                        _RxQ->Enqueue((unsigned char)_Incoming[i + 9]);
                                    }
                                
                                    /* Ack what was received in case there is more to come */
                                    if (BG::CTS_RTS_FLOW)
                                    {
                                        issueCommand( BG::BLE_WRITE, BG::HANDLE_SERIAL_RTS );
                                    }
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
        if ( (_newHandle == BG::GATT_HANDLE_SERIAL_CTS)
             || (_newHandle == BG::GATT_HANDLE_SERIAL_TX) )
        {
            return(false);
        }
        else if (_newHandle == BG::GATT_HANDLE_ANDROID)
        {
            unsigned int rdHandle = ((unsigned char)_Incoming[9]) << 8;
            rdHandle |= (unsigned char)_Incoming[10];

            if ((_androidSimulate) || (rdHandle > 255))
            {
                issueCommand( BG::BLE_READ, rdHandle );
            }

            return(false);
        }
        else
        {
            _NewSetting->Clear();
            int length = (unsigned char)_Incoming[8];
            for (int i = 0; i < length; ++i)
            {
                _NewSetting->Add( (unsigned char)_Incoming[9 + i] );
            }
            if (length != 0)
            {
                _newValue = (unsigned char)_Incoming[9];
                return(true);
            }
            else
            {
                log( "No Setting" );
                return(false);
            }
        }
    }

    bool attributeGroup( unsigned char group, int handle )
    {
        return((handle >= group) && (handle < (group + 4)));
    }





};
