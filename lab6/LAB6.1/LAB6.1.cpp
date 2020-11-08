#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** allocateMatrix(int** a, int column, int row, int i);

void freeMatrix(int** a, int row);
void enterArrayElements(int** a, int column, int row);
void printMatrix(int** a, int column, int row);
void changeMatrix(int** a, int column, int row);
void swapElementsMatrix(int** a, int i, int j, int row, int column);

int main()
{
	int** a = 0, column, row, i = 0, j = 0;
	printf(" Enter the row \n row = ");
	scanf_s("%d", &row);
	printf(" Enter the column \n column = ");
	scanf_s("%d", &column);

	if (row > 0 && column > 0)
	{
		a = allocateMatrix(a, column, row, i);

		printf(" Elements Array : \n");
		enterArrayElements(a, column, row);

		printf("Stareted Matrix:\n");
		printMatrix(a, column, row);

		printf("\nNew Matrix:\n");
		changeMatrix(a, column, row);

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

void changeMatrix(int** a, int column, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column / 2; j++)
		{
			if (row - 1 - j > -1 && column - 1 - i > -1)
			{
				swapElementsMatrix(a, i, j, row, column);

			}
		}
	}
	printMatrix(a, column, row);

}

void swapElementsMatrix(int** a, int i, int j, int row, int column)
{
	row = fmin(row, column);
	column = row;
	int count = a[i][j];
	a[i][j] = a[row - 1 - j][column - 1 - i];
	a[row - 1 - j][column - 1 - i] = count;
}

int** allocateMatrix(int** a, int column, int row, int i)
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
