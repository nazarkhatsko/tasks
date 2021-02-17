#include <iostream>
#include <string>


unsigned int input(std::string title) {

	std::cout << title;
	unsigned int n;
	std::cin >> n;
	return (n);

};


unsigned int largest_common_divisor(unsigned int a, unsigned int b) {

	unsigned int n = 0;
	for (unsigned int i = 1; i < (a + b) / 2; i++) {
		if (a % i == 0 && b % i == 0) {
			n = i;
		};
	};
	return (n);

};


unsigned int least_common_multiple(unsigned int a, unsigned int b) {

	return ((a * b) / largest_common_divisor(a, b));

};


int main() {

	std::cout << "least common multiple" << '\n' << '\n';

	auto a = input("enter a: ");
	auto b = input("enter b: ");
	std::cout << "result: " << least_common_multiple(a, b) << '\n';


	return (0);
};
