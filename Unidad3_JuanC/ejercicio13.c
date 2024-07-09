#include <stdio.h>

#define N 3 // Tamaño de la matriz (NxN)

// Función para multiplicar dos matrices
void multiplyMatrices(int firstMatrix[N][N], int secondMatrix[N][N], int resultMatrix[N][N]) {
    int temp[N][N]; // Matriz temporal para almacenar el resultado de la multiplicación

    // Multiplica las matrices
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            temp[i][j] = 0;
            for (int k = 0; k < N; ++k) {
                temp[i][j] += firstMatrix[i][k] * secondMatrix[k][j];
            }
        }
    }

    // Copia el resultado a la matriz de resultado final
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            resultMatrix[i][j] = temp[i][j];
        }
    }
}

// Función para elevar una matriz a una potencia k
void powerMatrix(int matrix[N][N], int k, int resultMatrix[N][N]) {
    // Inicializa la matriz de resultado como la matriz identidad
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (i == j)
                resultMatrix[i][j] = 1;
            else
                resultMatrix[i][j] = 0;
        }
    }

    int temp[N][N]; // Matriz temporal para almacenar la multiplicación

    // Realiza la potencia
    while (k > 0) {
        if (k % 2 != 0) { // Si k es impar, multiplica resultMatrix por matrix
            multiplyMatrices(resultMatrix, matrix, temp);
            for (int i = 0; i < N; ++i) {
                for (int j = 0; j < N; ++j) {
                    resultMatrix[i][j] = temp[i][j];
                }
            }
        }

        // Multiplica matrix por sí misma
        multiplyMatrices(matrix, matrix, temp);
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                matrix[i][j] = temp[i][j];
            }
        }

        k /= 2; // Divide k por 2
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
    // Define una matriz de ejemplo
    int A[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int k = 3; // Exponente para la potencia

    int result[N][N]; // Matriz para almacenar el resultado

    // Calcula la potencia de la matriz A elevada a k
    powerMatrix(A, k, result);

    // Imprime la matriz original y la matriz resultante
    printf("Matriz A:\n");
    printMatrix(A);

    printf("\nMatriz A^%d:\n", k);
    printMatrix(result);

    return 0;
}
