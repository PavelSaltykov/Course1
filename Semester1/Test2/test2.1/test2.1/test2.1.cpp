#include <stdio.h>
#include "list.h"

List *reverse(List *list)
{
	List *reverseList = createList();
	const int length = listLength(list);
	for (int i = length - 1; i >= 0; --i)
	{
		const int value = returnValue(list, i);
		addValue(reverseList, value);
	}
	return reverseList;
}

bool test1()
{
	List *list = createList();
	List *reverseList = reverse(list);
	const bool testPassed = listLength(reverseList) == 0;
	deleteList(list);
	deleteList(reverseList);
	return testPassed;
}

bool test2()
{
	List *list = createList();
	addValue(list, 12);
	addValue(list, 0);
	addValue(list, 3);
	addValue(list, -5);
	List *reverseList = reverse(list);
	const bool testPassed = returnValue(reverseList, 0) == -5 &&
		returnValue(reverseList, 1) == 3 &&
		returnValue(reverseList, 2) == 0 &&
		returnValue(reverseList, 3) == 12;
	deleteList(list);
	deleteList(reverseList);
	return testPassed;
}

bool tests()
{
	return test1() && test2();
}

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

	if (listLength(list) == 0)
	{
		printf("Zero list length\n");
		return 1;
	}

	List *reverseList = reverse(list);
	printf("Reverse list: ");
	printList(reverseList);

	fclose(file);
	deleteList(list);
	deleteList(reverseList);
	return 0;
}