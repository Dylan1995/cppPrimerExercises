#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main( int argc, char **argv )
{
    list<int> ilist = {1, 2, 3, 4, 5};
    vector<int> ivec;
    
    vector<double> dvec(ilist.begin(), ilist.end());
    cout << dvec[0] << endl;
    return 0;
}
