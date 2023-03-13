/**
 * Array based implementation
 * 
 * 
 */

#include <string>
#include <iostream> /* delete, only for tests */
#include "buffer.h"

using namespace std; /* delete, only for tests */

EditorBuffer::EditorBuffer() {
	capacity = INITIAL_CAPACITY;
	array = new char[capacity];
	used = 0;
	cursor = 0;
	after = capacity - 1;
}

EditorBuffer::~EditorBuffer() {
	delete[] array;
}

void EditorBuffer::moveCursorForward() {
	if (cursor < used) {
		array[cursor] = array[after + 1];
		after++;
		cursor++;
	}
}

void EditorBuffer::moveCursorBackward() {
	if (cursor > 0) {
		array[after] = array[cursor - 1];
		after--;
		cursor--;
	}
}

void EditorBuffer::moveCursorToStart() {
	while (cursor > 0) {
		array[after] = array[cursor - 1];
		after--;
		cursor--;
	}	
}

void EditorBuffer::moveCursorToEnd() {
	// cursor = length;
	while (cursor < used) {
		array[cursor] = array[after + 1];
		after++;
		cursor++;
	}
}

std::string EditorBuffer::getText() const {
	string beforeStr = std::string(array, cursor);

	string afterStr;
	for(int i = after + 1; i < capacity; i++)
		afterStr += array[i]; 

	return beforeStr + afterStr;
}

int EditorBuffer::getCursor() const {
	return cursor;
}

void EditorBuffer::insertCharacter(char ch) {
	if (used == capacity) expandCapacity();
	array[cursor] = ch;
	used++;
	cursor++;
}

void EditorBuffer::deleteCharacter() {
	if (after < capacity - 1) {
		after++;
		used--;
	}

}

void EditorBuffer::expandCapacity() {
	// cout << "Expand " << capacity << endl;
	char *oldArray = array;
	int size = capacity - after;
	capacity *= 2;

	array = new char[capacity];
	for (int i = 0; i < cursor; i++)
		array[i] = oldArray[i];

	for (int i = capacity; i > capacity - size; i--)
		array[i] = oldArray[i - (capacity / 2)];		
	/* Tenho de preencher pelos dois lados */
	
	delete[] oldArray;

	after = capacity - size;
}


/* Funcoes auxiliares para teste, devem ser apagadas */
/* delete, only for tests */
int EditorBuffer::getAfter() const {
	return after;
}

void EditorBuffer::showPointers() const {
	cout << "Cursor   " << cursor << endl;
	cout << "After    " << after << endl;
	cout << "Capacity " << capacity << endl;
	cout << "Used     " << used << endl;
}

void EditorBuffer::showStacks() const {
	cout << "Before: " << string(array, cursor) << endl;

	string afterStr;
	for(int i = after + 1; i < capacity; i++)
		afterStr += array[i];
	cout << "After : " << afterStr << endl;
}

void EditorBuffer::showArray() const {
	for(int i = 0; i < capacity; i++)
		cout << i << " " <<  array[i] << endl;
}





