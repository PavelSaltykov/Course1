#include <stdio.h>

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

	for (int i = 0; i < numberOfCapitals; ++i)
	{
		int capitalNumber = 0;
		fscanf(file, "%d", &capitalNumber);
		capitals[i] = capitalNumber;
	}

	return 0;
}