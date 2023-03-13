#ifndef _grid_h
#define _grid_h

#include "vector.h"
#include "../../../libraries/error.h"

#include <iostream>
using namespace std;

template <typename ValueType>
class Grid {
public:

	/**
	 * Constructor: Grid
	 * Usage: Grid<ValueType> g;
	 * Usage: Grid<ValueType> g(2, 3);
	 * ------------------------------
	 * Initializes a new empty Grid. Users need to call resize to
	 * specify the size.
	 */
	Grid();
	Grid(int rows, int cols);

	/**
	 * Destructor: ~Grid
	 * Usage: implicit
	 * -----------------
	 * Frees any heap memory used.
	 */
	~Grid();

	int numRows() const;
	int numCols() const;

	bool inBounds(int row, int col) const;
	ValueType get(int row, int col) const;
	void set(int row, int col, ValueType value);
	
	void resize(int rows, int cols);

	void show(int row, int col) const;

	void clear();

private:
	
	int rows;
	int cols;
	Vector< Vector<ValueType> *> array;
};

template <typename ValueType>
Grid<ValueType>::Grid() {
	rows = 0;
	cols = 0;
}

template <typename ValueType>
Grid<ValueType>::Grid(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;

	/* Initializing every element to be 0 */
	for (int i = 0; i < rows; i++) 
		array.add(new Vector<ValueType>(cols, 0));
}

template <typename ValueType>
Grid<ValueType>::~Grid() {
	clear();
}

template <typename ValueType>
void Grid<ValueType>::resize(int rows, int cols) {
	// Is there any other check I can make?

	if (this->rows == 0) {
		cout << "HJere " << endl;
		for (int i = 0; i < rows; i++) 
			array.add(new Vector<ValueType>(cols, 0));
	}

	for (int i = 0; i < rows; i++) {
		Vector<ValueType> *v_dest = new Vector<ValueType>(cols, 0);
		
		if (i < this->rows) {	
			Vector<ValueType> *v_src = array.get(i);
			for (int j = 0; j < this->cols; j++)
				v_dest->set(j, v_src->get(j));		
		} else 
			array.add(v_dest);
	}

	this->rows = rows;
	this->cols = cols;

	// Eu usei a ideia de substituir tudo, mas depois de 
	// alimentar o novo array nao tenho como devolver.
	// Em cima vou tentar fazer algo diferente, ou seja,
	// alimentar um vector e devolver no lugar.

	// Vector< Vector<ValueType> *> new_array;

	// for (int i = 0; i < rows; i++) 
	// 	array.add(new Vector<ValueType>(cols, 0));

	// for (int i = 0; i < this->rows; i++) {
	// 	Vector<ValueType> *v_dest = new_array.get(i);
	// 	Vector<ValueType> *v_src = array.get(i);
	// 	for (int j = 0; j < this->cols; j++) {
	// 		v_dest->set(j, v_src->get(j));
	// 	}
	// }

}

template <typename ValueType>
void Grid<ValueType>::set(int row, int col, ValueType value) {
	if (!inBounds(row, col)) error("Grid: Index out of bounds");
	Vector<ValueType> *v = array.get(row);
	v->set(col, value);
}

template <typename ValueType>
ValueType Grid<ValueType>::get(int row, int col) const {
	if (!inBounds(row, col)) error("Grid: Index out of bounds");
	return (array.get(row))->get(col);
}

template <typename ValueType>
void Grid<ValueType>::show(int row, int col) const {
	if (!inBounds(row, col)) error("Grid: Index out of bounds");
	cout << (array.get(row))->get(col) << endl;
}

template <typename ValueType>
int Grid<ValueType>::numRows() const {
	return rows;
}

template <typename ValueType>	
int Grid<ValueType>::numCols() const {
	return cols;
}

template <typename ValueType>
bool Grid<ValueType>::inBounds(int row, int col) const {
	if ((row < 0) || (row > numRows() - 1) || 
	    (col < 0) || (col > numCols() - 1))
	    return false;
	return true;
}

template <typename ValueType>
void Grid<ValueType>::clear() {
	/* Only deleting the pointers that were allocated in 
	   the class instantiation */
	// Tá errado, preciso mudar a funcao para liberar cada célula
	if (rows != 0) {
		for (int i = 0; i < rows; i++)
			delete array.get(i);
		}
}

#endif