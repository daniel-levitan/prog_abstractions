/**
 * File: ex_8_removeInPlace.cpp
 * -----------------------
 * 
 */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

void removeCharacter(string &str, char remove);
void removeCharacters(string &str, string remove);

int main() {
    string str = "counterrevolutionaries";
    string remove = "aeiou";
    // char remove = 'a';

    // cout << "counterrevolutionaries: " << removeCharacters(str, remove) << endl;
    removeCharacters(str, remove);
    cout << "counterrevolutionaries: " << str << endl;
    return 0;
}

void removeCharacters(string &str, string remove) {
    for (int i = 0; i < remove.length(); i++) 
        removeCharacter(str, remove[i]);
}

void removeCharacter(string &str, char remove) {
    int end = str.length();
    int count = 0;
    while (count < end) {
        if (str[count] == remove)
            str.erase(count, 1);
        else 
            count++;
    }
}
