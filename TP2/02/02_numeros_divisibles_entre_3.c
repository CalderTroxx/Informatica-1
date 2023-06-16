#include <stdio.h>

int main()
{
    int valor = 0;
    int numeros_divisibles_entre_3[10];
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        printf("Ingrese el numero N° %d: ", i + 1);
        scanf("%d", &valor);

        if (valor % 3 == 0)
        {
            numeros_divisibles_entre_3[count] = valor;
            count++;
        }
    }
    for (int i = 0; i < count; i++)
    {
        printf("%d Es divisible entre 3\n", numeros_divisibles_entre_3[i]);
    }
}