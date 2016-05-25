#include <iostream>

using namespace std;

class numbered {
private:
    static int seq;
public:
    numbered() {
        mysn = seq++;
    }
    numbered(numbered &n) {
        mysn = seq++;
    }
    int mysn;
};

int numbered::seq = 0;

void f1(const numbered &s) {
    cout << s.mysn << endl;
}

void f2(numbered &s) {
    cout << s.mysn << endl;
}

int main() {
    numbered a, b = a, c = b;
    f1(a);
    f1(b);
    f1(c);

    f2(a);
    f2(b);
    f2(c);

    return 0;
}
