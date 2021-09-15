#include "GameBoard.h"

using namespace std;

// Outlines all winning line combinations
const int GameBoard::winCombos[8][3] = {
	{0,1,2}, //Top horizontal win
	{3,4,5}, //Middle horizontal win
	{6,7,8}, //Bottom horozontal win
	{0,3,6}, //Left Vertical win
	{1,4,7}, //Middle Verticle win
	{2,5,8}, //Right Verticle win
	{0,4,8}, // Left-to-Right Diagnal win 
	{2,4,6} //Right-to-left Diagnal win
};

const int GameBoard::numWinCombos = 8;

GameBoard::GameBoard() { // Constructor
	board = new int[9]; // creates an array called board with a size of 9 integers

	// initializes board to be completely empty
	for (int i = 0; i < 9; i++) { // loops through the array assining each index to be zero
		board[i] = 0;
	}

	// defaults to starting on xTurn
	xTurn = true;
}

GameBoard::~GameBoard() { //Destructror
	delete[] board;
}

int* GameBoard::getBoard() { //Accessor
	return board;
};

bool GameBoard::getTurn() { //Accessor
	return xTurn;
};

bool GameBoard::switchTurn() { //Switches who's turn it is;PLayer 1 or PLayer 2
	xTurn = !xTurn; // xTurn is now the opposite. If True then false, or if false now true
	return xTurn;
}

bool GameBoard::playSpace(int pos) {
	if (pos < 0 || pos > 8 || board[pos] != 0) { //If the iser input(pos) is outside the scope of between 0 through 8 then return false
		return false; // return false = input is invalid
	}

	if (xTurn) { // If xTurn is true then its player 1's turn 
		board[pos] = 1;
	}
	else {// If xTurn is false then its player 2's turn 
		board[pos] = 2;
	}

	return true; //return true = input is valid
}

int GameBoard::checkForWinner() {
	//Varibles
	bool foundEmpty = false;

	for (int i = 0; i < numWinCombos; i++) { //Loop going throuhg all winning combinations
		// retrieves from the board the 3 spaces in the winning combination
		int a = board[winCombos[i][0]]; 
		int b = board[winCombos[i][1]];
		int c = board[winCombos[i][2]];

		//If all 3 squares from the winning combonations contain a 1(player 1) or 2(player 2) then there is a winner
		if (a != 0 && a == b && b == c) {
			// returns the winner
			return a; //return the value of who won, 1(player 1) or 2 (player 2)
		}
	}

	for (int i = 0; i < 9; i++) { // If there is an empty space in one of the winning combos then break and move on to next winning combo
		if (board[i] == 0) { // empty space is categorized as a 0 on the board, the displayBoard function dosnt display the 0's, 1's, or 2's
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