#include "13.37.h"
#include <iostream>

void swap(Message &lhs, Message &rhs) {
    lhs.RemoveFromFolders();
    rhs.RemoveFromFolders();
    swap(lhs.folders, rhs.folders);
    swap(lhs.contents, rhs.contents);
    lhs.AddToFolders(lhs);
    rhs.AddToFolders(rhs);
}

Message& Message::operator=(const Message &rhs) {
    RemoveFromFolders();
    contents = rhs.contents;
    folders = rhs.folders;
    AddToFolders(rhs);
    return *this;
}

Message::~Message() {
    RemoveFromFolders();
}

void Message::Save(Folder &f) {
    AddFldr(&f);
    f.AddMsg(this);
}

void Message::Remove(Folder &f) {
    RemFldr(&f);
    f.RemMsg(this);
}

void Message::PrintDebug() {
    cout << contents << endl;
}

void Message::AddToFolders(const Message &m) {
    for (auto f: m.folders)
        f->AddMsg(this);
}

void Message::RemoveFromFolders() {
    for (auto f: folders)
        f->RemMsg(this);
}

void swap(Folder &lhs, Folder &rhs) {
    lhs.RemoveFromMessages();
    rhs.RemoveFromMessages();

    swap(lhs.msgs, rhs.msgs);

    lhs.AddToMessages(lhs);
    rhs.AddToMessages(rhs);
}

Folder::Folder(const Folder &f): msgs(f.msgs) {
    AddToMessages(f);
}

Folder& Folder::operator=(const Folder& rhs) {
    RemoveFromMessages();
    msgs = rhs.msgs;
    AddToMessages(rhs);
    return *this;
}

Folder::~Folder() {
    RemoveFromMessages();
}

void Folder::PrintDebug() {
    for (auto m: msgs)
        cout << m->contents << " ";
    cout << endl;
}

void Folder::AddToMessages(const Folder &f) {
    for (auto m: f.msgs)
        m->AddFldr(this);
}

void Folder::RemoveFromMessages() {
    for (auto m: msgs)
        m->RemFldr(this);
}
