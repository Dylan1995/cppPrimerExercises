#include <iostream>

using namespace std;

void swap1(int *p, int *q){
    int *temp = p;
    p = q;
    q = temp;
}

void swap2(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;
}

void swap3(int *&p, int *&q){
    int *temp = p;
    p = q;
    q = temp;
}

int main(int argc, char **argv){
    int a = 5, b = 10;
    int *p = &a, *q = &b;
    cout << "before:" << endl;
    cout << "p:" << *p << ",q:" << *q << endl;
    swap1(p, q);
    cout << "after:" << endl;
    cout << "p:" << *p << ",q:" << *q << endl;

    a = 5, b = 10;
    p = &a, q = &b;
    cout << "before:" << endl;
    cout << "p:" << *p << ",q:" << *q << endl;
    swap2(p, q);
    cout << "after:" << endl;
    cout << "p:" << *p << ",q:" << *q << endl;

    a = 5, b = 10;
    p = &a, q = &b;
    cout << "before:" << endl;
    cout << "p:" << *p << ",q:" << *q << endl;
    swap3(p, q);
    cout << "after:" << endl;
    cout << "p:" << *p << ",q:" << *q << endl;
    return 0;
}
