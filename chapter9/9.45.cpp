#include <iostream>
#include <vector>
#include <string>

using namespace std;

void name_string(string &name, const string &prefix, const string &suffix){
    name.insert(name.begin(), 1, ' ');
    name.insert(name.begin(), prefix.begin(), prefix.end());
    name.append(" ");
    name.append(suffix.begin(), suffix.end());
}

int main( int argc, char **argv )
{
    string s = "vigor";
    name_string(s, "Mr.", "II");
    cout << s << endl;

    s = "hehe";
    name_string(s, "Ms.", "III");
    cout << s << endl;
    return 0;
}
