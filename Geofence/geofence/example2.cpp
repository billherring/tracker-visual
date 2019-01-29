
    #include "pack.h"




    const int LAT_DATUM = (90U * 100000U * 10U);/* x10 to match google position resolution */
    const int LONG_DATUM = (180U * 100000U * 10U);



    char csvBuffer[1000];//csv file text buffer
    unsigned char binBuffer[1000];//binary file (output) buffer




    Pack _packedBinary = gcnew Pack();//class that knows how to pack values



    //Prepare an output buffer
    _packedBinary->initialise( binBuffer );


    //Insert various values
    _packedBinary->insert( value, 8 );//id
    _packedBinary->insert( *vertices, 16 );//vertices

    //If necessary add the datum and round down to 5dp
    value = _packedBinary->round( value + LONGITUDE_DATUM, 6, 5 );
    _packedBinary->insert( value, 25 );


    //When finished all lat/long insertions then pad to a byte boundary
    _packedBinary->pad();

