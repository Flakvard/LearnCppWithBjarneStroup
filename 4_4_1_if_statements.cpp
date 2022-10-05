#include "./std_lib_facilities.h"

int main()
{
    // Try this! Write a program that converts dollar to yen and dollar to kroner
    constexpr double dollar_to_kroner = 7.45; // initilize the constant expression for dollar-to-krone conversion
    constexpr double dollar_to_yen = 144.11;  // initilize the constant expression for dollar-to-yen conversion

    double dollar = 0;          // initilize the variable dollar to 0
    double converted_value = 0; // initilize the variable converted_value to 0
    char conversion = 0;        // initilize the variable conversion to 0

    cout << "This program helps you convert dollar to yen or krones,"
         << "\nplease write dollars you want to convert followed by 'k' = kroner or 'y' = yen\n";

    while (cin >> dollar >> conversion)
    {
        if (conversion == 'y')
        {
            converted_value = dollar * dollar_to_yen; // assign the converted value of dollar to yen
            cout << "$" << dollar << " dollars is in japanese Yen JPY " << converted_value << ",-\n"; //print out the converted value 
        }
        else if (conversion == 'k')
        {
            converted_value = dollar * dollar_to_kroner; // assign the converted value of dollar to kroner
            cout << "$" << dollar << " dollars is in danish krones DKK " << converted_value << ",-\n"; //print out the converted value 
        }
        else
            cout << "ERROR: '"<<conversion<<"' is an invalid conversion unit, please write 'k' for danish kroner or 'y' for japanese yen\n"; //print out invalid units 
    }
}