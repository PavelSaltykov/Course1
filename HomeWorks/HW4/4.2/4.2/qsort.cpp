#include "qsort.h"

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