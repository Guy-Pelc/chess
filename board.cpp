#include "board.h"
#include "unix.h"
#include "soldier.h"
// #include "rook.h"
// #include "bishop.h"
// #include "queen.h"
// #include "knight.h"
// #include "king.h"

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


	void Board::resetBoard()
	{
		for (int i = 0; i <= 8; ++i)
		{
			for (int j = 0; j <= 8; ++j)
			{
				_board[i][j]=nullptr;
			}
		}
		_board[1][1] = new Soldier(WHITE);
		_board[2][1] = new Soldier(BLACK);
		_board[2][2] = new Soldier(BLACK);


		// int row = 1;
		// PLAYER curColor = WHITE;
		// for (int i = 0; i < 2; ++i)
		// {
		// 	_board[row][1] = new Rook(curColor);
		// 	_board[row][2] = new Knight(curColor);
		// 	_board[row][3] = new Bishop(curColor);
		// 	_board[row][4] = new King(curColor);
		// 	_board[row][5] = new Queen(curColor);
		// 	_board[row][6] = new Bishop(curColor);
		// 	_board[row][7] = new Knight(curColor);
		// 	_board[row][8] = new Rook(curColor);
		// 	row = 8;
		// 	curColor = BLACK;
		// }
		// for (int i = 1; i < 9; ++i)
		// {
		// 	_board[2][i]= new Soldier(WHITE);
		// 	_board[7][i]=new Soldier(BLACK);
		// }

	}

	bool Board::moveUnit(std::string str,bool whiteTurn)
	{
		//PARSE INPUT
		Point s = {str[0]-64,str[1]-48};
		Point e = {str[2]-64,str[3]-48};
		// int sCol = str[0]-64;
		// int sRow = str[1]-48;
		// int eCol = str[2]-64;
		// int eRow = str[3]-48;
		std::cout<<s<<e;
		return moveUnit(s,e,whiteTurn);
	}
	
	bool Board::moveUnit(Point s,Point e,bool whiteTurn)
	{
		PLAYER currentPlayer = (whiteTurn) ? WHITE : BLACK;
		// Unit *currUnit = _board[s.col][s.row];
		Unit *currUnit = _board[s.row][s.col];
		if (1<=s.row && s.row<=8 &&
			1<=e.row && e.row<=8 &&
			1<=s.col && s.col<=8 &&
			1<=e.col && e.col<=8 )
			
		{
			if(currUnit==nullptr  ) {
				std::cout<<"NULLPTR!";
				return false;
			}
			if (currUnit->getPlayer() != currentPlayer)
			{
				std::cout<<"wonrg player!";
				return false;
			}
			
			if (currUnit->move(s,e,_board)== false)
			{
				std::cout<<"invalid move";
				return false;
			}
			std::cout<<"here 103!";
			// if (currUnit->isKing())
			// {
			// 	//FIX ME!!!!!!!
			// }
			// eatAt(e);
			_board[s.row][s.col]=nullptr;
			_board[e.row][e.col]=currUnit;
			// currUnit->setHasMoved();
			return true;
		}
		else
		{
			std::cout<<ILLEGAL_MOVE;
			return false;
		}
	}
	void Board::eatAt(Point e)
	{
		Unit *toBeEaten = _board[e.row][e.col];
		if (toBeEaten!=nullptr)
		{
			delete toBeEaten;
			toBeEaten = nullptr;
		}
		return;
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