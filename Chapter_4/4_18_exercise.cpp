#include "./std_lib_facilities.h"

int main()
{
   /* Write a program to solve quadratic equations. A quadratic
    * equation is of the from:
    *                   ax²+bx+c=0
    * If you don't know the quadratic formula for solving such
    * expression, do some research.
    * Use doubles for the user inputs for a, b and c. Since 
    * there are two solutions to a quadratic equation, output
    * both x1 and x2.
    * Comments:
    * I have seen this equation before in school, but I did not 
    * remember it so I had to research online
    *
    */


 vector<string> words;
 vector<string> smWords;
 vector<string> lgWords;
 vector<int> wordSizes;

 cout << "Enter a set of whitespaced separated words (press enter then ctrl+z when finished): \n";
 string w;
 while (cin >> w)
 {
  words.push_back(w);
 }

 sort(words);

 string word;
 string mode;
 string mostOccurring;
 int highCount = 0;
 int count = 0;

 //print the words entered in order
 for (int i = 0; i < words.size(); ++i)
 {
  cout << words[i] << " ";
 }

 //calculate mode
 for (int i = 0; i < words.size(); ++i)
 {
  //get the ball rolling
  if (i == 0)
  {
   word = words[i];
   ++count;
  }

  else
  {
   if (word == words[i])
   {
    ++count;
    mode = words[i];
   }
   else
   {
    if (highCount == 0)
    {
     highCount = count;
     mostOccurring = mode;
    }

    else if (count > highCount)
    {
     highCount = count;
     mostOccurring = mode;
    }

    word = words[i];
    count = 1;

   }
  }
 }

 //calculate min & max
 for (int x = 0; x < words.size(); ++x)
 {
  wordSizes.push_back(words[x].size());
 }

 sort(wordSizes);

 int smallestWS = wordSizes[0];
 int largestWS = wordSizes[wordSizes.size() - 1];

 for (int x = 0; x < words.size(); ++x)
 {
  if (words[x].size() == smallestWS)
   smWords.push_back(words[x]);

  if (words[x].size() == largestWS)
   lgWords.push_back(words[x]);
 }


 //print results
 if (highCount == 1)
  cout << "\nThere is no mode in this set of words.";
 else
 {
  cout << "\nThe mode is: " << mostOccurring;
  cout << "\nAppearing " << highCount << " time(s)";
 }

 cout << "\nThe largest word(s): ";
 for (int x = 0; x < lgWords.size(); ++x)
  if(x == 0 || lgWords[x] != lgWords[x-1])
  cout << lgWords[x] << " ";

 cout << "\nThe smallest words(s): ";
 for (int x = 0; x < smWords.size(); ++x)
  if (x == 0 || smWords[x] != smWords[x - 1])
  cout << smWords[x] << " ";


 cout << '\n';

 keep_window_open();

 return 0;
}



