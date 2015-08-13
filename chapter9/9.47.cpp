#include <iostream>
#include <string>

using namespace std;

void find_char(string &s, const string &chars){
    string::size_type pos = 0;
    while( (pos = s.find_first_of(chars, pos)) != string::npos ) {
        cout << "pos: " << pos << ", char: " << s[pos] << endl;
        pos++;
    }
}

int main( int argc, char **argv )
{
    string s = "ab3ke13me";
    find_char(s, "0123456789");
    return 0;
}
