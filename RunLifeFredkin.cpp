// ----------------
// RunLifeFredkin.cpp
// ----------------

#ifndef RunLifeFredkin_cpp
#define RunLifeFredkin_cpp
#endif

// --------
// includes
// --------

#include <vector>
#include <iostream> // cin, cout

#ifndef Life_hpp
#include "Life.hpp"
#endif

#ifndef FredkinCell_hpp
#include "FredkinCell.hpp"
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
        Life<FredkinCell> life_board(start_map);
        if (i != 0) {
            cout << endl;
        }
        cout << "*** Life<FredkinCell> " << start_map.size() << "x" << start_map[0].size() << " ***" << endl;
        start_game (life_board);
    }
    return 0;
}