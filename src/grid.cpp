#include<iostream>
#include<string>

#include"../include/grid.h"

using namespace std;

Grid::Grid(){
    current = false;
    reset();
}

Grid::~Grid(){}

void Grid::reset() 
{
    for(int i = 0; i < 3; i++)
        for(int j = 0; j < 3; j++)
            cells[i][j] = "30m.";
}

void Grid::print() 
{
    for (int i = 0; i < 3; ++i) 
        for(int j = 0; j < 3; ++j)
            cout << cells[i][j];
}

string Grid::get_char_print(int col, int row) 
{
    return cells[col][row];
}

char Grid::check_win_grid(string turn, string action) 
{
    return 'z';
}

void Grid::play_turn(string turn, string posn) 
{
    int x, y = 0;
    if(posn[0] == 'u') { y = 0;}
    if(posn[0] == 'm') { y = 1;}
    if(posn[0] == 'l') { y = 2;}
    if(posn[1] == 'l') { x = 0;}
    if(posn[1] == 'm') { x = 1;}
    if(posn[1] == 'r') { x = 2;}
    cells[y][x] = turn;
}


void Grid::set_current() 
{
    if (current == false) {current = true;}
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if (cells[i][j] == "30m.") {
                cells[i][j] = "1;34m.";
            }
        }
    }
}

void Grid::rem_current() 
{
    if(current == true) { current = false;}
    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(cells[i][j] == "1;34m.") {
                cells[i][j] = "30m.";
            }
        }
    }
}
