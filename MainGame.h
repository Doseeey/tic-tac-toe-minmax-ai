#ifndef MAINGAME_H
#define MAINGAME_H
#include<string>
#include<iostream>
#include"Board.h"
#include"AI.h"
#include "AI.cpp"
#include "Board.cpp"



class MainGame {
public:
	void run();
	MainGame();
	~MainGame();
private:
	void _handleMenu();
	void _changePlayer();
	void _displayresult(int gameEnd);
	void _humanMove();
	void _pcMove();

	Board _board;
	int _size;
	int _inARow;
	int _currentPlayer;
	int _playerB;
	int _playerA;
	AI _ai;
};

#endif