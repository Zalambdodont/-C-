// TestingASCII.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <random>
#include <ctime>

using namespace std;

bool playerTurn = true;			//Needed for AI, not yet in-game.
char player = 'O';
char winner = 'W';		        //GameLoop in main();
int _column;					//Used in Input(); (odd numbers 1-13).


void printBoard();				//Prints the char Board[15][15].
void Input();					
void checkVertical(int row);	//Checking Y-axis.
bool checkWin();				//Used in togglePlayer();
void togglePlayer();
void prize();

/***********************- RANDOM GENERATOR -*******************************/

int getBetween(int min, int max) {
	static mt19937 generator(time(NULL));
	uniform_int_distribution<int> dis(min, max);
	return dis(generator);
}		

/**************************************************************************/

char Board[15][15] = {	 '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+',
						 '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',
						 '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+',
						 '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',
						 '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+',
						 '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',
						 '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+',
						 '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',
						 '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+',
						 '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',
						 '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+',
						 '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',
						 '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+',
						 '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|', ' ', '|',
						 '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', '-', '+', }; 

void printBoard() {

	cout << " LuffarSchack!" << endl << endl;
	cout << " 1 2 3 4 5 6 7" << endl;

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 15; j++) {
			cout << Board[i][j];
		}
		cout << endl;
	}
}

void Input() {

	while (playerTurn == true) {

		if (!checkWin()) {

			if (GetAsyncKeyState('1')) {  
				Sleep(300);
				_column = 1;
				checkVertical(_column);
				system("cls");
				printBoard();
			}
			if (GetAsyncKeyState('2')) {
				Sleep(300);
				_column = 3;
				checkVertical(_column);
				system("cls");
				printBoard();
			}
			if (GetAsyncKeyState('3')) {
				Sleep(300);
				_column = 5;
				checkVertical(_column);
				system("cls");
				printBoard();
			}
			if (GetAsyncKeyState('4')) {
				Sleep(300);
				_column = 7;
				checkVertical(_column);
				system("cls");
				printBoard();
			}
			if (GetAsyncKeyState('5')) {
				Sleep(300);
				_column = 9;
				checkVertical(_column);
				system("cls");
				printBoard();
			}
			if (GetAsyncKeyState('6')) {
				Sleep(300);
				_column = 11;
				checkVertical(_column);
				system("cls");
				printBoard();
			}
			if (GetAsyncKeyState('7')) {
				Sleep(300);
				_column = 13;
				checkVertical(_column);
				system("cls");
				printBoard();
			}

		}
		if (checkWin()) {
			playerTurn = false;
			winner = 'F';
		}
	}
}

void checkVertical(int column) {

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

bool checkWin() {

	for(int i = 1; i <= 13; i += 2) {
		for(int j = 1; j <= 13; j +=2) {
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

void togglePlayer() {

	checkWin();

	if(player == 'O') {
		player = 'X';
	}
	else if(player == 'X') {
		player = 'O';
	}
}

void prize() {

	if (player == 'X') {
		cout << "Grattis spelare O!" << endl;
	}
	else if (player == 'O') {
		cout << "Grattis spelare X!" << endl;
	}
}

/***********************- MAIN -*******************************/

int main() {

	printBoard();

	while (winner == 'W') {
		Input();
	}
	
	prize();

	system("PAUSE");

	return 0;
}
