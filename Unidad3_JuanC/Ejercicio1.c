#include <stdio.h>
//VOID NOO ESPERA DEVOLVER ALGUN RESULTADO
void imprimirEsquinas(int matriz[][4], int filas, int columnas) {
    
    int esquinas[2][2]; //para almacenar los valores de las esquinas de la matriz original
   

    // Esquina superior izquierda
    esquinas[0][0] = matriz[0][0];

    // Esquina superior derecha
    esquinas[0][1] = matriz[0][3];

    // Esquina inferior izquierda
    esquinas[1][0] = matriz[3][0];

    // Esquina inferior derecha
    esquinas[1][1] = matriz[3][3];

    // Imprimir la matriz de esquinas
    printf("Esquinas de la matriz:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            printf("%d ", esquinas[i][j]);
        }
        printf("\n");
    }
}

int main() {
    //declaramos el tamaño de nuestra matriz, en mi caso utilice una 4x4 
    int matriz[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16}
    };

    int filas = 4;
    int columnas = 4;
    //aqui simplemente llamamos a la funcion que realizamos arriba y deberia compilar

    imprimirEsquinas(matriz, filas, columnas);

    return 0;
}
