# C++ Hangman Game

A simple terminal-based Hangman game written in C++, designed in an object-oriented programming (OOP) style. This program demonstrates practical OOP design and file handling.

## Project Structure

```
hangman/
├── HangmanGame.h
├── HangmanRenderer.h
├── WordList.h
├── HangmanGame.cpp
├── HangmanRenderer.cpp
├── WordList.cpp
├── main.cpp
├── hangman.out
└── words.json
```

## Overview of classes

| Class                 | Responsibility                                                         |
| --------------------- | ---------------------------------------------------------------------- |
| **`HangmanGame`**     | Handles the game loop, player input, word masking, and win/lose logic. |
| **`HangmanRenderer`** | Stores and displays ASCII art of the hangman at each mistake level.    |
| **`WordList`**        | Loads a JSON file of words, validates them, and returns a random word. |

## Example Gameplay

```
========== HANGMAN ==========

  +---+
  |   |
      |
      |
      |
      |
=========

Word: _ _ _ _ _ _ _ _ _ _ _ _ _
Guessed: (none)
Wrong:   (none)
Lives remaining: 6
Enter a letter (A-Z): a

Nice! 'A' is in the word.

  +---+
  |   |
      |
      |
      |
      |
=========

Word: _ _ _ _ _ _ _ _ _ _ A _ _
Guessed: A
Wrong:   (none)
Lives remaining: 6
Enter a letter (A-Z): e

Nice! 'E' is in the word.

  +---+
  |   |
      |
      |
      |
      |
=========

Word: _ _ _ _ _ E _ _ _ _ A _ _
.
.
.
Guessed: A D E I N O R T Y
Wrong:   B M U V X
Lives remaining: 1
Enter a letter (A-Z): s

Nice! 'S' is in the word.

  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========

Word: D I S _ R E T I O N A R Y
Guessed: A D E I N O R S T Y
Wrong:   B M U V X
Lives remaining: 1
Enter a letter (A-Z): c

Nice! 'C' is in the word.

  +---+
  |   |
  O   |
 /|\  |
 /    |
      |
=========

Word: D I S C R E T I O N A R Y
Guessed: A C D E I N O R S T Y
Wrong:   B M U V X
Lives remaining: 1
You WIN! The word was: discretionary

Play again? (y/n): n

Thanks for playing!
```

## How to Run

### 1. Compile the game

Make sure you have a C++17 or newer compiler (e.g., `g++`, `clang++`).

```bash
g++ -std=c++17 main.cpp HangmanGame.cpp HangmanRenderer.cpp WordList.cpp -o hangman.out
```

### 2. Run the executable

```bash
./hangman.out
```
