#include <vector>
#include <iostream>
using namespace std;

void print_vector( vector<int>& iV )
{
    vector<int>::iterator iter;

    cout << "V = [ ";
    for (iter = iV.begin(); iter != iV.end(); ++iter)
            cout << *iter << " ";
    cout << "]" << endl;
}

int main()
{
    vector<int> intV;
    for (int ix = 0; ix != 5; ++ix) 
          intV.push_back(ix);
    print_vector(intV);

    vector<int>::iterator myIter = intV.begin();

    intV.insert(myIter, 123);   
    print_vector(intV);
	
	myIter = intV.begin();  //Important: reset myIter
    myIter++;
    intV.erase(myIter);
    print_vector(intV);

    myIter = intV.begin();   //Reset!
    cout << *myIter << endl;

}

