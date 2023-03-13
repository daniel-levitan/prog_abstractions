/*
 * File: ex_11_din_alloc.cpp
 * ------------------------------------
 * This program solves exercise #11.
 * 
 * Write a function IndexArray(n) that returns a pointer to a dynamically allocated 
 * integer array with n elements, each of which is initialized to its own index.
 * 
 * 
 */

#include <iostream>

using namespace std;

int *indexArray(int n);
void fillArray(int *array, int n);
void printArray(int *array, int n);

int main() {
	int *ip;
	int size = 5;

	ip = indexArray(size);
	fillArray(ip, size);
	printArray(ip, size);

	delete ip;
	return 0;
}

int *indexArray(int n) {
	int *ptr = new int[n];
	return ptr;
}

void fillArray(int *array, int n) {
	for (int i = 0; i < n; i++)
		array[i] = i;
}

void printArray(int *array, int n) {
	for (int i = 0; i < n; i++)
		cout << array[i] << " ";
	cout << endl;	
} 