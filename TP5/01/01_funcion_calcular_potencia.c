#include <stdio.h>

float calcular_potencia()
{
    float base = 0.0;
    int exp = 0;

    printf("Ingrese la base: ");
    scanf("%f", &base);
    printf("Ingrese el exponente: ");
    scanf("%d", &exp);

    float potencia = 1.0;
    for (int i = 0; i < exp; i++)
    {
        potencia = potencia * base;
    }
    printf("El valor de %.2f, elevado al exponente %d es de: %.2f", base, exp, potencia);
}

int main()
{
    calcular_potencia();
}
