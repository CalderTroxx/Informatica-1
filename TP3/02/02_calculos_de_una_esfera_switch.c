#include <stdio.h>
#include <math.h>

#define PI 3.141592

int main()
{
    float radio, circunferencia, area, volumen;
    char eleccion;

    printf("Ingrese el valor del radio: ");
    scanf("%f", &radio);

    printf("Ingrese: (a)-Cálculo de la longitud de la circunferencia, (b)-Cálculo del área del círculo y (c)-Cálculo del volumen de la esfera: ");
    scanf(" %c", &eleccion);

    switch (eleccion)
    {
    case 'a':
        //(a)-Cálculo de la longitud de la circunferencia
        circunferencia = 2 * PI * radio;
        printf("La longitud de la circunferencia es: %.2f", circunferencia);
        break;
    case 'b':
        //(b)-Cálculo del área del círculo
        area = PI * pow(radio, 2);
        printf("El valor del area es: %.2f", area);
        break;
    case 'c':
        //(c)-Cálculo del volumen de la esfera
        volumen = 1.33333333 * PI * pow(radio, 3);
        printf("El valor del volumen es: %.2f", volumen);
        break;
    default:
        // Te equivocaste
        printf("La opcion ingresada no es valida.");
        break;
    }
}