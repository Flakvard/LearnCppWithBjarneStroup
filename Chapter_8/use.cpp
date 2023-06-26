
#include "./my.h"
#include <iostream>

int main(int argc, char* argv[]){


    X::var = 7;
    Y::print_foo();
    X::print(X::var);

    using namespace Y;
    var = 9;
    print(var); // print Y’s var
    {  
        using Z::var;
        using Z::print;
        var = 11;
        print(var); // print Z’s var
    }
 

    // int x = 7;
    // int y =9;

    // const int cx = 7;
    // const int cy = 9;

    // double dx = 7.7;
    // double dy = 9.9;
// Swap const reference - everything run, but nothing got changed as expected
    // swap_cr(x,y);
    // swap_cr(7,9);
    // swap_cr(cx,cy);
    // swap_cr(7.7,9.9);
    // swap_cr(dx,dy);
    // swap_cr(7.7,9.9);

// Swap value - eveything worked as expected
    // swap_v(x,y);
    // swap_v(7,9);
    // swap_v(cx,cy);
    // swap_v(7.7,9.9);
    // swap_v(dx,dy);
    // swap_v(7.7,9.9);

// ONLY FUNCTIONS that did not compile
// Swap reference
    // swap_r(x,y); // only one that worked
    //swap_r(7,9); // There is no lvalue reference to the rvalue, because there is no variable to reference to
    //swap_r(cx,cy); // Cannot change the value, because it is a const variable
    //swap_r(7.7,9.9); // First wrong type then there is no lvalue reference to the rvalue, because there is no variable to reference to
    //swap_r(dx,dy); // this does not work because lvalue is of type int and variable passed into func is of type double
    //swap_r(7.7,9.9); // Same as 2 lines above
}