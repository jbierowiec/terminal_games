#include "HangmanGame.h"
#include "HangmanRenderer.h"

#include <algorithm>
#include <cctype>
#include <iostream>
#include <set>
#include <string>

using namespace std;

HangmanGame::HangmanGame(const string &secret,
                         const HangmanRenderer &renderer)
    : word_(secret), renderer_(renderer), mistakes_(0),
      maxMistakes_(renderer.maxMistakes()) {}

char HangmanGame::readLetter()
{
    while (true)
    {
        cout << "Enter a letter (A-Z): ";
        string s;
        if (!getline(cin, s))
            return '\0'; // EOF -> quit
        // trim spaces
        s.erase(remove_if(s.begin(), s.end(),
                          [](unsigned char c)
                          { return isspace(c); }),
                s.end());
        if (s.size() == 1 && isalpha(static_cast<unsigned char>(s[0])))
            return static_cast<char>(tolower(static_cast<unsigned char>(s[0])));
        cout << "Invalid input. Please type a single letter.\n";
    }
}

bool HangmanGame::allRevealed() const
{
    for (size_t i = 0; i < word_.size(); ++i)
    {
        char c = static_cast<char>(tolower(static_cast<unsigned char>(word_[i])));
        if (!guessed_.count(c))
            return false;
    }
    return true;
}

string HangmanGame::maskedWord() const
{
    string res;
    for (size_t i = 0; i < word_.size(); ++i)
    {
        char c = word_[i];
        if (guessed_.count(c))
            res.push_back(static_cast<char>(toupper(c)));
        else
            res.push_back('_');
        res.push_back(' ');
    }
    return res;
}

void HangmanGame::printState() const
{
    cout << "\n"
         << renderer_.stage(mistakes_) << "\n";
    cout << "Word: " << maskedWord() << "\n";

    cout << "Guessed: ";
    if (guessed_.empty())
        cout << "(none)";
    else
    {
        for (set<char>::const_iterator it = guessed_.begin();
             it != guessed_.end(); ++it)
        {
            cout << (char)toupper(*it) << ' ';
        }
    }
    cout << "\n";

    cout << "Wrong:   ";
    if (wrong_.empty())
        cout << "(none)";
    else
    {
        for (set<char>::const_iterator it = wrong_.begin();
             it != wrong_.end(); ++it)
        {
            cout << (char)toupper(*it) << ' ';
        }
    }
    cout << "\n";

    cout << "Lives remaining: " << (maxMistakes_ - mistakes_) << "\n";
}

bool HangmanGame::runRound()
{
    cout << "\n========== HANGMAN ==========\n";
    printState();

    while (mistakes_ < maxMistakes_)
    {
        char g = readLetter();
        if (g == '\0')
        {
            cout << "\nGoodbye!\n";
            return false; // quit early
        }

        if (guessed_.count(g) || wrong_.count(g))
        {
            cout << "You already tried '" << (char)toupper(g)
                 << "'. Try another.\n";
            continue;
        }

        if (word_.find(g) != string::npos)
        {
            guessed_.insert(g);
            cout << endl;
            cout << "Nice! '" << (char)toupper(g) << "' is in the word.\n";
        }
        else
        {
            wrong_.insert(g);
            mistakes_++;
            cout << endl;
            cout << "Oops! '" << (char)toupper(g) << "' is not in the word.\n";
        }

        printState();

        if (allRevealed())
        {
            cout << "You WIN! The word was: " << word_ << "\n";
            return true;
        }
    }

    cout << "You LOSE! The word was: " << word_ << "\n";
    return true;
}
