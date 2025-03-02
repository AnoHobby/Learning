import <vector>;
import <iostream>;
import <iterator>;
import <string>;
import <string_view>;
import <sstream>;
import <print>;
import <ranges>;
template <std::ranges::range T>
auto format_range(T range,std::string_view delimiter) {
    std::stringstream ss;
    std::ranges::copy(range,std::ostream_iterator<std::ranges::range_value_t<T> >(ss, delimiter.data()));
    auto result = ss.str();
    result.erase(result.size()-delimiter.size(),delimiter.size());
    return result;
}
void combine(std::size_t i,std::size_t combination_size,std::size_t size,std::vector<std::size_t> &current,std::vector<std::vector<std::size_t> > &combinations) {
    if (!combination_size) {
        combinations.push_back(current);
        return;
    }
    for (; i < size; ++i) {
        current.push_back(i);
        combine(i+1,combination_size-1,size,current,combinations);
        current.pop_back();
    }
}
auto combine(std::size_t combination_size,std::size_t size) {
    std::vector<std::vector<std::size_t>> combinations;
    std::vector<std::size_t> current;
    combine(0, combination_size, size, current, combinations);
    return combinations;
}
auto print_inclusion_exclusion_principle(std::vector<std::string> &terms) {
    if (terms.size() < 2)return;
    std::print("|{}| =", format_range(terms, " ∪ "));
    char symbol = '+';
    std::stringstream ss;
    for (auto k = 1; k <= terms.size(); ++k) {
        for (const auto&combination:combine(k,terms.size())) {
            ss << symbol << "|" << format_range(combination | std::ranges::views::transform([&terms](auto index) {return terms[index]; }), " ∩ ") << "|";
        }
        symbol ^= 6;
    }
    auto output = ss.str();
    output.front() = ' ';
    std::cout << output;
}
int main() {
    std::vector<std::string> terms = { "A", "B","C"};
    print_inclusion_exclusion_principle(terms);
    return 0;
}