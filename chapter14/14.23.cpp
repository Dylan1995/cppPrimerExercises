#include "14.23.h"
#include <algorithm>
#include <iostream>
#include <vector>

void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
}

pair<string*, string*>
StrVec::alloc_n_copy(const string *b, const string *e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
    if (elements) {
        for_each(elements, first_free,
                [this](string &rhs){alloc.destroy(&rhs);});
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::range_initialize(const string *first, const string *last) {
    auto new_data = alloc_n_copy(first, last);
    elements = new_data.first;
    first_free = cap = new_data.second;
}

StrVec::StrVec(const StrVec &rhs) {
    range_initialize(rhs.begin(), rhs.end());
}

StrVec::StrVec(initializer_list<string> il) {
    range_initialize(il.begin(), il.end());
}

StrVec::~StrVec() {
    free();
}

StrVec& StrVec::operator=(const StrVec &rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

void StrVec::alloc_n_move(size_t new_cap) {
    auto new_data = alloc.allocate(new_cap);
    auto dest = new_data;
    auto elem = elements;
    for (size_t i = 0; i != size(); i++)
        alloc.construct(dest++, move(*elem++));
    free();
    elements = new_data;
    first_free = dest;
    cap = elements + new_cap;
}

void StrVec::reallocate() {
    auto new_cap = size() ? 2 * size() : 1;
    alloc_n_move(new_cap);
}

void StrVec::reserve(size_t new_cap) {
    if (new_cap <= capacity()) return;
    alloc_n_move(new_cap);
}

void StrVec::resize(size_t count) {
    resize(count, string());
}

void StrVec::resize(size_t count, const string &s) {
    if (count > size()) {
        if (count > capacity()) reserve(count * 2);
        for (size_t i = size(); i != count; i++)
            alloc.construct(first_free++, s);
    }
    else if (count < size()) {
        while (first_free != elements + count)
            alloc.destroy(--first_free);
    }
}

StrVec::StrVec(StrVec &&s) noexcept:
elements(s.elements), first_free(s.elements), cap(s.cap) {
    s.elements = s.first_free = s.cap = nullptr;
}

StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
    return (lhs.size() == rhs.size() &&
            equal(lhs.begin(), lhs.end(), rhs.begin()));
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs == rhs);
}

bool operator<(const StrVec &lhs, const StrVec &rhs) {
    return lexicographical_compare(lhs.begin(), lhs.end(),
            rhs.begin(), rhs.end());
}

bool operator>(const StrVec &lhs, const StrVec &rhs) {
    return rhs < lhs;
}

bool operator<=(const StrVec &lhs, const StrVec &rhs) {
    return !(rhs < lhs);
}

bool operator>=(const StrVec &lhs, const StrVec &rhs) {
    return !(lhs < rhs);
}

StrVec& StrVec::operator=(initializer_list<string> il) {
    auto data = alloc_n_copy(il.begin(), il.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

int main() {
    StrVec vec;
    vec.reserve(6);
    cout << "capacity(reserve to 6): " << vec.capacity() << endl;

    vec.reserve(4);
    cout << "capacity(reserve to 4): " << vec.capacity() << endl;

    vec.push_back("hello");
    vec.push_back("world");

    vec.resize(4);

    for (auto i = vec.begin(); i != vec.end(); i++)
        cout << *i << endl;
    cout << "-EOF-" << endl;

    vec.resize(1);

    for (auto i = vec.begin(); i != vec.end(); i++)
        cout << *i << endl;
    cout << "-EOF-" << endl;

    StrVec vec2{"hello", "world", "vigor"};
    for (auto i = vec2.begin(); i != vec2.end(); i++)
        cout << *i << " ";

    const StrVec const_vec = {"hello", "world", "vigor"};
    if (vec2 == const_vec)
        for (const auto &str: const_vec)
            cout << str << " ";
    cout << endl;

    return 0;
}
