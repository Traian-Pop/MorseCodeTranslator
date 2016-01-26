#include <stdio.h>
#include <fstream>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
#include "Translator.h"
#include <sstream>
#include <iterator>
using namespace std;

Translator::Translator(string temp)
{
    morseKey.open(temp.c_str()); //open file
    char letter;
    string code;
    while (morseKey>>letter>>code) //read in the file
    {
      charToMorse[letter] = code; //assign letter to code
      morseToChar[code] = letter; //assign code to letter
    }
}

string Translator::TranslateMorseToChar(string &temp)
{
  string value;
  string returnOne;
  stringstream ss(temp); //get rid of the white spaces
  for (int i = 0; ss >> value; i++) //return the respective char value for each morse
    returnOne += morseToChar[value]; //add all the char values to one return string
  return returnOne;
}

vector<string> Translator::TranslateCharacterToMorse(string &temp)
{
  string value;
  string returnOne;
  vector<string> elems; //make return vector
  stringstream ss(temp); //get rid of the white spaces
  for(int i = 0; ss >> value; i++) //iterate through the words of the sentence
    for (char& c : value) //iterate through letter of each word
      elems.push_back(charToMorse[toupper(c)]); //transform each letter into a morse code equivalent
  return elems;
}

void Translator::DisplayCharToMorseKey()
{
  for(map<char, string>::iterator it = charToMorse.begin(); it != charToMorse.end(); ++it)//iterates through the map
    cout << it->first << " " << it->second << endl; //prints value out
}

void Translator::DisplayMorseToCharKey()
{
  for(map<string, char>::iterator it = morseToChar.begin(); it != morseToChar.end(); ++it)//iterates through the map
    cout << it->first << " " << it->second << endl; //prints value out
}
