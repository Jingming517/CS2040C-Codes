#include <iostream>
#include <algorithm> 
#include <vector>
using namespace std;

int main() {
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
   vector<int>::iterator result; 
   int new_val = 7; 
   result = lower_bound( nums.begin(), nums.end(), new_val ); 
   nums.insert( result, new_val ); 
   
   for( unsigned int i = 0; i < nums.size(); i++ ) { 
	     cout << nums[i] << " "; 
   } 
   return 0; 
}

