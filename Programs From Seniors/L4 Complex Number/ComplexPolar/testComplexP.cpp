#include <iostream>
#include "ComplexPolar.h"
using namespace std;
	
int main () {
    Complex c1(31.62, 0.322), c2(28.28, 0.785);

    cout << "Complex number c1:\n";
    cout << c1.toRectangularString() << endl;
    cout << c1.toPolarFormString() << endl;

    //...c2 can be printed in similar fashion

    cout << "add c2 to c1" << endl;
    c1.add( c2 );

    //print out c1 to check the addition
    cout << "Complex number c1:\n";
    cout << c1.toRectangularString() << endl;
    return 0;
}

