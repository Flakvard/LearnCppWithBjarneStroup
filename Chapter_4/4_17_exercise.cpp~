
#include "./std_lib_facilities.h"

int main()
{
   /* Write a program that finds the min, max and mode
    * of a sequence of strings.
    * Comments:
    *
    */
  string choose_a_value = "";
  string min_value = "";
  string max_value = "";
  int LargestValue = 0;
  string mode = "";
  string doublecate_value = "";
  int countDuplicate = 0;
  string mode_value = "";
  int trackCount = 0;
  string trackDuplicate = "";
  vector<string>Chosen_values;

  cout<<"Please input a string\n";
  while(cin>>choose_a_value){
    Chosen_values.push_back(choose_a_value);
    sort(Chosen_values);
    LargestValue = Chosen_values.size()-1; 
    min_value = Chosen_values[0];
    max_value = Chosen_values[LargestValue];

    for(int i = 0; i < Chosen_values.size(); ++i){
        cout<<Chosen_values[i]<<'\n';
        if(i > 1 && Chosen_values[i]==Chosen_values[i-1]){
          if(Chosen_values[i] != doublecate_value){
          doublecate_value = Chosen_values[i];
          countDuplicate = 0;
          ++countDuplicate;
          }else
            ++countDuplicate;
          if(countDuplicate>trackCount){
            trackDuplicate = doublecate_value;
            trackCount = countDuplicate;
          }

        }
    }
    
    cout<<"The min value is: "<<min_value<<'\n';
    cout<<"The max value is: "<<max_value<<'\n';
    cout<<"The mode value is: "<<trackDuplicate<<'\n';
    cout<<"The mode is counted: "<<trackCount<<'\n';

  } 
}
