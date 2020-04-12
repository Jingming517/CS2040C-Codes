#pragma once
#include <math.h>

#include <iostream>
using namespace std;

#ifndef HEAPHPP
#define HEAPHPP
/*
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}*/

template <class T>
void Heap<T>::_bubbleUp(int index) {
    if (index < 1) return; // at root, do nothing
    int parent = int(floor((index-1)/2));
    if (_heap[index] > _heap[parent]) { // violate property with parent
        //swap(&_heap[index], &_heap[parent]); // swap upwards
        int temp = _heap[index];
        _heap[index] = _heap[parent];
        _heap[parent] = temp;
        _bubbleUp(parent); // recurse
    }
}

template <class T>
void Heap<T>::_bubbleDown(int index) {
    if (index >= _n-1) return; // beyond last element, do nothing
    int swap_id = index;
    int left = 2*index+1;
    int right = 2*index+2;
    if (left <= _n-1 && _heap[index] < _heap[left]) swap_id = left; // compare with left child, if exists
    if (right <= _n-1 && _heap[swap_id] < _heap[right]) swap_id = right; // compare with right child, if exists
    if (swap_id != index)
    { // need to swap with the larger of the two children
        //swap(&_heap[index], &_heap[swap_id]); // swap downwards with the larger of the two children
        T temp = _heap[index];
        _heap[index] = _heap[swap_id];
        _heap[swap_id] = temp;
        _bubbleDown(swap_id); // recurse
    }
    else return;
}

template <class T>
void Heap<T>::insert(T item) {
    if (_n+1 >= DEFAULTHEAPSIZE) return; //overflow
    // First insert the new key at the end
    _n++;
    int i = _n - 1;
    _heap[i] = item;
    // Fix the min heap property if it is violated
    while (i != 0 && _heap[i] > _heap[(i-1)/2])   //_heap[parent(i) < _heap[i]
    {
        //swap(&_heap[i], &_heap[(i-1)/2]);
        T temp = _heap[i];
        _heap[i] = _heap[(i-1)/2];
        _heap[(i-1)/2] = temp;
        i = (i-1)/2;
    }
}


template <class T>
T Heap<T>::extractMax() {
    T max = _heap[0];
    //swap(&_heap[0], &_heap[_n-1]); // swap with the last existing leaf
    T temp = _heap[0];
    _heap[0] = _heap[_n-1];
    _heap[_n-1] = temp;
    _n = _n - 1;
    _bubbleDown(0);
    return max;
}



template <class T>
void Heap<T>::printHeapArray() {
	for (int i = 0; i < _n; i++)
		cout << _heap[i] << " ";
	cout << endl;
}

template <class T>
int Heap<T>::_lookFor(T x){ // not a very good implementation, but just use this for now.
    int i;
    for(i=0;i<_n;i++)
        if (_heap[i] == x)
            return i;
    return -1;
}

template <class T>
void Heap<T>::decreaseKey(T from, T to)
{
    int index = _lookFor(from);
    _heap[index] = to;
    _bubbleDown(index);
}


template <class T>
void Heap<T>::increaseKey(T from, T to)
{
    int index = _lookFor(from);
    _heap[index] = to;
    _bubbleUp(index);
}

template <class T>
void Heap<T>::deleteItem(T x)
{
    int index = _lookFor(x);
    _heap[index] = _heap[_n-1];
    _n--;
    _bubbleUp(index);
    _bubbleDown(index);
}

template <class T>
void Heap<T>::printTree() {
    int parity = 0;
    if (_n == 0)
        return;
    int space = pow(2,1 + (int) log2f(_n)),i;
    int nLevel = (int) log2f(_n)+1;
    int index = 0,endIndex;
    int tempIndex;
    
    for (int l = 0; l < nLevel; l++)
    {
        index = 1;
        parity = 0;
        for (i = 0; i < l; i++)
            index *= 2;
        endIndex = index * 2 - 1;
        index--;
        tempIndex = index;
        while (index < _n && index < endIndex) {
            for (i = 0; i < space-1; i++)
                cout << " ";
            if(index==0)
                cout << "|";
            else if (parity)
                cout << "\\";
            else
                cout << "/";
            parity = !parity;
            for (i = 0; i < space; i++)
                cout << " ";
            index++;
        }
        cout << endl;
        index=tempIndex;
        while (index < _n && index < endIndex) {
            for (i = 0; i < (space-1-((int) log10(_heap[index]))); i++)
                cout << " ";
            cout << _heap[index];
            for (i = 0; i < space; i++)
                cout << " ";
            index++;
        }
        
        cout << endl;
        space /= 2;
    }

}


#endif
