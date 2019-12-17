#include <stdio.h>
#include "list.h"

int main()
{
	printf("Entrer numbers: ");
	List *list = createList();
	while (true)
	{
		int number = 0;
		scanf("%d", &number);
		if (number == 0)
		{
			break;
		}
		addValueToSortedList(list, number);
	}
	printf("Numbers without repetition in ascending order: ");
	printList(list);
	deleteList(list);
	return 0;
}