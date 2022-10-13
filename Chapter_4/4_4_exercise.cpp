#include "./std_lib_facilities.h"

int main()
{
  /* Write a gussing game. User thinks of a number 
   * between 1 and 100 and the computer asks questions
   * to figure out what the number is. (e.g., "Is the
   * number you are thinking of less than 50?"). Your
   * program should identify the number after asking 
   * no more than 7 questions. Hint: Use the < and <=
   * operators and the if-else construct.
   */
  cout<<"Choose a number between 1-100\n";
  int gussing_number = 0; //the user input that program need to guess
  int program_number = 0; //program tracks the gussing number
  int previous_number = 0; //Track the previous guessed number
  int change_number = 0;
  int next_number = 50; //Start with if number is less or equal to 50
  string computer_question = "Is the number you are thinking of less than or equal to ";
  char answer = '0'; 
  cin>>gussing_number;
  cout<<"The program needs to guess the number: "<<gussing_number<<'\n'
      <<"Please only use \n'y' for yes and \n'n' for no, \n"
      <<"when answering question\n";
  
  for(int i = 0; i<7;){
    cout<<computer_question<<next_number;
    cin>>answer;

    if(answer == 'y'){
        program_number = next_number;
        change_number = (previous_number - next_number)/2;
        previous_number = next_number;
        if(change_number == 0) change_number = 1;
        if(change_number<0)
            next_number = previous_number + change_number;
        if(change_number>0)
            next_number = previous_number - change_number;
        ++i;

    }else if(answer == 'n'){
        program_number = next_number;
        change_number = (previous_number - next_number)/2;
        previous_number = next_number;
        if(change_number == 0) change_number = 1;
        if(change_number<0)
            next_number = previous_number - change_number;
        if(change_number>0)
            next_number = previous_number + change_number;
        ++i;
    }else{
      cout<<"Wrong, try again and use 'y' or 'n'\n";
    } 
    cout<<"Change_number "<<change_number<<'\n';  
    cout<<"Previous number "<<previous_number<<'\n';
    cout<<"Next number "<<next_number<<'\n';
    if(program_number == gussing_number) {
        i = 7;
        cout<<"Wow, you won\n";
    }

   }
  cout<<"Sorry, you have no you have chances left\n";
}
