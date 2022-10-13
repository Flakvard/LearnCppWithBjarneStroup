
#include "./std_lib_facilities.h"

int main()
{
  /* Write a program that performs a very simple calculator
   * Your calculator should handle four basic math operations
   * add, subtract, multiply and divide - on two inputs.
   * two double values and a character to represent an operation
   * fx. 35.6 24.1 + with output "the sum of 35.6 and 24.1 is 59.7"
   */ 

  double val1 = 0;
  double val2 = 0;
  char operation = '0';
  cout<<"Simple calculator: Write 'val1' and 'val2' and 'operation'\n"
      <<"Please choose a operator between: '+', '-', '/' and '*'\n";
  while(cin>>val1>>val2>>operation)
  {
  
    switch(operation){
      case '+':
        cout<<"The sum of "<<val1<<" and "
            <<val2<<" is "<<val1+val2<<'\n';
      break;
      case '-':
        cout<<"The deduction of "<<val1<<" and "
            <<val2<<" is "<<val1-val2<<'\n';
      break;
      case '/':
        cout<<"The divide of "<<val1<<" and "
            <<val2<<" is "<<val1/val2<<'\n';
      break;
      case '*':
        cout<<"The multiply of "<<val1<<" and "
          <<val2<<" is "<<val1*val2<<'\n';
      break;
      default:
      cout<<operation<<" is an invalid operator.\n"
          <<"Please us''+', '-', '/' and '*''\n'";
      break;
    }
  }
}
