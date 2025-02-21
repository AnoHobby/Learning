import <print>;
import <iostream>;
auto for_factorial(auto n) {
	decltype(n) result = 1;
	for (; 1 < n; --n) {
		result *= n;
	}
	return result;
}
int recursive_factorial(auto n) {
	if (1 < n)return recursive_factorial(n-1)*n;
	return 1;
}
auto main() -> int {
	const auto n = *std::istream_iterator<int>(std::cin);
	std::print("for:{},recursive:{}",for_factorial(n),recursive_factorial(n));
	return 0;
}