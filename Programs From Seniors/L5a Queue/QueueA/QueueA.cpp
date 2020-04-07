#include "QueueA.h"

template<typename T>
Queue<T>::Queue( )
{
	_front = 0;
	_back = MAX_QUEUE - 1;
	_count = 0;
}

template<typename T>
void Queue<T>::enqueue( const T& newItem )
    throw (SimpleException)
{  
   if ( _count == MAX_QUEUE )      
		throw SimpleException("queue full");
   else   {  		
      _back = ( _back + 1 ) % MAX_QUEUE;
      _items[_back] = newItem;
      ++_count;
   }
}

template <typename T>
void Queue<T>::dequeue() 
    throw (SimpleException)
{
   if ( isEmpty() )      
		throw SimpleException("Empty queue");
   else   {  		
	   _front = ( _front+1 ) % MAX_QUEUE;
       --_count;
   }
}

template <typename T>
void Queue<T>::dequeue( T& queueFront ) 
    throw (SimpleException)
{
   if ( isEmpty() )      
		throw SimpleException("Empty queue");
   else   {  		
	   queueFront = _items[ _front ];
      _front = ( _front+1 ) % MAX_QUEUE;
      --_count;
   }
}

template <typename T>
void Queue<T>::getFront( T& queueTop ) const
    throw (SimpleException)
{
   if ( isEmpty() )      
		throw SimpleException("Empty queue");
   else   {  		
	   queueTop = _items[ _front ];
   }
}

template <typename T>
int Queue<T>::size() const
{
   return _count;
}

template <typename T>
bool Queue<T>::isEmpty() const
{
   return _count == 0;
}
