# 🧮 Matrix Calculator in C

Welcome to the **Matrix Calculator**! 🎉 This program in C allows you to perform basic matrix operations like addition, subtraction, multiplication, transposition, and inversion (for 3x3 matrices). It’s designed to be simple and intuitive for beginners learning C programming.

## 🧑‍🏫 Learning C with Matrix Operations

This program introduces you to important concepts in C, including:

- **Memory Management**: Using `malloc` and `free` to dynamically allocate and deallocate memory.
- **2D Arrays**: Handling matrix data using arrays of pointers.
- **Functions**: Using functions to perform operations like addition, subtraction, and transposition on matrices.
- **Conditionals and Loops**: Using loops and conditions to perform operations on matrices.

## 🚀 Features

- **Matrix Addition (+)**: Adds two matrices of the same dimensions.
- **Matrix Subtraction (-)**: Subtracts one matrix from another.
- **Matrix Multiplication (*)**: Multiplies two matrices (requires the number of columns of the first matrix to match the number of rows of the second matrix).
- **Matrix Transposition (t)**: Converts a matrix into its transpose.
- **Matrix Inversion (i)**: Inverts a 3x3 matrix (only for 3x3 matrices).

## 📚 How to Use

1. **Matrix Dimensions**: Enter the number of rows and columns for two matrices (Matrix A and Matrix B).
2. **Matrix Elements**: Input the elements of each matrix in row-major order.
3. **Choose an Operation**: Pick an operation by entering one of the following:
   - `+` for matrix addition
   - `-` for matrix subtraction
   - `*` for matrix multiplication
   - `t` for matrix transposition
   - `i` for matrix inversion (only for 3x3 matrices)
4. **View the Result**: The result of the operation will be printed in the console.

## 🚀 Example Run

```text
Welcome to the Matrix calculator 

Enter the number of rows for Matrix A: 3
Enter the number of columns for Matrix A: 3

Enter elements for Matrix A (3x3):
Enter element[1][1]: 1
Enter element[1][2]: 2
Enter element[1][3]: 3
Enter element[2][1]: 4
Enter element[2][2]: 5
Enter element[2][3]: 6
Enter element[3][1]: 7
Enter element[3][2]: 8
Enter element[3][3]: 9

Enter the number of rows for Matrix B: 3
Enter the number of columns for Matrix B: 3

Enter elements for Matrix B (3x3):
Enter element[1][1]: 9
Enter element[1][2]: 8
Enter element[1][3]: 7
Enter element[2][1]: 6
Enter element[2][2]: 5
Enter element[2][3]: 4
Enter element[3][1]: 3
Enter element[3][2]: 2
Enter element[3][3]: 1

Choose an operation (+, -, *, t, i): +

Result:
Matrix A + Matrix B = 
[ [10 10 10] ]
[ [10 10 10] ]
[ [10 10 10] ]
