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
	const int survivorWarrior = headValue(list);
	deleteList(list);
	return survivorWarrior;
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

	printf("Enter the number of warriors: ");
	int numberOfWarriors = 0;
	scanf("%d", &numberOfWarriors);

	printf("Enter killing periodicity: ");
	int periodicity = 0;
	scanf("%d", &periodicity);

	if (numberOfWarriors < 1 || periodicity < 1)
	{
		printf("Invalid input\n");
		return 1;
	}

	const int survivorWarrior = count(numberOfWarriors, periodicity);
	printf("Position number of survivor warrior: %d\n", survivorWarrior);
	return 0;
}