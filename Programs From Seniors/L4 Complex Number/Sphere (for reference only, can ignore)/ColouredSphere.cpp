#include "ColouredSphere.h"

ColouredSphere::ColouredSphere (Colour initialColour)
	: Sphere(), c(initialColour)
{ } // end constructor

ColouredSphere::ColouredSphere (Colour initialColour,
                                 double initialRadius) 
	:Sphere(initialRadius),c(initialColour)
{ } // end constructor

void ColouredSphere::setColour (Colour newColour)
{
   c = newColour;
} // end setColour

Colour ColouredSphere::getColour ()
{
   return c;
} // end getColour

