/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

// The checking in Lexicon is missing

#include <string>
#include "console.h"
#include "set.h"
using namespace std;

void printVector(Set<string> set) {
    for (string e : set)
        cout << e << endl;
}

Set<string> combStrings(Set<string> set) {
    Set<string> result;

    if (set.isEmpty()) {
        result.add("");
    }
    else {
        string s = "";
        for (string e : set) s += e;
        result.add(s);

        for (string e : set) {
            Set<string> rest = set - e;
            result += combStrings(rest);
        }
    }
    return result;
}

int main()
{
//    Set<string> set = {"a", "b", "c", "d"};
    Set<string> set = {"H", "a", "p", "p", "y"};
    Set<string> result;

    result = combStrings(set);


    cout << result << endl;
    cout << result.size() << endl;
    return 0;
}
