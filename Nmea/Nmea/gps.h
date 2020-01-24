using namespace System;
using namespace System::Collections;


    public ref class GpsTrack
    {
        public:
            GpsTrack( void )
            {
                course = gcnew String("");
                originLatitude = 0;
                originLongitude = 0;
                targetLatitude = 0;
                targetLongitude = 0;
                deltaLatitude = 0;
                deltaLongitude = 0;
                trackLength = 0;
                deltaTrackLength = 0;

                courseIndex = 0;
            }


            ~GpsTrack( void )
            {
            }

            void start( String ^courseStr, String ^speedStr )
            {
                course = courseStr;
                courseIndex = 0;
                setNextTrack();
            }

            /*
             * Function Name: nextPosition
             * Description: 'Turns the handle' of course generation
             * Parameters:
             * Return:
             * Notes:
             */
            void nextPosition( String ^speed )
            {
                if (deltaTrackLength == trackLength)
                {
                    setNextTrack();
                }
                else
                {
                    // Steps/sec (i.e. lat/long units)
                    // 1 knot = 185/360 metres/sec
                    // 1 metre = 10/11 steps
                    int speedStep = ((Convert::ToInt32( speed ) * 185) + 198) / 396;
                    deltaTrackLength += speedStep;
                    if (deltaTrackLength > trackLength)
                    {
                        deltaTrackLength = trackLength;
                    }
                }

                if (trackLength != 0)
                {
                    deltaLatitude = ((deltaTrackLength * (targetLatitude - originLatitude)) + (trackLength / 2)) / trackLength;
                    deltaLongitude = ((deltaTrackLength * (targetLongitude - originLongitude)) + (trackLength / 2)) / trackLength;
                }

            }


            int latitude()
            {
                return ((int)(originLatitude + deltaLatitude));
            }


            int longitude()
            {
                return ((int)(originLongitude + deltaLongitude));
            }


        private:
            long long int originLatitude;
            long long int originLongitude;
            long long int targetLatitude;
            long long int targetLongitude;
            long long int deltaLatitude;
            long long int deltaLongitude;
            long long int trackLength;
            long long int deltaTrackLength;

            String ^course;
            int courseIndex;


            void setNextTrack( void )
            {
                if (courseIndex < course->Length)
                {

                    int point;

                    if (courseIndex == 0)
                    {
                        originLatitude = 0;
                        originLongitude = 0;

                        setTrackPoint( ',', &point );
                        targetLatitude = originLatitude = point;
                        setTrackPoint( 0x0d, &point );
                        targetLongitude = originLongitude = point;
                        setTrackPoint( 0x0a, &point );
                    }
                    else
                    {
                        originLatitude = targetLatitude;
                        originLongitude = targetLongitude;
                    }

                    setTrackPoint( ',', &point );
                    targetLatitude = point;
                    setTrackPoint( 0x0d, &point );
                    targetLongitude = point;
                    setTrackPoint( 0x0a, &point );

                    trackLength = getTrackLength( targetLatitude - originLatitude, targetLongitude - originLongitude );

                    deltaLatitude = 0;
                    deltaLongitude = 0;

                    deltaTrackLength = 0;
                }
            }


            void setTrackPoint( char delimiter, int *point )
            {
                int length;
                int position = course->IndexOf( delimiter, courseIndex );

                if (position > 0)
                {
                    length = position - courseIndex;

                    if (length > 0)
                    {
                        String ^s;
                        s = course->Substring( courseIndex, length );
                        *point = Convert::ToInt32( s );
                    }
                    courseIndex += (length + 1);
                }
                else
                {
                    //Bring to an end by going to end of string
                    courseIndex = course->Length;
                }

            }



            /*
             * Function Name: getTrackLength
             * Description: Calcs track length
             * Parameters:
             * Return:
             * Notes: Basic trigonometry . . its the root of the sum of the 
             *          squares of the sides
             */
            
            int getTrackLength( long long int a, long long int b )
            {
                long long square = (a * a) + (b * b);

                long long result = square / 4;

                long long estimate;

                if (result != 0)
                {
                    do
                    {
                        estimate = result;
                        result = ((square / estimate) + estimate) / 2;
                        
                    } while ((result != estimate) && (result != 0));
                }

                return ((int)result);
            }
    };




