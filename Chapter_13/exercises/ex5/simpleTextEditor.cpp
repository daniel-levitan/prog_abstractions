/**
 * File: simpleTextEditor.cpp
 * --------------------------
 * This file implements a simple command-driven text editor, which is used
 * to test the EditorBuffer class.
 */

#include <iostream>

#include "buffer.h"
#include "../../../libraries/simpio.h"

using namespace std;

/* Function Prototypes */

void getCommand(string & number, string & command, string line);
void executeCommand(EditorBuffer & buffer, string line, string num);
void displayBuffer(EditorBuffer & buffer);
void printHelpText();


int main() {
    EditorBuffer buffer;

    while (true) {
        string number;
        string command;
        string cmd = getLine("*");
        getCommand(number, command, cmd);        
        if (command != "") executeCommand(buffer, command, number);
    }

    return 0;
}


/**
 * Function: executeCommand 
 * Usage: executeCommand(buffer, line);
 * ------------------------------------
 * Executes the command specified by line on the editor buffer.
 */
void executeCommand(EditorBuffer & buffer, string line, string num) {
    int number;
    switch(toupper(line[0])) {
        case 'I': cout << num << endl;
                  line += num;
                  for (int i = 1; i < line.length(); i++) { 
                      buffer.insertCharacter(line[i]);
                  }
                  displayBuffer(buffer);
                  break;
        case 'D': if (num.empty()) 
                    number = 1;
                  else
                    number = stoi(num);
                  for (int i = 0; i < number; i++)
                    buffer.deleteCharacter(); 
                  displayBuffer(buffer); break;
        case 'F': if (num.empty()) 
                    number = 1;
                  else
                    number = stoi(num);
                  for (int i = 0; i < number; i++)
                    buffer.moveCursorForward(); 
                  displayBuffer(buffer); break;
        case 'B': if (num.empty()) 
                    number = 1;
                  else
                    number = stoi(num);
                  for (int i = 0; i < number; i++)
                    buffer.moveCursorBackward(); 
                  displayBuffer(buffer); break;
        case 'J': buffer.moveCursorToStart(); displayBuffer(buffer); break;
        case 'E': buffer.moveCursorToEnd(); displayBuffer(buffer); break;
        case 'H': printHelpText(); displayBuffer(buffer); break;
        case 'Q': exit(0);

        /* delete after */
        // case 'P': buffer.showPointers(); break;
        // case 'S': buffer.showStacks(); break;
        // case 'T': buffer.showArray(); break;

        default: cout << "Illegal command" << endl; break;
    }
}

/**
 * Function: displayBuffer
 * Usage: displayBuffer(buffer);
 * -----------------------------
 * Displays the state of the buffer including position of the cursor.
 */
void displayBuffer(EditorBuffer & buffer) {
    string str = buffer.getText();
    for (int i = 0; i < str.length(); i++) {
        cout << " " << str[i];
    }
    cout << endl;
    cout << string(2 * buffer.getCursor(), ' ') << "^" << endl;
}   


/**
 * Function: printHelpText
 * Usage: printHelpText();
 * -----------------------
 * Displays a message showing the legal commands.
 */

void printHelpText() {
    cout << "Editor commands:" << endl;
    cout << "  Iabc    Inserts the characters abc at the cursor position" << endl;
    cout << "  F       Moves the cursor forward one character" << endl;
    cout << "  B       Moves the cursor backward one character" << endl;
    cout << "  D       Deletes the character after the cursor" << endl;
    cout << "  J       Jumps to the beggining of the buffer" << endl;
    cout << "  E       Jumps to the end of the buffer" << endl;
    cout << "  H       Prints this message" << endl;
    cout << "  Q       Exits from the editor program" << endl;
}


void getCommand(string & number, string & command, string line) {
    // string num;
    for (char c : line) {
        if (isdigit(c))
            number += c;
        else
            command += c;
    }
    // if (!num.empty())
        // number = stoi(num); 
}