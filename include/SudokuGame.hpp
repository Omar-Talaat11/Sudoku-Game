#ifndef SUDOKU_GAME
#define SUDOKU_GAME

#include "../include/SudokuBoard.hpp"
#include "../include/SudokuSolver.hpp"



class SudokuGame : private SudokuBoard
{
    private:
    SudokuSolver solver;
    int get_option() const;

    void welcome_to_sudoku() const;
    public:

    SudokuGame();
    SudokuGame(const std::string& fname);
    SudokuGame(const std::vector<std::vector<int>>& other);

    void start_game();
};

#endif