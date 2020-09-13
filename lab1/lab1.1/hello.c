#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int check(float x, float y);
int main()
{
	float x, y;
	scanf_s("%f%f", &x, &y);
	int location = check(x, y);
	if (location == 0)
		printf("Point on the line");
	else if (location > 0)
		printf("Point above the line");
	else if (location < 0)
		printf("Point under the line");

}
int check(float x, float y)
{
	int i;
	if (y - 1 / 2 * x - 1 == 0)
		i = 0;
	else if (y - 1 / 2 * x - 1 > 0)
		i = 1;
	else if (y - 1 / 2 * x - 1 < 0)
		i = -1;
	return i;
}