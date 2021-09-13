// MinusOne_TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UI.h"
#include "GameBoard.h"
using namespace std;

int main()
{
    UI ui;
    //Varibles
    int numRounds;

    numRounds = ui.displayMenu(); // Displays menu and returns numRounds
    cout << "numRounds =" << numRounds;

    return 0;
}
