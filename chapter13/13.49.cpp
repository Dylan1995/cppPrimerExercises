#include "13.49.h"

void swap(Message &lhs, Message &rhs) {
    lhs.remove_from_folders();
    rhs.remove_from_folders();

    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);

    lhs.add_to_folders(lhs);
    rhs.add_to_folders(rhs);
}

Message::Message(const Message &m):
    contents(m.contents), folders(m.folders) {
    add_to_folders(m);
}

Message& Message::operator=(const Message &rhs) {
    remove_from_folders();
    contents = rhs.contents;
    folders = rhs.folders;
    add_to_folders(rhs);
    return *this;
}

Message::Message(Message &&m): contents(move(m.contents)) {
    move_folders(&m);
}

Message& Message::operator=(Message &&rhs) {
    if (this != &rhs) {
        remove_from_folders();
        contents = move(rhs.contents);
        move_folders(&rhs);
    }
    return *this;
}

Message::~Message() {
    remove_from_folders();
}

void Message::save(Folder &f) {
    addFldr(&f);
    f.addMsg(this);
}

void Message::remove(Folder &f) {
    remFldr(&f);
    f.remMsg(this);
}

void Message::print_debug() {
    cout << contents << endl;
}

void Message::add_to_folders(const Message &m) {
    for (auto f: m.folders)
        f->addMsg(this);
}

void Message::remove_from_folders() {
    for (auto f: folders)
        f->remMsg(this);
}

void Message::move_folders(Message *m) {
    folders = move(m->folders);
    for (auto f: folders) {
        f->remMsg(m);
        f->addMsg(this);
    }
    m->folders.clear();
}

void swap(Folder &lhs, Folder &rhs) {
    lhs.remove_from_messages();
    rhs.remove_from_messages();

    swap(lhs.msgs, rhs.msgs);

    lhs.add_to_messages(lhs);
    rhs.add_to_messages(rhs);
}

Folder::Folder(const Folder &f): msgs(f.msgs) {
    add_to_messages(f);
}

Folder& Folder::operator=(const Folder &rhs) {
    remove_from_messages();
    msgs = rhs.msgs;
    add_to_messages(rhs);
    return *this;
}

Folder::Folder(Folder &&f) {
    move_messages(&f);
}

Folder& Folder::operator=(Folder &&f) {
    if (this != &f) {
        remove_from_messages();
        move_messages(&f);
    }
    return *this;
}

Folder::~Folder() {
    remove_from_messages();
}

void Folder::print_debug() {
    for (auto m: msgs)
        cout << m->contents << " ";
    cout << endl;
}

void Folder::add_to_messages(const Folder &f) {
    for (auto m: f.msgs)
        m->addFldr(this);
}

void Folder::remove_from_messages() {
    for (auto m: msgs)
        m->remFldr(this);
}

void Folder::move_messages(Folder *f) {
    msgs = move(f->msgs);
    for (auto m: msgs) {
        m->remFldr(f);
        m->addFldr(this);
    }
    f->msgs.clear();
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
        for_each(elements, first_free, [this](string &rhs){
            alloc.destroy(&rhs);});
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

StrVec::StrVec(StrVec &&s) noexcept:
elements(s.elements), first_free(s.first_free), cap(s.cap) {
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
    return *this;
}

String::String(String &&s) noexcept: elements(s.elements), end(s.end) {
    s.elements = s.end = nullptr;
}

String& String::operator=(String &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        end = rhs.end;
        rhs.elements = rhs.end = nullptr;
    }
    return *this;
}

int main() {
    Message first_mail("hello");
    Message signin_mail("welcome to cpp");
    Folder mail_box;

    first_mail.save(mail_box);
    signin_mail.save(mail_box);
    mail_box.print_debug();

    first_mail = move(signin_mail);
    mail_box.print_debug();

    return 0;
}
