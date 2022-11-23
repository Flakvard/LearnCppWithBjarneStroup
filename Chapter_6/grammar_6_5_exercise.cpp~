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
vector<string> conj_vect = {
    "and",
    "or",
    "but"

};
vector<string> noun_vect = {
    "birds",
    "fish",
    "C++",
};
vector<string> artice_vect = {
    "the"
};
vector<string> verb_vect = {
    "rules",
    "fly",
    "swim"
};
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
  for(int i = 0; i<conj_vect.size(); ++i)
  {
    if(d == conj_vect[i])
    {
      for(int i = 0; i<verb_vect.size(); ++i)
      {
      if(words[words.size()-1] == verb_vect[i])
         return "OK!";
      else return "Not OK!";
      }
    }
  }
  return Verb(d);
}

string Verb(string sentence)
{
  string d = sentence;
  for(int i = 0; i<verb_vect.size(); ++i)
  {
    if(d == verb_vect[i])
    {
      for(int i = 0; i<noun_vect.size(); ++i)
      {
      if(words[words.size()-1] == noun_vect[i])
         return "OK!";
      else return "Not OK!";
      }
    }
  }
  return Noun(d);
}

string Noun(string sentence)
{
  string d = sentence;
  for(int i = 0; i<noun_vect.size(); ++i)
  {
    if(d == noun_vect[i])
    {
      if(words[words.size()-1] == "the")
         return "OK!";
      else return "Not OK!";
    }
  }
  return Article(d);
}

string Article(string sentence)
{
  string d = sentence;
  if(d == "the")
  {
    return "OK!";
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
 * Verb:
 *    "rules"
 *    "fly"
 *    "swim"
 * Noun:
 *    "birds"
 *    "fish"
 *    "C++"
 * Article:
 *    "the"
 */

