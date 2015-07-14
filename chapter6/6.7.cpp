#include <iostream>

using namespace std;

unsigned cnt(){
    static unsigned c = -1;
    ++c;
    return c;
}

int main(int argc, char **argv){
    char ch;
    while(cin >> ch)
        cout << cnt() << "times" << endl;
    return 0;
}
