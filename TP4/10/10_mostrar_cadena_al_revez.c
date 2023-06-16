#include <stdio.h>
#include <string.h>

int main()
{
    char cadena[20];
    char mem;
    int count = 0;

    printf("Ingrese la cadena: ");
    scanf("%s", cadena);

    char cadena_2[strlen(cadena)];
    char cadena_inversa[strlen(cadena)];
    strcpy(cadena_2, cadena);

    printf("Su cadena es: %s \n", cadena_2);

    printf("Su longitud es es: %d \n", strlen(cadena_2));

    for (int i = strlen(cadena_2) - 1; i >= 0; i--)
    {
        cadena_inversa[count] = cadena_2[i];
        count++;
    }
    printf("Su cadena al revez es: %s", cadena_inversa);
}