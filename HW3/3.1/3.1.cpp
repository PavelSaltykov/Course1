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
	int pivot = array[left];
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
		const int temp = pivot;
		pivot = array[left];
		array[left] = temp;
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
		if (i == lengthOfArray - 2)
		{
			return true;
		}
	}
}

int main()
{
	int counterOfErrors = 0;
	int array1[10] = {5, 4, 10, 6, 12, 7, 11, 3, 5, 2};
	insertionSort(array1, 0, 9);
	if (!checkSortedArray(array1, 10))
	{
		printf("Error in insertion sort\n");
		counterOfErrors++;
	}

	int array2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	qsort(array2, 0, 9);
	if (!checkSortedArray(array2, 10))
	{
		printf("Error in test with array already sorted\n");
		counterOfErrors++;
	}

	int array3[10] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	qsort(array3, 0, 9);
	if (!checkSortedArray(array3, 10))
	{
		printf("Error in test with all the identical elements\n");
		counterOfErrors++;
	}

	int array4[10] = {1, 4, 10, 6, 4, 7, 11, 1, 4, 5};
	qsort(array4, 0, 9);
	if (!checkSortedArray(array4, 10))
	{
		printf("Error when pivot is minimum in array\n");
		counterOfErrors++;
	}

	int array5[10] = {15, 4, 10, 6, 4, 15, 11, 3, 4, 5};
	qsort(array5, 0, 9);
	if (!checkSortedArray(array5, 10))
	{
		printf("Error when pivot is maximum in array");
		counterOfErrors++;
	}

	if (counterOfErrors == 0)
	{
		printf("Tests passed");
	}
	return 0;
}