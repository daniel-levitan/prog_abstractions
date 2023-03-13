/**
* File: mnemonic.cpp
* ----------------------
* This file list all mnemonics of a telephone number.
*/

//#include <iostream>
#include <string>
#include "console.h"
#include "set.h"

using namespace std;

string getLetters(char ch);

//Set<string> generatePermutations(string str) {
//    Set<string> result;
//    if (str == "")
//        result += "";
//    else {
//        for (int i = 0; i < str.length(); i++) {
//            string rest = str.substr(0, i) + str.substr(i+ 1);
//            for (string s: generatePermutations(rest))
//               result += str[i] + s;
//        }
//    }
//    return result;
//}

Set<string> generatePermutations(string str) {
    Set<string> result;
    string res;
    if (str == "")
        result += "";
    else {
        for (char ch : getLetters(str[0])){
            string rest = str.substr(1);
            for (string s: generatePermutations(rest))
               result += ch + s;
        }
    }
    return result;
}

int main() {
    string str = "723";

    Set<string> set = generatePermutations(str);

    for (string element : set)
        cout << element << endl;

    return 0;
}

string getLetters(char ch) {
    switch (ch) {
        case '0': return "ab"; //testing only
        case '1': return "cd"; //testing only
        case '2': return "ABC";
        case '3': return "DEF";
        case '4': return "GHI";
        case '5': return "JKL";
        case '6': return "MNO";
        case '7': return "PQRS";
        case '8': return "TUV";
        case '9': return "WXYZ";
        default: return "";
    }
}





