#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct sPerson {
	int age;
	struct sPerson* nextInLine;
};

struct sPerson* getNewPerson(const int age)
{
	struct sPerson* newPerson = NULL;
	newPerson = malloc(sizeof(struct sPerson));
	if (newPerson != NULL)
	{
		newPerson->nextInLine = NULL;
		newPerson->age = age;
		printf("created new person at %p\n", newPerson);
	}
	else
	{
		printf("Allocation Failure!!\n");
	}
	return newPerson;
}

void printPerson(const struct sPerson* person)
{
	if (person == NULL)
	{
		printf("error\n");
	}
	else
	{
		printf("age:%d address:%p nextInLine:%p\n",
			person->age,
			person,
			person->nextInLine);
	}
}

void printList(const struct sPerson* list)
{
	struct sPerson* t;
	t = list;

	if (t == NULL)
	{
		printf("list is empty\n");
	}
	else
	{
		while (t)
		{
			printPerson(t);
			t = t->nextInLine;
		}
	}
}


void cleanUp(struct sPerson* list)
{
	struct sPerson* next;
	while (list)
	{
		next = list->nextInLine;
		printf("Cleaning %d\n", list->age);
		free(list);
		list = next;
	}
}

int main()
{
	printf("\n\n** START **\n\n"); 

	struct sPerson* first = NULL;
	struct sPerson* added = NULL;

	char command[64];
	int age;

	while (1)
	{
		printf("Enter a command or value : ");
		fgets(command, 64, stdin);
		if (strcmp("q\n", command) == 0)
		{
			printf("Quitting...\n");
			break;
		}
		else if (strcmp("print\n", command) == 0)
		{
			printf("Printing...\n");
			printList(first);
		}
		else if (sscanf(command, "%d", &age) != 0)
		{
			printf("Adding...\n");
			if (first == NULL)
			{
				first = getNewPerson(age);
				if (first != NULL)
				{
					added = first;
				}
			}
			else
			{
				added->nextInLine = getNewPerson(age);
				if (added->nextInLine != NULL)
				{
					added = added->nextInLine;
				}
			}

		}
	}

	cleanUp(first);
	first = NULL;
	added = NULL;

	return 0;
}
