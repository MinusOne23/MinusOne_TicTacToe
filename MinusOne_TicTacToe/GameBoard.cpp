#include "GameBoard.h"

using namespace std;

// Outlines all winning line combinations
const int GameBoard::winCombos[8][3] = {
	{0,1,2},
	{3,4,5},
	{6,7,8},
	{0,3,6},
	{1,4,7},
	{2,5,8},
	{0,4,8},
	{2,4,6}
};

const int GameBoard::numWinCombos = 8;

GameBoard::GameBoard() {
	board = new int[9];

	// initializes board to be completely empty
	for (int i = 0; i < 9; i++) {
		board[i] = 0;
	}

	// defaults to starting on xTurn
	xTurn = true;
}

GameBoard::~GameBoard() { //Deconstructror
	delete[] board;
}

int* GameBoard::getBoard() { //Accessor
	return board;
};

bool GameBoard::getTurn() { //Accessor
	return xTurn;
};

bool GameBoard::switchTurn() {
	xTurn = !xTurn;
	return xTurn;
}

bool GameBoard::playSpace(int pos) {
	if (pos < 0 || pos > 8 || board[pos] != 0) {
		return false;
	}

	if (xTurn) {
		board[pos] = 1;
	}
	else {
		board[pos] = 2;
	}

	return true;
}

int GameBoard::checkForWinner() {
	for (int i = 0; i < numWinCombos; i++) {
		// retrieves from the board the 3 spaces in the winning combination
		int a = board[winCombos[i][0]];
		int b = board[winCombos[i][1]];
		int c = board[winCombos[i][2]];

		if (a != 0 && a == b && b == c) {
			// returns the winner
			return a;
		}
	}

	bool foundEmpty = false;
	for (int i = 0; i < 9; i++) {
		if (board[i] == 0) {
			foundEmpty = true;
			break;
		}
	}

	// if empty spot found, game not concluded
	if (foundEmpty) {
		return 0;
	}

	// if no empty spot found, game ends in a draw
	return 3;
}

void GameBoard::resetBoard(bool newXTurn) {
	// set every space on board to empty
	for (int i = 0; i < 9; i++) {
		board[i] = 0;
	}

	// assigns new value to xTurn
	xTurn = newXTurn;
}