/**
 * File: ex_8_digital_root.cpp
 * -------------------------
 */

#include <iostream>

using namespace std;

int sumDigits(int n);
int digitalRoot(int n);

int main() {
    cout << digitalRoot(123456789) << endl;
    return 0;
}

int sumDigits(int n) {
    if (n < 10)
        return n;
    else
        return (n % 10) + sumDigits(n / 10);
}

int digitalRoot(int n) {
    int sum = sumDigits(n);
    if (sum < 10)
        return sum;
    else
        return digitalRoot(sum);

}

