import <complex>;
import <cmath>;
import <numbers>;
import <vector>;
import <iostream>;
auto dft(std::vector<double> x) {
	std::vector<std::complex<double> > output(x.size(),std::complex<double>(0,0));
	for (auto k = 0; k < x.size(); ++k) {
		for (auto i = 0; i < x.size(); ++i) {
			output[k] += x[i] * std::exp(std::complex<double>(0, 2 * std::numbers::pi * k * i / x.size()));
		}
	}
	return output;
}
auto main()->int {
	std::vector<double> a{1,2,3,4 };
	for (auto i : dft(a)) {
		std::cout << i.real() << "," << i.imag() << std::endl;;
	}
	return 0;
}