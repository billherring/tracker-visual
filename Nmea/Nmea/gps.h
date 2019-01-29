using namespace System;
using namespace System::Collections;

namespace GPS_TRACK_DIRECTION
{
        enum
        {
            UP,
            DOWN,
            PAUSE,
        };
}

    public ref class GpsTrack
    {
        public:

            array<unsigned char> ^ insert( int select )
            {
                char cStr[20];
                int secs;
                int hours;
                int mins;
                
                switch (select)
                {
                    case 0:
                        sprintf_s( cStr, sizeof(cStr), "%06u", date );
                        break;
                    case 1:
                        ++time;
                        secs = time;
                        hours = secs / 3600;
                        sprintf_s( cStr, sizeof(cStr), "%02u", hours );
                        secs -= (hours * 3600);
                        mins = secs / 60;
                        sprintf_s( cStr + 2, sizeof(cStr) - 2, "%02u", mins );
                        secs -= (mins * 60);
                        sprintf_s( cStr + 4, sizeof(cStr) - 4, "%02u", secs );
                        break;
                    case 2:
                        if (direction == GPS_TRACK_DIRECTION::UP)
                        {
                            altitude += altitudeStep;
                        }
                        else if ((direction == GPS_TRACK_DIRECTION::DOWN) && (altitude >= altitudeStep))
                        {
                            altitude -= altitudeStep;
                        }
                        sprintf_s( cStr, sizeof(cStr), "%u", altitude );
                        break;
                    default:
                        cStr[0] = '\0';
                        break;
                }

                int length = strlen( cStr );
                array<unsigned char>^ buffer = gcnew array<unsigned char>( length );
                for (int i = 0; i < length; ++i)
                {
                    buffer[i] = cStr[i];
                }

                return(buffer);
            }

            String ^getAltitude( void )
            {
                return(Convert::ToString( altitude ));
            }    

            String ^getTime( void )
            {
                return(Convert::ToString( time ));
            }    

            String ^getDate( void )
            {
                return(Convert::ToString( date ));
            }    


            void setDirection( int d )
            {
                direction = d;
            }
            void setAltitude( String ^a )
            {
                altitude = Convert::ToInt32( a );
            }    
            void setTime( String ^t )
            {
                int secs = Convert::ToInt32( t->Substring( 4, 2 ) );
                int mins = Convert::ToInt32( t->Substring( 2, 2 ) );
                int hours = Convert::ToInt32( t->Substring( 0, 2 ) );
                time = secs + (mins * 60) + (hours * 3600);
            }    
            void setDate( String ^d )
            {
                date = Convert::ToInt32( d );
            }    
            void setAltitudeStep( String ^s )
            {
                altitudeStep = Convert::ToInt32( s );
            }

        private:
            int altitude;
            int time;
            int date;
            int direction;
            int altitudeStep;
    };




