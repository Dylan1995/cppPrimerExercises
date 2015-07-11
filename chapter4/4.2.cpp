#include <time.h>
#include <stdlib.h>
#include <vector>
#include <iostream>

using namespace std;

int main(int argc, char **argv){
    vector<int> vec;
    srand((unsigned)time(NULL));
    cout << "the random number: " << endl;
    for(int i = 0; i < 10; ++i){
        vec.push_back(rand() % 100);
    }
    cout << "the vector is " << endl;
    for(auto c: vec)
        cout << c << " ";
    cout << endl;
    cout << "==============" << endl;
    cout << "*vec.begin() is: " << *vec.begin() << endl;
    cout << "*(vec.begin()) is: " << *(vec.begin()) << endl;
    cout << "*vec.begin() + 1 is: " << *vec.begin() + 1 << endl;
    cout << "(*(vec.begin())) + 1 is: " << (*(vec.begin())) + 1 << endl;
    return 0;
}
