#include <stdio.h>

int fibonacciRecursion(int number)
{
	if (number <= 1)
	{
		return 1;
	}
	else
	{
		return fibonacciRecursion(number - 1) + fibonacciRecursion(number - 2);
	}
}

int fibonacciIteration(int number)
{
	int tempArray[3] = { 0, 1, 1 };
	for (int i = 0; i < number; i++)
	{
		tempArray[2] = tempArray[0] + tempArray[1];
		for (int j = 0; j < 2; j++)
		{
			tempArray[j] = tempArray[j + 1];
		}
	}
	return tempArray[2];
}

int main()
{
	printf("Input the fibonacci number: ");
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", fibonacciRecursion(n));
	printf("%d", fibonacciIteration(n));
	return 0;
}