#include <memory>
#include <string>
#include <initializer_list>
#include <iostream>
#include <fstream>
#include <map>
#include <set>
#include <cctype>

using namespace std;

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(const StrVec&);
    StrVec(initializer_list<string>);
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
    string& at(size_t pos) {
        return *(elements + pos);
    }
    const string& at(size_t pos) const {
        return *(elements + pos);
    }
    
    void reserve(size_t new_cap);
    void resize(size_t count);
    void resize(size_t count, const string&);
private:
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }
    void reallocate();
    void alloc_n_move(size_t new_cap);
    void range_initialize(const string*, const string*);

    string *elements;
    string *first_free;
    string *cap;
    allocator<string> alloc;
};

class QueryResult;
class TextQuery {
public:
    TextQuery(ifstream&);
    QueryResult query(const string&) const;
private:
    shared_ptr<StrVec> input;
    map<string, shared_ptr<set<size_t>>> result;
};

class QueryResult {
public:
    friend ostream& print(ostream&, const QueryResult&);

    QueryResult(const string &str, shared_ptr<set<size_t>> s,
            shared_ptr<StrVec> v): word(str), nos(s), input(v) {}

private:
    string word;
    shared_ptr<set<size_t>> nos;
    shared_ptr<StrVec> input;
};

std::ostream& print(ostream&, const QueryResult&);
