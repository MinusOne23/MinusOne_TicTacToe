#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>

using namespace std;

class GameBoard {
private:
	int* board; // Holds current game
	bool xTurn; // If true, Player One's turn, false Player Two
	static int** winCombos; // Holds all winning combinations
	static int numWinCombos; // Holds number of winning combinations

public:
	GameBoard(); // Default constructor that creates a new tic tac toe board
	bool switchTurn(); // Flips xTurn and returns new value
	bool playSpace(int pos); // Plays space if valid and returns true, otherwise returns false
	int checkForWinner(); // Returns 0 if game not concluded, 1 for Player One win 2 for Player Two win and 3 for a draw
};

#endif // !GAMEBOARD_H
