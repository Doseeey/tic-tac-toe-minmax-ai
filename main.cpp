#include <iostream>
#include <vector>
#include "tictactoe.h"

int main() {
    char board[3][3];
    std::fill(&board[0][0], &board[3][3], EMPTY_SPACE);
    
    board[1][1] = AI_MARKER;
    print_board(board);

    std::vector<std::pair<int, int>> taken_moves1 = get_taken_positions(board, AI_MARKER);
    std::cout << is_game_won(taken_moves1);
    board[0][0] = AI_MARKER;
    board[2][2] = AI_MARKER;
    print_board(board);

    std::vector<std::pair<int, int>> taken_moves2 = get_taken_positions(board, AI_MARKER);

    std::cout << is_game_won(taken_moves2);
    std::cout << get_opponent_marker('O');
    return 0;
}