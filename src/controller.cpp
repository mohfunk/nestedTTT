#include<string>
#include<iostream>

#include"controller.h"
#include"board.h"
using namespace std;



Controller::Controller() 
{
	board = new Board;
}

Controller::~Controller() 
{
	delete board;
}

// Main game loop
void Controller::play() 
{
	cout << "Nested Tic Tac Tow" << endl;
	cout << "Player one is X and Plauer two is O\n" << endl;
	cout << "Controls: <row><col> then press enter\n" << endl;
	cout << "<row> u - upper     row\n" << endl;
	cout << "<row> m - middle    row\n" << endl;
	cout << "<row> l - lower     row\n" << endl;
	cout << "<col> l - leftmost  column\n" << endl;
	cout << "<col> m - middle    column\n" << endl;
	cout << "<col> r - rightmost column\n" << endl;
	cout << "ul um ur \n" << endl;
	cout << "ml mm mr \n" << endl;
	cout << "ll lm lr \n" << endl;
	string input;

	if( board == NULL) {
        cout << "be" << endl;
	}
	// print action here
	this->board->reset();
	this->board->setup();
	while(getline(cin, input)) {
		if (input == "q") {
			cout << "Quitting Game..." << endl;
			return;
		} else {
			cout << endl;
			this->board->in_action(input);
		}
		if(this->board->get_ended()) {break;}
	}
	cout << "You have won the game." <<endl;
}
