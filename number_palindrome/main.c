#include <stdio.h>
#include <stdlib.h>
#include <string.h>


unsigned int input(const char *title) {

	printf("%s", title);
	unsigned int n;
	scanf("%u", &n);
	return (n);

};


unsigned int reverse(unsigned int n) {

	unsigned int rn = 0;
	while (n >= 1) {
		rn *= 10;
		rn += n % 10;
		n /= 10;
	};
	return (rn);

};


int main(void) {

	unsigned int n = input("enter n: ");
	unsigned int rn = reverse(n);

	if (n == rn) {
		printf("result: yes\n");
	} else {
		printf("result: no\n");
	};

	return (0);

};
