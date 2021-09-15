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
    int position; // user input [0-8] - position on the game board
    int* board = game.getBoard(); // used to display game board
    
    //Start program
    bool playGame = ui.displayMenu(); // Displays: menu

    while (playGame) {
        game.resetBoard(); // Starts game by reseating the gameboard to default position
        while (ui.getCurRound() <= ui.getNumRounds()) { // While the current round has not reached the total number of rounds repeat code
            int gamestate = game.checkForWinner(); //initialize gamestate by checking if there is a winner. If no winner and no draw, then the game is still in progress
            ui.displayBoard(board); // Displays: Game Board

            while (gamestate == 0) { //While the gamestate is no winner yet, continue looping
                bool turn = game.getTurn();

                if (turn == 1) {//If the turn is 1 then its player 1's turn
                    cout << "Player 1(X) Choose your Square: ";
                }
                else {//Else its player 2's turn
                    cout << "Player 2(Y) Choose your Square: ";
                }
                cin >> position;

                while (cin.fail()) { //while position is not an integer
                    cin.clear();//Clear the user input
                    cin.ignore(256, '\n');//Ignore any characters given including white space

                    cout << "Enter valid position: ";
                    cin >> position;
                }

                while (!game.playSpace(position)) { //While the playSpace function returns a False
                    cout << "Enter valid position: ";
                    cin >> position;

                    while (cin.fail()) { //while position is not an integer
                        cin.clear(); //Clear the user input
                        cin.ignore(256, '\n'); //Ignore any characters given including white space

                        cout << "Enter valid position: ";
                        cin >> position;
                    }
                }
                game.switchTurn();//Switch turn to let the next player play
                gamestate = game.checkForWinner(); //Check to see if there is a wining condition on the board
                ui.displayBoard(board); // Displays: Game Board
            }
            switch (gamestate) //Swicth statement for gamestate;
            {
            case 1: //Player 1
                cout << "\n====================================== ";
                cout << "\n    Player 1 WINS Round " << ui.getCurRound() << " out of " << ui.getNumRounds(); // Displays current round out of total rounds
                cout << "\n====================================== ";
                break;
            case 2: //Player 2
                cout << "\n====================================== ";
                cout << "\n    Player 2 WINS Round " << ui.getCurRound() << " out of " << ui.getNumRounds();// Displays current round out of  total rounds
                cout << "\n====================================== ";
                break;
            case 3: //Draw
                cout << "\n====================================== ";
                cout << "\n    No winner in Round " << ui.getCurRound() << " out of " << ui.getNumRounds();// Displays current round out of  total rounds
                cout << "\n====================================== ";
                break;
            }
            ui.addResult(gamestate); // adds the results to xWin, oWin, or Draw
            ui.incrementRound(); // increments the round counter
            ui.scoreBoard(); // Displays the updated scoreboard
            game.resetBoard(ui.getCurRound() % 2 == 1); //resets the board, but switching who plays first
        } //End of While Loop == round Limit Reached

        cout << endl << endl;
        playGame = ui.displayMenu(); // Displays the main Menu to ask user to play again, see instructions, or exit
    }//End of playGame while Loop == user chose 3 in menu to exit program
    system("pause");
    return 0;
}
