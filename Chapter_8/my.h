

extern int foo;

namespace X{
    extern int var;
    void print(int);
}

namespace Y {
    extern int var;
    void print_foo();
    void print(int);
}
namespace Z{
    extern int var;
    void print(int);
}
void swap_r(int& a, int& b);
int swap_v(int a, int b);
void swap_cr(const int& a, const int& b);