#include <cmath>
#include <iostream>
#include <sstream>
#include "ComplexRectangular.h"
using namespace std;

const double PI = 3.14159;

Complex::Complex( double real, double imag )
{
     _real = real;     
     _imag = imag;  
}

double Complex::getReal( )
{    return _real;   }

double Complex::getImaginary( )
{    return _imag;   }

double Complex::getMagnitude( )
{    return sqrt( _real*_real + _imag*_imag );  }

double Complex::getPhase( )
{   double radian;

    if (_real != 0 )
        radian = atan( _imag / _real );
    else if ( _imag > 0 )
        radian = PI / 2;
    else 
        radian = -PI / 2;
    return radian;
}

void Complex::add( Complex& otherC )
{
   _real = _real + otherC.getReal();
   _imag = _imag + otherC.getImaginary();

}

void Complex::minus( Complex& otherC )
{
   _real = _real - otherC.getReal();
   _imag = _imag - otherC.getImaginary();
}

void Complex::multiply (Complex& otherC )
{
   double realNew, imagNew;

   realNew = _real * otherC.getReal() - _imag * otherC.getImaginary();
   imagNew  = _real * otherC.getImaginary() + _imag * otherC.getReal();

   _real = realNew;
   _imag = imagNew;

}

string Complex::toRectangularString()
{
    ostringstream os;

    os << "(" << getReal() << ", " << getImaginary() << "i)";
    return os.str();
}

string Complex::toPolarFormString()
{
    double angle;
    ostringstream os;

    angle = getPhase();
    os << getMagnitude() << "( cos "  << angle;
    os <<  "+ i sin " << angle << ")";
    return os.str();
}

