#include <windows.h>
//#include <Bthsdpdef.h>
#include "BluetoothAPIs.h"

using namespace System;

public ref class BTDevice
{
    public:
    BTDevice( BLUETOOTH_DEVICE_INFO *device )
    {
        _device = device;
    }
    
    ~BTDevice( void )
    {
    }

    BLUETOOTH_DEVICE_INFO *get( void )
    {
        return(&_device);
    }
    
    private:
    BLUETOOTH_DEVICE_INFO _device;

};
