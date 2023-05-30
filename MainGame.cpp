#include "MainGame.h"


void MainGame::_handleMenu() 
{
	char userInputGameType;

	printf("Choose: \n's' - start game\n'e' - exit\n");
	std::cin >> userInputGameType;
	
	switch (userInputGameType)
	{
	case 's':
		_gameType = GameType::SINGLEPLAYER;
		break;
	case 'e':
		exit(0);
	default: 
		exit(0);
	}

	printf("Game size (enter natural number from 3 to 9): ");
	std::cin >> _size;  

	printf("\nWinning length (enter natural number less than size: ");
	std::cin >> _inARow;

	while (_size < 3 || _size > 9)
	{
		std::cout << "Wrong size, try again:\n";
		std::cin >> _size;
		std::cin.clear();
	}
	

	char userChoice;

	printf("\nChoose your marker (X or O)? (O starts): ");
	std::cin >> userChoice;
	do
	{
		if (userChoice == 'X' || userChoice == 'x') 
		{
			_playerA = X_MARK;
			_playerB = O_MARK;
			_currentPlayer = _playerB;
		}
		else if(userChoice == 'O' || userChoice == 'o')
		{
			_playerA = O_MARK;
			_playerB = X_MARK;
			_currentPlayer = _playerA;
		}
		else
		{
			printf("Wrong marker, try again: \n");
			std::cin >> userChoice;
			std::cin.clear();
			std::cin.ignore(10000, '\n');
		}
	} while (userChoice != 'X' && userChoice != 'O' && userChoice != 'x' && userChoice != 'o');
}

void MainGame::_changePlayer() 
{
	if (_currentPlayer == _playerA) 
	{
		_currentPlayer = _playerB;
	} 
	else 
	{
		_currentPlayer = _playerA;
	}
}

void MainGame::_displayresult(int gameEnd)
{
	if (gameEnd == WON_GAME) 
	{
		if (_currentPlayer == _playerA) 
		{
			printf("Game won!\n\n");
		} 
		else 
		{
			printf("Game lost!\n\n");
		}
	} 
	else 
	{
		printf("DRAW\n\n");
	}
}

void MainGame::_humanMove() 
{
	bool moveMade = false;
	while (moveMade == false) 
	{
		int x, y;
		printf("Enter your move: X Y\n ");
		
		std::cin >> x >> y;

		x--;
		y--;
		
		if (_board.getVal(y, x) == EMPTY) 
		{
			_board.setVal(y, x, _currentPlayer);
			moveMade = true;
		} 
		else 
		{
			printf("Wrong place, or already taken\n");
		}
	} 
	
}

void MainGame::_pcMove()
{
	_ai.makeMove(_board, _playerB);
}

void MainGame::run() 
{
	while(true)
	{
		_handleMenu();
		_board.init(_size, _inARow);
		while (true)
		{		
			_board.print();

			if (_gameType == GameType::SINGLEPLAYER) 
			{
				if (_currentPlayer == _playerA) 
				{
					_humanMove();
				} 
				else 
				{
					_pcMove();
				}
			} 
			int gameEnd = _board.checkVictory();

			if (gameEnd == WON_GAME || gameEnd == TIE_GAME) 
			{
				_board.print();
				_displayresult(gameEnd);
				break;
			} 
			else 
			{
				_changePlayer();
			}
		}
	}
}

MainGame::MainGame() {}


MainGame::~MainGame() {}
