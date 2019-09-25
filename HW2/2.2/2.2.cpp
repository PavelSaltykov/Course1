#include <stdio.h>

int raiseToThePowerInLinearTime(int number, int power)
{
	int result = 1;
	for (int i = 0; i < power; i++)
	{
		result = result * number;
	}
	return result;
}

int raiseToThePowerInLogN(int number, int power)
{
	if (power == 0)
	{
		return 1;
	}
	if (power % 2 == 0)
	{
		int halfPower = raiseToThePowerInLogN(number, power / 2);
		return halfPower * halfPower;
	}
	else
	{
		return raiseToThePowerInLogN(number, power - 1) * number;
	}
}

int main()
{
	printf("Input the number: ");
	int num = 0;
	scanf("%d", &num);

	printf("Input the power of number (non-negative): ");
	int  powerOfNumber = 0;
	scanf("%d", &powerOfNumber);

	printf("%d\n", raiseToThePowerInLinearTime(num, powerOfNumber));
	printf("%d", raiseToThePowerInLogN(num, powerOfNumber));
	return 0;
}