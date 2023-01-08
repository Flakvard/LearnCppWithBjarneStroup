#include "../std_lib_facilities.h"

int main()
{
  /* Write a program that reads digits and composes them into integers. For
     example, 123 is read as the characters 1, 2, and 3. The program should
     output 123 is 1 hundred and 2 tens and 3 ones. The number should be
     output as an int value. Handle numbers with one, two, three or four
     digits. Hint: To get the integer value 5 from the characters '5' subtract
     '0', that is, '5'-'0' == 5.
  */

 int hundred = 0;
 int tens = 0;
 int ones = 0;
 int five = '5'-'0';
 cout<<five<<'\n'; 
 int UserDigits = 0;
 while(cin>>UserDigits)
 {
   hundred = UserDigits / 100;
   tens = (UserDigits / 10) % 10;
   ones = (UserDigits % 10);
   cout<<hundred<<'\n'; 
   cout<<tens<<'\n'; 
   cout<<ones<<'\n'; 
 }
}
