#include"../include/board.h"
#include<iostream>
using namespace std;


#include "../include/color.h"
Board::~Board() 
{
    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            delete grids[i][j];
}



//rest
void Board::reset() 
{
    for(int i=0; i < 3; i++) {
        for(int j=0; j < 3; j++) {
            grids[i][j] = new Grid;
            grids[i][j]->reset();
        }
    }
    active_x = 1;
    active_y = 1;
    grids[1][1]->set_current();
    turn = "31m✕";
}

void Board::setup() 
{
    int im = 0, gy = 0;
    int jm = 0, gx = 0;
    for (int i = 0; i < 9; ++i) {
        im = i % 3;
        if ( im == 0 && i != 0 ) {
          ++gy;
            cout << endl;
        }
        for(int j = 0; j < 9; ++j) {
            cout << "   ";
            jm = j % 3;
            if ( jm == 0 && j != 0 ) {
                ++gx;
                cout << "   ";
            }
            display[i][j] = grids[gy][gx]->get_char_print(im, jm); 
            cout << ESC + display[i][j] + RST << "   ";
        }
        gx = 0;
        cout << endl;
        cout << endl;
        cout << endl;
    }
}

void Board::in_action(string action) 
{
    this->grids[active_y][active_x]->play_turn(this->turn, action);
    cout << this->results[active_y][active_x] << endl;

    this->grids[active_y][active_x]->rem_current();
    change_turn(this->turn);
    if (action[0] == 'u') { active_y= 0;}
    if (action[0] == 'm') { active_y= 1;}
    if (action[0] == 'l') { active_y= 2;}
    if (action[1] == 'l') { active_x = 0;}
    if (action[1] == 'm') { active_x = 1;}
    if (action[1] == 'r') { active_x = 2;}
    this->grids[active_y][active_x]->set_current();
    setup();
}
