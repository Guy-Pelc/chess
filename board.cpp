#include "board.h"
#include "unix.h"
#include "soldier.h"
#include "rook.h"
#include "bishop.h"
#include "queen.h"
#include "knight.h"
#include "king.h"
#include "point.h"

#include <iostream>
#include <cassert>


using std::string;
using std::cout;
using std::endl;

string endL = "\33[0m\n";
string Teal = "\33[42m";
string Green = "\33[46m";
string blanks[]={Teal,Green};
string EMPTY =" ";

//if there are no possible moves, return true;
bool Board::existsPossibleMove(PLAYER player)
{
	bool isWhiteTurn = player==WHITE;
	for (int sRow=1;sRow<9;sRow++)
	{
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
						//if there is a possible move, it is not checkmate.
						if (boardCopy.moveUnit(s,e,isWhiteTurn))
						{
							return true;
						}
					}
				}
			}
		}
	}
	//if didn't find any possible move, return false.
	return false;
}
bool Board::isKingExposed(PLAYER player)
	{
		Point kingLocation = (player==WHITE) ? whiteKingLoc : blackKingLoc;
		return _board[kingLocation.row][kingLocation.col]->isExposed(kingLocation, _board);
	}

bool Board::moveUnit(std::string str,bool whiteTurn)
	{
		//PARSE INPUT
		Point s = {str[0]-64,str[1]-48};
		Point e = {str[2]-64,str[3]-48};

		return moveUnit(s,e,whiteTurn);
	}
bool Board::moveUnit(Point s,Point e,bool whiteTurn)
{
	Board copy(whiteKingLoc,blackKingLoc, _board);
		if (copy.moveUnitHelper(s,e,whiteTurn))
		{
			moveUnitHelper(s,e,whiteTurn);
			return true;
		}
		else
		{
			return false;
		}
}	
bool Board::moveUnitHelper(Point s,Point e,bool whiteTurn)
	{
		PLAYER currentPlayer = (whiteTurn) ? WHITE : BLACK;
		Unit *currUnit = _board[s.row][s.col];

		if (1<=s.row && s.row<=8 &&
			1<=e.row && e.row<=8 &&
			1<=s.col && s.col<=8 &&
			1<=e.col && e.col<=8)
		{
			if(currUnit==nullptr  )
			{
				return false;
			}
			if (currUnit->getPlayer() != currentPlayer)
			{
				return false;
			}
			if (!(currUnit->move(s,e,_board)))
			{
				return false;
			}

			//check for hatsraha, or update king location
			if (currUnit->isKing())
			{
				//if hatsraha update rook
				Point dir = e-s;
				if (abs(dir.col)==2)
				{
					if (dir.col>0)
					{
						Unit* rookToMove = _board[s.row][8];
						_board[s.row][5]=rookToMove;
						_board[s.row][8]=nullptr;
					}
					else
					{
						Unit *rookToMove = _board[s.row][1];
						_board[s.row][3]=rookToMove;
						_board[s.row][1]=nullptr;
					}
				}
				if (currUnit->getPlayer()==WHITE)
				{
					whiteKingLoc = e;
				}
				else
				{
					blackKingLoc = e;
				}
			}

			eatAt(e);
			_board[s.row][s.col]=nullptr;
			_board[e.row][e.col]=currUnit;

			//check for pawn->queen
			if (currUnit->isPawn() &&
				(e.row==8||e.row==1))
			{
				delete currUnit;
				currUnit = new Queen(currentPlayer);
			}

			currUnit->setHasMoved();

			//check if enemy king is exposed, 
			if (isKingExposed(currentPlayer))
			{
				return false;
			}
			return true;
		}
		else
		{
			return false;
		}
	}

void Board::eatAt(Point e)
	{
		Unit *toBeEaten = _board[e.row][e.col];
		if (toBeEaten!=nullptr)
		{
			delete toBeEaten;
		}
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
					currStr = EMPTY;
				}
				else
				{
					currStr = _board[i][j]->getUnix();
				}
				cout<<blanks[(i+j)%2]<<currStr;
			}
			
			cout<<"\33[0m "<<i<<endL;
		}
	cout<<"\n  ABCDEFGH\n\n";
	}

Board::Board()
	{
		for (int i = 0; i <= 8; ++i)
		{
			for (int j = 0; j <= 8; ++j)
			{
				_board[i][j]=nullptr;
			}
		}

		blackKingLoc.row = 8;
		blackKingLoc.col = 4;

		whiteKingLoc.row = 1;
		whiteKingLoc.col = 4;

		_board[blackKingLoc.row][blackKingLoc.col] = new King(BLACK);
		_board[whiteKingLoc.row][whiteKingLoc.col] = new King(WHITE);



		int row = 1;
		PLAYER curColor = WHITE;
		for (int i = 0; i < 2; ++i)
		{
			_board[row][1] = new Rook(curColor);
			_board[row][2] = new Knight(curColor);
			_board[row][3] = new Bishop(curColor);

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