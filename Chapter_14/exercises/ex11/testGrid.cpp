// 218 - grid
// 535 - 12.4
// 669 - ex. 14

#include <iostream>
#include "grid.h"

int main() {
	Grid<int> g(2, 3);
	// g.show(0, 0);
	g.set(0, 0, -1);
	// g.show(0, 0);

	g.resize(4, 4);
	
	// Grid<int> g;
	// g.resize(2, 3);
	g.show(0, 0);
	// g.set(1, 2, 1);
	// g.show(1, 2);


	return 0;
}

