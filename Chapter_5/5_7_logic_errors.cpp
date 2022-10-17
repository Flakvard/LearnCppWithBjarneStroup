#include "../std_lib_facilities.h"

/* test logic errors
 * get the program to work and try to break the program
 * change the program so it can take all temperaturs
 */

int main()
{
  vector<double> temps; //temperatures


  double sum = 0;
  double high_temp = -459.67; //initialize the lowest temperature
  double low_temp = 135;      //initialize the highest temperature
  int no_of_temps = 0;

  for(double temp; cin>>temp;)  //read and put into temps
  {
        temps.push_back(temp);
        ++no_of_temps;
        if(temp>high_temp)high_temp = temp; //find high
        if(temp<low_temp)low_temp = temp;   //find low
        sum += temp;                     //compute sum
  
  }
  
  cout<<"High temperature: "<<high_temp<<'\n';
  cout<<"Low temperature: "<<low_temp<<'\n';
  cout<<"Average temperature: "<<sum/temps.size()<<'\n';
}
