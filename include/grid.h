#ifndef grid_h
#define grid_h

#include<string>

class Grid{
    std::string cells[3][3];
    bool current;
public:
    Grid();
   ~Grid();
    void print();
    void reset();
    std::string get_char_print(int, int);
    void play_turn(std::string, std::string);
    char check_win_grid(std::string,std::string);
    void set_current();
    void rem_current();
};

#endif
