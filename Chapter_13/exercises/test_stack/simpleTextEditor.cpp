#include <iostream>
#include "buffer.h"

using namespace std;

void displayBuffer(EditorBuffer & buffer);

int main() {
	EditorBuffer buffer; 
	for (char ch = 'A'; ch <= 'Z'; ch++)
		buffer.insertCharacter(ch);

	displayBuffer(buffer);


	return 0;
}




void displayBuffer(EditorBuffer & buffer) {
    string str = buffer.getText();
    for (int i = 0; i < str.length(); i++) 
        cout << " " << str[i];
    cout << endl;
    // cout << string(2 * buffer.getCursor(), ' ') << "^" << endl;
}   
