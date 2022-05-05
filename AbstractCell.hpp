// -------------
// AbstractCell.hpp
// -------------

#ifndef AbstractCell_hpp
#define AbstractCell_hpp
#endif

// --------
// includes
// --------

using namespace std;

class AbstractCell {

    protected:     
        int _y;
        int _x;
        bool _alive;

    public:
        explicit AbstractCell() = default;
        explicit AbstractCell( int y, int x, bool alive ) : _y(y), _x(x), _alive(alive) {}

        virtual string displaySelf() = 0;
        virtual bool updateCell(vector<vector<bool>> *) = 0;
};