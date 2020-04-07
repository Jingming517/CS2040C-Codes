#include <stack>
#include <iostream>
using namespace std;

bool check_bracket( string input )
{
     stack<char> sc;
     char current;
     bool ok = true;
     
     for (unsigned int pos = 0; 
                         ok && pos < input.size(); pos++){
        current = input[pos];
        switch (current){
            case '{':
                sc.push('}'); //Question: Why are we pushing the 
                break;        //                  closing bracket here??
            case '[':
                sc.push(']');
		   break;
            case '(':
                sc.push(')');
                break;
			case '}':
            case ']':
            case ')':
                if (sc.empty())     //missing open bracket
                   ok = false;
                else {
                     if (sc.top() == current)//matched!
                        sc.pop();
                     else                    //mismatched!
                         ok = false;
                }
                break;        
        }
    }
    
    if (sc.empty() && ok){       //make sure no leftover
       return true;
    } else 
       return false;
}

int main()
{
   	string input;
	cout << "Input string: " ;
	cin >> input;
	
	if (check_bracket(input)) {
		cout << "Brackets matched." << endl;
	}
	else {
		cout << "Brackets do not match." << endl;
	}
}


