#include <iostream>
#include <string>


unsigned int input(std::string title) {

	std::cout << title;
	unsigned int n;
	std::cin >> n;
	return (n);

};


unsigned int get_num(unsigned int n, unsigned int k) {

	unsigned int res = 0;
	for (unsigned int i = 1; i <= n; i++) {
		res += k;
	};
	return (res);

};


int main() {

	std::cout << "sum of the arithmetic progression" << '\n' << '\n';

	auto n = input("enter n: ");
	auto k = input("enter k: ");
	std::cout << "result: " << std::fixed << ((k + get_num(n, k)) * n) / 2 << '\n';

	return (0);

};
