#include "../std_lib_facilities.h"

void Error(string s);
int main()
{
    double d = 0;
    cin>>d;
    if(!cin) Error("couldn't read a double in 'some_function()'\n");
    return 0; // 0 indicates sucess
}


void Error(string s)
{
  throw runtime_error(s);
}
