#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "hashTable.h"

bool tests()
{
	HashTable *table = createHashTable();
	char string1[1000] = "a";
	char string2[2] = "M";
	char string3[5] = "bcdf";
	for (int i = 0; i < 900; ++i)
	{
		strcat(string1, "a");
		addValueToTable(table, string1);
		addValueToTable(table, string2);
		addValueToTable(table, string3);
	}
	bool testsPassed = tableContainsValue(table, string1);
	testsPassed = testsPassed && tableContainsValue(table, string2);
	testsPassed = testsPassed && tableContainsValue(table, string3);

	deleteTable(table);
	return testsPassed;
}

void parser(char *string)
{
	int last = strlen(string) - 1;
	if (!isalnum(string[last]))
	{
		string[last] = '\0';
	}
}

int main()
{
	if (!tests())
	{
		printf("Testing error\n");
		return 1;
	}

	FILE *file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found");
		return 1;
	}

	HashTable *table = createHashTable();
	while (!feof(file))
	{
		char word[50] = {};
		fscanf(file, "%s", word);
		parser(word);
		if (strlen(word) > 0)
		{
			addValueToTable(table, word);
		}
	}
	fclose(file);

	printf("Words:\n");
	printTable(table);

	printf("\n\nLoad factor: %f", loadFactor(table));
	printf("\nMaximum list length: %d", maximumListLength(table));
	printf("\nAverage list length: %f\n", averageListLength(table));

	deleteTable(table);
	return 0;
}