#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 0 = Rock, 1 = Paper, 2 = Scissors
// Returns -1 if the user chooses to quit
int getPlayerChoice()
{
    int choice;
    cout << "\n===== ROCK PAPER SCISSORS (C++) =====\n";
    cout << "1. Rock\n";
    cout << "2. Paper\n";
    cout << "3. Scissors\n";
    cout << "4. Quit\n";
    cout << "Enter your choice (1-4): ";
    cin >> choice;

    // Basic input validation
    while (cin.fail() || choice < 1 || choice > 4)
    {
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid choice. Please enter a number from 1 to 4: ";
        cin >> choice;
    }

    if (choice == 4)
        return -1; // Quit

    // Convert 1–3 to 0–2
    return choice - 1;
}

int getComputerChoice()
{
    // 0, 1, or 2
    return rand() % 3;
}

string choiceToString(int choice)
{
    if (choice == 0)
        return "Rock";
    else if (choice == 1)
        return "Paper";
    else
        return "Scissors";
}

// Returns:
// 0 -> tie
// 1 -> player wins
// 2 -> computer wins
int determineWinner(int player, int computer)
{
    if (player == computer)
        return 0; // tie

    // Rock(0) beats Scissors(2)
    // Paper(1) beats Rock(0)
    // Scissors(2) beats Paper(1)
    if ((player == 0 && computer == 2) ||
        (player == 1 && computer == 0) ||
        (player == 2 && computer == 1))
        return 1; // player wins

    return 2; // computer wins
}

void printRoundResult(int result)
{
    if (result == 0)
        cout << "It's a tie!\n";
    else if (result == 1)
        cout << "You win this round!\n";
    else
        cout << "Computer wins this round!\n";
}

void printScore(int playerWins, int computerWins, int ties)
{
    cout << "\n===== SCOREBOARD =====\n";
    cout << "Player wins:   " << playerWins << "\n";
    cout << "Computer wins: " << computerWins << "\n";
    cout << "Ties:          " << ties << "\n";
    cout << "======================\n\n";
}

int main()
{
    // Seed random generator once
    srand(static_cast<unsigned int>(time(0)));

    int playerWins = 0;
    int computerWins = 0;
    int ties = 0;

    bool playing = true;

    while (playing)
    {
        int playerChoice = getPlayerChoice();
        if (playerChoice == -1)
        {
            // User chose to quit
            break;
        }

        int computerChoice = getComputerChoice();

        cout << "\nYou chose:      " << choiceToString(playerChoice) << "\n";
        cout << "Computer chose: " << choiceToString(computerChoice) << "\n\n";

        int result = determineWinner(playerChoice, computerChoice);

        if (result == 0)
            ties++;
        else if (result == 1)
            playerWins++;
        else
            computerWins++;

        printRoundResult(result);
        printScore(playerWins, computerWins, ties);

        char again;
        cout << "Play another round? (y/n): ";
        cin >> again;

        if (again != 'y' && again != 'Y')
        {
            playing = false;
        }
    }

    cout << endl;
    cout << "Thanks for playing Rock Paper Scissors!\n";
    cout << "Final ";
    printScore(playerWins, computerWins, ties);
    cout << "Game over.\n"
         << endl;

    return 0;
}
