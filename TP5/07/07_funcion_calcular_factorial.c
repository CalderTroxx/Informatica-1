#include <stdio.h>

int calcular_factorial(int valor)
{
    int factorial = 1;
    for (int i = 1; i <= valor; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}

int main()
{
    int valor = 0;

    printf("Ingrese el valor del factorial: ");
    scanf("%d", &valor);

    printf("El factorial de %d es: %d", valor, calcular_factorial(valor));
}
