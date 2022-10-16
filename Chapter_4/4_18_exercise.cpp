#include "./std_lib_facilities.h"

int main()
{
   /* Write a program to solve quadratic equations. A quadratic
    * equation is of the from:
    *                   ax²+bx+c=0
    * If you don't know the quadratic formula for solving such
    * expression, do some research.
    * Use doubles for the user inputs for a, b and c. Since 
    * there are two solutions to a quadratic equation, output
    * both x1 and x2.
    * Comments:
    * I have seen this equation before in school, but I did not 
    * remember how to solve it, so I had to research online
    *
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



