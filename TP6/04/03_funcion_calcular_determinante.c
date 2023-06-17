#include <stdio.h>

/*
int calcular_determinante(int matriz[][3])
{
    printf("%d", matriz);
}
*/
int main()
{ /*
     int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

     for (int i = 0; i < 3; i++)
     {
         for (int j = 0; j < 3; i++)
         {
             printf("[%d], ", matriz[i][j]);
         }
     }

     // calcular_determinante(matriz3x3, 2);
     */

    int array[2][2] = {{1, 2}, {3, 4}};

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; i++)
        {
            printf("[%d], ", array[j][i]);
        }
    }
}