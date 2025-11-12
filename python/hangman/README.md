# Python Hangman Game

A simple terminal-based Hangman game written in Python, designed in an object-oriented programming (OOP) style. This program demonstrates practical OOP design and file handling.

## Project Structure

```
hangman/
├── hangman_game.py
├── hangman_renderer.py
├── word_list.py
├── main.py
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

Oops! 'A' is not in the word.


  +---+
  |   |
  O   |
      |
      |
      |
=========

Word: _ _ _ _ _ _ _ _ _ _ _ _ _
Guessed: (none)
Wrong:   A
Lives remaining: 5
Enter a letter (A-Z): e

Oops! 'E' is not in the word.


  +---+
  |   |
  O   |
  |   |
      |
      |
=========

Word: _ _ _ _ _ _ _ _ _ _ _ _ _
Guessed: (none)
Wrong:   A E
Lives remaining: 4
Enter a letter (A-Z): i

Nice! 'I' is in the word.


  +---+
  |   |
  O   |
  |   |
      |
      |
=========

Word: _ I _ _ _ _ _ I _ _ _ _ _
.
.
.
Guessed: C I O S T U
Wrong:   A E V Y
Lives remaining: 2
Enter a letter (A-Z): n

Nice! 'N' is in the word.


  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========

Word: _ I S C O N T I N U O U S
Guessed: C I N O S T U
Wrong:   A E V Y
Lives remaining: 2
Enter a letter (A-Z): d

Nice! 'D' is in the word.


  +---+
  |   |
  O   |
 /|\  |
      |
      |
=========

Word: D I S C O N T I N U O U S
Guessed: C D I N O S T U
Wrong:   A E V Y
Lives remaining: 2
You WIN! The word was: discontinuous

Play again? (y/n): n

Thanks for playing!
```

## How to Run

### 1. Ensure you have Python 3 installed

Check your version:

```bash
python3 --version
```

### 2. Run the game

```bash
python main.py
```
