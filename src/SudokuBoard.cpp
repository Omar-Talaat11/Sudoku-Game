#include "../include/SudokuBoard.hpp"

#include "../include/SudokuException.hpp"

#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>



std::vector<int> SudokuBoard::GetBox(int box_row_num, int box_col_num) const
{
    std::vector<int> box;

    for(int i = 0; i<3 ; i++)
    {
        for(int j = 0; j<3 ; j++)
        {
            box.push_back(board[box_row_num*3 + i][box_col_num*3 + j]);
        }
    }
    return box;
}

bool  SudokuBoard::ValidBox(int row_num, int col_num, int num) const
{
    int box_row_num = (row_num) / 3;
    int box_col_num = (col_num) / 3;

    std::vector<int> box = GetBox(box_row_num,box_col_num);

    auto it = std::find(box.begin(),box.end(),num);
    if(it == box.end()) return true;
    else                return false;
}

bool  SudokuBoard::ValidRow(int row_num, int num) const
{
    std::vector<int> row = board[row_num];

    auto it = std::find(row.begin(),row.end(),num);
    if(it == row.end()) return true;
    else                return false;
}

bool  SudokuBoard::ValidColumn(int col_num, int num) const
{
    std::vector<int> column;
    for (const auto& row : board) 
    {
        column.push_back(row[col_num]);
    }

    auto it = std::find(column.begin(),column.end(),num);
    if(it == column.end()) return true;
    else                return false;
}

SudokuBoard::SudokuBoard():board(9,std::vector<int>(9,0)){}

SudokuBoard::SudokuBoard(const std::vector<std::vector<int>>& otherboard):board(otherboard){}

SudokuBoard::SudokuBoard(const std::string& fname):board(9,std::vector<int>(9,0))
{
    std::ifstream infile(fname);
    std::string line;
    if(infile.is_open())
    {
        int row_num = 0, col_num = 0;
        while(std::getline(infile,line))
        {
            std::istringstream ss(line);
            std::string num;

            while (ss >> num) 
            { 
                int number = stoi(num); 
                board[row_num][col_num++] = number;
            }

            row_num++;
            col_num= 0;
        }
        infile.close();
        // print_board();
    }
    else    { throw WrongFileName("file failed to open"); }
}

bool  SudokuBoard::load_puzzle(const std::string& fname)
{
    std::ifstream infile(fname);
    std::string line;
    if(infile.is_open())
    {
        int row_num = 0, col_num = 0;
        while(std::getline(infile,line))
        {
            std::istringstream ss(line);
            std::string num;

            while (ss >> num) 
            { 
                int number = stoi(num); 
                board[row_num][col_num++] = number;
            }

            row_num++;
            col_num= 0;
        }
        infile.close();
        return true;
        // print_board();
    }
    else    
    { 
        throw WrongFileName("file failed to open");
        return false;
    }
}

bool  SudokuBoard::set_value(int row_num, int col_num, int num, bool backtrace)
{
    row_num = row_num - 1;
    col_num = col_num - 1;
    if(board[row_num][col_num]!=0 && !backtrace)
    {
        return false;
    }
    if(num==0 || (ValidBox(row_num,col_num,num) && ValidColumn(col_num,num) && ValidRow(row_num,num)))
    {
        board[row_num][col_num] = num;
        // print_board();
        return true;
    }
    // print_board();
    return false;
}

int  SudokuBoard::get_value(int row_num, int col_num) const
{
    return board[row_num-1][col_num-1];
}

void  SudokuBoard::print_board() const
{
    std::cout<<"---------SUDOKU---------"<<std::endl;
    for(int j = 0 ; j < 9 ; j++)
    {
        std::vector<int> row = board[j];
        for(int i = 0 ; i < 9 ; i++)
        {
            if(row[i]==0)   std::cout << "." << " ";
            else            std::cout << row[i] << " ";

            if(i==2 || i==5) std::cout<<" | ";
        }
        std::cout<<std::endl;
        if(j == 2 || j == 5) std::cout<<"------------------------"<<std::endl;
    }

}

void  SudokuBoard::save(const std::string& fname) const
{
    std::ofstream outfile(fname);
    std::string line;
    if(outfile.is_open())
    {
        for(auto row : board)
        {
            for(auto val : row)
            {
                outfile << val << " ";
            }
            outfile << std::endl;
        }
        outfile.close();
    }
    else    { std::cout<<"file failed to open"<<std::endl; }
}

const std::vector<std::vector<int>>&  SudokuBoard::get_board() const
{
    return board;
}

void  SudokuBoard::set_board(const std::vector<std::vector<int>>& other)
{
    board = other;
}

void  SudokuBoard::set_board(const SudokuBoard& other)
{
    board = other.board;
}

int  SudokuBoard::empty_count() const
{
    int count = 0;
    for(auto row : board)
    {
        for(auto value : row)
        {
            if(value == 0) count++;;
        }
    }
    return count;
}
