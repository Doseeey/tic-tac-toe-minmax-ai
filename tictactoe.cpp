#include <iostream>
#include <vector>
#include <algorithm>
#include "tictactoe.h"

#define PLAYER_MARKER 'X'
#define AI_MARKER 'O'
#define EMPTY_SPACE '-'

#define WIN 1000
#define LOSS -1000
#define DRAW 0

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

char get_opponent_marker(char marker) {
    char opponent_marker;
    if (marker == PLAYER_MARKER) opponent_marker = AI_MARKER;
    else opponent_marker = PLAYER_MARKER;

    return opponent_marker;
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

bool is_game_won(std::vector<std::pair<int, int>> taken_positions) {
    bool result;

    for (int i = 0; i < win_states.size(); i++) {
        result = true;
        std::vector<std::pair<int, int>> current_state = win_states[i];
        for (int j = 0; j < 3; j++) {
            //check pattern in subarray and taken positions for given marker
            if (!(std::find(std::begin(taken_positions), std::end(taken_positions), current_state[j]) != std::end(taken_positions))) {
				result = false;
				break;
			}
        }

        if (result) break;
    }
    return result;
}

int get_board_state(char board[3][3], char player_marker) {
    //Get player occupied slots
    //check if won - return value (WIN)
    //Get enemy marker
    //check if enemy won (player lost) - return value (LOSS)
    //check if board full - return value (DRAW)

    std::vector<std::pair<int, int>> player_pos = get_taken_positions(board, player_marker);
    if (is_game_won(player_pos)) return WIN;

    char enemy_marker = get_opponent_marker(player_marker);
    std::vector<std::pair<int, int>> enemy_pos = get_taken_positions(board, enemy_marker);
    if (is_game_won(enemy_pos)) return LOSS;

    if (is_board_full(board)) return DRAW;

    //return 0 if none applies
    return DRAW;
}

bool is_game_done(char board[3][3]) {
    if (is_board_full(board)) return true;
    if (get_board_state(board, PLAYER_MARKER) != DRAW) return true;
    return false;
}

//Todo: add minmax with alphabeta pruning to implement AI
//      add game() function that wraps whole gameflow
//      try to add dynamic size of board