#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class ShorterString {
public:
    bool operator()(string const &s1, string const &s2) const {
        return s1.size() < s2.size();
    }
};

class BiggerEqual {
    size_t sz;
public:
    BiggerEqual(size_t s): sz(s) {}
    bool operator()(string const &s) {
        return s.size() >= sz;
    }
};

class Print {
    void operator()(string const &s) {
        cout << s << " ";
    }
};

string make_plural(size_t ctr, string const &word, string const &ending) {
    return (ctr > 1) ? word + ending : word;
}

void elimDups(vector<string> &words) {
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

void biggies(vector<string> &words, vector<string>::size_type sz) {
    elimDups(words);
    stable_sort(words.begin(), words.end(), ShorterString());
    auto wc = find_if(words.begin(), words.end(), BiggerEqual(sz));
    auto cnt = words.end() - wc;
    cout << cnt << " " << make_plural(cnt, "word", "s") << " of length "
        << sz << " or longer" << endl;
    for_each(wc, words.end(), Print());
    cout << endl;
}

int main() {
    vector<string> vec {
        "fox", "jumps", "over", "quick", "end",
            "red", "slow", "the", "turtle"
    };
    biggies(vec, 4);

    return 0;
}
