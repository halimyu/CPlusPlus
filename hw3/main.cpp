/***************************************************************************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ * Programmer: Yusuf Halim                                                                                  / *
/ * Date: 09/23/2022                                                                                         / *
/ * Name: main.cpp                                                                                           / *
/ * Description: main function tests Wordle class and prints to the user if the tests passed                 / *
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
***************************************************************************************************************/

#include <iostream>
#include "Wordle.h"

using namespace std;

int main() {

//    Wordle wordle3("wordList.txt");
//    wordle3.loadWordList();
//    wordle3.setRandomSecretWord();
//    wordle3.setSecretWord("awake");
//    cout << wordle3.getSecretWord() << endl;
//    wordle3.makeGuess("thars");
//    wordle3.makeGuess("vezir");
//    wordle3.makeGuess("vezir");
//    wordle3.makeGuess("vezir");
//    wordle3.makeGuess("stall");
//    wordle3.makeGuess("llama");
//    wordle3.printAvailableLetters();
//
//    Wordle wordle4("wordList.txt");
//    wordle4.loadWordList();
//    wordle4.setRandomSecretWord();
//    wordle4.setSecretWord("awake");
//    cout << wordle4.getSecretWord() << endl;
//    wordle4.makeGuess("thars");
//    wordle4.makeGuess("vezir");
//    wordle4.makeGuess("valid");
//    wordle4.makeGuess("calid");
//    wordle4.makeGuess("stall");
//    wordle4.makeGuess("awake");
//    wordle4.printAvailableLetters();

    cout << "You have 6 guesses to guess the correct secret word!" << endl;
    cout << "The secret word has to be 5 letters and it has to be in the wordList file to be counted as a guess" << endl;

    Wordle wordle2("wordList.txt");
    wordle2.loadWordList();
    wordle2.setRandomSecretWord();
    string secret;
    cout << "guess the secret word" << endl;
    while((wordle2.getGuessNum() < wordle2.getMaxGuessNum())){
        cin >> secret;
        if (secret == wordle2.getSecretWord()){
            wordle2.makeGuess(secret);
            break;
        }
        wordle2.makeGuess(secret);

    }



//    // Test one with no parameters
//    Wordle test;
//    test.loadWordList();
//    test.printWordList();
//
//    // Test two with a file not included in the directory and then using setWordListFilename to correct it
//    Wordle wordle1("words.txt");
//    wordle1.setWordListFilename("wordList.txt");
//    wordle1.loadWordList();
//    wordle1.setRandomSecretWord();
//    cout << wordle1.getSecretWord() << endl;
//    wordle1.setSecretWord("grade");
//    wordle1.makeGuess("major");
//    wordle1.print();
//    wordle1.makeGuess("major");
//    wordle1.makeGuess("major");
//    wordle1.makeGuess("vezir");
//    wordle1.makeGuess("stall");
//    wordle1.print();
//    wordle1.makeGuess("grade");
//    wordle1.print();
//    //wordle1.printWordList();
//
//
//    // Test three with the actual file and used all gusses
//    Wordle wordle("wordList.txt");
//    wordle.loadWordList();
//    wordle.setRandomSecretWord();
//    wordle.setSecretWord("awake");
//    cout << wordle.getSecretWord() << endl;
//    wordle.makeGuess("thars");
//    wordle.print();
//    wordle.makeGuess("vezir");
//    wordle.makeGuess("vezir");
//    wordle.makeGuess("vezir");
//    wordle.makeGuess("stall");
//    wordle.print();
//    wordle.makeGuess("llama");
//    wordle.print();
//    //wordle.printWordList();

    return 0;

}
