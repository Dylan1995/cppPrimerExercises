#include <iostream>

using namespace std;

void mySwap(int &i, int &j){
    int k = i;
    i = j;
    j = k;
}

int main(int argc, char **argv){
    int a = 13, b = 6;
    cout << a << " " << b << endl;
    mySwap(a, b);
    cout << a << " " << b << endl;
    return 0;
}
