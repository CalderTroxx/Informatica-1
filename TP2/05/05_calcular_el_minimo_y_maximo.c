#include <stdio.h>

int main()
{
    int N;
    float valor;
    float mem;
    float val_max;
    float val_min;

    printf("Ingrese la cantidad de valores que desea ingresar: ");
    scanf("%d", &N);

    float array_valores_ingresados[N - 1];

    for (int i = 0; i < N; i++)
    {
        printf("Ingrese el valor N° %d: ", i + 1);
        scanf("%f", &valor);

        array_valores_ingresados[i] = valor;
    }

    for (int i = 0; i < N; i++)
    {
        if (val_max < array_valores_ingresados[i])
        {
            val_max = array_valores_ingresados[i];
        }
        if (val_min > array_valores_ingresados[i] || i == 0)
        {
            val_min = array_valores_ingresados[i];
        }
    }

    printf("El valor maximo ingresado es: %.2f\n", val_max);
    printf("El valor minimo ingresado es: %.2f", val_min);
}