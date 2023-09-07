// -------------
// ConwayCell.hpp
// -------------

#ifndef ConwayCell_hpp
#define ConwayCell_hpp
#endif

#include <cassert>

using namespace std;
class ConwayCell : public AbstractCell {

private:
    int countNeighbors(vector<vector<bool>> *map) {
        int pos_y = AbstractCell::_y;
        int pos_x = AbstractCell::_x;

        assert((*map)[pos_y][pos_x] == AbstractCell::_alive);

        int y_min = max(0, pos_y - 1);
        int y_max = min(pos_y + 1, (int) (*map).size() - 1);
        int x_min = max(0, pos_x - 1);
        int x_max = min(pos_x + 1, (int) (*map)[0].size() - 1);

        int total = 0;
        for (int i = y_min; i <= y_max; i++) {
            for (int j = x_min; j <= x_max; j++) {
                total += (*map)[i][j];
            }
        }
        return total - (*map)[pos_y][pos_x];
    }

public:
    ConwayCell() = AbstractCell();
    ConwayCell( int y, int x, bool alive ) : AbstractCell(x, y, alive);
    ConwayCell( ConwayCell *p ) : AbstractCell(*p);

    ~ConwayCell() = default;

    string displaySelf() {
        return AbstractCell::_alive ? "*" : ".";
    }

    bool updateCell(vector<vector<bool>> *map) {
        int n = countNeighbors(map);
        AbstractCell::_alive = n == 3 || (AbstractCell::_alive && n == 2);
        return AbstractCell::_alive;
    }
};