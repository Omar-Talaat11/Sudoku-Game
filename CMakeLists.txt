cmake_minimum_required(VERSION 3.8)
project(SudokuProject)

# Use C++17 (adjust if you need a different standard)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Core source files
set(SOURCES
    src/main.cpp 
    src/SudokuBoard.cpp 
    src/SudokuGame.cpp 
    src/SudokuGenerator.cpp 
    src/SudokuSolver.cpp 
    src/SudokuException.cpp
)


# Header files (not strictly required for add_executable, but good for clarity)
set(HEADERS
    include/SudokuBoard.hpp
    include/SudokuSolver.hpp
    include/SudokuGame.hpp
    include/SudokuGenerator.hpp
    include/SudokuException.hpp
)




# Create the final executable
add_executable(SudokuProject ${SOURCES} ${HEADERS})

# For example usage, you might do:
#    cmake -S . -B build -DBUILD_GENERATOR=OFF -DBUILD_ADVANCED=OFF
#    cmake --build build
#
# In that case, the project will build without the optional modules.
