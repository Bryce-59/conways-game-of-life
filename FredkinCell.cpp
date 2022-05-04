class FredkinCell : public AbstractCell {
    private:
        bool alive;
        
        int pos_y;
        int pos_x;

        int my_age;

        int countNeighbors(vector<vector<bool>> map) {
            int total = 0;
            if (pos_y > 0) {
                total += map.at(pos_y - 1).at(pos_x);
            }
            if (pos_y < map.size() - 1) {
                total += map.at(pos_y + 1).at(pos_x);
            }
            if (pos_x > 0) {
                total += map.at(pos_y).at(pos_x - 1);
            }
            if (pos_x < map.size() - 1) {
                total += map.at(pos_y).at(pos_x + 1);
            }
            return total;
        }
    public:
        FredkinCell( int y, int x, bool alive ) : AbstractCell(y, x, alive), my_age(0) {}

        String displaySelf() {
            if (alive) {
                if (age < 10) {
                    return "" + my_age;
                }
                return "+";
            }
            return "-";
        }

        bool isAlive() {
            return alive;
        }
        
        void updateCell(vector<vector<bool>> map) {
            assert(map.at(pos_y).at(pos_x) == alive);
            
            int n = countNeighbors(map);
            if (n % 2 == 1) {
                if (alive) {
                    ++age;
                }
                alive = true;
            } else {
                alive = false;
            }
            return alive;
        }
};