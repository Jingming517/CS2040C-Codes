#include <iostream>
using namespace std;

class Complex
{
  private:
    double _mag, _phase;

  public:
   
    Complex( double, double );
   
    double getReal( );
    double getImaginary( );

    double getMagnitude( );
    double getPhase( );
    
    void add( Complex& );
    void minus( Complex& );
    void multiply( Complex& );

    string toRectangularString( );
    string toPolarFormString( );    
};

