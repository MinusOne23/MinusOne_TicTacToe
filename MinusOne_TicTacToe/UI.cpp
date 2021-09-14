#include "UI.h"
#include <iostream>
#include<string>
using namespace std;

int UI::displayMenu()
{
	//Varibles
	int menuChoice = 0;
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

	do {
		
		switch (menuChoice)
		{
		case 1: // Start Game
			cout << "You Chosed: Start Game\n";
			cout << "How many Rounds do you want to play:"; // Promts user for round limit
			cin >> numRounds;
			return numRounds;
		case 2: //Display instructions
			cout << "\n\nADD INSTRUCTIONS HERE\n\n"; //ADD INSTRUCTIONS HERE<========================================================================
			break;
		case 3: // End Program
			cout << "You Chosed: End Program\n" << "Good Buy\n\n\n";
			exit(0);
		default:
			cout << "\n\n********************************\n" << "INVALID NUMBER PLEASE TRY AGAIN\n" << "********************************\n";
		}
	}
	while (menuChoice != 3 ); // While menuChoice is not "End Program", repeat code untill valid choice is made
	
};

//after correct placement, displayBoard is called
void UI::displayBoard(int curRound,int numRounds, int * board) {
	string gameBoard[9];

	for (int i = 0; i < 9; i++) {
		gameBoard[i] = board[i];
	}

	for (int i = 0; i < 9; i++) {
		if (board[i] == 1) {
			gameBoard[i] = "X";
		}
		else if(board[i] == 2) {
			gameBoard[i] = "O";

		}
		else {
			gameBoard[i] = to_string(i);
		}
	}
	cout << "\nCurrent Round : " << curRound << " of " << numRounds << endl << endl;
	cout << "\n\n\t " << gameBoard[0] << " | " << gameBoard[1] << " | " << gameBoard[2] << endl
		 << "\t------------\n"
		 << "\t " << gameBoard[3] << " | " << gameBoard[4] << " | " << gameBoard[5] << endl
		 << "\t------------\n"
		 << "\t " << gameBoard[6] << " | " << gameBoard[7] << " | " << gameBoard[8] << endl;

};

//Displays Scoreboard on call after round finishes
void UI::scoreBoard(int xWins, int oWins, int draw) {
	cout << "\n\nScoreBoard:"
		<< "\n-------------"
		<< "\nPlayer 1: " << xWins
		<< "\nPlayer 2: " << oWins
		<< "\n   Draws: " << draw
		<< "\n-------------\n";
}
