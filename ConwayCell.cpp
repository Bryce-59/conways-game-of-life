class ConwayCell extends AbstractCell {
    private:
        bool alive;
        
        int pos_y;
        int pos_x;

        int countNeighbors(vector<vector<bool>> map) {
            int y_min = max(0, pos_y - 1);
            int y_max = min(pos_y + 1, map.size() - 1);
            int x_min = max(0, pos_x - 1);
            int x_max = min(pos_x + 1, map.size() - 1);

            int total = 0;
            for (int i = y_min; i <= y_max; i++) {
                for (int j = x_min; j <= x_max; j++) {
                    total += map.at(i).at(j);
                }
            }
            return total - map.at(pos_y).at(pos_x);
        }
    public:
        ConwayCell( int y, int x, bool alive ) : AbstractCell(y, x, alive) {} 

        bool updateCell(vector<vector<bool>> map) {
            assert(map.at(pos_y).at(pos_x) == alive);
            
            int n = countNeighbors(map);
            if (n == 3) {
                alive = true;
            } else {
                alive = false;
            }
            return alive;
        }
        
        String displaySelf() {
            if (alive) {
                return "*";
            }
            return ".";
        }
};