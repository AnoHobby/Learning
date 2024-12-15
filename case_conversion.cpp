#include <iostream>
#include <iterator>
int main() {
	putchar(*std::istream_iterator<char>(std::cin)^32);
	return 0;
}