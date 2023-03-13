/**
 * This is an implementation using a dynamic array. It is not what I had
 * used so far. I will rewrite the methods and will need to test it.
 * 
 * 
 * 
 */

#ifndef _vector_h
#define _vector_h

#include "../../../libraries/error.h"


template <typename ValueType>
class Vector {

public:
	
	/**
	 * Constructor: Vector
	 * Usage: Vector<ValueType> vtr;
	 * --------------------------------
	 * Initializes a new empty vector.
	 */
	Vector();
	Vector(int n, ValueType value = ValueType());
	// ATENCAO! Olha isso aqui ValueType() !!!

	/**
	 * Destructor: ~Vector
	 * Usage: (implicit)
	 * --------------------------------
	 * Frees any heap storage associated with this vector
	 */
	~Vector();

	/**
	 * Method: size
	 * Usage: int n = vtr.size();
	 * -----------------------------
	 * Returns the number of elements in this vector.
	 */
	int size() const;

	/**
	 * Method: isEmpty
	 * Usage: if (vtr.isEmpty)
	 * --------------------------
	 * Returns true if the vector contains no elements.
	 */
	bool isEmpty() const;

	/**
	 * Method: clear
	 * Usage: vtr.clear();
	 * ----------------------
	 * Removes all elements from this vector/
	 */
	void clear();

	/** 
	 * Method: get
	 * Usage: ValueType value = vtr.get(index);
	 * ----------------------------------------
	 * Returns the element at the specified index in this vector. This method
	 * signals an error if the index is not in the array range.
	 */
	ValueType get(int index) const;
	// ValueType get(int index);

	/**
	 * Method: set
	 * Usage: vtr.set(index, value);
	 * -----------------------------
	 * Replaces the element at the specified index in this vetor with a new
	 * value. The previous value at that index is overwritten. This method
	 * signals an error if the index is not in the array range.
	 */
	void set(int index, ValueType value);

	/**
	 * Method: insert
	 * Usage: vtr.insert(0, value);
	 * -----------------------------
	 * Inserts the element into this vector before the speficied index. All
	 * subsequenmt elements are shifted on position to the right. This method 
	 * signals an error if the index is outside the range from 0 up to and
	 * including the length of the vector.
	 */ 
	void insert(int index, ValueType value);

	/**
	 * Method: remove
	 * Usage: vtr.remove(index);
	 * -------------------------
	 * Removes the element at the specified index from this vector. All
	 * subsequent elements are shifted one position to the left. This method
	 * signals an error if the index is outside the array range.
	 */
	void remove(int index);

	/**
	 * Method: add
	 * Usage: vtr.add(value);
	 * ----------------------
	 * Adds a new value to the end of this vector.
	 */
	void add(ValueType value);

	/**
	 * Operator: []
	 * Usage: vtr[index]
	 * -----------------
	 * Overloads [] to select elements from this vector. This extension
	 * enables the use of traditional array notation to get or set individual
	 * elements. This method signals an error if the index is outside the
	 * array range.
	 */
	ValueType & operator[](int index);

	/**
	 * Copy constructor and assignment operator
	 * ----------------------------------------
	 * These methods implement deep copying for vectors
	 */ 
	Vector(const Vector<ValueType> & src);
	Vector<ValueType> & operator=(const Vector<ValueType> & src);

/**
 * Notes on the representation
 * ---------------------------
 * This version of the vector.h interface stores the elements in a 
 * dynamic array of the speficied element type. If the space in the
 * array is ever exhausted, the implementation doubles the array capacity.
 */

private:

	static const int INITIAL_CAPACITY = 10;

	/* Instance variables */

	ValueType *array;  /* A dynamic array of the elements */
	int capacity;      /* The allocated size of the array */
	int count;         /* The number of elements in use */ 

	/* Private method prototypes */

	void deepCopy(const Vector<ValueType> & src);
	void expandCapacity();
};



/**
 * Implementation notes: Vector constructor and desctructor
 * --------------------------------------------------------
 * The two implementations of the constructor each allocated storage for
 * the dynamic array and then initialize the other fields of the object.
 * The destructor frees the heap memory used by the dynamic array.
 */

template <typename ValueType>
Vector<ValueType>::Vector() {
	capacity = INITIAL_CAPACITY;
	count = 0;
	array = new ValueType[capacity];
}

template <typename ValueType>
Vector<ValueType>::Vector(int n, ValueType value) {
	capacity = (n > INITIAL_CAPACITY) ? n : INITIAL_CAPACITY;
	array = new ValueType[capacity];
	count = n;
	for (int i = 0; i < n; i++) {
		array[i] = value;
	}
}

template <typename ValueType>
Vector<ValueType>::~Vector() {
	delete[] array;
}

/**
 * Impplementation notes: size, isEmpty, clear
 * -------------------------------------------
 * These methods require only the count field and do not look at the data.
 */

template <typename ValueType>
int Vector<ValueType>::size() const {
	return count;
}

template <typename ValueType>
bool Vector<ValueType>::isEmpty() const {
	return count == 0;
}

template <typename ValueType>
void Vector<ValueType>::clear() {
	count = 0;
}

/**
 * Implementation notes: get, set
 * ------------------------------
 * These methods first test that the index is in range and then get or set
 * the appropriate index position in the dynamic array.
 */

template <typename ValueType>
ValueType Vector<ValueType>::get(int index) const {
	if (index < 0 || index >= count) error("get: index out of bounds.");
	return array[index];
}

template <typename ValueType>
void Vector<ValueType>::set(int index, ValueType value) {
	if (index < 0 || index >= count) error("set: index out of bounds.");
	array[index] = value;	
}

/**
 * Implementation notes: Vector selection
 * --------------------------------------
 * The following code impements traditional array selection using square
 * brackets for the index. To ensure that clients can assign to array
 * elements, this method uses an & to return the result by reference.
 */ 

template <typename ValueType>
ValueType & Vector<ValueType>::operator[](int index) {
	if ((index < 0) || (index >= count)) error("Vector index out of bounds.");
	return array[index];
}

/**
 * Implementation notes: add, insert, remove
 * -----------------------------------------
 * These methods must shift the existing elements in the array to make
 * room for a new element or to close up the space left by a deleted one.
 */

template <typename ValueType>
void Vector<ValueType>::add(ValueType value) {
	insert(count, value);
}

template <typename ValueType>
void Vector<ValueType>::insert(int index, ValueType value) {
	if (count == capacity) expandCapacity();
	// Aqui ficar atento ao index >=, mudei, tenho de testar.
	if (index < 0 || index > count) error("insert: index out of bounds.");
	for (int i = count; i > index; i--)
		array[i] = array[i - 1];
	array[index] = value;
	count++;
}

template <typename ValueType>
void Vector<ValueType>::remove(int index) {
	if (index < 0 || index >= count) error("remove: index out of bounds.");
	for (int i = index; i < count - 1; i++)
		array[i] = array[i + 1];
	count--;
}

/**
 * Implementation notes: copy constructor and assignment operator
 * --------------------------------------------------------------
 * These methods follow the standard template, leaving the work to deepCopy.
 */


template <typename ValueType>
Vector<ValueType>::Vector(const Vector<ValueType> & src) {
	deepCopy(src);
}

template <typename ValueType>
Vector<ValueType> & Vector<ValueType>::operator=(const Vector<ValueType> & src) {
	if (this != &src) {
		delete[] array;
		deepCopy(src);
	}
	return *this;
}

/**
 * Implementation notes: deepCopy
 * ------------------------------
 * Copies the data from the src parameter into the current object.
 * All dynamic memory is reallocated to create a "deep copy" in 
 * which the current object and the source object are independent.
 * The capacity is set so the vector has some room to expand.
 */

template <typename ValueType>
void Vector<ValueType>::deepCopy(const Vector<ValueType> & src) {
	capacity = src.count + INITIAL_CAPACITY;
	this->array = new ValueType[capacity];
	for (int i = 0; i < src.count; i++)
		array[i] = src.array[i];
	count = src.count;
}

/**
 * Implementation notes: expandCapacity
 * ------------------------------------
 * This method doubles the array capacity whenever it runs out of space.
 */

template <typename ValueType>
void Vector<ValueType>::expandCapacity() {
	ValueType *oldArray = array;
	capacity *= 2;
	array = new ValueType[capacity];
	for (int i = 0; i < count; i++)
		array[i] = oldArray[i];
	delete[] oldArray;
}


#endif

/**
 * Ha um problema ou algo que nao entendi. Eu posso fazer
 * o overload do operator= usando & no inicio ou nao:
 * (1) ValueType Vector<ValueType>::operator[](int index) 
 * OR
 * (2) ValueType & Vector<ValueType>::operator[](int index)
 * 
 * Agora, preciso estar atento. Se eu quiser usar a implementacao
 * de get, ambas precisa retornar ValueType ou ValueType &.
 */