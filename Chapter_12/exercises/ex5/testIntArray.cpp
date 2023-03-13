#include <iostream>
#include "intArray.h"

using namespace std;

int main() {
	IntArray myArr(10);
	cout << "Size " << myArr.size() << endl;
	myArr.put(0, 10);
	myArr.put(1, 10);
	myArr.put(2, 13);
	myArr.put(4, 122);
	cout << "Size " << myArr.size() << endl;
	cout << "El0 " << myArr.get(0) << endl;
	myArr[0] = 2;
	cout << "El0 " << myArr.get(0) << endl;
	cout << "El0 " << myArr[0] << endl;
	// myArr.print();
	
	// int a = *(myArr[0]); 

	
	
	return 0; 
}