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

    private:
        bool _alive;
        
        int _x;
        int _y;

    public:
        explicit AbstractCell() = default;
        explicit AbstractCell( int y, int x, bool alive ) : _alive(alive), _y(y), _x(x) {}

        virtual string displaySelf() = 0;
        virtual bool updateCell(vector<vector<bool>> map) = 0;

        int getX() { return _x; }

        int getY() { return _y; }

        bool setAlive(bool val) { _alive = val; }

        bool getAlive() { return _alive; }
};