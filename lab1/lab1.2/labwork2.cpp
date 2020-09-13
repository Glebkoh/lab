#include <stdio.h>
#define _CRT_SECURE_NO_WARNING

int main()
{
	float x, y;
	scanf_s("%f%f", &x, &y);

	float y1 = 2 * x + 2;
	float y2 = 1 / 2 * x - 1;
	float y3 = 2 - x ;
	if (x == 0 && y == 2)
		printf("The point lies at the intersection of lines 1 and 3");
	else if (x == 4 && y == 0)
		printf("The point lies at the intersection of lines 2 and 3");
	else if (x == -4 && y == -2)
		printf("The point lies at the intersection of lines 1 and 2");
	else if (y < y1 && y > y3 && y > y2)
		printf(" region 1");
	else if ( y < y2 && y > y3)
		printf(" region 2");
	else if (y < y1 && y < y2 && y < y3)
		printf(" region 3");
	else if (y < y2 && y > y1)
		printf("region 4");
	else if (y > y1 && y > y2 && y < y3)
		printf("region 5");
	else if (y > 2 && y > y1 && y > y3)
		printf("region 6");
	else if (y > y2 && y < y1 && y < y3)
		printf("region 7");
	else if (y == y1)
		printf("1");
	else if (y == y2)
		printf("2");
	else if (y == y3)
		printf("3");
	return 0;
}