/**
 * File: charstack.h
 * -----------------
 * This interface defines the CharStack class, which implements the stack
 * abstraction for characters.
 */

#ifndef _charstack_h
#define _charstack_h

/**
 * Class: CharStack
 * ----------------
 * This class implements a stack of characters.
 */

class CharStack {

public:
	/**
	 * Constructor: CharStack
	 * Usage:       CharStack cstk;
	 * ----------------------------
	 * Initilizes a new empty stack that can contain characters.
	 */

	CharStack();

	/**
	 * Desstructor: ~CharStack
	 * Usage:       (implicit)
	 * -----------------------
	 * Frees any heap storage associated with this character stack.
	 */

	~CharStack();

	/**
	 * Method: size
	 * Usage: int nElems = cstk.size();
	 * --------------------------------
	 * Returns the number of characters in this stack.
	 */

	int size() const;

	/**
	 * Method: isEmpty
	 * Usage: if (cst.isEmpty()) ...
	 * -----------------------------
	 * Returns true if this stack contains no characters.
	 */
	
	bool isEmpty() const;

	/**
	 * Method: clear
	 * Usage: cstk.clear();
	 * --------------------
	 * Removes all characters from this stack.
	 */
	
	void clear();

	/**
	 * Method: push
	 * Usage: cstk.push(ch);
	 * ---------------------
	 * Pushes the character ch onto this stack.
	 */
	void push(char ch);

	/**
	 * Method: pop
	 * Usage: char ch = cstk.pop(ch);
	 * ------------------------------
	 * Removes the top character from this stack and returns it.
	 */

	char pop();

	/**
	 * Method: peek
	 * Usage: char ch = cstk.peek();
	 * -----------------------------
	 * Returns the value of the top character from this stack without
	 * removing it. Raises an error if called on an empty stack.
	 */

	char peek() const;


	// private section => ADD IT LATER
private:
	static const int INITIAL_CAPACITY = 10;

	char *array;     /* Dynamic array of characters */
	int capacity;    /* Allocated size of the array */
	int count;      /* Number of characters in buffer */

	/* Private Methods */
	void deepCopy(const CharStack & src);
	void expandCapacity();

};



#endif