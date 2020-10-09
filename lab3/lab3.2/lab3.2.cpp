#include <stdio.h>
#include <math.h>

void calculateIntegral(float S_past, float S_prev, float a, float b, float e, float h, float x_0, float N, float x_i, float x_1, float S_sum);
void searchTheIntegral(float S_past, float S_prev, float a, float b, float e, float h, float x_0, float N, float x_i, float x_1, float S_sum);

int main()
{
	float S_past = 0, S_prev = 0, a = 0, b = 0, e = 0, h = 0, x_0 = 0, N = 0, x_1 = 0, x_i = 0, S_sum = 0;

	calculateIntegral(S_past, S_prev, a, b, e, h, x_0, N, x_i, x_1, S_sum);
}

void calculateIntegral(float S_past, float S_prev, float a, float b, float e, float h, float x_0, float N, float x_i, float x_1, float S_sum)
{
	printf(" Calculation accuracy : \n e = ");
	scanf_s("%f", &e);
	printf(" N = ");
	scanf_s("%f", &N);
	printf(" Integration limits\n");
	printf(" a = ");
	scanf_s("%f", &a);
	printf(" b = ");
	scanf_s("%f", &b);
	h = (b - a) / N;
	x_0 = a;
	x_1 = a * h;
	S_past = h * log((x_0 + x_1) / 2);
	while ((S_past - S_prev) > e)
	{
		searchTheIntegral(S_past, S_prev, a, b, e, h, x_0, N, x_i, x_1, S_sum);
	}
	printf(" S_sum = ");
	printf("%f", S_sum);
}

void searchTheIntegral(float S_past, float S_prev, float a, float b, float e, float h, float x_0, float N, float x_i, float x_1, float S_sum)
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
