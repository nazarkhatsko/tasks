#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int input(char *title) {

	printf("%s", title);
	int n = 0;
	scanf("%i", &n);
	return (n);

};


float func(float x) {

	return (4 * (1 + sqrt(x)) * log10(x) - 1);

};


float find_root(float (*f)(float), float a, float b) {

	float c = 0.0;
	while ((b - a) / 2.0 > 0.000001) {
		c = (a + b) / 2.0;

		if ((f(a) * f(c)) > 0.0) {
			a = c;
		} else {
			b = c;
		};
	};
	return (c);

};


int main(void) {

	printf("search for the roots of the equation\n");
	printf("using the method of dividing the segment in half\n");
	printf("equation: 4 * (1 + sqrt(x)) * log10(x) - 1\n");
	printf("\n");

	int a = input("enter a: ");
	int b = input("enter b: ");

	printf("result: %f\n", find_root(func, a, b));

	return (0);

};
