#include <string>
#include <iostream>

using namespace std;

class HasPtr {
public:
    HasPtr(const string &s = string()):
        ps(new string(s)), i(0), use(new size_t(1)) {}
    HasPtr(const HasPtr &hp): ps(hp.ps), i(hp.i), use(hp.use) {
        ++*use;
    }
    HasPtr& operator=(const HasPtr&);
    HasPtr& operator=(const string&);
    string& operator*();
    ~HasPtr();
public:
    string *ps;
    int i;
    size_t *use;
};

HasPtr::~HasPtr() {
    if (--*use == 0) {
        delete ps;
        delete use;                    
    }
}

HasPtr& HasPtr::operator=(const HasPtr &rhs) {
    ++*rhs.use;
    if (--*use == 0) {
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

HasPtr& HasPtr::operator=(const string &rhs) {
    *ps = rhs;
    return *this;
}

string& HasPtr::operator*() {
    return *ps;
}

inline void swap(HasPtr &lhs, HasPtr &rhs) {
    cout << "swap " << *lhs.ps << " and " << *rhs.ps << endl;
    swap(lhs.ps, rhs.ps);
    swap(lhs.i, rhs.i);
}

int main() {
    HasPtr h1("hello");
    HasPtr h2(h1);
    HasPtr h3 = h1;
    h2 = "c++";
    h3 = "java";
    swap(h2, h3);
    cout << *h1 << endl;
    cout << *h2 << endl;
    cout << *h3 << endl;

    return 0;
}
