#include <iostream>
using namespace std;

int main()
{
	int ia[3] = {3, 5, 7};
	int* ptr;

	ptr = ia;
	//ia = ptr;
	ptr[2] = 9; // same as ia[2] = 9

	for (int i = 0; i < 3; i++) cout << ia[i] << " ";
	cout << endl;

	ptr = &ia[1]; // make ptr points to ia[1] as its starting point, ignoring ia[0]
	ptr[1] = 11; // ptr[1] = ia[2] = 11

	for (int i = 0; i < 3; i++) cout << ia[i] << " ";
	cout << endl;

	return 0;
}


