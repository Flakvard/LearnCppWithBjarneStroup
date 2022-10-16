#include "../std_lib_facilities.h"

char ask_user(string question);
int area(int lenght, int width);
void f(int x, int y, int z);
int framed_area(int x, int y);

int main()
{
  int x = 0;
  int y = 0;
  int z = 0;
  cout<<"Input ints = x, y and z\n";
  while(cin>>x>>y>>z)
  {
    cout<<"Input ints = x, y and z\n";
    f(x,y,z);
  }
  char return_msg = ' ';
  return_msg = ask_user("Do you want a sandwich");
  cout<<return_msg<<'\n';
}
//ask user for a yes-or-note answer;
//return 'b' to indicate a bad answer (i.e., not yes or no)

char ask_user(string question)
{
  cout<<question<<"?(yes or no)\n";
  string answer = " ";
  cin>>answer;
  if (answer == "y"||answer=="yes") return 'y';
  if (answer == "n"||answer=="no") return 'n';
  return 'b'; //'b' for "Bad answer"
}

void f(int x, int y, int z) // calculate 
{
  if(x <= 2) error("x less than 2 - non-positiv area");
  if(y <= 2) error("y less than 2 - non-positiv area");
  if(z <= 2) error("z less than 2 - non-positiv area");
  int area1 = area(x,y);
  int area2 = framed_area(x,z);
  int area3 = framed_area(y,z);
  double ratio = double(area1)/area3; //convert to double to get
                                      //floating-point division. 
  cout<<"area 1 = "<<area1<<'\n';
  cout<<"area 2 = "<<area2<<'\n';
  cout<<"area 3 = "<<area3<<'\n';
  cout<<"ratio  = "<<ratio<<'\n';
}
//calculate area of a rectagle;
//return -1 to indicate a bad argument
int area(int lenght, int width) // calculate area of a rectangle
{
  if(lenght<=0||width<=0) return -1;
  return lenght*width;
}

int framed_area(int x, int z) // calculate area widthin frame.
{
  if(x<=0||z<=0) return -1;
  return area(x-2,z-2);
}
