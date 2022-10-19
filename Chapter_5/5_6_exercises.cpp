#include "../std_lib_facilities.h"

double ftoc(double f);
double ctof(double c);
double ktoc(double k);
double ctok(double c);

int main()
{
  /* 1. Go through every drill and "Try this" exercies in chapter 5
   * 2. Debug and fix this program. 
   * 3. Now add a error if celsius is less than 273.15 e.g. kelvin less than 0.
   * 4. Do this again, but place the error handler inside the function
   * 5. Add a function that can convert Kelvin to Celsius
   * 6. Add a function that can convert Celsius to Fahrenheit and back again.
   * 7. I will continue this in a new file... 5_7_exercises.cpp
   * Comments: overall I think this was okey exercies. What I found most helpful
   * was the "Try this" exercies. Especally the Error precondition and postcondition.
   * "Error: Precondition input less than -273.15" and
   * "Error: Postcondition output less than 0" which checks the functions input
   * and output. Kelvin can never be less than 0 or -273.15 celsius. 
   * So we add c<-273.15, but if c is an int an the input was a very high number
   * it could bypass the c<-273.15, so therefor we must add as a postcondition k<0.
   */
  double c = 0;         //declare input variable
  cin>>c;               //retrieve temperature to input variable
  double k = ctof(c);   //convert temperature
  cout<<k<<'\n';        //print out temperature
}

double ctok(double c)   // converts Celsius to Kelvin
{
 //Precondition: input can never be below 273.15
 //Postcondition: output can never be less than 0
  if(c<-273.15) error("Error: Precondition input less than 273.15");
  double k = c + 273.15;
  if(k<0) error("Error: Postcondition output less than 0");
  return k;
}
double ktoc(double k)   // converts Kelvin to Celsius
{
 //Precondition: input can never be below 0
 //Postcondition: output can never be less than -273.15
  if(k<0) error("Error: Precondition input less than 0");
  double c = k - 273.15;
  if(c<-273.15) error("Error: Postcondition output less than -273.15");
  return c;
}
double ctof(double c)   // converts Celsius to Fahrenheit 
{
 //Precondition: input can never be below 273.15
 //Postcondition: output can never be less than 0
  if(c<-273.15) error("Error: Precondition input less than -273.15");
  double f = 9.0/5.0*c+32;
  if(f<-459.67) error("Error: Postcondition output less than -459.67");
  return f;
}
double ftoc(double f)   // converts Fahrenheit to Celsius  
{
 //Precondition: input can never be below 273.15
 //Postcondition: output can never be less than 0
  if(f<-459.67) error("Error: Precondition input less than -459.67");
  double c = 5.0/9.0*(f-32);
  if(c<-273.15) error("Error: Postcondition output less than -273.15");
  return c;
}
