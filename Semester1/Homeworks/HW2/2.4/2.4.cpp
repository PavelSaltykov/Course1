#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void remakeArray(int array[], int lengthOfArray)
{
	int left = 1;
	int right = lengthOfArray - 1;
	while (left < right)
	{
		if (array[left] < array[0])
		{
			left++;
		}
		else if (array[right] >= array[0])
		{
			right--;
		}
		else
		{
			const int temp = array[left];
			array[left] = array[right];
			array[right] = temp;
			left++;
			right--;
		}
	}
}

int main()
{
	const int length = 10;
	int array[length] = {};
	printf("Random array: ");
	srand(time(nullptr));
	for (int i = 0; i < length; i++)
	{
		array[i] = rand() % 100;
		printf("%d ", array[i]);
	}

	remakeArray(array, length);

	printf("\nNew array:    ");
	for (int i = 0; i < length; i++)
	{
		printf("%d ", array[i]);
	}
	return 0;
}