#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main( int argc, char **argv )
{
    ifstream in(argv[1]);
    if(!in){
        cout << "error" << endl;
        exit(1);
    }
    vector<int> iv;
    int val;
    while(cin >> val)
        iv.push_back(val);
    cin >> val;
    cout << count(iv.begin(), iv.end(), val) << endl;
    return 0;
}
