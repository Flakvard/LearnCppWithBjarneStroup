#include "../std_lib_facilities.h"

/*
 * Add the article "the" to the "English" grammer in 
 * 6.4.1, so that it can describe sentace such as 
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
int main()
{
  string sentence = "";
  vector <string> words;
  while(true)
  {
    cin>>sentence;
    if(sentence == ".")
        break;
    if(words.size() == 0){
       words.push_back(Sentences(sentence));
    }else{
       words.push_back(Sentences(sentence));
    }
  }
  for(int i = 0; i<words.size(); ++i)
    cout<<words[i];
}

string Sentences(string sentence)
{
  string d = sentence;
  string words = "";
  words = Article(d);
  return words;
};

string Article(string sentence)
{
  string d = sentence;
  if(d == "the")
  {
    return d;
  }else{
    return Noun(d);
  }
}
string Noun(string sentence)
{
  string d = sentence;
  if(d == "birds"||d == "fish"||d == "C++")
  {
    return d;
  }else{
    return Verb(d);
  }
}

string Verb(string sentence)
{
  string d = sentence;
  if(d == "rules"||d == "fly"||d == "swim")
  {
    return d;
  }else{
    return Conjunction(d);
  }
}

string Conjunction(string sentence)
{
  string d = sentence;
  if(d == "and"||d == "or"||d == "but")
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
