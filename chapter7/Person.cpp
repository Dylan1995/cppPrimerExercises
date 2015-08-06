#include "Person.h"

std::istream& Person::read(std::istream &is, Person &per){
    is >> per.strName >> per.strAddress;
    return is;
}

std::ostream& Person::print(std::ostream &os, const Person &per){
    os << per.getName() << per.getAddress();
    return os;
}
