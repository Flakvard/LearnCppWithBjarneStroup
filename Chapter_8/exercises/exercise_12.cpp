/*
    Improve print_until_s() from §8.5.2. Test it. What makes a good set of 
    test cases? Give reasons. Then, write a print_until_ss() that prints until it 
    sees a second occurrence of its quit argument
*/

#include "../../std_lib_facilities.h"
void print_until_s(vector<string> v, string quit);
void print_until_ss(vector<string> v, string quit, int times);

int main(int argc, char* argv[]){
    vector<string> strings = {"Hello", "World", "Just", "Quit","Or", "Don't", "Give", "Up","And", "Quit"};
    string quit = "Quit";
    print_until_ss(strings, quit, 2);
    // print_until_s(strings, quit);
}

void print_until_s(vector<string> v, string quit)
{
    for(string s : v) {
        if (s==quit) return;
        cout << s << '\n';
    }
}

void print_until_ss(vector<string> v, string quit, int times)
{
    int flag = 0;
    for(string s : v) {
        if (s==quit) flag += 1;
        cout << s << '\n';
        if (flag==times) return;
    }
}