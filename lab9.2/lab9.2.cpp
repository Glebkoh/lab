#include <stdio.h>
#include <malloc.h>
#include <string.h>

#define MAX_LEN_WORD 30
#define LEN_LINE 100
#define MAX_STR 300
#define MAX_LEN_TEXT 15000

char** checkSyntaxString(char* string);

int* distributWord(char** words, int numberWord);
int checkNumberArr(int number, int* arr);
int numberWordString(char* string);

void copyISymString1ToString2(char* stringDestination, char* stringSource, int n);
void freeMemoryArrStrings(char** enterArrStrings, int numberElements);
void increaseWords(char* word);

int main()
{
	char* text = (char*)malloc(MAX_LEN_TEXT * sizeof(char));

	printf(" Printf you started text : \n");
	fgets(text, MAX_LEN_TEXT, stdin);

	int numberWord = numberWordString(text);
	char** words = checkSyntaxString(text);
	int* lines = distributWord(words, numberWord);

	printf("\n Sorted text by length : ");
	for (int i = 0; i < LEN_LINE; i++)
	{
		printf(" ");
	}
	printf("\n");
	for (int i = 0; i < numberWord; i++)
	{
		printf("%s", words[i]);
		if (checkNumberArr(i, lines) && i)
		{
			printf("\n");
		}
	}

	free(text);
	free(lines);
	freeMemoryArrStrings(words, numberWord);
}

int numberWordString(char* string)
{
	int count = 0;
	char* p = string;
	for (char* pSpace; pSpace = strpbrk(p, " "); p++)
	{
		if (p != pSpace)
		{
			count++;
			p = pSpace;
		}
	}
	if (strlen(p))
	{
		count++;
	}
	return count;
}

char** checkSyntaxString(char* string)
{
	int numberWord = numberWordString(string);
	char* p = string;
	char** words = (char**)malloc(numberWord * sizeof(char*));
	int i = 0;
	for (char* pSpace; pSpace = strpbrk(p, " "); p++)
	{
		if (p != pSpace)
		{
			int LEN = pSpace - p;
			words[i] = (char*)malloc(MAX_LEN_WORD * sizeof(char));
			copyISymString1ToString2(words[i], p, LEN + 1);
			p = pSpace;
			i++;
		}
	}
	if (strlen(p))
	{
		words[i] = (char*)malloc(MAX_LEN_WORD * sizeof(char));
		copyISymString1ToString2(words[i], p, strlen(p));
		i++;
	}
	return words;
}

void copyISymString1ToString2(char* stringDestination, char* stringSource, int n)
{
	for (int i = 0; i < n; i++)
	{
		stringDestination[i] = stringSource[i];
	}
	stringDestination[n] = '\0';
}

void freeMemoryArrStrings(char** enterArrStrings, int numberElements)
{
	for (int i = 0; i < numberElements - 1; i++)
	{
		free(enterArrStrings[i]);
	}
	free(enterArrStrings);
}

void increaseWords(char* word)
{
	int LEN = strlen(word);
	word[LEN] = ' ';
	word[LEN + 1] = '\0';
}

void alignmentLine(int start, int finish, int* currentLen, char** words)
{
	int count = 0;
	while (*currentLen < LEN_LINE)
	{
		increaseWords(words[start + 1 + count]);
		(*currentLen)++;
		count++;
	}
	*currentLen = 0;
}

int* distributWord(char** words, int numberWord)
{
	int currentLenLine = 0;
	int currenNumberLine = 0;
	int* endStrings = (int*)malloc(MAX_STR * sizeof(int));
	for (int i = 0; i < MAX_STR; i++)
	{
		endStrings[i] = -1;
	}
	endStrings[0] = 0;
	for (int j = 0; j < numberWord; j++)
	{
		int LENOfCurrentWord = strlen(words[j]);
		if (currentLenLine + LENOfCurrentWord < LEN_LINE)
		{
			currentLenLine += LENOfCurrentWord;
		}
		else
		{
			endStrings[currenNumberLine + 1] = j - 1;
			alignmentLine(endStrings[currenNumberLine], endStrings[currenNumberLine + 1], &currentLenLine, words);
			currenNumberLine++;
			j--;
		}
	}
	return endStrings;
}

int checkNumberArr(int number, int* arr)
{
	for (int i = 0; i < MAX_STR; i++)
	{
		if (number == arr[i])
			return 1;
	}
	return 0;
}