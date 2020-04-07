#include "Exception.h"

template <typename T>
class Stack {
   public:
    Stack();
     ~Stack();
     
     bool isEmpty() const;
     int size() const;
     
     void push(const T& newItem) throw (SimpleException);
          
     void pop() throw (SimpleException);     
     void pop(T& stackTop) throw (SimpleException);
     

     void getTop(T& stackTop) const 
			throw (SimpleException);


private:
    struct ListNode {
        T item;
        ListNode* next;
    };

    ListNode* _head;
    int _size;
};

