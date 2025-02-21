import <print>;
import <iostream>;
auto for_factorial(auto n) {
	auto result = 1;
	for (; 1 < n; --n) {
		result *= n;
	}
	return result;
}
int recursive_factorial(auto n) {
	if (1 < n)return recursive_factorial(n-1)*n;
	return 1;
}
auto P(auto n,auto r) {
	auto result = 1;
	for (--r;0<=r; --r) {
		result *= n - r;
	}
	return result;
}
auto C(auto n,auto r) {
	return P(n, r) / for_factorial(r);
}
auto main() -> int {
	const auto n = *std::istream_iterator<int>(std::cin);
	std::println("factorial({})=for:{},recursive:{}",n,for_factorial(n),recursive_factorial(n));
	const auto r = *std::istream_iterator<int>(std::cin);
	std::println("{}P{}={}", n, r, P(n, r));
	std::println("{}C{}={}", n, r, C(n, r));
	return 0;
}
