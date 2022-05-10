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

    void try_mutate () {
        FredkinCell *ptr = dynamic_cast<FredkinCell*>(_p);
        if(ptr && ptr->isAge(2)) {
            ConwayCell *temp = new ConwayCell(_p);
            delete _p;
            _p = temp;
        }
    }

public:
    Cell() {
        _p = new FredkinCell();
    }

    Cell( int y, int x, bool alive ) {
        _p = new FredkinCell(y, x, alive);
    }

    Cell (AbstractCell* p) {
        _p = p;
    }

    ~Cell    ()             = default;

    bool updateCell(vector<vector<bool>> *map) {
        bool b = _p->updateCell(map);
        if (b) {
            try_mutate();
        }
        return b;
    }

    string displaySelf() {
        return _p->displaySelf();
    }
};