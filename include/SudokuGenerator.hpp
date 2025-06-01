#ifndef SUDOKU_GEN
#define SUDOKU_GEN

#include "../include/SudokuBoard.hpp"

class SudokuGenerator: private SudokuBoard
{
    private:

    void shuffle_vector(std::vector<int>& vec) const;

    bool generate_complete();

    void remove_elements(int empty);

    public:
    enum Difficulity
    {
        EASY = 40,
        MEDIUM = 48,
        HARD = 52
    };
    

    void generate(Difficulity d);

    using SudokuBoard::get_board;
};

#endif