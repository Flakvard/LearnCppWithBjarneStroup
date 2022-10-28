#include "../std_lib_facilities.h"


int main()
{
  /* Read (day-of-the-week, value) pairs from standard input. For example:
   * Tuesday 23 Friday 56 Tuesday -3 Thursday 99
   * Collect all the values for each day of the week in a vector<int>. Write
   * out the values of the seven day-of-the-week vectors. Print out the sum
   * of the values in each vector. Ignore illegal days of the week, such as
   * Funday, but accept common synonyms such as Mon and monday. Write out the
   * number of rejected values.
   * Comments:
   * This was a simple program to write, but it feels like it could be written better 
   * it seems to be many if statements and there is something in the vector we could use. 
   */
  vector <string> day_of_the_week {
    "Monday", 
    "Tuesday", 
    "Wednesday", 
    "Thursday", 
    "Friday", 
    "Saturday", 
    "Sunday",
    "Rejected values"
  };
  vector<int>values_of_the_day
  {
      0,
      0,
      0,
      0,
      0,
      0,
      0,
      0
  };
  string day = "";
  int amount = 0;

  std::cout<<"Please input day of the week and amount"<<std::endl;
  while(std::cin>>day>>amount)
  {
  std::cout<<std::endl;
  std::cout<<std::endl;
    if(day == "Monday"||day == "monday" || day == "mon"||day == "Mon"||day == "mo"||day == "Mo")
    {
      values_of_the_day[0] += amount;
    }else if(day == "Tuesday"||day == "tuesday" || day == "tue"||day == "Tue"||day == "tu"||day == "Tu")
    {
      values_of_the_day[1] += amount;
    }else if(day == "Wednesday"||day == "wednesday" || day == "wed"||day == "Wed"||day == "we"||day == "We")
    {
      values_of_the_day[2] += amount;
    }else if(day == "Thursday"||day == "thursday" || day == "Thu"||day == "thu"||day == "Th"||day == "th")
    {
      values_of_the_day[3] += amount;
    }else if(day == "Friday"||day == "friday" || day == "fri"||day == "Fri"||day == "fr"||day == "Fr")
    {
      values_of_the_day[4] += amount;
    }else if(day == "Saturday"||day == "saturday" || day == "Sat"||day == "sat"||day == "sa"||day == "Sa")
    {
      values_of_the_day[5] += amount;
    }else if(day == "Sunday"||day == "sunday" || day == "sun"||day == "Sun"||day == "su"||day == "Su")
    {
      values_of_the_day[6] += amount;
    }else{
      values_of_the_day[7] += amount;
    }
  for(int i = 0; i<values_of_the_day.size(); ++i)
    std::cout<<day_of_the_week[i]<<'\t'<<values_of_the_day[i]<<std::endl;
  }
  std::cout<<std::endl;
}
