#include <stdio.h>
#define _CRT_SECURE_NO_WARNING
#include <math.h>
void Funcion(float x);
int main()
{
	float x, y;
	int N; // ���������� �����
	printf("Give me interval:\n");
	scanf_s("%f%f", &x, &y);
	printf("Give me number N:\n");
	scanf_s("%d", &N);
	float step = (y - x) / N;
	float i = x;
	while (i < y + 0.0001 && step != 0)
	{
		Funcion(i);
		i = i + step;
	}
	return 0;
}
void Funcion(float x)
{
	float F;
	printf("+------------+------------+\n");
	printf("|");
	if (x != 0)
	{
		F = (sinf(x) * sinf(x)) / x;
		printf(" X = %6.3f ", x);
		printf("|");
		printf(" Y = %6.3f ", F);
		printf("|\n");
	}
	else
	{
		printf(" X = %6.3f ", x);
		printf("|");
		printf(" None       ");
		printf("|\n");
	}
	printf("+------------+------------+\n");
}