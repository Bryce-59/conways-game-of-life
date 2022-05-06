// -------------
// Life.hpp
// -------------

#ifndef Life_hpp
#define Life_hpp
#endif

// -------------
// includes
// -------------

#ifndef AbstractCell_hpp
#include "AbstractCell.hpp"
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

#include <vector>

using namespace std;

template <typename C>
class Life {

    private:
        vector<vector<C>> board;
        vector<vector<bool>> neighborhood;
        vector<vector<bool>> cur_neighborhood; //sacrifice space for speed
        
        int generation;
        int population;
    
    public:
        Life (vector<vector<bool>> initial) : neighborhood(initial), cur_neighborhood(initial) {
            vector<vector<C>> b(initial.size());
            for (int i = 0 ; i < initial.size(); i++) {
                b[i].resize(initial[i].size());
            }
            board = b;

            int init_pop = 0;
            for (int i = 0; i < initial.size(); i++) {
                for (int j = 0; j < initial[i].size(); j++) {
                    bool alive = neighborhood[i][j];
                    board[i][j] = C(i, j, alive);
                    init_pop += alive;
                }
            }
            generation = 0;
            population = init_pop;
        } 

        void updateBoard () {
            int cur_pop = 0;
            Cell tmp = Cell();
            for (int y = 0; y < board.size(); y++) {
                for (int x = 0; x < board[0].size(); x++) {
                    bool alive = board[y][x].updateCell(&neighborhood);
                    if (alive && typeid(board[y][x]).name() == typeid(tmp).name() && board[y][x].displaySelf() == "2") {
                        board[y][x] = new ConwayCell(y, x, true);
                    }
                    cur_neighborhood[y][x] = alive;
                    cur_pop += alive;
                }
            }
            neighborhood = cur_neighborhood;
            generation++;
            population = cur_pop;
        }

        string displayBoard() {
            string str = "Generation = " + to_string(generation) + ", Population = " + to_string(population) + ".\n";
            for (int y = 0; y < board.size(); y++) {
                for (int x = 0; x < board[0].size(); x++) {
                    str += board[y][x].displaySelf();
                }
                str += "\n";
            }
            return str;
        }
};