#include <iostream>
#include "Sales_item.h"

int main(){
	Sales_item book, sum;
	std::cin >> sum;
	while(std::cin >> book){
		if(compareIsbn(sum, book)){
			sum += book;
		}
		else{
			std::cout << "error" << std::endl;
			return 0;
		}
	}
	std::cout << "Sum is: " << sum << std::endl;
	return 0;
}
