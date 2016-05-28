#include "13.47.h"
#include <algorithm>
#include <iostream>

pair<char*, char*> String::alloc_n_copy(const char *b, const char *e) {
    auto str = alloc.allocate(e - b);
    return {str, uninitialized_copy(b, e, str)};
}

void String::range_initializer(const char *first, const char *last) {
    auto new_str = alloc_n_copy(first, last);
    elements = new_str.first;
    end = new_str.second;
}

String::String(const char *s) {
    char *ns = const_cast<char*>(s);
    while (*ns) ns++;
    range_initializer(s, ++ns);
}

String::String(const String &rhs) {
    range_initializer(rhs.elements, rhs.end);
    cout << "copy constructor" << endl;
}

void String::free() {
    if (elements) {
        for_each(elements, end, [this](char &c) {alloc.destroy(&c);});
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
    cout << "copy-assignment" << endl;
    return *this;
}
