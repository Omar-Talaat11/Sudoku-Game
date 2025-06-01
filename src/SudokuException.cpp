#include "../include/SudokuException.hpp"

#include <iostream>

SudokuExceptions::SudokuExceptions(const std::string& m):msg(m){}

const char*SudokuExceptions::what() const noexcept 
{
    return msg.c_str();
}


WrongInput::WrongInput(const std::string& m):SudokuExceptions(m){}

WrongFileName::WrongFileName(const std::string& m):SudokuExceptions(m){}
    
SudokuRulesException::SudokuRulesException(const std::string& m):SudokuExceptions(m){}
    
SudokuUnsolvable::SudokuUnsolvable(const std::string& m):SudokuExceptions(m){}