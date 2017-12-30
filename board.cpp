#include "board.h"
#include "unix.h"
#include "soldier.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "knight.h"
#include "king.h"

#include <iostream>
#include <cassert>


using std::string;
using std::cout;

string ILLEGAL_MOVE = "\33[37;41millegal move\33[0m\n";
string endL = "\33[0m\n";
string Teal = "\33[42m";
string Green = "\33[46m";
string blanks[]={Teal,Green};
string Black = "\33[30m";
string White = "\33[36m";
string EMPTY = " ";

Point whiteKingLoc;
Point blackKingLoc;

enum col{A=1,B,C,D,E,F,G,H,};

	void Board::resetBoard()
	{
		for (int i = 0; i <= 8; ++i)
		{
			for (int j = 0; j <= 8; ++j)
			{
				_board[i][j]=nullptr;
			}
		}
		int row = 1;
		PLAYER curColor = WHITE;
		for (int i = 0; i < 2; ++i)
		{
			_board[row][1] = new Rook(curColor);
			_board[row][2] = new Knight(curColor);
			_board[row][3] = new Bishop(curColor);
			_board[row][4] = new King(curColor);
			_board[row][5] = new Queen(curColor);
			_board[row][6] = new Bishop(curColor);
			_board[row][7] = new Knight(curColor);
			_board[row][8] = new Rook(curColor);
			row = 8;
			curColor = BLACK;
		}
		for (int i = 1; i < 9; ++i)
		{
			_board[2][i]= new Soldier(WHITE);
			_board[7][i]=new Soldier(BLACK);
		}

	}

	bool Board::moveUnit(std::string str,bool whiteTurn)
	{
		//PARSE INPUT
		Point s = {str[1]-48,str[0]-64};
		Point e = {str[3]-48,str[2]-64};
		// int sCol = str[0]-64;
		// int sRow = str[1]-48;
		// int eCol = str[2]-64;
		// int eRow = str[3]-48;
		
		return moveUnit(s,e,whiteTurn);
	}
	void Board::eatAt(Point e)
	{
		Unit *toBeEaten = _board[e.x][e.y];
		if (toBeEaten!=nullptr)
		{
			delete toBeEaten;
			toBeEaten = nullptr;
		}
		return;
	}
	bool Board::moveUnit(Point s,Point e,bool whiteTurn)
	{
		PLAYER currentPlayer = (whiteTurn) ? WHITE : BLACK;
		Unit *currUnit = _board[s.x][s.y];
		if (1<=s.x && s.x<=8 &&
			1<=e.x && e.x<=8 &&
			1<=s.y && s.y<=8 &&
			1<=e.y && e.y<=8 &&
			currUnit!=nullptr && 
			currUnit->getPlayer() == currentPlayer &&
			currUnit->move(s,e,_board))
		{
			// if (currUnit->isKing())
			// {
			// 	//FIX ME!!!!!!!
			// }
			// eatAt(e);
			_board[s.x][s.y]=nullptr;
			_board[e.x][e.y]=currUnit;
			// currUnit->setHasMoved();
			return true;
		}
		else
		{
			std::cout<<ILLEGAL_MOVE;
			return false;
		}
	}
	Board::Board()
	{
		resetBoard();
	}
	
	void Board::printBoard()
	{
	cout<<"  ABCDEFGH\n\n";

		for (int i = 8; i >= 1; --i)
		{
			cout<<i<<" ";
			for (int j = 1; j<= 8  ; ++j)
			{	
				std::string currStr;  
				if (_board[i][j]==nullptr)
				{
					// std::cout<<"NULL";
					currStr = EMPTY;
				}
				else
				{
					// std::cout<<"NOT NULL";
					currStr = _board[i][j]->getUnix();
				}
				// Unit currUnit = ;
				// std::string currStr = currUnit.getUnix();
				cout<<blanks[(i+j)%2]<<currStr;
			}
			
			cout<<"\33[0m "<<i<<endL;
		}
	cout<<"\n  ABCDEFGH\n\n";
	}
	


	// Soldier Board::getUnit(int Row, int Col)
	// {
	// 	// return 
	// }
	

 	// void Board::resetUnits()
 	// {
 	// 	// _board[7][A] = unitToString(SOLDIER); 
 	// }
 	// void Board::resetBoard()
 	// {
 	// 	// _board = 
 	// }