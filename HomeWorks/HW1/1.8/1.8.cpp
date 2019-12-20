#include <stdio.h>
#include <cstdlib>
#include <time.h>

int main()
{
	const int length = 10;
	int counter = 0;
	int a[length] = {};
	srand(time(nullptr));
	for (int i = 0; i < length; i++)
	{
		a[i] = rand() % 2;
		printf("%d ", a[i]);
		if (a[i] == 0)
			counter++;
	}
	printf("\nAmount of zero elements in the array: %d", counter);
	return 0;
}