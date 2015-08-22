#include <iostream>
#include <memory>

using namespace std;

struct destination { };
struct connection { };

connection connect(destination *pd) {
    cout << "open" << endl;
    return connection();
}

void disconnect(connection c) {
    cout << "close" << endl;
}

void f(destination d) {
    cout << "directly" << endl;
    connection c = connect(&d);

    cout << endl;
}

void end_connection(connection *p) {
    disconnect(*p);
}

void f1(destination &d) {
    cout << "shared_ptr" << endl;
    connection c = connect(&d);
    shared_ptr<connection> p(&c, end_connection);

    cout << endl;
}

int main() {
    destination d;
    f(d);
    f1(d);
    return 0;
}
