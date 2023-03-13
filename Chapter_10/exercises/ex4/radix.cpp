/**
 *  File: radix.cpp
 * 
 * --------------------------
 * 
 * 
 */

#include <iostream>
#include <vector>
#include <tgmath.h>

using namespace std;

void printVector(vector<int> v) {
	for (int i : v) 
		cout << i << " ";
	cout << endl;
}

void radixSort(vector<int> &v) {
	vector<int> temp;
	// this can be determined by the biggest number 
	// in this case I've assumed the number is up to 3 digits
	int loops = 3; 
	int n = 1;

	while (n <= loops) {

		for (int i = 0; i <= 9; i++) {
			for (int e : v) {
				
				int num = e / (int) pow(10, n - 1);
				// int den = (int) pow(10, n);
				int den = 10;
				int val = num % den;

				if (val == i) {
					// cout << "e " << e << " "
					//  	 << "num " << num << " "
				 // 	 	 << "den " << den << " "
					//  	 << "val " << val << endl;
					// cout << "Add " << e << " " << endl;
					temp.push_back(e);
				}
			}
		}

		n++;
		// cout << endl;
		for (int i = 0; i < v.size(); i++)
			v[i] = temp[i];
		temp.clear();
		// cout << "v==== ";
		// printVector(v);
	}

}

int main() {
	vector<int> v = {170, 45, 75, 90, 802, 24, 2, 66};

	// vector<int> v = {12, 23, 104, 45, 75, 30, 2};
	radixSort(v);
	printVector(v);
	// int a = (003 / 100) % 100;
	// cout << a << endl;
	// int a = 003;
	// int n = 1;
	// int num = a / (int) pow(10, n - 1);
	// int den =  (int) pow(10, n);
	// cout << "num " << num << endl;
	// cout << "den " << den << endl;
	// cout <<  % << endl;
	// n = 2;
	// cout << (a / (int) pow(10, n - 2)) % (int) pow(10, n) << endl;
	// n = 3;
	// cout << (a / (int) pow(10, n - 3)) % (int) pow(10, n) << endl;


	return 0;
}