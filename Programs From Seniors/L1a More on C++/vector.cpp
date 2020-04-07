#include <vector>
#include <iostream>
using namespace std;

int main()
{

    vector<int> intV;   
    
    cout << "intV size = " << intV.size() << endl;
    for (int ix = 0; ix != 5; ++ix)
          intV.push_back(ix);
    cout << "intV size = " << intV.size() << endl;
    
    if (!intV.empty()) {
        cout << "intV = [ ";
	 for (int ix = 0; ix != intV.size(); ++ix)
            cout << intV[ix] << " ";
        cout << "]" << endl;
    }
    
    intV.pop_back();
    cout << "intV size = " << intV.size() << endl;
}
