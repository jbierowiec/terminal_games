#include "WordList.h"
#include <algorithm>
#include <cctype>
#include <chrono>
#include <fstream>
#include <random>
#include <regex>
#include <stdexcept>

using namespace std;

bool WordList::loadFromJson(const string &path)
{
    words_.clear();

    ifstream in(path.c_str());
    if (!in.is_open())
        return false;

    string content((istreambuf_iterator<char>(in)), istreambuf_iterator<char>());
    in.close();

    content = regex_replace(content, regex("//[^\\n\\r]*"), "");

    if (content.find('[') == string::npos || content.find(']') == string::npos)
        return false;

    regex rx("\"([^\"\\\\]*)\"");
    smatch m;
    string::const_iterator begin = content.begin();
    string::const_iterator end = content.end();

    vector<string> tmp;
    while (regex_search(begin, end, m, rx))
    {
        string w = m[1].str();

        bool ok = !w.empty();
        for (size_t i = 0; i < w.size(); ++i)
        {
            unsigned char c = static_cast<unsigned char>(w[i]);
            if (!isalpha(c))
            {
                ok = false;
                break;
            }
        }

        if (ok)
        {
            transform(w.begin(), w.end(), w.begin(),
                      [](unsigned char c)
                      { return static_cast<char>(tolower(c)); });
            tmp.push_back(w);
        }
        begin = m.suffix().first;
    }

    if (tmp.empty())
        return false;
    words_.swap(tmp);
    return true;
}

string WordList::pickRandom() const
{
    if (words_.empty())
        throw runtime_error("WordList is empty. Did you load it?");

    static mt19937 rng((unsigned)chrono::high_resolution_clock::now()
                           .time_since_epoch()
                           .count());
    uniform_int_distribution<size_t> dist(0, words_.size() - 1);
    return words_[dist(rng)];
}
