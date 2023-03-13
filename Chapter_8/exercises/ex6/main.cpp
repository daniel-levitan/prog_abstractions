/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "set.h"
using namespace std;


void printVector(Set<int> set);
Set<int> comb(Set<int> set);
bool isMeasurable(int target, Vector<int> & weights);


int main() {
    Set<int> set = {1, 5, 13};
    Vector<int> vec = {1, 5, 13};
    Set<int> result;

    result = comb(set);
    cout << result << endl;
    cout << result.size() << endl;
    cout << result.contains(18) << endl;

    cout << isMeasurable(9, vec) << endl;
    cout << isMeasurable(11, vec) << endl;
    return 0;
}


void printVector(Set<int> set) {
    for (int e : set)
        cout << e << endl;
}

Set<int> comb(Set<int> set) {
    Set<int> result;
    int s = 0;

    for (int e : set) {
        Set<int> rest = set - e;
        Set<int> inter = comb(rest);
        result += inter;

        for (int f: inter) {
            if ((e - f) > 0)
                result += e - f;
        }
        s += e;
    }
    result += s;
    return result;
}

bool isMeasurable(int target, Vector<int> & weights) {
    Set<int> result;
    for (int value : weights)
        result.add(value);

    if (comb(result).contains(target))
        return true;
    return false;
}
