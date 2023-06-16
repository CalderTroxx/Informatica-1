#include <stdio.h>

float calcular_resistencia_equivalente(float R1, float R2, float R3)
{
    return 1 / ((1 / R1) + (1 / R2) + (1 / R3));
}

int main()
{
    unsigned int R1, R2, R3;

    printf("Ingresa el valor para R1: ");
    scanf("%d", &R1);
    printf("Ingresa el valor para R2: ");
    scanf("%d", &R2);
    printf("Ingresa el valor para R3: ");
    scanf("%d", &R3);

    printf("El valor de resistencia equivalente es: %.2f", calcular_resistencia_equivalente(R1, R2, R3));
}