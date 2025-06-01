#ifndef SUDOKU_BOARD
#define SUDOKU_BOARD

#include <vector>
#include <string>

class SudokuBoard
{
    private:
    friend class SudokuSolver;
    std::vector<std::vector<int>> board;
    
    std::vector<int> GetBox(int box_row_num, int box_col_num) const;
    bool ValidBox(int row_num, int col_num, int num) const;
    bool ValidRow(int row_num, int num) const;
    bool ValidColumn(int col_num, int num) const;

    protected:
    SudokuBoard();
    SudokuBoard(const std::vector<std::vector<int>>& otherboard);
    SudokuBoard(const std::string& fname);
    
    bool load_puzzle(const std::string& fname);
    
    bool set_value(int row_num, int col_num, int num, bool backtrace = 0);

    int get_value(int row_num, int col_num) const;

    void print_board() const;

    void save(const std::string& fname) const;

    const std::vector<std::vector<int>>& get_board() const;

    void set_board(const std::vector<std::vector<int>>& other);
    void set_board(const SudokuBoard& other);

    int empty_count() const;
};

#endif