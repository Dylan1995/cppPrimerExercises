#include <iostream>

int main(){
	std::cout << "Input the two integers:";
	int a, b;
	std::cin >> a >> b;
	if(a > b){
		int x = a;
		a = b;
		b = x;
	}
	for(int i = a; i <= b; i++)
		std::cout << i << " ";
	std::cout << std::endl;
}
