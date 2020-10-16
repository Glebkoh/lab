#include <stdio.h>
#include <math.h>

#define _CRT_SECURE_NO_WARNING

void functionWhile(float x, float y, float i, float step);
void functionFor(float x, float y, float i, float step);
void functionDoWhile(float x, float y, float i, float step);

void printTitleTable();
void printMainTable(float x);
void printTailTable();

float function(float x);

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
		printTitleTable();
		printMainTable(i);
		printTailTable();
		i = i + step;
	} while (i < y + 0.0001 && step != 0);
}
void functionFor(float x, float y, float i, float step)
{
	if (step != 0)
	{
		for (float i = x; i < y + 0.0001; i = i + step)
		{
			printTitleTable();
			printMainTable(i);
			printTailTable();
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
		printTitleTable();
		printMainTable(i);
		printTailTable();
		i = i + step;
	}

}

float function(float x)
{
	float F = (sinf(x) * sinf(x)) / x;
	return F;
}

void printTitleTable()
{
	printf("+------------+------------+\n");
	printf("|     X      |      Y     |\n");
}
void printMainTable(float x)
{
	printf("+------------+------------+\n");
	printf("|  %6.3f    |  %6.3f    |\n", x, function(x));
}
void printTailTable()
{
	printf("---------------------------\n");
}

