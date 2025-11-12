#ifndef HANGMANGAME_H
#define HANGMANGAME_H

#include <set>
#include <string>

using namespace std;

class HangmanRenderer;

class HangmanGame
{
public:
    HangmanGame(const string &secret, const HangmanRenderer &renderer);
    bool runRound();

private:
    char readLetter();
    bool allRevealed() const;
    string maskedWord() const;
    void printState() const;

    string word_;
    const HangmanRenderer &renderer_;
    set<char> guessed_;
    set<char> wrong_;
    int mistakes_;
    int maxMistakes_;
};

#endif
