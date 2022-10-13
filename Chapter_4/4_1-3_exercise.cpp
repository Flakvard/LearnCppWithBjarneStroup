#include "./std_lib_facilities.h"

int main()
{
  double median = 0;
  double lowest_val = 0;
  double highest_val = 0;
  vector<double>temps;            //temperatures
  for(double temp; cin >> temp;)  //read into temp
    temps.push_back(temp);        //put temp into vector
  
  cout<<"This is temp.size() = "<<temps.size()<<'\n';

  //compute mean temperature
  double sum = 0;
  for(double x : temps)
      sum +=x;
  cout<<"Average temperature: "<<sum/temps.size()<<'\n';

  //compute median temperature
  sort(temps);
  lowest_val = temps[0];
  highest_val = temps[temps.size()-1];
  median = ((highest_val - lowest_val)/2)+lowest_val;
  cout<<"Median temperature: "<<temps[temps.size()/2]<<'\n';
  cout<<"Temps highest "<<highest_val<<'\n';
  cout<<"Temps lowest "<<lowest_val<<'\n';
  cout<<"Median.v2 temperature: "<<median<<'\n'; 
  cout<<"Total temperature: "<<sum<<'\n';
  for(double j : temps)
      cout<<j<<'\n';
}
