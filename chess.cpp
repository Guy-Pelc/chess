#include <iostream>
#include <string>
#include "board.h"
#include "units.h"
#include "unix.h"

using std::cout;
using std::string;
#include <cmath>
using std::abs;
using namespace std;

string CHECK_MSG = "\33[37;41mCheck!\33[0m\n";
string ILLEGAL_MOVE_MSG = "\33[37;41millegal move\33[0m\n";

int test10()
{
	Board b;
	
	std::string whiteName = "w";
	std::string blackName = "b"; 

	// std::cout<<"Enter white player name:\n";
	// std::cin>>whiteName;
	// std::cout<<"Enter black player name:\n";
	// std::cin>> blackName;

	bool whiteTurn = true;
	std::string input;
	// bool isValidMove=false;
	std::cout<<"\33[2J";
	while (true)
	{
		

		PLAYER curPlayer = (whiteTurn) ? WHITE : BLACK;
		bool isCheck = b.isKingExposed(curPlayer);
		bool existsPossibleMove = b.existsPossibleMove(curPlayer);
		
		b.printBoard();
		cout<<"possibelmove,check: "<<existsPossibleMove<<","<<isCheck<<endl;
		if (isCheck && existsPossibleMove) std::cout<<CHECK_MSG;
		else if (isCheck && !existsPossibleMove) 
		{
			std::string winner = (whiteTurn) ? blackName : whiteName;
			std::cout<<winner<<" won!\n";
			return 0;	
		}
		else if (!isCheck && !existsPossibleMove)
			{
				std::cout<<"Tie, no winners!\n";
				return 0;
			}

		while (true)
		{
		std::string curName = (whiteTurn) ? whiteName : blackName;
		std::cout<<curName<<": please enter your move:\n";
		std::cin>>input;
		if (b.moveUnit(input,whiteTurn)) break;
		else cout<<ILLEGAL_MOVE_MSG;
		b.printBoard();	
		}

		whiteTurn = !whiteTurn;
		// isValidMove=false;
		
		//ADD PLAYER X WON!!
	}

}
int test11()
{
	Board b;
	
	// std::string whiteName;
	// std::string blackName; 

	// std::cout<<"Enter white player name:\n";
	// std::cin>>whiteName;
	// std::cout<<"Enter black player name:\n";
	// std::cin>> blackName;

	bool whiteTurn = true;
	std::string input;

	// std::cout<<"\33[2J";
	while (true)
	{
		b.printBoard();
		std::cout<<": please enter your move:\n";
		std::cin>>input;

		b.moveUnit(input,whiteTurn);
		// if () whiteTurn = !whiteTurn;
		//ADD PLAYER X WON!!
	}
}
int main()
{
	// std::cout<<"hello world\n\n";
	test10();	
}

// void test5()
// {
// 	Board b = Board();
// 	b.resetBoard();
// 	// b.resetUnits();
// 	b.printBoard();

// }
// void test6()
// {

// 	std::cout<<SOLDIER;
// }
// void test7()
// {
// 	Unit u;
// 	std::cout<<u.getUnix();
// }
// void test8()
// {
// 	string a = "hi";
// 	string b = "there";
// 	string ab = a+b;
// 	cout<<ab;
// }
// void test9()
// {
// 	Board b;
// 	b.printBoard();
// 	b.moveUnit(1,1,2,1);
// 	b.printBoard();
// 	// b.moveUnit(0,0,3,3);
// 	// b.printBoard();
// }

// void test11()
// {
// 	int a = '1'-48;
// 	int b = '2';
// 	std::cout<<a<<b;
// }


// print constants
// std::string str1 = "\33[30;42m\u265B";
// std::string str2 = "\33[37;46m\u265B";
// std::string endL = "\33[0m\n";
// std::string T = "\33[42m ";
// std::string G = "\33[46m ";
// void test1()
// {
// 	std::cout<<"in test 1...\n";
// 	// std::cout<<"\33[0;42m \33[0m";
// 	// std::cout<<"\33[30;46m\u265B\33[0m"<<std::endl;
// 	// std::cout<<"\33[0;42m \33[30m\33[0;46m\u265B\33[0m\n";
// 	// std::cout<<"\33[30;42m\u265B\33[37;46m\u265B\33[0m\n";
// 	std::cout<<str1<<str2<<str1<<endL;
// 	std::cout<<T<<G<<T<<G<<T<<G<<endL;
	

// 	return;
// }

// //print row
// void test2(int s)
// {
// 	std::string blanks[]={T,G};
// 	for (int i = 0; i < 8; ++i)
// 	{
// 		std::cout<<blanks[(s+i)%2];
// 	}
// 	std::cout<<endL;
// }
// //print empty board
// void test3()
// {
// 	for (int i = 0; i < 8; ++i)
// 	{
// 		test2(i%2);
// 	}
// }
// //formatted print start of turn!
// void test4(std::string playerName)
// {
// 	std::string move;
// 	std::cout<<playerName<<": Please enter your move:\n";
// 	std::cin>>move;
// 	std::cout<<"\n";
// 	std::cout<<"ABCDEFGH\n";
// 	std::cout<<"\n";
// 	test3();
// 	std::cout<<"\n";
// 	std::cout<<"ABCDEFGH\n";

// 	return;
// }