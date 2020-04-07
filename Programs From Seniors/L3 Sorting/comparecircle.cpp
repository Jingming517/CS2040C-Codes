#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Circle {
public:
	Circle(int i): r(i) {}
	int getr() { return r;}
private:
	int r;
};
bool smaller ( Circle x,  Circle y) { return x.getr() < y.getr(); }
bool bigger ( Circle x,  Circle y) { return x.getr() > y.getr(); }

int main(){
	Circle c1(1), c2(2), c3(3);
	vector<Circle> v;
	v.push_back(c2);
	v.push_back(c1);
	v.push_back(c3);
	vector<Circle>::iterator i = v.begin();
	vector<Circle>::iterator e = v.end();
	sort (i, e, smaller);  // use bigger for descending
	cout << " In ascending order:" << endl;
	for (; i != e; ++i)  cout << i ->getr() << endl;
	return 0;
}

