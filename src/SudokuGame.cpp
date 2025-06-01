#include "../include/SudokuGame.hpp"
#include "../include/SudokuGenerator.hpp"
#include "../include/SudokuException.hpp"

#include <iostream>
int SudokuGame::get_option() const
{
    std::cout<<"1) Enter a move"<<std::endl;
    std::cout<<"2) Solve automatically"<<std::endl;
    std::cout<<"3) Load puzzle from file"<<std::endl;
    std::cout<<"4) Save current puzzle to file"<<std::endl;
    std::cout<<"5) Exit"<<std::endl;
    std::cout<<"Choice: ";

    int c;
    std::cin>>c;
    return c;
}

void SudokuGame::welcome_to_sudoku() const
{
    std::cout<<"Welcome to SUDOKU!!"<<std::endl;
    std::cout<<"Developed my Omar Talaat"<<std::endl;
    print_board();
}

SudokuGame::SudokuGame():SudokuBoard(),solver(get_board())
{
    SudokuGenerator generator;
    generator.generate(SudokuGenerator::EASY);
    set_board(generator.get_board());
}

SudokuGame::SudokuGame(const std::string& fname):SudokuBoard(fname),solver(get_board()){}
SudokuGame::SudokuGame(const std::vector<std::vector<int>>& other):SudokuBoard(other),solver(get_board()){}

void SudokuGame::start_game()
{
    int choice = 0;
    std::string path;
    bool running = true;

    welcome_to_sudoku();
    
    while(running)
    {
        if(empty_count() == 0)
        {
            std::cout<<"Great job! The Sudoku is solved!"<<std::endl;
        }
        choice = get_option();
        try
        {
        switch(choice)
        {
            case 1: // Enter a move
            int row,column,value;
            std::cout<<"Enter row (1-9), column (1-9), and value (1-9): ";
            std::cin>>row>>column>>value;

            if(row > 9 || row < 1)          throw WrongInput("Invalid input: Row must be between 1 nd 9.");
            if(column > 9 || column < 1)    throw WrongInput("Invalid input: Column must be between 1 nd 9.");
            if(value > 9 || value < 0)      throw WrongInput("Invalid input: Vlue must be between 0 nd 9.");
            
            if(set_value(row,column,value))
            {
                std::cout<<"Move accepted!"<<std::endl;
                print_board();
            }
            else
            {
                throw SudokuRulesException("Invalid move. That cell might be occupied or the placement breaks Sudoku rules.");
            }
            break;

            case 2: // Solve automatically
            solver.set_board(get_board());
            if(solver.solve())
            {                
                std::cout<<"Puzzle solved!"<<std::endl;
                solver.print_board();
                set_board(solver.get_sudokyboard());
            }
            else  
            {
                throw SudokuUnsolvable("Game is unsolvable!!");
            }

            break;

            case 3: // Load puzzle from file
            std::cout<<"Please enter file path"<<std::endl;
            std::cin>>path;
            load_puzzle(path);
            break; 

            case 4: // Save current puzzle to file
            std::cout<<"Please enter file path"<<std::endl;
            std::cin>>path;
            save(path);
            break;

            case 5:
            std::cout<<"Game is now closing!!"<<std::endl;
            running = false;
            break;

            default:
            std::cin.clear();                 // Clear error flags
            std::cin.ignore(10000, '\n');    // Discard the rest of the input line
            throw WrongInput("Wrong input!!");
        }
        }
        catch(const SudokuExceptions& e)
        {
            std::cerr<<std::endl<<e.what()<<std::endl<<std::endl;
        }
        
    }
}


