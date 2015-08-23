#include <iostream>
#include <string>
#include <list>
#include <cassert>
#include <memory>
#include <vector>
using namespace std;

int main(int argc, char **argv) {
    vector<string> v1;
    {
        vector<string> v2 = {
            "a", "b", "c"
        };
        v1 = v2;
    }
    cout << v1.size() << endl;
    int *p = new int[5];
    *p = 3;
    cout << *p << endl;
    *(p + 3) = 4;
    cout << p[3] << endl;
    cout << p[1] << endl;
    return 0;
}
