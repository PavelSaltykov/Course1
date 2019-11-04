#include <stdio.h>
#include "circular_list.h"

int count(int numberOfWarriors, int periodicity)
{
	List *list = createList();
	for (int i = 1; i <= numberOfWarriors; ++i)
	{
		addValue(list, i);
	}

	const bool shouldMoveBeginningOfList = true;
	while (!onlyHeadInList(list))
	{
		deleteValue(list, periodicity, shouldMoveBeginningOfList);
	}

	const int lastWarrior = headValue(list);
	deleteList(list);
	return lastWarrior;
}

bool tests()
{

	return true;
}

int main()
{

	return 0;
}