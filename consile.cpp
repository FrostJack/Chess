#include "stdafx.h"
#include "console.h"
#include <conio.h>
#include <stdio.h>
#include "R32M.h"
#include "Chess.h"

int main(int argc, char* argv[])
{
	////init console
	//InitConsole(" Game ");
	////ClearConsole();

	//rninit( 13666 );

	//
	//int a = 100;
	//char * str = "str";
	//double f = 123.947;
	////trying to write different stuff different ways
	//ColorPrint( 20, 20, F_L_RED,"A = %d, str = %s gggggggggggggggg",a,str );
	//ColorPrint( 20, 21, F_D_WHITE | B_L_WHITE ,"A = %d, str = %s, f = %f gggggggggggggggg",a,str,f );

	////color test
	//ColorPrint( 10, 0, F_D_BLUE,"X");
	//ColorPrint( 10, 1, F_D_GREEN,"X");
	//ColorPrint( 10, 2, F_D_RED,"X");
	//ColorPrint( 10, 3, F_D_CYAN,"X");
	//ColorPrint( 10, 4, F_D_MAGENTA,"X");
	//ColorPrint( 10, 5, F_D_YELLOW,"X");
	//ColorPrint( 10, 6, F_D_WHITE,"X");
	//ColorPrint( 11, 0, F_L_BLUE,"X");
	//ColorPrint( 11, 1, F_L_GREEN,"X");
	//ColorPrint( 11, 2, F_L_RED,"X");
	//ColorPrint( 11, 3, F_L_CYAN,"X");
	//ColorPrint( 11, 4, F_L_MAGENTA,"X");
	//ColorPrint( 11, 5, F_L_YELLOW,"X");
	//ColorPrint( 11, 6, F_L_WHITE,"X");

	//ColorPrint( 10, 7,  B_D_BLUE,"X");
	//ColorPrint( 10, 8,  B_D_GREEN,"X");
	//ColorPrint( 10, 9,  B_D_RED,"X");
	//ColorPrint( 10, 10, B_D_CYAN,"X");
	//ColorPrint( 10, 11, B_D_MAGENTA,"X");
	//ColorPrint( 10, 12, B_D_YELLOW,"X");
	//ColorPrint( 10, 13, B_D_WHITE,"X");
	//ColorPrint( 11, 7,  B_L_BLUE,"X");
	//ColorPrint( 11, 8,  B_L_GREEN,"X");
	//ColorPrint( 11, 9,  B_L_RED,"X");
	//ColorPrint( 11, 10, B_L_CYAN,"X");
	//ColorPrint( 11, 11, B_L_MAGENTA,"X");
	//ColorPrint( 11, 12, B_L_YELLOW,"X");
	//ColorPrint( 11, 13, B_L_WHITE,"X");
	//
	//SetColor( F_L_YELLOW );
	//ColorPrint("X");
	//ColorPrint(B_L_CYAN, "X");
	//ColorPrint("X");
	//ColorPrint("X");

	////hide cursor
	//VisibleCursor( false );

	//getch();
	//
	////ClearConsole();
	//VisibleCursor( true );
	//MoveCursor( 5, 10 );
	//printf("GGG !");

	//int i=0, j=0;
	//MoveCursor(30, 0 );
	//for ( i=30; i<80; i++ ) {
	//	for ( j=0; j<25; j++ ) {
	//		MoveCursor( i, j );
	//		ColorPrint(int( rnunif() * 255 ), " ");
	//	}
	//}
	//
	//while ( !kbhit() ) {
	//	MoveCursor( 30 + int( rnunif() * 50 ) , int( rnunif() * 25 ) );
	//	ColorPrint(int( rnunif() * 255 ), " ");
	//}

	//InitConsole("Chess");
	//Chess table;
	//MoveCursor(60, 5);
	//cout << "F1 - start new game";
	//MoveCursor(60, 7);
	//cout << "F2 - load game";
	//MoveCursor(60, 9);
	//cout << "F3 - save game";
	//MoveCursor(60, 11);
	//cout << "F4 - exit";
	//printBoard(table);
	//printTurn(table);

	//int x1, x2, y1, y2;
	//char ch;
	//char fname[100];
	//bool f;
	//while (1) {
	//	if (table.gameEnd(table.white())) {
	//		MoveCursor(30, 8);
	//		cout << "                      ";
	//		MoveCursor(30, 8);
	//		if (table.white())
	//			cout << "Black";
	//		else
	//			cout << "White";
	//		cout << " player won";
	//		MoveCursor(0, 18);
	//		exit(10);
	//	}
	//	f = 1;
	//	MoveCursor(0, 17);
	//	VisibleCursor(true);
	//	ch = _getch();
	//	if ((ch == 0x0) || (ch == 0xE0))
	//		switch (ch = _getch()) {
	//		case f1:
	//			table = Chess();
	//			printBoard(table);
	//			printTurn(table);
	//			break;
	//		case f2:
	//			cout << "Please, input file name\n";
	//			gets_s(fname);
	//			table = Chess(fname);
	//			printBoard(table);
	//			printTurn(table);
	//			break;
	//		case f3:
	//			cout << "Please, input file name\n";
	//			gets_s(fname);
	//			if (!table.toFile(fname)) {
	//				cout << "ERROR\n";
	//				exit(4);
	//			}
	//			break;
	//		case f4:
	//			cout << "See you next time\n";
	//			exit(5);
	//			break;
	//		default:
	//			printf("\a");
	//			break;
	//		}
	//	else {
	//		if (!islower(ch))
	//			printf("\a");
	//		else
	//			if ((x1 = ch - 'a' + 1) > 8) {
	//				printf("\a");
	//			}
	//			else {
	//				int i = 0;
	//				cout << ch;
	//				while (!isdigit(ch = _getch()) || (ch == '0') || (ch == '9'))
	//					printf("\a");
	//				y1 = ch - '0';
	//				cout << ch;
	//				while ((ch = _getch()) != ' ')
	//					printf("\a");
	//				cout << ch;
	//				while (!(islower(ch = _getch()) && ((x2 = ch - 'a' + 1) <= 8)))
	//					printf("\a");
	//				cout << ch;
	//				while (!isdigit(ch = _getch()) || (ch == '0') || (ch == '9'))
	//					printf("\a");
	//				cout << ch;
	//				y2 = ch - '0';
	//				//cout << "x1 = " << x1 << "y1 = " << y1 << "x2 = " << x2 << "y2 = " << y2 << endl;
	//				Piece x = table.getPiece(x1, y1);
	//				Piece y = table.getPiece(x2, y2);
	//				if (x.getName() != ' ')
	//					if (x.isWhite() != table.white())
	//						f = 0;
	//				if (!table.canMove(x1, y1, x2, y2))
	//					f = 0;
	//				int x3, y3;
	//				if (f) {
	//					if (x.getName() != 'k')
	//						x3 = table.findKing(table.white(), y3);
	//					table.move(x1, y1, x2, y2);
	//					//cout << "   " << table.white();
	//					//cout << "    " << table.underAttack(x3, y3, table.white());
	//					if ((x.getName() != 'k') && table.underAttack(x3, y3, table.white())) {
	//						table.move(x2, y2, x1, y1);
	//						table.place(x2, y2, y);
	//						f = 0;
	//					}
	//					else {
	//						MoveCursor(x1 * 3 - 3, 16 - y1 * 2);
	//						cout << "--";
	//						MoveCursor(x2 * 3 - 3, 16 - y2 * 2);
	//						if (table.white())
	//							cout << "w";
	//						else
	//							cout << "b";
	//						cout << x.getName();
	//						table.switchTurn();
	//						printTurn(table);
	//					}
	//				}
	//			}
	//	}
	//	VisibleCursor(false);
	//	//_getch();
	//	MoveCursor(0, 18);
	//	if (!f) {
	//		cout << "invalid move";
	//		_getch();
	//	}
	//	MoveCursor(0, 17);
	//	cout << "                                 " << endl;
	//	cout << "                                 " << endl;

	//}
	//MoveCursor(10, 20);
	InitConsole("Chess");
	Chess table;
	table.gameStart();
	table.game();
	return 0;
}

