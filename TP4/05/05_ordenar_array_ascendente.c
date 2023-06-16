#include <stdio.h>

int main()
{
    int array[10];
    int mem = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Ingrese el numero N° %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    printf("Array original: ");

    for (int i = 0; i < 10; i++)
    {
        printf("[%d], ", array[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if (array[j] > array[j + 1])
            {
                mem = array[j + 1];
                array[j + 1] = array[j];
                array[j] = mem;
            }
        }
    }

    printf("Array ordenado: ");

    for (int i = 0; i < 10; i++)
    {
        printf("[%d], ", array[i]);
    }
}