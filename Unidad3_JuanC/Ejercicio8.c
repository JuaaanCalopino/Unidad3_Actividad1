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

int main() {
    int filas, columnas;

    // pedir al usuario las dimensiones de la matriz
    printf("Ingrese el numero de filas: ");
    scanf("%d", &filas);
    printf("Ingrese el numero de columnas: ");
    scanf("%d", &columnas);

    // crear la matriz
    float matriz[filas][columnas];

    // pedir al usuario que ingrese los elementos de la matriz
    printf("Ingrese los elementos de la matriz (%d x %d):\n", filas, columnas);
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            scanf("%f", &matriz[i][j]);
        }
    }

    // imprimir la matriz
    printf("Matriz ingresada:\n");
    imprimirMatriz(filas, columnas, matriz);

    // imprimir el numero de filas y columnas
    printf("La matriz tiene %d filas y %d columnas.\n", filas, columnas);

    return 0;
}
