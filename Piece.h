#pragma once

const char fig[] = "phbrqk ";

class Piece
{
	char name;
	bool white;
public:
	Piece(char n = ' ', bool f = 0);
	bool canReach(int x1, int y1, int x2, int y2);
	char getName();
	bool isWhite();
	bool sameColour(Piece x);
};

