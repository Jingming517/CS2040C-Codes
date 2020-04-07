#include <iostream>
using namespace std;

void swap_ByAdr(int* a, int* b) {   
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

int main() {   
	int i = 123, j = 456;

	swap_ByAdr(&i, &j);

	cout << i << endl;
	cout << j << endl;
}

