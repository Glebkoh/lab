#include "mystr.h"
#include <malloc.h>
// n- number; p - point;

int	ñalculationLengthStrings(char* string)   // strlen
{
	int lenght;
	for (lenght = 0; string[lenght]; lenght++);
	return lenght;
}

void ñopyString(char* string1, char* string2) // strcpy
{
	for (int i = 0; string1[i] = string2[i]; i++);
}

void concatenateStrings(char* stringNum1, char* stringNum2) // strcat
{
	char* temp;
	for (temp = stringNum1; *temp; temp++);
	for (int i = 0; temp[i] = stringNum2[i]; i++);
}

int ñheckEqualityString(char* stringFir, char* stringSec) // strcmp
{
	for (int Number = 0; stringFir[Number] || stringSec[Number]; Number++)
	{
		if (stringFir[Number] != stringSec[Number])
			return 0;
	}
	return 1;
}

char* returnPointer(char* string, char ch) // strchar
{
	char* p; 
	for (p = string; *p; p++)
	{
		if (*p == ch)
			return p;
	}
	return NULL;
}

char* ReturnPointerFirstOccurrence(char* string, char* substr) // strstr
{
	char* pString = string;
	char* nString; 
	char* nSequence = substr;
	int check = 1;
	while (*pString && *nSequence && check)
	{
		for (nString = pString, nSequence = substr;
			*nString && *nString == *nSequence;
			nString++, nSequence++);
		if (!(*nString && *nSequence))
			check = 0;
		else
			pString++;
	}
	return *pString ? pString : NULL;
}

void deleteElementString(char* string, int nElemment)
{
	if (string)
	{
		if (ñalculationLengthStrings(string) <= nElemment)
			string[0] = '\0';
		else
			ñopyString(string, string + nElemment);
	}
}

void deleteSubstrFromString(char* string, char* substr)
{
	char* temp = ReturnPointerFirstOccurrence(string, substr);
	if (NULL != temp)
		ñopyString(temp, temp + ñalculationLengthStrings(substr));
}
