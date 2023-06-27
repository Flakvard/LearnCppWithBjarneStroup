
/*
2. Write a function print() that prints a vector of ints to cout. Give it two 
arguments: a string for “labeling” the output and a vector.

3. Create a vector of Fibonacci numbers and print them using the function 
from exercise 2. To create the vector, write a function, fibonacci(x,y,v,n), 
where integers x and y are ints, v is an empty vector<int>, and n is the 
number of elements to put into v; v[0] will be x and v[1] will be y. 

A Fibonacci number is one that is part of a sequence where each element is the 
sum of the two previous ones. For example, starting with 1 and 2, we get 
1, 2, 3, 5, 8, 13, 21, . . . . Your fibonacci() function should make such a 
sequence starting with its x and y arguments
*/
#include "../../std_lib_facilities.h"

void print(vector<int>& vec, string& str);
void fibonacci(int x, int y, vector<int> v, size_t n);


int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    vector<int> v;
    string label = "Hello number ";

    // print(vec,label);
    fibonacci(10,20,v,50);

}

void print(vector<int>& vec, string& str){
    for(size_t i = 0; i < vec.size(); i++){
        cout<<str<<vec[i]<<'\n';
    }
}
void fibonacci(int x, int y, vector<int> v, size_t n){
    int fib = 0;
    v.push_back(x);
    v.push_back(y);

    if(n == 1 || n == 2){
        fib = x+y;
        v.push_back(fib);
    }
    else{
        for(size_t i = 1; i < n; i++){
            fib = v[i-1] + v[i];
            v.push_back(fib);
        }
    }
    string label = "Hello fibo number: ";
    for(size_t i = 0; i < v.size(); i++){
        cout<<label<<i<<" "<<v[i]<<'\n';
    }
}