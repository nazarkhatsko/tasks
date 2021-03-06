#include <stdio.h>
#include <math.h>


float formula(float x) {

	return (log((1 + x) / (1 - x)));

};


float sum(float eps, float x) {

	float n = 0.0;
	float sum = 0.0;
	unsigned int i = 0;

	do {
		n = pow(x, 2.0 * i + 1.0) / (2.0 * i + 1.0);
		sum += n;
		i++;
	} while (fabs(n) > eps);
	sum *= 2;

	return (sum);

};


int main(void) {

	float eps = 0.0;
	printf("enter eps: ");
	scanf("%f", &eps);

	float x = 0.0;
	printf("enter x (|x| < 1): ");
	scanf("%f", &x);

	if (fabs(x) < 1) {
		printf("result sum: %f\n", sum(eps, x));
		printf("result formula: %f\n", formula(x));
	} else {
		printf("error x!\n");
	};

	return (0);

};
