#include <iostream>
#include "AbstractCell.hpp"
using namespace std;


class Cell {
    private:
		AbstractCell* _p;

	public:
        Cell( int y, int x, bool alive ) : _p(new FredkinCell(y, x, alive)) {}
		
        Cell (AbstractCell* p) { 
			_p = p; 
        }

    
};