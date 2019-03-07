using namespace System;
using namespace System::Collections;
//using namespace std;

class Edge
{
    public:
    
        Edge( void )
        {
        }
    

        ~Edge( void )
        {
        }
        
        



	    bool operator <( Edge & edgeObj )
        /* If current edge is leftmost then return true condition
            
            Calculate longitude of intersection with edge baseline for each
            edge (use signed arithmetic):-
            lon west + ((lon east - lon west)(lat east - lat base)) / (lat east - lat west)
        */
   	    {
            signed int baseLongitude;
            signed int baseLongitudeObj;
            signed int baseDelta;
          
            baseDelta = ( ((longitudeEast - longitudeWest) * (latitudeEast - baseLatitude))
                           / (latitudeEast - latitudeWest) );
                            
            if ((latitudeEast - latitudeWest) < 0)
            {
                baseLongitude = longitudeEast - baseDelta;
            }
            else
            {
                baseLongitude = longitudeWest + baseDelta;
            }


            baseDelta = ( ((edgeObj.longitudeEast - edgeObj.longitudeWest) * (edgeObj.latitudeEast - edgeObj.baseLatitude))
                           / (edgeObj.latitudeEast - edgeObj.latitudeWest) );
                            
            if ((edgeObj.latitudeEast - edgeObj.latitudeWest) < 0)
            {
                baseLongitudeObj = edgeObj.longitudeEast - baseDelta;
            }
            else
            {
                baseLongitudeObj = edgeObj.longitudeWest + baseDelta;
            }


            return (baseLongitude < baseLongitudeObj);
//            return (longitudeEast < edgeObj.longitudeEast);
	    }

        int vEast;
        int vWest;
        signed int latitudeEast;
        signed int longitudeEast;
        signed int latitudeWest;
        signed int longitudeWest;

        signed int baseLatitude;
};



class Vertex
{

    public:
    
        Vertex( void )
        {
        }
    

        ~Vertex( void )
        {
        }
        
        



	    bool operator <( Vertex & vertexObj )
	    {
            if (orderByLatitude)
            {
		        return (latitude < vertexObj.latitude);
            }
            else
            {
		        return (longitude < vertexObj.longitude);
            }
	    }

        int latitude;
        int longitude;
        int index;
        int orderedIndex;
        int westIndex;
        int eastIndex;
        std::list<Edge> edges;
        
        static bool orderByLatitude;
        
};



class Fence
{

    public:
    
        Fence( void )
        {
        }
    

        ~Fence( void )
        {
        }
        
        

        int id;
        int behaviour;
        int transmitMode;
        int altitudeFloor;
        int altitudeCeiling;
        int startDate;
        int stopDate;
        int minSpeed;
        int slowTransmit;
        int normalTransmit;
        
        int vertexCount;
        std::list<Vertex> vertices;
        
        static bool orderByLatitude;
        
};



class BoxBoundary
{

    public:
    
        BoxBoundary( void )
        {
        }
    

        ~BoxBoundary( void )
        {
        }
        

        bool operator <( BoxBoundary & boxBoundary )
	    {
            return (position < boxBoundary.position);
	    }

        int position;
        int index;
        std::list<int> activeIndexes;
        
};



