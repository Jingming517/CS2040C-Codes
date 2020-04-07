#include <iostream>
#include "StackP.cpp"

using namespace std;

int main (){
	
	Stack<int> intStack;
 
    int rItem;
    try {
        intStack.push(333);
        intStack.push(111);
        intStack.push(777);
        intStack.push(555);
        cout << "Size of stack is " << intStack.size() << endl;
        intStack.getTop(rItem);
        cout << "First item is "  << rItem << endl;
     
		intStack.pop(rItem);
		intStack.pop(rItem);
        cout << "First item is "  << rItem << endl;
        intStack.getTop(rItem);
        cout << "First item is " << rItem << endl;
    } catch (SimpleException sExcpt) {
        cout << sExcpt.getMessage() << endl;
    } 
}
