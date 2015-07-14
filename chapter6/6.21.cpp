#include <iostream>
#include <string>
#include <time.h>
#include <stdlib.h>

using namespace std;

int compare(const int val, const int *p){
    return (val > *p) ? val : *p;
}

int main(int argc, char **argv){
    srand((unsigned)time(NULL));
    int a[10];
    for(auto &i: a)
        i = rand() % 100;
    int j;
    cin >> j;
    cout << "the bigger is " << compare(j, a) << endl;
    cout << "the array is " << endl;
    for(auto i: a)
        cout << i << " ";
    cout << endl;
    return 0;
}
