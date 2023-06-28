/*
13. Write a function that takes a vector<string> argument and returns a 
    vector<int> containing the number of characters in each string. Also 
    find the longest and the shortest string and the lexicographically first and 
    last string. How many separate functions would you use for these tasks? 
    Why?
    ANSWER:
    func takes vec<str> and returns vec<int> = one function
    func print all vec<int> = one function
    func print lexicographically first and last string = one function
    func print longest string = one function
    func print shortest string = one function
    There could be more, like seperating sorted vectors in print function
    or a function that gets longest/shortes value and another function that prints it
*/

#include "../../std_lib_facilities.h"

vector<int> numOfCharsInVec(const vector<string>& str);
void printLexicograp(const vector<string>& strs);
void printVector(vector<int>& numsOfChars);
void longestString(const vector<string>& str);
void shortestString(const vector<string>& str);

int main(int argc, char* argv[]){
    vector<string> strs = {"Hello", "World", "Just", "Quit","Or", "Don't", "Give", "Up","And", "Quit"};
    vector<int> numOfChars = numOfCharsInVec(strs);
    printLexicograp(strs);
    printVector(numOfChars);
    longestString(strs);
    shortestString(strs);
}
void longestString(const vector<string>& strs){
    vector<string> str = strs;
    sort(str.begin(),str.end());
    int longest = 0;
    for (size_t i = 1; i < str.size(); i++){
        if(str[i-1].length()<str[i].length()){
            longest = str[i].length();
        }
    }
    cout<<"longst letter is: "<<longest<<'\n';
}
void shortestString(const vector<string>& strs){
    int shortest = 0;
    vector<string> str = strs;
    sort(str.begin(),str.end());
    for (size_t i = 1; i < str.size(); i++){
        if(str[i-1].length()>str[i].length()){
            shortest = str[i].length();
        }
    }
    cout<<"Shortest letter is: "<<shortest<<'\n';
}

void printLexicograp(const vector<string>& strs){
    vector<string> str = strs;
    sort(str.begin(),str.end());
    int n = str.size();
    for (int i = 0; i < n; i++){
        cout<<str[i]<<" has "<<str[i].length()<<" letters\n";
    }
}

void printVector(vector<int>& numsOfChars){
    int n = numsOfChars.size();
    for (int i = 0; i < n; i++){
        cout<<numsOfChars[i]<<'\n';
    }
}

vector<int> numOfCharsInVec(const vector<string>& str){
    size_t n = str.size();
    vector<int> nums;
    for (size_t i = 0; i < n; i++){
        nums.push_back(str[i].length());
    }
    return nums;
}