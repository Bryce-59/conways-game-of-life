// ---------------
// TestVoting.cpp
// ---------------

// https://code.google.com/p/googletest/wiki/V1_7_Primer#Basic_Assertions

// --------
// includes
// --------

#include "gtest/gtest.h"

#ifndef Life_hpp
#include "Life.hpp"
#endif

#ifndef ConwayCell_hpp
#include "ConwayCell.hpp"
#endif

using namespace std;

// ----------------
// whos_a_winner
// ----------------

TEST(LifeFixture, conway_test_0) {
    vector<vector<bool>> map = {{0,0,0,1,1},
        {1,1,1,1,0},
        {0,0,1,0,1},
        {1,1,1,0,1},
        {1,0,0,0,0},
        {1,1,0,0,0}
    };

    int f = 3;

    Life<ConwayCell> lifeboard(map);
    string ans = "Generation = 3, Population = 11.\n"
                 "..*..\n"
                 ".***.\n"
                 ".*..*\n"
                 "**...\n"
                 "*.*..\n"
                 ".*...\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, conway_test_1) {
    vector<vector<bool>> map = {{0,0,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0},
        {0,0,1,0,0,0,0,0},
        {1,0,0,0,0,0,0,0}
    };

    int f = 0;

    Life<ConwayCell> lifeboard(map);
    string ans = "Generation = 0, Population = 3.\n"
                 "........\n"
                 "....*...\n"
                 "..*.....\n"
                 "*.......\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, conway_test_2) {
    vector<vector<bool>> map = {{1,1,0,1,1,0,1,0,0},
        {0,1,0,1,0,0,1,0,0}
    };
    int f = 2;

    Life<ConwayCell> lifeboard(map);
    string ans = "Generation = 2, Population = 8.\n"
                 "**.*.*...\n"
                 "**.*.*...\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, conway_test_3) {
    vector<vector<bool>> map = {{1},
        {1},
        {1},
        {0},
        {1},
        {1}
    };

    int f = 1;

    Life<ConwayCell> lifeboard(map);
    string ans = "Generation = 1, Population = 1.\n"
                 ".\n"
                 "*\n"
                 ".\n"
                 ".\n"
                 ".\n"
                 ".\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, conway_test_4) {
    vector<vector<bool>> map = {{1,1,1,0,1,0,1},
        {1,1,1,1,1,0,1},
        {1,0,1,1,1,0,0}
    };

    int f = 2;

    Life<ConwayCell> lifeboard(map);
    string ans = "Generation = 2, Population = 2.\n"
                 ".......\n"
                 "....**.\n"
                 ".......\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, conway_test_5) {
    vector<vector<bool>> map = {{0,0,1,1,0,0,1},
        {1,0,0,1,0,1,0},
        {1,0,0,1,0,1,0},
        {0,0,0,0,1,0,0},
        {1,0,0,1,0,0,1},
        {0,1,0,0,1,1,0}
    };

    int f = 1;

    Life<ConwayCell> lifeboard(map);
    string ans = "Generation = 1, Population = 15.\n"
                 "..***..\n"
                 ".*.*.**\n"
                 "...*.*.\n"
                 "...***.\n"
                 "...*...\n"
                 "....**.\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, conway_test_6) {
    vector<vector<bool>> map = {{1,1,1},
        {1,1,1}
    };
    int f = 3;

    Life<ConwayCell> lifeboard(map);
    string ans = "Generation = 3, Population = 0.\n"
                 "...\n"
                 "...\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}