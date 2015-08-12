#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main( int argc, char **argv )
{
    list<char *> slist = {"c++", "java", "python"};
    vector<string> svec;
    svec.assign(slist.begin(), slist.end());
    cout << svec.size() << " " << svec[0] << endl; 
    return 0;
}
