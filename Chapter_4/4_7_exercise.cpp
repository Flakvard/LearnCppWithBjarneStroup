#include "./std_lib_facilities.h"

int main()
{
  /* Make a vector holding ten strings values: "zero", "one",..."nine".
   * Write a program that converts digits to its spelled-out value.
   * E.g. input 7 gives the output "seven" and input "seven" outputs 7.
   */

  vector<string> spelled_val = {"zero","one","two","three","four","five","six","seven","eight","nine"};
 
  vector<string> values = {"0","1","2","3","4","5","6","7","8","9"};
  
  string value = "";
  int intvalue = 0;

  string val1 = "";
  string val2 = "";
  int valu1 = 0;
  int valu2 = 0;
  char operation = '0';
  cout<<"Simple calculator: Write 'val1' and 'val2' and 'operation'\n"
      <<"Please choose a operator between: '+', '-', '/' and '*'\n";
   
  while(cin>>val1>>val2>>operation){ 
    for(int i = 0; i<10; i++){
      if(val1 == spelled_val[i]){
          valu1 = i;
      }
    
      if(val1 == values[i]){
          valu1 = i;
      }
    } 
    for(int i = 0; i<10; i++){
      if(val2 == spelled_val[i]){
          valu2 = i;
      }
    
      if(val2 == values[i]){
          valu2 = i;
      }
    } 
  

    switch(operation){
      case '+':
        cout<<"The sum of "<<valu1<<" and "
            <<valu2<<" is "<<valu1+valu2<<'\n';
      break;
      case '-':
        cout<<"The deduction of "<<valu1<<" and "
            <<valu2<<" is "<<valu1-valu2<<'\n';
      break;
      case '/':
        cout<<"The divide of "<<val1<<" and "
            <<valu2<<" is "<<valu1/valu2<<'\n';
      break;
      case '*':
        cout<<"The multiply of "<<valu1<<" and "
          <<valu2<<" is "<<valu1*valu2<<'\n';
      break;
      default:
      cout<<operation<<" is an invalid operator.\n"
          <<"Please us''+', '-', '/' and '*''\n'";
      break;
    }
  
  }
}

