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
}

