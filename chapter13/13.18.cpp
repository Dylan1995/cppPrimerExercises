#include <iostream>
#include <string>

using namespace std;

class Employee {
private:
    static int sn;
    string name;
    int mysn;
public:
    Employee() {
        mysn = sn++;
    }
    Employee(const string &s): name(s), mysn(sn++) {}
    Employee(Employee &e): name(e.name), mysn(sn++) {}
    Employee& operator=(Employee &rhs) {
        name = rhs.name;
        return *this;
    }
    const string& get_name() {
        return name;
    }
    int get_mysn() {
        return mysn;
    }
};

int Employee::sn = 0;

void f(Employee &e) {
    cout << e.get_name() << ": " << e.get_mysn() << endl;
}

int main() {
    Employee a("vigor"), b = a, c;
    c = b;
    f(a);
    f(b);
    f(c);

    return 0;
}
