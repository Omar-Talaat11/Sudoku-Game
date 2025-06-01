#ifndef SUDOKU_EXCEPTION
#define SUDOKU_EXCEPTION
#include <string>
#include <stdexcept>
class SudokuExceptions: public std::exception
{
    private:
    std::string msg;

    public:
    SudokuExceptions(const std::string& m);
    
    const char* what() const noexcept override;
};


class WrongInput: public SudokuExceptions
{
    public:
    WrongInput(const std::string& m);
    
    using SudokuExceptions::what;
};


class WrongFileName: public SudokuExceptions
{
    public:
    WrongFileName(const std::string& m);
    
    using SudokuExceptions::what;
};


class SudokuRulesException: public SudokuExceptions
{
    public:
    SudokuRulesException(const std::string& m);
    
    using SudokuExceptions::what;
};

class SudokuUnsolvable: public SudokuExceptions
{
    public:
    SudokuUnsolvable(const std::string& m);
    
    using SudokuExceptions::what;
};


#endif