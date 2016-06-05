#include <iostream>
#include <string>
#include <map>
#include <functional>

using namespace std;

int add(int x, int y) {
    return x + y;
}

auto mod = [](int x, int y) { return x % y; };

struct my_div {
    int operator()(int x, int y) {
        return x / y;
    }
};

map<string, function<int(int, int)>> binops = {
    {"+", add},
    {"-", minus<int>()},
    {"/", my_div()},
    {"*", [](int x, int y) { return x * y; }},
    {"%", mod}
};

int main() {
    while (1) {
        cout << "enter: num op num\n";
        int n1, n2;
        string op;
        cin >> n1 >> op >> n2;
        cout << binops[op](n1, n2) << endl;
    }

    return 0;
}
