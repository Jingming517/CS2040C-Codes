// File: testSphere.cpp
#include <iostream>
#include "Sphere.h"

int main()
{
   Sphere unitSphere;    	   // radius is 1.0
   Sphere mySphere(5.0);      // radius is 5.0

   unitSphere.displayStatistics();

   mySphere.setRadius(4.2);   // resets radius to 4.2
   cout << mySphere.getDiameter() << endl;

   return 0;
} // end main

