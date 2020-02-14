#include <cstdio>

int main() {

    printf("\n\n\t.: Generador de nueva matriz :.\n\n");

    int filas, columnas;

    printf("No. de Filas: ");
    scanf("%i", &filas);
    printf("No. de Columnas: ");
    scanf("%i", &columnas);

    filas += 2;
    columnas += 2;

    float matriz[filas][columnas];
    float nueva[filas - 2][columnas - 2];

    /** Se llena las matrices con 0s */

    for(int i = 0; i < filas; i++){
        for(int j = 0; j < columnas; j++){
            matriz[i][j] = 0;
        }
    }

    for(int i = 0; i < filas - 2; i++){
        for(int j = 0; j < columnas - 2; j++){
            nueva[i][j] = 0;
        }
    }

    /** Llenado de matriz */

    printf("\n");

    for(int i = 1; i < filas - 1; i++){
        for(int j = 1; j < columnas - 1; j++){
            printf("[%i][%i]: ", i - 1, j - 1);
            scanf("%f", &matriz[i][j]);

            if(i == 1) matriz[filas - 1][j] = matriz[i][j];
            if(i == filas - 2) matriz[0][j] = matriz[i][j];
            if(j == 1) matriz[i][columnas - 1] = matriz[i][j];
            if(j == columnas - 2) matriz[i][0] = matriz[i][j];
        }
    }

    matriz[0][0] = matriz[filas - 2][columnas - 2];
    matriz[filas - 1][0] = matriz[1][columnas - 2];
    matriz[0][columnas - 1] = matriz[filas - 2][1];
    matriz[filas - 1][columnas - 1] = matriz[1][1];

    /** Generador de nueva matriz */

    for(int i = 0; i < filas - 2; i++){
        for(int j = 0; j < columnas - 2; j++){
            for (int k = 0; k < 3; k++){
                for(int l = 0; l < 3; l++){
                    nueva[i][j] += matriz[k + i][l + j];
                }
            }
            nueva[i][j] /= 9;
        }
    }

    /** Se imprime la matriz completa */

    printf("\n\nMatriz:\n\n");

    for(int i = 1; i < filas - 1; i++){
        printf("\t");
        for(int j = 1; j < columnas - 1; j++){
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\nMatriz Completa:\n\n");

    for(int i = 0; i < filas; i++){
        printf("\t");
        for(int j = 0; j < columnas; j++){
            printf("%f ", matriz[i][j]);
        }
        printf("\n");
    }

    printf("\n\nNueva Matriz:\n\n");

    for(int i = 0; i < filas - 2; i++){
        printf("\t");
        for(int j = 0; j < columnas - 2; j++){
            printf("%f ", nueva[i][j]);
        }
        printf("\n");
    }

    printf("\n\n");

    return 0;
}
