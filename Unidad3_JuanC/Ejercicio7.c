#include <stdio.h>

// funcion para imprimir una matriz
void imprimirMatriz(int dimension, float matriz[dimension][dimension]) {
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// funcion para generar una matriz simetrica
void generarMatrizSimetrica(int dimension, float matriz[dimension][dimension]) {
    // pedir al usuario que ingrese los elementos de la matriz
    printf("Ingrese los elementos de la matriz (%d x %d):\n", dimension, dimension);
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j <= i; j++) {
            printf("Elemento [%d][%d]: ", i, j);
            scanf("%f", &matriz[i][j]);
            matriz[j][i] = matriz[i][j]; // asegura la simetria
        }
    }
}

int main() {
    int dimension;

    // pedir al usuario la dimension de la matriz cuadrada
    printf("Ingrese la dimension de la matriz cuadrada: ");
    scanf("%d", &dimension);

    // crear la matriz
    float matriz[dimension][dimension];

    // generar la matriz simetrica
    generarMatrizSimetrica(dimension, matriz);

    // imprimir la matriz simetrica
    printf("Matriz Simetrica:\n");
    imprimirMatriz(dimension, matriz);

    return 0;
}
