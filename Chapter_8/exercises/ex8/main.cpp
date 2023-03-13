#include <iostream>
#include <string>
#include "console.h"
#include "set.h"

using namespace std;

Set<string> permutations(string &str);

int main() {
    string str = "abc";
    cout << "Results:" << endl;
    for (string s: permutations(str))
        cout << s << endl;
    return 0;
}

/**
 * The recursive decomposition presented in section 8-3 to solve the problem of
 * generating permutations is not the only effective strategy. Another way to
 * look at the problem is to solve the recursive case looks like this:
 *
 * a) Remove the first character from the string and store it in the variable ch.
 *
 * b) Generate the set containing all permutations of the remaining characters.
 *
 * c) Form a new set by inserting ch in every possible position in each
 *  of those permutations.
 */
Set<string> permutations(string &str) {
    Set<string> result;
    if (str == "")
        result += "";
    else {
        char ch = str[0];
        string newStr = str.substr(1);
        for (int i = 0; i < newStr.length(); i++) {
            char c = str[i];
            string rest = newStr.substr(0, i) + newStr.substr(i);
            for (string s : permutations(rest)) {
                string inter;
                inter = ch;
                inter += c + s;
                result += inter;
            }
        }
    }
    return result;


    // if (index == str.length()) {
    // 	cout << str << endl;
    // } else {
    // 	for (int i = index + 1; i < str.length(); i++) {
    // 		char tmp = str[index];
    // 		str[index] = str[i];
    // 		str[i] = tmp;

    // 		permutations(str, index + 1);
    // 		cout << str << endl;

    // 		str[i] = str[index];
    // 		str[index] = tmp;
    // 		permutations(str, index + 1);
    // 	}
    // }
}


