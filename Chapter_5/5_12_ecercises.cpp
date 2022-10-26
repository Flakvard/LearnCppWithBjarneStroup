#include "../std_lib_facilities.h"

int main()
{
  /* Exercise 11: Write the guessing game called "Bulls and Cows".
   * The program has 4 integers in a vector between 0-9
   * (e.g. 1234 but not 1122) and the user's task is to
   * guess it. If the user says 1359 and the number is 1234
   * the response should be "1 bull and 1 cow", because the 
   * user got one digt (1) right and in the right position(a bull)
   * and one digt (3) right but in the wrong position (a cow).
   * the game end when the user has guessed all the digits right.
   * Exercise 12: Make a version where the user can repeatedly
   * (without stopping and restaring the program) and each game
   * has a new set of four digits. You can get four random digits
   * by calling the random number generator randint(10) from
   * std_lib_facilities four times. Ask the user to enter a number
   * (any number) and call seed_randint(n), also from std_lib_facilities
   * where n is there number user entered before calling randint(10)
   * Such an n is called a seed, and different seeds give different
   * sequences of random numbers.
   */

  srand(time(NULL)); //Random seed number from the date function
  vector <int> guessing_number { //passing random numbers into vector
    rand()%9,
    rand()%9,
    rand()%9,
    rand()%9
  }; 
  vector <int> user_guesses;
  int bull_count = 0;
  int cow_count = 0;
  int bull_number = 0;
  int user_guess_1 = 0;
  int user_guess_2 = 0;
  int user_guess_3 = 0;
  int user_guess_4 = 0;
  int random_guess = 0;
  for(int i = 0; i < guessing_number.size();++i) cout<<guessing_number[i]<<" ";
  cout<<"Please write 4 number 0-9\n";
  while(cin>>user_guess_1>>user_guess_2>>user_guess_3>>user_guess_4)
  {
    user_guesses.push_back(user_guess_1);
    user_guesses.push_back(user_guess_2);
    user_guesses.push_back(user_guess_3);
    user_guesses.push_back(user_guess_4);
  for(int i = 0; i < guessing_number.size();++i)
  {
    if(guessing_number[i] == user_guesses[i])
      {
        ++bull_count;
        bull_number = user_guesses[i]; 
      }
    for(int j = 0; j<guessing_number.size(); ++j){
      if(guessing_number[i] == user_guesses[j]){
        if(bull_number == user_guesses[j])
        {

        }else{
          ++cow_count;
        }
      }
    }
  }
  if(bull_count == 4) cout<<"Wow, you got the correct series of numbers\n";
  if(bull_count < 5 && cow_count < 5)cout<<bull_count<<" bull "<<cow_count<<" cow\n";
  bull_count = 0; // reset the counter after the results
  cow_count = 0; // reset the counter after the results
  user_guesses.clear(); //reset user guessed numbers
  }
}
