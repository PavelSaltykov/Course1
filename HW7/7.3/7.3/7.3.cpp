#include <stdio.h>
#include "list.h"

bool tests()
{

	return true;
}

int main()
{
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
	delete file;
	deleteList(list);

	return 0;
}