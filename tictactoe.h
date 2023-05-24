#ifndef TICTACTOE_H
#define TICTACTOE_H

#include<vector>
#include "tictactoe.cpp"

//Util & Helper
void print_board(char board[3][3]);
bool is_board_full(char board[3][3]);
char get_opponent_marker(char marker);

//Get positions
std::vector<std::pair<int, int>> get_possible_moves(char board[3][3]);
std::vector<std::pair<int, int>> get_taken_positions(char board[3][3], char marker);

//Check given position
bool is_position_taken(char board[3][3], std::pair<int, int> position);
//Game result check
bool is_game_won(std::vector<std::pair<int, int>> taken_positions);
bool is_game_done(char board[3][3]); //check if board is full or someone already won

//Board state for given marker
int get_board_state(char board[3][3], char marker);

#endif