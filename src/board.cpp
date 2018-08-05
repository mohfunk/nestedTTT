#include"../include/board.h"
#include<iostream>
using namespace std;



// dtor
Board::~Board(){
	for(int i = 0; i < 3; ++i) {
		for(int j = 0; j < 3; ++j) {
			delete grids[i][j];
		}
	}
}



//rest
void Board::reset() {
	for(int i=0; i < 3; i++){
		for(int j=0; j < 3; j++) {
			grids[i][j] = new Grid;
			grids[i][j]->reset();
		}
	}
	activeGridX = 1;
	activeGridY = 2;
	grids[1][1]->set_current();
	turn = 'X';
}
void Board::setup() {
	for (int i = 0; i < 17; ++i) {
		for(int j = 0; j < 29; ++j) {
			if (i % 2 == 0) { // if i is even
				int ones = j % 10;
				int tens = j / 10;
				if ( tens == 0 ) {
					if (ones == 0 || ones == 4 || ones == 8) {
						if( i == 0 || i == 2 || i == 4) {
							textDisplay[i][j] = grids[0][0]->get_char_print(i, ones);
						} else if ( i == 6 || i == 8 || i == 10) {
							textDisplay[i][j] = grids[1][0]->get_char_print(i, ones);
						} else if ( i == 12 || i == 14 || i == 16) {
							textDisplay[i][j] = grids[2][0]->get_char_print(i, ones);
						} else {
							textDisplay[i][j] = ' ';
						}
					} else {
						if (j == 9 || j == 19) {
							textDisplay[i][j] = '	';
						} else { textDisplay[i][j] = ' ';}
					}

				} else if ( tens == 1 ) {
					if (ones == 0 || ones == 4 || ones == 8) {
						if( i == 0 || i == 2 || i == 4) {
							textDisplay[i][j] = grids[0][1]->get_char_print(i, ones);
						} else if ( i == 6 || i == 8 || i == 10) {
							textDisplay[i][j] = grids[1][1]->get_char_print(i, ones);
						} else if ( i == 12 || i == 14 || i == 16) {
							textDisplay[i][j] = grids[2][1]->get_char_print(i, ones);
						} else {
							textDisplay[i][j] = ' ';
						}
					} else {if (j == 9 || j == 19) {
						textDisplay[i][j] ='	';
					} else { textDisplay[i][j] = ' ';}
					}
				} else if ( tens == 2 ) {
					if (ones == 0 || ones == 4 || ones == 8) {
						if( i == 0 || i == 2 || i == 4) {
							textDisplay[i][j] = grids[0][2]->get_char_print(i, ones);
						} else if ( i == 6 || i == 8 || i == 10) {
							textDisplay[i][j] = grids[1][2]->get_char_print(i, ones);
						} else if ( i == 12 || i == 14 || i == 16) {
							textDisplay[i][j] = grids[2][2]->get_char_print(i, ones);
							//	int m = 5;
						} else {
							textDisplay[i][j] = ' ';
						}
					} else {if(j == 9 || j == 19) {
						textDisplay[i][j]='	';
					} else { textDisplay[i][j] = ' '; }

					}
				}
			} else {
				if (j == 9 || j == 19) {
					textDisplay[i][j] = '	';
				} else if ( i == 5 || i == 11) {
					textDisplay[i][j] = '-';
				} else { textDisplay[i][j] = ' ';}
			}
		}
	}
}


void Board::print() {
	for (int i = 0; i < 17; ++i) {
		for(int j = 0; j < 29; ++j) {
			cout << textDisplay[i][j];
		}
		cout << endl;
	}
}


void Board::inAction(string action) {
	this->grids[activeGridY][activeGridX]->play_turn(this->turn, action);
  	cout << this->results[activeGridY][activeGridX] << endl;

	this->grids[activeGridY][activeGridX]->rem_current();
	changeTurn(this->turn);
	if (action[0] == 'u') { activeGridY= 0;}
	if (action[0] == 'm') { activeGridY= 1;}
	if (action[0] == 'l') { activeGridY= 2;}
	if (action[1] == 'l') { activeGridX = 0;}
	if (action[1] == 'm') { activeGridX = 1;}
	if (action[1] == 'r') { activeGridX = 2;}
	this->grids[activeGridY][activeGridX]->set_current();
	setup();
	print();
}
