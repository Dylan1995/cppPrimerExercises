#include <iostream>
#include <stdexcept>

using namespace std;

int main(int argc, char **argv){
    cout << "input the 2 numbers" << endl;
    int a, b;
    while(cin >> a >> b){
        try{
            if(!b){
                throw runtime_error("0!");
            }
            cout << a / b << endl;
        }
        catch(runtime_error err){
            cout << err.what() << endl;
            cout << "continue?" << endl;
            char ch;
            cin >> ch;
            if(ch != 'y'){
                break;
            }
        }
    }
    return 0;
}
