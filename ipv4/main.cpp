#include <iostream>
#include "ipv4.hpp"

int main(int argc, char* argv[])
{
	std::cout << "Input range: ";
	ipv4 a1, a2;
	std::cin >> a1 >> a2;
	if (a2 > a1) {
		for (ipv4 a = a1; a <= a2; ++a) {
			std::cout << a << std::endl;
		}
	} else {
		std::cerr << "Invalid range!" << std::endl;
		return 1;
	}
	return 0;
} 