#include <iostream>
#include <vector>

using namespace std;

class Date {
    friend bool operator==(const Date &lhs, const Date &rhs);
    friend bool operator<(const Date &lhs, const Date &rhs);
    friend bool check(const Date &d);
    friend ostream& operator<<(ostream&, const Date&);

public:
    Date() = default;
    explicit Date(size_t days);
    Date(size_t d, size_t m, size_t y): day(d), month(m), year(y) {}
    Date(istream&, ostream&);
    Date(const Date&);
    Date(Date&&) noexcept;
    
    Date& operator=(const Date&);
    Date& operator=(Date&&) noexcept;

    ~Date() {
        cout << "destructor" << endl;
    }

    size_t toDays() const;
    Date& operator+=(size_t offset);
    Date& operator-=(size_t offset);

private:
    size_t day = 1;
    size_t month = 1;
    size_t year = 0;
};

static const size_t YtoD_400 = 365*400 + 400/4 - 3;
static const size_t YtoD_100 = 365*100 + 100/4 - 1;
static const size_t YtoD_4 = 365*4 + 1;
static const size_t YtoD_1 = 365;

static const vector<size_t> monthsVec_n = {
    31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};
static const vector<size_t> monthsVec_l = {
    31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
};

ostream& operator<<(ostream&, const Date&);
istream& operator>>(istream&, Date&);
int operator-(const Date&, const Date&);
bool operator==(const Date&, const Date&);
bool operator!=(const Date&, const Date&);
bool operator<(const Date&, const Date&);
bool operator<=(const Date&, const Date&);
bool operator>(const Date&, const Date&);
bool operator>=(const Date&, const Date&);
Date operator-(const Date&, size_t);
Date operator+(const Date&, size_t);

bool check(const Date&);
inline bool isLeapYear(size_t);

inline bool check(const Date &d) {
    if (d.month == 0 || d.month > 12)
        return false;
    else {
        if (d.month == 1 || d.month == 3 || d.month == 5 || d.month == 7
                || d.month == 8 || d.month == 10 || d.month == 12) {
            if (d.day == 0 || d.day > 31)
                return false;
            return true;
        }
        else {
            if (d.month == 4 || d.month == 6 || d.month == 9
                    || d.month == 11) {
                if (d.day == 0 || d.day > 30)
                    return false;
                return true;
            }
            else {
                if (isLeapYear(d.year)) {
                    if (d.day == 0 || d.day > 29)
                        return false;
                    return true;
                }
                else {
                    if (d.day == 0 || d.day > 28)
                        return false;
                    return true;
                }
            }
        }
    }
}

inline bool isLeapYear(size_t y) {
    if (!(y % 400)) return true;
    else {
        if (!(y % 100)) return false;
        return !(y % 4);
    }
}
