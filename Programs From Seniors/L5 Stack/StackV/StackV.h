#include "Exception.h"
#include <vector>
using namespace std;

template <typename T>
class Stack {
   public:
    Stack(); 
     
     bool isEmpty() const;
     int size() const;
     
     void push(const T& newItem) throw (SimpleException);
          
     void pop() throw (SimpleException);     
     void pop(T& stackTop) throw (SimpleException);
     

     void getTop(T& stackTop) const 
			throw (SimpleException);


private:
     vector<T> _items;
};

