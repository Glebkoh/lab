#include <stdio.h>
#include <stdlib.h>

int** allocateMatrix(int** a, int row, int column);

void enterArrayElements(int** a, int row, int column);
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

		enterArrayElements(a, row, column);

		printf("\n Start Matrix : \n");
		printMatrix(a, row, column);

		printf("\n New Matrix : \n");
		changeMatrix(a, row, column);

		freeMatrix(a, row, column);
	}
	else printf("\n Print normal size Matrix , where column > 0 and row > 0");
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

void  enterArrayElements(int** a, int row, int column)
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

void changeMatrix(int** a, int row, int column)
{
	for (int k = 0; k < row; k++)
		for (int l = 0; l < column; l++)
			for (int i = 0; i < row; ++i)
				for (int j = 0; j < column; ++j)
				{
					if (j != column - 1)
					{
						if (a[i][j + 1] < a[i][j])
						{
							int tmp = a[i][j + 1];
							a[i][j + 1] = a[i][j];
							a[i][j] = tmp;
						}
					}
					else if (i != row - 1)
					{
						if (a[i + 1][0] < a[i][j])
						{
							int tmp = a[i + 1][0];
							a[i + 1][0] = a[i][j];
							a[i][j] = tmp;
						}
					}
				}
		printMatrix(a, row, column);
}

int** allocateMatrix(int** a, int row, int column)
{	
	a = (int**)malloc(row * sizeof(int*));
	return a;
}

void freeMatrix(int** a, int row, int column)
{
	for (int i = 0; i < row; i++)
		free(a[i]);
	free(a);
}
