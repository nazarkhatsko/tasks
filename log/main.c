#include <stdio.h>
#include <math.h>


float input(char *title) {

	printf("%s", title);
	float n = 0.0;
	scanf("%f", &n);
	return (n);

};


float my_log(float x) {

	int k = 0;
	while (x > 2.0) { 
		x /= 2.0;
		k += 1;
	};
	x -= 1.0;

	int n = 1;
	float s = 0.0;
	float an = x;
	while (fabs(an) > 0.000001) {
		s += an;
		n += 1;
		an *= -x * (n - 1) / n;
	};
	s += k * M_LN2;

	return (s);

};


int main() {

	float n = input("enter n: ");
	printf("result my log: %f\n", my_log(n));
	printf("result standard log: %f\n", log(n));

	return (0);

};
