#include <iostream>

using namespace std;

void reset(int &i){
    i = 0;
}

int main(int argc, char **argv){
    int num = 10;
    cout << num << endl;
    reset(num);
    cout << num << endl;
    return 0;
}
