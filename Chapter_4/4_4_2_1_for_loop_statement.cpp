#include "./std_lib_facilities.h"

int main()
{
    char a = 'A';
    char z = 'Z';
    int integer_a = a;
    int integer_z = z;

    for (integer_a; integer_a <= integer_z; ++integer_a)
    {
        
        cout << a << " = " << integer_a<<'\n';
        ++a;
    }
}
