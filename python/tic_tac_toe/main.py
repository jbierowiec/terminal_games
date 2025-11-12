#!/usr/bin/env python3
# Tic Tac Toe - Python version mirroring the provided C++ implementation

def display_board(board):
    print("\n")
    for i in range(3):
        print(" ", end="")
        for j in range(3):
            print(board[i][j], end="")
            if j < 2:
                print(" | ", end="")
        print()
        if i < 2:
            print("---+---+---")
    print("\n")


def check_winner(board):
    # Check rows
    for i in range(3):
        if board[i][0] == board[i][1] == board[i][2] and board[i][0] != " ":
            return board[i][0]
    # Check columns
    for j in range(3):
        if board[0][j] == board[1][j] == board[2][j] and board[0][j] != " ":
            return board[0][j]
    # Check diagonals
    if board[0][0] == board[1][1] == board[2][2] and board[0][0] != " ":
        return board[0][0]
    if board[0][2] == board[1][1] == board[2][0] and board[0][2] != " ":
        return board[0][2]
    return " "  # no winner yet


def is_draw(board):
    for i in range(3):
        for j in range(3):
            if board[i][j] == " ":
                return False
    return True


def main():
    board = [[" " for _ in range(3)] for _ in range(3)]
    turn = "X"
    game_over = False

    print()
    print("===== TIC TAC TOE =====")
    print()
    print("Player 1: X")
    print("Player 2: O")
    display_board(board)

    while not game_over:
        try:
            move = int(input(f"Player {turn}, enter your move (1-9): "))
        except ValueError:
            print("Invalid move. Please enter a number from 1 to 9.")
            continue

        if move < 1 or move > 9:
            print("Invalid move. Please enter a number from 1 to 9.")
            continue

        row = (move - 1) // 3
        col = (move - 1) % 3

        if board[row][col] != " ":
            print("That spot is already taken. Try again.")
        else:
            board[row][col] = turn
            display_board(board)

            winner = check_winner(board)
            if winner in ("X", "O"):
                print(f"Player {winner} wins!")
                game_over = True
            elif is_draw(board):
                print("It's a draw!")
                game_over = True
            else:
                turn = "O" if turn == "X" else "X"

    print()
    print("Game over.")
    print()


if __name__ == "__main__":
    main()
