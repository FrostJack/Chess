#pragma once
#include "Piece.h"
const char f1 = ';';
const char f2 = '<';
const char f3 = '=';
const char f4 = '>';

class Chess
{
	Piece board[9][9];
	bool isWhite;
public:
	Chess();
	void fromFile(char* fname);
	bool canMove(int x1, int y1, int x2, int y2);
	bool underAttack(int x, int y, bool white);
	bool toFile(char* fname);
	bool white();
	Piece getPiece(int x, int y);
	int findKing(bool white, int &y);
	void switchTurn();
	void move(int x1, int y1, int x2, int y2);
	void place(int x, int y, Piece p);
	void printCell(int x, int y);
	void printBoard();
	void printTurn();
	bool gameEnd();
	void menu();
	bool turn(char ch);
	void gameStart();
	void game();
	void printMove(int x1, int y1, int x2, int y2, Piece x);
	void readTurn(int &x1, int &y1, int &x2, int &y2, char &ch);
	void printWinner();
};



