#include <math.h>
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS
#define ARRAY_SIZE 10

void theMinimumElementArray(int min, int index, int a[ARRAY_SIZE], int i);
void findingNumberOfElements(int count, int a[ARRAY_SIZE], int i, int min);
void calculatingArithmeticSum(int count, int a[ARRAY_SIZE], float S);


int main()
{
    int a[ARRAY_SIZE];
    int min = 0;
    int i = 0, index = 0, count = 0;
    float S = 0;

    for ( int i = 0; i < ARRAY_SIZE; i++) // ввод значений массиву                                                                                            1
    {
        printf(" a[%d] = ", i);
        scanf_s("%d", &a[i]);
    }
    theMinimumElementArray(min, index, a, i);
}



void theMinimumElementArray(int min, int index, int a[ARRAY_SIZE], int i)
{
    int  count = 0;
    min = a[ARRAY_SIZE - 1];
    index = 0;
    for (int i = 0; i < ARRAY_SIZE; i++) // нахождение минимального элемента массива                                                                          2
    {
        while ((a[i]) < min)
        {
            min = a[i];
            index = i;
        }

    }
    printf(" Minimum element of the array : \n min = ");
    printf("%d", min);

    findingNumberOfElements(count, a, i, min);
}


void findingNumberOfElements(int count, int a[ARRAY_SIZE], int i, int min)
{
    float S = 0.0;
    count = 0, i = 0;
    while (a[i] != min && a[i] != 0 && i < 10) // нахождение чисел из массива удовлетвор€ющих условию                                                              3
    {
        i++;
        count++;

    }
    printf(" \nThe number of array elements that are at a minimum : \n count = ");
    printf("%d", count);

    calculatingArithmeticSum(count, a, S);
}


void  calculatingArithmeticSum(int count, int a[ARRAY_SIZE], float S)
{
    S = ((a[0] + a[count])/2.0)* count; //  cумма арифметической прогресии 
    printf("\n%f", S);
}
