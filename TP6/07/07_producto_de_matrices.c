#include <stdio.h>

void imprimir_arr(int arr[], int f)
{
    int valor = 0;
    int count = 0;
    int nueva_matriz[3][3];

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < f; j++)
        {
            nueva_matriz[i][j] = arr[count];
            count++;
        }
    }

    for (int i = 0; i < f; i++)
    {
        for (int j = 0; j < f; j++)
        {
            valor = nueva_matriz[i][j];
            printf("[%d] ", valor);
        }
        printf("\n");
    }
    printf("\n");
}

int calcular_producto(int matriz_A[], int fila_A, int columna_A, int matriz_B[], int fila_B, int columna_B)
{
    int count = 0;
    int nueva_matriz_A[3][3];
    int nueva_matriz_B[3][3];
    int matriz_producto[3][3];
    int producto = 0;
    int puntero = 0;
    int puntero_2 = 0;

    for (int i = 0; i < fila_A; i++)
    {
        for (int j = 0; j < columna_A; j++)
        {
            nueva_matriz_A[i][j] = matriz_A[count];
            count++;
        }
    }
    count = 0;
    imprimir_arr(*nueva_matriz_A, 3);

    for (int i = 0; i < fila_B; i++)
    {
        for (int j = 0; j < columna_B; j++)
        {
            nueva_matriz_B[i][j] = matriz_B[count];
            count++;
        }
    }
    count = 0;
    imprimir_arr(*nueva_matriz_B, 3);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                producto += nueva_matriz_A[puntero_2][k] * nueva_matriz_B[k][puntero];
                printf("%d * %d + ", nueva_matriz_A[puntero_2][k], nueva_matriz_B[k][puntero]);
            }
            printf(" = %d \n", producto);
            matriz_producto[i][j] = producto;
            puntero++;
            producto = 0;
        }
        printf("- - -\n");
        puntero = 0;
        puntero_2++;
    }

    // matriz_producto[0][0] = nueva_matriz_A[0][0] * nueva_matriz_B[0][0] + nueva_matriz_A[0][1] * nueva_matriz_B[1][0] + nueva_matriz_A[0][2] * nueva_matriz_B[2][0];

    imprimir_arr(*matriz_producto, 3);
}

int main()
{
    int matriz_A[3][3] = {{6, 9, 4}, {8, 6, 1}, {9, 2, 8}};

    int matriz_B[3][3] = {{7, 2, 9}, {5, 4, 2}, {8, 1, 3}};

    calcular_producto(*matriz_A, 3, 3, *matriz_B, 3, 3);
}