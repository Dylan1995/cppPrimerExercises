#include "13.47.h"
#include <vector>
#include <iostream>

void foo(String s) {
    cout << s.c_str() << endl;
}

void bar(const String &s) {
    cout << s.c_str() << endl;
}

String baz() {
    String ret("world");
    return ret;
}

int main() {
    char text[] = "world";
    String s0;
    String s1("hello");
    String s2(s0);
    String s3 = s1;
    String s4(text);
    s2 = s1;

    foo(s1);
    bar(s1);
    foo("temp");
    bar("temp");
    String s5 = baz();

    vector<String> svec;
    svec.reserve(8);
    svec.push_back(s0);
    svec.push_back(s1);
    svec.push_back(s2);
    svec.push_back(s3);
    svec.push_back(s4);
    svec.push_back(s5);
    svec.push_back(baz());
    svec.push_back("good job");

    for (const auto &s: svec)
        cout << s.c_str() << endl;

    return 0;
}
