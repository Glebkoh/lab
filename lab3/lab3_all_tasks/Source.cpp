#include <stdio.h>
#include <math.h>

void calculateSumOfAnInfiniteSeries(float S_last, float Sprev, float fact, float Sum, float E);
void calculateTheAmount(float S_last, float Sprev, float fact, float Sum, float E, int i);

int main()
{
	float S_last = 0, Sprev = 0, fact = 1, Sum = 0, E = 0;

	calculateSumOfAnInfiniteSeries(S_last, Sprev, fact, Sum, E);
}

void calculateSumOfAnInfiniteSeries(float S_last, float Sprev, float fact, float Sum, float E)
{
	printf("First task\n");
	int i = 1;
	S_last = 1 / fact;
	Sum = Sum + S_last;
	printf(" Calculation accuracy : \n  E = ");
	scanf_s("%f", &E);
	printf("\n");
	if (E > 1 && E < 0)
	{
		printf("Incorrect accuracy");
	}
	else
	{
		while (fabsf(S_last - Sprev) > E)
		{
			calculateTheAmount(S_last, Sprev, fact, Sum, E, i);
		}
		printf(" Sum of factorials : \n  Sum = ");
		printf("%f", Sum);
	}
}

void calculateTheAmount(float S_last, float Sprev, float fact, float Sum, float E, int i)
{
	i = 0;
	while (fabsf(S_last - Sprev) > E)
	{
		Sprev = S_last;
		i++;
		fact *= i;
		S_last = 1 / fact;
		Sum = Sum + S_last;
	}
}



