#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void enterArraySize(int** a, int row, int column);
void writeFirstMatrix(int** a, int row, int column);
void transportationMatrixElements(int** a, int row, int column);
void writeSecondMatrix(int** a, int row, int column);

int main()
{
	int** a, row, column;
	printf(" Enter the number of items per line \n column = ");
	scanf_s("%d", &column);
	printf(" Enter the number of columns \n row = ");
	scanf_s("%d", &row);

	a = (int**)malloc(column * row * sizeof(int*));

	printf(" Elements Array : \n");
	enterArraySize(a, row, column);

	printf("First Matrix:\n");
	writeFirstMatrix(a, row, column);

	printf(" \nNew Elements Array : ");
	transportationMatrixElements(a, row, column);

	printf("\nSecond Matrix:\n");
	writeSecondMatrix(a, row, column);


	free(a);
}

void enterArraySize(int** a, int row, int column)
{
	if (column != 0)
	{
		for (int i = 0; i < column; i++)
		{
			a[i] = (int*)malloc(row * sizeof(int));
			for (int j = 0; j < row; j++)
			{
				printf("a[%d][%d] = ", i, j);
				scanf_s("%d", &a[i][j]);
			}
		}	
	}
	else printf("Invalid output n");
}

void writeFirstMatrix(int** a, int row, int column)
{
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		printf("%d ", a[i][j]);
		printf("\n");
	}
}

void transportationMatrixElements(int** a, int row, int column)
{
	column = fmin(column, row);
	row = column;
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
		{	
			printf("\na[%d][%d] = ", i, j);
			printf("%d", a[j][i]);
		}
	}
}
void writeSecondMatrix(int** a, int row, int column)
{
	column = fmin(column, row);
	row = column;
	for (int i = 0; i < column; i++)
	{
		for (int j = 0; j < row; j++)
			printf("%d ", a[j][i]);
		printf("\n");
	}
}