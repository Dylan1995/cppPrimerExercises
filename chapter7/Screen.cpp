#include <string>
#include <iostream>
using namespace std;
class Screen{
private:
    unsigned height = 0, width = 0;
    unsigned cursor = 0;
    string contents;
public:
    Screen() = default;
    Screen(unsigned ht, unsigned wd): height(ht), width(wd), contents(ht * wd, ' '){}
    Screen(unsigned ht, unsigned wd, char c): height(ht), width(wd), contents(ht * wd, c){}
public:
    Screen& move(unsigned r, unsigned c){
        cursor = r * width + c;
        return *this;
    }

    Screen& set(char ch){
        contents[cursor] = ch;
        return *this;
    }

    Screen& set(unsigned r, unsigned c, char ch){
        contents[r * width + c] = ch;
        return *this;
    }

    Screen& display(){
        cout << contents;
        return *this;
    }
    
};
