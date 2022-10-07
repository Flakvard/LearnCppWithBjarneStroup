#include "./std_lib_facilities.h"

int main()
{
    char a = 'a';
    char z = 'z';
    int integer_a = a;
    int integer_z = z;

    while (integer_a <= integer_z)
    {
        cout << a << " = " << integer_a<<'\n';
        ++a;
        ++integer_a;
    }
}