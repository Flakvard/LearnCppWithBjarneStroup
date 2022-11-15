  /* Define a class Name_value that holds a string and a value.
   * Rework exercise 19 in Chapter 4 to use a vector<Name_value> instead of two vectors.
   *
   * Exercise 19 in chapter 4:
   * Writa a program where you enter a set of values
   * name-and-value pairs. Fx. Joe 17 and Barbara 22.
   * Add Joe in a vector called names and 17 in scores.
   * So names[7] == "Joe" and scores[7] == 17.
   * Terminate input with NoName 0. 
   * Check that each input is unique and terminate if
   * with an error msg if name entered twice.
   * Write out all names and scores pairs one per line.
   */
#include "../std_lib_facilities.h"

class Name_value
{
  public: 
    string names;
    int value;
};

int main()
{
  vector<Name_value>Names_values;
  string name = "";
  int val = 0;
  Name_value data;
  bool New_name_val = true;
  cout<<"Terminate input with NoName 0.\n";
  while(cin>>name>>val)
  {
    if(name == "NoName"||val == 0) break;
    if(Names_values.size()==0)
    {
      cout<<"No value in db\n";
      data.names = name;
      data.value = val;
      Names_values.push_back(data);
    }else{
      for(int i = 0; i<Names_values.size();++i)
      {
        cout<<Names_values[i].names<<" "<<Names_values[i].value<<'\n';
        if(Names_values[i].names == name && Names_values[i].value == val)
        {
          cout<<"Error msg: Name entered twice\n";
          New_name_val = false;
        } 
      }
      if(New_name_val)
      {
      data.names = name;
      data.value = val;
      Names_values.push_back(data);
      }
    }
    New_name_val = true;
  }
  for(int i = 0; i<Names_values.size(); ++i)
    {
      cout<<Names_values[i].names<<" "<<Names_values[i].value<<'\n';
    }

}
