#include <stdio.h>
#include <string.h>

int main()
{
    char cadena[20];
    int count;

    printf("Ingrese la cadena: ");
    scanf("%s", cadena);

    for (int i = 0; i < strlen(cadena); i++)
    {
        if (cadena[i] == 'a' || cadena[i] == 'e' || cadena[i] == 'i' || cadena[i] == 'o' || cadena[i] == 'u')
        {
            count++;
        }
    }
    printf("Su cadena %s tiene %d vocales ", cadena, count);
}