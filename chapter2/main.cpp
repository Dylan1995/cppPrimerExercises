#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    /*int ival = 1024;
    int &refval = ival;
    refval = 92;
    cout << "ival = " << ival << endl;
    int ii = refval;
    cout << "ii = " << ii << endl;
    int &refval3 = refval;
    refval3 = 81;
    cout << "refval = " << refval << endl;
    cout << "ival = " << ival << endl;

    int i, &ri = i;
    i = 5;
    ri = 10;
    cout << "i = " << i << " ri = " << ri << endl;*/

    int ival = 43;
    int *p = &ival;
    cout << *p << endl;
    *p = 9;
    cout << ival << endl;

    int i = 42;
    int *pi = 0;
    int *pi2 = &i;
    int *pi3;
    pi3 = pi2;
    cout << "pi3 = " << *pi3 << endl;
    pi2 = 0;
    cout << "pi3 = " << *pi3 << endl;

    /*const int ci = 1024;
    const int &ri = ci;
    r1 = 98;
    int &r2 = ci;*/
    return 0;
}

