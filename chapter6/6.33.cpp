#include <iostream>
#include <vector>

using namespace std;

void p(vector<int> v, unsigned i){
    unsigned sz = v.size();
    if(!v.empty() && i < sz){
        cout << v[i] << endl;
        p(v, i + 1);
    }
}

int main(int argc, char **argv){
    vector<int> v = {
        1, 3, 5 ,7, 9, 11, 13, 15
    };
    p(v, 0);
    return 0;
}
