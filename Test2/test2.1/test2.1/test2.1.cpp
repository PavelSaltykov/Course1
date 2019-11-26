#include <stdio.h>
#include "list.h"

bool test()
{
	List *list = createList();
	addValue(list, 1);
	addValue(list, 2);
	addValue(list, 3);
	addValue(list, 2);
	addValue(list, 1);
	addValue(list, 4);
	List *testList = newList(list);

	bool testPassed = deleteValue(testList) == 1;
	testPassed = testPassed && deleteValue(testList) == 2;
	testPassed = testPassed && deleteValue(testList) == 3;

	deleteList(list);
	deleteList(testList);
	return testPassed;
}

int main()
{
	if (!test())
	{
		printf("Testing error\n");
		return 1;
	}

	List *list = createList();
	int length = 0;
	printf("Enter list length: ");
	scanf("%d\n", &length);
	printf("Enter list: ");
	for (int i = 0; i < length; ++i)
	{
		int value = 0;
		scanf("%d", &value);
		addValue(list, value);
	}
	List *listNew = newList(list);
	return 0;
}