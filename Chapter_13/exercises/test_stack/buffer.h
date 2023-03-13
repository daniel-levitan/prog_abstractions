#ifndef _buffer_h
#define _buffer_h

#include "charstack.h"

class EditorBuffer {

public:
	EditorBuffer();

	void insertCharacter(char ch);

	std::string getText() const;

private:
	CharStack before;
	CharStack after;

	/* Make it illegal to copy buffers */
	EditorBuffer(const EditorBuffer * value) {}
	const EditorBuffer & operator=(const EditorBuffer * rhs) {return *this;}

	EditorBuffer deepCopy(const EditorBuffer & src);
};


#endif