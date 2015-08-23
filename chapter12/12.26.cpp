#include <iostream>
#include <string>
#include <memory>

using namespace std;

int main() {
    allocator<string> alloc;
    auto const p = alloc.allocate(5);
    string s;
    string *q = p;
    while (cin >> s && q != p + 5)
        alloc.construct(q++, s);
    const size_t size = q - p;

    for (size_t i = 0; i < size; i++)
        cout << p[i] << " " << endl;

    while (q != p)
        alloc.destroy(--q);
    alloc.deallocate(p, 5);

    return 0;
}
