// -------------
// Cell.hpp
// -------------

#ifndef Cell_hpp
#define Cell_hpp
#endif

// --------
// includes
// --------
#ifndef AbstractCell_hpp
#include "AbstractCell.hpp"
#endif

#ifndef FredkinCell_hpp
#include "FredkinCell.hpp"
#endif


class Cell {
    private:
        AbstractCell* _p;
       bool mutated;

    public:
        Cell() {
            _p = new FredkinCell();
            mutated = false;
        }

        Cell( int y, int x, bool alive ) {
            _p = new FredkinCell(y, x, alive);
            mutated = false;
        }
        
        Cell (AbstractCell* p) { 
            _p = p; 
            mutated = false;
        }

        bool updateCell(vector<vector<bool>> *map) {
                bool b = _p->updateCell(map);
                return b;
        }

        string displaySelf() {
                return _p->displaySelf();
        }    

        void mutate (AbstractCell *p) {
                if(!mutated && ((FredkinCell *) _p)->isAge(2)) {
                    delete _p;
                    _p = p;
                    mutated = true;
                }
        }
};