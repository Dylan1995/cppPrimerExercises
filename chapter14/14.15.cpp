#include "14.15.h"

istream& operator>>(istream &is, Book &book) {
    is >> book._no >> book._name >> book._author
        >> book._pubdate >>book._number;
    if (!is) book = Book();
    return is;
}

ostream& operator<<(ostream &os, const Book &book) {
    os << book._no << " " << book._name << " " << book._author
        << " " << book._pubdate << " " << book._number;
    return os;
}

bool operator==(const Book &lhs, const Book &rhs) {
    return lhs._no == rhs._no;
}

bool operator!=(const Book &lhs, const Book &rhs) {
    return !(lhs == rhs);
}

bool operator<(const Book &lhs, const Book &rhs) {
    return lhs._no < rhs._no;
}

bool operator>(const Book &lhs, const Book &rhs) {
    return rhs < lhs;
}

Book& Book::operator+=(const Book &rhs) {
    this->_number += rhs._number;
    return *this;
}

Book operator+(const Book &lhs, const Book &rhs) {
    Book book = lhs;
    book += rhs;
    return book;
}

int main() {
    Book b1(123, "csapp", "kr", "2014", 2);
    Book b2(123, "csapp", "kr", "2014", 4);
    cout << b1 + b2 << endl;

    return 0;
}
