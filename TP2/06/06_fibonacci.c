#include <stdio.h>

int main()
{
    int N = 0;
    int a1 = 1;
    int a2 = 1;
    int mem = 0;

    printf("Ingrese el valor N que desea obtener de la sucesion de fibonacci: ");
    scanf("%d", &N);

    for (int i = 2; i < N; i++)
    {
        mem = a1 + a2;
        a1 = a2;
        a2 = mem;
    }

    printf("El valor de la sucesion para el lugar ingresado es: %d", mem);
}