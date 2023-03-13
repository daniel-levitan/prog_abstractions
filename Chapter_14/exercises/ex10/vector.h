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
	ValueType operator[](int index);

	/**
	 * Copy constructor and assignment operator
	 * ----------------------------------------
	 * These methods implement deep copying for vectors
	 */ 
	Vector(const Vector<ValueType> & src);
	Vector<ValueType> & operator=(const Vector<ValueType> & src);

private:

	struct Cell {
		ValueType data;
		Cell *next;	
	};

	/* Instance variables */

	Cell *start;
	Cell *last;
	int count;

	/* Private method prototypes */
	void deepCopy(const Vector<ValueType> & src);
};



/* Implementation */

template <typename ValueType>
Vector<ValueType>::Vector() {
	start = NULL;
	count = 0;
}

template <typename ValueType>
Vector<ValueType>::Vector(int n, ValueType value) {
	for (int i = 0; i < n; i++)
		add(value);
}

template <typename ValueType>
Vector<ValueType>::~Vector() {
	clear();
}

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
	// Cell *old;
	// for (Cell *cp = start; cp != NULL; cp = cp->next) {
	// 	old = cp;
	// 	delete old;
	// }
	if (!isEmpty()) {
		Cell *cp = start;
		while (cp != NULL) {
			Cell *old = cp;
			cp = cp->next;
			delete old;
		}
	}
}

template <typename ValueType>
void Vector<ValueType>::add(ValueType value) {
	Cell *cp = new Cell;
	cp->data = value;
	cp->next = NULL;

	if (start == NULL)
		start = cp;
	else {
		Cell *pt = start;
		while (pt->next != NULL)
			pt = pt->next;
		pt->next = cp;
	}
	count++;
}

template <typename ValueType>
void Vector<ValueType>::insert(int index, ValueType value) {
	if ((index < 0) || (index >= size())) error("Index out of bounds.");
	Cell *ncp = new Cell;
	ncp->data = value;

	if (index == 0) {
		ncp->next = start;
		start = ncp;
	} else {
		Cell *before = NULL;
		Cell *pt = start;
		
		int i = 0;
		while (i < index) {
			before = pt;
			pt = pt->next;		
			i++;
		}
		ncp->next = before->next;
		before->next = ncp;
	}
	count++;
}

template <typename ValueType>
void Vector<ValueType>::remove(int index) {
	if ((index < 0) || (index >= size())) error("Index out of bounds.");

	if (index == 0) {
		Cell *old = start;
		start = start->next;
		delete old;
	} else {
		Cell *before = NULL;
		Cell *pt = start;
		
		int i = 0;
		while (i < index) {
			before = pt;
			pt = pt->next;		
			i++;
		}
		before->next = pt->next;
		delete pt;
	}
	count--;
}

template <typename ValueType>
ValueType Vector<ValueType>::get(int index) const {
// ValueType Vector<ValueType>::get(int index) {
	if ((index < 0) || (index >= size())) error("Index out of bounds.");
	
	Cell *pt = start;
	for (int i = 0; i < index; i++) {
		pt = pt->next;	
	}
	return pt->data;
}

template <typename ValueType>
void Vector<ValueType>::set(int index, ValueType value) {
	if ((index < 0) || (index >= size())) error("Index out of bounds.");
	
	Cell *pt = start;
	for (int i = 0; i < index; i++) {
		pt = pt->next;	
	}
	pt->data = value;	
}

template <typename ValueType>
ValueType Vector<ValueType>::operator[](int index) {
	return get(index);
	// if ((index < 0) || (index >= size())) error("Index out of bounds.");

	// Cell *pt = start;
	// for (int i = 0; i < index; i++) {
	// 	pt = pt->next;	
	// }
	// return pt->data;
}

template <typename ValueType>
Vector<ValueType>::Vector(const Vector<ValueType> & src) {
	deepCopy(src);
}

template <typename ValueType>
Vector<ValueType> & Vector<ValueType>::operator=(const Vector<ValueType> & src) {
	if (this != &src) {
		clear();
		deepCopy(src);
	}
	return *this;
}

template <typename ValueType>
void Vector<ValueType>::deepCopy(const Vector<ValueType> & src) {
	count = src.count;
	Cell *tail = NULL;

	for (Cell *cp = src.start; cp != NULL; cp = cp->next) {
		Cell *ncp = new Cell;
		ncp->data = cp->data;

		if (tail == NULL) 
			start = ncp;
		else 
			tail->next = ncp;
		tail = ncp;
	}
	if (tail != NULL) tail->next = NULL;

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