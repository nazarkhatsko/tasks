#include <stdio.h>
#include <stdlib.h>

#define SIZE 10


typedef struct {

	char brand[32];
	char number[8];
	unsigned int year;
	float run;

} CAR;


int compare_function(const void *a, const void *b) {

	CAR *a_2 = (CAR *)a;
	CAR *b_2 = (CAR *)b;
	return (a_2->year > b_2->year);

};


void print(CAR *cars, unsigned int count) {

	printf("count\tbrand\tnumber\tyear\trun\n");
	for (unsigned int i = 0; i < count; i++) {
		printf("%u\t%s\t%s\t%u\t%.2f\n", i + 1, cars[i].brand, cars[i].number, cars[i].year, cars[i].run);
	};

};


int main(void) {

	CAR cars[SIZE];

	for (unsigned int i = 0; i < SIZE; i++) {
		printf("count: %u/%u\n", i + 1, SIZE);

		printf("enter brand: ");
		scanf("%31s", cars[i].brand);

		printf("enter number: ");
		scanf("%8s", cars[i].number);

		printf("enter year: ");
		scanf("%u", &cars[i].year);

		printf("enter run: ");
		scanf("%f", &cars[i].run);

		printf("\n");
	};

	qsort(cars, SIZE, sizeof (*cars), compare_function);

	print(cars, SIZE);

	return (0);

};
