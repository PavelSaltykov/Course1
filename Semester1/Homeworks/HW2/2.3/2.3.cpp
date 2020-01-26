#include <stdio.h>
#include <climits>

void printArray(int array[], int lengthOfArray)
{
	for (int i = 0; i < lengthOfArray; i++)
	{
		printf("%d ", array[i]);
	}
}

void sortByBubble(int array[], int lengthOfArray)
{
	for (int i = 0; i < lengthOfArray; i++)
	{
		for (int j = lengthOfArray - 1; j > i; j--)
		{
			if (array[j] < array[j - 1])
			{
				const int temp = array[j - 1];
				array[j - 1] = array[j];
				array[j] = temp;
			}
		}
	}
}

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

void sortByCount(int array[], int lengthOfArray)
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

	int  index = 0;
	for (int i = 0; i < numberOfCounters; i++)
	{
		for (int j = 0; j < arrayOfCounters[i]; j++)
		{
			array[index] = i + shift;
			index++;
		}
	}
	delete[] arrayOfCounters;
}

int main()
{
	printf("Input length of array: ");
	int length = 0;
	scanf("%d", &length);

	printf("Input array: ");
	int *array = new int[length];
	int *arrayForSortByCount = new int[length];
	for (int i = 0; i < length; i++)
	{
		scanf("%d", &array[i]);
		arrayForSortByCount[i] = array[i];
	}

	sortByBubble(array, length);
	printArray(array, length);
	delete[] array;

	sortByCount(arrayForSortByCount, length);
	printf("\n");
	printArray(arrayForSortByCount, length);
	delete[] arrayForSortByCount;
	return 0;
}