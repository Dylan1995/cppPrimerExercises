#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main( int argc, char **argv )
{
    vector<char> cv = {'a', 'b', 'c'};
    string s(cv.data(), cv.size());
    cout << s << endl;
    return 0;
}
