#include "StackV.h"

template<typename T>
Stack<T>::Stack()
{ }

template<typename T>
bool Stack<T>::isEmpty() const
{
    return _items.empty();
}

template<typename T>
int Stack<T>::size() const
{
    return _items.size();
}

template<typename T>
void Stack<T>::push( const T& newItem )
    throw (SimpleException)
{
    _items.push_back(newItem);
}

template<typename T>
void Stack<T>::getTop(T& stackTop) const
    throw (SimpleException)
{
    if ( _items.empty() )
        throw SimpleException("Stack is empty on getTop()");
    else
        stackTop = _items.back();
}

template<typename T>
void Stack<T>::pop()
    throw (SimpleException)
{
    if ( _items.empty() )
        throw SimpleException("Stack is empty on pop()");
    else {
        _items.pop_back();
    }
}

template<typename T>
void Stack<T>::pop(T& stackTop)
    throw (SimpleException)
{
    if ( _items.empty() )
        throw SimpleException("Stack is empty on pop()");
    else {
        stackTop = _items.back();
        _items.pop_back();
    }
}

