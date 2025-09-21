#include <stdio.h>
#include "matrix.h"

int main() {
	printf("\n\n --- Matrix calculator --- \n\n");

	int height, width;
	printf("Enter the height of the matrix: ");
	scanf(" %1i", &height);
	printf("Enter the width of the matrix: ");
	scanf(" %1i", &width);

	int matrix[height][width];
	for (int i = 0; i < height; i++ ) {
		for (int j = 0; j < width; j++) {
			printf("Enter value for current coords [%i][%i]: ", i+1, j+1);
			scanf(" %2i", &matrix[i][j]);
		};
	};

	printf("\n------\n\nFinal matrix: \n\n");
	for (int i = 0; i < height; i++ ) {
		for (int j = 0; j < width; j++) {
			printf("%i ", matrix[i][j]);
		};
		printf("\n");
	};
	printf("\n------\n\n");

	if (height == width) {
		printf("Determinant of matrix: %d", determinant(height, matrix));
	} else {
		printf("It is impossible to find the inverse matrix: the matrix is not square.");
	};

	return 0;
};