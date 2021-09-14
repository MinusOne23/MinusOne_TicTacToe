#include "UI.h"
#include <iostream>
#include<string>
using namespace std;

UI::UI() {
	xWins = oWins = draws = 0;
}

string UI::getSpotIcon(int boardVal, int pos) {
	if (boardVal == 0) {
		return to_string(pos);
	}

	return boardVal == 1 ? "X" : "Y";
}

bool UI::displayMenu()
{
	//Varibles
	int menuChoice = 0;

	do {
		//Displays Menu in a do-while statement
		cout << "================================\n"
			<< "WELCOME TO MINUSONE-TIC_TAC_TOE\n"
			<< "================================\n"
			<< "\t1 - START GAME\n"
			<< "\t2- INSTRUCTIONS\n"
			<< "\t3 - QUIT GAME\n"
			<< "================================\n"
			<< "PLEASE ENTER YOUR NUMBER CHOICE AND PRESS ENTER:";
		cin >> menuChoice;

		if (cin.fail()) {
			menuChoice = -1;
			cin.clear();
			cin.ignore(256, '\n');
		}

		switch (menuChoice)
		{
		case 1: // Start Game
			cout << "You Chose: Start Game\n";
			cout << "How many Rounds do you want to play:"; // Promts user for round limit
			cin >> numRounds;

			while (numRounds < 1) {
				cout << "Enter positive number of rounds: ";
				cin >> numRounds;
			}

			// initialize values on game start
			curRound = 1;
			xWins = 0;
			oWins = 0;
			draws = 0;
			return true;
		case 2: //Display instructions
			cout << "You Chose: Instructions\n";
			cout << endl;
			cout << "\t1) Players will take turn playing places on the board\n";
			cout << "\t2) First to 3 in a row (horizontal, vertical, or diagonal) wins\n";
			cout << "\t3) If the board is filled with no winner, the game ends in a draw\n";
			cout << "\t4) Every round, the starting player will alternate\n";
			cout << "\t5) To choose a spot to play, type the number corresponding to the spot on the screen\n";
			cout << endl;
			break;
		case 3: // End Program
			cout << "You Chose: End Program\n" << "Good Bye\n\n";
			return false;
		default:
			cout << endl << endl;
			cout << "*******************************\n";
			cout << "INVALID NUMBER PLEASE TRY AGAIN\n";
			cout << "*******************************\n";
			break;
		}
	}
	while (menuChoice != 3); // While menuChoice is not "End Program", repeat code untill valid choice is made

	return false;
};

//after correct placement, displayBoard is called
void UI::displayBoard(int * board) {
	cout << "\nCurrent Round : " << curRound << " of " << numRounds << endl;

	cout << endl;
	cout << "\t " << getSpotIcon(board[0], 0) << " | " << getSpotIcon(board[1], 1) << " | " << getSpotIcon(board[2], 2) << endl
		 <<	 "\t------------\n"
		 <<	 "\t " << getSpotIcon(board[3], 3) << " | " << getSpotIcon(board[4], 4) << " | " << getSpotIcon(board[5], 5) << endl
		 <<	 "\t------------\n"
		 <<	 "\t " << getSpotIcon(board[6], 6) << " | " << getSpotIcon(board[7], 7) << " | " << getSpotIcon(board[8], 8) << endl;
	cout << endl;

};

//Displays Scoreboard on call after round finishes
void UI::scoreBoard() {
	cout << "\nScoreBoard:"
		<< "\n-------------"
		<< "\nPlayer 1: " << xWins
		<< "\nPlayer 2: " << oWins
		<< "\nDraws: " << draws
		<< "\n-------------\n";
}

void UI::addResult(int result) {
	switch (result) {
	case 1:
		xWins++;
		break;
	case 2:
		oWins++;
		break;
	case 3:
		draws++;
		break;
	}
}

void UI::incrementRound() {
	curRound++;
}

int UI::getCurRound() {
	return curRound;
}

int UI::getNumRounds() {
	return numRounds;
}
