#include <stdio.h>

// Funcion para imprimir elementos pares de una matriz
void imprimirElementosPares(int matriz[][4], int filas, int columnas) {
    // Imprime un mensaje inicial
    printf("Elementos pares de la matriz:\n");

    // Bucle externo para recorrer las filas de la matriz
    for (int i = 0; i < filas; i++) {
        // Bucle interno para recorrer las columnas de la matriz
        for (int j = 0; j < columnas; j++) {
            // Verifica si el elemento en la posicion [i][j] es par
            if (matriz[i][j] % 2 == 0) {
                // Imprime el elemento par encontrado
                printf("%d ", matriz[i][j]);
            }
        }
    }

    // Imprime un salto de linea al final para una mejor presentacion
    printf("\n");
}

// Funcion principal del programa
int main() {
    // Definicion e inicializacion de una matriz 4x4 con valores del 1 al 16
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Definicion de variables para el numero de filas y columnas
    int filas = 4;
    int columnas = 4;

    // Llamada a la funcion para imprimir elementos pares de la matriz
    imprimirElementosPares(matriz, filas, columnas);

    // Retorna 0 para indicar que el programa se ejecuto correctamente
    return 0;
}
