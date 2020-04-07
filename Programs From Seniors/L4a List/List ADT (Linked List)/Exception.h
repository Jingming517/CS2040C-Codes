#include <string>
using namespace std;

class SimpleException 
{
 private:
  string _errorMsg;

 public:
  SimpleException ( string message )   
  {   _errorMsg = message; }
   
  string getMessage () const 
  {  return _errorMsg; }
};

