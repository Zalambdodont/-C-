#pragma once

class Game
{
public:
	Game();
	~Game();


/***********************- PUBLIC VARIABLES -********************/

	bool playerTurn = true;			
	char player = 'O';					
	char value = ' '; //temporary for testing.

/***************************************************************/
/***********************- BOARD -*******************************/
	
	void printBoard(int row_size, int column_size);
	void printBoardLines(int row_size);
	

/***************************************************************/
/***********************- PLAYER -******************************/

	//void Input();
	void togglePlayer();


/***************************************************************/
/***********************- CHECK WIN -***************************/

	//void checkVertical(int row);	
	//bool checkWin();				
	
/***************************************************************/

};

