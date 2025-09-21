#ifndef MATRIX_H
#define MATRIX_H

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
	};

	return det;
};

#endif