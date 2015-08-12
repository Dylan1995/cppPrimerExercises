#include <iostream>
#include <stdexcept>

using namespace std;

istream& f(istream &in){
    int v;
    while( in >> v, !in.eof() ) {
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
    f(cin);
    return 0;
}
