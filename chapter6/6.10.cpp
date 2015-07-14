#include <iostream>

using namespace std;

void mySwap(int *p, int *q){
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

int main(int argc, char **argv){
    int a = 5, b = 10;
    int *r = &a, *s = &b;
    cout << a << " " << b << endl;
    mySwap(r, s);
    cout << a << " " << b << endl;
    return 0;
}
