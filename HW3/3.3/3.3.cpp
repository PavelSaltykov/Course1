#include <climits>
#include <stdio.h>

int searchMaxInArray(int array[], int lengthOfArray)
{
	int maximum = INT_MIN;
	for (int i = 0; i < lengthOfArray; i++)
	{
		if (array[i] > maximum)
		{
			maximum = array[i];
		}
	}
	return maximum;
}

int searchMinInArray(int array[], int lengthOfArray)
{
	int minimum = INT_MAX;
	for (int i = 0; i < lengthOfArray; i++)
	{
		if (array[i] < minimum)
		{
			minimum = array[i];
		}
	}
	return minimum;
}

int searchOfMostFrequent(int array[], int lengthOfArray)
{
	const int maximumElement = searchMaxInArray(array, lengthOfArray);
	const int minimumElement = searchMinInArray(array, lengthOfArray);
	const int shift = minimumElement;
	const int numberOfCounters = maximumElement - minimumElement + 1;

	int *arrayOfCounters = new int[numberOfCounters]();
	for (int i = 0; i < lengthOfArray; i++)
	{
		arrayOfCounters[array[i] - shift]++;
	}

	int MostFrequentElement = 0;
	int  maxCounter = 0;
	for (int i = 0; i < numberOfCounters; i++)
	{
		if (arrayOfCounters[i] > maxCounter)
		{
			MostFrequentElement = i + shift;
			maxCounter = arrayOfCounters[i];
		}
	}
	delete[] arrayOfCounters;
	return MostFrequentElement;
}

bool testWithoutMostFrequentElement()
{
	int array[3] = {1, 2, 3};
	const int MostFrequent = searchOfMostFrequent(array, 3);
	return MostFrequent == 1 || MostFrequent == 2 || MostFrequent == 3;
}

bool testWithAllTheIdenticalElements()
{
	int array[4] = {5, 5, 5, 5};
	return searchOfMostFrequent(array, 4) == 5;
}

bool testWithTwoMostFrequentElements()
{
	int array[6] = {2, 4, 2, 3, 7, 4};
	const int MostFrequent = searchOfMostFrequent(array, 6);
	return (MostFrequent == 2) || (MostFrequent == 4);
}

bool testWithNegativeElements()
{
	int array[7] = {9, 1, -3, 3, -3, 4, -5};
	return searchOfMostFrequent(array, 7) == -3;
}

int main()
{
	int counterOfErrors = 0;
	if (!testWithoutMostFrequentElement())
	{
		printf("Error in test without most frequent element\n");
		counterOfErrors++;
	}
	if (!testWithAllTheIdenticalElements())
	{
		printf("Error in test with all the identical elements\n");
		counterOfErrors++;
	}
	if (!testWithTwoMostFrequentElements())
	{
		printf("Error in test with two most frequent elements\n");
		counterOfErrors++;
	}
	if (!testWithNegativeElements())
	{
		printf("Error in test with negative elements\n");
		counterOfErrors++;
	}
	if (counterOfErrors == 0)
	{
		printf("Tests passed");
	}
	return 0;
}