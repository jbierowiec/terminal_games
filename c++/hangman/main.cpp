#include "WordList.h"
#include "HangmanRenderer.h"
#include "HangmanGame.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
    WordList wl;
    if (!wl.loadFromJson("words.json"))
    {
        cout << "Failed to load words.json (must be a JSON array of alphabetic strings).\n";
        return 1;
    }

    HangmanRenderer renderer;

    while (true)
    {
        string word = wl.pickRandom();
        HangmanGame game(word, renderer);

        bool finished = game.runRound();
        if (!finished)
            break; 

        cout << "\nPlay again? (y/n): ";
        string ans;
        if (!getline(cin, ans))
            break;
        if (ans.empty() || (ans[0] != 'y' && ans[0] != 'Y'))
            break;
    }

    cout << endl;
    cout << "Thanks for playing!\n";
    return 0;
}
