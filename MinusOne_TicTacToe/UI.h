#pragma once
#ifndef UI_H
#define UI_H

#include <iostream>
#include "GameBoard.h"

using namespace std;

class UI {
private:
	int curRound;
	int numRounds;
public:
	//UI(); // Default constructor to create the UI Display object
	int displayMenu(); // Displays instructions with option to start new game or quit - prompts for number of rounds on start
					   //Returns: numRounds
	void displayBoard(int curRound,int numRounds, int* board); // Displays current board to the user
	void scoreBoard(int xWins, int oWins, int draw);
};

#endif // !UI_H
