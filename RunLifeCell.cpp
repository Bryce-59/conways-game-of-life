// ----------------
// RunLifeConway.cpp
// ----------------

// --------
// includes
// --------

#include <vector>
#include <iostream> // cin, cout

#include "Life.hpp"
#include "Cell.hpp"

#include "RunLife.cpp"

// ----
// main
// ----

int main () {
    using namespace std;

    int t = get_tests ();

    for (int i = 0; i < t; i++) {
        // create the board
        vector<vector<bool>> start_map = get_start_map ();

        // perform the simulation
        Life<Cell> life(map);
        start_game (life);
    }
    return 0;
}