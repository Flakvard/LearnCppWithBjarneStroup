#include "./std_lib_facilities.h"

int square(int x)
{
  int square = 0;
  for(int i = 0; i<x;++i)
  {
    square += x;
  }

  return square;
}

int main()
{
  /* Implement square() by starting with a 
   * * variable restult of 0 and adding x to 
   * * it x times */

  cout<<"3 "<<square(3)<<" = 3*3"<<'\n'; //Print 9
   
}
