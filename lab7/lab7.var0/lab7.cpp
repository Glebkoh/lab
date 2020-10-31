#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int** a, int row, int column);

void printElementsMatrix(int** a, int row, int column);
void printMatrix(int** a, int row, int column);
void changeMatrix(int** a, int row, int column);
void freeMatrix(int** a, int row, int column);

int main()
{
	int** a = 0, row, column, i = 0;
	printf(" Enter row in Matrix : \n  row = ");
	scanf_s("%d", &row);
	printf(" Enter column in Matrix : \n  column = ");
	scanf_s("%d", &column);

	if (row > 0 && column > 0)
	{
		a = allocateMatrix(a, row, column);

		printElementsMatrix(a, row, column);

		printf("\n Start Matrix : \n");
		printMatrix(a, row, column);

		printf("\n New Matrix : \n");
		changeMatrix(a, row, column);

		freeMatrix(a, row, column);
	}
	else printf("\n Print normal size Matrix , where column > 0 and row > 0");
}

void printElementsMatrix(int** a, int row, int column)
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

void printMatrix(int** a, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			printf(" %d ", a[i][j]);
		printf("\n");
	}

}

void changeMatrix(int** a, int row, int column)
{

		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < column/2; j++)
			{ 
				if (i % 2 != 0)
				{
					int count = a[i][j];
					a[i][j] = a[i][column - 1 - j];
					a[i][column - 1 - j] = count;
				}
			}
		}
		printMatrix(a, row, column);
}

int** allocateMatrix(int** a, int row, int column)
{
	a = (int**)malloc(row * column * sizeof(int*));
	return a;
}

void freeMatrix(int** a, int row, int column)
{
	for (int i = 0; i < row; i++)
		free(a[i]);
	free(a);
}
