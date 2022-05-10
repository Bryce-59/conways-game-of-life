// ----------------
// RunLifeCell.cpp
// ----------------

#ifndef RunLifeCell_cpp
#define RunLifeCell_cpp
#endif

// --------
// includes
// --------

#include <vector>
#include <iostream> // cin, cout

#ifndef Life_hpp
#include "Life.hpp"
#endif

#ifndef Cell_hpp
#include "ConwayCell.hpp"
#endif

#ifndef RunLife_cpp
#include "RunLife.cpp"
#endif

// ----
// main
// ----

int main () {
    using namespace std;
    int t = get_tests();
    for (int i = 0; i < t; i++) {
        // create the board
        vector<vector<bool>> start_map = get_start_map();
        Life<Cell> life_board(start_map);
        if (i != 0) {
            cout << endl;
        }
        cout << "*** Life<Cell> " << start_map.size() << "x" << start_map[0].size() << " ***" << endl;
        start_game (life_board);
    }
    return 0;
}