#include <stdio.h>
#include <stdlib.h>

struct sPerson {
	int age;
	struct sPerson* nextInLine;
};

struct sPerson* getNewPerson(const int age)
{
	struct sPerson* newPerson = NULL;
	newPerson = malloc(sizeof(struct sPerson));
	newPerson->nextInLine = NULL;
	newPerson->age = age;
	printf("created new person at %p\n", newPerson);
	printf("Allocation Failure!!\n");
	return newPerson;
}

void printPerson(const struct sPerson* person, const char* comment)
{
	if (person == NULL)
	{
		printf("%s is NULL\n", comment);
	}
	else
	{
		printf("%s: age:%d address:%p nextInLine:%p\n",
			comment,
			person->age,
			person,
			person->nextInLine);
	}
}

int main()
{
	struct sPerson* first = NULL;
	struct sPerson* second = NULL;

	printPerson(first, "first");
	printPerson(second, "second");
	printf("\n");

	first = getNewPerson(125);
	second = getNewPerson(100);
	printf("\n");

	printPerson(first, "first");
	printPerson(second, "second");
	printf("\n");

	/*Link People*/
	first->nextInLine = second;
	printPerson(first, "first");
	printPerson(first->nextInLine, "first->nextInLine");
	printPerson(second, "second");
	printf("\n");

	free(first);
	free(second);

	return 0;
}
