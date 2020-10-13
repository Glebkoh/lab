#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void enterArrayElements(int* a, int n);
void changeFunction(int j, int* a);
void outputArrayElement(int n, int* a);
void checkVariables(int* a, int n);

int main()
{
    int* a;
    int i = 0, n, j = 0;
    printf(" Enter the size of the array: \n");
    scanf_s("%d", &n);
    a = (int*)malloc(n * sizeof(int));

    enterArrayElements(a, n);
    checkVariables(a, n);
    outputArrayElement(n, a);

    free(a);
    return 0;
}

void enterArrayElements(int* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf_s("%d", &a[i]);
    }
}

void checkVariables(int* a, int n)
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] < a[j + 1]) 
            {
                changeFunction(j, a);
            }
            else if (a[j] > a[j + 1] && a[j] < 0)
            {
                changeFunction(j, a);
            }
        }
    }
}

void outputArrayElement(int n, int* a)
{
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
}

void changeFunction(int j, int* a)
{
    int swap = 0;
    swap = a[j];
    a[j] = a[j + 1];
    a[j + 1] = swap;
}
