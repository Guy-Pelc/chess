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
using std::endl;

string ILLEGAL_MOVE = "\33[37;41millegal move\33[0m\n";
string endL = "\33[0m\n";
string Teal = "\33[42m";
string Green = "\33[46m";
string blanks[]={Teal,Green};
string Black = "\33[30m";
string White = "\33[36m";
string EMPTY = " ";

//assume king of player is exposed,
//if there are no possible moves, return true;
bool Board::existsPossibleMove(PLAYER player)
{
	bool isWhiteTurn = (player==WHITE) ? true:false;
	for (int sRow=1;sRow<9;sRow++)
		for (int sCol=1;sCol<9;sCol++)
		{	
		Point s;
		s.row = sRow;
		s.col = sCol;
			
			//if tile contains this player's unit
			if (_board[s.row][s.col]!=nullptr &&
				_board[s.row][s.col]->getPlayer() == player)
			{
				//check if there are any possible valid moves for that unit
				Board boardCopy(whiteKingLoc,blackKingLoc, _board);
				for (int eRow = 1;eRow<9;eRow++)
				{
					for (int eCol =1;eCol<9;eCol++)
					{
						Point e;
						e.row = eRow;
						e.col = eCol;
						cout<<"checking move (s->e):"<<s<<e<<endl;
						//if there is a possible move, it is not checkmate.
						if (boardCopy.moveUnit(s,e,isWhiteTurn))
						{
							return true;
						}
					}
				}
				//if didn't find any possible move, it is checkmate.
				return false;
			}
		}
}
bool Board::isKingExposed(PLAYER player)
	{
		cout<<"checking board::isKingExposed\n";
		Point kingLocation = (player==WHITE) ? whiteKingLoc : blackKingLoc;
		cout<<"king location: "<<kingLocation<<endl;
		// PLAYER attackingPlayer = (player==WHITE) ? BLACK : WHITE;
		for (int row=1;row<=8;row++)
		{
			for (int col=1;col<=8;col++)
			{
				Unit *curUnit=_board[row][col];
				if (curUnit==nullptr) continue;
				// if (curUnit->getPlayer==player) continue;
				
				Point curLocation;
				curLocation.row = row;
				curLocation.col = col;
				if (curUnit->move(curLocation,kingLocation,_board)==true) 
					{
						std::cout<<"location of offender:"<<curLocation<<std::endl;
						return true;
					}
			}
		}

		return false;
	}

void Board::resetBoard()
	{
		for (int i = 0; i <= 8; ++i)
		{
			for (int j = 0; j <= 8; ++j)
			{
				_board[i][j]=nullptr;
			}
		}
		
		blackKingLoc.row = 1;
		blackKingLoc.col = 1;

		whiteKingLoc.row = 8;
		whiteKingLoc.col = 1;

		_board[whiteKingLoc.row][whiteKingLoc.col] = new King(WHITE);
		_board[blackKingLoc.row][blackKingLoc.col] = new King(BLACK);
		
		// _board[4][4] = new Queen(BLACK);
		// _board[4][3] = new Queen(WHITE);
		
		_board[2][2] = new Rook(WHITE);
		// _board[1][1] = new Soldier(WHITE);

		// _board[2][2] = new Queen(WHITE);
		// _board[1][4] = new Soldier(WHITE);

		// _board[2][4] = new Soldier(BLACK);
		// _board[2][3] = new Soldier(BLACK);
		// _board[2][5] = new Soldier(BLACK);
		


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

		// _board[]

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
		// std::cout<<s<<e;
		Board copy(whiteKingLoc,blackKingLoc, _board);
		cout<<"printing copy board after move try..:\n";
		if (copy.moveUnit(s,e,whiteTurn))
		{
			copy.printBoard();
			cout<<"copyboard move success, now moving real board\n";

			moveUnit(s,e,whiteTurn);	

			return true;
		}
		else
		{
			copy.printBoard();
			cout<<"copyboard failed. invalid move..\n";
			return false;
		}
		
	}
	
bool Board::moveUnit(Point s,Point e,bool whiteTurn)
	{
		PLAYER currentPlayer = (whiteTurn) ? WHITE : BLACK;
		// Unit *currUnit = _board[s.col][s.row];
		Unit *currUnit = _board[s.row][s.col];
		// cout<<"at boardcpp 149\n";
		// cout<<"s:"<<s<<"e:"<<e<<endl;

		if (1<=s.row && s.row<=8 &&
			1<=e.row && e.row<=8 &&
			1<=s.col && s.col<=8 &&
			1<=e.col && e.col<=8 )
			
		{
			if(currUnit==nullptr  ) {
				std::cout<<"NULLPTR!\n";
				return false;
			}
			if (currUnit->getPlayer() != currentPlayer)
			{
				std::cout<<"wonrg player!\n";
				return false;
			}
			if (currUnit->move(s,e,_board)== false)
			{
				cout<<"boardcpp 169\n";
				std::cout<<"invalid move\n";
				return false;
			}
			// std::cout<<"here 103!";
			if (currUnit->isKing())
			{
				if (currUnit->getPlayer()==WHITE)
				{
					std::cout<<"white king moved!!\n";
					whiteKingLoc = e;
				}
				else
				{
					std::cout<<"black king moved!!\n";
					blackKingLoc = e;
				}
				
			}

			eatAt(e);
			_board[s.row][s.col]=nullptr;
			_board[e.row][e.col]=currUnit;
			currUnit->setHasMoved();

			//check if enemy king is exposed, 
			if (isKingExposed(currentPlayer))
			{
				cout<<"KING CAN BE KILLED! ILLEGAL MOVE";
				return false;
			}

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

Board::Board()
	{

		resetBoard();
	}	

Board::Board(Point wKing, Point bKing, Unit* b[9][9])
:whiteKingLoc(wKing),blackKingLoc(bKing)
{
	//set all pointers to null
	for (int i = 0; i <= 8; ++i)
		{
			for (int j = 0; j <= 8; ++j)
			{
				_board[i][j]=nullptr;
			}
		}
	//copy units from original board
	for (int row = 1;row<9;row++)
		for (int col = 1; col<9;col++)
		{
			if (b[row][col]!=nullptr)
			{
				std::cout<<"cloning a unit...\n";
				_board[row][col] = b[row][col]->clone();
			}
		}
}

Board::~Board()
	{
		for (int row=0; row<9;row++)
		{
			for (int col=0;col<9;col++)
			{
				if (_board[row][col]!=nullptr)
					delete _board[row][col];
			}
		}
	}