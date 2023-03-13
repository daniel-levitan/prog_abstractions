/*
 * File: main.cpp
 * --------------
 * Blank C++ project configured to use Stanford cslib and Qt
 */

#include "console.h"
#include "stack.h"

using namespace std;

void moveTower(int n, Stack<int> &start, Stack<int> &finish, Stack<int> &tmp, int &count);

int main()
{
    int count = 0;

    Stack<int> a = {1, 2, 3, 4, 5, 6, 7, 8};
    Stack<int> b, c;

    cout << "Finish: "<< b << endl;
    cout << "Start: "<< a << endl;

    moveTower(a.size(), a, b, c, count);
    cout << "Finish: "<< b << endl;
    cout << "Start: "<< a << endl;
    cout << "Count: " << count << endl;
    return 0;
}

void moveTower(int n, Stack<int> &start, Stack<int> &finish, Stack<int> &tmp, int &count) {
    count++;
    int disk;
    if (n == 1) {
        disk = start.pop();
        finish.push(disk);
    } else {
        moveTower(n - 1, start, tmp, finish, count);
        disk = start.pop();
        finish.push(disk);
        moveTower(n - 1, tmp, finish, start, count);
    }
}
