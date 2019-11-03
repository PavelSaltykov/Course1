#include <stdio.h>
#include <string.h>
#include "list.h"

void begin()
{
	printf("Enter:\n 0 - log off\n");
	printf(" 1 - add value to sorted list\n");
	printf(" 2 - remove value from list\n");
	printf(" 3 - print list\n");
}

bool tests()
{
	List *testList = createList();
	addValue(testList, 1);
	addValue(testList, 2);
	addValue(testList, 0);
	const bool isSorted = checkSortedList(testList);
	
	const bool test1Passed = deleteValue(testList, 0);
	const bool test2Passed = deleteValue(testList, 2);
	const bool test3Passed = !deleteValue(testList, 2);
	deleteList(testList);
	return isSorted && test1Passed && test2Passed && test3Passed;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}
	char input[100] = {};
	bool shouldGoOut = false;
	List *list = createList();
	while (!shouldGoOut)
	{
		begin();
		scanf("%s", input);
		if (strlen(input) != 1)
		{
			printf("Invalid input, try again\n\n");
			continue;
		}
		switch (input[0])
		{
		case '0':
			shouldGoOut = true;
			break;
		case '1':
		{
			printf("Enter value: ");
			int value = 0;
			scanf("%d", &value);
			addValue(list, value);
			printf("\n");
			break;
		}
		case '2':
		{
			printf("Enter value: ");
			int value = 0;
			scanf("%d", &value);
			if (!deleteValue(list, value))
			{
				printf("Value not found\n");
			}
			printf("\n");
			break;
		}
		case '3':
			if (isEmpty(list))
			{
				printf("The list is empty\n\n");
			}
			else
			{
				printf("The list: ");
				printList(list);
				printf("\n\n");
			}
			break;
		default:
			printf("Invalid input, try again\n\n");
			break;
		}
	}
	deleteList(list);
	return 0;
}