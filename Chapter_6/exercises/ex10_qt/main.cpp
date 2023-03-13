#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "tokenscanner.h"
#include "console.h"
#include "lexicon.h"

using namespace std;

int main() {
    ifstream infile;
    TokenScanner myScanner = TokenScanner();
    Lexicon lex("words.txt");

    myScanner.ignoreWhitespace();

    infile.open("input.txt");
    if (infile.fail()) {
        cout << "Input file error " << endl;
        return -1;
    }


    while (true) {
        string line, word;
        getline(infile, line);
        if (infile.fail()) break;
        myScanner.setInput(line);
        while ( (word = myScanner.nextToken()) != "") {
            if (!lex.contains(word))
                cout << word << " is not in the dictionary." << endl;
        }

    }

    infile.close();
    return 0;
}
