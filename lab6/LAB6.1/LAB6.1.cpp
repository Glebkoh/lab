#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int** allocatingMemoryRow(int** a, int column, int row);
int* allocatingMemoryRowColumn(int** a, int column, int row, int i);

void freeAllocatingMemory(int** a);
void freeAllocatingMemoryColumn(int** a, int column, int row);
void enterArraySize(int** a, int column, int row);
void writeFirstMatrix(int** a, int column, int row);
void writeSecondMatrix(int** a, int column, int row);

int main()
{
	int** a = 0, column, row, i = 0;
	printf(" Enter the row \n row = ");
	scanf_s("%d", &row);
	printf(" Enter the column \n column = ");
	scanf_s("%d", &column);

	if (row > 0 && column > 0)
	{
		a = allocatingMemoryRow(a, column, row);

		printf(" Elements Array : \n");
		enterArraySize(a, column, row);

		printf("First Matrix:\n");
		writeFirstMatrix(a, column, row);



		printf("\nSecond Matrix:\n");
		writeSecondMatrix(a, column, row);

		freeAllocatingMemoryColumn(a, column, row);
		freeAllocatingMemory(a);
	}
	else printf("\n Print normal size Matrix , where column > 0 and row > 0");
}

void enterArraySize(int** a, int column, int row)
{
	for (int i = 0; i < row; i++)
	{
		a[i] = allocatingMemoryRowColumn(a, column, row, i);
		for (int j = 0; j < column; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}



void writeFirstMatrix(int** a, int column, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		printf("%d ", a[i][j]);
		printf("\n");
	}
}


void writeSecondMatrix(int** a, int column, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (row - 1 - j > -1 && column - 1 - i > -1)
			{
				int controRow = fmin(row, column);
				int controColumn = controRow;
				printf("%d ", a[controRow - 1 - j][controColumn - 1 - i]);
			}
			else printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}


int** allocatingMemoryRow(int** a, int column, int row)
{
	a = (int**)malloc(row * sizeof(int*));
	return a;
}

void freeAllocatingMemory(int** a)
{
free(a);
}

int* allocatingMemoryRowColumn(int** a, int column, int row, int i)
{
	a[i] = (int*)malloc(column * sizeof(int));
	return a[i];
}

void freeAllocatingMemoryColumn(int** a, int column, int row)
{
	for (int i = 0; i < row; i++)
		free(a[i]);
}

