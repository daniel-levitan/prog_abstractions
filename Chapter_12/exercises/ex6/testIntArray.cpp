#include <iostream>
#include "intArray.h"

using namespace std;

int main() {
	int size = 10;
	IntArray source(10);
	
	for (int i = 0; i < size; i++)
		source.put(i, i);
	
	cout << "Source      ";
	source.print();
	cout << "Source size " << source.size() << endl;

	// As duas linhas abaixo funcionam. O que não posso fazer é
	// IntArray fresh(10); e depois chamar fresh = source; Isso não funciona.
	// IntArray fresh = source;
	IntArray fresh(source);
	cout << "Fresh size " << fresh.size() << endl;
	cout << "Fresh      ";
	fresh.print();	
	
	return 0; 
}