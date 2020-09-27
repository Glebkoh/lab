#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS

int checkPointPosition(float x, float y);

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
	int result;
	if (y - 1 / 2 * x - 1 == 0)
		result = 0;
	else if (y - 1 / 2 * x - 1 > 0)
		result = 1;
	else if (y - 1 / 2 * x - 1 < 0)
		result = -1;
	return result;
}