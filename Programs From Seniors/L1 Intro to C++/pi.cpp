#include <iostream>

using namespace std;



int i, N, den = 1, sign = 1;

double PI;



int main()

{
	
   cout << "Enter the number of terms to be used: ";
	
   cin >> N;
	
   for (i = PI = 0; i < N; i++, den += 2)
	
   {
		
      if (sign)
				
         PI += 4.0/den;
			
      else
				
         PI -= 4.0/den;
		
      sign = 1-sign;
	
    }
	
    cout << PI << endl;
	
    return 0;

}


