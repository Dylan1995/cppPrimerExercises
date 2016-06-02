#include <iostream>
#include <string>

using namespace std;

class Book {
    friend istream& operator>>(istream&, Book&);
    friend ostream& operator<<(ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);

public:
    Book() = default;
    Book(unsigned no, string name, string author, string pubdate):
        _no(no), _name(name), _author(author), _pubdate(pubdate) {}
    Book(istream &is) {
        is >> *this;
    }

private:
    unsigned _no;
    string _name;
    string _author;
    string _pubdate;
};

istream& operator>>(istream&, Book&);
ostream& operator<<(ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
