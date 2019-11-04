#include <stdio.h>
#include "circular_list.h"

int count(int numberOfWarriors, int periodicity)
{
	List *list = createList();
	for (int i = 1; i <= numberOfWarriors; ++i)
	{
		addValue(list, i);
	}

	while (!onlyHeadInList(list))
	{
		deleteValue(list, periodicity);
	}
	const int lastWarrior = headValue(list);
	deleteList(list);
	return lastWarrior;
}

bool tests()
{
	return count(10, 2) == 5 && count(10, 3) == 4 && count(10, 8) == 1 && count(1, 3) == 1 && count(5, 6) == 4;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	return 0;
}