#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

string& trans(string &s) {
    for (int p = 0; p < s.size(); ++p) {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= ('A' - 'a');
        else if (s[p] == ',' || s[p] =='.')
            s.erase(p, 1);
    }
    return s;
}

int main(int argc, char **argv) {
    map<string, size_t> word_count;
    string word;
    while (cin >> word)
        ++word_count[word];
    for (auto &w: word_count)
        cout << w.first << " " << w.second << endl;
    return 0;
}
