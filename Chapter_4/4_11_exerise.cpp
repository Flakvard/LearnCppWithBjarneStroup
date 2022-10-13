#include "./std_lib_facilities.h"

int main()
{
  /* Find all prime numbers in 1 2 3 ... 100
   * Capture prime numbers into a vector
   * List prime numbers 3 5 7 11 13 17 19...97
   */

  vector<int> prime_numbers {};
  int prime_number = 0;
  int modular2 = 0;
  int modular3 = 0;
  int modular5 = 0;
  int modular7 = 0;
  int modular9 = 0;
  int modular10 = 0;
  int max = 0;
  int start = 0;

  cout<<"Please input a start and max value\n"
      <<"The output will be prime numbers.\n";
  cin>>start>>max;

  for(int i = start; i < max; i++){
    if(i<11){
      modular2 = i % 2;
      modular9 = i % 9;
      if(modular2 > 0 & modular9 > 0)
        prime_numbers.push_back(i);
    }
      if(i>11){
      modular2 = i % 2;
      modular3 = i % 3;
      modular5 = i % 5;
      modular7 = i % 7;

      if(modular2 > 0 && modular3 > 0 && modular5 > 0&& modular7 > 0)
        prime_numbers.push_back(i);
      }
  } 
  for (int i:prime_numbers)
    cout<<i<<'\n';

  for(int i = start; i < max; i++){


    if(i<=10){
      modular2 = i % 2;
      modular9 = i % 9;
      if(modular2 > 0&&modular9 > 0){
        cout<<'('<<i<<')'<<'\t';
      }else{
        cout<<i<<'\t';
      }
    }
    if(i>=11){
      modular2 = i % 2;
      modular3 = i % 3;
      modular5 = i % 5;
      modular7 = i % 7;

      if(modular2 > 0 && modular3 > 0 && modular5 > 0&& modular7 > 0){
        cout<<'('<<i<<')'<<'\t';
      }else{
        cout<<i<<'\t';
      }
  }
    modular10 = i % 10;
    if(modular10 == 0) cout<<'\n';
  }
  cout<<'\n';

}
