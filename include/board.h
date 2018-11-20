#ifndef board_hpp
#define board_hpp

#include<string>

#include"grid.h"

class Grid;

class Board {
    Grid       *grids[3][3];
    int         active_x;
    int         active_y;
    std::string        turn;
    std::string        display[9][9];
    std::string        results[3][3];
    bool        ended;
    std::string action;
    public:
    Board()     {}
   ~Board();
    void        reset();
    void        setup();
    void        in_action(std::string action);
    void        change_turn(std::string turn) { if (turn == "✕") this->turn = "⭘"; else this->turn = "✕";}
    bool        get_ended() { return this->ended; }
};

#endif
