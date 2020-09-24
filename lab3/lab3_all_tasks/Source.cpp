#include <stdio.h>
#include <math.h>
void FUN1(float S_last, float Sprev, float fact, float Sum, float E);
void second(float S_past, float S_prev, float a, float b, float e, float h, float x_0, float N, float x_i, float x_1, float S_sum);
int main()
{
	float S_past = 0, S_prev = 0, a = 0, b = 0, e = 0, h = 0, x_0 = 0, N = 0, x_1 = 0, x_i = 0, S_sum = 0; 
	float S_last = 0, Sprev = 0, fact = 1, Sum = 0, E = 0; 
	FUN1(S_last, Sprev, fact, Sum, E);
	second(S_past, S_prev, a, b, e, h, x_0, N, x_i, x_1, S_sum);
}

void FUN1(float S_last, float Sprev, float fact, float Sum, float E)
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
			Sprev = S_last;
			i++;
			fact *= i;
			S_last = 1 / fact;
			Sum = Sum + S_last;
		}
		printf(" Sum of factorials : \n  Sum = ");
		printf("%f", Sum);
	}
}

void second(float S_past, float S_prev, float a, float b, float e, float h, float x_0, float N, float x_i, float x_1, float S_sum)
{
	printf("\n-------------------------------------------------");
	printf("\nSecond task\n");
	printf(" Calculation accuracy : \n  e = ");
	scanf_s("%f", &e);
	printf("  N = ");
	scanf_s("%f", &N);
	printf(" Integration limits\n");
	printf("  a = ");
	scanf_s("%f", &a); 
	printf("  b = ");
	scanf_s("%f", &b);
	h = (b - a) / N;
	x_0 = a;
	x_1 = a * h;
	S_past = h * log((x_0 + x_1) / 2);
	while ((S_past - S_prev) > e)
	{
		S_prev = S_past;
		N *= 2;
		S_prev = S_past;
		S_sum = S_sum + S_past;
		h = (b - a) / N;
		x_1 = a * h;
		x_i = a * ((b - a) / (2 * N));
		S_past = h * log((x_1 + x_i) / 2);
	}
	printf("  S_sum = ");
	printf("%f", S_sum);
}




