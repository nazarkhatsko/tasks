#include <stdio.h>
#include <stdlib.h>
#include <math.h>


float input(char *title) {

	printf("%s", title);
	float n = 0.0;
	scanf("%f", &n);
	return (n);

};


float my_cos(float x) {

	float n = 1.0;
	float sum = 0.0;
	unsigned int i = 1;

	do {
		sum += n;
		n *= (-1.0 * pow(x, 2)) / ((i * 2 - 1) * (i * 2));
		i++;
	} while (fabs(n) > 0.000000001);

	return (sum);

};


int main(void) {

	float x = input("enter x: ");
	printf("result my cos: %f\n", my_cos(x));
	printf("result standard cos: %f\n", cos(x));

	return (0);

};
