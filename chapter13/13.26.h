#include <vector>
#include <string>
#include <initializer_list>
#include <memory>
#include <exception>

using namespace std;

class ConstStrBlobPtr;

class StrBlob {
public:
    using size_type = vector<string>::size_type;
    friend class ConstStrBlobPtr;

    ConstStrBlobPtr begin() const;
    ConstStrBlobPtr end() const;

    StrBlob(initializer_list<string> il):
        data(make_shared<vector<string>>(il)) {}
    StrBlob(const StrBlob &sb):
        data(make_shared<vector<string>>(*sb.data)) {}
    StrBlob& operator=(const StrBlob &sb);

    size_type size() const {
        return data->size();
    }
    bool empty() const {
        return data->empty();
    }
    
    void push_back(const string &x) {
        data->push_back(x);
    }
    void pop_back() {
        check(0, "pop_back on empty StrBlob");
        data->pop_back();
    }

    string& front() {
        check(0, "front on empty StrBlob");
        return data->front();
    }

    string& back() {
        check(0, "back on empty StrBlob");
        return data->back();
    }
private:
    void check(size_type i, const string &msg) const {
        if (i >= data->size()) throw out_of_range(msg);
    }
private:
    shared_ptr<vector<string>> data;
};

class ConstStrBlobPtr {
public:
    ConstStrBlobPtr(): curr(0) {}
    ConstStrBlobPtr(const StrBlob &sb, size_t sz = 0):
        wptr(sb.data), curr(sz) {}
    bool operator!=(ConstStrBlobPtr &rhs) {
        return rhs.curr != curr;
    }
    const string& dereference() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    ConstStrBlobPtr& increment() {
        check(curr, "increment past end of StrBlobPtr");
        ++curr;
        return *this;
    }
private:
    shared_ptr<vector<string>> check(size_t i, const string &msg) const {
        auto ret = wptr.lock();
        if (!ret) throw runtime_error("unbound StrBlobPtr");
        if (i >= ret->size()) throw out_of_range(msg);
        return ret;
    }
    weak_ptr<vector<string>> wptr;
    size_t curr;
};
