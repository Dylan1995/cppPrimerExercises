#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    map<string, size_t> word_count;
    string word;
    while (cin >> word && word != "0")
        ++word_count[word];
    for (auto &w: word_count)
        cout << w.first << " " << w.second << endl;
    return 0;
}
