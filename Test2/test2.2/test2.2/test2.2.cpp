#include <stdio.h>
#include "list.h"
#include "symmetryCheck.h"
#include "tests.h"

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	FILE *file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found\n");
		return 1;
	}

	List *list = createList();
	while (true)
	{
		int number = 0;
		if (fscanf(file, "%d", &number) != EOF)
		{
			addValue(list, number);
		}
		else
		{
			break;
		}
	}
	fclose(file);

	if (listLength(list) == 0)
	{
		printf("Zero list length\n");
		deleteList(list);
		return 1;
	}

	printf("The list is ");
	printf(isSymmetric(list) ? "symmetric\n" : "asymmetric\n");
	deleteList(list);
	return 0;
}