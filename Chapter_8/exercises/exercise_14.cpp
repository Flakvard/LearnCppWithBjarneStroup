/*
14. Can we declare a non-reference function argument const (e.g., void 
    f(const int);)? What might that mean? Why might we want to do that? 
    Why don’t people do that often? Try it; write a couple of small programs 
    to see what works.

    ANSWER:
    What might that mean?
    Using const gives us a read-only parameter for our variable

    Why might we want to do that? 
    Immutable data, so we cannot assign it a new value.

    Why don’t people do that often?
    Maybe they want their data to be mutable/changed
    or
    They forget to do add const on the function, because they 'only' want to print it.
    Also, sometimes a print() func does something else before it prints. Fx. sort the vector first. 

*/

#include "../../std_lib_facilities.h"
void f1(const int foo);
void f2(const int foo);
void f3(const int foo);
void f4(const int foo);

int main(int argc, char* argv[]){
    int foo = 20;
    f1(foo);
    f2(foo);
    f3(foo);
    f4(foo);
}
void f1(const int foo){
    cout<<"foo = "<<foo<<'\n';
}
void f2(const int foo){
    int newFoo = foo;
    cout<<"newFoo = "<<newFoo<<'\n';
}
void f3(const int foo){
    int newFoo = 10;
    // foo = newFoo; // - does not work
}
void f4(const int foo){
    int newFoo = 10;
    f1(newFoo);
}