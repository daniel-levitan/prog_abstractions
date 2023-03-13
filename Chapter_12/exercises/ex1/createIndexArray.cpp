#include <iostream>

using namespace std;

int* createIndexArray(int n);

int main() {
	int *start;
	int size = 3;
	start = createIndexArray(size);

	for (int i = 0; i < size; i++) {
		cout << start[i] << " ";
	}
	cout << endl;
	return 0;
}

int* createIndexArray(int n) {
	int *start;
	start = new int[n];
	for (int i = 0; i < n; i++)
		start[i] = i;
	return start;
}