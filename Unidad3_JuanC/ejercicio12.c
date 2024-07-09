#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define N 3 // Define el tamaño de las matrices (NxN)

// Función para encontrar la inversa de una matriz
bool inverseMatrix(double matrix[N][N], double inverse[N][N]) {
    double temp;

    // Crear una matriz identidad
    double identity[N][N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j)
                identity[i][j] = 1;
            else
                identity[i][j] = 0;
        }
    }

    // Crear una copia de la matriz original
    double augmented[N][2*N];
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            augmented[i][j] = matrix[i][j];
        }
        for (int j = N; j < 2*N; ++j) {
            augmented[i][j] = identity[i][j-N];
        }
    }

    // Aplicar eliminación de Gauss-Jordan
    for (int i = 0; i < N; ++i) {
        if (augmented[i][i] == 0.0) {
            printf("Error: Matriz no invertible\n");
            return false;
        }
        temp = augmented[i][i];
        for (int j = 0; j < 2*N; ++j) {
            augmented[i][j] = augmented[i][j] / temp;
        }
        for (int j = 0; j < N; ++j) {
            if (j != i) {
                temp = augmented[j][i];
                for (int k = 0; k < 2*N; ++k) {
                    augmented[j][k] = augmented[j][k] - augmented[i][k] * temp;
                }
            }
        }
    }

    // Separar la matriz inversa
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            inverse[i][j] = augmented[i][j+N];
        }
    }

    return true;
}

// Función para multiplicar dos matrices
void multiplyMatrices(double firstMatrix[N][N], double secondMatrix[N][N], double resultMatrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            resultMatrix[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

// Función para imprimir una matriz
void printMatrix(double matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%0.2lf ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define dos matrices de ejemplo
    double A[N][N] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    double B[N][N] = {
        {7, 8, 9},
        {4, 5, 6},
        {1, 2, 3}
    };

    double A_inv[N][N]; // Matriz para almacenar la inversa de A
    double X[N][N];     // Matriz para almacenar el resultado

    // Encuentra la inversa de A
    if (!inverseMatrix(A, A_inv)) {
        printf("No se puede encontrar la inversa de A.\n");
        return 1;
    }

    // Multiplica la inversa de A por B para obtener X
    multiplyMatrices(A_inv, B, X);

    // Imprime las matrices
    printf("Matriz A:\n");
    printMatrix(A);

    printf("\nMatriz B:\n");
    printMatrix(B);

    printf("\nInversa de A:\n");
    printMatrix(A_inv);

    printf("\nMatriz Resultante (X = A^-1 * B):\n");
    printMatrix(X);

    return 0;
}
