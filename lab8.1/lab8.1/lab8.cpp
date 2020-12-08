
#include <stdio.h>
#include "mystr.h"

void deleteSpaces(char* string, char* space);

int main()
{
    char string[80], space[3] = { ' ',' ','\0' };
    printf("Enter a string: ");
    fgets(string, 80, stdin);
    printf("Corrected line: ");

    deleteSpaces(string, space);

    printf(string);
}

void deleteSpaces(char* string, char* space) 
{
    char* numSpace = ReturnPointerFirstOccurrence(string, space);
    while (numSpace) 
    {
        numSpace = ReturnPointerFirstOccurrence(string, space);
        deleteElementString(numSpace, 1);
    }
}
