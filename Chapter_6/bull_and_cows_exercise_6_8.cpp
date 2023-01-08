#include "../std_lib_facilities.h"

/* 8. Redo the Bulls and Cows game from exercise 12 in Chapter 5 to use
 * four letters rather than four digits.
 */
string RandomString(int ch); //Declaration of RandomString

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
  vector <string> guessing_number { //passing random numbers into vector
    RandomString(1), // random nr. 1
    RandomString(1), // random nr. 2
    RandomString(1), // random nr. 3
    RandomString(1)  // random nr. 4
  };
  vector <string> user_guesses; //define vector guesses that user inputs
  int bull_count = 0; //Initialize bull counts
  int cow_count = 0;  //Initialize bull counts
  string bull_letter = "";
  string user_guess_1 = "";
  string user_guess_2 = "";
  string user_guess_3 = "";
  string user_guess_4 = "";
  for(int i = 0; i < guessing_number.size();++i) cout<<guessing_number[i]<<" ";
  cout<<"Please write 4 number 0-9\n";
  //print out the number to be guessed and starting text
  while(cin>>user_guess_1>>user_guess_2>>user_guess_3>>user_guess_4)
  {
    user_guesses.push_back(user_guess_1);
    user_guesses.push_back(user_guess_2);
    user_guesses.push_back(user_guess_3);
    user_guesses.push_back(user_guess_4);
    //Wait for user input for 4 numbers and endless loop
    //2 4 2 7 teldan
    //4 4 5 2 vit gita
    for(int bull = 0; bull < guessing_number.size();++bull)
    { // loop through bull row and comparare 1 by 1 and see if we guessed the right letter
      if(guessing_number[bull] == user_guesses[bull]) 
        {
          ++bull_count; //if user guesses the letter in the right place, count 1 bull 
          bull_letter = user_guesses[bull]; //store in bull, to seperate cow
        }
      for(int findCow = 0; findCow<guessing_number.size(); ++findCow)
      {// loop through our letter for every computer letter to see if we guessed a cow
        if(guessing_number[bull] == user_guesses[findCow]){
          if(bull_letter == user_guesses[findCow])
          {

          }else{
            ++cow_count;//User guesses the letter, but not in the right place, count 1 cow 
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
 string RandomString(int ch)
  {
      const int ch_MAX = 26;
      char alpha[ch_MAX] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g',
                            'h', 'i', 'j', 'k', 'l', 'm', 'n',
                            'o', 'p', 'q', 'r', 's', 't', 'u',
                            'v', 'w', 'x', 'y', 'z' };
      string result = "";
      for (int i = 0; i<ch; i++)
          result = result + alpha[rand() % ch_MAX];

      return result;
  }
