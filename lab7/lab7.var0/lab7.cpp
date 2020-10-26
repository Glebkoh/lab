#include <stdio.h>
#include <stdlib.h>

int** mallocRowMemory(int** a, int row, int column);
int* mallocCloumnMemory(int** a, int column, int i, int row);

void elementsMatrix(int** a, int row, int column);
void firstMatrix(int** a, int row, int column);
void secondMatrix(int** a, int row, int column);
void freeMallocRowMemory(int** a, int row, int column);
void freeMallocColumnMemory(int** a, int i, int row);


int main()
{
	int** a = 0, row, column, i = 0;
	printf(" Enter row in Matrix : \n  row = ");
	scanf_s("%d", &row);
	printf(" Enter column in Matrix : \n  column = ");
	scanf_s("%d", &column);

	a = mallocRowMemory(a, row, column);

	elementsMatrix(a, row, column);

	printf("\n Start Matrix : \n");
	firstMatrix(a, row, column);

	printf("\n New Matrix : \n");
	secondMatrix(a, row, column);

	freeMallocRowMemory(a, row, column);
	freeMallocColumnMemory(a, row, i);

}

void elementsMatrix(int** a, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		a[i] = mallocCloumnMemory(a, row, i, column);
		for (int j = 0; j < column; j++)
		{
			printf("a[%d][%d] = ", i, j);
			scanf_s("%d", &a[i][j]);
		}
	}
}

void firstMatrix(int** a, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
			printf(" %d ", a[i][j]);
			printf("\n");
	}
}

void secondMatrix(int** a, int row, int column)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < column; j++)
		{
			if (i % 2 == 0)
			printf(" %d ", a[i][j]);
			else if (i % 2 != 0)
				printf(" %d ", a[i][column - 1 - j]);
		}
		printf("\n");
	} 
}

int** mallocRowMemory(int** a, int row, int column)
	{
		a = (int**)malloc(row *  sizeof(int*));
		return a;
	}

int* mallocCloumnMemory(int** a, int column, int i, int row)
{
	a[i] = (int*)malloc(column * sizeof(int));
	return a[i];
}

void freeMallocRowMemory(int** a, int row, int column)
{
	free(a);
}

void freeMallocColumnMemory(int** a, int i, int row)
{
	for (i = 0; i < row; i++) 
	free(a[i]);
}


