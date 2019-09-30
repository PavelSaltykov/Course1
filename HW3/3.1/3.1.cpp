#include <stdio.h>

void insertionSort(int array[], int left, int right)
{
	for (int i = left + 1; i <= right; i++)
	{
		for (int j = i; j > left; j--)
		{
			if (array[j] < array[j - 1])
			{
				int const temp = array[j];
				array[j] = array[j - 1];
				array[j - 1] = temp;
			}
		}
	}
}

int partition(int array[], int left, int right)
{
	const int pivot = array[left];
	int low = left;
	int high = right;
	while (low < high)
	{
		if (array[low] < pivot)
		{
			low++;
		}
		else if (array[high] >= pivot)
		{
			high--;
		}
		else
		{
			const int temp = array[low];
			array[low] = array[high];
			array[high] = temp;
		}
	}
	if (low == left)
	{
		low = left + 1;
	}
	return low;
}

void qsort(int array[], int left, int right)
{
	if (right - left + 1 < 10)
	{
		insertionSort(array, left, right);
	}
	else
	{
		const int pivot = partition(array, left, right);
		qsort(array, left, pivot - 1);
		qsort(array, pivot, right);
	}
}

bool checkSortedArray(int array[], int lengthOfArray)
{
	for (int i = 0; i < lengthOfArray - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			return false;
		}
	}
	return true;
}

bool arrayTest(int array[], int lengthOfArray)
{
	qsort(array, 0, lengthOfArray - 1);
	return checkSortedArray(array, lengthOfArray);
}

bool tests()
{
	bool testsPassed = true;
	int array1[9] = {5, 4, 10, 6, 12, 7, 11, 3, 5};
	if (!arrayTest(array1, 9))
	{
		printf("Error in insertion sort\n");
		testsPassed = false;
	}

	int array2[10] = {5, 4, 10, 6, 12, 7, 11, 3, 5};
	if (!arrayTest(array2, 10))
	{
		printf("Error in test with array of 10 elements\n");
		testsPassed = false;
	}

	int array3[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
	if (!arrayTest(array3, 15))
	{
		printf("Error in test with array already sorted\n");
		testsPassed = false;
	}

	int array4[15] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	if (!arrayTest(array4, 15))
	{
		printf("Error in test with all the identical elements\n");
		testsPassed = false;
	}

	int array5[15] = {1, 4, 10, 6, 4, 7, 11, 1, 4, 5, 7, 15, 8, 9, 13};
	if (!arrayTest(array5, 15))
	{
		printf("Error when pivot is minimum in array\n");
		testsPassed = false;
	}

	int array6[15] = {15, 4, 10, 6, 4, 15, 11, 3, 4, 5, 3, 2, 7, 4, 9};
	if (!arrayTest(array6, 15))
	{
		printf("Error when pivot is maximum in array");
		testsPassed = false;
	}
	return testsPassed;
}

int main()
{
	if (tests())
	{
		printf("Tests passed");
	}
	return 0;
}