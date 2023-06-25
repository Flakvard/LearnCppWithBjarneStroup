#include "./my.h"
#include "../std_lib_facilities.h"


void print(int n){
    for(int i = 0; i < n; i++){
        cout<<i<<'\n';
        }
    }
    
void print_foo(){
        cout<<"foo\n";
    }

int swap_v(int a, int b){ 
    std::cout<<"a = "<<a<<" and b = "<<b<<'\n';
    int temp; 
    temp = a;
    a=b; 
    b=temp; 
    std::cout<<"a = "<<a<<" and b = "<<b<<'\n';
    return a&&b;
    }
void swap_r(int& a, int& b){
    std::cout<<"a = "<<a<<" and b = "<<b<<'\n';
    int temp; 
    temp = a;
    a=b; 
    b=temp; 
    std::cout<<"a = "<<a<<" and b = "<<b<<'\n';
    }

void swap_cr(const int& a, const int& b){ 
    std::cout<<"a = "<<a<<" and b = "<<b<<'\n';
    int temp; 
    temp = a;
    //a=b; // Does not work to change a const variable
    //b=temp; // Does not work to change a const variable
    std::cout<<"a = "<<a<<" and b = "<<b<<'\n';
    }