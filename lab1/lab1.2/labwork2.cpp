#include <stdio.h>

#define _CRT_SECURE_NO_WARNING

void function1DoesThePointLieOnLines(float x, float y);
void function2IsThePointInTheRegion(float x, float y);
void function3PointLiesOnAStraightLine(float x, float y);

float line1(float x);
float line2(float x);
float line3(float x);

int main()
{
	float x, y;
	scanf_s("%f%f", &x, &y);

	function1DoesThePointLieOnLines(x, y);
	function2IsThePointInTheRegion(y, x);
	function3PointLiesOnAStraightLine(x, y);
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

	void function2IsThePointInTheRegion(float x, float y)
	{
		if (y < line1(x) && y > line3(x) && y > line2(x))
			printf(" region 1");
		else if (y < line2(x) && y > line3(x))
			printf(" region 2");
		else if (y < line1(x) && y < line2(x) && y < line3(x))
			printf(" region 3");
		else if (y < line2(x) && y > line1(x))
			printf("region 4");
		else if (y > line1(x) && y > line2(x) && y < line3(x))
			printf("region 5");
		else if (y > 2 && y > line1(x) && y > line3(x))
			printf("region 6");
		else if (y > line2(x) && y < line1(x) && y < line3(x))
			printf("region 7");
	}

	void function3PointLiesOnAStraightLine(float x, float y)
	{
		if (y == line1(x))
			printf(" line 1");
		else if (y == line2(x))
			printf(" line 2");
		else if (y == line3(x))
			printf(" line 3");
	}

	float line1(float x)
	{
		float y1 = 2 * x + 2;
		return y1;
	}

	float line2(float x)
	{
		float y2 = 1 / 2 * x - 1;
		return y2;
	}

	float line3(float x)
	{
		float y3 = 1 / 2 * x - 1;
		return y3;
	}
