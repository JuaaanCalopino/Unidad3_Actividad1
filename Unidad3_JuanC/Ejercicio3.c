#include <stdio.h>

// Función para imprimir elementos impares de una matriz
void imprimirElementosImpares(int matriz[][4], int filas, int columnas) {
    // Imprime un mensaje inicial
    printf("Elementos impares de la matriz:\n");

    // Bucle externo para recorrer las filas de la matriz
    for (int i = 0; i < filas; i++) {
        // Bucle interno para recorrer las columnas de la matriz
        for (int j = 0; j < columnas; j++) {
            // Verifica si el elemento en la posición [i][j] es impar
            if (matriz[i][j] % 2 != 0) {
                // Imprime el elemento impar encontrado
                printf("%d ", matriz[i][j]);
            }
        }
    }

    // Imprime un salto de línea al final para una mejor presentación
    printf("\n");
}

// Función principal del programa
int main() {
    // Definición e inicialización de una matriz 4x4 con valores del 1 al 16
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    // Definición de variables para el número de filas y columnas
    int filas = 4;
    int columnas = 4;

    // Llamada a la función para imprimir elementos impares de la matriz
    imprimirElementosImpares(matriz, filas, columnas);

    // Retorna 0 para indicar que el programa se ejecutó correctamente
    return 0;
}
