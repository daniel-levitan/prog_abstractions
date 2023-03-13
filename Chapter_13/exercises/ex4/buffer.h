/**
 * File: buffer.h
 * --------------
 * The file defines the interface for the EditorBuffer class.
 */

#ifndef _buffer_h
#define _buffer_h


/** Class: EditorBuffer
 *  -------------------
 * This class represents an editor buffer, which maintains and ordered 
 * sequence of characters along with an insertion point called the cursor.
 */

class EditorBuffer {

public:
	/**
	 * Constructor: EditorBuffer
	 * Usage:       EditorBuffer buffer;
	 * ---------------------------------
	 * Creates an empty editor buffer.
	 */

	EditorBuffer();

	/**
	 * Destructor:  ~EditorBuffer
	 * Usage:       (implicit)
	 * ---------------------------------
	 * Frees any heap storage associated with this buffer.
	 */

	~EditorBuffer();	

	/**
	 * Methods: moveCursorForward
	 * 			moveCursorBackwards
	 * Usage:   buffer.moveCursorForward();
	 *          buffer.moveCursorBackwards();
	 * --------------------------------------
	 * These functions move the cursor forward or backward one character,
	 * respectively. If the command would shift the cursor beyond either
	 * end of the buffer, this method has no effect.
	 */

	void moveCursorForward();
	void moveCursorBackward();

	/**
	 * Methods: moveCursorToStart
	 * 			moveCursorToEnd
	 * Usage:   buffer.moveCursorToStart();
	 *          buffer.moveCursorToEnd();
	 * --------------------------------------
	 * These functions move the cursor to the start of to the end of this 
	 * buffer.
	 */

	void moveCursorToStart();
	void moveCursorToEnd();


	/**
	 * Method: insertCharacter
	 * Usage:  buffer.insertCharacter(char ch);
	 * ----------------------------------------
	 * Inserts the character ch into this buffer at the cursor point,
	 * leaving the cursor after the inserted character.
	 */

	void insertCharacter(char ch);

	/**
	 * Method: deleteCharacter
	 * Usage:  buffer.deleteCharacter();
	 * ----------------------------------------
	 * Deletes the character right after the cursor, if any.
	 */

	void deleteCharacter();


	/** 
	 * Method: getText
	 * Usage: std::string str = buffer.getText();
	 * ------------------------------------------
	 * Returns the content of the buffer as a string.
	 */ 

	std::string getText() const;

	/**
	 * Method: getCursor
	 * Usage: int cursor = getCursor();
	 * --------------------------------
	 * Returns the index of the cursor.
	 */

	int getCursor() const;

	/* Funcoes auxiliares para teste, devem ser apagadas */
	int getAfter() const;
	void showPointers() const;
	void showStacks() const;
	void showArray() const;

private:
	/** 
	 * This implementation relies on array. It mimicks the stack
	 * by filling up the array from both ends.
	 */

	/* Constants */
	static const int INITIAL_CAPACITY = 4;

	/* Instance variables */

	char *array;     /* Dynamic array of characters */
	int capacity;    /* Allocated size of the array */
	int used;      /* Number of characters in buffer */
	int cursor;      /* Index of character after cursos */
	int after;

	/* Make it illegal to copy buffers */
	EditorBuffer(const EditorBuffer * value) {}
	const EditorBuffer & operator=(const EditorBuffer * rhs) {return *this;}

	/* Private Methods */
	void expandCapacity();
};

#endif