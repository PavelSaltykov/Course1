#include <climits>
#include "list.h"
#include "algorithm.h"

void giveCity(int **graph, int size, int capitalNumber, int *distance, bool *used, List *state, int &numberOfRemainingCities)
{
	int minimumDistance = INT_MAX;
	int currentVertex = -1;
	for (int i = 0; i < size; ++i)
	{
		if (!used[i] && distance[i] < minimumDistance)
		{
			minimumDistance = distance[i];
			currentVertex = i;
		}
	}
	if (currentVertex == -1)
	{
		return;
	}

	for (int i = 0; i < size; ++i)
	{
		if (graph[currentVertex][i] != 0 && !used[i] && distance[currentVertex] + graph[currentVertex][i] < distance[i])
		{
			distance[i] = distance[currentVertex] + graph[currentVertex][i];
		}
	}
	used[currentVertex] = true;
	addValue(state, currentVertex);
	--numberOfRemainingCities;
}

void distributeCities(int **graph, int size, int *capitals, int numberOfCapitals, List **states)
{
	bool *used = new bool[size];
	for (int i = 0; i < size; ++i)
	{
		used[i] = false;
	}

	int **distance = new int *[numberOfCapitals];
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		distance[i] = new int[size];
		for (int j = 0; j < size; ++j)
		{
			distance[i][j] = INT_MAX;
		}
		distance[i][capitals[i]] = 0;
	}

	int numberOfRemainingCities = size;
	while (numberOfRemainingCities > 0)
	{
		for (int i = 0; i < numberOfCapitals; ++i)
		{
			giveCity(graph, size, capitals[i], distance[i], used, states[i], numberOfRemainingCities);
		}
	}

	delete[] used;
	for (int i = 0; i < numberOfCapitals; ++i)
	{
		delete[] distance[i];
	}
	delete[] distance;
}