#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main( int argc, char **argv )
{
    vector<string> vs = {"123", "+456", "-789"};
    int sum = 0;
    for(auto iter = vs.begin(); iter != vs.end(); iter++)
        sum += stoi(*iter);
    cout << sum << endl;
    return 0;
}
