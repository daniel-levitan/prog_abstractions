#include <iostream>
#include <string>


using namespace std;

void generateBinaryCode(int nBits) {

	if (nBits == 1) {
		for (int i = 0; i < 2; i++)
			cout << i;
	} else {
		for (int i = 0; i < 2; i++){
			cout << i;
			generateBinaryCode(nBits - 1);
		}
	}
}

int main() {
	int bits = 2;
	generateBinaryCode(bits);
	return 0;
}
