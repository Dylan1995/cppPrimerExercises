#include <iostream>

using namespace std;

double add(double a, double b){
    double res = a + b;
    static unsigned cnt = 0;
    ++cnt;
    cout << cnt << "times" << endl;
    return res;
}

int main(int argc, char **argv){
    double num1, num2;
    while(cin >> num1 >> num2){
        cout << "the sum is " << add(num1, num2) << endl;
    }
    return 0;
}
