#include <iostream>

using namespace std;

int &f(int *a, int i){
    return a[i];
}

int main(int argc, char **argv){
    int a[10];
    for(int i = 0; i < 10; ++i){
        f(a, i) = i;
    }
    for(int i = 0; i < 10; ++i){
        cout << a[i] << endl;
    }
    return 0;
}
