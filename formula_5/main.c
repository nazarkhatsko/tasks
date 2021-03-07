#include <stdio.h>
#include <math.h>


float formula(float x) {

	return (pow(1.0 + x, 5.0 / 2.0));

};


float sum(float eps, float x) {

	float n = 0.0;
	float sum = 1.0;
	float k = 5.0 / 2.0;
	unsigned int i = 1;

	do {
		n = pow(x, i) * pow(1, k - i) * tgamma(k + 1) / (tgamma(i + 1) * tgamma(k - i + 1));
		sum += n;
		i++;
	} while (fabs(n) > eps);

	return (sum);

};


int main(void) {

	float eps = 0.0;
	printf("enter eps: ");
	scanf("%f", &eps);

	float x = 0.0;
	printf("enter x (|x| < 1): ");
	scanf("%f", &x);

	printf("\n");

	if (fabs(x) < 1) {
		printf("result sum: %f\n", sum(eps, x));
		printf("result formula: %f\n", formula(x));
	} else {
		printf("error x!\n");
	};

	return (0);

};
