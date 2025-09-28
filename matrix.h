#ifndef MATRIX
#define MATRIX

#include <stdlib.h>

int** addition(int height, int width, int first_matrix[height][width], int second_matrix[height][width]) {
	int** matrix = (int**)malloc(height*sizeof(int*));
	if (matrix == NULL) return NULL;

	for (int i = 0; i < width; i++) {
		matrix[i] = (int*)malloc(width*sizeof(int*));
		if (matrix[i] == NULL) {
			for (int j = 0; j < i; j++) free(matrix[j]);
			free(matrix);
			return NULL;
		};
	};

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = first_matrix[i][j] + second_matrix[i][j];
			printf("%i ", matrix[i][j]);
		};
		printf("\n");
	}; return matrix;
};

int** subtract(int height, int width, int first_matrix[height][width], int second_matrix[height][width]) {
	int** matrix = (int**)malloc(height*sizeof(int*));
	if (matrix == NULL) return NULL;

	for (int i = 0; i < width; i++) {
		matrix[i] = (int*)malloc(width*sizeof(int*));
		if (matrix[i] == NULL) {
			for (int j = 0; j < i; j++) free(matrix[j]);
			free(matrix);
			return NULL;
		};
	};

	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			matrix[i][j] = first_matrix[i][j] - second_matrix[i][j];
			printf("%i ", matrix[i][j]);
		};
		printf("\n");
	}; return matrix;
};

int** transposition(int height, int width, int matrix[height][width]) {
	int** new_matrix = (int**)malloc(width*sizeof(int*));
	if (new_matrix == NULL) return NULL;

	for (int i = 0; i < width; i++) {
		new_matrix[i] = (int*)malloc(height*sizeof(int));
		if (new_matrix[i] == NULL) {
			for (int j = 0; j < i; j++) free(new_matrix[j]);
			free(new_matrix);
			return NULL;
		};
	};

	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			new_matrix[i][j] = matrix[j][i];
		};
	}; return new_matrix;
};

int determinant(int size, int matrix[size][size]) {
	int det = 0;
	int submatrix[size-1][size-1];

	if (size == 1) 
		return matrix[0][0];
	if (size == 2)
		return 	matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];

	int sign = 1;
	for (int x = 0; x < size; x++) {
		int subi = 0;
		for (int i = 0; i < size; i++) {
			if (i == 0) continue;
			int subj = 0;
			for (int j = 0; j < size; j++) {
				if (j == x) continue;
				submatrix[subi][subj] = matrix[i][j];
				subj++;
			}; subi++;
		};
		det += sign * matrix[0][x] * determinant(size-1, submatrix);
		sign = -sign;
	}; return det;
};

#endif