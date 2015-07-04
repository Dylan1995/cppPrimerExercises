#include <iostream>

int main(){
	int sum = 0, num;
	while(std::cin >> num)
		sum += num;
	std::cout << "The sum is " << sum << std::endl;
	return 0;
}
