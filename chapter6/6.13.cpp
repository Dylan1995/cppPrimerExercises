#include <iostream>

using namespace std;

void a(int i){
    ++i;
    cout << i << endl;
}

void b(int &j){
    ++j;
    cout << j << endl;
}

int main(int argc, char **argv){
    int s = 0, t = 11;
    a(s);
    cout << s << endl;
    b(t);
    cout << t << endl;
    return 0;
}
