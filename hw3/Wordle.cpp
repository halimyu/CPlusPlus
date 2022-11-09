/***************************************************************************************************************
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/ * Programmer: Yusuf Halim                                                                                  / *
/ * Date: 09/22/2022                                                                                         / *
/ * Name: Wordle.cpp                                                                                         / *
/ * Description: source file where all the methods are initialized                                           / *
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
***************************************************************************************************************/

#include "Wordle.h"

#include <utility>

/////////////////////////////////////////////////////////////
///
/// Description: << Constructor of the class>>
/// Inputs: << filename, string variable, used to setup the class WordListFilename to the filename inputted using
///             setWordlistFilename method>>
/// Output: << no returned value >>
///
/////////////////////////////////////////////////////////////
Wordle::Wordle(string filename) {
    Wordle::setWordListFilename(filename);
    for (bool & i : availableLetter) {
        i = true;
    }
    for(char lwalpCh = 'a'; lwalpCh <= 'z'; lwalpCh++)
    {
        alphabets.push_back(lwalpCh);
    }
    srand (time(nullptr));
}

/////////////////////////////////////////////////////////////
///
/// Description: << returns the filename >>
/// Inputs: << no Input >>
/// Output: << Returns a string value of wordListFilename, it's the filename that will be used to get the word list >>
///
/////////////////////////////////////////////////////////////
const string &Wordle::getWordListFilename() const {
    return wordListFilename;
}

/////////////////////////////////////////////////////////////
///
/// Description: << Describe what the function does. >>
/// Inputs: << wordListFilename, String variable, used to set the original wordListFilename variable to the filename >>
/// Output: << No return values >>
///
/////////////////////////////////////////////////////////////
void Wordle::setWordListFilename(const string &wordListFilename) {
    Wordle::wordListFilename = wordListFilename;
}

/////////////////////////////////////////////////////////////
///
/// Description: << returns the vector wordlist >>
/// Inputs: << no Inputs >>
/// Output: << wordList, vector of type string, will be used to print all word lists in the file >>
///
/////////////////////////////////////////////////////////////
const vector<string> &Wordle::getWordList() const {
    return wordList;
}

/////////////////////////////////////////////////////////////
///
/// Description: << sets the wordlist vector to the input vector >>
/// Inputs: << wordList, vector of type string, used to to set class wordList to wordList input in the file>>
/// Output: << no return value >>
///
/////////////////////////////////////////////////////////////
void Wordle::setWordList(const vector<string> &wordList) {
    Wordle::wordList = wordList;
}

string Wordle::getSecretWord() const {
    return Wordle::secretWord;
}

void Wordle::setSecretWord(string secretWord) {
    if (find(wordList.begin(),wordList.end(),secretWord) == wordList.end()){
        cout << "Word was not found in the word list" << endl;
    } else {
        Wordle::secretWord = secretWord;
    }
}

/////////////////////////////////////////////////////////////
///
/// Description: << reads the word list file and know how many words in there, resize the vector, and then
///                 read the words into the vector>>
/// Inputs: << No inputs >>
/// Output: << No return value >>
///
/////////////////////////////////////////////////////////////
void Wordle::loadWordList() {
    int count = 0; // counts how many words in the file
    int position = 0; // positions to set the vector
    string word; // words of each line
    ifstream inFS; // file stream used to open files
    inFS.open(Wordle::getWordListFilename());
    // Return and error code and a message to the user if file was not opened
    if (!inFS.is_open()) {
        cout << "Error: There was an issue with accessing the file, please check the file name and try again!" << endl;
    }
    // getting the number of words in the file
    while(getline(inFS, word)){
        count++;
    }
    // starting from the begining of the file
    inFS.clear();
    inFS.seekg(0, inFS.beg);
    Wordle::wordList.resize(count); // resizing the vector to equal number of words
    // intializing words inside if the vector
    while(getline(inFS, word)){
        Wordle::wordList[position] = word;
        position++;
    }
    inFS.close(); // closing file
}

/////////////////////////////////////////////////////////////
///
/// Description: << Outputs either a message that there's no word list to print or the word list >>
/// Inputs: << No input >>
/// Output: << no return value>>
///
/////////////////////////////////////////////////////////////
void Wordle::printWordList() const {
    if (Wordle::wordList.empty() ){
        cout << "Warning: The list is empty, there's no words to print" << endl;
    }
    else {
        for (const auto & i : Wordle::wordList) {
            cout << i << endl;
        }
    }
}

/////////////////////////////////////////////////////////////
///
/// Description: << Prints the guess vector along the feedback vector>>
/// Inputs: << No input >>
/// Output: << no return value>>
///
/////////////////////////////////////////////////////////////
void Wordle::print() const {
    if (Wordle::guess.empty() ){
        cout << "The list is empty, there's no guesses to print" << endl;
    }
    else {
        for (int i = 1; i <= guess.size() ; ++i) {
            cout << i << ": " << guess[i-1] << " " << feedback[i-1] << endl;
        }
        cout << endl;
    }
}

/////////////////////////////////////////////////////////////
///
/// Description: << Generates a random number from 0 to the size of the worldList vector and then gets the position of
///                 the word with that number and set it as the secret word>>
/// Inputs: << No input >>
/// Output: << no return value>>
///
/////////////////////////////////////////////////////////////
void Wordle::setRandomSecretWord() {


    int random, max_value = Wordle::wordList.size()-1, min_value = 0;
    random = rand() % max_value + min_value; // a random number within the index of wordlist vector
    string word = Wordle::wordList[random]; // getting the word with random number generated
    setSecretWord(word); // setting the random word to secretWord


}

/////////////////////////////////////////////////////////////
///
/// Description: << returns the number of times a word was guessed>>
/// Inputs: << No input >>
/// Output: << int , guessNum, returns the number of times a word was guessed>>
///
/////////////////////////////////////////////////////////////
int Wordle::getGuessNum() const {
    return guessNum;
}

/////////////////////////////////////////////////////////////
///
/// Description: << Gets a string from the main function and compare it if it's in the wordlist and have 5 chars
///                 if true see if it matches secretword and added it guess vector and accumlate guessnum>>
/// Inputs: << string, guess word, a guess word from the main function >>
/// Output: << return true if a word equals secretword, false otherwise>>
///
/////////////////////////////////////////////////////////////
bool Wordle::makeGuess(string word) {
    if (word.size() == 5){
        if (find(wordList.begin(),wordList.end(),word) == wordList.end()){
            cout << "Sorry this guess was not found in the word list" << endl;
        } else {
                guessNum++;
                if (word == secretWord) {
                    cout << "Congrats! You guessed the secrete word" << endl;
                    feedback.push_back("!!!!!");
                    guess.push_back(word);
                    cout << guessNum << ": " << guess[guessNum-1] << " " << feedback[guessNum-1] << endl;
                    return true;
                }
                else {
                    if (guessNum != MAX_GUESS_NUM) {
                        string feedbackChar = word;
                        for (int i = 0; i < word.size(); ++i) {
                            if (secretWord.find(word[i]) != std::string::npos){
                                if (secretWord[i] == word[i]){
                                    feedbackChar[i] = '!';
                                }
                                else{
                                    feedbackChar[i] = '+';
                                }
                            } else {
                                feedbackChar[i] = '.';
                                auto letter = find(alphabets.begin(), alphabets.end(), word[i]);
                                int index = letter - alphabets.begin();
                                availableLetter[index] = false;
                            }

                        }
                        feedback.push_back(feedbackChar);
                        guess.push_back(word);
                        cout << guessNum << ": " << guess[guessNum-1] << " " << feedback[guessNum-1] << endl;
                        cout << "Wrong word! guess again" << endl;
                        cout<<endl;
                        printAvailableLetters();
                        return false;
                    }
                    else{
                        cout << "Game over! You ran out of guesses" << endl;
                        string feedbackChar = word;
                        for (int i = 0; i < word.size(); ++i) {
                            if (secretWord.find(word[i]) != std::string::npos){
                                if (secretWord[i] == word[i]){
                                    feedbackChar[i] = '!';
                                }
                                else{
                                    feedbackChar[i] = '+';
                                }
                            } else {
                                feedbackChar[i] = '.';
                                auto letter = find(alphabets.begin(), alphabets.end(), word[i]);
                                int index = letter - alphabets.begin();
                                availableLetter[index] = false;
                            }
                        }
                        feedback.push_back(feedbackChar);
                        guess.push_back(word);
                        cout << guessNum << ": " << guess[5] << " " << feedback[5];
                        cout << " secret word is: " << getSecretWord() << endl;
                        cout << endl;
                    }
                }
        }
    }
    return false;
}

const int Wordle::getMaxGuessNum() const {
    return MAX_GUESS_NUM;
}

void Wordle::printAvailableLetters() const {
    cout << "available letters to guess with:";
    for (int i = 0; i < 26; ++i) {
        if (availableLetter[i] == 1)
            cout << " " << alphabets[i] << ",";
    }
    cout<<endl;
    cout<<endl;
}





