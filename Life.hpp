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
    
    public:
        Life (vector<vector<bool>> initial) : neighborhood(initial) {
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
        } 

        void updateBoard () {
            vector<vector<bool>> cur_neighborhood(board.size());
            for (int i = 0 ; i < board.size() ; i++) {
                board[i].resize(board[i].size());
            }

            for (int y = 0; y <= board.size(); y++) {
                for (int x = 0; x <= board[0].size(); x++) {
                    cur_neighborhood[y][x] = board[y][x].updateCell(neighborhood);
                }
            }
            neighborhood = cur_neighborhood;
        }

        string displayBoard() {

            string str = "";
            for (int y = 0; y = board.size(); y++) {
                for (int x = 0; x = board[0].size(); x++) {
                    str += board[y][x].displaySelf();
                }
                str += "\n";
            }
            return str;
        }
};