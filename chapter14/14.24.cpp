#include "14.24.h"
#include <algorithm>

Date::Date(size_t days) {
    size_t y400 = days / YtoD_400;
    size_t y100 = (days - y400 * YtoD_400) / YtoD_100;
    size_t y4 = (days - y400 * YtoD_400 - y100 * YtoD_100) / YtoD_4;
    size_t y = (days - y400 * YtoD_400 - y100 * YtoD_100
            - y4 * YtoD_4) / 365;
    size_t d = days - y400 * YtoD_400 - y100 * YtoD_100
        - y4 * YtoD_4 - y * 365;
    this->year = y400 * 400 + y100 * 100 + y4 * 4 + y;
    vector<size_t> currYear = isLeapYear(this->year)
        ? monthsVec_l : monthsVec_n;
    size_t D_accumu = 0, M_accumu = 0;
    find_if(currYear.cbegin(), currYear.cend(), [&](size_t m) {
        D_accumu += m;
        M_accumu++;
        if (d < D_accumu) {
            this->month = M_accumu;
            this->day = d + m - D_accumu;
            return true;
        }
        else return false;
    });
}

Date::Date(istream &is, ostream &os) {
    is >> day >> month >> year;
    if (is) {
        if (check(*this)) return;
        else {
            os << "Invalid input!Object is default initializer.";
            *this = Date();
        }
    }
    else {
        os << "Invalid input!Object is default initialized";
        *this = Date();
    }
}

Date::Date(const Date &d): day(d.day), month(d.month), year(d.year) {}

Date::Date(Date &&d) noexcept: day(d.day), month(d.month), year(d.year) {
    cout << "copy moving";
}

Date& Date::operator=(const Date &d) {
    this->day = d.day;
    this->month = d.month;
    this->year = d.year;

    return *this;
}

Date& Date::operator=(Date &&rhs) noexcept {
    if (this != &rhs) {
        day = rhs.day;
        month = rhs.month;
        year = rhs.year;
    }
    cout << "moving = ";
    return *this;
}

size_t Date::toDays() const {
    size_t res = day;
    vector<size_t> currYear = isLeapYear(year) ? monthsVec_l : monthsVec_n;
    for (auto it = currYear.cbegin(); it != currYear.cbegin()
            + this->month - 1; it++)
        res += *it;
    res += (year / 400) * YtoD_400;
    res += (year % 400 / 100) * YtoD_100;
    res += (year % 100 / 4) * YtoD_4;

    return res;
}
