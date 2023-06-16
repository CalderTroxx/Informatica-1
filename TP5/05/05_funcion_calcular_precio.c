#include <stdio.h>

float calcular_precio(float precio, float descuento)
{
    return precio - ((precio * descuento) / 100);
}

int main()
{
    printf("El precio final es: %.2f", calcular_precio(15900, 15));
}