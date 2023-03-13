/**
 * Essa não é a resposta, esse algoritmo roda em NlogN
 * 
 * 
 */

#include <iostream>
#include <vector>
// #include <sort>
#include <iomanip>

using namespace std;
	
void printVector(vector<int> v) {
	for (int i : v) 
		cout << i << " ";
	cout << endl;
}

int findMajorityElement(vector<int> v) {
	vector<int> inter = v;
	sort(inter.begin(), inter.end()); // fazer isso eleva o algoritmo para NlogN
	int count = 0;
	int threshold = inter.size() / 2;

	int mode = inter[0];

	for (int e : inter) {
		if (count > threshold)
			return mode;
		if (e != mode) {
			mode = e;
			count = 0;
		}
		count++;
	}
	return -1;
}

int main() {

	vector<int> v = {2, 1, 1, 1, 1, 1, 1, 8, 2, 2, 0, 0, 1, 1, 2};
	int mode = findMajorityElement(v);
	cout << "Most frequent term: " << mode << endl;

	v = {2, 1, 1, 3, 1, 5, 1, 8, 2, 2, 0, 0, 1, 1, 2};
	mode = findMajorityElement(v);
	cout << "Most frequent term: " << mode << endl;	
	
	return 0;
}

// def findMajorityElement(lista: List[int]) -> int:
//     sortedList = sorted(lista)
//     count = 0
//     threshold = len(sortedList) / 2
//     print("threshold", threshold)
//     mode = sortedList[0]
//     for e in sortedList:
//         if (count > threshold):
//             return mode
//         if (e != mode):
//             mode = e
//             count = 0
//         count += 1
//     return -1