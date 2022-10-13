#include "./std_lib_facilities.h"

int main()
{
  /* Drill these 11 steps. Start with a while loop that reads
   * inn 2 ints and prints them and exit with a '|' is entered
   * 2. Add a text that says which value is smaller and which is 
   * bigger.
   * 3. Then add equal if values are both the same number
   * 4. change int to double 
   * 5. Add a 'almost equal' if within 1.0/100
   * 6. Now remove val1 and val2 and keep track of which is smallest
   * and which is largest. Add the same text as before
   * 7. Add a unit to cin and accept cm, m, in, ft. Add conversion
   *    Read into a string 
   * 8. Reject units like yard, meter, km, gallons ect
   * 9. Keep track of smalles and largest and sum of everything
   * 10. Keep all the values entered (converted into meters)
   *     and into a vector. At the end print all values out
   * 11. Before writing out the values from vector, sort them.
   */
  double largestval = 0;
  double smallestval = 10000;
  double choose_a_value = 0;
  bool flag = true;
  double almost_equal = 0;
  string unit = "";
  
  while(cin>>choose_a_value){
    
    cout<<choose_a_value<<unit<<'\n';
    if(choose_a_value>largestval)
        largestval = choose_a_value;
    if(choose_a_value<smallestval)
        smallestval = choose_a_value;

    almost_equal = largestval-smallestval;
    if(largestval < smallestval){
      cout<<"The larger value is "<<smallestval<<'\n';
      cout<<"The smaller value is "<<largestval<<'\n';
      if(almost_equal < 1&&almost_equal>0||almost_equal >-1&&almost_equal<0)
          cout<<"The numbers are almost equal by only "
              <<almost_equal<<'\n';

    }else if(smallestval < largestval){
      cout<<"The larger value is "<<largestval<<'\n'; 
      cout<<"The smaller value is "<<smallestval<<'\n';
      if(almost_equal < 1&&almost_equal>0||almost_equal >-1&&almost_equal<0)
          cout<<"The numbers are almost equal by only "
              <<almost_equal<<'\n';

    }else if(largestval == smallestval){
      cout<<"The values are equal"<<'\n';

    }else{

    }
  }
  return 0; 
}
