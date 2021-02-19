#include <iostream>
#include <string>
#include <vector>
#include <numeric>
#include <cmath>


long int input(std::string title) {

	std::cout << title;
	long int n = 0;
	std::cin >> n;
	return (n);

};


bool isprime(long int n) { 

	if (n <= 1) {
		return (false);
	};

	for (unsigned int i = 2; i < (int)std::sqrt(n); i++) {
		if (n % i == 0) {
			return (false);
		};
	};
	return (true); 

};


long int pollard(long int n) {

	long int a = 2;
	unsigned int i = 2;
	while (true) {
		a = (long int)std::pow(a, i) % n;
		long int d = std::gcd(a - 1, n);

		if (d > 1) {
			return (d);
		};

		i++;
	};
	return (0);

};


void print(std::string title, const std::vector<long int> &v) {

	std::cout << title;
	for (auto i : v) {
		std::cout << i << ' ';
	};
	std::cout << '\n';

};


int main() {

	std::cout << "Pollard’s p-1 Algorithm" << '\n';
	std::cout << "decomposition of a large odd integer n into its corresponding prime factors" << '\n';
	std::cout << "examples 143, 657, 1233, 1603 ..." << '\n' << '\n';

	long int n = input("enter n: ");
	std::vector<long int> v;
	while (true) {
		v.push_back(pollard(n));
		long int r = n / v.back();

		if (isprime(r)) {
			v.push_back(r);
			break;
		} else {
			n = r;
		};
	};

	print("result: ", v);

	return (0);

};
