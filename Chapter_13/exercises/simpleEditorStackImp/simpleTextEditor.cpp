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

void executeCommand(EditorBuffer & buffer, string line);
void displayBuffer(EditorBuffer & buffer);
void printHelpText();

int main() {
    EditorBuffer buffer;
    // string line = "This is my line test";
    // for (int i = 0; i < line.length(); i++) buffer.insertCharacter(line[i]);
    
    // string str = buffer.getText();
    // cout << str << endl;
    
    // // line = "Yet more text";
    // // for (int i = 0; i < line.length(); i++) buffer.insertCharacter(line[i]);
    // // cout << str << endl;

    // // displayBuffer(buffer);

    while (true) {
        string cmd = getLine("*");
        if (cmd != "") executeCommand(buffer, cmd);
    }
    return 0;
}

/**
 * Function: executeCommand 
 * Usage: executeCommand(buffer, line);
 * ------------------------------------
 * Executes the command specified by line on the editor buffer.
 */
void executeCommand(EditorBuffer & buffer, string line) {
    switch(toupper(line[0])) {
        case 'I': for (int i = 1; i < line.length(); i++) 
                        buffer.insertCharacter(line[i]);
                  displayBuffer(buffer);
                  break;
        case 'D': buffer.deleteCharacter(); displayBuffer(buffer); break;
        case 'F': buffer.moveCursorForward(); displayBuffer(buffer); break;
        case 'B': buffer.moveCursorBackward(); displayBuffer(buffer); break;
        case 'J': buffer.moveCursorToStart(); displayBuffer(buffer); break;
        case 'E': buffer.moveCursorToEnd(); displayBuffer(buffer); break;
        case 'H': printHelpText(); displayBuffer(buffer); break;
        case 'Q': exit(0);
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
    for (int i = 0; i < str.length(); i++) 
        cout << " " << str[i];
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
