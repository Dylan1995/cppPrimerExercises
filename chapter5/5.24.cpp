#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char **argv){
    cout << "input the 2 numbers" << endl;
    int a, b;
    cin >> a >> b;
    if(!b)
        throw runtime_error("0!");
    cout << a / b << endl;
    return 0;
}
