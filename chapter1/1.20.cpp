#include <iostream>
#include "Sales_item.h"

int main(){
	Sales_item book;
	std::cout << "Input the sales record: ";
	while(std::cin >> book)
		std::cout << book << std::endl;
	return 0;
}
