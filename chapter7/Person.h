#include <string>
class Person{
private:
    std::string strName;
    std::string strAddress;
public:
    std::string getName() const {return strName;}
    std::string getAddress() const {return strAddress;}
};
