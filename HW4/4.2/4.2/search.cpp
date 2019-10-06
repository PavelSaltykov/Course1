#include "qsort.h"
#include "search.h"

int searchOfMinimumMostFrequent(int array[], int lengthOfArray)
{
	qsort(array, 0, lengthOfArray - 1);
	int minimumMostFrequent = array[0];
	int maxCounter = 1;
	int tempCounter = 1;
	for (int i = 1; i < lengthOfArray; i++)
	{
		if (array[i] == array[i - 1])
		{
			tempCounter++;
		}
		else
		{
			tempCounter = 1;
		}
		if (tempCounter > maxCounter)
		{
			maxCounter = tempCounter;
			minimumMostFrequent = array[i];
		}
	}
	return minimumMostFrequent;
}