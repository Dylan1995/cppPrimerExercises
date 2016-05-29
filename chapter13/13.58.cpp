#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Foo {
public:
    Foo sorted()&&;
    Foo sorted() const&;

private:
    vector<int> data;
};

Foo Foo::sorted() && {
    sort(data.begin(), data.end());
    cout << "&&" << endl;
    return *this;
}

Foo Foo::sorted() const& {
    cout << "const&" << endl;
    return Foo(*this).sorted();
}

int main() {
    Foo().sorted();
    Foo f;
    f.sorted();

    return 0;
}
