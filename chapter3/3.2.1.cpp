#include <iostream>
#include <string>

using namespace std;

int main(){
     string line;
     cout << "input the string" << endl;
     while(getline(cin, line))
         cout << line << endl;
     return 0;
}
