#include <stdio.h>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Translator
{
  private:
    ifstream morseKey; //file object
    map<char, string> charToMorse; //map #1
    map<string, char> morseToChar;//map #2
  public:
    Translator(string); //constructor
    vector<string> TranslateCharacterToMorse(string&); //method to return translation from charcater to morse
    string TranslateMorseToChar(string&); //method to return translation from morse to character
    void DisplayCharToMorseKey(); //method to print out char to morse map
    void DisplayMorseToCharKey(); //method to print out morse to char map
};
