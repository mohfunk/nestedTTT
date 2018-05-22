#ifndef board_hpp
#define board_hpp
#include"grid.h"
#include<string>

class Board {
friend class Grid;
	Grid *grids[3][3];
	int current_grid_x;
	int current_grid_y;
	char turn;
	char textDisplay[17][29];
  char results[3][3];
	bool ended;
	std::string action;
public:
	Board();
	~Board();
	void print();
	void reset();
	void setup();
	void Raction(std::string action);
	void change_turn(char turn);
	bool check_win_game();
	bool has_ended();
};

#endif
