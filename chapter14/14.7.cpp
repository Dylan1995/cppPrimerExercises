#include "14.7.h"
#include <algorithm>
#include <iostream>

pair<char*, char*> String::alloc_n_copy(const char *b, const char *e) {
    auto s = alloc.allocate(e - b);
    return {s, uninitialized_copy(b, e, s)};
}

void String::range_initializer(const char *first, const char *last) {
    auto new_str = alloc_n_copy(first, last);
    elements = new_str.first;
    end = new_str.second;
}

String::String(const char *s) {
    auto sl = s;
    while (*sl) sl++;
    range_initializer(s, ++sl);
}

String::String(const String &rhs) {
    range_initializer(rhs.elements, rhs.end);
    cout << "copy constructor" << endl;
}

void String::free() {
    if (elements) {
        for_each(elements, end, [this](char &c){alloc.destroy(&c);});
        alloc.deallocate(elements, end - elements);
    }
}

String::~String() {
    free();
}

String& String::operator=(const String &rhs) {
    auto new_str = alloc_n_copy(rhs.elements, rhs.end);
    free();
    elements = new_str.first;
    end = new_str.second;
    cout << "copy assignment" << endl;
    return *this;
}

ostream& operator<<(ostream &os, const String &s) {
    auto c = s.c_str();
    while (*c) os << *c++;
    return os;
}

int main() {
    String str("hello world");
    cout << str << endl;

    return 0;
}
