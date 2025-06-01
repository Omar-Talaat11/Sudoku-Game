# Sudoku-Game
This project is a console-based implementation of the classic Sudoku puzzle, developed using modern C++ with an emphasis on clean design, modularity, and extensibility. The game is structured with object-oriented programming (OOP) principles and makes extensive use of the C++ Standard Template Library (STL).

Users can:

Interactively solve Sudoku puzzles via the terminal

Load and save puzzles from files

Automatically solve puzzles using a backtracking algorithm

Optionally generate new puzzles

The architecture separates the core logic (board, solver, generator) from the user interface, enabling easy migration to GUI frameworks like Qt or web frontends in the future.

✅ Project Objectives
Practice and demonstrate strong OOP and STL usage

Implement core Sudoku features:

9×9 board with validity checks

Backtracking-based solver

User-friendly console interface

Maintain a clear separation of concerns between modules

Puzzle generation

Load/save functionality

🔧 Features & Functionality
🖥️ Console Interface
Displays a clear ASCII-rendered 9×9 Sudoku board

Main menu options include:

Enter a move

Solve the puzzle automatically

Load a puzzle from a file

Save current puzzle to a file

Exit the application

🔲 Board Operations
SudokuBoard class handles:

Loading a 9×9 board (from file or hardcoded)

Validating user moves (row, column, 3×3 box constraints)

Setting and retrieving cell values

Displaying the board in a readable format

🧠 Puzzle Solving
SudokuSolver class:

Implements a classic recursive backtracking algorithm

Fills the board if a valid solution exists

Handles edge cases and detects unsolvable puzzles

🗃️ Optional Features
File I/O Support

Load board from file (plain text, 0 for empty cells)

Save current board to a file

SudokuGenerator (optional)

Randomly generates new Sudoku puzzles

Supports difficulty levels by adjusting clues removed

