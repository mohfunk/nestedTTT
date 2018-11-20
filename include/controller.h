#ifndef controller_hpp
#define controller_hpp
#include"board.h"


class Controller {
	Board *board;			// pointer to the main board
public:
	Controller();			// ctor
   ~Controller();			// dtor
	void play();			// Main Game loop.
};
#endif
