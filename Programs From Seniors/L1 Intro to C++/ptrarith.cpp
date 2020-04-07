#include <iostream>
using namespace std;

int main (){
	int ia[5] = {1, 3, 5, 7, 9};
	int *p = ia;
	int *q, *r;

	q = p + 3;    // what is q?
	r = q - 1;    // what is r?

	cout << *p << endl;
	cout << *q << endl;
	cout << *r << endl;

	cout << *p + 1 << endl;
	cout << *(p + 1) << endl;

}
