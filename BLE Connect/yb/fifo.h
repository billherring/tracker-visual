using namespace System;

public ref class Fifo
{
    public:
    
        Fifo( int size )
        {
            /* Set the actual _size to the nearest multiple of 2 */
            ++size;
            while (size != 0)
            {
                _sizeMask = size;
                size = size & (size - 1);
            }
            _sizeMask <<= 1;
            
            _buffer = gcnew array<unsigned int>( _sizeMask );
            
            /* Now set a size bit mask so we don't need to watch for wrap around */
            --_sizeMask;
     
     
            _head = 0;
            _tail = 0;
        }
    

        ~Fifo( void )
        {
        }
        

        void Enqueue( unsigned int byte )
        {
            _buffer[_head & _sizeMask] = byte;
            ++_head;
        }
        

        unsigned int Dequeue( void )
        {
            unsigned int byte = _buffer[_tail & _sizeMask];
            
            ++_tail;

            return(byte);
        }
        

        int Count( void )
        {
            return(_head - _tail);
        }
        
        
        void Clear( void )
        {
            _head = 0;
            _tail = 0;
        }    
    


    private:
        array<unsigned int>^ _buffer;
        int _head;
        int _tail;
        int _sizeMask;
        
};
