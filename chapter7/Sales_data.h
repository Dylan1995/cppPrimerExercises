#include <string>
class Sales_data
{
private:
    std::string bookNo;
    unsigned units_sold = 0;
    double sellingprice = 0.0;
    double saleprice = 0.0;
    double discount = 0.0;
public:
    std::string isbn() const {return bookNo;}
    Sales_data& combine(const Sales_data &rhs){
        units_sold += rhs.units_sold;
        saleprice = (rhs.saleprice * rhs.units_sold + saleprice * units_sold);
        if( sellingprice != 0 )
        {
            discount = saleprice / sellingprice;
        }
        return *this;
    }
    Sales_data add(const Sales_data&, const Sales_data&);
    std::istream &read(std::istream&, Sales_data&);
    std::ostream &print(std::ostream&, const Sales_data&);

    Sales_data() = default;
    Sales_data(const std::string &book): bookNo(book){}
    Sales_data(const std::string &book, const unsigned, const double, const double);
    Sales_data(std::istream&);

};
