#include "./std_lib_facilities.h"

int main()
{
  /* Emperor wanted to reward the inventor of chess.
   * Inventor asked for one grain of rice for one square.
   * 2 for the second, 4 for the third and so on. Doubling
   * for each of the 64 squares.
   * Write a program to see how many squares for 1.000 grains
   * then for 1.000.000, then 1.000.000.000 grains.
   * You'll loop
   */
  int grains = 1;
  constexpr int max_squares = 64;
  for(int i = 0; i < max_squares; i++){
   grains *= 2;

   if(grains >=1000 && grains <=1500) cout<<"Total squares for 1 thousand "<<i<<'\n';
   if(grains >=1000000 && grains <=1050000) cout<<"Total squares for 1 mio "<<i<<'\n';
   if(grains >=1000000000) cout<<"Total squares for 1 mil "<<i<<'\n';
cout<<grains<<'\n';
  }
}
