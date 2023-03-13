/**
 * File: ex_10_replaceAll.cpp
 * --------------------------
 * 
 */


#include <iostream>
#include <string>
#include "../../libraries/error.h"

using namespace std;

string replaceAll(string str, char c1, char c2);
string replaceAll(string str, string s1, string s2);
bool compare(string str1, string str2);
string substr(string str, int pos, int n);


int main() {
    cout << replaceAll("nannies", 'n', 'd') << endl;
    cout << replaceAll("nannies", "n", "d") << endl;
    string testStr = "abcdefabcdefabcdef";
    cout << "ORIGINAL: " << testStr << endl;
    string newString = replaceAll(testStr, "cd", "12");
    cout << "RESULT  : " << newString << endl;
    return 0;
}

string replaceAll(string str, char c1, char c2) {
    string st = str;
    for (int i = 0; i < st.length(); i++)
        if (st[i] == c1) 
            st[i] = c2;
    return st;
}

string replaceAll(string str, string s1, string s2) {
    string line;
    string result = str;
    string strToCompare;
    // for (int i = 0; i < str.length() - s1.length() + 1; i++) {
    int i = 0;
    while (i < result.length() - s1.length() + 1) {
        strToCompare = substr(result, i, s1.length());
        if (compare(strToCompare, s1)) {
            int j = 0;
            while (j < s2.length()) {
                result[i + j] = s2[j];
                j++;
            }
            i += j;
        } else 
            i++;
    }
    return result;
}

bool compare(string str1, string str2) {
    int size = str2.length();
    for (int i = 0; i < size; i++)
        if (str1[i] != str2[i])
            return false;
    return true;
}

string substr(string str, int pos, int n) {
    if (pos > str.length()) 
        error("Out of bound");
    if (n > str.length())
        n = str.length();

    string newString = "";
    for (int i = pos; i < pos + n; i++) 
        newString += str[i];
    return newString; 
}






