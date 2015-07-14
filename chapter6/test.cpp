#include <iostream>

using namespace std;

int f(){
    static int cnt = 0;
    return ++cnt;
}

char &get_val(string &str, int x){
    return str[x];
}

int main(int argc, char **argv){
    for(int i = 0; i < 10; ++i){
        cout << f() << endl;
    }
    int a[] = {
        3, 5
    };
    cout << end(a) - begin(a) << endl;
    string s = "abc";
    cout << s << endl;
    get_val(s, 0) = 'A';
    cout << s << endl;
    return 0;
}
