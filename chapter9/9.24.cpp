#include <iostream>
#include <vector>

using namespace std;

int main( int argc, char **argv )
{
    vector<int> iv;
    cout << iv.at(0) << endl;
    cout << iv[0] << endl;
    cout << iv.front() << endl;
    cout << *(iv.begin());
    return 0;
}
