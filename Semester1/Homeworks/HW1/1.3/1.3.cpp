#include <stdio.h>

void revers_array(int array[], int initialValue, int numberOfelements)
{
	for (int i = initialValue; i < numberOfelements / 2; i++)
	{
		int temp = array[i + 1];
		array[i + 1] = array[numberOfelements - i];
		array[numberOfelements - i] = temp;
	}
}

int main()
{
	printf("input m: ");
	int m;
	scanf("%d", &m);
	printf("input n: ");
	int n;
	scanf("%d", &n);
	printf("input array: ");
	int array[10000] = {};
	for (int i = 0; i < m + n; i++)
	{
		scanf("%d", &array[i + 1]);
	}
	revers_array(array, 0, m);
	revers_array(array, m, 2 * m + n);
	revers_array(array, 0, m + n);
	printf("new array: ");
	for (int i = 0; i < m + n; i++)
	{
		printf("%d ", array[i + 1]);
	}
	return 0;
}