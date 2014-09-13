#if !defined PASSWORD_H
#define PASSWORD_H

//complete the includes
#include "ListArrayIterator.h"
using CSC2110::ListArrayIterator;
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
	int max_sze;
	int sze;
      //a private helper method to report the number of character matches between two Strings
      int getNumMatches(String* curr_word, String* word_guess);

   public:
	Password();
	~Password();
	void addWord(String* word);
	void guess(int try_password, int num_matches);
	int getNumberOfPasswordsLeft();
	void displayViableWords();
	int bestGuess();
	String* getOriginalWord(int index);

};

Password::Password()
{
	max_sze = 2;
	len = 0;
	sze = 0;
	viable_words = new ListArray<String>[max_sze];
	all_words = new ListArray<String>[max_sze];
}

Password::~Password()
{
	ListArrayIterator<String>* ite = all_words->iterator();
	
	while(ite->hasNext())
	{
		String* word = ite->next();
		delete word;
	}
}

void Password::addWord(String* word)
{
	if(sze == max_sze)
	{
	}
	if(len == 0)
	{
		len = word->length();
		all_words[sze] = word;
		viable_words[sze] = word;
	}
	
	
	else if(len == word->length())
	{
		all_words[sze] = word;
		viable_words[sze] = word; 
	}
	sze++;
}

#endif
