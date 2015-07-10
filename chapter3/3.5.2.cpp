#include <iostream>
#include <string>

using namespace std;

int main(){
     char cont = 'y';
     string s, res;
     cout << "input the first string" << endl;
     while(cin >> s){
          if(!res.size())
              res += s;
          else
              res = res + " " + s;
          cout << "contine?(y or n)" << endl;
          cin >> cont;
          if(cont == 'y')
              cout << "input the next string" << endl;
          else
              break;
     }
     cout << "the total string is " << res << endl;
     return 0;
}
