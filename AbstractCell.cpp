class AbstractCell {
    private:
        bool alive;
        
        int pos_y;
        int pos_x;
    public:
        explicit AbstractCell( int y, int x, bool alive) : alive(alive), pos_y(y), pos_x(x) {}

        virtual bool updateCell() = 0;
        virtual String displaySelf() = 0;
};