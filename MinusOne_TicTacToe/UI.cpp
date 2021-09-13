#include "UI.h"
#include <iostream>
using namespace std;

void UI::displayMenu()
{
	//Varibles
	int menuChoice = 0;

	//Displays Menu in a do-while statement
	do {
		cout << "================================\n";
		cout << "WELCOME TO MINUSONE-TIC_TAC_TOE\n" << "================================";
		cout << endl
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
			break;
		case 2: //Display instructions
			break;
		case 3: // End Program
			break;
		default:
			cout << "\n\n********************************\n" << "INVALID NUMBER PLEASE TRY AGAIN\n" << "********************************\n";
		}
	}
	while (menuChoice != 3); // While menuChoice is not "End Program", repeat code untill valid choice is made
};
