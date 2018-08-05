#include"../include/grid.h"
#include<iostream>
#include<string>
using namespace std;



// ctor
Grid::Grid(){
	current = false;
	reset();
}

// dtor
Grid::~Grid(){}


//rest
void Grid::reset() {
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++) {
			cells[i][j] = '.';
		}
	}
} // reset()


// FOR DEBUGGING
void Grid::print() {
	for (int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			cout << cells[i][j];
		}
		//     cout << endl;
	}

}
char Grid::get_char_print(int i, int ones) {
	int x = 0;
	int y = 0;
	if (ones == 0) {
		x = 0;
	} else if (ones == 4) {
		x = 1;
	} else if (ones == 8){
		x = 2;
	}
	if (i % 6 == 0 ) { y = 0; }
	else if ( i == 2 ||  i == 8 || i == 14 ) { y = 1; }
	else if ( i == 4 ||  i == 10 || i == 16) { y = 2; }
	return cells[y][x];
}

char Grid::check_win_grid(char turn, string action) {
return 'z';
}

void Grid::play_turn(char turn, string posn) {
	int x, y = 0;
	if(posn[0] == 'u') { y = 0;}
	if(posn[0] == 'm') { y = 1;}
	if(posn[0] == 'l') { y = 2;}
	if(posn[1] == 'l') { x = 0;}
	if(posn[1] == 'm') { x = 1;}
	if(posn[1] == 'r') { x = 2;}
	cells[y][x] = turn;
}


void Grid::set_current() {
	if (current == false) {current = true;}
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if (cells[i][j] == '.') {
				cells[i][j] = '*';
			}
		}
	}
}

void Grid::rem_current() {
	if(current == true) { current = false;}
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			if(cells[i][j] == '*') {
				cells[i][j] = '.';
			}
		}
	}
}
