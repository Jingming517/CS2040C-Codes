#include <iostream>
#include "ListA.cpp"

int main()
{
    List<int> intList;
    int rItem;
    try {
        intList.insert(1, 333);
        intList.insert(1, 111);
        intList.insert(3, 777);
        intList.insert(3, 555);

        intList.retrieve(1, rItem);
        cout << "First item is "  << rItem << endl;
        intList.retrieve( intList.getLength() , rItem);
        cout << "Last item is "  << rItem << endl;
     
		intList.remove(1);
        intList.remove(2);
        intList.remove( intList.getLength() );

        intList.retrieve(1, rItem);
        cout << "First item is "  << rItem << endl;
        intList.retrieve( intList.getLength() , rItem);
        cout << "Last item is "  << rItem << endl;

    } catch (SimpleException sExcpt) {
        cout << sExcpt.getMessage() << endl;
    } 

}

