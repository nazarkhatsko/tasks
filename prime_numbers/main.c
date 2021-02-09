#include <stdio.h>
#include <stdlib.h>


unsigned int input(char *title) {

	printf("%s", title);
	unsigned int n;
	scanf("%u", &n);
	return (n);

};


unsigned int is_prime(unsigned int n){

	for (unsigned int i = 2; i <= n / 2; i++)
	if ((n % i) == 0) {
		return (0);
	};
	return (1);

};


unsigned int sum_prime_numbers(unsigned int n) {

	unsigned int sum = 0;
	for (unsigned int i = 2; i <= n; i++) {
		if (is_prime(i)) {
			sum += i;
		};
	};
	return (sum);

};


int main(void) {

	unsigned int n = input("enter n: ");
	printf("result: %u\n", sum_prime_numbers(n));

	return (0);

};
