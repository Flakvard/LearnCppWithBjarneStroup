#include "../std_lib_facilities.h"

/*
 * Add the article "the" to the "English" grammer in 
 * ½6.4.1, so that it can describe sentace such as 
 * "The birds fly but the fish swim".
 */

/* Sentence:
 *    Article Noun Verb                     // e.g., the C++ rules
 *    Sentence Conjunction Sentence // e.g., Birds fly but fish swim
 * Conjunction:
 *    "and"
 *    "or"
 *    "but"
 * Noun:
 *    "birds"
 *    "fish"
 *    "C++"
 * Article:
 *    "the"
 * Verb:
 *    "rules"
 *    "fly"
 *    "swim"
 */
 /* Write a program that checks if a sentence is correct according
  * to the "English" grammar in 6.4.1. Assume that every sentence is
  * terminated by a full stop (.) surrounded by whitespace. For 
  * example, "birds fly but the fish swim ." is a sentence, but 
  * "birds fly but the fish swim " (terminating dot missing) and
  * "birds fly but the fish swim." (no space before dot) are not.
  * For each sentence entered, the program should simply respond "OK"
  * or "not OK."
  * Hint: Don't bother with tokens; just read into string
  * using >>.
  */
string Sentences(string sentence);
string Conjunction(string sentence);
string Noun(string sentence);
string Article(string sentence);
string Verb(string sentence);
vector<string> words;
int main()
{
  string sentence = "";
  while(true)
  {
    cin>>sentence;
    if(sentence == "."){
      for(int i = 0; i<words.size(); ++i)
        cout<<words[i]<<" ";
    }
    if(words.size() == 0){
    words.push_back(sentence);
    }else{
    words.push_back(Sentences(sentence));
  }
  }
}
string Sentences(string sentence)
{
  string d = sentence;
  string words = "";
  words = Conjunction(d);
  return words;
};

string Conjunction(string sentence)
{
  string d = sentence;
  if(d == "and"||d == "or"||d == "but")
  {
    if(words[words.size()-1] == "fly")
      return d;
    else return "Not OK!";
  }else{
    return Verb(d);
  }
}

string Verb(string sentence)
{
  string left = words[words.size()-1];
  string d = sentence;
  if(d == "rules"||d == "fly"||d == "swim"&& left == "birds")
  {
    if(words[words.size()-1] == "birds")
      return d;
    else return "Not OK!";
  }else{
    return Noun(d);
  }
}

string Noun(string sentence)
{
  string d = sentence;
  if(d == "birds"||d == "fish"||d == "C++" )
  {
  if(words[words.size()-1] == "the")
      return d;
  else return "Not OK!";
  }else
    return Article(d);
  
}

string Article(string sentence)
{
  string d = sentence;
  if(d == "the")
  {
    return d;
  }else{
    return "Not OK!";
  }
}


/* Sentence:
 *    Article Noun Verb                     // e.g., the C++ rules
 *    Sentence Conjunction Sentence // e.g., Birds fly but fish swim
 * Conjunction:
 *    "and"
 *    "or"
 *    "but"
 * Noun:
 *    "birds"
 *    "fish"
 *    "C++"
 * Article:
 *    "the"
 * Verb:
 *    "rules"
 *    "fly"
 *    "swim"
 */
