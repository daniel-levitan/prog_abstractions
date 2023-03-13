/**
 *  File: clockTime.cpp
 * 
 * --------------------------
 * 
 * 
 */

#include <iostream>
#include <ctime>
#include <vector>
#include <iomanip>
#include "random.h"

using namespace std;

const int NUMBER_OF_TIMES = 1000;
// const int SIZE = 10;

void swap(int &a, int &b) {
	int tmp;
	tmp = a;
	a = b;
	b = tmp;
}

void regularSort(vector<int> &vec) {
	for (int i = 0; i < vec.size(); i++) {
		for (int j = i; j < vec.size(); j++) {
			if (vec[j] < vec[i])
				swap(vec[j], vec[i]);	
		}	
	}
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
	// vector<int> v = {56, 25, 37, 58, 95, 19, 73, 30, 12, 33};
	vector<int> v;
	// vector<int> vec_of_sizes = {10, 50, 100, 500};
	vector<int> vec_of_sizes = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000};
	double start, finish, elapsed;
	
	cout << setw(12) << "N" << " | "  <<  " Time (msec)" << endl;
	for (int s: vec_of_sizes) {
		for (int i = 0; i < s; i++)
			v.push_back(randomInteger(0, 100));
		start = double(clock()) / CLOCKS_PER_SEC;
		for (int i = 0; i < NUMBER_OF_TIMES; i++)
			insertionSort(v);	
		finish = double(clock()) / CLOCKS_PER_SEC;
		elapsed = finish - start;
		elapsed /= NUMBER_OF_TIMES;
		cout << setw(12) << s <<  " |  " << fixed << elapsed << endl;
	}
	
	
	
	
	

	// for (int i : v) 
	// 	cout << i << " ";
	// cout << endl;

	return 0;
}


