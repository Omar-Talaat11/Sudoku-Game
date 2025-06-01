#include "../include/SudokuSolver.hpp"



SudokuSolver::SudokuSolver(const SudokuBoard& other):board(other){}
SudokuSolver::SudokuSolver(const std::vector<std::vector<int>>& boardObject):board(boardObject){}

bool SudokuSolver::solve() 
{
    for (int i = 1 ; i <= 9 ; i++) {
        for (int j = 1 ; j <= 9 ; j++) {
            if (board.get_value(i,j) == 0) {
                for (int num = 1; num <= 9; num++) {
                    if (board.set_value(i,j,num)) {
                        if (solve()) return true;
                        board.set_value(i,j,0,1); // backtrack
                    }
                }
                return false; // only if no valid number was found for this empty cell
            }
        }
    }
    return true; // board is fully solved
}

const SudokuBoard& SudokuSolver::get_sudokyboard() const
{
    return board;
}

void SudokuSolver::set_board(const std::vector<std::vector<int>>& boardObject)
{
    board.set_board(boardObject);
}

void SudokuSolver::print_board()
{
    board.print_board();
}