#include <stdio.h>
#include <math.h>

#define PI 3.141592

float calcular_esfera(float radio, char eleccion)
{
    if (eleccion == 'a')
    {
        //(a)-Cálculo de la longitud de la circunferencia
        return 2 * PI * radio;
        // printf("La longitud de la circunferencia es: %.2f", circunferencia);
    }
    else if (eleccion == 'b')
    {
        //(b)-Cálculo del área del círculo
        return PI * pow(radio, 2);
        // printf("El valor del area es: %.2f", area);
    }
    else if (eleccion == 'c')
    {
        //(c)-Cálculo del volumen de la esfera
        return 1.33333333 * PI * pow(radio, 3);
        // printf("El valor del volumen es: %.2f", volumen);
    }
    else
    {
        // Te equivocaste
        return 0;
    }
}

int main()
{
    float radio, circunferencia, area, volumen;
    char eleccion;

    printf("Ingrese el valor del radio: ");
    scanf("%f", &radio);

    printf("Ingrese: (a)-Cálculo de la longitud de la circunferencia, (b)-Cálculo del área del círculo y (c)-Cálculo del volumen de la esfera: ");
    scanf(" %c", &eleccion);

    if (calcular_esfera(radio, eleccion))
        printf("El resultado de su calculo es: %f", calcular_esfera(radio, eleccion));
}