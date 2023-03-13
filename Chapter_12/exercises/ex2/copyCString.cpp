#include <iostream>

using namespace std;

int getSize(char *str);
char *copyCString(char *str);

int main() {
	char *copied;
	char original[] = "Test string";
	copied = copyCString(original);

	cout << original << endl;
	cout << copied << endl;

	return 0;
}

int getSize(char *str) {
	int i = 0;
	while (str[i] != '\0') 
		i++;
	return i;
}

char *copyCString(char *str) {
	int size = getSize(str);
	char *newString = new char[size + 1];
	for (int i = 0; i < size; i ++)
		newString[i] = str[i];
	newString[size] = '\0';

	return str;
}

// void strcpy(char *dst, char *src) {
//           while (*dst++ = *src++);
// }