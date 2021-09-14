#pragma once
#ifndef UI_H
#define UI_H

#include <iostream>
#include "GameBoard.h"
#include <string>

using namespace std;

class UI {
private:
	int curRound, numRounds;
	int xWins, oWins, draws;
	string getSpotIcon(int boardVal, int pos); // Takes the number in the board position and position on board and returns what to show to the user
public:
	UI(); // Default constructor to create the UI Display object
	bool displayMenu(); // Displays instructions with option to start new game or quit - prompts for number of rounds on start
					   //Returns true to play round, false to exit
	void displayBoard(int* board); // Displays current board to the user
	void scoreBoard(); // Displays the scoreboard to the user
	void addResult(int result); // Adds the result to the scoreboard: 1 is xWin, 2 is oWin, 3 is draw
	void incrementRound(); // Adds 1 to current round
	int getCurRound(); // returns the current round number
	int getNumRounds(); // returns the number of rounds chosen by the user
};

#endif // !UI_H
