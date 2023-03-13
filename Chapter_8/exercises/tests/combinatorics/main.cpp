/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include <string>
#include "console.h"
#include "set.h"
using namespace std;


void printVector(Set<string> set) {
    for (string e : set)
        cout << e << endl;
}

//def comb(string: str, combinations: set):
//    if string:
//        combinations.add(string)
//        for i, l in enumerate(string):
//            comb(string[:i] + string[i + 1:], combinations)
//        return combinations

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
    Set<string> set = {"a", "b", "c"};
    Set<string> result;

    result = combStrings(set);


    cout << result << endl;
    cout << result.size() << endl;
    return 0;
}
