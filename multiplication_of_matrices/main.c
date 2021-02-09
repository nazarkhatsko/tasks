#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned int input(char *title) {

	printf("%s", title);
	unsigned int size;
	scanf("%u", &size);
	return (size);

};


unsigned int * generate_random_vector(unsigned int size) {

	unsigned int *vector = malloc(sizeof (*vector) * size);
	for (unsigned int i = 0; i < size; i++) {
		vector[i] = rand() % 10;
	};
	return (vector);

};


unsigned int ** generate_random_matrix(unsigned int size) {

	unsigned int **matrix = malloc(sizeof (*matrix) * size);
	for (unsigned int i = 0; i < size; i++) {
		matrix[i] = generate_random_vector(size);
	};
	return (matrix);

};


unsigned int ** multiplication_matrices(unsigned int size, unsigned int **matrix_a, unsigned int **matrix_b) {

	unsigned int **matrix = malloc(sizeof (*matrix) * size);
	for (unsigned int i = 0; i < size; i++) {
		matrix[i] = malloc(sizeof (*matrix[i]) * size);
		for (unsigned int t = 0; t < size; t++) {
			for (unsigned int n = 0; n < size; n++) {
				matrix[i][t] += matrix_a[i][n] * matrix_b[n][t];
			};
		};
	};
	return (matrix);

};


void print(unsigned int size, unsigned int **matrix) {

	for (unsigned int i = 0; i < size; i++) {
		for (unsigned int n = 0; n < size; n++) {
			printf("%u ", matrix[i][n]);
		};
		printf("\n");
	};

};


int main(void) {

	srand(time(NULL));

	unsigned int size = input("enter size: ");

	printf("\nA:\n");
	unsigned int **matrix_a = generate_random_matrix(size);
	print(size, matrix_a);

	printf("\nB:\n");
	unsigned int **matrix_b = generate_random_matrix(size);
	print(size, matrix_b);

	printf("\nC:\n");
	unsigned int begin = time(NULL);
	unsigned int **matrix_c = multiplication_matrices(size, matrix_a, matrix_b);
	unsigned int end = time(NULL);
	print(size, matrix_c);

	printf("\ntime: %u seconds\n", (end - begin));

	free(matrix_a);
	free(matrix_b);
	free(matrix_c);

	return (0);

};
