#pragma once
#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <iostream>

using namespace std;

class GameBoard {
private:
	const static int winCombos[8][3]; // Holds all winning combinations
	const static int numWinCombos; // Holds number of winning combinations
	int* board; // Holds current game
	bool xTurn; // If true, Player One's turn, false Player Two

public:
	GameBoard(); // Default constructor that creates a new tic tac toe board
	~GameBoard(); // Destructor to deallocate the board array
	int* getBoard(); //Accessor
	bool getTurn(); //Accessor
	bool switchTurn(); // Flips xTurn and returns new value
	bool playSpace(int pos); // Plays space if valid and returns true, otherwise returns false
	int checkForWinner(); // Returns 0 if game not concluded, 1 for Player One win 2 for Player Two win and 3 for a draw
	void resetBoard(bool newXTurn = true); // Resets all board spaces to empty and assigns newXTurn to xTurn
};

#endif // !GAMEBOARD_H
