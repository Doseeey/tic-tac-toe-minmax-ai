#include <iostream>
#include <vector>
#include "tictactoe.h"

#define PLAYER_MARKER 'X'
#define AI_MARKER 'O'
#define EMPTY_SPACE '-'

std::vector<std::vector<std::pair<int, int>>> win_states {
    //Rows
    {std::make_pair(0, 0), std::make_pair(0, 1), std::make_pair(0, 2)},
    {std::make_pair(1, 0), std::make_pair(1, 1), std::make_pair(1, 2)},
    {std::make_pair(2, 0), std::make_pair(2, 1), std::make_pair(2, 2)},
    //Columns
    {std::make_pair(0, 0), std::make_pair(1, 0), std::make_pair(2, 0)},
    {std::make_pair(0, 1), std::make_pair(1, 1), std::make_pair(2, 1)},
    {std::make_pair(0, 2), std::make_pair(1, 2), std::make_pair(2, 2)},
    //Diagonals
    {std::make_pair(0, 0), std::make_pair(1, 1), std::make_pair(2, 2)},
    {std::make_pair(2, 0), std::make_pair(1, 1), std::make_pair(0, 2)}
};

void print_board(char board[3][3]) {
    std::cout << std::endl;
    std::cout << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << std::endl;
    std::cout << "----------" << std::endl;
	std::cout << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << std::endl;
	std::cout << "----------" << std::endl;
	std::cout << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << std::endl << std::endl;
}

std::vector<std::pair<int, int>> get_possible_moves(char board[3][3]) {
    std::vector<std::pair<int, int>> moves;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == EMPTY_SPACE) {
                moves.push_back(std::make_pair(i, j));
            }
        }
    }

    return moves;
}

bool is_position_taken(char board[3][3], std::pair<int, int> position) {
    std::vector<std::pair<int, int>> possible_moves = get_possible_moves(board);

    for (int i = 0; i < possible_moves.size(); i++) {
        if (position.first == possible_moves[i].first && position.second == possible_moves[i].second) {
            return false;
        }
    }
    
    return true;
}

std::vector<std::pair<int, int>> get_taken_positions(char board[3][3], char marker) {
    std::vector<std::pair<int, int>> taken_positions;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (marker == board[i][j]) taken_positions.push_back(std::make_pair(i, j));
        }
    }

    return taken_positions;
}

bool is_board_full(char board[3][3]) {
    std::vector<std::pair<int, int>> possible_moves = get_possible_moves(board);

    if (possible_moves.size() == 0) return true;
    return false;
}