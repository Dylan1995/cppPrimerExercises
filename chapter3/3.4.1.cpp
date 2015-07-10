#include <iostream>
#include <string>

using namespace std;

int main(){
     string s1, s2;
     cout << "input the two strings" << endl;
     cin >> s1 >> s2;
     if(s1 == s2)
         cout << "equal" << endl;
     else if(s1 > s2)
         cout << s1 << " > " << s2 << endl;
     else
         cout << s1 << " > " << s2 << endl;
     return 0;
}
