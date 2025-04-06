#include <stdio.h>
#include <stdlib.h>


int main() {
		
	int** matrix = (int**)calloc(3 ,sizeof(int*));

	for (int i = 0; i < 3; i++) {
		matrix[i] = (int*)calloc(3 ,sizeof(int));
	}

	printf("Matrix created by Dynamic memory allocation:\n");

	for (int i = 0; i < 3;i++) {
		for (int j = 0; j < 3;j++) {
			printf("%d", matrix[i][j]);
		}
		printf("\n");
	}

	for (int i = 0; i < 3;i++) {
		free(matrix[i]);
	}
	free(matrix);
	return 0;

	}