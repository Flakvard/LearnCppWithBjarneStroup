
#include "./std_lib_facilities.h"

int main()
{
   /* Write a program that finds the min, max and mode
    * of a sequence of strings.
    * Comments:
    * This one was easier since I knew kinda how I would tackel
    * the tracking of most counted duplicates and since the 
    * higest and lowest values were easy because it is sorted
    * in alphabetical order and by each character. e.g zab 
    * comes before zba and zza.
    *
    */
  string choose_a_value = "";
  string min_value = "";
  string max_value = "";
  int smallest_value = 0;
  int highest_value = 0;
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
  } 
  for(int i = 0; i < Chosen_values.size(); ++i){
        cout<<Chosen_values[i]<<" ";
        if(i > 1 && Chosen_values[i]==Chosen_values[i-1]){
          if(Chosen_values[i] != doublecate_value){
          doublecate_value = Chosen_values[i];
          countDuplicate = 1;
          ++countDuplicate;
          }else
            ++countDuplicate;
          if(countDuplicate>trackCount){
            trackDuplicate = doublecate_value;
            trackCount = countDuplicate;
          }

        }
    }
    cout<<'\n'; 
    string trackHighestString = "";
    string trackLowestString = "";
    int word_count = 0;
    int track_word_count = 0;
    for(int i = 1; i < Chosen_values.size(); ++i)
    {
        cout<<Chosen_values[i]<<'\t'<<Chosen_values[i].size()<<'\n';
        word_count = Chosen_values[i].size();
        
        if(word_count > Chosen_values[i-1].size()){
           trackHighestString = Chosen_values[i];
           highest_value = word_count;
        }
        if(word_count < Chosen_values[i-1].size()){
          trackLowestString = Chosen_values[i];
          smallest_value = word_count;

        }
    }
    cout<<"The min value is: "<<min_value<<'\n';
    cout<<"The smallest value is: "<<trackLowestString<<'\n';
    cout<<trackLowestString<<" has "<<smallest_value<<" characters\n";
    cout<<"The max value is: "<<max_value<<'\n';
    cout<<"The highest value is: "<<trackHighestString<<'\n';
    cout<<trackHighestString<<" has "<<highest_value<<" characters\n";
    cout<<"The mode value is: "<<trackDuplicate<<'\n';
    cout<<"The mode is counted: "<<trackCount<<'\n';
}
