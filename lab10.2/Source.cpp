#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

#define MaxName 50

struct student
{
	char* firstname = (char*)malloc(MaxName * sizeof(char));
	int* marks = (int*)malloc(5 * sizeof(int));
	float averageMark = 0;
};
struct mark
{
	int mark5 = 0;
	int mark4 = 0;
	int mark3 = 0;
	int mark2 = 0;
};


void inputGroupStudent(student* studentArray, int numStudent);
void avregeMarkStudent(student* studentArray, int numStudent);
void outputGroupSortStudent(student* studentArray, student* array5, student* array4, student* array3, student* array2, mark* mark);
void sortMarksStudent(student* studentArray, student* array5, student* array4, student* array3, student* array2, int numStudent, mark* mark);
void writeFirstnameStudent(char* str);
void sortGroupStudentAlphabet(student* array, mark* mark);
void swap(student* s1, student* s2);


int main()
{
	int numStudent = 0;
	printf("How many students we sort : ");
	scanf_s("%d", &numStudent);
	getchar();

	mark mark;
	student* studentArray = (student*)malloc(numStudent * sizeof(student));
	student* array2 = (student*)malloc(numStudent * sizeof(student));
	student* array3 = (student*)malloc(numStudent * sizeof(student));
	student* array4 = (student*)malloc(numStudent * sizeof(student));
	student* array5 = (student*)malloc(numStudent * sizeof(student));

	inputGroupStudent(studentArray, numStudent);
	avregeMarkStudent(studentArray, numStudent);
	sortMarksStudent(studentArray, array5, array4, array3, array2, numStudent, &mark);
	sortGroupStudentAlphabet(array2, &mark);
	sortGroupStudentAlphabet(array3, &mark);
	sortGroupStudentAlphabet(array4, &mark);
	sortGroupStudentAlphabet(array5, &mark);
	outputGroupSortStudent(studentArray, array5, array4, array3, array2, &mark);
}

student inputStudent()
{
	student result;
	printf("Firstname student: ");
	writeFirstnameStudent(result.firstname);
	printf("5 marks student:");
	for (int i = 0; i < 5; i++)
	{
		scanf_s("\n%d", &result.marks[i]);
	}
	getchar();
	return result;
}
void writeFirstnameStudent(char* str)
{
	fgets(str, MaxName, stdin);
	str[strlen(str) - 1] = '\0';
}

void avregeMarkStudent(student* studentArray, int numStudent)
{
	for (int i = 0; i < numStudent; i++)
	{
		studentArray[i].averageMark = (studentArray[i].marks[0] + studentArray[i].marks[1] + studentArray[i].marks[2] + studentArray[i].marks[3] + studentArray[i].marks[4]);
		float sum = studentArray[i].averageMark / 5.0;
		printf("Average %d student mark : %0.2f\n", i + 1, sum);
	}
}

void sortMarksStudent(student* studentArray, student* array5, student* array4, student* array3, student* array2, int numStudent, mark* mark)
{

	for (int i = 0; i < numStudent; i++)
	{
		if (studentArray[i].marks[0] == 5 && studentArray[i].marks[1] == 5 && studentArray[i].marks[2] == 5 && studentArray[i].marks[3] == 5 && studentArray[i].marks[4] == 5)
		{
			array5[mark->mark5] = studentArray[i];
			mark->mark5++;
		}
		else if (studentArray[i].marks[0] >= 4 && studentArray[i].marks[1] >= 4 && studentArray[i].marks[2] >= 4 && studentArray[i].marks[3] >= 4 && studentArray[i].marks[4] >= 4)
		{
			array4[mark->mark4] = studentArray[i];
			mark->mark4++;
		}
		else if (studentArray[i].marks[0] >= 3 && studentArray[i].marks[1] >= 3 && studentArray[i].marks[2] >= 3 && studentArray[i].marks[3] >= 3 && studentArray[i].marks[4] >= 3)
		{
			array3[mark->mark3] = studentArray[i];
			mark->mark3++;
		}
		else
		{
			array2[mark->mark2] = studentArray[i];
			mark->mark2++;
		}

	}

}
void sortGroupStudentAlphabet(student* array, mark* mark)
{
	for (int i = 0; i < mark->mark5; i++)
	{
		for (int j = i + 1; j < mark->mark5; j++)
		{
			if (strcmp(array[i].firstname, array[j].firstname) > 0)
			{
				swap(&array[i], &array[j]);
			}
		}
	}
}

void swap(student* s1, student* s2)
{
	student tmp;
	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

void outputGroupSortStudent(student* studentArray, student* array5, student* array4, student* array3, student* array2, mark* mark)
{
	printf("A grade: \n");
	for (int i = 0; i < mark->mark5; i++)
	{
		printf("%s\n", array5[i].firstname);
		
	}

	printf("B grade: \n");
	for (int i = 0; i < mark->mark4; i++)
	{
		printf("%s\n", array4[i].firstname);	
	}
	printf("C grade: \n");
	for (int i = 0; i < mark->mark3; i++)
	{
		printf("%s\n", array3[i].firstname);
	}
	printf("F grade: \n");
	for (int i = 0; i < mark->mark2; i++)
	{
		printf("%s\n", array2[i].firstname);
	}
}

void inputGroupStudent(student* studentArray, int numStudent)
{
	for (int i = 0; i < numStudent; i++)
		studentArray[i] = inputStudent();
}