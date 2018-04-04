#include "stdafx.h"
#include "Piece.h"
#include "Console.h"

Piece::Piece(char n, bool f) {
	if (strchr(fig, n) == NULL) {
		printf("Wrong charachter received in Piece construction\n");
		exit(1);
	}
	name = n;
	white = f;
}

bool Piece::canReach(int x1, int y1, int x2, int y2) {
	int col = abs(x2 - x1);
	int row = abs(y2 - y1);
	switch (name) {
	case 'p':
		if (col > 1)
			return false;
		return ((white && (y1 + 1 == y2)) || (!white && (y1 - 1 == y2)) || (col == 0) &&
			((white && (y1 == 2) && (y2 = 4)) || (!white && (y1 == 7) && (y2 == 5))));
	case 'h':
		return ((row == 2) && (col == 1) || (row == 1) && (col == 2));
	case 'b':
		return (col == row);
	case 'r':
		return ((col == 0) || (row == 0));
	case 'q':
		return ((col == 0) || (row == 0) || (col == row));
	case 'k':
		return ((col <= 1) && (row <= 1));
	default:
		printf("wrong character recieved");
		exit(2);
	}
}

char Piece::getName() {
	return name;
}

bool Piece::isWhite() {
	return white;
}

bool Piece::sameColour(Piece x) {
	if (x.getName() == ' ')
		return false;
	return (white == x.isWhite());
}

