#include "./std_lib_facilities.h"

bool check_duplicates(string name, int score);
void push_back_inputs(string name, int score);
void check_bad_inputs(string name, int score);
void search_name_and_score(string name, int score);

  vector<string>names;
  vector<int>scores;
  string name = "";
  int score = 0;
  bool name_taken = false;
  bool score_taken = false;

int main()
{
  /* Exercise 19: 
   * Writa a program where you enter  a set of values
   * name-and-value pairs. Fx. Joe 17 and Barbara 22.
   * Add Joe in a vector called names and 17 in scores.
   * So names[7] == "Joe" and scores[7] == 17.
   * Terminate input with NoName 0. 
   * Check that each input is unique and terminate if
   * with an error msg if name entered twice.
   * Write out all names and scores pairs one per line.
   * Exercise 20:
   * Modify the program so when you enter a name,
   * the program will output score or name not found
   * Exercise 21:
   * Modify the program so when you enter an integer,
   * the program wil output all the names with that score
   * or if no score print score not found.
   * Comments: 
   * This was not that hard in the beginning, but I tried
   * implementing functions and switch statements
   * for this program and that made it far
   * harder, especally since it is my first time
   * I will continuing on to try and make main() as
   * small as I can while implementing functions.
   * Implementing functions for this exercise was fun.
   */
  bool start_end = true;
  char user_action = 0; 
  while(start_end){
    cout<<"Insert name and score (1)\nSearch names and score(2)\n"
        <<"Press 3 to stop the program\n";
    cin>>user_action;
    switch (user_action){
      case '1':
        cout<<"Please input a name and scroe\ninput 's' to stop loop\n";
        while(cin>>name>>score){
          if(name == "s"){
              break;
          }else{
              check_bad_inputs(name, score);
          }
        }
        cout<<"Back to chooseing search options\n";
        break;
      case '2':
        cout<<"Search by name and score (1)\n"
            <<"Search by score only (2)\n";
        while(cin>>user_action){
          if(user_action == '3')
                break;
          switch(user_action){
            case '1':
              cout<<"Please input name and score to search the db\n"
                  <<"'s' to stop\n";
              while(cin>>name>>score){
                if(name == "s"){
                    cout<<"Back to chooseing search options\n";
                    break;
                }else{
                  search_name_and_score(name,score);
                }
              } 
              break;

            case '2':
              cout<<"Please input score to search the db\n"
                  <<"'s' to stop\n";
              while(cin>>score){
                if(score == 's'){
                    cout<<"Back to chooseing search options\n";
                    break;
                }else{
                  for(int i = 0; i < scores.size(); i++){
                    if(score == scores[i]){
                      cout<<"Name: "<<names[i]<<" score: "<<scores[i]<<'\n';
                      score_taken = true;
                    }
                  } 
                }
                if(score_taken == false)
                    cout<<"Sorry, score "<<score<<" not found.\n";
                score_taken = false;
               }
              break;

            defalut:
              cout<<user_action<<" is and invalid action\n"
                  <<"Please try 1, 2 og 3";
              break;
          }

        }

        break;

      case '3':
        start_end = false;
        break;

      default:
        cout<<user_action<<" is and invalid action, please choose 1, 2 or 3\n";
        break;
    }
  }
for(int i = 0; i < names.size(); i++)
    cout<<names[i]<<" "<<scores[i]<<'\n';
start_end = false;
}

bool check_duplicates(string name, int score){
      for(int i = 0; i < names.size(); i++){
        if(name == names[i] && score == scores[i]){
            name_taken = true;      
          }
      } 
  return name_taken;
}
void push_back_inputs(string name, int score){
    names.push_back(name);
    scores.push_back(score);
}

void check_bad_inputs(string name, int score){
    if(names.size() == 0 && scores.size() == 0){ //First input no check
      push_back_inputs(name,score);
    }else{
      name_taken = check_duplicates(name,score);
      if(name_taken == false){
        push_back_inputs(name,score);
      }else{
        cout<<"Sorry, the name "<<name<<" and score "<<score
            <<" is taken, please try again\n";
      }
      name_taken = false; // reset name_taken flag
      }
          
}
void search_name_and_score(string name, int score){
      name_taken = check_duplicates(name,score);
      if(name_taken == true){
        cout<<"The name "<<name<<" and "<<score<<" is in the db\n";
      }else {
          cout<<"Sorry, the name "<<name<<" and score "<<score
              <<" are not in the db. Please try again\n";
      }
      name_taken = false; //reset value
}
