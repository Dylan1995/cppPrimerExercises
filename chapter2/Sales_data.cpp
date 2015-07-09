#include <iostream>
#include <string>

using namespace std;

class Sales_data{
    friend std::istream& operator >> (std::istream&, Sales_data&);

    friend std::ostream& operator << (std::ostream&, const Sales_data&);

    friend bool operator < (const Sales_data&, const Sales_data&);

    friend bool operator == (const Sales_data&, const Sales_data&);

public:
    Sales_data() = default;
    Sales_data(const std::string &book): bookNo(book){

    }
    Sales_data(std::istream &is){
        is >> *this;
    }
public:
    Sales_data& operator += (const Sales_data&);
    std::string isbn() const{
        return bookNo;
    }
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
};

inline bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs){
    return lhs.isbn() == rhs.isbn();
}

inline bool operator == (const Sales_data &lhs, const Sales_data &rhs){
    return lhs.units_sold == rhs.units_sold && lhs.sellingprice == rhs.sellingprice && lhs.saleprice == rhs.saleprice && lhs.isbn() == rhs.isbn();
}

inline bool operator != (const Sales_data &lhs, const Sales_data &rhs){
    return !(lhs == rhs);
}

Sales_data operator + (const Sales_data&, const Sales_data&);

Sales_data& Sales_data::operator += (const Sales_data& rhs){
    units_sold += rhs.units_sold;
    saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold) / (rhs.units_sold + units_sold);
    if(sellingprice)
        discount = saleprice / sellingprice;
    return *this;
}

Sales_data operator + (const Sales_data& lhs, const Sales_data& rhs){
    Sales_data ret(lhs);
    ret += rhs;
    return ret;
}

std::istream operator >> (std::istream& in, Sales_data& s){
    in >> s.bookNo >> s.units_sold >> s.sellingprice >> s.saleprice;
    if(in && s.sellingprice)
        s.discount += s.saleprice;
    else
        s = Sales_data();
    return in;
}

std::ostream operator << (std::ostream& out, const Sales_data& s){
    out << s.isbn() << " " << s.units_sold << " " << s.sellingprice << " " << s.saleprice << " " << s.discount;
    return out;
}

int main(){
    Sales_data book;
    std::cout << "input the record" << std::endl;
    while(std::cin >> book){
        std::cout << book << std::endl;
    }
    Sales_data trans1, trans2;
    std::cout << "input 2 records that have the same isbn" << std::endl;
    std::cin >> trans1 >> trans2;
    if(compareIsbn(trans1, trans2))
        std::cout << trans1 + trans2 << std::endl;
    else
        std::cout << "isbn differs" << std::endl;

    Sales_data total, trans;
    std::cout << "input records that have the same isbn" << std::endl;
    if(std::cin >> total){
        while(std::cin >> trans){
            if(compareIsbn(total, trans))
                total += trans;
            else{
                std::cout << "isbn differs" << std::endl;
                break;
            }
        }
        std::cout << total << std::endl;
    }
    else{
        std::cout << "no records" << std::endl;
        return -1;
    }

    int num = 1;
    std::cout << "input records" << std::endl;
    if(std::cin >> trans1){
        while(std::cin >> trans2){
            if(compareIsbn(trans1, trans2))
                num++;
            else{
                std::cout << trans1.isbn() << "has" << num << "records" << std::endl;
                trans1 = trans2;
                num = 1;
            }
        }
        std::cout << trans1.isbn() << "has" << num << "records" << std::endl;
    }
    else{
        std::cout << "has no records" << std::endl;
        return -1;
    }

    return 0;
}
