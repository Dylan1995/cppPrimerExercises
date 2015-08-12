#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>

using namespace std;

istream &f(istream &in){
    string v;
    while( in >> v, in.eof() ) {
        if(in.bad())
            throw runtime_error("io");
        if(in.fail()){
            cerr << "error" << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main( int argc, char **argv )
{
    ostringstream msg;
    msg << "c++" << endl;
    istringstream in(msg.str());
    f(in);
    return 0;
}
