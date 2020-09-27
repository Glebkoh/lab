#include <stdio.h>

#define _CRT_SECURE_NO_WARNING

void function1DoesThePointLieOnLines(float x, float y);
void function2IsThePointInTheRegion(float y1, float y2, float y3, float x, float y);
void function3PointLiesOnAStraightLine(float y1, float y2, float y3, float y);

int main()
{
	float x, y;
	scanf_s("%f%f", &x, &y);

	float y1 = 2 * x + 2;
	float y2 = 1 / 2 * x - 1;
	float y3 = 2 - x;

	function1DoesThePointLieOnLines(x, y);
	function2IsThePointInTheRegion(y1, y2, y3, y, x);
	function3PointLiesOnAStraightLine(y1, y2, y3, y);
}

	void function1DoesThePointLieOnLines(float x, float y)
	{
		if (x == 0 && y == 2)
			printf("The point lies at the intersection of lines 1 and 3");
		else if (x == 4 && y == 0)
			printf("The point lies at the intersection of lines 2 and 3");
		else if (x == -4 && y == -2)
			printf("The point lies at the intersection of lines 1 and 2");

	}

	void function2IsThePointInTheRegion(float y1, float y2, float y3, float x, float y)
	{
		if (y < y1 && y > y3 && y > y2)
			printf(" region 1");
		else if (y < y2 && y > y3)
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
	}
	void function3PointLiesOnAStraightLine(float y1, float y2, float y3, float y)
	{
		if (y == y1)
			printf(" line 1");
		else if (y == y2)
			printf(" line 2");
		else if (y == y3)
			printf(" line 3");
		getchar();
		getchar();
	}