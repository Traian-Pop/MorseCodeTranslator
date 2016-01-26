/*
Course Number:  CSE1342-801
Programmer:     Traian Pop
Date:           12/6/2015
Program Number: Program 6
Purpose:        Translate a sentence to and from morse code.
Server:		 genuse40.lyle.smu.edu
Instructor: Don Evans
TA:        Christopher Horst

Sources Consulted: Google
*/

#include "Translator.h"
#include <iostream>
using namespace std;

int main()
{
    Translator test("MorseCode.txt"); //open file;
    int place = 0;
    while (place != 5) //repeat until user chooses to exit
    {
      cout << "1 - Translate Morse to Character" << endl;
      cout << "2 - Translater Character to Morse" << endl;
      cout << "3 - Display Morse to Character Key" << endl;
      cout << "4 - Display Character to Morse Key" << endl;
      cout << "5 - Exit the Program" << endl;
      cin >> place;
      string temp;
      vector<string> temp1;
      while (place < 1 || place > 5) //error checking
      {
        cout << "Incorrect choice. Please repick." << endl;
        cin >> place;
      }
      switch (place)
      {
        case 1: //user picks choice 1
          cout << "Enter sentence: ";
          cin.ignore();
          getline(cin, temp);
          cout << test.TranslateMorseToChar(temp) << endl;
          break;
        case 2: //user picks choice 2
          cout << "Enter sentence: ";
          cin.ignore();
          getline(cin, temp);
          temp1 = test.TranslateCharacterToMorse(temp);
          for (auto i : temp1)
          {
            cout << i << " ";
          }
          cout << endl;
          break;
        case 3: //user picks choice 3
          test.DisplayMorseToCharKey();
          cout << endl;
          break;
        case 4: //user picks choice 4
          test.DisplayCharToMorseKey();
          cout << endl;
          break;
      }
    }
}
