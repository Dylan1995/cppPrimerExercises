#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool judge(const string &s) {
    return s.size() >= 5;
}

int main( int argc, char **argv ) {
    ifstream in(argv[1]);
    if (!in) {
        cout << "error" << endl;
        exit(1);
    }
    vector<string> words;
    string word;
    while (in >> word)
        words.push_back(word);
    auto iter = partition(words.begin(), words.end(), judge);
    return 0;
}
