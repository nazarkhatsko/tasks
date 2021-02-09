#include <iostream>
#include <string>


unsigned int input(std::string title) {

	std::cout << title;
	unsigned int n;
	std::cin >> n;
	return (n);

};


int main() {

	auto n = input("enter n: ");

	int fib_1 = 1;
	int fib_2 = 1;
	int result = 0;
	while (true) {
		fib_2 = fib_1;
		fib_1 = result;
		result = fib_1 + fib_2;

		if (result > n) {
			break;
		};
	};

	std::cout << "result: " << result << '\n';

	return (0);

};
