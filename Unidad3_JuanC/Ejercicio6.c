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

// funcion para calcular la transpuesta de una matriz
void calcularTranspuesta(int filas, int columnas, float matriz[filas][columnas], float transpuesta[columnas][filas]) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            transpuesta[j][i] = matriz[i][j];
        }
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

    // crear la matriz transpuesta
    float transpuesta[columnas][filas];

    // calcular la transpuesta de la matriz
    calcularTranspuesta(filas, columnas, matriz, transpuesta);

    // imprimir la matriz original y la transpuesta
    printf("Matriz Original:\n");
    imprimirMatriz(filas, columnas, matriz);

    printf("Matriz Transpuesta:\n");
    imprimirMatriz(columnas, filas, transpuesta);

    return 0;
}
