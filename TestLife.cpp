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

#ifndef FredkinCell_hpp
#include "FredkinCell.hpp"
#endif

#ifndef Cell_hpp
#include "Cell.hpp"
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
                                {1,1,0,0,0}};

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
                                {1,0,0,0,0,0,0,0}};
    
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
                                {0,1,0,1,0,0,1,0,0}};
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
                                {1}};
    
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
                                {1,0,1,1,1,0,0}};
    
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
                                {0,1,0,0,1,1,0}};
    
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
                                {1,1,1}};
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

TEST(LifeFixture, fredkin_test_0) {
    vector<vector<bool>> map = {{0,0,0,1,1},
                                {1,1,1,1,0},
                                {0,0,1,0,1},
                                {1,1,1,0,1},
                                {1,0,0,0,0},
                                {1,1,0,0,0}};

    int f = 3;

    Life<FredkinCell> lifeboard(map);
    string ans = "Generation = 3, Population = 17.\n"
                    "----3\n"
                    "----0\n"
                    "00-23\n"
                    "001--\n"
                    "100-2\n"
                    "1101-\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, fredkin_test_1) {
    vector<vector<bool>> map = {{0,0,0,0,0,0,0,0},
                                {0,0,0,0,1,0,0,0},
                                {0,0,1,0,0,0,0,0},
                                {1,0,0,0,0,0,0,0}};
    
    int f = 0;

    Life<FredkinCell> lifeboard(map);
    string ans = "Generation = 0, Population = 3.\n"
                    "--------\n"
                    "----0---\n"
                    "--0-----\n"
                    "0-------\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, fredkin_test_2) {
    vector<vector<bool>> map = {{1,1,0,1,1,0,1,0,0},
                                {0,1,0,1,0,0,1,0,0}};
    int f = 2;

    Life<FredkinCell> lifeboard(map);
    string ans = "Generation = 2, Population = 6.\n"
                    "-----0--0\n"
                    "----012-0\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, fredkin_test_3) {
    vector<vector<bool>> map = {{1},
                                {1},
                                {1},
                                {0},
                                {1},
                                {1}};
    
    int f = 1;

    Life<FredkinCell> lifeboard(map);
    string ans = "Generation = 1, Population = 4.\n"
                    "1\n"
                    "-\n"
                    "1\n"
                    "-\n"
                    "1\n"
                    "1\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, fredkin_test_4) {
    vector<vector<bool>> map = {{1,1,1,0,1,0,1},
                                {1,1,1,1,1,0,1},
                                {1,0,1,1,1,0,0}};
    
    int f = 2;

    Life<FredkinCell> lifeboard(map);
    string ans = "Generation = 2, Population = 8.\n"
                    "-2----2\n"
                    "-2-2-0-\n"
                    "---201-\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, fredkin_test_5) {
    vector<vector<bool>> map = {{0,0,1,1,0,0,1},
                                {1,0,0,1,0,1,0},
                                {1,0,0,1,0,1,0},
                                {0,0,0,0,1,0,0},
                                {1,0,0,1,0,0,1},
                                {0,1,0,0,1,1,0}};
    
    int f = 1;

    Life<FredkinCell> lifeboard(map);
    string ans = "Generation = 1, Population = 21.\n"
                    "001-0--\n"
                    "10---1-\n"
                    "1001010\n"
                    "---0--0\n"
                    "--0-0--\n"
                    "--0-11-\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, fredkin_test_6) {
    vector<vector<bool>> map = {{1,1,1},
                                {1,1,1}};
    int f = 3;

    Life<FredkinCell> lifeboard(map);
    string ans = "Generation = 3, Population = 2.\n"
                    "-3-\n"
                    "-3-\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, cell_test_0) {
    vector<vector<bool>> map = {{0,0,0,1,1},
                                {1,1,1,1,0},
                                {0,0,1,0,1},
                                {1,1,1,0,1},
                                {1,0,0,0,0},
                                {1,1,0,0,0}};

    int f = 3;

    Life<Cell> lifeboard(map);
    string ans = "Generation = 3, Population = 17.\n"
                    "----*\n"
                    ".---0\n"
                    "00-**\n"
                    "001--\n"
                    "100-*\n"
                    "1101-\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, cell_test_1) {
    vector<vector<bool>> map = {{0,0,0,0,0,0,0,0},
                                {0,0,0,0,1,0,0,0},
                                {0,0,1,0,0,0,0,0},
                                {1,0,0,0,0,0,0,0}};
    
    int f = 0;

    Life<Cell> lifeboard(map);
    string ans = "Generation = 0, Population = 3.\n"
                    "--------\n"
                    "----0---\n"
                    "--0-----\n"
                    "0-------\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, cell_test_2) {
    vector<vector<bool>> map = {{1,1,0,1,1,0,1,0,0},
                                {0,1,0,1,0,0,1,0,0}};
    int f = 2;

    Life<Cell> lifeboard(map);
    string ans = "Generation = 2, Population = 6.\n"
                    "-----0--0\n"
                    "----01*-0\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, cell_test_3) {
    vector<vector<bool>> map = {{1},
                                {1},
                                {1},
                                {0},
                                {1},
                                {1}};
    
    int f = 1;

    Life<Cell> lifeboard(map);
    string ans = "Generation = 1, Population = 4.\n"
                    "1\n"
                    "-\n"
                    "1\n"
                    "-\n"
                    "1\n"
                    "1\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, cell_test_4) {
    vector<vector<bool>> map = {{1,1,1,0,1,0,1},
                                {1,1,1,1,1,0,1},
                                {1,0,1,1,1,0,0}};
    
    int f = 0;

    Life<Cell> lifeboard(map);
    string ans = "Generation = 0, Population = 15.\n"
                    "000-0-0\n"
                    "00000-0\n"
                    "0-000--\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, cell_test_5) {
    vector<vector<bool>> map = {{0,0,1,1,0,0,1},
                                {1,0,0,1,0,1,0},
                                {1,0,0,1,0,1,0},
                                {0,0,0,0,1,0,0},
                                {1,0,0,1,0,0,1},
                                {0,1,0,0,1,1,0}};
    
    int f = 1;

    Life<Cell> lifeboard(map);
    string ans = "Generation = 1, Population = 21.\n"
                    "001-0--\n"
                    "10---1-\n"
                    "1001010\n"
                    "---0--0\n"
                    "--0-0--\n"
                    "--0-11-\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}

TEST(LifeFixture, cell_test_6) {
    vector<vector<bool>> map = {{1,1,1},
                                {1,1,1}};
    int f = 3;

    Life<Cell> lifeboard(map);
    string ans =    "Generation = 3, Population = 0.\n"
                    "-.-\n"
                    "-.-\n";

    for (int i = 0; i < f; i++) {
        lifeboard.updateBoard();
    }
    ASSERT_EQ(lifeboard.displayBoard() == ans, true);
}