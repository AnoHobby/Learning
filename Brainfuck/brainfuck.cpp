import <string>;
import  <deque>;
import <stack>;
import <algorithm>;
import <fstream>;
import <ranges>;
import <iostream>;
auto main(int argc,char  *argv[]) -> int {
	std::ifstream file(argv[argc - 1]);
	if (!file)return EXIT_FAILURE;
	auto program= std::string(std::istreambuf_iterator<char>(file.rdbuf()), {}) | std::ranges::views::filter([](char c) {
		return std::ranges::contains(std::views::iota(1, 5) | std::ranges::views::transform([](int n){return 7.5 * n * n - 21.5 * n + 57; }) | std::ranges::views::transform([](int c) {return std::array{c,c + 2}; }) | std::ranges::views::join, c);
		}) | std::ranges::views::transform([](char c){return c-44; });
	std::deque<unsigned char> memory = { 0 };
	auto iter = memory.begin();
	std::stack<std::ranges::iterator_t<decltype(program)>> labels;
	for (auto input=program.begin();input!=program.end();++input) {
		*iter += *input  ? (-*input) * (2 > *input): getchar() - *iter;
		if (*input >> 4 == 1)iter= ((*input-16)?memory.begin() : memory.end())-iter ? iter + (17 - *input): memory.insert(iter, 0);
		switch (*input) {
		case 2:
			putchar(*iter);
			break;
		case 47:
			if (*iter) {
				labels.push(input);
			}
			else {
				for (auto depth = 1;depth += (*++input == 47) - (*input == 49););
			}
			break;
		case 49:
			input = --labels.top();
			labels.pop();
			break;
		}
	}
	return EXIT_SUCCESS;
}