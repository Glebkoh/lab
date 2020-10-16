#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int checkPointPosition(float x, float y);

float line(float x);

int main()
{
	float x, y;
	scanf_s("%f%f", &x, &y);
	int location = checkPointPosition(x, y);
	if (location == 0)
		printf("Point on the line");
	else if (location > 0)
		printf("Point above the line");
	else if (location < 0)
		printf("Point under the line");

	
}
int checkPointPosition(float x, float y)
{
	int result = 100;
	if (line(x) == y)
		result = 0;
	else if (line(x) < y)
		result = 1;
	else if (line(x) > y)
		result = -1;
	return result;
}

float line(float x)
{
	float y = x / 2  + 1;
	return y;
}