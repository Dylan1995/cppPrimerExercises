#include <iostream>
#include <vector>
#include <string>

using namespace std;

void name_string(string &name, const string &prefix, const string &suffix){
    name.insert(0, " ");
    name.insert(0, prefix);
    name.insert(name.size(), " ");
    name.insert(name.size(), suffix);
}

int main( int argc, char **argv )
{
    string s = "vigor";
    name_string(s, "Mr.", "II");
    cout << s << endl;
    return 0;
}
