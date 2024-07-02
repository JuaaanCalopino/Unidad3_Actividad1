#include <stdio.h>
#include <stdlib.h>

#define N 3  // define la dimension de la matriz cuadrada

// funcion para imprimir una matriz
void imprimirMatriz(float matriz[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%.2f\t", matriz[i][j]);
        }
        printf("\n");
    }
}

// funcion para intercambiar dos filas de una matriz
void intercambiarFilas(float matriz[N][N], int fila1, int fila2) {
    for (int i = 0; i < N; i++) {
        float temp = matriz[fila1][i];
        matriz[fila1][i] = matriz[fila2][i];
        matriz[fila2][i] = temp;
    }
}

// funcion para calcular la inversa de una matriz
int calcularInversa(float matriz[N][N], float inversa[N][N]) {
    // inicializa la matriz inversa como una matriz identidad
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            inversa[i][j] = (i == j) ? 1.0 : 0.0;
        }
    }

    // realiza el algoritmo de Gauss-Jordan
    for (int i = 0; i < N; i++) {
        // encuentra el maximo elemento en la columna actual
        float max = matriz[i][i];
        int filaMax = i;
        for (int k = i + 1; k < N; k++) {
            if (matriz[k][i] > max) {
                max = matriz[k][i];
                filaMax = k;
            }
        }

        // intercambia las filas para poner el maximo elemento en la posicion diagonal
        if (i != filaMax) {
            intercambiarFilas(matriz, i, filaMax);
            intercambiarFilas(inversa, i, filaMax);
        }

        // si el elemento diagonal es cero, la matriz no es invertible
        if (matriz[i][i] == 0) {
            return 0;
        }

        // divide la fila por el elemento diagonal para hacer el elemento diagonal igual a 1
        float divisor = matriz[i][i];
        for (int j = 0; j < N; j++) {
            matriz[i][j] /= divisor;
            inversa[i][j] /= divisor;
        }

        // hace que todos los elementos en la columna actual (excepto el diagonal) sean cero
        for (int k = 0; k < N; k++) {
            if (k != i) {
                float factor = matriz[k][i];
                for (int j = 0; j < N; j++) {
                    matriz[k][j] -= factor * matriz[i][j];
                    inversa[k][j] -= factor * inversa[i][j];
                }
            }
        }
    }

    return 1;  // la matriz es invertible
}

int main() {
    float matriz[N][N] = {
        {2, -1, 0},
        {1, 2, -1},
        {3, 1, 2}
    };

    float inversa[N][N];

    printf("Matriz Original:\n");
    imprimirMatriz(matriz);

    if (calcularInversa(matriz, inversa)) {
        printf("Matriz Inversa:\n");
        imprimirMatriz(inversa);
    } else {
        printf("La matriz no es invertible.\n");
    }

    return 0;
}
