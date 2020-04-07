#include <iostream>
using namespace std;

class BankAcct {

private:
  int _acctNum;
  double _balance;

public:
  BankAcct( int aNum )
  {  _acctNum = aNum;
     _balance = 0;
  }

  BankAcct( int aNum, double amt )
  : _acctNum( aNum), _balance( amt )
  {

  }

  int getacctNum(){
  	return _acctNum;
  }
  
  int getbalance(){
  	return _balance;
  }
  
  int withdraw( double amount )
  {   if (_balance < amount)
         return 0; 
      _balance -= amount;
      return 1;            
  }

  void deposit( double amount )  
  { 
      _balance += amount;
  }
 
  void printAcct (){
 	cout << "Account No: " << getacctNum() << " Balance: " << getbalance() << endl;
  }
 
  static void transfer(BankAcct& fromAcct, BankAcct& toAcct, double amt)
  {
      fromAcct.withdraw(amt);
      toAcct.deposit(amt);
  }

};

int main( )
{
    BankAcct ba1 (1233);

    ba1.deposit(1000);
    ba1.withdraw(500.25);

    //ba1._acctNum = 1357;
    //ba1._balance = 10000000;
    //Simple testing on object passing
    BankAcct ba2(1234,1000.00), ba3(1235, 2000.00);
    BankAcct::transfer(ba3, ba2, 500.00);

    ba1.printAcct();
	ba2.printAcct();
	ba3.printAcct();
}

