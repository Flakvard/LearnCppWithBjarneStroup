
#include "../std_lib_facilities.h"

int main()
{
   /* Exercise 7 was to copy exercise 4.18 from chapter 4
    * and to add error prevention, so when equation has no
    * real roots, b²-4ac is less than 0 
    */

   double a = 0;
   double b = 0;
   double c = 0; 

  cout<<"Using quadratic equation, ax²+bx+c=0, to solve expression\n"
      <<"Plese insert values a, b and c.\n";
  cin>>a>>b>>c;
  
  cout<<"\nx = (-b +/- sqrt(b²-4ac) ) / 2a\n"
      <<"\nx = ("<<-b<<" +/- sqrt("
      <<b<<"²-4*"<<a<<"*"<<c<<") ) / 2*"<<a<<'\n';
  cout<<"\nx = ("<<-b<<" +/- sqrt("
      <<b*b<<"-("<<-4*a*c<<")) ) / "<<2*a<<'\n';
  cout<<"\nx = ("<<-b<<" +/- sqrt("
      <<b*b-4*a*c<<")) ) / "<<2*a<<'\n';
  if((b*b-4*a*c)<0) cout<<"Equation has no real roots. b²-4ac is less than 0\n";
  if((b*b-4*a*c)>0){
  cout<<"\nx = ("<<-b<<" +/- "
      <<sqrt(b*b-4*a*c)<<") / "<<2*a<<'\n';
  cout<<"\nx = ("<<-b<<" + "
      <<sqrt(b*b-4*a*c)<<") / "<<2*a<<'\t';
  cout<<"x = ("<<-b<<" - "
      <<sqrt(b*b-4*a*c)<<") / "<<2*a<<'\n';
  cout<<"\nx = ("<<-b+(sqrt(b*b-4*a*c))<<") / "<<2*a<<'\t';
  cout<<"x = ("<<-b-(sqrt(b*b-4*a*c))<<") / "<<2*a<<'\n';
  cout<<"\nx = ("<<(-b+(sqrt(b*b-4*a*c)))/(2*a)<<'\t';
  cout<<"x = "<<(-b-(sqrt(b*b-4*a*c)))/(2*a)<<'\n';
  }
}



