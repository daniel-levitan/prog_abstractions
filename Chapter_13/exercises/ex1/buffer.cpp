/**
 * Array based implementation
 * 
 * 
 */

#include <string>
// #include <iostream>
#include "buffer.h"

EditorBuffer::EditorBuffer() {
	capacity = INITIAL_CAPACITY;
	array = new char[capacity];
	length = 0;
	cursor = 0;
}

EditorBuffer::~EditorBuffer() {
	delete[] array;
}

void EditorBuffer::moveCursorForward() {
	if (cursor < length) cursor++;
}

void EditorBuffer::moveCursorBackward() {
	if (cursor > 0) cursor--;
}

void EditorBuffer::moveCursorToStart() {
	cursor = 0;
}

void EditorBuffer::moveCursorToEnd() {
	cursor = length;
}



std::string EditorBuffer::getText() const {
	// return "string";
	return std::string(array, length);
	// return std::string(array);
}

int EditorBuffer::getCursor() const {
	return cursor;
}

void EditorBuffer::insertCharacter(char ch) {
	if (length == capacity) expandCapacity();
	for (int i = length;  i > cursor ; i--) {
		array[i] = array[i - 1];
	}
	array[cursor] = ch;
	length++;
	cursor++;
}

void EditorBuffer::deleteCharacter() {
	if (cursor < length) {
		for (int i = cursor + 1; i < length; i++)
			array[i - 1] = array[i];
		length--;
	}
}

void EditorBuffer::expandCapacity() {
	char *oldArray = array;
	capacity *= 2;
	array = new char[capacity];
	for (int i = 0; i < length; i++)
		array[i] = oldArray[i];
	delete[] oldArray;

}
