#include "./std_lib_facilities.h"

int main()
{
  /* Recreate the drill from chapter 4:
   * Find the mode for all positive integers inputs.
   * The drill from Chapter 4:
   */
  double largestval = 0;
  double smallestval = 10000;
  double choose_a_value = 0;
  bool flag = true;
  double almost_equal = 0;
  string unit = "";
  double cm_to_m = 100.0;
  double in_to_ft = 12.0;
  double cm_to_in = 2.54;
  double total_value_in_m = 0;
  double converted_value = 0;
  double mode = 0;
  double trackCount = 0;
  double trackDuplicate = 0;
  double trackLargestDuplicate = 0;
  double duplicates = 0;
  double countDuplicate = 0;
  vector<double>Chosen_values;
  cout<<"Please input a value and then cm, m, in or ft\n";
  while(cin>>choose_a_value>>unit){

    cout<<"Please input a value and then cm, m, in or ft\n";
    if (unit == "cm"){
    converted_value = choose_a_value/100;
    total_value_in_m += converted_value;  
    Chosen_values.push_back(converted_value);
    }else if(unit == "m"){
    converted_value = choose_a_value;  
    total_value_in_m += converted_value;
    Chosen_values.push_back(converted_value);
    }else if(unit == "in"){
    converted_value = (choose_a_value * cm_to_in)/100;
    total_value_in_m += converted_value;
    Chosen_values.push_back(converted_value);
    }else if(unit == "ft"){
    converted_value = ((choose_a_value*in_to_ft)*cm_to_in)/100;
    total_value_in_m += converted_value; 
    Chosen_values.push_back(converted_value);
    }else{
      cout<<unit<<" is not a valid unit\n"
        <<"Please choose between, cm, m, in or ft\n";
    }

    if(choose_a_value>largestval)
      largestval = choose_a_value;
    if(choose_a_value<smallestval)
      smallestval = choose_a_value;
    


    almost_equal = largestval-smallestval;
    if(largestval < smallestval){
      cout<<"The largest value is "<<smallestval<<'\n';
      cout<<"The smallest value is "<<largestval<<'\n';
      if(almost_equal < 1&&almost_equal>0||almost_equal >-1&&almost_equal<0)
          cout<<"The numbers are almost equal by only "
              <<almost_equal<<'\n';
    

    }else if(smallestval < largestval){
      cout<<"The largest value is "<<largestval<<'\n'; 
      cout<<"The smallest value is "<<smallestval<<'\n';
      if(almost_equal < 1&&almost_equal>0||almost_equal >-1&&almost_equal<0)
          cout<<"The numbers are almost equal by only "
              <<almost_equal<<'\n';
    }
  }
    sort(Chosen_values);
    //for(double k :Chosen_values)
      //cout<<k<<'\n';
    for(int k = 1; k < Chosen_values.size();++k){
      if(Chosen_values.size()>1){ //Start printing when size is 2 or more
       cout<<"Nr:"<<k<<" "<<Chosen_values[k]<<'\n'; //prints out the values 

        duplicates = Chosen_values[k]-Chosen_values[k-1];//if the previous
                                                         //values is the same
                                                         //as the next value
                                                         //then assign it to
                                                         //duplicates.
        if(duplicates == 0){
          if(Chosen_values[k] != trackDuplicate){ //not the same previousvalue
             trackDuplicate = Chosen_values[k]; //start tracking new value
             countDuplicate = 1; //rest value
             ++countDuplicate; //increment by one for first duplicate
          }else {
             ++countDuplicate; // increment if the same value as previous 
          }
          if (countDuplicate > trackCount){ //
           trackCount = countDuplicate;
           trackLargestDuplicate = trackDuplicate;
          }
         }
        }
      }
    cout<<"Total value: "<<total_value_in_m<<"m"<<"\n";
    cout<<"The mode is: "<<trackLargestDuplicate<<" m"<<'\n';
    cout<<"The mode was counted: "<<trackCount<<'\n';
  
}
