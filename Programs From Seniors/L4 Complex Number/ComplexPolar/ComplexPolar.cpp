#include <cmath>
#include <iostream>
#include <sstream>
#include "ComplexPolar.h"
using namespace std;

const double PI = 3.14159;

Complex::Complex( double magnitude, double phase )
{
    _mag = magnitude;
    _phase = phase;
}

double Complex::getReal( )
{
    return _mag * cos( _phase );
}

double Complex::getImaginary( )
{
    return _mag * sin( _phase );
}

double Complex::getMagnitude( )
{
    return _mag;
}

double Complex::getPhase( )
{
    return _phase;
}

void Complex::add( Complex& otherC)
{
    double real, imag;

    real = getReal() + otherC.getReal();
    imag = getImaginary() + otherC.getImaginary();

    _mag =  sqrt( real*real + imag*imag );
    if (real != 0 ){   
        _phase = atan( imag / real );
    } else if ( imag > 0 ){
        _phase = PI / 2;
    } else {
      _phase = -PI / 2;
    }
}

void Complex::minus( Complex& otherC)
{
    double real, imag;

    real = getReal() - otherC.getReal();
    imag = getImaginary() - otherC.getImaginary();

 _mag =  sqrt( real*real + imag*imag );
    if (real != 0 ){   
        _phase = atan( imag / real );
    } else if ( imag > 0 ){
        _phase = PI / 2;
    } else {
        _phase = -PI / 2;
    }
}

void Complex::multiply( Complex& otherC)
{
    _mag *= otherC.getMagnitude();
    _phase += otherC.getPhase();
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

