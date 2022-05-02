// ----------------
// RunLifeCell.cpp
// ----------------

// --------
// includes
// --------

#include <vector>
#include <iostream> // cin, cout
#include <sstream>  // istringstream
#include <map>

#include "Allocator.hpp"

// ----
// main
// ----

int main () {
    using namespace std;

    string s;
    int t;
    cin >> t;
    getline(cin, s);
    assert(t > 0);
    assert(t <= 100);
    getline(cin, s);

    for (int i = 0; i < t; i++) {
        // create the board
        int r;
        int c;
        cin >> r;
        cin >> c;
        getline(cin, s);
        assert(r > 0);
        assert(r <= 200);
        assert(c > 0);
        assert(c <= 200);

        // initialize the board
        int n;
        cin >> n;
        assert(n > 0);
        assert((n <= r * c) && (n <= 700));
        getline(cin, s);

        int coor = 0;
        while (coor < n && getline(cin, s)) {
            istringstream iss(s);
            int x;
            int y;
            iss >> x;
            iss >> y;

            /* add initilization code here */

            ++coor;
        }
        assert(coor == n);
        
        int s;
        int f;
        cin << s;
        cin << f;
        getline(cin, s);
        assert(s > 0);
        assert(s <= 2000);
        assert(f > 0);
        assert(f <= 200);
        getline(cin, s);

        // perform the simulation

        /* add simulation code here */

    }
    return 0;
}
