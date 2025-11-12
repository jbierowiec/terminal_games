#ifndef WORDLIST_H
#define WORDLIST_H

#include <string>
#include <vector>

using namespace std;

class WordList
{
public:
    bool loadFromJson(const string &path);
    string pickRandom() const;
    inline const vector<string> &words() const { return words_; }

private:
    vector<string> words_;
};

#endif
