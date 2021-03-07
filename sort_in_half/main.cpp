#include <iostream>
#include <vector>
#include <string>
#include <random>


auto input(const std::string &s) -> std::string {

	std::cout << s;
	std::string r;
	std::cin >> r;
	return (r);

};


auto gen_rand_vec(long int size, int a, int b) -> std::vector<int> {

	std::vector<int> v(size);
	std::default_random_engine gen;
	std::uniform_int_distribution<int> db(a, b);
	for (auto &i : v) {
		i = db(gen);
	};
	return (v);

};


auto sort_algorithm(std::vector<int> &v) -> void {

	for (int i = 0; i < v.size(); i++) {
		if (v.at(i) < 0) {
			for (int n = 0; n < v.size(); n++) {
				if (v.at(n) > 0 and i > n) {
					std::swap(v.at(i), v.at(n));
					break;
				};
			};
		};
	};

};


auto print_vec(const std::string &s, const std::vector<int> &v) -> void {

	std::cout << s;
	for (auto i : v) {
		std::cout << i << ' ';
	};
	std::cout << '\n';

};


auto main() -> int {

	auto n = std::stoi(input("enter n: "));
	auto v = gen_rand_vec(n, -10, 10);
	print_vec("array old: ", v);
	sort_algorithm(v);
	print_vec("array new: ", v);

	return (0);

};
