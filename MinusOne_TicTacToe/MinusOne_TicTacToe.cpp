// MinusOne_TicTacToe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "UI.h"
#include "GameBoard.h"
using namespace std;

int main()
{
    //Class Objects
    UI ui;
    GameBoard game;

    //Variables
    int position;
    int* board = game.getBoard();
    
    //Start program
    bool playGame = ui.displayMenu(); // Displays: menu

    while (playGame) {
        game.resetBoard();
        while (ui.getCurRound() <= ui.getNumRounds()) {
            int gamestate = game.checkForWinner();
            ui.displayBoard(board); // Displays: Game Board
            while (gamestate == 0) {
                bool turn = game.getTurn();

                if (turn == 1) {
                    cout << "Player 1(X) Choose your Square: ";
                }
                else {
                    cout << "Player 2(Y) Choose your Square: ";
                }
                cin >> position;

                while (cin.fail()) {
                    cin.clear();
                    cin.ignore(256, '\n');

                    cout << "Enter valid position: ";
                    cin >> position;
                }

                while (!game.playSpace(position)) {
                    cout << "Enter valid position: ";
                    cin >> position;

                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore(256, '\n');

                        cout << "Enter valid position: ";
                        cin >> position;
                    }
                }
                game.switchTurn();
                gamestate = game.checkForWinner();
                ui.displayBoard(board); // Displays: Game Board
            }
            switch (gamestate)
            {
            case 1:
                cout << "\n====================================== ";
                cout << "\n    Player 1 WINS Round " << ui.getCurRound() << " out of " << ui.getNumRounds();
                cout << "\n====================================== ";
                break;
            case 2:
                cout << "\n====================================== ";
                cout << "\n    Player 2 WINS Round " << ui.getCurRound() << " out of " << ui.getNumRounds();
                cout << "\n====================================== ";
                break;
            case 3:
                cout << "\n====================================== ";
                cout << "\n    No winner in Round " << ui.getCurRound() << " out of " << ui.getNumRounds();
                cout << "\n====================================== ";
                break;
            }
            ui.addResult(gamestate);
            ui.incrementRound();
            ui.scoreBoard();
            game.resetBoard(ui.getCurRound() % 2 == 1);
        }

        cout << endl << endl;
        playGame = ui.displayMenu();
    }

    system("pause");
    return 0;
}
