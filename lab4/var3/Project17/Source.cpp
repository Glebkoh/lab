#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 10


int searchTheMinimumElementArray(int min, int index, int* a, int i);
float findGeoSum(int* a, int i, int min);
void enterArrayElements(int* a, int i);


int main()
{
    int* a;
    int min = 0;
    int i = 0, index = 0;
    float S = 0.0;
    a = (int*)malloc(ARRAY_SIZE * sizeof(int));

    enterArrayElements(a, i);

    min = searchTheMinimumElementArray(min, index, a, i);
    printf(" Minimum element of the array : \n min = ");
    printf("%d", min);

    S = findGeoSum(a, i, min);
    printf("\n The sum of a geometric progression:");
    printf("\n S = %0.3f", S);
}

void enterArrayElements(int* a, int i)
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("  a[%d] = ", i);
        scanf_s("%d", &a[i]);
    }
}

int searchTheMinimumElementArray(int min, int index, int* a, int i)
{

    min = a[ARRAY_SIZE - 1];
    index = 0;
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        while ((a[i]) < min)
        {
            min = a[i];
            index = i;
        }
    }
    return min;
}

float findGeoSum(int* a, int i, int min)
{
    float power = 1;
    float compositionArray = 1;
    float S = 0.0;
    i = 0;
    while (a[i] != min && a[i] != 0 && i < 10)
    {
        compositionArray *= a[i];
        i++;
        power = 1.0 / i;
    }
    S = pow(compositionArray, power);
    return S;
}
