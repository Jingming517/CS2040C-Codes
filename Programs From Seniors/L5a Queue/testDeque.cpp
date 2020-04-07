#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

int main (){
	deque<int> dq1;
	dq1.push_front(1);
	dq1.push_front(2);
	dq1.push_back(3);
	dq1.push_back(4);
	cout << "First item is " << dq1.front() << endl;
	cout << "last item is " << dq1.back() << endl;
		
   // continued next slide
	deque<int> dq2(dq1.begin()+1, dq1.end()-1);
	dq1[1] = 5;
	dq1.erase(dq1.begin());
	dq1.insert(dq1.end() -1, 2, 6);

	sort(dq1.begin(), dq1.end());
	deque<int> dq3;
	dq3.resize(dq1.size()+dq2.size());
	merge(dq1.begin(), dq1.end(), dq2.begin(), dq2.end(), dq3.begin());
	cout << "First item is " << dq3.front() << endl;
	cout << "Last item is " << dq3.back() << endl;
	
	return 0;

}

