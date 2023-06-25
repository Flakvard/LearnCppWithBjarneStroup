
#include "./my.h"
#include <iostream>

int main(int argc, char* argv[]){

    // foo = 7;

    print_foo();
    print(5);
    int a = 5;
    int b = 8;
    std::cout<<"a= "<<a<<" and b= "<<b<<'\n';
    swap_v(a, b);
    std::cout<<"a= "<<a<<" and b= "<<b<<'\n';

    int x = 7;
    int y =9;

    const int cx = 7;
    const int cy = 9;

    double dx = 7.7;
    double dy = 9.9;
// Swap const reference
/*
    std::cout<<swap_cr(x,y)<<'\n';
    std::cout<<swap_cr(7,9)<<'\n';
    std::cout<<swap_cr(cx,cy)<<'\n';
    std::cout<<swap_cr(7.7,9.9)<<'\n';
    std::cout<<swap_cr(dx,dy)<<'\n';
    std::cout<<swap_cr(7.7,9.9)<<'\n';

*/
// Swap value
    std::cout<<swap_v(x,y)<<'\n';
    std::cout<<swap_v(7,9)<<'\n';
    std::cout<<swap_v(cx,cy)<<'\n';
    std::cout<<swap_v(7.7,9.9)<<'\n';
    std::cout<<swap_v(dx,dy)<<'\n';
    std::cout<<swap_v(7.7,9.9)<<'\n';
// ONLY FUNCTIONS that did not compile
// Swap reference
    //swap_r(x,y);
    //swap_r(7,9); // There is no lvalue reference to the rvalue, because there is no variable to reference to
    //swap_r(cx,cy); // Cannot change the value, because it is a const variable
    //swap_r(7.7,9.9); // First wrong type then there is no lvalue reference to the rvalue, because there is no variable to reference to
    //swap_r(dx,dy); // this does not work because lvalue is of type int and variable passed into func is of type double
    //swap_r(7.7,9.9); // Same as 2 lines above
}