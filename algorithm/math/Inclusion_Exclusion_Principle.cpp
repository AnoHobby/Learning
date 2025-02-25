/*AI GENERATED!!!*/
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// --- ジェネリックな join 関数 ---
// イテレータで渡された範囲の要素を、指定した区切り文字で連結した文字列を返す。
template<typename Iterator>
std::string join(Iterator begin, Iterator end, const std::string& delimiter) {
    std::ostringstream oss;
    if (begin != end) {
        oss << *begin;
        ++begin;
        while (begin != end) {
            oss << delimiter << *begin;
            ++begin;
        }
    }
    return oss.str();
}

// --- 各関数の実装 ---

// 全集合の和集合文字列を生成：例 "A ∪ B ∪ C" を "|A ∪ B ∪ C|" の形で返す。
std::string generateUnionString(const std::vector<std::string>& setNames) {
    return "|" + join(setNames.begin(), setNames.end(), " ∪ ") + "|";
}

// 組み合わせ（部分集合）のインデックスを受け取り、
// 対応する集合名を " ∩ " で連結した文字列を生成する。
// 例: {0,2,3} → "A ∩ C ∩ D" （setNames[0] = "A", 2 = "C", 3 = "D" とする）
std::string joinIntersection(const std::vector<int>& combination, const std::vector<std::string>& setNames) {
    std::vector<std::string> elements;
    for (int index : combination) {
        elements.push_back(setNames[index]);
    }
    return join(elements.begin(), elements.end(), " ∩ ");
}

// 再帰的に組み合わせ（部分集合）を生成する関数
void combine(int start, int k, const std::vector<std::string>& setNames,
    std::vector<int>& current, std::vector<std::vector<int>>& combinations) {
    if (k == 0) {
        combinations.push_back(current);
        return;
    }
    for (int i = start; i < static_cast<int>(setNames.size()); ++i) {
        current.push_back(i);
        combine(i + 1, k - 1, setNames, current, combinations);
        current.pop_back();
    }
}

// 包除原理の計算式を生成する関数
std::string generateInclusionExclusionFormula(const std::vector<std::string>& setNames) {
    int n = static_cast<int>(setNames.size());
    std::ostringstream formula;

    // 左辺：和集合部分
    formula << generateUnionString(setNames) << " = ";

    bool firstTerm = true;
    // k=1 から n まで、各部分集合に対する項を生成
    for (int k = 1; k <= n; k++) {
        std::vector<std::vector<int>> combinations;
        std::vector<int> current;
        combine(0, k, setNames, current, combinations);

        // 符号は (-1)^(k-1) となる（kが奇数なら正、偶数なら負）
        bool positive = ((k - 1) % 2 == 0);
        for (const auto& comb : combinations) {
            std::string term = "|" + joinIntersection(comb, setNames) + "|";
            if (firstTerm) {
                // 最初の項には符号の記述をせず、もし負なら "- " を付ける
                if (!positive)
                    formula << "- ";
                formula << term;
                firstTerm = false;
            }
            else {
                formula << (positive ? " + " : " - ") << term;
            }
        }
    }
    return formula.str();
}

int main() {
    // サンプル：集合名リスト
    std::vector<std::string> setNames = { "A", "B"};

    std::string formula = generateInclusionExclusionFormula(setNames);
    std::cout << "包除原理の計算式: " << formula << std::endl;

    return 0;
}
