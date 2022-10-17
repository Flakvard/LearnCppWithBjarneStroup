#include "../std_lib_facilities.h"

int area(int length, int width);

int main()
{
    int value = 0;
    int lenght = 0;
    int width = 0;
    while(true){
        cin>>lenght>>width;
        value = area(lenght, width);
        cout<<value<<'\n';
    }
}


int area(int length, int width)
{
    if(length<=0||width<=0) error("area() pre-condition");
    int a = length*width;
    if(a <= 0) error("area() post-condition");
    return a;
}
