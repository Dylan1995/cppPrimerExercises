#include <iostream>
#include "Sales_item.h"

int main(){
	Sales_item b1, b2;
	std::cout << "Input the two books: " << std::endl;
	std::cin >> b1 >> b2;
	if(compareIsbn(b1, b2))
		std::cout << b1 + b2 << std::endl;
	else
		std::cout << "error" << std::endl;
	return 0;
}
