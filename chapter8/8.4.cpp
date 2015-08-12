#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main( int argc, char **argv )
{
    ifstream in("data");
    if(!in){
        cerr << "error" << endl;
        return -1;
    }
    string line;
    std::vector<string> words;
    while( getline(in, line) ) {
        words.push_back(line);
    }
    in.close();
    vector<string>::const_iterator it = words.begin();
    while( it != words.end() ) {
        cout << *it  << endl;
        ++it;
    }
    return 0;
}
