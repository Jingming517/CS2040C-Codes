#include <stack>
#include <iostream>
using namespace std;

int main()
{
  stack<int> s;

	s.push(5);
	int &j = s.top(); 	

	s.push(3);

	j++;		
	cout << "top: " << s.top() << endl;

	s.pop();
	cout << "After pop, top: " << s.top() << endl;

}

