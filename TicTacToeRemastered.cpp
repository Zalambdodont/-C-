// TicTacToeRemastered.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <String>
#include <Vector>
#include "Game.h"

using namespace std;


/***********************- MAIN -*******************************/
int main()
{
	Game TicTacToe;

/*******-SET BOARD- ********/
	int column_size;
	int row_size;

	cout << "Enter the board column size: \n";
	cin >> column_size;
	cout << "Enter the board row size: \n";
	cin >> row_size;
/**************************/

	TicTacToe.printBoard(row_size, column_size);

	return 0;
}
/**************************************************************/