#include <string>
#include <iostream>

using namespace std;

class Sales_data {
    friend istream& operator>>(istream&, Sales_data&);
    friend ostream& operator<<(ostream&, const Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);

public:
    Sales_data(const string &s, unsigned n, double p):
        bookNo(s), units_sold(n), revenue(n * p) {}
    Sales_data(): Sales_data("", 0, 0.0) {}
    Sales_data(istream&);

    Sales_data& operator=(const string&);
    Sales_data& operator+=(const Sales_data&);
    explicit operator string() const {
        return bookNo;
    }
    explicit operator double() const {
        return avg_price();
    }

    string isbn() const {
        return bookNo;
    }

    inline double avg_price() const;
    string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

istream& operator>>(istream&, Sales_data&);
ostream& operator<<(ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const {
    return units_sold ? revenue / units_sold : 0;
}
