#include <iostream>
#include <utility>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(int argc, char **argv) {
    vector<pair<string, int> > data;
    string s;
    int v;
    while (cin >> s >> v)
        data.push_back(pair<string, int>(s, v));
    for (auto &d: data)
        cout << d.first << " " << d.second << endl;
    return 0;
}
