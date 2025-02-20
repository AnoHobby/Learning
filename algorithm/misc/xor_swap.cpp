#include <iostream>
#include <format>
int main() {
	int a, b;
	std::cin >> a >> b;
	std::cout << std::format("a={},b={}", a, b) << std::endl;
	a ^= b ^= a ^= b;
	std::cout << std::format("a={},b={}", a, b) << std::endl;
	return 0;
}
