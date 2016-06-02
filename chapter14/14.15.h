#include <iostream>
#include <string>

using namespace std;

class Book {
    friend istream& operator>>(istream&, Book&);
    friend ostream& operator<<(ostream&, const Book&);
    friend bool operator==(const Book&, const Book&);
    friend bool operator!=(const Book&, const Book&);
    friend bool operator<(const Book&, const Book&);
    friend bool operator>(const Book&, const Book&);
    friend Book operator+(const Book&, const Book&);

public:
    Book() = default;
    Book(unsigned no, string name, string author,
            string pubdate, unsigned number): _no(no), _name(name),
            _author(author), _pubdate(pubdate), _number(number){}
    Book(istream &is) {
        is >> *this;
    }
    
    Book& operator+=(const Book&);

private:
    unsigned _no;
    string _name;
    string _author;
    string _pubdate;
    unsigned _number;
};

istream& operator>>(istream&, Book&);
ostream& operator<<(ostream&, const Book&);
bool operator==(const Book&, const Book&);
bool operator!=(const Book&, const Book&);
bool operator<(const Book&, const Book&);
bool operator>(const Book&, const Book&);
Book operator+(const Book&, const Book&);
