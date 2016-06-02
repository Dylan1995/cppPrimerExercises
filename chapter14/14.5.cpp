#include "14.5.h"

istream& operator>>(istream &is, Book &book) {
    is >> book._no >> book._name >> book._author >> book._pubdate;
    if (!is) book = Book();
    return is;
}

ostream& operator<<(ostream &os, const Book &book) {
    os << book._no << " " << book._name << " " << book._author
        << " " << book._pubdate;
    return os;
}

bool operator==(const Book &lhs, const Book &rhs) {
    return lhs._no == rhs._no;
}

bool operator!=(const Book &lhs, const Book &rhs) {
    return !(lhs == rhs);
}

int main() {
    Book b1(123, "csapp", "kr", "2014");
    Book b2(123, "csapp", "kr", "2014");
    cout << (b1 == b2) << endl;
    Book b3(123, "c++", "lp", "2013");
    cout << (b1 != b2) << endl;

    return 0;
}
