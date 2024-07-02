#include <stdio.h>

// funcion para imprimir una matriz
void imprimirMatriz(int filas, int columnas, float matriz[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// funcion para sumar dos matrices
void sumarMatrices(int filas, int columnas, float matriz1[filas][columnas], float matriz2[filas][columnas], float resultado[filas][columnas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            resultado[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
}

int main() {
    int filas, columnas;

    // pedir al usuario las dimensiones de las matrices
    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    // crear las matrices
    float matriz1[filas][columnas];
    float matriz2[filas][columnas];
    float resultado[filas][columnas];

    // pedir al usuario que ingrese los elementos de la primera matriz
    printf("Ingrese los elementos de la primera matriz (%d x %d):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            scanf("%f", &matriz1[i][j]);
        }
    }

    // pedir al usuario que ingrese los elementos de la segunda matriz
    printf("Ingrese los elementos de la segunda matriz (%d x %d):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            scanf("%f", &matriz2[i][j]);
        }
    }

    // sumar las matrices
    sumarMatrices(filas, columnas, matriz1, matriz2, resultado);

    // imprimir las matrices y el resultado
    printf("Primera matriz:\n");
    imprimirMatriz(filas, columnas, matriz1);

    printf("Segunda matriz:\n");
    imprimirMatriz(filas, columnas, matriz2);

    printf("Resultado de la suma:\n");
    imprimirMatriz(filas, columnas, resultado);

    return 0;
}
