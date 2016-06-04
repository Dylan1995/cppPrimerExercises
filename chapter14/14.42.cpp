#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <functional>

using namespace std;

int main() {
    vector<int> ivec{1, 111, 1111, 11111};
    int cnt = count_if(ivec.cbegin(), ivec.cend(),
            bind(greater<int>(), placeholders::_1, 1024));
    cout << cnt << endl;

    vector<string> svec{"pooh", "pooh", "pezy", "pooh"};
    auto found = find_if(svec.cbegin(), svec.cend(),
            bind(not_equal_to<string>(), placeholders::_1, "pooh"));
    cout << *found << endl;

    transform(ivec.begin(), ivec.end(), ivec.begin(),
            bind(multiplies<int>(), placeholders::_1, 2));
    for (int i: ivec)
        cout << i << " ";
    cout << endl;

    return 0;
}
