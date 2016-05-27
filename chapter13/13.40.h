#include <memory>
#include <string>

using namespace std;

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec(initializer_list<string> il);
    StrVec& operator=(const StrVec&);
    ~StrVec();
    void push_back(const string&);
    size_t size() const {
        return first_free - elements;
    }
    size_t capacity() const {
        return cap - elements;
    }
    string* begin() const {
        return elements;
    }
    string* end() const {
        return first_free;
    }
private:
    static allocator<string> alloc;
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    void reallocate(size_t);
    void reverse(size_t n);
    void resize(size_t n);
    void resize(size_t n, const string&);
    string *elements;
    string *first_free;
    string *cap;
};
