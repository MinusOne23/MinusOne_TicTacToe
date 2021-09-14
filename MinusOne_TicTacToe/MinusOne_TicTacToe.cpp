// MinusOne_TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UI.h"
#include "GameBoard.h"
using namespace std;

int main()
{
    //Class Objectives
    UI ui;
    GameBoard game;

    //Varibles
    int numRounds, position;
    int curRound = 1;
    int* board = game.getBoard();
    int xWins = 0,oWins = 0,draw = 0;
    
    //Start program
    numRounds = ui.displayMenu(); // Displays: menu
                                  // Returns: numRounds

    while (curRound <= numRounds) {
        int gamestate = game.checkForWinner();
        ui.displayBoard(curRound, numRounds, board); // Displays: Game Board
        while (gamestate == 0) {
            bool turn = game.getTurn();
            do {
                if (turn == 1) {
                    cout << "\nPlayer 1(1) Choose your Square: ";
                }
                else {
                    cout << "\nPlayer 2(2) Choose your Square: ";
                }
                cin >> position;
            }
            while (!(game.playSpace(position)));
            game.switchTurn();
            gamestate = game.checkForWinner();
            ui.displayBoard(curRound, numRounds, board); // Displays: Game Board
        }
        switch (gamestate)
        {
        case 1:
            cout << "Player 1 WINS Round " << curRound << " out of " << numRounds;
            xWins++;
            break;
        case 2:
            cout << "Player 2 WINS Round " << curRound << " out of " << numRounds;
            oWins++;
            break;
        case 3:
            cout << "No winner in Round " << curRound << " out of " << numRounds;
            draw++;
            break;
        }
        curRound++;
        ui.scoreBoard(xWins, oWins, draw);
        game.resetBoard(curRound %2 == 1);
    }
}
