#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
			if (j == 0) printf("| %i ", matrix[i][j]);
			else printf("%i ", matrix[i][j]);
		}; printf("|\n");
	}; printf("\n------\n\n");

	char math_operator[20] = "";
	printf("Choose a mathematical operation [+, -, *, transposition, determinant, inverse]: ");
	scanf(" %20s", &math_operator);

	printf("\n------\n\n");
	if (strcmp(math_operator, "+") == 0) {
		
		if (height == width) {
			int new_matrix[height][width];
			for (int i = 0; i < height; i++ ) {
				for (int j = 0; j < width; j++) {
					printf("Enter value for second matrix [%i][%i]: ", i+1, j+1);
					scanf(" %2i", &new_matrix[i][j]);
				};
			};

			int** addition_matrix = addition(height, width, matrix, new_matrix);
			printf("\n------\n\nResult: \n\n");
			for (int i = 0; i < height; i++ ) {
				for (int j = 0; j < width; j++) {
					if (j == 0) printf("| %i ", addition_matrix[i][j]);
					else printf("%i ", addition_matrix[i][j]);
				}; printf("|\n");
			}; printf("\n------\n\n");

			for (int i = 0; i < height; i++) {
				free(addition_matrix[i]);
			}; free(addition_matrix);
		} else {
			printf("It is impossible to add up the matrices - the main matrix must be square.");
		};

	} else if (strcmp(math_operator, "-") == 0) {
		
		if (height == width) {
			int new_matrix[height][width];
			for (int i = 0; i < height; i++ ) {
				for (int j = 0; j < width; j++) {
					printf("Enter value for second matrix [%i][%i]: ", i+1, j+1);
					scanf(" %2i", &new_matrix[i][j]);
				};
			};

			int** subtract_matrix = subtract(height, width, matrix, new_matrix);
			printf("\n------\n\nResult: \n\n");
			for (int i = 0; i < height; i++ ) {
				for (int j = 0; j < width; j++) {
					if (j == 0) printf("| %i ", subtract_matrix[i][j]);
					else printf("%i ", subtract_matrix[i][j]);
				}; printf("|\n");
			}; printf("\n------\n\n");

			for (int i = 0; i < height; i++) {
				free(subtract_matrix[i]);
			}; free(subtract_matrix);
		} else {
			printf("It is impossible to find the sum of the matrices - the main matrix must be square.");
		};

	} else if (strcmp(math_operator, "transposition") == 0) {

		printf("The result of the matrix transpose:\n ");
		int** transpos = transposition(height, width, matrix);
		for (int i = 0; i < width; i++) {
			for (int j = 0; j < height; j++) {
				if (j == 0) printf("| %i ", transpos[i][j]);
				else printf("%i ", transpos[i][j]);
			}; printf("|\n");
		};

		for (int i = 0; i < width; i++) {
			free(transpos[i]);
		}; free(transpos);

	} else if (strcmp(math_operator, "determinant") == 0) {

		if (height == width) {
			printf("Daterminant: %i", determinant(height, matrix));
		} else {
			printf("It is impossible to find the inverse matrix: the matrix is not square.");
		};

	} else printf("Invalid math operator.");

	return EXIT_SUCCESS;
};