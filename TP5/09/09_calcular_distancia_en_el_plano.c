#include <stdio.h>

int calcular_distancia(int origen, int destino)
{
    return destino - origen;
}

int main()
{
    int x_origen, y_origen, z_origen, x_destino, y_destino, z_destino;

    printf("Ingrese la cordenada 'X' de ORIGEN: ");
    scanf("%d", &x_origen);

    printf("Ingrese la cordenada 'Y' de ORIGEN: ");
    scanf("%d", &y_origen);

    printf("Ingrese la cordenada 'Z' de ORIGEN: ");
    scanf("%d", &z_origen);

    printf("Ingrese la cordenada 'X' de DESTINO: ");
    scanf("%d", &x_destino);

    printf("Ingrese la cordenada 'Y' de DESTINO: ");
    scanf("%d", &y_destino);

    printf("Ingrese la cordenada 'Z' de DESTINO: ");
    scanf("%d", &z_destino);

    printf("Su coordenada de destino en X es: %d \n", calcular_distancia(x_origen, x_destino));
    printf("Su coordenada de destino en Y es: %d \n", calcular_distancia(y_origen, y_destino));
    printf("Su coordenada de destino en Z es: %d \n", calcular_distancia(z_origen, z_destino));
}