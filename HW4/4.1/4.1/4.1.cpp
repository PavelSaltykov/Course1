#include <stdio.h>
#include <locale.h>

void convert(char number, int binaryNumber[]) 
{
	printf("%d -> ", number);
	int bit = 0b10000000;
	for (int i = 0; i < 8; i++)
	{
		binaryNumber[i] = (number & bit) ? 1 : 0;
		printf("%d", binaryNumber[i]);
		bit = bit >> 1;
	}
	printf("\n");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("Введите первое число: ");
	int temp;
	scanf("%d", &temp);
	const char number1 = temp;
	int binaryNumber1[8] = {};
	convert(number1, binaryNumber1);

	printf("Введите второе число: ");
	scanf("%d", &temp);
	const char number2 = temp;
	int binaryNumber2[8] = {};
	convert(number2, binaryNumber2);
	
	return 0;
}