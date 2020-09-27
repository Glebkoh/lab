
#include <math.h>

#define _CRT_SECURE_NO_WARNING

void functionWhile(float x, float y, float i, float step);
void functionFor(float x, float y, float i, float step);
void functionDoWhile(float x, float y, float i, float step);
void function(float x);

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

	functionDoWhile(x, y, i, step);

	functionFor(x, y, i, step);

	functionWhile(x, y, i, step);

}

void functionDoWhile(float x, float y, float i, float step)
{

	do
	{

		function(i);
		i = i + step;
	} while (i < y + 0.0001 && step != 0);

}

void functionFor(float x, float y, float i, float step)
{

	if (step != 0)
	{
		for (float i = x; i < y + 0.0001; i = i + step)
		{
			function(i);
		}
	}
	else
	{
		printf("Step = 0 ");
	}
}

void functionWhile(float x, float y, float i, float step)
{

	while (i < y + 0.0001 && step != 0)
	{
		function(i);
		i = i + step;
	}
}

void function(float x)
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