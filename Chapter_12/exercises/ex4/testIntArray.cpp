#include <iostream>
#include "intArray.h"

using namespace std;

int main() {
	IntArray myArr(10);

	cout << "Size " << myArr.size() << endl;
	myArr.put(0, 10);
	myArr.put(1, 10);
	myArr.put(2, 13);
	myArr.put(4, 111);
	cout << "Size " << myArr.size() << endl;

	cout << "El 0 " << myArr.get(0) << endl;
	cout << "El 1 " << myArr.get(1) << endl;
	cout << "El 2 " << myArr.get(2) << endl;
	cout << "El 3 " << myArr.get(3) << endl;
	cout << "El 4 " << myArr.get(4) << endl;

	return 0; 
}