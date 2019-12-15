#include <stdio.h>
#include "list.h"
#include "mergeSort.h"

bool tests()
{

	return true;
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	FILE *file = fopen("entries.txt", "r");
	if (!file)
	{
		printf("File not found");
		return 1;
	}

	List *list = createList();
	while (!feof(file))
	{
		char name[1000] = {};
		char phone[1000] = {};
		fscanf(file, "%[^-]%*c%*c", name);
		fscanf(file, "%[^\n]%*c", phone);
		addEntry(list, name, phone);
	}
	fclose(file);

	printf("Enter:\n 1 - sort by name\n 2 - sort by phone\n");
	int input = 0;
	scanf("%d", &input);
	if (input != 1 && input != 2)
	{
		printf("Invalid input\n");
		deleteList(list);
		return 1;
	}

	List *sortedList = mergeSort(list, input == 1);
	printf("\nSorted entries:\n");
	printList(sortedList);

	deleteList(sortedList);
	return 0;
}