#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 3
#define COLS 3

// Define a struct for Matrix that holds the matrix and its dimensions
typedef struct {
    int **matrix;  // Pointer to a 2D array (matrix)
    int rows;      // Number of rows in the matrix
    int cols;      // Number of columns in the matrix
} Matrix;

// Function to create a matrix dynamically, allocating memory for the matrix
Matrix create_matrix(int rows, int cols) {
    Matrix m;  // Declare a Matrix variable
    m.rows = rows;  // Set the number of rows
    m.cols = cols;  // Set the number of columns

    // Dynamically allocate memory for the matrix (rows)
    m.matrix = (int**)malloc(sizeof(int*) * rows);
    if (m.matrix == NULL) {  // Check if memory allocation failed
        printf("Memory allocation failed for matrix rows.\n");
        exit(1);  // Exit if memory allocation fails
    }

    // Dynamically allocate memory for each row of the matrix (columns)
    for (int i = 0; i < rows; i++) {
        m.matrix[i] = (int*)malloc(sizeof(int) * cols);
    }

    return m;  // Return the created matrix
}

// Function to free the dynamically allocated memory for a matrix
void free_matrix(Matrix* m) {
    // Loop through each row and free the memory for each row
    for (int i = 0; i < m->rows; i++) {
        free(m->matrix[i]);
    }
    // Free the memory allocated for the matrix itself
    free(m->matrix);
}

// Function to add two matrices (Matrix A + Matrix B)
int matrix_add(Matrix* a, Matrix* b, Matrix* result) {
    // Ensure both matrices have the same dimensions for addition
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Matrix dimensions must match for addition.\n");
        return 0;  // Return failure if dimensions don't match
    }

    // Perform element-wise addition
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->matrix[i][j] = a->matrix[i][j] + b->matrix[i][j];
        }
    }
    return 1;  // Return success
}

// Function to subtract two matrices (Matrix A - Matrix B)
int matrix_sub(Matrix* a, Matrix* b, Matrix* result) {
    // Ensure both matrices have the same dimensions for subtraction
    if (a->rows != b->rows || a->cols != b->cols) {
        printf("Matrix dimensions must match for subtraction.\n");
        return 0;  // Return failure if dimensions don't match
    }

    // Perform element-wise subtraction
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->matrix[i][j] = a->matrix[i][j] - b->matrix[i][j];
        }
    }
    return 1;  // Return success
}

// Function to transpose a matrix (swap rows and columns)
void matrix_transpose(Matrix* a, Matrix* result) {
    result->rows = a->cols;  // The number of rows in the result is the number of columns in A
    result->cols = a->rows;  // The number of columns in the result is the number of rows in A

    // Perform the transposition
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < a->cols; j++) {
            result->matrix[j][i] = a->matrix[i][j];
        }
    }
}

// Function to multiply two matrices (Matrix A * Matrix B)
int matrix_mult(Matrix* a, Matrix* b, Matrix* result) {
    // Ensure that the number of columns in A equals the number of rows in B for multiplication
    if (a->cols != b->rows) {
        printf("Matrix dimensions are incompatible for multiplication.\n");
        return 0;  // Return failure if dimensions don't match
    }

    // Perform matrix multiplication
    for (int i = 0; i < a->rows; i++) {
        for (int j = 0; j < b->cols; j++) {
            result->matrix[i][j] = 0;  // Initialize the result element
            for (int k = 0; k < a->cols; k++) {
                result->matrix[i][j] += a->matrix[i][k] * b->matrix[k][j];
            }
        }
    }
    return 1;  // Return success
}

// Function to calculate the inverse of a 3x3 matrix
int matrix_inverse_3x3(int matrix[ROWS][COLS], float result[ROWS][COLS]) {
    float determinant = 0;

    // Calculate the determinant of the matrix
    for (int j = 0; j < COLS; j++) {
        determinant += matrix[0][j] * (matrix[1][(j + 1) % 3] * matrix[2][(j + 2) % 3] -
                                       matrix[1][(j + 2) % 3] * matrix[2][(j + 1) % 3]);
    }
    printf("\n\ndeterminant: %2f\n", determinant);

    // Check if the matrix is singular (determinant = 0)
    if (determinant == 0) {
        printf("Matrix is singular, no inverse exists.\n");
        return 1;  // Return failure if the matrix is singular
    }

    // Calculate the inverse if the determinant is non-zero
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            result[i][j] = (((matrix[(j + 1) % 3][(i + 1) % 3] * matrix[(j + 2) % 3][(i + 2) % 3]) -
                             (matrix[(j + 1) % 3][(i + 2) % 3] * matrix[(j + 2) % 3][(i + 1) % 3])) / determinant);
        }
    }
    return 1;  // Return success
}

int main() {
    int rowsA, colsA, rowsB, colsB;
    char input[10];
    float inverse[3][3];

    // Display introductory message
    printf("\n  ------------ \n Welcome to the Matrix calculator \n ------------ \n created by Almeida \n\n");
    printf("\n*** NOTE: Inverse operation is only supported for 3x3 matrices. ***\n\n");
    printf("Please ensure that your matrix is 3 rows by 3 columns to proceed.\n\n");
    printf("Please enter the matrix elements in row-major order.\n\n");

    // Get the dimensions for Matrix A
    printf("Enter the number of rows for Matrix A: ");
    scanf_s("%d", &rowsA);
    printf("Enter the number of columns for Matrix A: ");
    scanf_s("%d", &colsA);

    // Create Matrix A
    Matrix a = create_matrix(rowsA, colsA);

    // Get elements for Matrix A from the user
    printf("\nEnter elements for Matrix A (%dx%d):\n", rowsA, colsA);
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsA; j++) {
            printf("Enter element[%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &a.matrix[i][j]);
        }
    }

    // Get the dimensions for Matrix B
    printf("Enter the number of rows for Matrix B: ");
    scanf_s("%d", &rowsB);
    printf("Enter the number of columns for Matrix B: ");
    scanf_s("%d", &colsB);

    // Create Matrix B
    Matrix b = create_matrix(rowsB, colsB);

    // Get elements for Matrix B from the user
    printf("\nEnter elements for Matrix B (%dx%d):\n", rowsB, colsB);
    for (int i = 0; i < rowsB; i++) {
        for (int j = 0; j < colsB; j++) {
            printf("Enter element[%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &b.matrix[i][j]);
        }
    }

    // Ask user for the desired operation (addition, subtraction, multiplication, transpose, inverse)
    printf("Enter operation:\n + : add \n - : subtract \n * : multiply\n t : transpose\n> i : inverse \n ");
    scanf_s("%s", input);

    Matrix result;
    int success = 0;

    // Perform the selected operation
    if (input[0] == '+') {
        if (rowsA == rowsB && colsA == colsB) {
            result = create_matrix(rowsA, colsA);  // Result has same size as A and B
            success = matrix_add(&a, &b, &result);
        }
    }
    else if (input[0] == '-') {
        if (rowsA == rowsB && colsA == colsB) {
            result = create_matrix(rowsA, colsA);  // Result has same size as A and B
            success = matrix_sub(&a, &b, &result);
        }
    }
    else if (input[0] == '*') {
        if (colsA == rowsB) {
            result = create_matrix(rowsA, colsB);  // Result will have rows of A and cols of B
            success = matrix_mult(&a, &b, &result);
        }
    }
    else if (input[0] == 't') {
        result = create_matrix(colsA, rowsA);  // Transpose of A
        matrix_transpose(&a, &result);
        success = 1;
    }
    else if (input[0] == 'i') {
        if (rowsA == 3 && colsA == 3) {
            int temp[3][3];
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    temp[i][j] = a.matrix[i][j];
                }
            }
            success = matrix_inverse_3x3(temp, inverse);
        }
        else {
            printf("Inverse operation is only supported for 3x3 matrices.\n");
        }
    }
    else {
        printf("Invalid operation.\n");
    }

    // Print the result of the operation
    if (success) {
        printf("The result is:\n");
        if (input[0] == 'i') {
            // Print inverse of the matrix
            for (int i = 0; i < ROWS; i++) {
                for (int j = 0; j < COLS; j++) {
                    printf("%6.2f ", inverse[i][j]);
                }
                printf("\n");
            }
        }
        else {
            // Print the result matrix
            for (int i = 0; i < result.rows; i++) {
                for (int j = 0; j < result.cols; j++) {
                    printf("%d ", result.matrix[i][j]);
                }
                printf("\n");
            }
            free_matrix(&result);  // Free memory for result matrix
        }

        // Free memory for matrices A and B
        free_matrix(&a);
        free_matrix(&b);
    }
    return 0;  // Exit the program
}
