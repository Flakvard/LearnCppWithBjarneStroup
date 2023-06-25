
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

// Swap const reference
    int x = 7;
    int y =9;
    swap_cr(x,y);
    swap_cr(7,9);
    const int cx = 7;
    const int cy = 9;
    swap_cr(cx,cy);
    swap_cr(7.7,9.9);
    double dx = 7.7;
    double dy = 9.9;
    swap_cr(dx,dy);
    swap_cr(7.7,9.9);

// Swap value
    swap_v(x,y);
    swap_v(7,9);
    swap_v(cx,cy);
    swap_v(7.7,9.9);
    swap_v(dx,dy);
    swap_v(7.7,9.9);
// ONLY FUNCTIONS that did not compile
// Swap reference
    //swap_r(x,y);
    //swap_r(7,9); // There is no lvalue reference to the rvalue, because there is no variable to reference to
    //swap_r(cx,cy); // Cannot change the value, because it is a const variable
    //swap_r(7.7,9.9); // First wrong type then there is no lvalue reference to the rvalue, because there is no variable to reference to
    //swap_r(dx,dy); // this does not work because lvalue is of type int and variable passed into func is of type double
    //swap_r(7.7,9.9); // Same as 2 lines above
}