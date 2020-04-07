#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
	vector<int> v; 
	v.push_back( 23 ); 
	v.push_back( -1 ); 
	v.push_back( 9999 ); 
	v.push_back( 0 ); 
	v.push_back( 4 ); 

	sort( v.begin(), v.end() ); 	// using operator< for int
    // sort (v.begin(), v.end(), greater<int>());
	cout << "After sorting: "<< endl; 
	for( unsigned int i = 0; i < v.size(); i++ ) { 
		cout << v[i] << endl ; 
	} 
}
