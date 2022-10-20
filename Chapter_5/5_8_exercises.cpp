#include "../std_lib_facilities.h"


int main()
{
  /* Write a program that reads and stores a series of integers
   * then compute the sum of the first N integers.
   * First ask for N, then read the values into a vector
   * then calculate the sum of the first N values.
   * Fx. "Please enter the number of values you want to sum: "
   * "Please input some integers (press | to stop): "
   * "The sum of the first 3 numbers (12 23 13) is 48"
   */

  vector<double>integers;
  double chosen_sum_number = 0;
  double integer = 0;
  double sum = 0;

   cout<<"Please enter the number of values you want to sum: \n";
   cin>>chosen_sum_number;
   cout<<"Please input some integers (press | to stop): \n";
   while(cin>>integer)
     integers.push_back(integer);
   if(chosen_sum_number>integers.size())
        error("Error: sum of the first numbers exceeds vector size\n");
   cout<<"The sum of the first "<<chosen_sum_number<<" numbers is (";
   for(int i = 0; i<chosen_sum_number;++i){
     sum += integers[i];
     cout<<integers[i]<<", ";
   }
   cout<<") "<<sum<<'\n';
}
