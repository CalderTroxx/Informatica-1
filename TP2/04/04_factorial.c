#include <stdio.h>

int main()
{
    int valor = 0;
    int factorial = 1;

    printf("Ingrese el valor del factorial: ");
    scanf("%d", &valor);

    for (int i = 1; i <= valor; i++)
    {
        factorial = factorial * i;
    }
    printf("El factorial de %d es: %d", valor, factorial);
}