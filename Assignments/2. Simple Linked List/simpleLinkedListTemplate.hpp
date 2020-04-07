#include <iostream>
#include "simpleLinkedListTemplate.h"
using namespace std;


template <class T>
ListNode<T>::ListNode(T n)
{
	_item = n;
	_next = NULL;
}

template <class T>
void List<T>::insertHead(T n)
{
	ListNode<T> *aNewNode = new ListNode<T>(n);
	aNewNode->_next = _head;
	_head = aNewNode;
	_size++;
};

template <class T>
void List<T>::removeHead()
{
	if (_size > 0) {
		ListNode<T> *temp = _head;
		_head = _head->_next;
		delete temp;
		_size--;
	}
}

template <class T>
void List<T>::print(bool withNL) {

	ListNode<T> *temp = _head;
	while (temp) {
		cout << temp->_item;
		if (withNL)
			cout << endl;
		else
			cout << " ";
		temp = temp->_next;
	}
	cout << endl;
	  
}

//Task 1 - done
template <class T>
bool List<T>::exist(T n) {
	// modify this
    ListNode<T> *next = _head;
    while (next != NULL){
        if (next->_item == n){
            return true;
        }
        next=next->_next;
    }
	return false; 
}

template <class T>
T List<T>::headItem()
{
	if (_size)
		return *_head;
}

//Task 3
template <class T>
T List<T>::extractMax()
{
    T max;
    ListNode<T> *next = _head;
    ListNode<T> *deleteNode;
    max=next->_item;
    next=next->_next;
    while(next != NULL){
        if(next->_item > max){
            max=next->_item;
        }
        next = next->_next;
    }

    next=_head;
    ListNode<T> *last=NULL;
    while(1){
        if(next->_item==max){
            if(last==NULL){
                _head=next->_next;
                deleteNode=next;
                break;
            }
            else{
                last->_next=next->_next;
                deleteNode=next;
                break;
            }
        }
        last=next;
        next=next->_next;
    }
    
    _size--;
	return max;
}


//Task 5
template <class T>
void List<T>::reverseOp() {
    ListNode<T> *_headrev;
    _headrev=NULL;
    
    // Initialize current, previous and next pointers
    ListNode<T> *current = _head;
    ListNode<T> *prev = NULL, *next = NULL;
  
    while (current != NULL) {
        // Store next
        next = current->_next;
  
        // Reverse current node's pointer
        current->_next = prev;
  
        // Move pointers one position ahead.
        prev = current;
        current = next;
        }
    _head = prev;
    
}
 

template <class T>
List<T>::~List()
{
	while (_head)
		removeHead();
};


