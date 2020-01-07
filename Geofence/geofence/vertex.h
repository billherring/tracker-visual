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
        /* If current edge is leftmost then return true condition */
   	    {
            return (longitude < edgeObj.longitude);

	    }




        int east;
        int west;
        int longitude;
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

        enum
        {
            ORDER_BY_LATITUDE = 0,
            ORDER_BY_LONGITUDE,
            ORDER_BY_INDEX
        };
        
        



	    bool operator <( Vertex & vertexObj )
	    {
            if (orderBy == ORDER_BY_LATITUDE)
            {
		        return (latitude < vertexObj.latitude);
            }
            else if (orderBy == ORDER_BY_LONGITUDE)
            {
		        return (longitude < vertexObj.longitude);
            }
            else
            {
		        return (index < vertexObj.index);
            }
	    }

        int latitude;
        int longitude;
        int index;
        int edgeListOffset;
        Edge edge1;
        Edge edge2;
        
        static int orderBy;
        
};



class VertexCrossRef
{
    public:
        VertexCrossRef( void )
        {
        }


        ~VertexCrossRef( void )
        {
        }


        bool operator <( VertexCrossRef & vertexCrossRef )
	    {
            return (index < vertexCrossRef.index);
	    }

        int index;
        int orderedIndex;
        

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

        std::list<VertexCrossRef> crossRef;
        
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
        int boxListOffset;
        
};


class FenceSummary
{
    public:
        FenceSummary( void )
        {
        }


        ~FenceSummary( void )
        {
        }


        bool operator <( FenceSummary & fenceSummary )
	    {
            return (id < fenceSummary.id);
	    }

        int index;
        int id;
        int offset;
};




