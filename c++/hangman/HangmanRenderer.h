#ifndef HANGMANRENDERER_H
#define HANGMANRENDERER_H

#include <string>
#include <vector>

using namespace std;

class HangmanRenderer
{
public:
    HangmanRenderer();

    const string &stage(int mistakes) const;
    inline int maxMistakes() const { return (int)stages_.size() - 1; }

private:
    vector<string> stages_;
};

#endif
