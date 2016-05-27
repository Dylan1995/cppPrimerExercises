#include <set>
#include <string>

using namespace std;

class Folder;

class Message {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Folder;
public:
    explicit Message(const string &s = ""): contents(s) {}
    Message(const Message&);
    Message& operator=(const Message&);
    ~Message();
    void Save(Folder&);
    void Remove(Folder&);
    void PrintDebug();
private:
    string contents;
    set<Folder*> folders;
    
    void AddToFolders(const Message&);
    void RemoveFromFolders();

    void AddFldr(Folder *f) {
        folders.insert(f);
    }
    void RemFldr(Folder *f) {
        folders.erase(f);
    }
};

void swap(Message&, Message&);

class Folder {
    friend void swap(Message&, Message&);
    friend void swap(Folder&, Folder&);
    friend class Message;
public:
    Folder() = default;
    Folder(const Folder&);
    Folder& operator=(const Folder&);
    ~Folder();

    void PrintDebug();
private:
    set<Message*> msgs;

    void AddToMessages(const Folder&);
    void RemoveFromMessages();

    void AddMsg(Message *m) {
        msgs.insert(m);
    }
    void RemMsg(Message *m) {
        msgs.erase(m);
    }
};

void swap(Folder&, Folder&);
