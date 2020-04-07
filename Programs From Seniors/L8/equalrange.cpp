#include <algorithm> 
#include <iostream>
#include <vector>
using namespace std;
int main() {
   // data declared in the previous example
   vector<int> nums; 
   nums.push_back( -242 ); 
   nums.push_back( -1 ); 
   nums.push_back( 0 ); 
   nums.push_back( 5 ); 
   nums.push_back( 8 ); 
   nums.push_back( 8 ); 
   nums.push_back( 11 ); 
   cout << "Before nums is: "; 
   for( unsigned int i = 0; i < nums.size(); i++ ) { 
	     cout << nums[i] << " "; 
   } 
   cout << endl; 
   pair<vector<int>::iterator, vector<int>::iterator> result; 
   int new_val = 8; 
   result = equal_range( nums.begin(), nums.end(), new_val ); 
   cout << "The first place that " 
	<< new_val 
	<< " could be inserted is before " 
	<< *result.first 
	<< ", and the last place that it could be inserted is before " 
	<< *result.second << endl; 
   return 0; 
}

