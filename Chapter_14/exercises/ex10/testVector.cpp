#include <iostream>
#include "vector.h"
using namespace std;

const int VECTOR_SIZE = 2;

// void printVector(Vector<int> vec, int vec_size) {
// 	for (int i = 0; i < vec_size; i++)
// 		cout << vec.get(i) << " ";
// 	cout << endl;
// }

int main() {
	Vector<string> vec;
	vec.add("K");
	cout << vec.get(0) << endl;

	// Vector<int> *vtr = new Vector<int>;
	// vtr->add(0);

	// Vector< Vector<int> * > vtr;
	// vtr = new Vector< Vector <int *> >;
	// vtr.add(new Vector<int>(2, 0));
	// Vector<int> *v1 = new Vector<int>(2, 0); 
	// v1.add(1);
	// v1.add(2);

	// vtr.add(&v1);

	// cout << (vtr.get(0))->get(0) << endl;
	// cout << (vtr.get(0))->get(1) << endl;

	// printVector(*v1, v1->size());

	// vtr.add(v1);
	
	// vtr.add()





	// (vtr.get(0)).set(0, 1);
	// cout << (vtr.get(0)).get(0) << endl;

	// Vector< Vector<int> > vtr(2, Vector<int>(2));
	// Vector<int> v1, v2;
	// v1.add(27); v1.add(19);
	// v2.add(35); v2.add(12);

	// printVector(v1, VECTOR_SIZE);

	// Vector< Vector<int> > vtr;
	// vtr.add(v1);
	// vtr.add(v2);

	// cout << vtr.size() << endl;

	// for (int i = 0; i < vtr.size(); i++) 
		// printVector(vtr.get(i), VECTOR_SIZE);


	// vtr.add(v1);
	// vtr[0].set(0, 1);
	// vtr[0].get(0);
	// (vtr.get(0)).set(0, 2);

	// (vtr.get(0)).get(0);

	// Vector<int> vtr;


	// for (int i = 0; i < VECTOR_SIZE; i++)
	// 	vtr.add(i);

	// for (int i = 0; i < VECTOR_SIZE; i++)
	// 	cout << vtr[i] << " ";
	// 	// cout << vtr.get(i) << " ";
	// cout << endl;
	
	// // vtr.insert(0, 8);		
	// // vtr.insert(1, 9);
	// // vtr.insert(2, 7);
	// vtr.remove(1);

	// for (int i = 0; i < vtr.size(); i++)
	// 	cout << vtr[i] << " ";
	// 	// cout << vtr.get(i) << " ";
	// cout << endl;

	// vtr.set(1, 11);
	// vtr.set(2, 22);

	// for (int i = 0; i < VECTOR_SIZE; i++)
		// cout << vtr.get(i) << " ";
	// cout << endl;

	// vtr.set(3, 33);
	// cout << "El 3: " << vtr.get(3) << endl;

	// Vector<int> vtr2 = vtr;
	// for (int i = 0; i < vtr2.size(); i++)
	// cout << endl;

	return 0;
}