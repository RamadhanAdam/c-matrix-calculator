#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3

void matrix_add(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            result[i][j] = a[i][j] + b[i][j];
}

void matrix_mult(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++) {
            result[i][j] = 0;
            for (int k = 0; k < COLS; k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
}

void matrix_sub(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++)
        for (int j = 0; j < COLS; j++)
            result[i][j] = a[i][j] - b[i][j];
}

void matrix_transpose(int a[ROWS][COLS], int result[COLS][ROWS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = a[j][i];
        }
    }
}

void matrix_inverse(int matrix[ROWS][COLS], float result[ROWS][COLS]) {
    float determinant = 0;
    for (int j = 0; j < COLS; j++) {
        determinant = determinant + (matrix[0][j] * (matrix[1][(j + 1) % 3] * matrix[2][(j + 2) % 3])
            - matrix[1][(j + 2) % 3] * matrix[2][(j + 1) % 3]);
    }
    printf("\n\ndeterminant: %2f\n", determinant);

    // Singular matrix if determinant = 0
    if (determinant == 0) {
        printf("Matrix is singular, no inverse exists.\n");
        return;
    }

    // Calculate the inverse of the matrix if determinant is non-zero
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS;j++) {
            result[i][j] = (((matrix[(j + 1) % 3][(i + 1) % 3] * matrix[(j + 2) % 3][(i + 2) % 3]) - (matrix[(j + 1) % 3][(i + 2) % 3] * matrix[(j + 2) % 3][(i + 1) % 3])) / determinant);
        }
    }
}

int main() {
    int a[ROWS][COLS], b[ROWS][COLS], c[ROWS][COLS];
    float inverse[ROWS][COLS];
    char input[10];

    printf("\n  ------------ \n Welcome to the Matrix calculator \n ------------ \n created by Almeida \n");

    // User input for matrix a
    printf("\nEnter elements for matrix A (3x3):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("\n Enter an element[%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &a[i][j]);
        }
    }

    // User input for matrix b
    printf("\nEnter elements for matrix B (3x3):\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("\n Enter an element[%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &b[i][j]);
        }
    }

    printf("Enter operation:\n + : add \n - : subtract \n * : multiply\n i : inverse (not implemented)\n t : transpose\n> ");
    scanf_s("%s", input, (unsigned int)sizeof(input));

    if (input[0] == '+') {
        matrix_add(a, b, c);
    }
    else if (input[0] == '*') {
        matrix_mult(a, b, c);
    }
    else if (input[0] == '-') {
        matrix_sub(a, b, c);
    }
    else if (input[0] == 't') {
        matrix_transpose(a, c);
    }
    else if (input[0] == 'i') {
        matrix_inverse(a, inverse);
    }
    else {
        printf("Invalid operand.\n");
        return 1;
    }

    printf("The result is:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (input[0] == 'i') {
                printf("%2f ", inverse[i][j]);
            }
            else {
                printf("%d ", c[i][j]);
            }
        }
        printf("\n");
    }

    return 0;
}
