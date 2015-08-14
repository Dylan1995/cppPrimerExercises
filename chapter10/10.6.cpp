#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main (int argc, char **argv)
{
    ifstream in(argv[1]);
    if (!in) {
        cout << "error" << endl;
        exit(1);
    }

    vector<int> vi;
    int val;
    while (in >> val) {
        vi.push_back(val);
        cout << val << " ";
    }
    cout << endl;
    
    fiil_n(vi.begin(), vi.end(), 0);
    for (auto iter = vi.begin(); iter != vi.end(); iter++)
        cout << *iter << " ";
    return 0;
}
