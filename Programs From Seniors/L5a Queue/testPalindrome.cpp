#include <queue>
#include <stack>
#include <iostream>
#include <string>
using namespace std;

bool palindrome(string input) {
   stack <char> s ;
   queue <char> q ;
  
   for (int j=0; j < input.size(); j++) { 
		s.push (input[j]); 
		q.push (input[j]);    
   }
	 while (!s.empty()) {       
		if ( s.top() != q.front() ) 
		    return false;
		s.pop();
		q.pop();
	 }
    return true;
}

int main(){
	
	string input;
	cout << "Input String:" << endl;
	//getline (cin,input) ;
	cin >> input ;
	
	if (palindrome(input)){
		cout << input << " is a Palindrome" ; 
	}
	else 
	{
		cout << input << " is not Palindrome";
	}
}
