#include "./std_lib_facilities.h"

int main()
{
  /*Program that *bleeps* words you do not like
   * read words in with cin and print out cout
   * if word you dont like, print BLEEP
   */
  vector<string>disliked = {"broccoli","Hello","windows","fork","cup","cap"};
  bool wordfail = false;
  vector<string>words;
  for(string temp; cin>>temp;) //read whitespace-separated words
      words.push_back(temp);  //put into vector

  cout<<"Number of words: "<<words.size()<<'\n';

  //sort(words); //sort the words

  for(int i = 0; i<words.size();++i)
  {
    
    for(int j = 0;j<disliked.size();++j)
    {
      if(words[i]==disliked[j])
        {
          cout<<"'BLEEP'"<<" ";
          wordfail = true;
        }
    }
    if(wordfail == true){
      wordfail = false;
        
    }else if(wordfail == false){
      cout<<words[i]<<" ";
    }
  }
}
    
