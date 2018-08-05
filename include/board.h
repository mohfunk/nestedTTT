#ifndef board_hpp
#define board_hpp
#include"grid.h"
#include<string>
class Grid;
class Board {
	Grid *grids[3][3];
	int activeGridX;
	int activeGridY;
	char turn;
	char textDisplay[17][29];
  	char results[3][3];
	bool ended;
	std::string action;
public:
	Board() {} // ctor
	~Board();
	void print();
	void reset();
	void setup();
	void inAction(std::string action);
	void changeTurn(char turn) { if (turn == 'X') this->turn = 'O'; else this->turn = 'X';}
	bool hasEnded() { return this->ended; }
};

#endif
