#include "13.39.h"

StrVec::StrVec(const StrVec &s) {
    auto new_data = alloc_n_copy(s.begin(), s.end());
    elements = new_data.first;
    first_free = cap = new_data.second;
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
        for (auto p = first_free; p != elements;)
            alloc.destroy(--p);
        alloc.deallocate(elements, cap - elements);
    }
}

void StrVec::reallocate() {
    auto new_capacity = size() ? 2 * size() : 1;
    reallocate(new_capacity);
}

inline void StrVec::reallocate(size_t new_capacity) {
    auto new_data = alloc.allocate(new_capacity);
    auto dest = new_data;
    auto elem = elements;
    for (size_t i = 0; i != size(); i++)
        alloc.construct(dest++, move(*elem++));
    free();

    elements = new_data;
    first_free = dest;
    cap = elements + new_capacity;
}

void StrVec::reverse(size_t n) {
    if (n > capacity())
        reallocate(n);
} 

inline void StrVec::resize(size_t n) {
    if (n > size()) {
        while (size() < n)
            push_back("");
    }
    else if (n < size()) {
        while (size() < n)
            alloc.destroy(--first_free);
    }
}

inline void StrVec::resize(size_t n, const string &s) {
    if (n > size()) {
        while (size() < n)
            push_back(s);
    }
}
