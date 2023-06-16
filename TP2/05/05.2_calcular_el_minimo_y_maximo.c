#include <stdio.h>

int main()
{
    int N;
    float valor;
    float val_max = 0; // Inicializar con valor muy pequeño
    float val_min = 0; // Inicializar con valor muy grande

    printf("Ingrese la cantidad de valores que desea ingresar: ");
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el valor N° %d: ", i + 1);
        scanf("%f", &valor);

        if (val_max < valor)
        {
            val_max = valor;
        }
        if (val_min > valor)
        {
            val_min = valor;
        }
    }

    printf("El valor maximo ingresado es: %.2f\n", val_max);
    printf("El valor minimo ingresado es: %.2f", val_min);
}