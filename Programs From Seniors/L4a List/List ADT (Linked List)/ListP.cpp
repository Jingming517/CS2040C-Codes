#include "ListP.h"

template <typename T>
List<T>::List()
{   _size = 0;
    _head = NULL;
}

template <typename T>
List<T>::~List()
{
    while (!isEmpty())
        remove(1);
}

template <typename T>
bool List<T>::isEmpty() const
{    return _size == 0;      }

template <typename T>
int List<T>::getLength() const
{    return _size;           }

template <typename T>
typename List<T>::ListNode* List<T>::find(int index) const
{
    if ( (index < 1) || (index > getLength()) )
        return NULL;
    else  // count from the beginning of the list.
    {
        ListNode*cur = _head;
        for (int skip = 1; skip < index; ++skip)
            cur = cur->next;
        return cur;
    }  // end if

}

template <typename T>
void List<T>::retrieve(int userIdx, T& dataItem) const
    throw (SimpleException)
{
   if ( (userIdx < 1) || (userIdx > getLength()) )
      throw SimpleException("Bad Index in retrieve()");
   else  {  // get pointer to node, then data in node

      ListNode *cur = find(userIdx);
      dataItem = cur->item;

   }
}

template <typename T>
void List<T>::insert(int userIdx, const T& newItem)
   throw (SimpleException)
{
    int newLength = getLength() + 1;

    if ( (userIdx < 1) || (userIdx > newLength) )
        throw SimpleException("Bad Index in insert()");
    else {  

        ListNode *newPtr = new ListNode;
        _size = newLength;
        newPtr->item = newItem;
// attach new node to list
        if (userIdx == 1) {  

            newPtr->next = _head;
            _head = newPtr;
        } else {

            ListNode *prev = find(userIdx-1);

            newPtr->next = prev->next;
            prev->next = newPtr;
        }

    } //end if
}

template <typename T>
void List<T>::remove(int userIdx)
    throw (SimpleException)
{

    ListNode *cur;

    if ( (userIdx < 1) || (userIdx > getLength()) )
        throw SimpleException("Bad index in remove()");
    else {
        --_size;
if (userIdx == 1) {
  
            cur = _head;  // save pointer to node
            _head = _head->next;
        } else {
            ListNode *prev = find(userIdx - 1);

            cur = prev->next;  // save pointer to node
            prev->next = cur->next;
        }  // end if
        cur->next = NULL;
        delete cur;
        cur = NULL;
    }  // end if
}


