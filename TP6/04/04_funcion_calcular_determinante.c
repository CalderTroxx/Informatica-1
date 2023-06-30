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

int calcular_determinante(int matriz[])
{
    int count = 0;
    int nueva_matriz[3][3];

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            nueva_matriz[i][j] = matriz[count];
            count++;
        }
    }
    int determinante = ((nueva_matriz[0][0] * ((nueva_matriz[1][1] * nueva_matriz[2][2]) - (nueva_matriz[1][2] * nueva_matriz[2][1]))) +        // Cofactor 1
                        (nueva_matriz[0][1] * (-1 * ((nueva_matriz[1][0] * nueva_matriz[2][2]) - (nueva_matriz[1][2] * nueva_matriz[2][0])))) + // Cofactor 2
                        (nueva_matriz[0][2] * ((nueva_matriz[1][0] * nueva_matriz[2][1]) - (nueva_matriz[1][1] * nueva_matriz[2][0]))));        // Cofactor 3
    return determinante;
}

int main()
{
    int matriz[3][3] = {{6, 9, 4}, {8, 6, 1}, {9, 2, 8}};

    printf("El determinante de la matriz es: %d\n", calcular_determinante(*matriz));
}