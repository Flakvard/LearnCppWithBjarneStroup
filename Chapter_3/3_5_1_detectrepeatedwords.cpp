#include "./std_lib_facilities.h"

int main()
{
    string previous = " "; // previous word; initilize to "not a word"
    string current;
    while (cin>>current)
    {
        if (previous == current)
            cout << "Repeated word: "<<current<<'\n';
        previous = current;
    }

}