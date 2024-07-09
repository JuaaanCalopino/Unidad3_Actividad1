#include <stdio.h>

#define N 3 // Define el tamaño de las matrices (NxN)

// Función para multiplicar dos matrices
void multiplyMatrices(int firstMatrix[N][N], int secondMatrix[N][N], int resultMatrix[N][N]) {
    // Inicializa la matriz de resultado con ceros
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            resultMatrix[i][j] = 0;
        }
    }

    // Multiplica las matrices
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                resultMatrix[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }
}

// Función para imprimir una matriz
void printMatrix(int matrix[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define dos matrices de ejemplo
    int firstMatrix[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int secondMatrix[N][N] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    int resultMatrix[N][N]; // Matriz para almacenar el resultado

    // Multiplica las matrices
    multiplyMatrices(firstMatrix, secondMatrix, resultMatrix);

    // Imprime las matrices
    printf("Primera Matriz:\n");
    printMatrix(firstMatrix);

    printf("\nSegunda Matriz:\n");
    printMatrix(secondMatrix);

    printf("\nMatriz Resultante (Producto):\n");
    printMatrix(resultMatrix);

    return 0;
}
