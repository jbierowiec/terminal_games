# C++ Rock Paper Scissors Game

A simple terminal-based Rock Paper Scissors game written in C++, designed in a procedural programming style. This program demonstrates fundamental C++ concepts such as input handling, random number generation, conditional logic, and functions.

## Project Structure

```
rock_paper_scissors/
├── rps.cpp
└── rps.out
```

## Example Gameplay

```

===== ROCK PAPER SCISSORS (C++) =====
1. Rock
2. Paper
3. Scissors
4. Quit
Enter your choice (1-4): 1

You chose:      Rock
Computer chose: Rock

It's a tie!

===== SCOREBOARD =====
Player wins:   0
Computer wins: 0
Ties:          1
======================

Play another round? (y/n): y

===== ROCK PAPER SCISSORS (C++) =====
1. Rock
2. Paper
3. Scissors
4. Quit
Enter your choice (1-4): 2

You chose:      Paper
Computer chose: Paper

It's a tie!

===== SCOREBOARD =====
Player wins:   0
Computer wins: 0
Ties:          2
======================

Play another round? (y/n): y

===== ROCK PAPER SCISSORS (C++) =====
1. Rock
2. Paper
3. Scissors
4. Quit
Enter your choice (1-4): 1

You chose:      Rock
Computer chose: Rock

It's a tie!

===== SCOREBOARD =====
Player wins:   0
Computer wins: 0
Ties:          3
======================

Play another round? (y/n): y

===== ROCK PAPER SCISSORS (C++) =====
1. Rock
2. Paper
3. Scissors
4. Quit
Enter your choice (1-4): 3

You chose:      Scissors
Computer chose: Paper

You win this round!

===== SCOREBOARD =====
Player wins:   1
Computer wins: 0
Ties:          3
======================

Play another round? (y/n): n

Thanks for playing Rock Paper Scissors!
Final
===== SCOREBOARD =====
Player wins:   1
Computer wins: 0
Ties:          3
======================

Game over.

```

## How to Run

### 1. Compile the game

Make sure you have a C++17 or newer compiler (e.g., `g++`, `clang++`).

```bash
g++ -std=c++17 rps.cpp -o rps.out
```

### 2. Run the executable

```bash
./rps.out
```
