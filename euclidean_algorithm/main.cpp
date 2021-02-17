#include <iostream>
#include <string>


unsigned int input(std::string title) {

	std::cout << title;
	unsigned int n;
	std::cin >> n;
	return (n);

};


unsigned int euclidean_algorithm(unsigned int a, unsigned int b) {

	while (a != 0) {
		if (a < b) {
			std::swap(a, b);
		};

		a -= b;
	};

	return (b);

};


int main() {

	std::cout << "euclidean algorithm" << '\n' << '\n';

	auto a = input("enter a: ");
	auto b = input("enter b: ");
	std::cout << "result: " << euclidean_algorithm(a, b) << '\n';

	return (0);

};
