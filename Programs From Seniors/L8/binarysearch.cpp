#include <algorithm> 
#include <iostream>
using namespace std;

int main() {
   int nums[] = { -242, -1, 0, 5, 8, 9, 11 }; 
   int start = 0; 
   int end = 7; 
   for( int i = 0; i < 10; i++ ) { 
	   if( binary_search( nums+start, nums+end, i ) ) { 
		cout << "nums[] contains " << i << endl; 
	   } else { 
		cout << "nums[] DOES NOT contain " << i  << endl; 
        } 
   } 
   return 0; 
}

