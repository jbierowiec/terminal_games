import random

def get_player_choice():
    """
    Returns:
        0 for Rock, 1 for Paper, 2 for Scissors
        -1 if the player chooses to quit
    """
    print("\n===== ROCK PAPER SCISSORS (Python) =====")
    print("1. Rock")
    print("2. Paper")
    print("3. Scissors")
    print("4. Quit")

    while True:
        try:
            choice = int(input("Enter your choice (1-4): ").strip())
            if choice < 1 or choice > 4:
                print("Invalid choice. Please enter a number from 1 to 4.")
                continue

            if choice == 4:
                return -1

            return choice - 1  # Map 1–3 to 0–2
        except ValueError:
            print("Invalid input. Please enter a number from 1 to 4.")

def get_computer_choice():
    """Return 0 (Rock), 1 (Paper), or 2 (Scissors) at random."""
    return random.randint(0, 2)

def choice_to_string(choice):
    if choice == 0:
        return "Rock"
    elif choice == 1:
        return "Paper"
    else:
        return "Scissors"

def determine_winner(player, computer):
    """
    Returns:
        0 -> tie
        1 -> player wins
        2 -> computer wins
    """
    if player == computer:
        return 0

    # Rock(0) beats Scissors(2)
    # Paper(1) beats Rock(0)
    # Scissors(2) beats Paper(1)
    if ((player == 0 and computer == 2) or
        (player == 1 and computer == 0) or
        (player == 2 and computer == 1)):
        return 1

    return 2

def print_round_result(result):
    if result == 0:
        print("It's a tie!")
    elif result == 1:
        print("You win this round!")
    else:
        print("Computer wins this round!")

def print_score(player_wins, computer_wins, ties):
    print("\n===== SCOREBOARD =====")
    print(f"Player wins:   {player_wins}")
    print(f"Computer wins: {computer_wins}")
    print(f"Ties:          {ties}")
    print("======================\n")

def main():
    random.seed()

    player_wins = 0
    computer_wins = 0
    ties = 0

    playing = True

    while playing:
        player_choice = get_player_choice()
        if player_choice == -1:
            # Player chose to quit
            break

        computer_choice = get_computer_choice()

        print()
        print(f"You chose:      {choice_to_string(player_choice)}")
        print(f"Computer chose: {choice_to_string(computer_choice)}")
        print()

        result = determine_winner(player_choice, computer_choice)

        if result == 0:
            ties += 1
        elif result == 1:
            player_wins += 1
        else:
            computer_wins += 1

        print_round_result(result)
        print_score(player_wins, computer_wins, ties)

        again = input("Play another round? (y/n): ").strip().lower()
        if again != "y":
            playing = False

    print()
    print("Thanks for playing Rock Paper Scissors!")
    print("Final ", end="")
    print_score(player_wins, computer_wins, ties)
    print("Game over.")
    print()

if __name__ == "__main__":
    main()
