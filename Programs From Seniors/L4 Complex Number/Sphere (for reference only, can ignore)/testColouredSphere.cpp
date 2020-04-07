#include "ColouredSphere.h"
#include <iostream>
using namespace std;
int main() {

   ColouredSphere ball(RED);

   ball.setRadius(5.0);
   cout << "The ball's diameter is ";
   cout << ball.getDiameter() << endl;

   ball.setColour(YELLOW);
   cout << "The ball's colour is "; 
   cout << ball.getColour() << endl;

   return 0;
}

