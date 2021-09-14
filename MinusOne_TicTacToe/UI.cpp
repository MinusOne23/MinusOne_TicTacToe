#include "UI.h"
#include <iostream>
using namespace std;

int UI::displayMenu()
{
	//Varibles
	int menuChoice = 0;
	//Displays Menu in a do-while statement
	do {
		cout << "================================\n"
			 << "WELCOME TO MINUSONE-TIC_TAC_TOE\n" 
			 << "================================\n"
			 << "\t1 - START GAME\n"
			 << "\t2- INSTRUCTIONS\n"
			 << "\t3 - QUIT GAME\n"
			 << "================================\n"
			 << "PLEASE ENTER YOUR NUMBER CHOICE AND PRESS ENTER:";

		cin >> menuChoice;

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
	while (menuChoice != 3); // While menuChoice is not "End Program", repeat code untill valid choice is made
};

//after correct placement, displayBoard is called
void UI::displayBoard(int curRound,int numRounds, int * board) {
	cout << "\nCurrent Round : " << curRound << " of " << numRounds << endl << endl;
	cout << "\n\n\t " << board[0] << " | " << board[1] << " | " << board[2] << endl
		 << "\t------------\n"
		 << "\t " << board[3] << " | " << board[4] << " | " << board[5] << endl
		 << "\t------------\n"
		 << "\t " << board[6] << " | " << board[7] << " | " << board[8] << endl;

};

//Displays Scoreboard on call after round finishes
void UI::scoreBoard(int xWins, int oWins, int draw) {
	cout << "\nScoreBoard:"
		<< "\n-------------"
		<< "\nPlayer 1: " << xWins
		<< "\nPlayer 2: " << oWins
		<< "\nDraws: " << draw
		<< "\n-------------\n";
}
