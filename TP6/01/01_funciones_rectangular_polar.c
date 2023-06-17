#include <stdio.h>
#include <math.h>

#define PI 3.141592

float conversion_a_polar(int x, int y)
{
	float amplitud_polar = sqrt(pow(x, 2) + pow(y, 2));
	float fase_polar = atan(y / x) * (180 / PI);

	printf("La expresion polar es la siguiente: %.2f, %.2f� \n", amplitud_polar, fase_polar);
}

float conversion_a_rectangular(int amplitud_polar, int fase_polar)
{
	float x = amplitud_polar * (cos(fase_polar * PI / 180));
	float y = amplitud_polar * (sin(fase_polar * PI / 180));

	printf("La expresion rectangular es la siguiente: %.2f, j%.2f \n", x, y);
}

int main()
{
	conversion_a_polar(16, 51);
	conversion_a_rectangular(12, 50);
}
