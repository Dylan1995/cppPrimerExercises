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
    string *ps = new string;
    if (*ps == "") cout << "ok" << endl;
    unique_ptr<double> upd(new double(3.14));
    cout << *upd << endl;
    unique_ptr<int> upi1(new int(123));
    unique_ptr<int> upi2(upi1.release());
    cout << *upi2 << endl;
    return 0;
}
