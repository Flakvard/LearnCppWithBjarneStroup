#include "./std_lib_facilities.h"

int main()
{
    // Exercise 8: write out if it is an even or odd number
    /*
    int value = 0;
    int even_or_odd_number = 0;
    while (cin >> value)
    {
        even_or_odd_number = value % 2;
        if (even_or_odd_number == 0)
        {
            cout << "The value " << value << " is an even number\n";
        }
        else
            cout << "The value " << value << " is an odd number\n";
    }
    */

    // Exercise 9: convert spell-out number to numbers
    /*
     zero = 0
     one = 1
     two = 2
     three = 3
     four = 4
    */

    /*
    string digit_string = " ";

    cin>>digit_string;
    if (digit_string == "zero")
    {
        cout<<0;
    }else if (digit_string == "one")
    {
        cout<<1;
    }else if (digit_string == "two")
    {
        cout<<2;
    }else if (digit_string == "three")
    {
        cout<<3;
    }else if (digit_string == "four")
    {
        cout<<4;
    }else
        cout<<"not a number I know\n";
    */

    // Exercise 10: Calculate two values with the assigned operator

    string operands = " ";
    double val1 = 0;
    double val2 = 0;

    while (cin >> operands >> val1 >> val2)
    {
        if (operands == "+")
        {
            cout << val1 + val2;
        }
        else if (operands == "-")
        {
            cout << val1 - val2;
        }
        else if (operands == "*")
        {
            cout << val1 * val2;
        }
        else if (operands == "/")
        {
            cout << val1 / val2;
        }
        else
            cout << "Invalid operand";
    }
}