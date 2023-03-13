/**
 * File: ex_7_remove.cpp
 * -----------------------
 * 
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string removeCharacter(string str, char remove);
string removeCharacters(string str, string remove);

int main() {
    string str = "counterrevolutionaries";
    string remove = "aeiou";

    cout << "counterrevolutionaries: " << removeCharacters(str, remove) << endl;
    return 0;
}

string removeCharacters(string str, string remove) {
    string result = str;

    for (int i = 0; i < remove.length(); i++) 
        result = removeCharacter(result, remove[i]);
    return result;
}

string removeCharacter(string str, char remove) {
    string st = str;
    int end = str.length();

    int count = 0;
    while (count < end) {
        if (st[count] == remove) {
            st.erase(count, 1);
        } else {
            count++;
        }
    }
    return st;
}
