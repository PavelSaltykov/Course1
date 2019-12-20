#include "hashTable.h"
#include "list.h"

struct HashTable
{
	int size = 20;
	int amountOfElements = 0;
	float loadFactor = 0.0;
	List **buckets = nullptr;
};

void createBuckets(HashTable *table)
{
	table->buckets = new List *[table->size];
	for (int i = 0; i < table->size; ++i)
	{
		table->buckets[i] = createList();
	}
}

HashTable *createHashTable()
{
	HashTable *newTable = new HashTable;
	createBuckets(newTable);
	return newTable;
}

int hashFunction(char *value, int size)
{
	int result = 0;
	for (int i = 0; value[i] != '\0'; ++i)
	{
		result = (result + value[i]) % size;
	}
	return result;
}

void addToTable(HashTable *table, char *value, int quantity)
{
	const bool newElementAdded = addNewValueToList(table->buckets[hashFunction(value, table->size)], value, quantity);
	if (newElementAdded)
	{
		table->amountOfElements++;
		table->loadFactor = 1.0 * table->amountOfElements / table->size;
	}
}

List *helpList(HashTable *table)
{
	List *helpList = createList();
	for (int i = 0; i < table->size; ++i)
	{
		while (!isEmpty(table->buckets[i]))
		{
			char *value = returnValueFromHead(table->buckets[i]);
			addNewValueToList(helpList, value, quantityOfValuesFromHead(table->buckets[i]));
			deleteValueFromHead(table->buckets[i]);
		}
		deleteList(table->buckets[i]);
	}
	return helpList;
}

void rehashing(HashTable *table)
{
	List *tempList = helpList(table);
	delete[] table->buckets;
	table->size *= 2;
	table->amountOfElements = 0;
	createBuckets(table);

	while (!isEmpty(tempList))
	{
		char *value = returnValueFromHead(tempList);
		addToTable(table, value, quantityOfValuesFromHead(tempList));
		deleteValueFromHead(tempList);
	}
	deleteList(tempList);
}

void addValueToTable(HashTable *table, char *value)
{
	addToTable(table, value, 1);

	if (table->loadFactor > 1)
	{
		rehashing(table);
	}
}

bool tableContainsValue(HashTable *table, char *value)
{
	return listContainsValue(table->buckets[hashFunction(value, table->size)], value);
}

void printTable(HashTable *table)
{
	for (int i = 0; i < table->size; ++i)
	{
		printList(table->buckets[i]);
	}
}

float loadFactor(HashTable *table)
{
	return table->loadFactor;
}

int maximumListLength(HashTable *table)
{
	int maxLength = 0;
	for (int i = 0; i < table->size; ++i)
	{
		const int currentListLength = listLength(table->buckets[i]);
		if (currentListLength > maxLength)
		{
			maxLength = currentListLength;
		}
	}
	return maxLength;
}

float averageListLength(HashTable *table)
{
	int sumOfAllLengths = 0;
	int numberOfLists = 0;
	for (int i = 0; i < table->size; ++i)
	{
		if (!isEmpty(table->buckets[i]))
		{
			sumOfAllLengths += listLength(table->buckets[i]);
			numberOfLists++;
		}
	}
	return numberOfLists != 0 ? 1.0 * sumOfAllLengths / numberOfLists : 0;
}


void deleteTable(HashTable *table)
{
	for (int i = 0; i < table->size; ++i)
	{
		deleteList(table->buckets[i]);
	}
	delete[] table->buckets;
	delete table;
}