#include <stdio.h>
#include <time.h>
#include <stdlib.h>

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
	if (right - left > 0)
	{
		const int pivot = partition(array, left, right);
		qsort(array, left, pivot - 1);
		qsort(array, pivot, right);
	}
}

bool binSearch(int array[], int lengthOfArray, const int key)
{
	int left = 0;
	int right = lengthOfArray - 1;
	while (left <= right)
	{
		const int middle = (left + right) / 2;
		if (key < array[middle])
		{
			right = middle - 1;
		}
		else if (key > array[middle])
		{
			left = middle + 1;
		}
		else
		{
			return true;
		}
	}
	return false;
}

bool elementSearchTest()
{
	const int length = 10;
	int array[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	for (int i = 0; i < length; i++)
	{
		if (!binSearch(array, length, array[i]))
		{
			return false;
		}
	}
	return !(binSearch(array, length, 11) || binSearch(array, length, 0));
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

bool tests()
{
	int counterOfErrors = 0;
	const int length = 10;
	int testArray1[length] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	qsort(testArray1, 0, length - 1);
	if (!checkSortedArray(testArray1, length))
	{
		printf("Error in test with array already sorted\n");
		counterOfErrors++;
	}

	int testArray2[length] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
	qsort(testArray2, 0, length - 1);
	if (!checkSortedArray(testArray2, length))
	{
		printf("Error in test with all the identical elements\n");
		counterOfErrors++;
	}

	int testArray3[length] = {1, 4, 10, 6, 4, 7, 11, 1, 4, 5};
	qsort(testArray3, 0, length - 1);
	if (!checkSortedArray(testArray3, length))
	{
		printf("Error when pivot is minimum in array\n");
		counterOfErrors++;
	}

	int testArray4[length] = {15, 4, 10, 6, 4, 15, 11, 3, 4, 5};
	qsort(testArray4, 0, length - 1);
	if (!checkSortedArray(testArray4, length))
	{
		printf("Error when pivot is maximum in array");
		counterOfErrors++;
	}

	if (!elementSearchTest())
	{
		printf("Error in search of elements");
		counterOfErrors++;
	}
	return counterOfErrors == 0;
}

int main()
{	
	if (tests())
	{
		printf("Input n: ");
		int n = 0;
		scanf("%d", &n);
		printf("Input k: ");
		int k = 0;
		scanf("%d", &k);
		srand(time(nullptr));
		int *array = new int[n]();
		printf("Random array: ");
		for (int i = 0; i < n; i++)
		{
			array[i] = rand() % 100;
			printf("%d ", array[i]);
		}
		qsort(array, 0, n - 1);

		printf("\nRandom numbers: ");
		int *randomNumbers = new int[k]();
		for (int i = 0; i < k; i++)
		{
			randomNumbers[i] = rand() % 100;
			printf("%d ", randomNumbers[i]);
		}

		printf("\nNumbers found in array: ");
		for (int i = 0; i < k; i++)
		{
			if (binSearch(array, n, randomNumbers[i]))
			{
				printf("%d ", randomNumbers[i]);
			}
		}
		delete[] randomNumbers;
		delete[] array;
	}
	return 0;
}