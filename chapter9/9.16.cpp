#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool judge(vector<int> &ivec, list<int> &ilist){
    if(ivec.size() != ilist.size())
        return false;
    auto vb = ivec.begin();
    auto ve = ivec.end();
    auto lb = ilist.begin();

    while( vb != ve ) {
        if(*vb != *lb)
            return false;
        vb++;
        lb++;
    }
    return true;
}

int main( int argc, char **argv )
{
    list<int> ilist = {1, 2, 3, 4, 5};
    vector<int> ivec = {1, 2, 3, 4 ,5};
    cout << judge(ivec, ilist);
    return 0;
}
