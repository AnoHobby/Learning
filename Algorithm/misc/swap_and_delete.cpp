#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
#include <iterator>
int main() {
	std::vector<int> vec(10);
	std::ranges::iota(vec,0);
	std::ranges::copy(vec,std::ostream_iterator<decltype(vec)::value_type>(std::cout,","));
	puts("");
	std::swap(vec[*std::istream_iterator<std::size_t>(std::cin)],vec.back());
	vec.pop_back();
	std::ranges::copy(vec, std::ostream_iterator<decltype(vec)::value_type>(std::cout, ","));
	return 0;
}
