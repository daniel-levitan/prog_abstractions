/**
 * File: main.cpp
 * --------------
 * SubsetSumWays should return the number of possible ways in which the target
 * can be achieved.
 */

#include <iostream>
#include "console.h"
#include "set.h"
using namespace std;

void printSet(Set<int> &set);
bool subsetSumExists(Set<int> & set, int target, int &count);
int subsetSumWays(Set<int> & set, int target);
int countSubsetSumWays(Set<int> & set, int target);

int main() {
    Set<int> set = { 1, 2, 3 };
//    int ways = subsetSumWays(set, 3);
//    cout << "Ways: " << ways << endl;
    cout << countSubsetSumWays(set, 3) << endl;
    return 0;
}

int subsetSumWays(Set<int> & set, int target) {
    int count = 0;
    subsetSumExists(set, target, count);
    return count;
}

bool subsetSumExists(Set<int> & set, int target, int &count) {
    cout << "Target: " << target << " | ";
    cout << "Subset: ";
    printSet(set);
    cout << endl;
//    cout << endl;
    if (set.isEmpty()) {
        cout << "Found: " << (target == 0) << endl << endl;
        if (target == 0) count++;
        return target == 0;
    } else {
     int element = set.first();
     cout << "El: " << element << endl;
     cout << endl;
     Set<int> rest = set - element;
     return subsetSumExists(rest, target, count)
         || subsetSumExists(rest, target - element, count);
    }
}

int countSubsetSumWays(Set<int> & set, int target) {
    cout << "Target: " << target << " | ";
    cout << "Subset: ";
    printSet(set);
    cout << endl;

    if (set.isEmpty()) {
        cout << "Found: " << (target == 0) << endl << endl;
        return (target == 0) ? 1 : 0;
    } else {
        int element = set.first();
        cout << "Element: " << element << endl;
        cout << endl;
        Set<int> rest = set - element;
        return countSubsetSumWays(rest, target) +
               countSubsetSumWays(rest, target - element);
    }
}

void printSet(Set<int> &set) {
    cout << "(";
    for (int i : set) {
        if (i != set.first()) cout << ", ";
        cout << i;
    }
    cout << ")";
}
