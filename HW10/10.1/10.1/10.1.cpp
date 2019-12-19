#include <stdio.h>
#include <string.h>
#include "hashTable.h"

bool tests()
{
	HashTable *table = createHashTable();
	char string1[1000] = "a";
	char string2[2] = "M";
	char string3[2] = "b";
	for (int i = 0; i < 900; ++i)
	{
		strcat(string1, "a");
		addValueToTable(table, string1);
		addValueToTable(table, string2);
		addValueToTable(table, string3);
	}
	const bool testsPassed = tableContainsValue(table, string3);

	printTable(table);
	printf("\n%f", loadFactor(table));
	printf("\n%d", maximumListLength(table));
	printf("\n%f", averageListLength(table));
	deleteTable(table);
	return testsPassed;
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