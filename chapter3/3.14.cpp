#include <iostream>
#include <vector>

using namespace std;

int main(){
     vector<int> v;
     int i;
     char cont = 'y';
     while(cin >> i){
          v.push_back(i);
          cout << "continue?" << endl;
          cin >> cont;
          if(cont != 'y')
              break;
     }
     for(auto mem: v)
         cout << mem << " ";
     cout << endl;
     return 0;
}
