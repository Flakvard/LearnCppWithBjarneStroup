#include "./std_lib_facilities.h"

int main()
{
  /* Write a Rock, Paper, Scissors game.
   * use vector to store the computers actions
   * make it more 'random' by letting the user
   * add the actions into the vector. Use a
   * switch statement to solve this exercise
   */

  vector<char> computer_action = {};
  char choose_comp_act = ' ';
  char user_action = ' ';
  cout<<"Please choose 5 (r)ock, (p)aper or (s)cissors\n for the computer\n";

  for(int i = 0; i < 5; ++i){
      cin>>choose_comp_act;
      computer_action.push_back(choose_comp_act);
  }

  for(int i = 0; i < computer_action.size();i++){
    cout<<"Please choose (r)ock, (p)aper or (s)cissors\n";
    cin>>user_action; 
    switch (user_action){
        case 'r':
           cout<<"Computer choose: "<<computer_action[i]<<'\n';
           if(computer_action[i]==user_action) cout<<"Wow, even-steven\n";
           if(computer_action[i] == 's') cout<<"Awesome, you won\n";
           if(computer_action[i] == 'p') cout<<"Sorry, you lost\n";
           break;
        case 'p':
           cout<<"Computer choose: "<<computer_action[i]<<'\n';
           if(computer_action[i]==user_action) cout<<"Wow, even-steven\n";
           if(computer_action[i] == 'r') cout<<"Awesome, you won\n";
           if(computer_action[i] == 's') cout<<"Sorry, you lost\n";
         break;
        case 's':
           cout<<"Computer choose: "<<computer_action[i]<<'\n';
           if(computer_action[i]==user_action) cout<<"Wow, even-steven\n";
           if(computer_action[i] == 'p') cout<<"Awesome, you won\n";
           if(computer_action[i] == 'r') cout<<"Sorry, you lost\n";
         break;
        default:
           cout<<"Wrong char, please choose r, p or s as options\n";
           break;
    }
  }
}
