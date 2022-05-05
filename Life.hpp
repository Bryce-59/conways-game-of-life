#include <vector>

// #include "ConwayCell.hpp"
#include "FredkinCell.hpp"
#include "Cell.hpp"

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
            for (int i = 0; i < initial.size(); i++) {
                for (int j = 0; j < initial[i].size(); j++) {
                    board[i][j] = *(new C(i, j, neighborhood[i][j]));
                }
            }
            generation = 0;
        } 

        void updateBoard () {
            int cur_pop = 0;
            for (int y = 0; y < board.size(); y++) {
                for (int x = 0; x < board[0].size(); x++) {
                    bool alive = board[y][x].updateCell(&neighborhood);
                    cur_neighborhood[y][x] = alive;
                    cur_pop += alive;
                }
            }
            neighborhood = cur_neighborhood;
            generation++;
            population = cur_pop;
        }

        string displayBoard() {
            cout << "Generation = " << generation << ", Population = " << population << "." << endl;
            string str = "";
            for (int y = 0; y < board.size(); y++) {
                for (int x = 0; x < board[0].size(); x++) {
                    str += board[y][x].displaySelf();
                }
                str += "\n";
            }
            return str;
        }
};