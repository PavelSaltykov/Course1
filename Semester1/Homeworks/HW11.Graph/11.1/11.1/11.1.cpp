#include <stdio.h>
#include "list.h"
#include "algorithm.h"

bool test()
{
	const int size = 5;
	int **testGraph = new int *[size];
	for (int i = 0; i < size; ++i)
	{
		testGraph[i] = new int[size] {};
	}

	FILE *file = fopen("testGraph.txt", "r");
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			fscanf(file, "%d", &testGraph[i][j]);
		}
	}
	fclose(file);

	int capitals[2] = {0, 1};
	const int numberOfCapitals = 2;

	List **states = new List *[numberOfCapitals];
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		states[i] = createList();
	}

	List *answer1 = createList();
	addValue(answer1, 0);
	addValue(answer1, 2);
	addValue(answer1, 3);
	addValue(answer1, 4);

	List *answer2 = createList();
	addValue(answer2, 1);

	distributeCities(testGraph, size, capitals, numberOfCapitals, states);

	for (int i = 0; i < size; ++i)
	{
		delete[] testGraph[i];
	}
	delete[] testGraph;

	const bool testPassed = compareLists(states[0], answer1) && compareLists(states[1], answer2);

	for (int i = 0; i < numberOfCapitals; ++i)
	{
		deleteList(states[i]);
	}
	delete[] states;
	deleteList(answer1);
	deleteList(answer2);
	return testPassed;
}

int main()
{
	if (!test())
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

	int **graph = new int *[size];
	for (int i = 0; i < size; ++i)
	{
		graph[i] = new int[size] {};
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