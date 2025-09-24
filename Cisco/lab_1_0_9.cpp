#include <iostream>
using namespace std;

class AdHocSquare {
    private:
        double    side;
    public:
        AdHocSquare(double s){
            if (s >= 0) {
                side = s;   
            }
        }
        double get_area(){
            return (side * side);
        }
};

class LazySquare {
    public:
        AdHocSquare(double side);
        void set_side(double side);
        double get_area();
    private:
        double    side;
        double    area;
        bool      side_changed;
};

