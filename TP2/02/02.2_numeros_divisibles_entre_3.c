#include <stdio.h>

int main()
{
    int valor = 0;
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Ingrese el numero N° %d: ", i + 1);
        scanf("%d", &valor);

        if (valor % 3 == 0)
        {
            printf("%d Es divisible entre 3\n", valor);
            count++;
        }
    }
    if (count == 0)
    {
        printf("No se ingresaron numeros divisibles entre 3.\n");
    }
}