#include <stdio.h>

int main()
{
    int notas_alumnos[15];
    int frecuencia[11] = {0};

    for (int i = 0; i < 15; i++)
    {
        printf("Ingrese la nota del alumno N° %d: ", i + 1);
        scanf("%d", &notas_alumnos[i]);

        frecuencia[notas_alumnos[i]]++;
    }

    for (int i = 0; i <= 10; i++)
    {
        printf("La frecuencia de la nota %d es de %d \n. ", i, frecuencia[i]);
    }
}