#include <iostream>
#include <vector>
#include "tictactoe.h"

int main() {
    char board[3][3];
    std::fill(&board[0][0], &board[3][3], EMPTY_SPACE);
    
    board[1][1] = AI_MARKER;
    print_board(board);

    std::vector<std::pair<int, int>> pos_moves = get_possible_moves(board);
    for (auto move : pos_moves) {
        std::cout << move.first << move.second << "\n";
    }

    std::vector<std::pair<int, int>> taken_moves = get_taken_positions(board, AI_MARKER);
    for (auto move : taken_moves) {
        std::cout << move.first << move.second << "\n";
    }
        
    return 0;
}