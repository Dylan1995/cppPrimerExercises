#include <iostream>
#include <string>

using namespace std;

bool hasUpper(const string& str){
    for(auto c: str)
        if(isupper(c))
            return 1;
    return false;
}

void changeToLower(string& str){
    for(auto &c: str)
        c = tolower(c);
}

int main(int argc, char **argv){
    string str;
    cin >> str;
    if(hasUpper(str)){
        changeToLower(str);
        cout << str << endl;
    }
    else
        cout << "heh" << endl;
    return 0;
}
