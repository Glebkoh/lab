#include <stdio.h>
#define _CRT_SECURE_NO_WARNING
#include <math.h>
void Function_while(float x, float y, float i, float step);
void Function_for(float x, float y, float i, float step);
void Function_do_while(float x, float y, float i, float step);
void Function(float x);
int main()
{
	float x, y;
	int N;
	printf("Give me interval:\n");
	scanf_s("%f%f", &x, &y);
	printf("Give me number N:\n");
	scanf_s("%d", &N);
	float step = (y - x) / N;
	float i = x;
	Function_do_while(x, y, i, step);
	Function_for(x, y, i, step);
	Function_while(x, y, i, step);
}
void Function_do_while(float x, float y, float i, float step)
{
	do
	{
		Function(i);
		i = i + step;
	} while (i < y + 0.0001 && step != 0);
}
void Function_for(float x, float y, float i, float step)
{
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
}
void Function_while(float x, float y, float i, float step)
{
	while (i < y + 0.0001 && step != 0)
	{
		Function(i);
		i = i + step;
	}
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
		printf(" None ");
		printf("|\n");
	}
	printf("+------------+------------+\n");

}