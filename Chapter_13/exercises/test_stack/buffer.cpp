#include <iostream>
#include "buffer.h"

using namespace std;

EditorBuffer::EditorBuffer() { };

void EditorBuffer::insertCharacter(char ch) {
	before.push(ch);
}


std::string EditorBuffer::getText() const {
	// CharStack beforeCopy = before;




	std::string str = "";

	// while (!beforeCopy.isEmpty()) {
	// 	str = beforeCopy.pop() + str;
	// }

	// while (!afterCopy.isEmpty()) {
	// 	str += afterCopy.pop();
	// }
	str = "return";
	return str;
}


EditorBuffer EditorBuffer::deepCopy(const EditorBuffer & src) {
	tempCharStack = new CharStack;
	
}