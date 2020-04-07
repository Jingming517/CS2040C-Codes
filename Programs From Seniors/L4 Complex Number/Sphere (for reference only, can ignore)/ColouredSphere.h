#include "Sphere.h"

enum Colour {RED, BLUE, GREEN, YELLOW};

class ColouredSphere : public Sphere
{
public:
   ColouredSphere(Colour);
   ColouredSphere(Colour, double);
   void setColour(Colour);
   Colour getColour();

private:
   Colour c;

}; //end ColouredSphere class

