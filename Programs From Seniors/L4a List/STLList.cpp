#include <iostream>
#include <list>
using namespace std;

int main()
{
	list<double> dl;  
   dl.insert( dl.begin(), 3.14 );
   dl.insert( dl.begin(), 1.23 );
    
   list<double>::iterator li = dl.begin();
    
   cout << *li << endl;
   li++;
   cout << *li << endl;
    
   return 0;
}

