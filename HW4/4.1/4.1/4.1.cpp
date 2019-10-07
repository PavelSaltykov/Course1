#include <stdio.h>
#include <locale.h>

void convert(char number, int binaryNumber[]) 
{
	int bit = 0b10000000;
	for (int i = 0; i < 8; i++)
	{
		binaryNumber[i] = (number & bit) ? 1 : 0;
		bit = bit >> 1;
	}
}

bool rangeCheck(int number, int left, int right)
{
	return(number >= left && number <= right);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int left = -128;
	int right = 127;
	printf("Введите первое целое число (из диапазона от %d до %d): ", left, right);
	int temp;
	scanf("%d", &temp);
	if (temp >= 0 && rangeCheck(temp, left, right))
	{
		right -= temp;
	}
	else if(temp <= 0 && rangeCheck(temp, left, right))
	{
		left -= temp;
	}
	else
	{
		printf("Введённое число вне диапазона!");
		return 1;
	}
	const char number1 = temp;
	int binaryNumber1[8] = {};
	convert(number1, binaryNumber1);

	printf("Введите второе целое число (из диапазона от %d до %d): ", left, right);
	scanf("%d", &temp);
	if (!rangeCheck(temp, left, right))
	{
		printf("Введённое число вне диапазона!");
		return 1;
	}
	const char number2 = temp;
	int binaryNumber2[8] = {};
	convert(number2, binaryNumber2);

	printf("%d -> ", number1);
	for (int i = 0; i < 8; i++)
	{
		printf("%d", binaryNumber1[i]);
	}
	printf("\n%d -> ", number2);
	for (int i = 0; i < 8; i++)
	{
		printf("%d", binaryNumber2[i]);
	}
	
	return 0;
}