#include "ListA.h"

template <typename T>
List<T>::List()
{
    _size = 0;
}

template <typename T>
bool List<T>::isEmpty() const
{
    return _size == 0;
}

template <typename T>
int List<T>::getLength() const
{
    return _size;
}

template <typename T>
void List<T>::retrieve(int userIdx, T& dataItem) const
   throw (SimpleException)
{
    int index = userIdx - 1;    

   
    if ((index >= 0) && (index < _size) )
        dataItem = _items[index];
    
    else
        throw SimpleException("Bad Index!");
}

template <typename T>
void List<T>::insert( int userIdx, const T& newItem )
   throw (SimpleException)
{
    int index = userIdx - 1;    
    if (_size >= MAX_LIST)
        throw SimpleException("List is full in insert()!");

    if ( (index>=0) && (index < _size + 1) ) {

        for (int pos = _size-1; pos >= index; --pos)
            _items[pos+1] = _items[pos];

        _items[index] = newItem;

        ++_size;

    } else
        throw SimpleException("Bad Index in insert()!");
}

template <typename T>
void List<T>::remove( int userIdx )
    throw (SimpleException)
{
    int index = userIdx - 1;    

    if ((index >= 0) && (index < _size)){

        for (int pos = index; pos < _size-1; ++pos)
            _items[pos] = _items[pos+1];

        --_size;

    } else
        throw SimpleException("Bad Index in remove()!");
}



