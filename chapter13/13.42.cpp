#include "13.42.h"
#include <sstream>
#include <algorithm>

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

void StrVec::alloc_n_copy_move(size_t new_cap) {
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
        if (count > capacity())
            reserve(count * 2);
        for (size_t i = size(); i != count; i++)
            alloc.construct(first_free++, s);
    }
    else if (count < size()) {
        while (first_free != elements + count)
            alloc.destroy(--first_free);
    }
}

TextQuery::TextQuery(ifstream &ifs): input(new StrVec) {
    size_t line_no = 0;
    for (string line; getline(ifs, line); line_no++) {
        input->push_back(line);
        istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
            remove_copy_if(text.begin(), text.end(),
                    back_inserter(word), ispunct);
            auto &nos = result[word];
            if (!nos) nos.reset(new set<size_t>);
            nos->insert(line_no);
        }
    }
}

QueryResult TextQuery::query(const string &str) const {
    static shared_ptr<set<size_t>> nodate(new set<size_t>);
    auto found = result.find(str);
    if (found == result.end())
        return QueryResult(str, nodate, input);
    else
        return QueryResult(str, found->second, input);
}

ostream& print(ostream &out, const QueryResult &qr) {
    out << qr.word << " occurs " << qr.nos->size()
        << (qr.nos->size() > 1 ? " times" : " time") << endl;
    for (auto i: *qr.nos)
        out << "\t(line " << i + 1 << ") " << qr.input->at(i) << endl;
    return out;
}

void RunQueries(ifstream &infile) {
    TextQuery tq(infile);
    while (1) {
        cout << "enter word to look for, or q to quit: ";
        string s;
        if (!(cin >> s) || s == "q") break;
        print(cout, tq.query(s)) << endl;
    }
}

int main() {
    ifstream file("data.txt");
    RunQueries(file);
}
