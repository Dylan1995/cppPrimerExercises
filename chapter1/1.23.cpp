#include <iostream>
#include "Sales_item.h"

int main(){
	Sales_item b1, b2;
	int cnt = 1;
	std::cin >> b1;
	while(std::cin >> b2){
		if(compareIsbn(b1, b2))
			cnt++;
		else{
			std::cout << b1.isbn() << " " << cnt << std::endl;
			b1 = b2;
			cnt = 1;
		}
	}
	std::cout << b1.isbn() << " " << cnt << std::endl;
	return 0;
}
