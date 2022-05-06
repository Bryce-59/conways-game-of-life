// -------------
// ConwayCell.hpp
// -------------

#ifndef FredkinCell_hpp
#define FredkinCell_hpp
#endif

// --------
// includes
// --------
#ifndef AbstractCell_hpp
#include "AbstractCell.hpp"
#endif

#include <cassert>

using namespace std;
class FredkinCell : public AbstractCell {
private:
    int _age;

    int countNeighbors(vector<vector<bool>> *map) {
        int pos_y = AbstractCell::_y;
        int pos_x = AbstractCell::_x;
        assert((*map)[pos_y][pos_x] == AbstractCell::_alive);

        int total = 0;
        if (pos_y > 0) {
            total += (*map)[pos_y - 1][pos_x];
        }
        if (pos_y < (*map).size() - 1) {
            total += (*map)[pos_y + 1][pos_x];
        }
        if (pos_x > 0) {
            total += (*map)[pos_y][pos_x - 1];
        }
        if (pos_x < (*map)[0].size() - 1) {
            total += (*map)[pos_y][pos_x + 1];
        }
        return total;
    }

public:
    FredkinCell() : AbstractCell() {}

    FredkinCell( int y, int x, bool alive ) : AbstractCell(y, x, alive), _age(0) {}

    FredkinCell( AbstractCell *p ) : AbstractCell(p), _age(0) {}

    ~FredkinCell    ()             = default;

    string displaySelf() {
        if (AbstractCell::_alive) {
            if (_age < 10) {
                return to_string(_age);
            }
            return "+";
        }
        return "-";
    }

    bool updateCell(vector<vector<bool>> *map) {
        int n = countNeighbors(map);
        if (AbstractCell::_alive == true) {
            if (n % 2 == 0) {
                AbstractCell::_alive = false;
                return false;
            } else {
                _age++;
                return true;
            }
        } else {
            if (n % 2 == 1) {
                AbstractCell::_alive = true;
                return true;
            }
        }
        return false;
    }

    bool isAge(int age) {
        return age == _age;
    }
};