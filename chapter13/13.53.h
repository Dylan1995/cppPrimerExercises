#include <string>

using namespace std;

class HasPtr {
public:
    friend void swap(HasPtr&, HasPtr&);
    HasPtr(const string &s = string());
    HasPtr(const HasPtr &hp);
    HasPtr(HasPtr &&hp) noexcept;
    HasPtr& operator=(HasPtr rhs);
    ~HasPtr();
private:
    string *ps;
    int i;
};
