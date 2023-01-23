#include "../std_lib_facilities.h"


/* A permutation is an ordered subset of a set. For example, say you wanted
to pick a combination to a vault. There are 60 possible numbers, and
you need three different numbers for the combination. There are P(60,3)
permutations for the combination, where P is defined by the formula
P (a , b ) =
a!
/
( a − b )!
where ! is used as a suffix factorial operator. For example, 4! is 4*3*2*1.
Combinations are similar to permutations, except that the order of the
objects doesn’t matter. For example, if you were making a “banana split”
sundae and wished to use three different flavors of ice cream out of five
that you had, you wouldn’t care if you used a scoop of vanilla at the
beginning or the end; you would still have used vanilla. The formula for
combinations is
C (a , b ) =
P (a , b )
/
b!
Design a program that asks users for two numbers, asks them whether
they want to calculate permutations or combinations, and prints out the
result. This will have several parts. Do an analysis of the above require-
ments. Write exactly what the program will have to do. Then, go into
the design phase. Write pseudo code for the program, and break it into
sub-components. This program should have error checking. Make sure
that all erroneous inputs will generate good error messages.
*/ 
double userinput = 0;
double password = 0;
double factorialCalc(double userinput);
double permutation(double combinations, double password);
double combinations(double permutation, double val);

int main()
{
cout<<"Do you want to calculate Permutation or Combination?\n1 = Permutation\n2 = Combination\n";
cin>>userinput>>password;
if(userinput != 1||2) error("Please write 1 or 2");

if(userinput == 1) error("Please write 1 or 2");
if(userinput == 2) 
{
  while(true)
}
cout<<permutation(userinput, password);

}

double permutation(double combinations, double password)
{
//P (a , b ) = a!/( a − b )!
double a = factorialCalc(combinations);
double b = factorialCalc(combinations-password);
double permutation = a/b;
return permutation;
}

double combinations(double a, double val)
{
//C (a , b ) = P (a , b )/b!
  double p = permutation(a,val);
  double b = factorialCalc(val);
  return p/b;
}
double factorialCalc(double userinput){
  double factorial = 0;
  double factorialVal = 0;
  factorial = userinput;
  factorialVal = userinput;
  for(int i = 1; i<userinput; i++)
    { // input 4! is 4*3*2*1
      factorial -= 1;
      factorialVal *= factorial;
    }
  return factorialVal;
}
