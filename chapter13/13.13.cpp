#include <iostream>
#include <vector>

struct X {
    X() {
        std::cout << "X()" << std::endl;
    }
    X(const X&) {
        std::cout << "X(const X&)" << std::endl;
    }
    X& operator=(const X&) {
        std::cout << "X& operator=(const X&)" << std::endl;
        return *this;
    }
    ~X() {
        std::cout << "~X()" << std::endl;
    }
};

void f1(X x) {}
void f2(X &x) {}

int main() {
    std::cout << "local variables: " << std::endl;
    X x;
    std::cout << std::endl;

    std::cout << "none-reference argument pass: " << std::endl;
    f1(x);
    std::cout << std::endl;

    std::cout << "reference argument pass: " << std::endl;

    f2(x);
    std::cout << std::endl;

    std::cout << "dynamic allocate: " << std::endl;
    X *px = new X;
    std::cout << std::endl;

    std::cout << "push into a container: " << std::endl;
    std::vector<X> vx;
    vx.push_back(x);
    std::cout << std::endl;

    std::cout << "release dynamic-allocated object: " << std::endl;
    delete px;
    std::cout << std::endl;

    std::cout << "indirect initializatio and assignment: " << std::endl;
    X y = x;
    y = x;
    std::cout << std::endl;

    std::cout << "END" << std::endl;

    return 0;
}
