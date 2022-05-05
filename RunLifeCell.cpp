// ----------------
// RunLifeConway.cpp
// ----------------

// --------
// includes
// --------

#include <vector>
#include <iostream> // cin, cout

#include "Life.hpp"

#include "RunLife.cpp"

// ----
// main
// ----

int main () {
    int t = get_tests();
    for (int i = 0; i < t; i++) {
        // create the board
        vector<vector<bool>> start_map = get_start_map();
        vector<vector<Cell>> board(start_map.size());
        for (int i = 0 ; i < start_map.size() ; i++) {
            board[i].resize(start_map[0].size());
        }

        for (int i = 0; i < start_map.size(); i++) {
            for (int j = 0; j < start_map[0].size(); j++) {
                board[i][j] = new FredkinCell(i, j, start_map[i][j]);
            }
        }

        Life<Cell> life_board(start_map);
        if (i != 0) {
            cout << endl;
        }
        cout << "*** Life<Cell> " << start_map.size() << "x" << start_map[0].size() << " ***" << endl;
        start_game (life_board);
    }
    return 0;
}