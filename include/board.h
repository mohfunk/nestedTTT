#ifndef board_hpp
#define board_hpp
#include"grid.h"
#include<string>
class Grid;
class Board {
    Grid *grids[3][3];
    int active_grid_x;
    int active_grid_y;
    char turn;
    char text_display[17][29];
    char results[3][3];
    bool ended;
    std::string action;
public:
    Board() {} // ctor
    ~Board();
    void print();
    void reset();
    void setup();
    void in_action(std::string action);
    void change_turn(char turn) { if (turn == 'X') this->turn = 'O'; else this->turn = 'X';}
    bool get_ended() { return this->ended; }
};

#endif
