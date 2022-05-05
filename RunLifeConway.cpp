// ----------------
// RunLifeConway.cpp
// ----------------

// --------
// includes
// --------

#include <vector>
#include <iostream> // cin, cout

#include "Life.hpp"
#include "ConwayCell.hpp"

#include "RunLife.cpp"

// ----
// main
// ----

int main () {
    using namespace std;
    int t = get_tests();
    for (int i = 0; i < t; i++) {
        // create the board
        vector<vector<bool>> start_map = get_start_map();
        Life<ConwayCell> life_board(start_map);
        if (i != 0) {
            cout << endl;
        }
        cout << "*** Life<ConwayCell> " << start_map.size() << "x" << start_map[0].size() << " ***" << endl;
        start_game (life_board);
    }
    return 0;
}