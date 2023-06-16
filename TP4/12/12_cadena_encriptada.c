#include <stdio.h>
#include <string.h>

int main()
{
    char cadena[20];
    int count;

    printf("Ingrese la cadena: ");
    scanf("%s", cadena);

    printf("Su cadena es: %s", cadena);

    char cadena_encryptada[strlen(cadena)];

    for (int i = 0; i < strlen(cadena); i++)
    {
        cadena_encryptada[i] = cadena[i] + 3;
    }
    printf("Su cadena encryptada es: %s", cadena_encryptada);
}