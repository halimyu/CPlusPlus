/***************************************************************************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ * Programmer: Yusuf Halim                                                                                  / *
/ * Date: 09/23/2022                                                                                         / *
/ * Name: Wordle.h                                                                                           / *
/ * Description:Wordle class definetions rest here in this file                                               / *
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
***************************************************************************************************************/


#ifndef HW3_WORDLE_H
#define HW3_WORDLE_H

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Wordle {
public:

/////////////////////////////////////////////////////////////
///
/// Description: << Constructor of the class>>
/// Inputs: << filename, string variable, used to setup the class WordListFilename to the filename inputted using
///             setWordlistFilename method>>
/// Output: << no returned value >>
///
/////////////////////////////////////////////////////////////
    explicit Wordle(string wordListFilename = "");

/////////////////////////////////////////////////////////////
///
/// Description: << returns the filename >>
/// Inputs: << no Input >>
/// Output: << Returns a string value of wordListFilename, it's the filename that will be used to get the word list >>
///
/////////////////////////////////////////////////////////////
    const string &getWordListFilename() const;

/////////////////////////////////////////////////////////////
///
/// Description: << Describe what the function does. >>
/// Inputs: << wordListFilename, String variable, used to set the original wordListFilename variable to the filename >>
/// Output: << No return values >>
///
/////////////////////////////////////////////////////////////
    void setWordListFilename(const string &wordListFilename);

/////////////////////////////////////////////////////////////
///
/// Description: << returns the vector wordlist >>
/// Inputs: << no Inputs >>
/// Output: << wordList, vector of type string, will be used to print all word lists in the file >>
///
/////////////////////////////////////////////////////////////
    const vector<string> &getWordList() const;

/////////////////////////////////////////////////////////////
///
/// Description: << sets the wordlist vector to the input vector >>
/// Inputs: << wordList, vector of type string, used to to set class wordList to wordList input in the file>>
/// Output: << no return value >>
///
/////////////////////////////////////////////////////////////
    void setWordList(const vector<string> &wordList);

    string getSecretWord() const;

    void setSecretWord(string secretWord);

/////////////////////////////////////////////////////////////
///
/// Description: << reads the word list file and know how many words in there, resize the vector, and then
///                 read the words into the vector>>
/// Inputs: << No inputs >>
/// Output: << No return value >>
///
/////////////////////////////////////////////////////////////
    void loadWordList();

/////////////////////////////////////////////////////////////
///
/// Description: << Outputs either a message that there's no word list to print or the word list >>
/// Inputs: << No input >>
/// Output: << no return value>>
///
/////////////////////////////////////////////////////////////
    void printWordList() const;

/////////////////////////////////////////////////////////////
///
/// Description: << Prints the guess vector along the feedback vector>>
/// Inputs: << No input >>
/// Output: << no return value>>
///
/////////////////////////////////////////////////////////////
    void print() const;

    void printAvailableLetters() const;

/////////////////////////////////////////////////////////////
///
/// Description: << Generates a random number from 0 to the size of the worldList vector and then gets the position of
/////               the word with that number and set it as the secret word >>
/// Inputs: << No input >>
/// Output: << no return value>>
///
/////////////////////////////////////////////////////////////
    void setRandomSecretWord();


/////////////////////////////////////////////////////////////
///
/// Description: << returns the number of times a word was guessed>>
/// Inputs: << No input >>
/// Output: << int , guessNum, returns the number of times a word was guessed>>
///
/////////////////////////////////////////////////////////////
    int getGuessNum() const;

/////////////////////////////////////////////////////////////
///
/// Description: << Gets a string from the main function and compare it if it's in the wordlist and have 5 chars
///                 if true see if it matches secretword and added it guess vector and accumlate guessnum>>
/// Inputs: << string, guess word, a guess word from the main function >>
/// Output: << return true if a word equals secretword, false otherwise>>
///
/////////////////////////////////////////////////////////////
    bool makeGuess(string word);

    const int getMaxGuessNum() const;



private:
    string wordListFilename; // name of the filename that contains the words
    string secretWord; // the word that the user will guess
    int guessNum = 0;  // number of guesses
    const int MAX_GUESS_NUM = 6; // maximum number of guesses
    bool availableLetter[26]; // contains all the valid letters in the secret word

    vector<string> guess;  // list of previous guesses
    vector<string> feedback; // list of feedback strings
    vector<string> wordList; // vector that contains all the words
    vector<char> alphabets;

};


#endif //HW3_WORDLE_H
