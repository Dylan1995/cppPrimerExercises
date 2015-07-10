#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(){
     vector<string> v;
     string s;
     char cont = 'y';
     while(cin >> s){
          v.push_back(s);
          cout << "continue?" << endl;
          cin >> cont;
          if(cont != 'y')
              break;
     }

     for(auto &mem: v){
          for(auto &c: mem)
              c = toupper(c);
          cout << mem << endl;
     }
     return 0;
}
