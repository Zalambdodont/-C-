#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <random>
#include <ctime>
#include "Game.h"

using namespace std;

Game::Game()
{
}


Game::~Game()
{
}

void Game::printBoardLines(int row_size){
	cout << " ";
	for (int row_loop = 0; row_loop < row_size; row_loop++) {
		cout << " ---";
	}
}

void Game::printBoard(int row_size, int column_size){
	system("CLS");

	vector<vector<char> > aVector(column_size, vector<char>(row_size, value));
	
		printBoardLines(row_size);

	for(int column_loop = 0; column_loop < column_size; column_loop++) {
			cout << endl;
		for(int row_loop = 0; row_loop < row_size; row_loop++) {
			cout << " | " << aVector[column_loop][row_loop];
		}
		cout << " | " << endl;
		printBoardLines(row_size);
	}
}

/*
void Game::Input() {

	while (playerTurn == true) {

		if (!checkWin()) {

			if (GetAsyncKeyState('1')) {
				Sleep(300);
				_column = 1;
				checkVertical(_column);
				system("cls");
			}
			if (GetAsyncKeyState('2')) {
				Sleep(300);
				_column = 3;
				checkVertical(_column);
				system("cls");
			}
			if (GetAsyncKeyState('3')) {
				Sleep(300);
				_column = 5;
				checkVertical(_column);
				system("cls");
			}
			if (GetAsyncKeyState('4')) {
				Sleep(300);
				_column = 7;
				checkVertical(_column);
				system("cls");
			}
			if (GetAsyncKeyState('5')) {
				Sleep(300);
				_column = 9;
				checkVertical(_column);
				system("cls");
			}
			if (GetAsyncKeyState('6')) {
				Sleep(300);
				_column = 11;
				checkVertical(_column);
				system("cls");
			}
			if (GetAsyncKeyState('7')) {
				Sleep(300);
				_column = 13;
				checkVertical(_column);
				system("cls");
			}

		}
	}
}
*/

/*
void Game::checkVertical(int column) {

	int row = 13; //The first X or O will always be on row 13.
	bool checkVertical = false;

	while (checkVertical == false && row >= 1) {

		if (Board[row][column] != 'X' && Board[row][column] != 'O' && Board[row][column] == ' ') {
			Board[row][column] = player;
			togglePlayer();
			checkVertical = true;
		}
		else {
			row -= 2;
		}
	}
}
*/

/*
bool Game::checkWin() {

	for (int i = 1; i <= 13; i += 2) {
		for (int j = 1; j <= 13; j += 2) {
			if ((Board[i][j] == 'X' && Board[i][j + 2] == 'X' && Board[i][j + 4] == 'X' && Board[i][j + 6] == 'X') || (Board[i][j] == 'O' && Board[i][j + 2] == 'O' && Board[i][j + 4] == 'O' && Board[i][j + 6] == 'O')) {	//X-axis(1)		
				cout << "vinst via X-axis(1)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i][j + 2] == 'X' && Board[i][j + 4] == 'X' && Board[i][j - 2] == 'X') || (Board[i][j] == 'O' && Board[i][j + 2] == 'O' && Board[i][j + 4] == 'O' && Board[i][j - 2] == 'O')) { //X-axis(2)	
				cout << "vinst via X-axis(2)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i][j + 2] == 'X' && Board[i][j - 2] == 'X' && Board[i][j - 4] == 'X') || (Board[i][j] == 'O' && Board[i][j + 2] == 'O' && Board[i][j - 2] == 'O' && Board[i][j - 4] == 'O')) {	//X-axis(3)	   
				cout << "vinst via X-axis(3)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i][j - 2] == 'X' && Board[i][j - 4] == 'X' && Board[i][j - 6] == 'X') || (Board[i][j] == 'O' && Board[i][j - 2] == 'O' && Board[i][j - 4] == 'O' && Board[i][j - 6] == 'O')) {	//X-axis(4)
				cout << "vinst via X-axis(4)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i - 2][j] == 'X' && Board[i - 4][j] == 'X' && Board[i - 6][j] == 'X') || (Board[i][j] == 'O' && Board[i - 2][j] == 'O' && Board[i - 4][j] == 'O' && Board[i - 6][j] == 'O')) {	//Y-axis(1)    
				cout << "vinst via Y-axis(1)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i - 2][j] == 'X' && Board[i - 4][j] == 'X' && Board[i + 2][j] == 'X') || (Board[i][j] == 'O' && Board[i - 2][j] == 'O' && Board[i - 4][j] == 'O' && Board[i + 2][j] == 'O')) {	//Y-axis(2) 
				cout << "vinst via Y-axis(2)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i - 2][j] == 'X' && Board[i + 2][j] == 'X' && Board[i + 4][j] == 'X') || (Board[i][j] == 'O' && Board[i - 2][j] == 'O' && Board[i + 2][j] == 'O' && Board[i + 4][j] == 'O')) {	//Y-axis(3) 
				cout << "vinst via Y-axis(3)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i + 2][j] == 'X' && Board[i + 4][j] == 'X' && Board[i + 6][j] == 'X') || (Board[i][j] == 'O' && Board[i + 2][j] == 'O' && Board[i + 4][j] == 'O' && Board[i + 6][j] == 'O')) {	//Y-axis(4) 
				cout << "vinst via Y-axis(4)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i - 2][j + 2] == 'X' && Board[i - 4][j + 4] == 'X' && Board[i - 6][j + 6] == 'X') || (Board[i][j] == 'O' && Board[i - 2][j + 2] == 'O' && Board[i - 4][j + 4] == 'O' && Board[i - 6][j + 6] == 'O')) {	//XY1(1) 
				cout << "vinst via XY1(1)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i - 2][j + 2] == 'X' && Board[i - 4][j + 4] == 'X' && Board[i + 2][j - 2] == 'X') || (Board[i][j] == 'O' && Board[i - 2][j + 2] == 'O' && Board[i - 4][j + 4] == 'O' && Board[i + 2][j - 2] == 'O')) {	//XY1(2)
				cout << "vinst via XY1(2)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i - 2][j + 2] == 'X' && Board[i + 2][j - 2] == 'X' && Board[i + 4][j - 4] == 'X') || (Board[i][j] == 'O' && Board[i - 2][j + 2] == 'O' && Board[i + 2][j - 2] == 'O' && Board[i + 4][j - 4] == 'O')) {	//XY1(3)
				cout << "vinst via XY1(3)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i + 2][j - 2] == 'X' && Board[i + 4][j - 4] == 'X' && Board[i + 6][j - 6] == 'X') || (Board[i][j] == 'O' && Board[i + 2][j - 2] == 'O' && Board[i + 4][j - 4] == 'O' && Board[i + 6][j - 6] == 'O')) {	//XY1(4)
				cout << "vinst via XY1(4)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i - 2][j - 2] == 'X' && Board[i - 4][j - 4] == 'X' && Board[i - 6][j - 6] == 'X') || (Board[i][j] == 'O' && Board[i - 2][j - 2] == 'O' && Board[i - 4][j - 4] == 'O' && Board[i - 6][j - 6] == 'O')) {	//XY2(1) 
				cout << "vinst via XY2(1)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i - 2][j - 2] == 'X' && Board[i - 4][j - 4] == 'X' && Board[i + 2][j + 2] == 'X') || (Board[i][j] == 'O' && Board[i - 2][j - 2] == 'O' && Board[i - 4][j - 4] == 'O' && Board[i + 2][j + 2] == 'O')) {	//XY2(2)
				cout << "vinst via XY2(2)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i - 2][j - 2] == 'X' && Board[i + 2][j + 2] == 'X' && Board[i + 4][j + 4] == 'X') || (Board[i][j] == 'O' && Board[i - 2][j - 2] == 'O' && Board[i + 2][j + 2] == 'O' && Board[i + 4][j + 4] == 'O')) {	//XY2(3)
				cout << "vinst via XY2(3)" << endl;
				return true;
			}
			if ((Board[i][j] == 'X' && Board[i + 2][j + 2] == 'X' && Board[i + 4][j + 4] == 'X' && Board[i + 6][j + 6] == 'X') || (Board[i][j] == 'O' && Board[i + 2][j + 2] == 'O' && Board[i + 4][j + 4] == 'O' && Board[i + 6][j + 6] == 'O')) {	//XY2(4)
				cout << "vinst via XY2(4)" << endl;
				return true;
			}

		}
	}
	return false;
}
*/

void Game::togglePlayer() {

	if (player == 'O') {
		player = 'X';
	}
	else if (player == 'X') {
		player = 'O';
	}
}


