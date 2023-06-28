
/*
2.  Write a function print() that prints a vector of ints to cout. Give it two 
    arguments: a string for “labeling” the output and a vector.

3.  Create a vector of Fibonacci numbers and print them using the function 
    from exercise 2. To create the vector, write a function, fibonacci(x,y,v,n), 
    where integers x and y are ints, v is an empty vector<int>, and n is the 
    number of elements to put into v; v[0] will be x and v[1] will be y. 

    A Fibonacci number is one that is part of a sequence where each element is the 
    sum of the two previous ones. For example, starting with 1 and 2, we get 
    1, 2, 3, 5, 8, 13, 21, . . . . Your fibonacci() function should make such a 
    sequence starting with its x and y arguments
4.  An int can hold integers only up to a maximum number. Find an approximation of that maximum number by using fibonacc
5.  Write two functions that reverse the order of elements in a vector<int>. 
    For example, 1, 3, 5, 7, 9 becomes 9, 7, 5, 3, 1. The first reverse function 
    should produce a new vector with the reversed sequence, leaving its original vector unchanged.
    The other reverse function should reverse the elements of its vector without using any other vectors (hint: swap).
6.  Write versions of the functions from exercise 5, but with a vector<string>.

*/
#include "../../std_lib_facilities.h"

void print(vector<int>& vec, string& str);
void fibonacci(int x, int y, vector<int> v, size_t n);
void reverseVec(vector<int> vec);
void swapVec(vector<int>& vec);
void swapStrVec(vector<string>& vec);
void printStr(vector<string>& vec, string& str);

int main(){
    vector<int> vec = {1,2,3,4,5,6,7,8,9,10};
    vector<string> vecStr = {"hello", "my", "name", "is", "unnamed"};
    vector<int> v;
    string label = "Hello normal vec ";

    // print(vec,label);
    // fibonacci(10,20,v,50);
    // reverseVec(vec);
    // swapVec(vec);
    printStr(vecStr, label);
    swapStrVec(vecStr);
}
void swapStrVec(vector<string>& vec){
    // Brute force way
    for(size_t i = 1; i < vec.size(); i++){
        for(size_t k = 1; k < vec.size(); k++){
            if (vec[k-1]<vec[i]){
                string temp; 
                temp = vec[k-1];
                vec[k-1] = vec[i]; 
                vec[i] = temp; 
            }
        }
    }
    // inbuilt sort way
    // sort(vec.begin(),vec.end(),greater());
    string label = "Hello reverse vec ";
    printStr(vec,label);
}


void swapVec(vector<int>& vec){
    // Brute force way
    for(size_t i = 1; i < vec.size(); i++){
        for(size_t k = 1; k < vec.size(); k++){
            if (vec[k-1]<vec[i]){
                int temp; 
                temp = vec[k-1];
                vec[k-1] = vec[i]; 
                vec[i] = temp; 
            }
        }
    }
    // inbuilt sort way
    // sort(vec.begin(),vec.end(),greater());
    string label = "Hello reverse vec ";
    print(vec,label);

}

void reverseVec(vector<int> vecCopy){
    vector<int> vec = vecCopy;
    string label = "Hello copy reverse vec ";
    sort(vec.begin(),vec.end(),greater());
    print(vec,label);
}

void print(vector<int>& vec, string& str){
    for(size_t i = 0; i < vec.size(); i++){
        cout<<str<<vec[i]<<'\n';
    }
}

void printStr(vector<string>& vec, string& str){
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