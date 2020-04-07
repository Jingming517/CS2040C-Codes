#include <iostream>
#include "QueueA.cpp"
using namespace std;

int main (){
	Queue<int> intQueue;
 
    int rItem;
    try {
        intQueue.enqueue(333);
        intQueue.enqueue(111);
        intQueue.enqueue(777);
        intQueue.enqueue(555);
        cout << "Size of Queue is " << intQueue.size() << endl;
        intQueue.getFront(rItem);
        cout << "First item is "  << rItem << endl;
     
		intQueue.dequeue(rItem);
		intQueue.dequeue(rItem);
        cout << "First item is "  << rItem << endl;
        intQueue.getFront(rItem);
        cout << "First item is " << rItem << endl;
    } catch (SimpleException sExcpt) {
        cout << sExcpt.getMessage() << endl;
    } 
}
