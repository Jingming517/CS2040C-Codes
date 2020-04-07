#include "StackP.h"

template<typename T>
Stack<T>::Stack()
: _size(0), _head(NULL) { }

template<typename T>
Stack<T>::~Stack()
{   
    while (!isEmpty())
        pop();
}

template<typename T>
bool Stack<T>::isEmpty() const
{
    return _size == 0;
}

template<typename T>
int Stack<T>::size() const
{
    return _size;
}

template<typename T>
void Stack<T>::pop()
    throw (SimpleException)
{
	ListNode* cur;

    if ( isEmpty() )
        throw SimpleException("Stack is empty on pop()");
    else { 
        cur = _head;
        _head = _head->next;

        delete cur;
        cur = NULL;
        _size--;
    }
}

template<typename T>
void Stack<T>::pop(T& stackTop)
    throw (SimpleException)
{
    ListNode* cur;

    if ( isEmpty() )
        throw SimpleException("Stack is empty on pop()");
    else { 
        stackTop = _head->item;

        cur = _head;
        _head = _head->next;

        delete cur;
        cur = NULL;
        _size--;
    }
}

template<typename T>
void Stack<T>::push(const T& newItem)
    throw (SimpleException)
{
    ListNode* newPtr = new ListNode;
    
    newPtr->item = newItem;
    newPtr->next = _head;
    _head = newPtr;
    
    _size++;

}

template<typename T>
void Stack<T>::getTop(T& stackTop) const
    throw (SimpleException)
{
    if ( isEmpty() )
        throw SimpleException("Stack is empty on getTop()");
    else
        stackTop = _head->item;
}


