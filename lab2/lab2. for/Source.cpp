#include <stdio.h>
#define _CRT_SECURE_NO_WARNING
#include <math.h>
void Function(float x);
int main()
{
	float x, y;
	int N; // количество шагов
	printf("Give me interval:\n");
	scanf_s("%f%f", &x, &y);
	printf("Give me number N:\n");
	scanf_s("%d", &N);
	float step = (y - x) / N;
	if (step != 0)
	{
		for (float i = x; i < y + 0.0001; i = i + step)
		{
			Function(i);
		}
	}
	else
	{
		printf("Step = 0 ");
	}
	return 0;
}
void Function(float x)
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