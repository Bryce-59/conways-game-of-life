// ----------------
// RunLife.cpp
// ----------------

// --------
// includes
// --------

#include <vector>
#include <iostream> // cin, cout
#include <sstream>  // istringstream
#include <cassert>   // assert
#include <algorithm> //count

// #include "Life.hpp"

// ----
// main
// ----


int get_tests() {
    string s;
    int t;
    cin >> t;
    getline(cin, s);
    assert(t > 0);
    assert(t <= 100);
    getline(cin, s);
    return t;
}

vector<vector<bool>> get_start_map () {
    // create the board
    string s;
    int r;
    int c;
    cin >> r;
    cin >> c;
    getline(cin, s);
    assert(r > 0);
    assert(r <= 200);
    assert(c > 0);
    assert(c <= 200);

    vector<vector<bool>> map(r);
    for (int i = 0 ; i < r ; i++) {
        map[i].resize(c);
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            map[i][j] = false;
        }
    }

    // initialize the board
    int n;
    cin >> n;
    assert(n > 0);
    assert((n <= r * c) && (n <= 700));
    getline(cin, s);

    int coor = 0;
    while (coor < n && getline(cin, s)) {
        istringstream iss(s);
        int y;
        int x;
        iss >> y;
        iss >> x;
        assert(y >= 0);
        assert(y < r);
        assert(x >= 0);
        assert(x < c);

        map[y][x] = true;
        ++coor;
    }
    assert(coor == n);
    return map;

}

template <typename C>
void start_game(Life<C> life_board) {
    string s;
    int s_;
    int f;
    cin >> s_;
    cin >> f;
    getline(cin, s);
    assert(s_ > 0);
    assert(s_ <= 2000);
    assert(f > 0);
    assert(f <= 200);
    getline(cin, s);

    for (int i = 0; i <= s_; i++) {
        if (i % f == 0) {
            cout << endl;
            cout << life_board.displayBoard();
        }
        life_board.updateBoard();
    }
}