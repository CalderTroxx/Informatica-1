#include <stdio.h>

int main()
{
    float array[10];
    float valor;
    float suma_par, prom_par, suma_impar, prom_impar;

    for (int i = 0; i < 10; i++)
    {
        printf("Ingrese el valor Nº %d: ", i + 1);
        scanf("%f", &valor);

        array[i] = valor;
    }
    for (int i = 0; i < 10; i++)
    {

        if (i % 2 == 0)
        {
            suma_par = suma_par + array[i];
            prom_par = suma_par / i;
        }
        else
        {
            suma_impar = suma_impar + array[i];
            prom_impar = suma_impar / i;
        }
        printf("\nLos valores ingresados fueron: %.2f", array[i]);
    }

    printf("\nLa suma de los valores con indice par es: %.2f", suma_par);
    printf("\nEl promedio de los valores con indice par es: %.2f", prom_par);
    printf("\nLa suma de los valores con indice impar es: %.2f", suma_impar);
    printf("\nEl promedio de los valores con indice impar es: %.2f", prom_impar);
}
