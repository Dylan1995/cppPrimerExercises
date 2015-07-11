#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char **argv){
    vector<int> v;
    const int sz = 10;
    srand((unsigned)time(NULL));
    cout << "the vector is: " << endl;
    for(int i = 0; i < sz; ++i){
        v.push_back(rand() % 100);
        cout << v[i] << " ";
    }
    cout << endl;
    for(auto &val: v)
        val = (val % 2) ? val * 2 : val;
    for(auto it = v.cbegin(); it != v.cend(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}
