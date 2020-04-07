#include "Exception.h"

const int MAX_QUEUE = 50;

template<typename T>
class Queue {
   public:
     Queue(); 
	 bool isEmpty() const;
     int size() const;
     
     void enqueue(const T& newItem) throw (SimpleException);
          
     void dequeue() throw (SimpleException);     
     void dequeue(T& queueFront) throw (SimpleException);
     
     void getFront(T& queueTop) const throw (SimpleException);
private:

	T _items[MAX_QUEUE];

   int _front, _back, _count;

};

