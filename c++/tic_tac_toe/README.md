# C++ Tic Tac Toe Game

A simple terminal-based Tic Tac Toe game written in C++, designed in a procedural programming style. This program demonstrates fundamental C++ concepts such as input handling, conditional logic, and array traversal.

## Project Structure

```
tic_tac_toe/
├── tictactoe.cpp
└── tictactoe.out
```

## Example Gameplay

```

===== TIC TAC TOE =====

Player 1: X
Player 2: O

   |   |
---+---+---
   |   |
---+---+---
   |   |

Player X, enter your move (1-9): 1

 X |   |
---+---+---
   |   |
---+---+---
   |   |

Player O, enter your move (1-9): 2

 X | O |
---+---+---
   |   |
---+---+---
   |   |

Player X, enter your move (1-9): 5

 X | O |
---+---+---
   | X |
---+---+---
   |   |

Player O, enter your move (1-9): 9

 X | O |
---+---+---
   | X |
---+---+---
   |   | O

Player X, enter your move (1-9): 7

 X | O |
---+---+---
   | X |
---+---+---
 X |   | O

Player O, enter your move (1-9): 4

 X | O |
---+---+---
 O | X |
---+---+---
 X |   | O

Player X, enter your move (1-9): 3

 X | O | X
---+---+---
 O | X |
---+---+---
 X |   | O

Player X wins!

Game over.

```

## How to Run

### 1. Compile the game

Make sure you have a C++17 or newer compiler (e.g., `g++`, `clang++`).

```bash
g++ -std=c++17 tictactoe.cpp -o tictactoe.out
```

### 2. Run the executable

```bash
./tictactoe.out
```
