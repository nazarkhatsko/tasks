#include <iostream>


unsigned int input(std::string title) {

	std::cout << title;
	unsigned int n;
	std::cin >> n;
	return (n);

};


float func(float n, unsigned int count) {

	if (count == 0) {
		return (n + (1 / 100));
	};

	return (n + (1 / func(n + 2 + (1 / 100), count - 1)));

};


int main() {

	auto n = input("enter n: ");
	auto res = func(0, n);
	std::cout << "result: " << std::fixed << res << '\n';

	return (0);

};
