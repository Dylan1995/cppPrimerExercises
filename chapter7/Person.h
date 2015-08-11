#include <string>
class Person{
private:
    std::string strName;
    std::string strAddress;
public:
    std::string getName() const {return strName;}
    std::string getAddress() const {return strAddress;}
    std::istream& read(std::istream&, Person&);
    std::ostream& print(std::ostream&, const Person&);
    Person() = default;
    Person(const std::string &name, const std::string &add){
        strName = name;
        strAddress = add;
    }
    Person(std::istream &is){
        is >> *this;
    }
};
