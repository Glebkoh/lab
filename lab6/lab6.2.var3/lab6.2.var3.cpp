#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** allocateMatrix(int** a, int column, int row);

int searchCentralElementMatrix(int** a, int column, int row, int mid);
int calculatedSumTrianglesUp1(int** a, int column, int row, int mid, int sum1);
int calculatedSumTrianglesDown2(int** a, int column, int row, int mid, int sum2);
int calculatedSumTriangles(int sum1, int sum2);

void enterArrayElements(int** a, int column, int row);
void printMatrix(int** a, int column, int row);
void changeMatirx(int** a, int column, int row, int sum);
void freeMatrix(int** a, int row);

int main()
{
	int** a = 0, column, row, i = 0, sum = 0, sum1 = 0, sum2 = 0, mid = 0;
	printf(" Enter the row \n row = ");
	scanf_s("%d", &row);
	printf(" Enter the column \n column = ");
	scanf_s("%d", &column);

	if (row > 0 && column > 0)
	{
		a = allocateMatrix(a, column, row);

		printf(" Elements Array : \n");
		enterArrayElements(a, column, row);

		printf("Stareted Matrix:\n");
		printMatrix(a, column, row);

		mid = searchCentralElementMatrix(a, column, row, mid);

		printf("\n Sum1 = ");
		sum1 = calculatedSumTrianglesUp1(a, column, row, mid, sum1);

		printf("\n Sum2 = ");
		sum2 = calculatedSumTrianglesDown2(a, column, row, mid, sum2);

		printf("\n Sum = Sum1 - Sum2 = ");
		sum = calculatedSumTriangles(sum1, sum2);

		printf("\nNew Matrix:\n");
		changeMatirx(a, column, row, sum);


		freeMatrix(a, row);
	}
	else printf("\n Print normal size Matrix , where column > 0 and row > 0");
}

void enterArrayElements(int** a, int column, int row)
{
	for (int i = 0; i < row; i++)
	{
		a[i] = (int*)malloc(column * sizeof(int));
		for (int j = 0; j < column; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}

void printMatrix(int** a, int column, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
}

int searchCentralElementMatrix(int** a, int column, int row, int mid)
{
	if ((row % 2 != 0) && (column >= 3) && (column % 2 != 0))
	{
		mid = a[row / 2][column / 2];
		printf("\n Mid = %d", mid);
	}
	else printf("\n Matrix not have Central element, row mod 2 != 0, column mod 2 != 0 , column >= 3 \n");
	return mid;
}

int calculatedSumTrianglesUp1(int** a, int column, int row, int mid, int sum1)
{
	sum1 = mid;
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (j + count < column - count && i < row / 2)
				sum1 = sum1 + a[i][j + count];
		}
		count++;
	}
	printf("%d", sum1);
	return sum1;
}

int calculatedSumTrianglesDown2(int** a, int column, int row, int mid, int sum2)
{
	sum2 = mid;
	int count = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (j + count < column - count && i != row / 2 && i < row / 2)
				sum2 = sum2 + a[row - 1 - count][j + count];
		}
		count++;
	}
	printf("%d", sum2);
	return sum2;
}

int calculatedSumTriangles(int sum1, int sum2)
{
	int sum = sum1 - sum2;
	printf("%d", sum);
	return sum;
}

void changeMatirx(int** a, int column, int row, int sum)
{
	a[row / 2][column / 2] = sum;
	printMatrix(a, column, row);
}

int** allocateMatrix(int** a, int column, int row)
{
	a = (int**)malloc(row * column * sizeof(int*));
	return a;
}

void freeMatrix(int** a, int row)
{
	for (int i = 0; i < row; i++)
		free(a[i]);
	free(a);
}

