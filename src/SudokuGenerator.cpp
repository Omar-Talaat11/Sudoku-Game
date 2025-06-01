#include "../include/SudokuGenerator.hpp"

#include <cstdlib>
#include <ctime>

void SudokuGenerator::shuffle_vector(std::vector<int>& vec) const
    {
        std::srand(std::time(0));
        for (int i = vec.size() - 1; i > 0; --i) 
        {
            int j = std::rand() % (i + 1);
            std::swap(vec[i], vec[j]);
        }
    }

bool SudokuGenerator::generate_complete()
{
    for (int i = 1; i <= 9; ++i) 
    {
        for (int j = 1; j <= 9; ++j) 
        {
        if (get_value(i, j) == 0)  // Only try to fill empty cells
            {
                std::vector<int> values = {1,2,3,4,5,6,7,8,9};
                shuffle_vector(values);   
                
                for(int r : values)
                {
                    if(set_value(i,j,r))
                    {
                        if(generate_complete()) return true;
                        set_value(i,j,0,1);
                    }
                }
                return false;
            }
        }
    }
    return true;
}

void SudokuGenerator::remove_elements(int empty)
{
    while(empty_count() < empty)
    {
        std::vector<int> values = {1,2,3,4,5,6,7,8,9};
        shuffle_vector(values);
        for(int i : values)
        {
            if(empty_count() >= empty) break;
            for(int j : values)
            {
                if(empty_count() >= empty) break;
                int f = rand() % 2 + 1;
                if(f == 1) 
                {
                    set_value(i,j,0,1);
                }

            }
        }
    }
}

enum Difficulity
{
    EASY = 40,
    MEDIUM = 48,
    HARD = 52
};


void SudokuGenerator::generate(Difficulity d)
{
    generate_complete();
    remove_elements(d);
}
