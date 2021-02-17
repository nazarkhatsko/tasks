#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>


int input(std::string title) {

	std::cout << title;
	int n;
	std::cin >> n;
	return (n);

};


std::vector<float> generate_sequence(unsigned int n, int x) {

	std::vector<float> v;
	for (unsigned int i = 1; i <= n; i++) {
		v.push_back(
			std::pow(-1, i + 1) *
			(2 * i + 1) * std::pow(x, i) /
			std::tgamma(2 * i)
		);
	};
	return(v);

};


void print(std::string title, const std::vector<float> &v) {

	std::cout << title;
	for (auto i : v) {
		std::cout << i << ' ';
	};
	std::cout << '\n';

};


int main() {

	auto n = input("enter n: ");
	auto x = input("enter x: ");
	auto v = generate_sequence(n, x);
	print("elements: ", v);
	auto res = std::accumulate(v.begin(), v.end(), decltype(v)::value_type(0));
	std::cout << "result: " << std::fixed << res << '\n';

	return (0);

};
