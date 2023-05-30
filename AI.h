#ifndef MASTER_H
#define MASTER_H

#include"Board.h"

const int LOSS = -1000000;
const int WIN = 1000000;

struct Move {
	int x;
	int y;
};

class AI {
	public:
		void init(int aiPlayer);
		void makeMove(Board& board, int aiPlayer);
		AI();
		~AI();

	private:
		Move _getBestMove(Board& board, int player);
		int _minimax(Board& board, int depth, bool isMaximizing, int alpha, int beta);
		int _aiPlayer;
		int _humanPlayer;
};

#endif