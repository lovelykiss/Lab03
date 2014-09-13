#if !defined PASSWORD_H
#define PASSWORD_H

//complete the includes
#include "ListArray.h"
using CSC2110::ListArray;
#include "Text.h"
using CSC2110::String;


class Password
{
   private:
      ListArray<String>* viable_words;  //the list of words that can still be the password
      ListArray<String>* all_words;  //the original list of words
      int len;  //the length of the first word entered is stored to check that all subsequent words have the same length

      //a private helper method to report the number of character matches between two Strings
      int getNumMatches(String* curr_word, String* word_guess);

   public:
      //a private helper method to report the number of character matches between two Strings
    //  int getNumMatches(String* curr_word, String* word_guess);

   public:
      Password();
      ~Password();
      void addWord(String* word);
      void guess(int try_password, int num_matches);
      int getNumberOfPasswordsLeft();
      String* getOriginalWord(int index);
	int bestGuess();
	void displayViableWords();

};









#endif
