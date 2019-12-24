#include <stdio.h>
#include "list.h"
#include "algorithm.h"

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

	FILE *file = fopen("input.txt", "r");
	if (!file)
	{
		printf("File not found\n");
		return 1;
	}

	int size = 0;
	fscanf(file, "%d", &size);

	int **graph = new int*[size];
	for (int i = 0; i < size; ++i)
	{
		graph[i] = new int[size];
		for (int j = 0; j < size; ++j)
		{
			graph[i][j] = 0;
		}
	}

	int numberOfRoads = 0;
	fscanf(file, "%d", &numberOfRoads);

	for (int i = 0; i < numberOfRoads; ++i)
	{
		int firstCityNumber = 0;
		fscanf(file, "%d", &firstCityNumber);
		int secondCityNumber = 0;
		fscanf(file, "%d", &secondCityNumber);
		int length = 0;
		fscanf(file, "%d", &length);
		graph[firstCityNumber][secondCityNumber] = length;
		graph[secondCityNumber][firstCityNumber] = length;
	}

	int numberOfCapitals = 0;
	fscanf(file, "%d", &numberOfCapitals);
	int *capitals = new int[numberOfCapitals];

	List **states = new List *[numberOfCapitals];
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		int capitalNumber = 0;
		fscanf(file, "%d", &capitalNumber);
		capitals[i] = capitalNumber;
		states[i] = createList();
	}
	fclose(file);

	distributeCities(graph, size, capitals, numberOfCapitals, states);

	for (int i = 0; i < size; ++i)
	{
		delete[] graph[i];
	}
	delete[] graph;

	delete[] capitals;

	for (int i = 0; i < numberOfCapitals; ++i)
	{
		printf("Cities of state %d: ", i + 1);
		printList(states[i]);
		printf("\n");
	}

	for (int i = 0; i < numberOfCapitals; ++i)
	{
		deleteList(states[i]);
	}
	delete[] states;
	return 0;
}