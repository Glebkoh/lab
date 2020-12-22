#include <stdio.h>
#include <string.h>
#include <malloc.h>

#define MAX_LEN_WORDS 20
#define MAX_LEN_TEXT 10000

typedef struct DictionaryWords
{
	char** words;
	int* repetition;
} DictionaryWords;

int numberWordString(char* string);
int checkUniquenessWord(char** enterArrStrings, char* string, int numberOfElements);

char** checkSyntaxString(char* string);
DictionaryWords createDictionary(char* text);

void enterArrStrings(char** enterArrStrings, int numberOfElements);
void freeMemoryArrStrings(char** enterArrStrings, int numberOfElements);
void copyISymString1ToString2(char* stringDestination, char* stringSource, int n);
void printDictionaryWords(DictionaryWords tmp1, int numberOfWords);
void freeMemoryDictionaryWords(DictionaryWords tmp1, int numberOfWords);
void sortDictionaryWords(DictionaryWords tmp1, int numberOfWords);


int main()
{
	char* text = (char*)malloc(MAX_LEN_TEXT * sizeof(char));
	printf("Print you text : \n");

	fgets(text, MAX_LEN_TEXT, stdin);
	text[strlen(text) - 1] = '\0';

	int numberOfWords = numberWordString(text);
	DictionaryWords tmp1 = createDictionary(text);
	sortDictionaryWords(tmp1, numberOfWords);
	printDictionaryWords(tmp1, numberOfWords);
	freeMemoryDictionaryWords(tmp1, numberOfWords);
	free(text);

	printf("\nCreate Dictionary Words, finish with text+)\n");
}

int numberWordString(char* string)
{
	int count = 0;
	char* p = string;
	for (char* pSpace; pSpace = strpbrk(p, " ,.''-_!?><;:()|}]{{"); p++)
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

DictionaryWords createDictionary(char* text)
{
	int numberOfWords = numberWordString(text);
	char** words = checkSyntaxString(text);
	int* repetRate = (int*)malloc(numberOfWords * sizeof(int));
	for (int i = 0; i < numberOfWords; i++)
	{
		repetRate[i] = 1;
	}
	for (int i = 0; i < numberOfWords; i++)
	{
		int index = checkUniquenessWord(words, words[i], i - 1);
		if (words[i] && (index + 1))
		{
			words[i] = { };
			repetRate[index]++;
		}
	}
	DictionaryWords tmp1 = { words, repetRate };
	return tmp1;
}

char** checkSyntaxString(char* string)
{
	int numberOfWords = numberWordString(string);
	char* p = string;
	char** words = (char**)malloc(numberOfWords * sizeof(char*));
	int i = 0;
	for (char* pSpace; pSpace = strpbrk(p, " ,.''-_!?><;:()|}]{"); p++)
	{
		if (p != pSpace)
		{
			int LEN = pSpace - p;
			words[i] = (char*)malloc((LEN + 1) * sizeof(char));
			copyISymString1ToString2(words[i], p, LEN);
			p = pSpace;
			i++;
		}
	}
	if (strlen(p))
	{
		words[i] = (char*)malloc(strlen((p)+1) * sizeof(char));
		copyISymString1ToString2(words[i], p, strlen(p));
		i++;
	}
	return words;
}

void enterArrStrings(char** enterArrStrings, int numberOfElements)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		puts(enterArrStrings[i]);
	}
}

void freeMemoryArrStrings(char** enterArrStrings, int numberOfElements)
{
	for (int i = 0; i < numberOfElements - 1; i++)
	{
		free(enterArrStrings[i]);
	}
	free(enterArrStrings);
}

void copyISymString1ToString2(char* stringDestination, char* stringSource, int n)
{
	for (int i = 0; i < n; i++)
	{
		stringDestination[i] = stringSource[i];
	}
	stringDestination[n] = '\0';
}

int checkUniquenessWord(char** enterArrStrings, char* string, int numberOfElements)
{
	for (int i = 0; i < numberOfElements; i++)
	{
		if (enterArrStrings[i] && string)
		{
			if (!strcmp(enterArrStrings[i], string))
			{
				return i;
			}
		}
	}
	return -1;
}

void printDictionaryWords(DictionaryWords tmp1, int numberOfWords)
{
	int j = 0;
	for (int i = 0; i < numberOfWords; i++)
	{
		if (tmp1.words[i])
		{
			printf("\n%d.%15.15s:  %d\n", j+1, tmp1.words[i], tmp1.repetition[i]);
			j++;
		}
	}
	printf("\n Number of unique words in the text : %d\n", j);
}

void freeMemoryDictionaryWords(DictionaryWords tmp1, int numberOfWords)
{
	freeMemoryArrStrings(tmp1.words, numberOfWords);
	free(tmp1.repetition);
}

void sortDictionaryWords(DictionaryWords tmp1, int numberOfWords)
{
	for (int i = 0; i < numberOfWords - 1; i++)
		for (int j = 0; j < numberOfWords - 1 - i; j++)
			if (tmp1.repetition[j] < tmp1.repetition[j + 1])
			{
				int temporary = tmp1.repetition[j];
				tmp1.repetition[j] = tmp1.repetition[j + 1];
				tmp1.repetition[j + 1] = temporary;

				char* temp = tmp1.words[i];
				tmp1.words[i] = tmp1.words[i + 1];
				tmp1.words[i + 1] = temp;
			}
}

