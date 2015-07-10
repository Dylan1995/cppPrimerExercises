#include <iostream>
#include <string>

using namespace std;

int main(){
    string s1, s2;
    cout << "input the 2 strings" << endl;
    cin >> s1 >> s2;
    auto len1 = s1.size(), len2 = s2.size();
    if(len1 == len2)
        cout << "equal" << endl;
    else if(len1 > len2)
        cout << s1 << " > " << s2 << endl;
    else
        cout << s1 << " < " << s2 << endl;
    return 0;
}
