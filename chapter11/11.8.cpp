#include <iostream>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

string& trans(string &s) {
    for( int p = 0; p < s.size(); ++p ) {
        if (s[p] >= 'A' && s[p] <= 'Z')
            s[p] -= ('A' - 'a');
        else if (s[p] == ',' || s[p] == '.')
            s.erase(p, 1);
    }
    return s;
}

int main(int argc, char **argv) {
    set<string> unique_word;
    string word;
    while(cin >> word) {
        trans(word);
        unique_word.insert(word);
    }

    for (auto &w: unique_word)
        cout << w << " ";
    cout << endl;
    return 0;
}
