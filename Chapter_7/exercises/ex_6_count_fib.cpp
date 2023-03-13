/**
 * File: ex_6_count_fib.cpp
 * ----------------------
 * Count Fibonacci calls
 * 
 * 
 */

int fib1(int n);
int fib2(int n, int t0, int t1);


#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 13;

int fib1(int n, int & count);
int fib2(int n, int t0, int t1, int & count);

int main() {
	int count_1;
	int count_2;

	cout << " n   fib1   fib2" << endl;
	cout << "---  ----   -----" << endl;
		
	for (int i = 0; i < MAX; i++) {
		count_1 = 0;
		count_2 = 0;
		fib1(i, count_1);
		fib2(i, 0, 1, count_2);

		cout << 
				setw(2) << right << i <<  
		        "  " << setw(4) << right << count_1 << 
		        "  " << setw(4) << right << count_2 << endl;
	}
	return 0;
}


int fib1(int n, int &count) {
	count++;
	if (n < 2) 
		return n;
	else 
		return fib1(n - 1, count) + fib1(n - 2, count); 
}

int fib2(int n, int t0, int t1, int &count) { 
	count++;
	if (n == 0) return t0;
	if (n == 1) return t1;
	return fib2(n - 1, t1, t0 + t1, count);
}
