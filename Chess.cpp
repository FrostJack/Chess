#include "stdafx.h"
#include "Chess.h"
#include "Console.h"
#include <conio.h>

Chess::Chess()
{
	isWhite = 1;
	for (int i = 1; i < 9; ++i) {
		board[i][2] = Piece('p', 1);
		board[i][7] = Piece('p', 0);
		board[i][3] = Piece();
		board[i][4] = Piece();
		board[i][5] = Piece();
		board[i][6] = Piece();
	}
	board[1][1] = board[8][1] = Piece('r', 1);
	board[1][8] = board[8][8] = Piece('r', 0);
	board[2][1] = board[7][1] = Piece('h', 1);
	board[2][8] = board[7][8] = Piece('h', 0);
	board[3][1] = board[6][1] = Piece('b', 1);
	board[3][8] = board[6][8] = Piece('b', 0);
	board[4][1] = Piece('q', 1);
	board[5][1] = Piece('k', 1);
	board[4][8] = Piece('q', 0);
	board[5][8] = Piece('k', 0);
}

void Chess::fromFile(char* fname) {
	FILE * f;
	if ((f = fopen(fname, "rt")) == nullptr) {
		printf("WRONG INPUT FILE");
		exit(6);
	}
	char c;
	c = fgetc(f);
	if (c == 'w')
		isWhite = 1;
	else
		isWhite = 0;
	fgetc(f);
	for (int i = 8; i > 0; --i) {
		for (int j = 1; j < 9; ++j) {
			c = fgetc(f);
			if (c == '-') {
				board[j][i] = Piece();
				fgetc(f);
			}
			else
				if (c == 'w')
					board[j][i] = Piece(fgetc(f), 1);
				else
					board[j][i] = Piece(fgetc(f), 0);
			fgetc(f);
		}
		fgetc(f);
	}
	fclose(f);
}

bool Chess::canMove(int x1, int y1, int x2, int y2) {
	int col = abs(x1 - x2);
	int row = abs(y1 - y2);
	int k1, k2, k;
	if ((col == 0) && (row == 0))
		return false;
	Piece x = board[x1][y1];
	Piece y = board[x2][y2];
	if (x.getName() == ' ')
		return false;
	if (!x.canReach(x1, y1, x2, y2))
		return false;
	if (x.sameColour(y))
		return false;
	switch (x.getName()) {
	case 'p':
		if (col == 0)
			if (y.getName() != ' ')
				return false;
			else
				if (row == 2)
					return (board[(x1 + x2) / 2][(y1 + y2) / 2].getName() == ' ');
				else
					return true;
		else
			return (y.getName() != ' ');
	case 'h':
		return true;
	case 'b':
		k1 = (-2) * (x2 < x1) + 1;
		k2 = (-2) * (y2 < y1) + 1;
		for (int i = 0; col - i - 1 > 0; ++i) {
			x1 += k1;
			y1 += k2;
			if (board[x1][y1].getName() != ' ')
				return false;
		}
		return true;
	case 'r':
		if (col == 0) {
			k = (-2)*(y2 < y1) + 1;
			for (int i = 0; row - i - 1 > 0; ++i) {
				y1 += k;
				if (board[x1][y1].getName() != ' ')
					return false;
			}
		}
		else {
			k = (-2)*(x2 < x1) + 1;
			for (int i = 0; col - i - 1 > 0; ++i) {
				x1 += k;
				if (board[x1][y1].getName() != ' ')
					return false;
			}
		}
		return true;
	case 'q':
		if (col == 0) {
			k = (-2)*(y2 < y1) + 1;
			for (int i = 0; row - i - 1 > 0; ++i) {
				y1 += k;
				if (board[x1][y1].getName() != ' ')
					return false;
			}
		}
		else
			if (row == 0) {
				k = (-2)*(x2 < x1) + 1;
				for (int i = 0; col - i - 1 > 0; ++i) {
					x1 += k;
					if (board[x1][y1].getName() != ' ')
						return false;
				}
			}
		k1 = (-2) * (x2 < x1) + 1;
		k2 = (-2) * (y2 < y1) + 1;
		for (int i = 0; col - i - 1 > 0; ++i) {
			x1 += k1;
			y1 += k2;
			if (board[x1][y1].getName() != ' ')
				return false;
		}
		return true;
	case 'k':
		if (underAttack(x2, y2, x.isWhite()))
			return false;
		move(x1, y1, x2, y2);
		if (underAttack(x2, y2, x.isWhite())) {
			board[x1][y1] = x;
			board[x2][y2] = y;
			return false;
		}
		board[x1][y1] = x;
		board[x2][y2] = y;
		return true;
	default:
		cout << "recieved wrong piece name";
		exit(4);
	}
}

bool Chess::underAttack(int x, int y, bool white) {
	for (int i = 1; i < 9; ++i)
		for (int j = 1; j < 9; ++j) {
			if ((board[i][j].getName() != ' ') && (white != board[i][j].isWhite()))
				if (board[i][j].getName() == 'k')
					if (board[i][j].canReach(i, j, x, y))
						return true;
					else;
				else
					if (board[i][j].getName() == 'p')
						if ((board[i][j].canReach(i, j, x, y)) && (i != x))
							return true;
						else;
					else
						if (canMove(i, j, x, y))
							return true;
		}
	return false;
}

bool Chess::toFile(char* fname) {
	FILE * f;
	if ((f = fopen(fname, "wt")) == nullptr)
		return false;
	if (isWhite)
		fputc('w', f);
	else
		fputc('b', f);
	fputc('\n', f);
	for (int i = 8; i > 0; --i) {
		for (int j = 1; j < 9; ++j) {
			if (board[j][i].getName() == ' ') {
				fputc('-', f);
				fputc('-', f);
			}
			else {
				if (board[j][i].isWhite())
					fputc('w', f);
				else
					fputc('b', f);
				fputc(board[j][i].getName(), f);
			}
			fputc(' ', f);
		}
		fputc('\n', f);
	}
	fclose(f);
	return true;
}

Piece Chess::getPiece(int x, int y) {
	return board[x][y];
}

bool Chess::white() {
	return (isWhite);
}

void Chess::printCell(int x, int y) {
	char c1, c2;
	Piece f = board[x][y];
	if (!f.isWhite())
		//c1 = 'w';
		SetColor(F_L_MAGENTA);
	else
		//c1 = 'b';
		SetColor(F_L_CYAN);
	c2 = f.getName();
	if (c2 == ' ') {
		//c1 = '-';
		SetColor(F_D_WHITE);
		c2 = '-';
	}
	MoveCursor(x * 3 - 3, 16 - y * 2);
	//cout << c1 << c2 << " ";
	ColorPrint("%c ", c2);
}

void Chess::printBoard() {
	MoveCursor(0, 0);
	for (int i = 8; i > 0; --i) {
		for (int j = 1; j < 9; ++j) {
			printCell(j, i);
		}
	}
}

int Chess::findKing(bool white, int &y) {
	for (int i = 8; i > 0; --i)
		for (int j = 1; j < 9; ++j) {
			Piece p = board[j][i];
			if ((p.getName() == 'k') && (p.isWhite() == white)) {
				y = i;
				return j;
			}
		}
	return 0;
}

bool Chess::gameEnd() {
	int x, y;
	bool col = isWhite;

	x = findKing(col, y);
	if (!underAttack(x, y, col))
		return false;
	for (int i = -1; i < 2; ++i)
		for (int j = -1; j < 2; ++j) {
			if ((x + i > 0) && (x + i < 9) && (y + j > 0) && (y + j < 9))
				if (canMove(x, y, x + i, y + j)) {
					//checking which move saves the king;
					/*MoveCursor(0, 20);
					cout << "King safe move x, y = " << x + i << "," << y + j;*/
					return false;
				}
		}
	for (int i = 1; i < 9; ++i)
		for (int j = 1; j < 9; ++j) {
			Piece t = board[i][j];
			if ((t.isWhite() == col) && (t.getName() != 'k'))
				for (int k = 1; k < 9; ++k)
					for (int l = 1; l < 9; ++l)
						if (canMove(i, j, k, l)) {
							Piece q = board[k][l];
							move(i, j, k, l);
							if (!underAttack(x, y, col)) {
								move(k, l, i, j);
								place(k, l, q);
								//checking which figure with which move saves the king;
								/*MoveCursor(0, 20);
								cout << "other figure save i, j, k, l = " << i << j << k << l;*/
								return false;
							}
							else {
								move(k, l, i, j);
								place(k, l, q);
							}
						}

		}
	return true;
}

void Chess::switchTurn() {
	isWhite = !isWhite;
}

void Chess::move(int x1, int y1, int x2, int y2) {
	board[x2][y2] = board[x1][y1];
	board[x1][y1] = Piece();
}

void Chess::place(int x, int y, Piece p) {
	board[x][y] = p;
}

void Chess::printTurn() {
	MoveCursor(30, 8);
	if (white())
		cout << "White's";
	else
		cout << "Black's";
	cout << " turn";
}



void Chess::game() {
	char ch;
	bool f;
	while (1) {
		if (gameEnd())
			printWinner();
		f = 1;
		MoveCursor(0, 17);
		VisibleCursor(true);
		ch = _getch();
		if ((ch == 0x0) || (ch == 0xE0))
			menu();
		else
			if (!islower(ch) || ((ch - 'a' + 1) > 8))
				printf("\a");
			else
				f = turn(ch);
		VisibleCursor(false);
		//_getch();
		MoveCursor(0, 18);
		if (!f) {
			cout << "invalid move";
			_getch();
		}
		MoveCursor(0, 17);
		cout << "                                 " << endl;
		cout << "                                 " << endl;

	}
	MoveCursor(10, 20);
}

void Chess::menu() {
	char ch;
	char fname[100];
	switch (ch = _getch()) {
	case f1:
		*this = Chess();
		printBoard();
		printTurn();
		break;
	case f2:
		cout << "Please, input file name\n";
		gets_s(fname);
		fromFile(fname);
		printBoard();
		printTurn();
		break;
	case f3:
		cout << "Please, input file name\n";
		gets_s(fname);
		if (!toFile(fname)) {
			cout << "ERROR\n";
			exit(4);
		}
		break;
	case f4:
		cout << "See you next time\n";
		exit(5);
		break;
	default:
		printf("\a");
		break;
	}
}

bool Chess::turn(char ch) {
	int x1, x2, y1, y2;
	readTurn(x1, y1, x2, y2, ch);
	Piece x = getPiece(x1, y1);
	Piece y = getPiece(x2, y2);
	if (x.isWhite() != white())
		return 0;
	if (!canMove(x1, y1, x2, y2))
		return 0;
	int x3, y3;
	if (x.getName() != 'k')
		x3 = findKing(white(), y3);
	move(x1, y1, x2, y2);
	if ((x.getName() != 'k') && underAttack(x3, y3, white())) {
		move(x2, y2, x1, y1);
		place(x2, y2, y);
		return 0;
	}
	printMove(x1, y1, x2, y2, x);
	switchTurn();
	printTurn();
	return 1;
}

void Chess::gameStart() {
	MoveCursor(60, 5);
	cout << "F1 - start new game";
	MoveCursor(60, 7);
	cout << "F2 - load game";
	MoveCursor(60, 9);
	cout << "F3 - save game";
	MoveCursor(60, 11);
	cout << "F4 - exit";
	printBoard();
	printTurn();
}
void Chess::printMove(int x1, int y1, int x2, int y2, Piece x) {
	printCell(x1, y1);
	printCell(x2, y2);
}

void Chess::readTurn(int &x1, int &y1, int &x2, int &y2, char &ch) {
	x1 = ch - 'a' + 1;
	cout << ch;
	while (!isdigit(ch = _getch()) || (ch == '0') || (ch == '9'))
		printf("\a");
	y1 = ch - '0';
	cout << ch;
	while ((ch = _getch()) != ' ')
		printf("\a");
	cout << ch;
	while (!(islower(ch = _getch()) && ((x2 = ch - 'a' + 1) <= 8)))
		printf("\a");
	cout << ch;
	while (!isdigit(ch = _getch()) || (ch == '0') || (ch == '9'))
		printf("\a");
	cout << ch;
	y2 = ch - '0';
}

void Chess::printWinner() {
	MoveCursor(30, 8);
	cout << "                      ";
	MoveCursor(30, 8);
	if (isWhite)
		cout << "Black";
	else
		cout << "White";
	cout << " player won";
	MoveCursor(0, 18);
	exit(10);
}