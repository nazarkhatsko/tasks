#include <iostream>
#include <string>
#include <vector>
#include <numeric>


unsigned int input(std::string title) {

	std::cout << title;
	unsigned int n;
	std::cin >> n;
	return (n);

};


std::vector<unsigned int> generate_sequence(unsigned int n) {

	std::vector<unsigned int> v;
	for (unsigned int i = 1; i <= n; i++) {
		v.push_back(i);
	};
	return(v);

};


int main() {

	auto n = input("enter n: ");
	auto v = generate_sequence(n);
	auto res = std::accumulate(v.begin(), v.end(), 0);
	std::cout << "result: " << res << '\n';

	return (0);
	
};
