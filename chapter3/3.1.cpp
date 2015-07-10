#include <iostream>

using std::cout;
using std::endl;

int main(){
     int sum = 0, i = 50;
     while(i <= 100){
          sum += i;
          i++;
     }
     cout << "the sum is " << sum << endl;
     return 0;
}
