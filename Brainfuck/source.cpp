import <string>;
import  <deque>;
import <stack>;
import <algorithm>;
import <fstream>;
auto main(int argc,char  *argv[]) -> int {
	if (argc < 2)return EXIT_FAILURE;
	std::fstream file(argv[1]);
	if (!file)return EXIT_FAILURE;
	auto program= std::move(std::string(std::istreambuf_iterator<char>(file), std::istreambuf_iterator<char>()));
	std::deque<unsigned char> memory = { 0 };
	auto iter = memory.begin();
	std::stack<decltype(program)::iterator> labels;
	for (auto input=program.begin();input!=program.end();++input) {
		switch (*input) {
		case '+':
			++(*iter);
			break;
		case '-':
			--(*iter);
			break;
		case '<':
			if (iter == memory.end()) {
				memory.push_back(0);
				iter = memory.end();
				break;
			}
			++iter;
			break;
		case '>':
			if (iter == memory.begin()) {
				memory.push_front(0);
				iter=memory.begin();
				break;
			}
			--iter;
			break;
		case ',':
			*iter = getchar();
			break;
		case '.':
			putchar(*iter);
			break;
		case '[':
			if (*iter) {
				labels.push(input);
				break;
			}
			for (const auto depth=labels.size();;++input) {
				switch (*input) {
				case '[':
					labels.push(input);
					break;
				case ']':
					labels.pop();
					break;
				}
				if (depth == labels.size())break;
			}
			break;
		case ']':
			input = labels.top()-1;
			labels.pop();
			break;
		}
	}
	return EXIT_SUCCESS;
}