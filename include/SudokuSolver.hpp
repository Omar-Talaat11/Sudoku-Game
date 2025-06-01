#ifndef SUDOKU_SOLVER
#define SUDOKU_SOLVER

#include "../include/SudokuBoard.hpp"

class SudokuSolver
{
    private:
    SudokuBoard board;
    public:
    SudokuSolver(const SudokuBoard& other);
    SudokuSolver(const std::vector<std::vector<int>>& boardObject);

    bool solve();

    const SudokuBoard& get_sudokyboard() const;

    void set_board(const std::vector<std::vector<int>>& boardObject);

    void print_board();
};

#endif