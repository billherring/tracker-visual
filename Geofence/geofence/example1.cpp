
#include "pack.h"

char csvBuffer[1000];//csv file text buffer
unsigned char binBuffer[1000];//binary file (output) buffer

Pack _packer = gcnew Pack();//class that knows how to pack values



int csvTextSize = 0;
int csvTextIndex = 0;
int totalFences = 0;

//Read input file into buffer


//At this point:-
//csvBuffer is a buffer holding all the text read from the csv file.
//csvTextSize has the size in characters
//csvTextIndex will maintain the position in the buffer as conversion progresses
//totalFences counts fences discovered in file as conversion progresses




    _packer->initialise( binBuffer );

    while (csvTextIndex < csvTextSize)
    {
        /* Get a single fence */
        //This takes two parse passes - one to count vertices (without
        //outputting binary) and a second to actually output binary.
        int vertices = 0;
        
        (void)parse( csvBuffer, csvTextSize, csvTextIndex, &vertices );//1st (gets vertices)
        csvTextIndex = parse( csvBuffer, csvTextSize, csvTextIndex, &vertices );//2nd (uses vertices)
        
        _packer->pad();
        ++totalFences;
    }
            





    //Parses strings from an 'csv' file and packs the string values into a binary object.
    //Also requires size of the csv and current byte position which will progress for each
    //fence call
    //The 'vertices' contents will be zero for a 1st pass call but non zero for a 2nd pass.
    //The csv file has 4 columns and accordingly the parsing maintains a state =
    //id/flags/lat/long which is simply a count modulo 4) 
    
    //Return the starting position of next fence csv (if any)
    int parse( char *csv, int csvSize, int csvPosn, int *verticesCount )
    {
    	char stringBuffer[MAX_ENTRY_SZ];/* to buffer strings parsed from input */
        int csvColumn = 0;
        int csvRows = 0;//counts rows found during parse
        bool endOfFence = false;//remembers when a fence is done

        int endPosn = 0;//Will return the current csv byte position at end of parse


	    while ((csvPosn < csvSize) && (endOfFence == false))
	    {
	        int charCount = 0;//counts chars in a string
	        int integers = 0;//counts numbers before any dp

	        //Get a string from the input delimited by either a ',' or 'x0d' and ignoring any '.' */
            char character = csv[csvPosn];
            while ((character != '\x0d') && (character != ','))
            {
                if (character != '.')
                {
                    stringBuffer[charCount] = character;
                    ++charCount;
                }
                else
                {
                    integers = charCount;
                }
                ++csvPosn;
                character = csv[csvPosn];
            }
            //String done
            
            
            stringBuffer[charCount] = '\0';//Complete the string

            //Skip past last delimiter
            ++csvPosn;

            //End of a line?
            if (character == '\x0d')
            {
                ++csvPosn;/* then skip past the 0xa to start of next line */
            }
        
            if (charCount != 0)
            {
                if (*verticesCount != 0)
                {
                    //This is 2nd parse pass, so insert the values depending upon column
                    unsigned int value = (unsigned int)atol( stringBuffer );
                    switch (csvColumn & 3)//modulo 4
                    {
                        case 0://ID
                            //Only the 1st fence row would have a value in this column
                            if (csvRows == 0)
                            {
                                //Must be 1st row so insert ID and inputted vertix count
                                _packer->insert( value, 8 );//id
                                _packer->insert( *verticesCount, 16 );
                            }
                            else
                            {
                                //Must be value for next fence - so end this fence (i.e. stop)
                                endOfFence = true;
                            }
                            break;
                        case 1://FLAGS
                            //Only the 1st fence row would have a value in this column
                            _packer->insert( value, 8 );
                            break;
                        case 2://LATITUDE
                            //Need to add datum and produce result rounded to 5dp
                            value = _packer->round( value, charCount - integers, 6 );
                            value = _packer->round( value + LAT_DATUM, 6, 5 );
                            _packer->insert( value, 25 );
                            break;
                        case 3://LONGITUDE
                            //Need to add datum and produce result rounded to 5dp
                            value = _packer->round( value, charCount - integers, 6 );
                            value = _packer->round( value + LONG_DATUM, 6, 5 );
                            _packer->insert( value, 26 );
                            ++csvRows;
                            
                            endPosn = csvPosn;//Remember potential end of a fence
                            break;
                    }
                }
                else
                {
                    //This is 1st parse pass, we are just counting rows until end of a fence
                    switch (csvColumn & 3)//modulo 4
                    {
                        case 0://ID
                            if (csvRows != 0)
                            {
                                //Must be 1st row so insert ID and inputted vertix count
                                endOfFence = true;
                            }
                            break;
                        case 1://FLAGS
                        case 2://LATITUDE
                            break;
                        case 3://LONGITUDE
                            //Count the row
                            ++csvRows;
                            break;
                    }
                    
                }
            }

            ++csvColumn;//cycle the column state
        }
        
        *verticesCount = csvRows;//vertix count must be no or rows encountered
        return(endPosn);
    }


