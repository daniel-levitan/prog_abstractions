/**
 *  File: insertionSort.cpp
 * 
 * --------------------------
 * Implements the insertionSort algorithm.
 * 
 */

#include <iostream>
#include <vector>

using namespace std;

void swap(int &a, int &b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void printVector(vector<int> v) {
	for (int i : v) 
		cout << i << " ";
	cout << endl;
}

void insertionSort(vector<int> &vec) {
	for (int i = 1; i < vec.size(); i++) {
		if (vec[i] < vec[i - 1]) {
			int j = i - 1;
			while ((j >= 0) && (vec[i] < vec[j])) 
				j--;
			int tmp = vec[i];
			for (int k = i; k > j; k--) 
				vec[k] = vec[k - 1];
			vec[j + 1] = tmp;
		}
	}	
} 

int main() {
	vector<int> v = {56, 25, 37, 58, 95, 19, 73, 30};
	// vector<int> v = {1, 2, 4, 5, 3};
	insertionSort(v);
	printVector(v);
	return 0;
}


