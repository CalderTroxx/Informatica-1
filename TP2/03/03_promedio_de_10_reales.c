#include <stdio.h>

int main()
{
    float valor, suma, promedio;
    for (int i = 0; i < 10; i++)
    {
        printf("Ingrese el numero N° %d: ", i + 1);
        scanf("%f", &valor);

        suma = suma + valor;
    }
    promedio = suma / 10;
    printf("El promedio de los valores ingresados es: %.2f", promedio);
}