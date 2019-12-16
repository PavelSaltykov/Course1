#include <stdio.h>
#include "list.h"
#include "mergeSort.h"

bool tests()
{
	List *list = createList();
	char name1[10] = "z";
	char phone1[10] = "1";
	addEntry(list, name1, phone1);

	char name2[10] = "c";
	char phone2[10] = "9";
	addEntry(list, name2, phone2);

	char name3[10] = "a";
	char phone3[10] = "4";
	addEntry(list, name3, phone3);

	char name4[10] = "h";
	char phone4[10] = "2";
	addEntry(list, name4, phone4);

	List *sortedList1 = mergeSort(list, true);
	bool testsPassed = checkSort(sortedList1, true);

	List *sortedList2 = mergeSort(sortedList1, false);
	testsPassed = testsPassed && checkSort(sortedList2, false);
	deleteList(sortedList2);
	return testsPassed;
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